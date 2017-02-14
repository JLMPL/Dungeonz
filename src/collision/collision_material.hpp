#ifndef collision_material_hpp
#define collision_material_hpp

enum class CollMaterial : int
{
	NONE    = 1 << 0,
	REGULAR = 1 << 1,
	TRAP    = 1 << 2,
	LIVING  = 1 << 3
};

using CollMaterial_t = CollMaterial;

#endif