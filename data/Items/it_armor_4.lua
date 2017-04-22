item_defense = 69;

Item = {
	code = "it_armor_4",
	name = "Awesome Armor",
	image = "item_armor.png",
	type = "armor",
	desc = "Woow. That's nice!",

	equip = function(user)
		user:setDefense(item_defense)
	end,

	takeoff = function(user)
		user:restoreBasicDefense()
	end
}
