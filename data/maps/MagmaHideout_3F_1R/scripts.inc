MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Qu’est-ce que j’ai fait de mal\n"
	.string "pour être obligé de monter la\p"
	.string "garde ici?\p"
	.string "Mon oreille gauche est presque\n"
	.string "en train de brûler!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Je dois avoir des bouffées de\n"
	.string "chaleur…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Tu trouves pas ça bizarre qu’on\n"
	.string "porte des bonnets dans cette\p"
	.string "fournaise?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Nous avons rejoint la TEAM pour\n"
	.string "aider notre leader à concrétiser\p"
	.string "sa vision.\p"
	.string "Je me moque que tu appartiennes\n"
	.string "ou non à la TEAM AQUA.\p"
	.string "Je ne laisserai personne\n"
	.string "interférer dans nos plans!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh non… Je n’ai rien pu faire.$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Ecoute-moi bien. Ne te trompe\n"
	.string "pas d’ennemi.\p"
	.string "N’écoute pas la TEAM AQUA. Ne\n"
	.string "crois pas leurs mensonges!$"

