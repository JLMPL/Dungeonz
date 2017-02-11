#ifndef message_bus_hpp
#define message_bus_hpp
#include "listener.hpp"
#include <memory>
#include <vector>

//Singleton
class MessageBus
{
    public:
        static MessageBus& Get()
        {
            static MessageBus self;
            return self;
        }

        void init();

        void addListener(Listener* listener);

        void sendMessage(int message, MessagePtr_t value);

    private:
        std::vector<Listener*> m_Listeners;
};

#endif
