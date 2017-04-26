#ifndef AI_HPP
#define AI_HPP
#include <memory>

class Living;

class Ai
{
    public:
        using Ptr = std::unique_ptr<Ai>;

        void init(Living* target);
        virtual void setup();
        virtual void update(float deltaTime);

    protected:
        Living* m_target;
};

#endif
