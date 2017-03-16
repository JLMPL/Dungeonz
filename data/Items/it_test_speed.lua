
Spell_Speed = 2

Item = {
	code = "it_test_speed",
	name = "Speed",
	image = "test_note.png",
	type = "spell",
	desc = "Run forrest run!",

	effect = function(user)
		if user:knowsSpell(Spell_Speed) == false then
			user:learnSpell(Spell_Speed, true)
			gui_read("I'm usain bold!");
		end
	end
}
