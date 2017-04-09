item_damage = 9;

Item = {
	code = "it_sword_0",
	name = "Rusty Sword",
	image = "it_sword.png",
	type = "weapon",
	desc = "This sword if properly used can deliver up to 200\npoints of damage.",

	equip = function(user)
		user:setDamage(item_damage)
	end,

	takeoff = function(user)
		user:restoreBasicDamage()
	end
}
