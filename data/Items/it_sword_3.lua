item_damage = 36;

Item = {
	code = "it_sword_3",
	name = "Solid Polished Sword",
	image = "it_sword.png",
	type = "weapon",
	desc = "Didn't expect to find something like THIS here.",

	equip = function(user)
		user:setDamage(item_damage)
	end,

	takeoff = function(user)
		user:restoreBasicDamage()
	end
}
