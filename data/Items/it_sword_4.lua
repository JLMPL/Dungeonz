item_damage = 45;

Item = {
	code = "it_sword_4",
	name = "Badass Sword",
	image = "it_sword.png",
	type = "weapon",
	desc = "Didn't really believe somethin' like this even exists.",

	equip = function(user)
		user:setDamage(item_damage)
	end,

	takeoff = function(user)
		user:restoreBasicDamage()
	end
}
