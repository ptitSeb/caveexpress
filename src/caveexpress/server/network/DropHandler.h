#pragma once

#include "engine/common/network/IProtocolHandler.h"
#include "caveexpress/server/map/Map.h"

class DropHandler: public IServerProtocolHandler {
private:
	Map& _map;
public:
	DropHandler (Map& map) :
			_map(map)
	{
	}

	void execute (const ClientId& clientId, const IProtocolMessage& message) override
	{
		Player* player = _map.getPlayer(clientId);
		if (player == nullptr) {
			error(LOG_SERVER, "drop for player with clientId " + string::toString((int)clientId) + " failed");
			return;
		}
		player->drop();
	}
};
