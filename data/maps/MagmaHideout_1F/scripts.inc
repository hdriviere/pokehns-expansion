MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "A l’appel de la TEAM MAGMA, nous\n"
	.string "nous sommes présentés un par un\p"
	.string "pour recevoir nos assignements.\p"
	.string "C’est pour ça que je suis coincé\n"
	.string "dans ce coin, j’arrive toujours\p"
	.string "trop tard!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "J’arrive aussi toujours en\n"
	.string "retard aux entraînements!\p"
	.string "J’aime pas trop l’avouer, mais\n"
	.string "je suis loin d’être le meilleur…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "OK, je vais essayer de\n"
	.string "m’entraîner un peu plus\p"
	.string "sérieusement.$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Notre leader nous a dit de\n"
	.string "creuser dans le MONT CHIMNEE,\p"
	.string "alors on a creusé.\p"
	.string "Et pendant qu’on était en train\n"
	.string "de creuser, on est tombés sur\p"
	.string "quelque chose de vraiment\n"
	.string "incroyable.\p"
	.string "Tu veux savoir ce que c’est?\p"
	.string "Ouahahah! Je te le dirai si\n"
	.string "t’arrives à me battre!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Ouille! Tu m’as eu!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "J’ai changé d’avis, j’vais rien\n"
	.string "te dire! Tu vas devoir découvrir\p"
	.string "par toi-même!\p"
	.string "Je te gâcherais la surprise si\n"
	.string "je te disais tout, tu crois pas?$"

