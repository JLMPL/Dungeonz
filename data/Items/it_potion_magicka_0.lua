Item = {
	code = "it_potion_magicka_0",
	name = "Small Blue Potion",
	image = "it_potion_blue.png",
	type = "food",
	desc = "This one doesn't really taste bad.\nRestores 30pt magicka",

	effect = function(user)
		user:restoreMana(30);
	end
}

