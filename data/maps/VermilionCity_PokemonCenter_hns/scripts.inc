VermilionCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY_HNS
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "Un Pokémon endormi est devant la\n"
	.string "CAVE TAUPIQUEUR.\p"
	.string "On pourrait l'attraper, mais\n"
	.string "comment le réveiller?$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "Il y avait un Pokémon endormi\p"
	.string "devant la CAVE TAUPIQUEUR.\p"
	.string "Mais il a disparu, on dirait.$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "Les combats de\n"
	.string "Dresseurs ne sont pas\p"
	.string "la moindre des joies\n"
	.string "du Bateau Express!$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "Oh? Je n’ai jamais\n"
	.string "vu ces Badges...\p"
	.string "Ah, je vois, tu\n"
	.string "viens de Johto!$"
