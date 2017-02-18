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
        std::string finalpath = "data/Living/" + path;
    	std::ifstream file(finalpath.c_str());

        if(!file.good())
        {
            printf("Failed to load LivingProfile \"%s\"!", finalpath.c_str());
        }
        else
        {
        	file >> code;
        	file >> apperance;
    		file >> name;
    		file >> health;
    		file >> magicka;
    		file >> damage;
    		file >> defense;
    		file >> level;
    		file >> xp;
        }
    	file.close();
    }
};

#endif
