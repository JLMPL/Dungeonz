item_defense = 30;

Item = {
	code = "it_armor_1",
	name = "Saggy Armor",
	image = "item_armor.png",
	type = "armor",
	desc = "Still holds itself together.",

	equip = function(user)
		user:setDefense(item_defense)
	end,

	takeoff = function(user)
		user:restoreBasicDefense()
	end
}
