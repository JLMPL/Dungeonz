#ifndef ENTITY_PTR_HPP
#define ENTITY_PTR_HPP
#include "Entity.hpp"
#include <memory>

using EntityPtr_t = std::unique_ptr<Entity>;

#endif
