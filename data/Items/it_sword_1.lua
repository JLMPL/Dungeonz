item_damage = 14;

Item = {
	code = "it_sword_1",
	name = "Dirty Sword",
	image = "it_sword.png",
	type = "weapon",
	desc = "This one looks fine. It can be really useful",

	equip = function(user)
		user:setDamage(item_damage)
	end,

	takeoff = function(user)
		user:restoreBasicDamage()
	end
}
