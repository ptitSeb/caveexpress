#include "TextureDefinition.h"
#include "engine/common/FileSystem.h"
#include "engine/common/ConfigManager.h"
#include "engine/common/Logger.h"
#include "engine/common/LUA.h"
#include "engine/common/System.h"
#include "engine/common/FileSystem.h"
#include "engine/common/ExecutionTime.h"
#include "engine/common/IProgressCallback.h"

TextureDefinition::TextureDefinition (const std::string& textureSize, IProgressCallback* progress) :
		_textureSize(textureSize), _cnt(0)
{
	if (textureSize != "big" && textureSize != "small") {
		System.exit("invalid texturesize value given: " + textureSize + ". Valid values are: auto, big, small", 1);
	}

	ExecutionTime e("Texture definition loading for " + textureSize);

	const std::string& path = FS.getTexturesDir();
	const DirectoryEntries& entries = FS.listDirectory(path);
	LUA lua;
	for (DirectoryEntries::const_iterator i = entries.begin(); i != entries.end(); ++i) {
		const std::string filename = path + *i;
		if (!FS.hasExtension(filename, "lua"))
			continue;
		if (!lua.load(filename)) {
			error(LOG_CLIENT, "failed to load textures from " + filename);
			continue;
		}
		lua.getGlobalKeyValue("textures" + textureSize);

		while (lua.getNextKeyValue()) {
			const String id = lua.getKey();
			if (id.empty()) {
				lua.pop();
				System.exit("Invalid texture entry found", 1);
			}

			if (progress != nullptr) {
				progress->progressStep();
			}
			const std::string name = lua.getValueStringFromTable("image");
			const float x0 = lua.getValueFloatFromTable("x0");
			const float y0 = lua.getValueFloatFromTable("y0");
			const float x1 = lua.getValueFloatFromTable("x1");
			const float y1 = lua.getValueFloatFromTable("y1");
			const int trimmedWidth = lua.getValueIntegerFromTable("trimmedwidth");
			const int trimmedHeight = lua.getValueIntegerFromTable("trimmedheight");
			const int untrimmedWidth = lua.getValueIntegerFromTable("untrimmedwidth");
			const int untrimmedHeight = lua.getValueIntegerFromTable("untrimmedheight");
			const int trimmedOffsetX = lua.getValueIntegerFromTable("trimmedoffsetx");
			const int trimmedOffsetY = lua.getValueIntegerFromTable("trimmedoffsety");
			const TextureDefinitionTrim trim(trimmedWidth, trimmedHeight,
					untrimmedWidth, untrimmedHeight, trimmedOffsetX, trimmedOffsetY);
			const TextureDefinitionCoords r = { x0, y0, x1, y1 };

			if (id.contains(TEXTURE_DIRECTION)) {
				const String rightID = id.replaceAll(TEXTURE_DIRECTION, TEXTURE_DIRECTION_RIGHT);
				create(name, rightID, r, trim, false);
				const String leftID = id.replaceAll(TEXTURE_DIRECTION, TEXTURE_DIRECTION_LEFT);
				create(name, leftID, r, trim, true);
			} else {
				const bool mirror = lua.getValueBoolFromTable("mirror");
				create(name, id, r, trim, mirror);
			}
			lua.pop();
			++_cnt;
		}
	}

	if (_textureDefs.empty())
		System.exit("could not load any texture definition", 1);
	info(LOG_CLIENT, "loaded " + string::toString(_textureDefs.size()) + " texture definitions");
}

TextureDefinition::~TextureDefinition ()
{
	_textureDefs.clear();
}

void TextureDefinition::create (const std::string& textureName, const std::string& id, const TextureDefinitionCoords& texcoords,
		const TextureDefinitionTrim& trim, bool mirror)
{
	if (_textureDefs.find(id) != _textureDefs.end()) {
		error(LOG_CLIENT, "texture def with same name found: " + id);
		return;
	}

	if (!texcoords.isValid()) {
		error(LOG_CLIENT, "texture def has invalid texcoords: " + id);
		return;
	}

	const TextureDef d = {textureName, id, texcoords, trim, mirror};
	_textureDefs[id] = d;
}

const TextureDef& TextureDefinition::getTextureDef (const std::string& textureName) const
{
	TextureDefMapConstIter i = _textureDefs.find(textureName);
	if (i != _textureDefs.end()) {
		return i->second;
	}

	return _emptyTextureDef;
}

bool TextureDefinition::exists (const std::string& textureName) const
{
	TextureDefMapConstIter i = _textureDefs.find(textureName);
	if (i != _textureDefs.end()) {
		return true;
	}

	return false;
}
