#ifndef living_profile_hpp
#define living_profile_hpp
#include <string>
#include <fstream>

struct LivingProfile
{
    std::string code;
    std::string apperance;
    std::string name;

    int health;
    int magicka;
    int damage;
    int defense;
    int level;
    int xp;

    void loadFromFile(std::string path)
    {
    	std::ifstream file(path.c_str());
    	file >> code;
    	file >> apperance;
		file >> name;
		file >> health;
		file >> magicka;
		file >> damage;
		file >> defense;
		file >> level;
		file >> xp;
    	file.close();
    }
};

#endif
