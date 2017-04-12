item_defense = 15;

Item = {
	code = "it_armor_0",
	name = "Ripped Armor",
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
