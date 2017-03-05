#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP
#include <SFML/Window/Keyboard.hpp>

enum KeyBind
{
    Up = 0,
    Down,
    Left,
    Right,
    Action,
    Attack,
    Inv,
    Use,
    Run,
    Cast,
    Spellz,
    Escape,
    Roll,
    NumKeys
};

//Singleton
class InputHandler
{
    public:
        static InputHandler& Get()
        {
            static InputHandler self;
            return self;
        }

        void init();

        bool isKeyPressed(sf::Keyboard::Key key);
        bool isAnyKeyPressed();

        void bindKey(KeyBind bind, sf::Keyboard::Key key);

        bool isUp();
        bool isDown();
        bool isLeft();
        bool isRight();
        bool isAction();
        bool isAttack();
        bool isInv();
        bool isRun();
        bool isCast();
        bool isSpellbook();
        bool isEscape();
        bool isRoll();

    private:
        sf::Keyboard::Key m_keys[KeyBind::NumKeys];
};

#endif
