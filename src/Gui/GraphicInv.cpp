#include "GraphicInv.hpp"
#include "../Core/Screen.hpp"
#include "../Render/Renderer.hpp"
#include "../Gameplay/Inventory.hpp"
#include "../Resource/TextureCache.hpp"
#include "../Input/InputHandler.hpp"
#include "../Resource/FontCache.hpp"
#include "../Gameplay/Living.hpp"
#include "../Gameplay/Level.hpp"
#include "../Gameplay/ItemBag.hpp"

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
}

void GraphicInv::init(int width, int height)
{
    m_width = width;
    m_height = height;

    for (int i = 0; i < g_maxItems; i++)
        m_slots.push_back(Slot());

    m_invPos = {m_width - 32 * g_invSize, (m_height/2) - (g_invSize*16)};
    m_select.setTexture(*TextureCache::Get().getTexture("selection.png"));
    
    initDesc();
    initStats();
}

void GraphicInv::initDesc()
{
    m_descBack = sf::RectangleShape(sf::Vector2f(g_descWidth, g_descHeight));
    m_descBack.setFillColor({0x20,0x20,0x20});

    m_descBackPos = vec2i((m_width/2) - (g_descWidth /2), m_height - g_descHeight);

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

    m_statsPos = vec2i(0, (m_height/2) - (g_statsHeight/2));

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
        m_selected > g_invSize-1)
    {
        m_selected -= g_invSize;
        m_timer.restart();
    }
    else if (InputHandler::Get().isDown() and
        m_timer.getElapsedTime().asMilliseconds() > 150 and
        m_selected < g_maxItems - g_invSize)
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
        m_selected < g_maxItems-1)
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

    for (int i = 0; i < g_maxItems; i++)
    {
        Slot& slot = m_slots[i];
        if (i < m_inv->getAmount())
            slot.setItem(m_inv->getItem(i));
        slot.unmark();

        if (!slot.empty)
        {
            if (m_player->isEquipped(Equip::Weapon, slot.item.get()))
            {
                slot.mark();
            }
            else if (m_player->isEquipped(Equip::Armor, slot.item.get()))
            {
                slot.mark();
            }
            else if (m_player->isEquipped(Equip::Bow, slot.item.get()))
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
            case Item::Type::Weapon:
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
            }
            break;
            case Item::Type::Armor:
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
            }
            break;
            case Item::Type::Bow:
            {
                if (!m_player->isEquipped(Equip::Bow, &item))
                {
                    m_player->setEquippedItem(Equip::Bow, &item);
                    (*item.equip)(m_player);
                }
                else
                {
                    m_player->setEquippedItem(Equip::Bow, nullptr);
                    (*item.takeoff)(m_player);
                }
            }
            break;
            case Item::Type::Food:
            {
                (*item.effect)(m_player);
                m_player->accessInv().removeItem(&item);
                m_slots[m_selected].empty = true;
            }
            break;
            case Item::Type::Book:
            {
                (*item.effect)();
            }
            break;
            case Item::Type::Spell:
            {
                (*item.effect)(m_player);
                m_player->accessInv().removeItem(&item);
            }
            break;
            case Item::Type::Misc:
                break;
            default:break;
        }
        m_timer.restart();
    }
    else if (InputHandler::Get().isCast() and
        m_timer.getElapsedTime().asMilliseconds() > 150 and
        !m_slots[m_selected].empty)
    {
        Item::Ptr item = m_slots[m_selected].item;

        ItemBag* bag = (ItemBag*)m_player->getLevel()->addEntity(Entity::Ptr(new ItemBag()));
        bag->setCode("spitoff");
        bag->setPosition(m_player->getFakePos().getf());

        bag->accessInv().addItem(item);
        m_player->accessInv().removeItem(item.get());

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
            case Item::Type::Weapon:
                m_descType.setString("Weapon");
                break;
            case Item::Type::Armor:
                m_descType.setString("Armor");
                break;
            case Item::Type::Food:
                m_descType.setString("Consumable");
                break;
            case Item::Type::Book:
                m_descType.setString("Book");
                break;
            case Item::Type::Spell:
                m_descType.setString("Spell");
                break;
            case Item::Type::Misc:
                m_descType.setString("Miscellaneous");
                break;
        }
        
        m_descType.setOrigin({static_cast<int>(m_descType.getLocalBounds().width/2), 0});
        m_desc.setString(slot.item->desc);
    }

    auto thePos = m_pos + m_descBackPos;
    m_descBack.setPosition(thePos.getSfVecf());

    auto otherPos = m_pos + m_descBackPos + vec2i(g_descWidth/2, 10);
    m_descName.setPosition(otherPos.getSfVecf());

    auto typePos = m_pos + m_descBackPos + vec2i(g_descWidth/2, 30);
    m_descType.setPosition(typePos.getSfVecf());

    auto descPos = m_pos + m_descBackPos + vec2i(30, 50);
    m_desc.setPosition(descPos.getSfVecf());

    Renderer::Get().submitOverlay(&m_descBack);
    Renderer::Get().submitOverlay(&m_descName);
    Renderer::Get().submitOverlay(&m_descType);
    Renderer::Get().submitOverlay(&m_desc);
}

void GraphicInv::stats()
{
    auto pos = m_pos + m_statsPos;
    m_statsBcg.setPosition(pos.getSfVecf());

    auto levelPos = m_pos + m_statsPos + vec2i(10,5);
    m_statsLevel.setPosition(levelPos.getSfVecf());
    m_statsLevel.setString("Level " + std::to_string(m_player->getAttribute(Attribute::currLevel)));

    auto xpBarPos = m_pos + m_statsPos + vec2i(10,24);
    m_xpBar.setMaxValue(m_player->getAttribute(Attribute::ToNext));
    m_xpBar.setValue(m_player->getAttribute(Attribute::Xp));
    m_xpBar.setPosition(xpBarPos);

    auto healthPos = m_pos + m_statsPos + vec2i(10, 45);
    m_statsHealth.setPosition(healthPos.getSfVecf());

    auto healthBarPos = m_pos + m_statsPos + vec2i(10,64);
    m_healthBar.setMaxValue(m_player->getAttribute(Attribute::Health));
    m_healthBar.setValue(m_player->getAttribute(Attribute::Hp));
    m_healthBar.setPosition(healthBarPos);

    auto manaPos = m_pos + m_statsPos + vec2i(10, 85);
    m_statsMana.setPosition(manaPos.getSfVecf());

    auto manaBarPos = m_pos + m_statsPos + vec2i(10,104);
    m_manaBar.setMaxValue(m_player->getAttribute(Attribute::Magicka));
    m_manaBar.setValue(m_player->getAttribute(Attribute::Mp));
    m_manaBar.setPosition(manaBarPos);

    auto damagePos = m_pos + m_statsPos + vec2i(10, 128);
    m_statsDamage.setString("Damage " + std::to_string(m_player->getAttribute(Attribute::Damage)) + "pt");
    m_statsDamage.setPosition(damagePos.getSfVecf());

    auto defensePos = m_pos + m_statsPos + vec2i(10, 142);
    m_statsDefense.setString("Defense " + std::to_string(m_player->getAttribute(Attribute::Defense)) + "%");
    m_statsDefense.setPosition(defensePos.getSfVecf());

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