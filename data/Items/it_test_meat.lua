Item = {
	code = "it_test_meat",
	name = "Bat meat",
	image = "item_meat.png",
	type = "food",
	desc = "It's not nearly as tasty as shit, but It will have to do.",

	effect = function(user)
		print("Tfoo! Awful!");
		user:restoreHealth(10);
	end
}
