
Spell_Lightning = 2

Item = {
	code = "it_spell_lightning",
	name = "Lightning",
	image = "it_note.png",
	type = "spell",
	desc = "Continous stream of electrons. Magic gets technical\nsometimes. Requires 5pt magicka",

	effect = function(user)
		if user:knowsSpell(Spell_Lightning) == false then
			user:learnSpell(Spell_Lightning, true)
			gui_read("The power once held by the\nweather itself now trapped\nbetween fingers of a mere mortal.");
		end
	end
}
