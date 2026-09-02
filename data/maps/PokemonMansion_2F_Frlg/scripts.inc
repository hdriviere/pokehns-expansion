PokemonMansion_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
	.string "Un bouton secret!\p"
	.string "Appuyer dessus?$"

PokemonMansion_Text_WhoWouldnt::
	.string "Qui ne le ferait pas?$"

PokemonMansion_Text_NotQuiteYet::
	.string "Pas vraiment!$"

PokemonMansion_1F_Text_ArnieIntro::
	.string "Mais… J'suis complètement paumé!$"

PokemonMansion_1F_Text_ArnieDefeat::
	.string "Non! Mon butin!$"

PokemonMansion_1F_Text_ArniePostBattle::
	.string "Les interrupteurs ouvrent et\n"
	.string "ferment alternativement les\p"
	.string "portes!$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
	.string "Rapport: 5 Juillet. Jungle X.\p"
	.string "Un nouveau type de POKéMON a été\n"
	.string "découvert.$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
	.string "Rapport: 10 Juillet. Le POKéMON\n"
	.string "a été baptisé MEW.$"

