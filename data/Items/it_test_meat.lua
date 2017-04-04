Item = {
	code = "it_test_meat",
	name = "Bat meat",
	image = "it_meat.png",
	type = "food",
	desc = "It's not nearly as tasty as shit, but It will have to do.",

	effect = function(user)
		user:restoreHealth(10);
	end
}

