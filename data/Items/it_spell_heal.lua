
Spell_Heal = 3

Item = {
	code = "it_spell_heal",
	name = "Heal",
	image = "it_note.png",
	type = "spell",
	desc = "Put that there.\nRequires 32pt magicka",

	effect = function(user)
		if user:knowsSpell(Spell_Heal) == false then
			user:learnSpell(Spell_Heal, true)
			gui_read("Magic put into harmless but\nstill useful purpose.");
		end
	end
}
