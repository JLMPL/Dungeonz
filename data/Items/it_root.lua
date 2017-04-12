Item = {
	code = "it_root",
	name = "Edible Root",
	image = "it_root.png",
	type = "food",
	desc = "This peed on root smells like magicka.\nRestores 10pt magicka",

	effect = function(user)
		user:restoreMana(10);
	end
}
