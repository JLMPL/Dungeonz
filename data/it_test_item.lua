Item = {
	code = "it_test_item",
	name = "The Sample Item",
	image = "data/item.png",
	type = "weapon",
	desc = "This sword if properly used can deliver up to 200\npoints of damage.",

	equip = function(user)
		print("equipped!")
		user:setDamage(20)
	end,

	takeoff = function(user)
		print("taken off!")
		user:restoreBasicDamage()
	end
}
