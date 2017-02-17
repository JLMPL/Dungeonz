#include "graphic_loot.hpp"
#include "../render/renderer.hpp"
#include "../gameplay/inventory.hpp"
#include "../resource/texture_cache.hpp"
#include "../input/input_handler.hpp"

constexpr int gMaxItems = 5;

GraphicLoot::GraphicLoot()
{
	for(int i = 0; i < gMaxItems; i++)
		m_slots.push_back(Slot());

	m_select.setTexture(*TextureCache::Get().getTexture("data/selection.png"));
}

void GraphicLoot::update()
{
	if (InputHandler::Get().isLeft() and 
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected > 0)
	{
		m_selected--;
		m_timer.restart();
	}
	else if (InputHandler::Get().isRight() and 
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected < 4)
	{
		m_selected++;
		m_timer.restart();
	}

	for (int i = 0; i < gMaxItems; i++)
	{
		vec2i pos = vec2i((m_pos.x -80) + i *32, m_pos.y -64);
		m_slots[i].setPosition(pos);
		m_slots[i].empty = true;

		if(m_selected == i)
			m_select.setPosition(pos.getSfVecf());
	}

	for (int i = 0; i < m_inv->getAmount(); i++)
	{
		m_slots[i].setItem(m_inv->getItem(i).get());
	}

	if (InputHandler::Get().isAction() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_inv->getAmount() >= m_selected and
		m_slots[m_selected].empty == false)
	{
		if (m_tinv->addItem(m_inv->getItem(m_selected)))
		{
			m_inv->removeItem(m_inv->getItem(m_selected)->code);
			m_slots[m_selected].empty = true;
		}

		m_timer.restart();
	}

	for (auto& i : m_slots)
	{
		Renderer::Get().submitOverlay(&i.rect);
		if (!i.empty)
			Renderer::Get().submitOverlay(&i.sprite);
		Renderer::Get().submitOverlay(&m_select);
	}
}

void GraphicLoot::reset()
{
	m_timer.restart();
	m_selected = 0;
}

void GraphicLoot::setPosition(const vec2i& pos)
{
	m_pos = pos;
}

void GraphicLoot::setInv(Inventory* inv)
{
	m_inv = inv;
}

void GraphicLoot::setTargetInv(Inventory* inv)
{
	m_tinv = inv;
}	