#include "Inventory.hpp"

bool Inventory::addItem(ItemPtr_t item)
{
	if(m_Items.size() < 25)
	{
		m_Items.push_back(item);
		return true;
	}
	return false;
}

void Inventory::removeItem(const std::string& code)
{
	// if(hasItem(code))
	// {
	for(int i = 0; i < m_Items.size(); i++)
	{
		if(m_Items[i]->code == code)
		{
			m_Items.erase(m_Items.begin() + i);
			return;
		}
	}
	// }
}

void Inventory::removeItem(Item* item)
{
	for(int i = 0; i < m_Items.size(); i++)
	{
		if(m_Items[i].get() == item)
		{
			m_Items.erase(m_Items.begin() + i);
			return;
		}
	}
}

bool Inventory::hasItem(const std::string& code)
{
	for(int i = 0; i < m_Items.size(); i++)
	{
		if(m_Items[i]->code == code)
		{
			return true;
		}
	}
	return false;
}

ItemPtr_t Inventory::getItem(int index)
{
	return m_Items[index];
}

int Inventory::getAmount()
{
	return m_Items.size();
}
