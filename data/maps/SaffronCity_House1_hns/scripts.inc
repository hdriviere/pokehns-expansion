SaffronCity_House1_hns_MapScripts::
	.byte 0

SaffronCity_House1_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_PSYCHIC, SaffronCity_House1_EventScript_MrPsychicAfter
	msgbox MrPsychic_Text_1, MSGBOX_NPC
	giveitem ITEM_TM_PSYCHIC
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	setflag FLAG_GOT_TM_PSYCHIC
	release
	end

SaffronCity_House1_EventScript_MrPsychicAfter::
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	end

MrPsychic_Text_1:
	.string "...\p"
	.string "....\p"
	.string ".....\p"
	.string "...... Je sais!\p"
	.string "Tu veux ça!$"

MrPsychic_Text_2:
	.string "Tu le sais déjà... La CT29\n"
	.string "contient Psyko.\p"
	.string "... Ça peut baisser la Défense\n"
	.string "Spéciale de l’ennemi!$"
