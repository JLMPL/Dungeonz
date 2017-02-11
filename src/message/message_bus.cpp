#include "message_bus.hpp"

void MessageBus::init()
{

}

void MessageBus::addListener(Listener* listener)
{
    m_Listeners.push_back(listener);
}

void MessageBus::sendMessage(int message, MessagePtr_t value)
{
    for(auto& i : m_Listeners)
        i->sendMessage(message, value);
}
