item_damage = 20;

Item = {
	code = "it_test_item",
	name = "The Sample Item",
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
