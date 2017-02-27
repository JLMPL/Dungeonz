#include "GraphicInv.hpp"
#include "../Render/Renderer.hpp"
#include "../Gameplay/Inventory.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Input/InputHandler.hpp"
#include "../Resource/FontCache.hpp"
#include "../Gameplay/Living.hpp"

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

constexpr int gInvSize = 5;
constexpr int gMaxItems = 25;

constexpr int gDescWidth = 384;
constexpr int gDescHeight = 128;

constexpr int gStatsWidth = 192;
constexpr int gStatsHeight = 192;

GraphicInv::GraphicInv()
{
	for (int i = 0; i < gMaxItems; i++)
		m_slots.push_back(Slot());

	m_invPos = vec2i(640, 220);
	m_select.setTexture(*TextureCache::Get().getTexture("selection.png"));
	
	initDesc();
	initStats();
}

void GraphicInv::initDesc()
{
	m_desc_back = sf::RectangleShape(sf::Vector2f(gDescWidth, gDescHeight));
	m_desc_back.setFillColor({0x20,0x20,0x20});

	m_desc_back_pos = vec2i(400 - (gDescWidth /2), 600 - gDescHeight);

	m_desc_name.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_desc_name.setCharacterSize(16);

	m_desc_type.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_desc_type.setCharacterSize(10);
	m_desc_type.setFillColor({0x80,0x80,0x80});

	m_desc.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_desc.setCharacterSize(10);
}

void GraphicInv::initStats()
{
	m_stats_bcg.setSize({gStatsWidth,gStatsHeight});
	m_stats_bcg.setFillColor({0x20,0x20,0x20});

	m_stats_pos = vec2i(0,300-gStatsHeight/2);

	m_stats_level.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_level.setCharacterSize(10);
	m_stats_level.setString("Level");

	m_xp_bar.init({gStatsWidth - 20,14}, {128,0,128});
	m_xp_bar.setShowStats(true);

	m_stats_health.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_health.setCharacterSize(10);
	m_stats_health.setString("Health");

	m_health_bar.init({gStatsWidth - 20,14}, {192,0,0});
	m_health_bar.setShowStats(true);

	m_stats_mana.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_mana.setCharacterSize(10);
	m_stats_mana.setString("Magicka");

	m_mana_bar.init({gStatsWidth - 20,14}, {0,0,192});
	m_mana_bar.setShowStats(true);

	m_stats_damage.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_damage.setCharacterSize(10);

	m_stats_defense.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_defense.setCharacterSize(10);
}


void GraphicInv::update()
{	
	if (InputHandler::Get().isUp() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected > 4)
	{
		m_selected -= 5;
		m_timer.restart();
	}
	else if (InputHandler::Get().isDown() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected < 20)
	{
		m_selected += 5;
		m_timer.restart();
	}

	if (InputHandler::Get().isLeft() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected > 0)
	{
		m_selected--;
		m_timer.restart();
	}
	else if (InputHandler::Get().isRight() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected < 25)
	{
		m_selected++;
		m_timer.restart();
	}

	for (int i = 0; i < gInvSize; i++)
	for (int j = 0; j < gInvSize; j++)
	{
		Slot& slot = m_slots[i * gInvSize + j];
		vec2i pos = vec2i(m_pos.x + m_invPos.x + j*32, m_pos.y + m_invPos.y + i*32);
		slot.setPosition(pos);
		slot.empty = true;

		if (m_selected == i * gInvSize + j)
			m_select.setPosition(pos.getSfVecf());
	}

	for (int i = 0; i < 25; i++)
	{
		Slot& slot = m_slots[i];
		if (i < m_inv->getAmount())
			slot.setItem(m_inv->getItem(i).get());
		slot.unmark();

		if (!slot.empty)
		{
			if (m_player->isEquipped(Equip::WEAPON, slot.item))
			{
				slot.mark();
			}
			else if (m_player->isEquipped(Equip::ARMOR, slot.item))
			{
				slot.mark();
			}
		}
	}

	if (InputHandler::Get().isAction() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		!m_slots[m_selected].empty)
	{
		Item& item = *m_slots[m_selected].item;

		switch(item.type)
		{
			case ItemType::WEAPON:
			{
				if (!m_player->isEquipped(Equip::WEAPON, &item))
				{
					m_player->setEquippedItem(Equip::WEAPON, &item);
					(*item.equip)(m_player);
				}
				else
				{
					m_player->setEquippedItem(Equip::WEAPON, nullptr);
					(*item.takeoff)(m_player);
				}
				break;
			}
			case ItemType::ARMOR:
			{
				if (!m_player->isEquipped(Equip::ARMOR, &item))
				{
					m_player->setEquippedItem(Equip::ARMOR, &item);
					(*item.equip)(m_player);
				}
				else
				{
					m_player->setEquippedItem(Equip::ARMOR, nullptr);
					(*item.takeoff)(m_player);
				}
				break;
			}
			case ItemType::FOOD:
			{
				(*item.effect)(m_player);
				m_player->accessInv().removeItem(&item);
				m_slots[m_selected].empty = true;
				break;
			}
			case ItemType::BOOK:
			{
				(*item.effect)();
			}
			case ItemType::SPELL:
			{
				(*item.effect)(m_player);
				break;
			}
			case ItemType::MISC:
			{
				break;
			}
			default:break;
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
	
	description();
	stats();
}

void GraphicInv::description()
{
	Slot& slot = m_slots[m_selected];
	if (!slot.empty)
	{
		m_desc_name.setString(slot.item->name);
		m_desc_name.setOrigin({static_cast<int>(m_desc_name.getLocalBounds().width/2), 0});
		
		switch(slot.item->type)
		{
			case ItemType::WEAPON:
				m_desc_type.setString("Weapon");
			break;
			case ItemType::ARMOR:
				m_desc_type.setString("Armor");
			break;
			case ItemType::FOOD:
				m_desc_type.setString("Consumable");
			break;
			case ItemType::BOOK:
				m_desc_type.setString("Book");
			break;
			case ItemType::SPELL:
				m_desc_type.setString("Spell");
			break;
			case ItemType::MISC:
				m_desc_type.setString("Miscellaneous");
			break;
		}
		
		m_desc_type.setOrigin({static_cast<int>(m_desc_type.getLocalBounds().width/2), 0});
		m_desc.setString(slot.item->desc);
	}

	auto the_pos = m_pos + m_desc_back_pos;
	m_desc_back.setPosition(the_pos.getSfVecf());

	auto other_pos = m_pos + m_desc_back_pos + vec2i(gDescWidth/2, 10);
	m_desc_name.setPosition(other_pos.getSfVecf());

	auto type_pos = m_pos + m_desc_back_pos + vec2i(gDescWidth/2, 30);
	m_desc_type.setPosition(type_pos.getSfVecf());

	auto desc_pos = m_pos + m_desc_back_pos + vec2i(30, 50);
	m_desc.setPosition(desc_pos.getSfVecf());

	Renderer::Get().submitOverlay(&m_desc_back);
	Renderer::Get().submitOverlay(&m_desc_name);
	Renderer::Get().submitOverlay(&m_desc_type);
	Renderer::Get().submitOverlay(&m_desc);
}

void GraphicInv::stats()
{
	auto pos = m_pos + m_stats_pos;
	m_stats_bcg.setPosition(pos.getSfVecf());

	auto level_pos = m_pos + m_stats_pos + vec2i(10,5);
	m_stats_level.setPosition(level_pos.getSfVecf());
	m_stats_level.setString("Level " + std::to_string(m_player->getAttribute(Attribute::LEVEL)));

	auto xp_bar_pos = m_pos + m_stats_pos + vec2i(10,24);
	m_xp_bar.setMaxValue(m_player->getAttribute(Attribute::TO_NEXT));
	m_xp_bar.setValue(m_player->getAttribute(Attribute::XP));
	m_xp_bar.setPosition(xp_bar_pos);

	auto health_pos = m_pos + m_stats_pos + vec2i(10, 45);
	m_stats_health.setPosition(health_pos.getSfVecf());

	auto health_bar_pos = m_pos + m_stats_pos + vec2i(10,64);
	m_health_bar.setMaxValue(m_player->getAttribute(Attribute::HEALTH));
	m_health_bar.setValue(m_player->getAttribute(Attribute::HP));
	m_health_bar.setPosition(health_bar_pos);

	auto mana_pos = m_pos + m_stats_pos + vec2i(10, 85);
	m_stats_mana.setPosition(mana_pos.getSfVecf());

	auto mana_bar_pos = m_pos + m_stats_pos + vec2i(10,104);
	m_mana_bar.setMaxValue(m_player->getAttribute(Attribute::MAGICKA));
	m_mana_bar.setValue(m_player->getAttribute(Attribute::MP));
	m_mana_bar.setPosition(mana_bar_pos);

	auto damage_pos = m_pos + m_stats_pos + vec2i(10, 128);
	m_stats_damage.setString("Damage " + std::to_string(m_player->getAttribute(Attribute::DAMAGE)));
	m_stats_damage.setPosition(damage_pos.getSfVecf());

	auto defense_pos = m_pos + m_stats_pos + vec2i(10, 142);
	m_stats_defense.setString("Defense " + std::to_string(m_player->getAttribute(Attribute::DEFENSE)));
	m_stats_defense.setPosition(defense_pos.getSfVecf());

	Renderer::Get().submitOverlay(&m_stats_bcg);
	Renderer::Get().submitOverlay(&m_stats_level);
	Renderer::Get().submitOverlay(&m_stats_health);
	Renderer::Get().submitOverlay(&m_stats_mana);
	Renderer::Get().submitOverlay(&m_stats_damage);
	Renderer::Get().submitOverlay(&m_stats_defense);

	m_xp_bar.update();
	m_health_bar.update();
	m_mana_bar.update();
}

void GraphicInv::setPosition(const vec2i& pos)
{
	m_pos = pos;
}

void GraphicInv::setInv(Inventory* inv)
{
	m_inv = inv;
}

void GraphicInv::setTarget(Living* player)
{
	m_player = player;
}