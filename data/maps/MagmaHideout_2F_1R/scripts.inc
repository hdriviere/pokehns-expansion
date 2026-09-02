MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Pas si vite!\p"
	.string "Seuls les membres de la TEAM\n"
	.string "MAGMA sont autorisés à être ici!\p"
	.string "Mais tu ne portes pas notre\n"
	.string "uniforme…\p"
	.string "Il vaut mieux que je sois sûre!\n"
	.string "Allez, viens te battre!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aïe… Mon honneur vient d’en\n"
	.string "prendre un coup.$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Si tu n’aimes pas avoir froid,\n"
	.string "rejoins la TEAM MAGMA!$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Attends un peu toi!\p"
	.string "Tu pensais vraiment pouvoir\n"
	.string "passer devant moi comme ça?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Bon d’accord, j’ai rien dit.$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "J’aurais sûrement mieux fait de\n"
	.string "te laisser passer directement…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ah ah! Un intrus!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "J’ai perdu…\p"
	.string "Est-ce que je dois continuer à\n"
	.string "tourner en rond bêtement?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh oh! Un intrus!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Humpff…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "En fait, les combats n’ont\n"
	.string "jamais été ma spécialité…$"

