Item = {
	code = "it_root",
	name = "Edible Root",
	image = "it_meat.png",
	type = "food",
	desc = "This peed on root smells like magicka.\nRestores 10pt health",

	effect = function(user)
		user:restoreMana(10);
	end
}
