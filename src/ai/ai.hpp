#ifndef ai_hpp
#define ai_hpp

class Living;

class AI
{
    public:
        void init(Living* target);

        virtual void setup();

        virtual void update(float deltaTime);

    protected:
        Living* m_target;
};

#endif
