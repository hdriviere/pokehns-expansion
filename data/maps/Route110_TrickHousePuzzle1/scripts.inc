Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} écrit le code secret\n"
	.string "sur la porte.\p"
	.string "“Le MAITRE DES PIEGES est\n"
	.string "formidable.” … … … … … … … …\p"
	.string "La porte s’ouvre!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Grâce à COUPE, que je viens\n"
	.string "d’apprendre, je vais vaincre à\p"
	.string "la force de ma lame!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Pourquoi as-tu l’air si sérieux?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Je ne me lasse pas de trancher,\n"
	.string "découper et taillader!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Je me suis retrouvé dans cette\n"
	.string "étrange maison par hasard…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Et maintenant, j’ai perdu…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "J’ai perdu mon chemin, un combat\n"
	.string "et la tête… Je n’arrive pas à\p"
	.string "sortir…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Mais qui est le MAITRE DES\n"
	.string "PIEGES?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Tu as gagné parce que j’étais\n"
	.string "perdue dans mes pensées!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Tu es balèze! Mais qui es-tu, au\n"
	.string "juste?$"

