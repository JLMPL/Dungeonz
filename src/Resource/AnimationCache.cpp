#include "AnimationCache.hpp"

void AnimationCache::init()
{
	m_zip = zip_open("data/anims.pak", 0, 'r');
}

AnimationCache::~AnimationCache()
{
	zip_close(m_zip);
}

AnimPtr_t AnimationCache::getAnimation(const std::string& path)
{
	auto anim = m_Animations.find(path);

	if (anim == m_Animations.end())
		return loadAnimation(path);
	else
		return m_Animations[path];
}

AnimPtr_t AnimationCache::loadAnimation(const std::string& path)
{
	void* buffer = nullptr;
	size_t buffer_size = 0;

	zip_entry_open(m_zip, path.c_str());
	zip_entry_read(m_zip, &buffer, &buffer_size);

	if (!buffer)
	{
		printf("Failed to load %s!\n", path.c_str());
	}

	AnimPtr_t anim = AnimPtr_t(new Animation());
	anim->loadFromMemory(buffer);
	m_Animations.insert(std::make_pair(path, anim));

	zip_entry_close(m_zip);
	return anim;
}
