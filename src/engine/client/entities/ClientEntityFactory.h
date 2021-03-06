#pragma once

#include "engine/common/EntityType.h"
#include "engine/common/Animation.h"
#include "engine/common/EntityAlignment.h"
#include "engine/common/SpriteDefinition.h"
#include "engine/common/IFactoryRegistry.h"
#include "engine/common/Pointers.h"
#include "engine/client/sound/Sound.h"
#include "engine/common/Singleton.h"
#include "engine/common/Logger.h"
#include "engine/common/LUA.h"
#include "engine/common/ExecutionTime.h"
#include <string>

class ClientEntity;
typedef SharedPtr<ClientEntity> ClientEntityPtr;

typedef std::map<const Animation*, std::string> SoundMapping;
typedef SoundMapping::const_iterator SoundMappingConstIter;
typedef std::map<const EntityType*, SoundMapping> SoundMappingCache;
typedef SoundMappingCache::const_iterator SoundMappingCacheConstIter;

class ClientEntityFactoryContext {
public:
	ClientEntityFactoryContext (const EntityType& _type, uint16_t _id, const std::string& _sprite,
			const Animation& _animation, float _x, float _y, float _width, float _height, EntityAngle _angle,
			const SoundMapping& _soundMapping, EntityAlignment _align) :
			type(_type), id(_id), sprite(_sprite), animation(_animation), x(_x), y(_y), width(_width), height(_height), angle(
					_angle), soundMapping(_soundMapping), align(_align)
	{
	}

	const SoundMapping& soundMapping;
	const EntityType& type;
	uint16_t id;
	const std::string& sprite;
	const Animation& animation;
	float x;
	float y;
	float width;
	float height;
	EntityAngle angle;
	EntityAlignment align;
};

class IClientEntityFactory: public IFactory<ClientEntity, ClientEntityFactoryContext> {
public:
	virtual ~IClientEntityFactory ()
	{
	}
	virtual ClientEntityPtr create (const ClientEntityFactoryContext *ctx) const = 0;
};

class ClientEntityRegistry: public IFactoryRegistry<EntityType, ClientEntity, ClientEntityFactoryContext> {
private:
	SoundMappingCache _soundMappingCache;
	friend class SoundMapper;

	void loadLUA () {
		ExecutionTime cache("Initialize entity sounds");
		LUA lua;
		if (!lua.load("entitysounds.lua")) {
			error(LOG_CLIENT, "could not load entitysounds.lua script");
			return;
		}

		for (EntityType::TypeMapConstIter eIter = EntityType::begin(); eIter != EntityType::end(); ++eIter) {
			String typeName = eIter->second->name;
			typeName = typeName.replaceAll("-", "");
			for (Animation::TypeMapConstIter aIter = Animation::begin(); aIter != Animation::end(); ++aIter) {
				String animationName = aIter->second->name;
				animationName = animationName.replaceAll("-", "");
				const std::string id = typeName.str() + "." + animationName.str();
				const std::string sound = lua.getString(id, "");
				if (sound.empty())
					continue;
				_soundMappingCache[eIter->second][aIter->second] = sound;
			}
		}
	}
public:
	ClientEntityRegistry () {}

	void initSounds() {
		loadLUA();
		for (SoundMappingCacheConstIter i = _soundMappingCache.begin(); i != _soundMappingCache.end(); ++i) {
			ExecutionTime cache("Entity sound cache: " + i->first->name + " (" + string::toString(i->second.size()) + ")");
			for (SoundMappingConstIter innerI = i->second.begin(); innerI != i->second.end(); ++innerI) {
				SoundControl.cache(innerI->second);
			}
		}
	}
	static ClientEntityPtr get (const EntityType& type, uint16_t id, const std::string& sprite = "",
			const Animation& animation = Animation::NONE, float x = 0.0f, float y = 0.0f, float sizeX = 0.0f,
			float sizeY = 0.0f, EntityAngle angle = 0, EntityAlignment align = ENTITY_ALIGN_LOWER_LEFT)	{
		ClientEntityRegistry& reg = Singleton<ClientEntityRegistry>::getInstance();
		const ClientEntityFactoryContext ctx(type, id, sprite, animation, x, y, sizeX, sizeY, angle, reg._soundMappingCache[&type], align);
		return reg.create(type, &ctx);
	}
};
