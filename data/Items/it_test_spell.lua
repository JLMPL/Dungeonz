
Spell_Fireball = 0

Item = {
	code = "it_test_spell",
	name = "Fireball",
	image = "it_note.png",
	type = "spell",
	desc = "I'm suprised this didn't burn.",

	effect = function(user)
		if user:knowsSpell(Spell_Fireball) == false then
			user:learnSpell(Spell_Fireball, true)
			gui_read("Shmaten faken shiten biten.\nTrolololo!");
		end
	end
}
