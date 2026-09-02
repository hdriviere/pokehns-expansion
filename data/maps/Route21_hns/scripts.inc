Route21_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH_HNS, Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI_HNS, Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD_HNS, Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "Haahahahahhaa! C'est la fête!$"

Route21_Text_SwimmermSethBeaten:
	.string "Glug...$"

Route21_Text_SwimmermSethAfterBattle:
	.string "Il y avait ce type arrogant près\n"
	.string "du volcan de Cramois’Ile.$"

Route21_Text_SwimmerfNikkiSeen:
	.string "Si je gagne, tu me passes de la\n"
	.string "crème!$"

Route21_Text_SwimmerfNikkiBeaten:
	.string "Je fais attention aux coups de\n"
	.string "soleil!$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "Les rides, les taches,\n"
	.string "quelle horreur!\p"
	.string "C’est que je suis en\n"
	.string "âge de me marier...$"

Route21_Text_FisherArnoldSeen:
	.string "Ras-le-bol de la pêche! Allez\n"
	.string "hop, combat!$"

Route21_Text_FisherArnoldBeaten:
	.string "Tout perdu...$"

Route21_Text_FisherArnoldAfterBattle:
	.string "J'vais pêcher plutôt...$"

