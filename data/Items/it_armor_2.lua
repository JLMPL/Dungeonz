item_defense = 42;

Item = {
	code = "it_armor_2",
	name = "Nice Armor",
	image = "item_armor.png",
	type = "armor",
	desc = "This one provides fair amount of protection",

	equip = function(user)
		user:setDefense(item_defense)
	end,

	takeoff = function(user)
		user:restoreBasicDefense()
	end
}
