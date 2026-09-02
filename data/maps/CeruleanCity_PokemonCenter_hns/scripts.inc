CeruleanCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY_HNS
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "Contre un Dresseur,\n"
	.string "je préfère envoyer\p"
	.string "un Pokémon que j’ai\n"
	.string "bien entraîné, même\p"
	.string "s’il est moins fort qu’un\n"
	.string "Pokémon que\p"
	.string "je viendrais d’attraper.$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "Le Train Magnétique\n"
	.string "file à 550 km/h! Il\p"
	.string "va de Kanto à Johto\n"
	.string "en un clin d’œil!\p"
	.string "C’est devenu\n"
	.string "tellement plus\p"
	.string "facile d’aller à\n"
	.string "Johto, maintenant!$"
