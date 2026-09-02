ViridianCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY_HNS
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "Où est donc le\n"
	.string "CHAMPION de l'ARENE\p"
	.string "de JADIELLE? Je\n"
	.string "veux l'affronter.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "Il n'y a pas de dresseurs dans\n"
	.string "l'ARENE de JADIELLE.\p"
	.string "Le CHAMPION dit qu'il n'en a pas\n"
	.string "besoin.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "On dit que l’Arène de\n"
	.string "Cramois’Ile a disparu...\p"
	.string "Mais qu’est-il arrivé à Auguste,\n"
	.string "le Champion?$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "Je rêve de devenir Champion\n"
	.string "d’Arène!$"
