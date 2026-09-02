MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Je suis d’accord avec tout ce\n"
	.string "que dit notre leader. Mais tu\p"
	.string "sais quoi?\p"
	.string "Faire des trucs comme exhumer un\n"
	.string "POKéMON super vieux et voler le\p"
	.string "METEORITE de quelqu’un…\p"
	.string "Je crois qu’on va peut-être un\n"
	.string "peu trop loin. T’es pas\p"
	.string "d’accord?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ouaip, je pense vraiment qu’on\n"
	.string "fait quelque chose de mal.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Tu sais, perdre permet de\n"
	.string "prendre conscience de certaines\p"
	.string "choses.\p"
	.string "La prochaine fois que je verrai\n"
	.string "notre leader, je lui parlerai de\p"
	.string "ce que nous sommes en train de\n"
	.string "faire.$"

