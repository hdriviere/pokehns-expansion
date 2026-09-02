Route18_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route18_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route18_EventScript_Trigger_HideKecleon0::
	setvar VAR_TEMP_0, 1
	setflag FLAG_TEMP_1
	removeobject LOCALID_ROUTE18_KECLEON0
	end

Route18_EventScript_Trigger_HideKecleon1::
	setvar VAR_TEMP_1, 1
	setflag FLAG_TEMP_2
	removeobject LOCALID_ROUTE18_KECLEON1
	end

Route18_EventScript_Boris::
	trainerbattle_single TRAINER_BORIS_HNS, Route18_Text_BirdKeeperBorisSeen, Route18_Text_BirdKeeperBorisBeaten
	msgbox Route18_Text_BirdKeeperBorisAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Bob::
	trainerbattle_single TRAINER_BOB_HNS, Route18_Text_BirdKeeperBobSeen, Route18_Text_BirdKeeperBobBeaten
	msgbox Route18_Text_BirdKeeperBobAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_SIGN
	end

Route18_Text_BirdKeeperBorisSeen:
	.string "Il faut chercher les Pokémon\n"
	.string "dans les hautes herbes.\p"
	.string "Tu le savais déjà?$"

Route18_Text_BirdKeeperBorisBeaten:
	.string "Aïe!$"

Route18_Text_BirdKeeperBorisAfterBattle:
	.string "Si j’étais aussi\n"
	.string "fort que toi, les\p"
	.string "combats seraient\n"
	.string "si amusants...$"

Route18_Text_BirdKeeperBobSeen:
	.string "La Piste Cyclable est un\n"
	.string "raccourci vers Céladopole.$"

Route18_Text_BirdKeeperBobBeaten:
	.string "... Fouiii!$"

Route18_Text_BirdKeeperBobAfterBattle:
	.string "Moi, je n’ai pas de\n"
	.string "Bicyclette, alors je ne\p"
	.string "peux pas l’emprunter,\n"
	.string "le raccourci!$"

Route18_Text_Sign:
	.string "ROUTE 18\p"
	.string "CELADOPOLE PARMANIE$"
