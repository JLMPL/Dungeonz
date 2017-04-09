item_damage = 30;

Item = {
	code = "it_sword_1",
	name = "Not that rusty sword",
	image = "it_sword.png",
	type = "weapon",
	desc = "This one really looks good. It can be really useful",

	equip = function(user)
		user:setDamage(item_damage)
	end,

	takeoff = function(user)
		user:restoreBasicDamage()
	end
}
