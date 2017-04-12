item_damage = 20;

Item = {
	code = "it_sword_2",
	name = "Quite Clean Sword",
	image = "it_sword.png",
	type = "weapon",
	desc = "This one looks pretty good. Slice some cracks in four.",

	equip = function(user)
		user:setDamage(item_damage)
	end,

	takeoff = function(user)
		user:restoreBasicDamage()
	end
}
