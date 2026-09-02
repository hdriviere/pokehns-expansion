Route1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY_HNS, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN_HNS, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "Si deux Dresseurs\n"
	.string "se rencontrent,\p"
	.string "ils doivent\n"
	.string "combattre.$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "Graaaaaaah! Perduuuu!$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "Le combat pour\n"
	.string "les Dresseurs,\p"
	.string "c’est un peu comme\n"
	.string "une salutation.$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "Toi là! Combat?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "Houlà!$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "Pas mal.\p"
	.string "Tu as dû t'entraîner comme à\n"
	.string "donf!$"

Route1_Text_Sign:
	.string "ROUTE 1\p"
	.string "BOURG PALETTE JADIELLE$"
