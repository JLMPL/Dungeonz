Item = {
	code = "it_rat_meat",
	name = "Rat meat",
	image = "it_meat.png",
	type = "food",
	desc = "It's fresh but tastes like a week old.\nRestores 16pt health",

	effect = function(user)
		user:restoreHealth(16);
	end
}

