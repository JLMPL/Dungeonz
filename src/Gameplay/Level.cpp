#include "Level.hpp"
#include "Living.hpp"
#include "../Ai/AiPlayer.hpp"
#include "../Ai/AiMob.hpp"
#include "../Collision/CollisionHandler.hpp"
#include "../Gui/Gui.hpp"
#include "../Render/IndicationHandler.hpp"
#include <fstream>

#ifdef _WIN32
#include "../Core/MinGWSucks.hpp"
#endif

void Level::init(const std::string& map, bool isFirst)
{
    m_map.setLevel(this);
    m_map.loadFromFile(map);

    m_mapName = map;

    if (!isFirst)
        loadTravel("data/travel.sav", false);

    saveTravel("data/checkpoint.sav", true);
}

void Level::loadTravel(const std::string& path, bool save)
{
    Living* player = (Living*)getEntityByCode("pc_player");

    std::ifstream file(path.c_str());

    if (save)
    {
        int shit;
        file >> shit;
    }

    int hp;
    int health;
    int mp;
    int magicka;
    int curr;
    int xp;
    int tonext;

    file >> hp;
    file >> health;
    file >> mp;
    file >> magicka;
    file >> curr;
    file >> xp;
    file >> tonext;

    player->setAttribute(Attribute::Hp, hp);
    player->setAttribute(Attribute::Health, health);
    player->setAttribute(Attribute::Mp, mp);
    player->setAttribute(Attribute::Magicka, magicka);

    player->setAttribute(Attribute::currLevel, curr);
    player->setAttribute(Attribute::Xp, xp);
    player->setAttribute(Attribute::ToNext, tonext);

    //SPELLZ
    bool is;
    for (std::size_t i = 0; i < Spell::NumSpells; i++)
    {
        file >> is;

        if (is)
            player->learnSpell(i, false);
    }

    int ready;
    file >> ready;
    player->setReadySpell(ready);

    //ITEMS
    int amount;
    std::string aitem;
    file >> amount;

    for (std::size_t i = 0; i < amount; i++)
    {
        file >> aitem;

        ItemPtr_t item = ItemPtr_t(new Item());
        item->loadFromFile(aitem + ".lua");
        player->accessInv().addItem(item);
    }

    //EQUIPPED
    std::string weapon;
    std::string armor;
    std::string bow;

    file >> weapon;
    file >> armor;
    file >> bow;

    if (weapon != "0")
    {
        for (std::size_t i = 0; i < player->accessInv().getAmount(); i++)
        {
            auto item = player->accessInv().getItem(i);
            if (item->code == weapon)
            {
                player->setEquippedItem(Equip::Weapon, item.get());
                (*item->equip)(player);
            }
        }
    }

    if (armor != "0")
    {
        for (std::size_t i = 0; i < player->accessInv().getAmount(); i++)
        {
            auto item = player->accessInv().getItem(i);
            if (item->code == armor)
            {
                player->setEquippedItem(Equip::Armor, item.get());
                (*item->equip)(player);
            }
        }
    }

    if (bow != "0")
    {
        for (std::size_t i = 0; i < player->accessInv().getAmount(); i++)
        {
            auto item = player->accessInv().getItem(i);
            if (item->code == bow)
            {
                player->setEquippedItem(Equip::Bow, item.get());
                (*item->equip)(player);
            }
        }
    }
    file.close();
}

void Level::saveTravel(const std::string& path, bool save)
{
    printf("saving!\n");
    Living* player = (Living*)getEntityByCode("pc_player");

    FILE* file = fopen(path.c_str(), "w");

    if (save)
    {
        fprintf(file, "#%s\n", m_mapName.c_str());
    }

    //STATS
    fprintf(file, "%d\n", player->getAttribute(Attribute::Hp));
    fprintf(file, "%d\n", player->getAttribute(Attribute::Health));

    fprintf(file, "%d\n", player->getAttribute(Attribute::Mp));
    fprintf(file, "%d\n", player->getAttribute(Attribute::Magicka));

    fprintf(file, "%d\n", player->getAttribute(Attribute::currLevel));
    fprintf(file, "%d\n", player->getAttribute(Attribute::Xp));
    fprintf(file, "%d\n", player->getAttribute(Attribute::ToNext));
    //SPELLS

    for (std::size_t i = 0; i < Spell::NumSpells; i++)
    {
        if (player->knowsSpell(i))
            fprintf(file, "1\n");
        else
            fprintf(file, "0\n");
    }

    fprintf(file, "%d\n", player->getReadySpell());

    //ITEMS
    int amount = player->accessInv().getAmount();
    fprintf(file, "%d\n", amount);

    for (std::size_t i = 0; i < amount; i++)
    {
        fprintf(file, "%s\n", player->accessInv().getItem(i)->code.c_str());
    }
    //EQUIPPED

    Item* weapon = player->getEquippedItem(Equip::Weapon);
    Item* armor = player->getEquippedItem(Equip::Armor);
    Item* bow = player->getEquippedItem(Equip::Bow);

    if (weapon)
        fprintf(file, "%s\n", weapon->code.c_str());
    else
        fprintf(file, "0\n");

    if (armor)
        fprintf(file, "%s\n", armor->code.c_str());
    else
        fprintf(file, "0\n");

    if (bow)
        fprintf(file, "%s\n", bow->code.c_str());
    else
        fprintf(file, "0\n");

    fclose(file);
}

Entity* Level::addEntity(EntityPtr_t entity)
{
    m_entities.push_back(std::move(entity));
    m_entities.back()->setLevel(this);
    m_entities.back()->setId(m_lastEntityId);
    m_lastEntityId++;
    return m_entities.back().get();
}

ItemPtr_t Level::addItem(ItemPtr_t item)
{
    m_items.push_back(item);
    return m_items.back();
}

FireMissile* Level::addFireMissile(std::shared_ptr<FireMissile> missile)
{
    m_missiles.push_back(missile);
    m_missiles.back()->setLevel(this);
    m_missiles.back()->setId(m_lastEntityId);
    m_lastEntityId++;
    return m_missiles.back().get();
}

IceMissile* Level::addIceMissile(std::shared_ptr<IceMissile> missile)
{
    m_iceMissiles.push_back(missile);
    m_iceMissiles.back()->setLevel(this);
    m_iceMissiles.back()->setId(m_lastEntityId);
    m_lastEntityId++;
    return m_iceMissiles.back().get();
}

LightningBolt* Level::addLightningBolt(std::shared_ptr<LightningBolt> bolt)
{
    m_lightnings.push_back(bolt);
    m_lightnings.back()->setLevel(this);
    m_lightnings.back()->setId(m_lastEntityId);
    m_lastEntityId++;
    return m_lightnings.back().get();
}

Arrow* Level::addArrow(std::shared_ptr<Arrow> arrow)
{
    m_arrows.push_back(arrow);
    m_arrows.back()->setLevel(this);
    m_arrows.back()->setId(m_lastEntityId);
    m_lastEntityId++;
    return m_arrows.back().get();
}

void Level::addBigParticle(const std::string& path, const vec2i& pos, const vec2i& offset, float life)
{
    m_bigParticles.push_back(BigParticle());
    m_bigParticles.back().init(path, offset, life);
    m_bigParticles.back().setPosition(pos);
}

void Level::update(float deltaTime)
{
    for (auto i = m_entities.begin(); i != m_entities.end();)
    {
        if ((*i)->isDestroyed())
            i = m_entities.erase(i);
        else
            i++;
    }

    for (auto i = m_missiles.begin(); i != m_missiles.end();)
    {
        if ((*i)->isDestroyed())
            i = m_missiles.erase(i);
        else 
            i++;
    }

    for (auto i = m_iceMissiles.begin(); i != m_iceMissiles.end();)
    {
        if ((*i)->isDestroyed())
            i = m_iceMissiles.erase(i);
        else 
            i++;
    }

    for (auto i = m_lightnings.begin(); i != m_lightnings.end();)
    {
        if ((*i)->isDestroyed())
            i = m_lightnings.erase(i);
        else
            i++;
    }

    for (auto i = m_arrows.begin(); i != m_arrows.end();)
    {
        if ((*i)->isDestroyed())
            i = m_arrows.erase(i);
        else
            i++;
    }

    for (auto i = m_bigParticles.begin(); i != m_bigParticles.end();)
    {
        if ((*i).isDead())
            i = m_bigParticles.erase(i);
        else
            i++;
    }

    for (auto& i : m_entities)
        i->update(deltaTime);

    for (auto& i : m_missiles)
        i->update(deltaTime);

    for (auto& i : m_iceMissiles)
        i->update(deltaTime);

    for (auto& i : m_lightnings)
        i->update(deltaTime);

    for (auto& i : m_arrows)
        i->update(deltaTime);

    for (auto& i : m_bigParticles)
        i.update(deltaTime);

    m_map.update();
    CollisionHandler::Get().update(deltaTime);

    auto camera_pos = GUI::Get().getTarget()->getPosition().geti();
    Renderer::Get().setCameraPos(camera_pos);

    IndicationHandler::Get().update(deltaTime);
    GUI::Get().update(deltaTime);
}

void Level::leave()
{
    saveTravel("data/travel.sav", false);
}

std::vector<Entity*> Level::getEntitiesInRange(const vec2f& pos, float range)
{
    std::vector<Entity*> ents;

    for (int i = 0; i < m_entities.size(); i++)
    {
        if (m_entities[i]->getPosition() != pos)
        {
            vec2f die = pos - m_entities[i]->getPosition();

            if (length(die) <= range)
            {
                ents.push_back(m_entities[i].get());
            }
        }
    }

    return ents;
}

Entity* Level::getEntityByCode(std::string code)
{
    for (int i = 0; i < m_entities.size(); i++)
    {
        if (m_entities[i]->getCode() == code)
        {
            return m_entities[i].get();
        }
    }
    return nullptr;
}

std::vector<Entity*> Level::getEntitiesByCode(std::string code)
{
    std::vector<Entity*> ents;

    for (std::size_t i = 0; i < m_entities.size(); i++)
    {
        if (m_entities[i]->getCode() == code)
        {
            ents.push_back(m_entities[i].get());
        }
    }
    return ents;
}

Living* Level::getPlayer()
{
    for (auto& i : m_entities)
    {
        if (i->getCode() == "pc_player")
            return static_cast<Living*>(i.get());
    }
}
