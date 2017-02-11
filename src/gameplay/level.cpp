#include "level.hpp"
#include "../ai/ai_player.hpp"
#include "../ai/ai_mob.hpp"
#include "../gui/gui.hpp"
#include "../message/message_bus.hpp"
#include "../collision/collision_handler.hpp"
#include "../render/indication_handler.hpp"

void Level::init()
{
	profile.loadFromFile("data/pc_player.chr");

	//Player
	player = (Living*)addEntity(EntityPtr_t(new Living()));
	player->init(profile);
	player->setAI(AIPtr_t(new AIPlayer()));
	player->setPosition(vec2f(600,400));//(vec2f(418,950));

	ItemPtr_t book = addItem(ItemPtr_t(new Item("data/it_test_note.lua")));

	player->accessInv().addItem(book);

	mope.setLevel(this);
	mope.loadFromFile("data/map_test.tmx");

	GUI::Get().setTarget(player);
}

Entity* Level::addEntity(EntityPtr_t entity)
{
	m_Entities.push_back(std::move(entity));
	m_Entities.back()->setLevel(this);
	m_Entities.back()->setId(m_lastEntityId);
	m_lastEntityId++;
	return m_Entities.back().get();
}

ItemPtr_t Level::addItem(ItemPtr_t item)
{
	m_Items.push_back(item);
	return m_Items.back();
}

void Level::update(float deltaTime)
{	
	for(auto& i : m_Entities)
		i->update(deltaTime);

	mope.update();
	CollisionHandler::Get().update(deltaTime);

	MessagePtr_t setCameraPos = MessagePtr_t(new Message::RENDER::MessageCamera(vec2i(player->getPosition().x, player->getPosition().y)));
	MessageBus::Get().sendMessage(Message::RENDER::SET_CAMERA_POS, setCameraPos);

	IndicationHandler::Get().update(deltaTime);
	GUI::Get().update();
}

std::vector<Entity*> Level::getEntitiesInRange(const vec2f& pos, float range)
{
	std::vector<Entity*> ents;

	for(int i = 0; i < m_Entities.size(); i++)
	{
		if(m_Entities[i]->getPosition() != pos)
		{
			vec2f die = pos - m_Entities[i]->getPosition();

			if(length(die) <= range)
			{
				ents.push_back(m_Entities[i].get());
			}
		}
	}

	return ents;
}

Entity* Level::getEntityByCode(std::string code)
{
	for(int i = 0; i < m_Entities.size(); i++)
	{
		if(m_Entities[i]->getCode() == code)
		{
			return m_Entities[i].get();
		}
	}
	return nullptr;
}	