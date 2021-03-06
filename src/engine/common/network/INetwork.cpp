#include "INetwork.h"
#include "engine/common/Logger.h"

INetwork::CountMap INetwork::_count;

INetwork::INetwork () :
		_clientFunc(nullptr), _serverFunc(nullptr)
{
}

INetwork::~INetwork ()
{
}

void INetwork::count (const IProtocolMessage &msg)
{
	CountMap::iterator i = _count.find(msg.getId());
	int value = 1;
	if (i != _count.end()) {
		value += i->second;
	}
	_count[msg.getId()] = value;
}

void INetwork::shutdown ()
{
	info(LOG_GENERAL, "shutting down the network");
	closeClient();
	closeServer();

	for (CountMap::iterator i = _count.begin(); i != _count.end(); ++i) {
		info(LOG_NET, String::format("used protocol id %i %i times", static_cast<int>(i->first), i->second));
	}
	_count.clear();
}

int INetwork::sendToAllClients (const IProtocolMessage& msg)
{
	return sendToClients(0, msg);
}
