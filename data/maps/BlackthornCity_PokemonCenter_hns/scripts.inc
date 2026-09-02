BlackthornCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "Au fin fond du Plateau Indigo se\n"
	.string "trouve la Ligue Pokémon.\p"
	.string "On dit que les\n"
	.string "meilleurs Dresseurs\p"
	.string "de tout le pays\n"
	.string "s’y retrouvent.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "Il y avait une\n"
	.string "capacité que je\p"
	.string "voulais faire apprendre\n"
	.string "à mon Pokémon...\p"
	.string "Alors j’ai demandé\n"
	.string "à l’Effaceur de\p"
	.string "Capacités de lui\n"
	.string "faire oublier une CS.$"
