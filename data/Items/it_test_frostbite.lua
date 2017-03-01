
Spell_Frostbite = 1

Item = {
	code = "it_test_frostbite",
	name = "Frostbite Spell",
	image = "test_note.png",
	type = "spell",
	desc = "It'll freeze your balls off!",

	effect = function(user)
		if user:knowsSpell(Spell_Frostbite) == false then
			user:learnSpell(Spell_Frostbite)
			gui_read("Frosty saves the day!");
		end
	end
}
