#ifndef gui_hpp
#define gui_hpp
#include "graphic_inv.hpp"
#include "graphic_loot.hpp"
#include "gui_mode.hpp"
#include "../message/listener.hpp"
#include "../render/bar.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>

class Living;
class Inventory;

//Singleton
class GUI : public Listener
{
	public:
		static GUI& Get()
		{
			static GUI self;
			return self;
		}

		void init();
		void update();

		void goLoot(Inventory* inv, const vec2i& pos);
		void goRead(const std::string& content);
		void showFocusHealthbar(int val, int max, const vec2i& pos);
		void setFocusLabel(const std::string& label, const vec2i& pos);

		virtual void sendMessage(int message, MessagePtr_t value) override final;

		void setTarget(Living* living);

	private:

	private:
		GUIMode m_mode;
		sf::Clock m_timer;
		sf::Sprite m_sight;
		vec2i m_camera;

		bool m_showLabel = false;
		sf::Text m_focusLabel;
		bool m_showHealthbar = false;
		Bar m_focusHealth;

		Living* m_target;

		GraphicInv m_ginv;
		GraphicLoot m_gloot;
		Bar m_health;
		Bar m_magicka;

		vec2i m_bookPos;
		sf::RectangleShape m_bookBack;
		sf::Text m_bookText;
};

#endif
