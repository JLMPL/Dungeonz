
Spell_Lightning = 3

Item = {
	code = "it_test_lightning",
	name = "Lightning",
	image = "test_note.png",
	type = "spell",
	desc = "Don't underestimate my power!",

	effect = function(user)
		if user:knowsSpell(Spell_Lightning) == false then
			user:learnSpell(Spell_Lightning, true)
			gui_read("Unlimited Power!!!");
		end
	end
}
