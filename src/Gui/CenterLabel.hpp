#ifndef CENTER_LABEL_HPP
#define CENTER_LABEL_HPP
#include "../Core/Vec2.hpp"
#include <SFML/Graphics/Text.hpp>
#include <queue>

class CenterLabel
{
	public:
		CenterLabel();

		void update(float deltaTime);
		void addLabel(const std::string& label);

		void setPosition(const vec2i& pos);

	private:
		std::deque<std::string> m_waitingLabels;
		vec2i m_position;
		sf::Text m_label;
		float m_timer;
};

#endif