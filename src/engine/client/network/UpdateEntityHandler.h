#pragma once

#include "engine/common/network/IProtocolHandler.h"
#include "engine/common/network/messages/UpdateEntityMessage.h"
#include "engine/client/ClientMap.h"

class UpdateEntityHandler: public IClientProtocolHandler {
private:
	ClientMap& _map;
public:
	UpdateEntityHandler (ClientMap& map) :
			_map(map)
	{
	}

	void execute (const IProtocolMessage& message) override
	{
		const UpdateEntityMessage *msg = static_cast<const UpdateEntityMessage*>(&message);
		_map.updateEntity(msg->getEntityId(), msg->getX(), msg->getY(), msg->getAngle(), msg->getState());
	}
};
