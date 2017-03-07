#include "GraphicInv.hpp"
#include "../Core/Screen.hpp"
#include "../Render/Renderer.hpp"
#include "../Gameplay/Inventory.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Input/InputHandler.hpp"
#include "../Resource/FontCache.hpp"
#include "../Gameplay/Living.hpp"

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

constexpr int g_invSize = 6;
constexpr int g_maxItems = g_invSize * g_invSize;

constexpr int g_descWidth = 384;
constexpr int g_descHeight = 128;

constexpr int g_statsWidth = 192;
constexpr int g_statsHeight = 192;

GraphicInv::GraphicInv()
{
	for (int i = 0; i < g_maxItems; i++)
		m_slots.push_back(Slot());

	m_invPos = vec2i(Screen::Get().width - 32 * g_invSize, Screen::Get().halfHeight - (g_invSize*32)/2);
	m_select.setTexture(*TextureCache::Get().getTexture("selection.png"));
	
	initDesc();
	initStats();
}

void GraphicInv::initDesc()
{
	m_desc_back = sf::RectangleShape(sf::Vector2f(g_descWidth, g_descHeight));
	m_desc_back.setFillColor({0x20,0x20,0x20});

	m_desc_back_pos = vec2i(Screen::Get().halfWidth - (g_descWidth /2), Screen::Get().height - g_descHeight);

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
	m_stats_bcg.setSize({g_statsWidth, g_statsHeight});
	m_stats_bcg.setFillColor({0x20,0x20,0x20});

	// m_stats_pos = vec2i(0, 300 - g_statsHeight/2);
	m_stats_pos = vec2i(0, Screen::Get().halfHeight - g_statsHeight/2);

	m_stats_level.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_level.setCharacterSize(10);
	m_stats_level.setString("Level");

	m_xp_bar.init({g_statsWidth - 20,14}, {128,0,128});
	m_xp_bar.setShowStats(true);

	m_stats_health.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_health.setCharacterSize(10);
	m_stats_health.setString("Health");

	m_health_bar.init({g_statsWidth - 20,14}, {192,0,0});
	m_health_bar.setShowStats(true);

	m_stats_mana.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_stats_mana.setCharacterSize(10);
	m_stats_mana.setString("Magicka");

	m_mana_bar.init({g_statsWidth - 20,14}, {0,0,192});
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

	for (int i = 0; i < g_invSize; i++)
	for (int j = 0; j < g_invSize; j++)
	{
		Slot& slot = m_slots[i * g_invSize + j];
		vec2i pos = vec2i(m_pos.x + m_invPos.x + j*32, m_pos.y + m_invPos.y + i*32);
		slot.setPosition(pos);
		slot.empty = true;

		if (m_selected == i * g_invSize + j)
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
			if (m_player->isEquipped(Equip::Weapon, slot.item))
			{
				slot.mark();
			}
			else if (m_player->isEquipped(Equip::Armor, slot.item))
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

		switch (item.type)
		{
			case ItemType::Weapon:
			{
				if (!m_player->isEquipped(Equip::Weapon, &item))
				{
					m_player->setEquippedItem(Equip::Weapon, &item);
					(*item.equip)(m_player);
				}
				else
				{
					m_player->setEquippedItem(Equip::Weapon, nullptr);
					(*item.takeoff)(m_player);
				}
				break;
			}
			case ItemType::Armor:
			{
				if (!m_player->isEquipped(Equip::Armor, &item))
				{
					m_player->setEquippedItem(Equip::Armor, &item);
					(*item.equip)(m_player);
				}
				else
				{
					m_player->setEquippedItem(Equip::Armor, nullptr);
					(*item.takeoff)(m_player);
				}
				break;
			}
			case ItemType::Food:
			{
				(*item.effect)(m_player);
				m_player->accessInv().removeItem(&item);
				m_slots[m_selected].empty = true;
				break;
			}
			case ItemType::Book:
			{
				(*item.effect)();
			}
			case ItemType::Spell:
			{
				(*item.effect)(m_player);
				break;
			}
			case ItemType::Misc:
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
		
		switch (slot.item->type)
		{
			case ItemType::Weapon:
				m_desc_type.setString("Weapon");
			break;
			case ItemType::Armor:
				m_desc_type.setString("Armor");
			break;
			case ItemType::Food:
				m_desc_type.setString("Consumable");
			break;
			case ItemType::Book:
				m_desc_type.setString("Book");
			break;
			case ItemType::Spell:
				m_desc_type.setString("Spell");
			break;
			case ItemType::Misc:
				m_desc_type.setString("Miscellaneous");
			break;
		}
		
		m_desc_type.setOrigin({static_cast<int>(m_desc_type.getLocalBounds().width/2), 0});
		m_desc.setString(slot.item->desc);
	}

	auto the_pos = m_pos + m_desc_back_pos;
	m_desc_back.setPosition(the_pos.getSfVecf());

	auto other_pos = m_pos + m_desc_back_pos + vec2i(g_descWidth/2, 10);
	m_desc_name.setPosition(other_pos.getSfVecf());

	auto type_pos = m_pos + m_desc_back_pos + vec2i(g_descWidth/2, 30);
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
	m_stats_level.setString("Level " + std::to_string(m_player->getAttribute(Attribute::currLevel)));

	auto xp_bar_pos = m_pos + m_stats_pos + vec2i(10,24);
	m_xp_bar.setMaxValue(m_player->getAttribute(Attribute::ToNext));
	m_xp_bar.setValue(m_player->getAttribute(Attribute::Xp));
	m_xp_bar.setPosition(xp_bar_pos);

	auto health_pos = m_pos + m_stats_pos + vec2i(10, 45);
	m_stats_health.setPosition(health_pos.getSfVecf());

	auto health_bar_pos = m_pos + m_stats_pos + vec2i(10,64);
	m_health_bar.setMaxValue(m_player->getAttribute(Attribute::Health));
	m_health_bar.setValue(m_player->getAttribute(Attribute::Hp));
	m_health_bar.setPosition(health_bar_pos);

	auto mana_pos = m_pos + m_stats_pos + vec2i(10, 85);
	m_stats_mana.setPosition(mana_pos.getSfVecf());

	auto mana_bar_pos = m_pos + m_stats_pos + vec2i(10,104);
	m_mana_bar.setMaxValue(m_player->getAttribute(Attribute::Magicka));
	m_mana_bar.setValue(m_player->getAttribute(Attribute::Mp));
	m_mana_bar.setPosition(mana_bar_pos);

	auto damage_pos = m_pos + m_stats_pos + vec2i(10, 128);
	m_stats_damage.setString("Damage " + std::to_string(m_player->getAttribute(Attribute::Damage)) + "pt");
	m_stats_damage.setPosition(damage_pos.getSfVecf());

	auto defense_pos = m_pos + m_stats_pos + vec2i(10, 142);
	m_stats_defense.setString("Defense " + std::to_string(m_player->getAttribute(Attribute::Defense)) + "%");
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