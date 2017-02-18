#ifndef INDICATION_HANDLER_HPP
#define INDICATION_HANDLER_HPP
#include "Indication.hpp"
#include <vector>

class IndicationHandler
{
	public:
		static IndicationHandler& Get()
		{
			static IndicationHandler self;
			return self;
		}

		void init();
		void update(float deltaTime);
		void addIndication(const std::string& message, const sf::Color& col, const vec2f& pos);

	private:
		std::vector<Indication> m_inds;
};

#endif