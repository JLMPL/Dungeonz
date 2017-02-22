Item = {
	code = "it_test_root",
	name = "Edible Root",
	image = "item_meat.png",
	type = "food",
	desc = "This peed on root smells like magicka.",

	effect = function(user)
		user:restoreMana(10);
	end
}
