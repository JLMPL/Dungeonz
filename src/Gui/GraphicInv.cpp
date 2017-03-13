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

//Screen::Get().resolution problem

GraphicInv::GraphicInv()
{
	for (int i = 0; i < g_maxItems; i++)
		m_slots.push_back(Slot());

	m_invPos = {800 - 32 * g_invSize, 300 - (g_invSize*16)};// = vec2i(Screen::Get().width - 32 * g_invSize, Screen::Get().halfHeight - (g_invSize*32)/2);
	m_select.setTexture(*TextureCache::Get().getTexture("selection.png"));
	
	initDesc();
	initStats();
}

void GraphicInv::initDesc()
{
	m_descBack = sf::RectangleShape(sf::Vector2f(g_descWidth, g_descHeight));
	m_descBack.setFillColor({0x20,0x20,0x20});

	m_descBackPos = vec2i(400 - (g_descWidth /2), 600 - g_descHeight);

	m_descName.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_descName.setCharacterSize(16);

	m_descType.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_descType.setCharacterSize(10);
	m_descType.setFillColor({0x80,0x80,0x80});

	m_desc.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_desc.setCharacterSize(10);
}

void GraphicInv::initStats()
{
	m_statsBcg.setSize({g_statsWidth, g_statsHeight});
	m_statsBcg.setFillColor({0x20,0x20,0x20});

	// m_statsPos = vec2i(0, 300 - g_statsHeight/2);
	m_statsPos = vec2i(0, 300 - (g_statsHeight/2));

	m_statsLevel.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_statsLevel.setCharacterSize(10);
	m_statsLevel.setString("Level");

	m_xpBar.init({g_statsWidth - 20,14}, {128,0,128});
	m_xpBar.setShowStats(true);

	m_statsHealth.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_statsHealth.setCharacterSize(10);
	m_statsHealth.setString("Health");

	m_healthBar.init({g_statsWidth - 20,14}, {192,0,0});
	m_healthBar.setShowStats(true);

	m_statsMana.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_statsMana.setCharacterSize(10);
	m_statsMana.setString("Magicka");

	m_manaBar.init({g_statsWidth - 20,14}, {0,0,192});
	m_manaBar.setShowStats(true);

	m_statsDamage.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_statsDamage.setCharacterSize(10);

	m_statsDefense.setFont(*FontCache::Get().getFont("Monaco_Linux.ttf"));
	m_statsDefense.setCharacterSize(10);
}

void GraphicInv::update()
{	
	if (InputHandler::Get().isUp() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected > 4)
	{
		m_selected -= g_invSize;
		m_timer.restart();
	}
	else if (InputHandler::Get().isDown() and
		m_timer.getElapsedTime().asMilliseconds() > 150 and
		m_selected < 20)
	{
		m_selected += g_invSize;
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
		m_descName.setString(slot.item->name);
		m_descName.setOrigin({static_cast<int>(m_descName.getLocalBounds().width/2), 0});
		
		switch (slot.item->type)
		{
			case ItemType::Weapon:
				m_descType.setString("Weapon");
			break;
			case ItemType::Armor:
				m_descType.setString("Armor");
			break;
			case ItemType::Food:
				m_descType.setString("Consumable");
			break;
			case ItemType::Book:
				m_descType.setString("Book");
			break;
			case ItemType::Spell:
				m_descType.setString("Spell");
			break;
			case ItemType::Misc:
				m_descType.setString("Miscellaneous");
			break;
		}
		
		m_descType.setOrigin({static_cast<int>(m_descType.getLocalBounds().width/2), 0});
		m_desc.setString(slot.item->desc);
	}

	auto the_pos = m_pos + m_descBackPos;
	m_descBack.setPosition(the_pos.getSfVecf());

	auto other_pos = m_pos + m_descBackPos + vec2i(g_descWidth/2, 10);
	m_descName.setPosition(other_pos.getSfVecf());

	auto type_pos = m_pos + m_descBackPos + vec2i(g_descWidth/2, 30);
	m_descType.setPosition(type_pos.getSfVecf());

	auto desc_pos = m_pos + m_descBackPos + vec2i(30, 50);
	m_desc.setPosition(desc_pos.getSfVecf());

	Renderer::Get().submitOverlay(&m_descBack);
	Renderer::Get().submitOverlay(&m_descName);
	Renderer::Get().submitOverlay(&m_descType);
	Renderer::Get().submitOverlay(&m_desc);
}

void GraphicInv::stats()
{
	auto pos = m_pos + m_statsPos;
	m_statsBcg.setPosition(pos.getSfVecf());

	auto level_pos = m_pos + m_statsPos + vec2i(10,5);
	m_statsLevel.setPosition(level_pos.getSfVecf());
	m_statsLevel.setString("Level " + std::to_string(m_player->getAttribute(Attribute::currLevel)));

	auto xp_bar_pos = m_pos + m_statsPos + vec2i(10,24);
	m_xpBar.setMaxValue(m_player->getAttribute(Attribute::ToNext));
	m_xpBar.setValue(m_player->getAttribute(Attribute::Xp));
	m_xpBar.setPosition(xp_bar_pos);

	auto health_pos = m_pos + m_statsPos + vec2i(10, 45);
	m_statsHealth.setPosition(health_pos.getSfVecf());

	auto health_bar_pos = m_pos + m_statsPos + vec2i(10,64);
	m_healthBar.setMaxValue(m_player->getAttribute(Attribute::Health));
	m_healthBar.setValue(m_player->getAttribute(Attribute::Hp));
	m_healthBar.setPosition(health_bar_pos);

	auto mana_pos = m_pos + m_statsPos + vec2i(10, 85);
	m_statsMana.setPosition(mana_pos.getSfVecf());

	auto mana_bar_pos = m_pos + m_statsPos + vec2i(10,104);
	m_manaBar.setMaxValue(m_player->getAttribute(Attribute::Magicka));
	m_manaBar.setValue(m_player->getAttribute(Attribute::Mp));
	m_manaBar.setPosition(mana_bar_pos);

	auto damage_pos = m_pos + m_statsPos + vec2i(10, 128);
	m_statsDamage.setString("Damage " + std::to_string(m_player->getAttribute(Attribute::Damage)) + "pt");
	m_statsDamage.setPosition(damage_pos.getSfVecf());

	auto defense_pos = m_pos + m_statsPos + vec2i(10, 142);
	m_statsDefense.setString("Defense " + std::to_string(m_player->getAttribute(Attribute::Defense)) + "%");
	m_statsDefense.setPosition(defense_pos.getSfVecf());

	Renderer::Get().submitOverlay(&m_statsBcg);
	Renderer::Get().submitOverlay(&m_statsLevel);
	Renderer::Get().submitOverlay(&m_statsHealth);
	Renderer::Get().submitOverlay(&m_statsMana);
	Renderer::Get().submitOverlay(&m_statsDamage);
	Renderer::Get().submitOverlay(&m_statsDefense);

	m_xpBar.update();
	m_healthBar.update();
	m_manaBar.update();
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