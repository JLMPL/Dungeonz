#ifndef COLLISION_MATERIAL_HPP
#define COLLISION_MATERIAL_HPP

namespace CollMaterial
{
constexpr int NONE    = 1 << 0;
constexpr int REGULAR = 1 << 1;
constexpr int TRAP    = 1 << 2;
constexpr int LIVING  = 1 << 3;
}

using CollMaterial_t = int;

#endif