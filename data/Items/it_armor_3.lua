item_defense = 55;

Item = {
	code = "it_armor_3",
	name = "Pretty Armor",
	image = "item_armor.png",
	type = "armor",
	desc = "I gotta admit. I like it!",

	equip = function(user)
		user:setDefense(item_defense)
	end,

	takeoff = function(user)
		user:restoreBasicDefense()
	end
}
