#pragma once

#include "engine/common/network/IProtocolHandler.h"
#include "engine/common/network/messages/RumbleMessage.h"
#include "engine/client/ClientMap.h"

/**
 * @brief Informs the client that it could play a rumble effect on the map because the player hit something
 */
class RumbleHandler: public IClientProtocolHandler {
private:
	ClientMap& _map;
public:
	RumbleHandler (ClientMap& map) :
			_map(map)
	{
	}

	void execute (const IProtocolMessage& message) override
	{
		const RumbleMessage *msg = static_cast<const RumbleMessage*>(&message);
		_map.rumble(msg->getStrength(), msg->getLengthMillis());
	}
};
