Item = {
	code = "it_potion_health_0",
	name = "Small Red Potion",
	image = "it_potion_red.png",
	type = "food",
	desc = "This one doesn't really taste bad.",

	effect = function(user)
		user:restoreHealth(30);
	end
}

