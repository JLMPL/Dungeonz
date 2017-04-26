#ifndef COLLISION_MATERIAL_HPP
#define COLLISION_MATERIAL_HPP

namespace CollMaterial
{
constexpr int None    = 1 << 0;
constexpr int Regular = 1 << 1;
constexpr int Trap    = 1 << 2;
constexpr int Living  = 1 << 3;
}

using CollMaterial_t = int;

#endif