#ifndef listener_hpp
#define listener_hpp
#include "message_ptr.hpp"

class Listener
{
    public:
        virtual void sendMessage(int message, MessagePtr_t value) = 0;
    private:
};

#endif
