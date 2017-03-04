#ifndef AI_HPP
#define AI_HPP

class Living;

class Ai
{
    public:
        void init(Living* target);

        virtual void setup();

        virtual void update(float deltaTime);

    protected:
        Living* m_target;
};

#endif
