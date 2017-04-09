Item = {
	code = "it_bat_meat",
	name = "Bat meat",
	image = "it_meat.png",
	type = "food",
	desc = "Definitely not a tasty one, but It will have to do.\nRestores 10pt health",

	effect = function(user)
		user:restoreHealth(10);
	end
}

