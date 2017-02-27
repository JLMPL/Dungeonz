#include "Inventory.hpp"

bool Inventory::addItem(ItemPtr_t item)
{
	if (m_items.size() < 25)
	{
		m_items.push_back(item);
		return true;
	}
	return false;
}

void Inventory::removeItem(const std::string& code)
{
	// if (hasItem(code))
	// {
	for (int i = 0; i < m_items.size(); i++)
	{
		if (m_items[i]->code == code)
		{
			m_items.erase(m_items.begin() + i);
			return;
		}
	}
	// }
}

void Inventory::removeItem(Item* item)
{
	for (int i = 0; i < m_items.size(); i++)
	{
		if (m_items[i].get() == item)
		{
			m_items.erase(m_items.begin() + i);
			return;
		}
	}
}

bool Inventory::hasItem(const std::string& code)
{
	for (int i = 0; i < m_items.size(); i++)
	{
		if (m_items[i]->code == code)
		{
			return true;
		}
	}
	return false;
}

ItemPtr_t Inventory::getItem(int index)
{
	if (index >= m_items.size())
		return nullptr;
	return m_items[index];
}

int Inventory::getAmount()
{
	return m_items.size();
}
