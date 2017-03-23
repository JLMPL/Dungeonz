Item = {
	code = "it_test_bow",
	name = "Yes a bow",
	image = "bow.png",
	type = "bow",
	desc = "You can actually shoot that thing.",

	equip = function(user)
		--user:setDamage(item_damage)
	end,

	takeoff = function(user)
		--user:restoreBasicDamage()
	end
}
