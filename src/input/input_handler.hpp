#ifndef input_handler_hpp
#define input_handler_hpp
#include <SFML/Window/Keyboard.hpp>

enum KeyBind
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	ACTION,
	ATTACK,
	INV,
	USE,
	RUN,
	NUM_KEYS
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

	private:
		sf::Keyboard::Key m_keys[KeyBind::NUM_KEYS];
};

#endif
