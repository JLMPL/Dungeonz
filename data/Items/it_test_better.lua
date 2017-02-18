item_damage = 30;

Item = {
	code = "it_test_better",
	name = "Slightly Better Sword",
	image = "item.png",
	type = "weapon",
	desc = "This one really looks good. It can be really useful",

	equip = function(user)
		print("equipped!")
		user:setDamage(item_damage)
	end,

	takeoff = function(user)
		print("taken off!")
		user:restoreBasicDamage()
	end
}
