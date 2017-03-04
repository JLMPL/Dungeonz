item_defense = 20;

Item = {
	code = "it_test_armor",
	name = "Shitty Armor",
	image = "item_armor.png",
	type = "armor",
	desc = "Still better than running without shirt.",

	equip = function(user)
		user:setDefense(item_defense)
	end,

	takeoff = function(user)
		user:restoreBasicDefense()
	end
}
