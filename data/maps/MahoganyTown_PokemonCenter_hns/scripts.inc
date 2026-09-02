MahoganyTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "C'est quoi ça? La TEAM ROCKET\n"
    .string "est de retour?\p"
    .string "J'ai vu des hommes en noir au\n"
    .string "LAC COLERE...$"

MahoganyTown_PokemonCenter_Text_Youngster:
    .string "J'ai empêché mes Pokémon\n"
    .string "d'évoluer trop tôt.\p"
    .string "Je leur fais\n"
    .string "apprendre certaines\p"
    .string "capacités avant de\n"
    .string "les faire évoluer.$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "Les Pokémon deviennent\n"
    .string "bien plus forts\p"
    .string "lorsqu’ils évoluent\n"
    .string "mais ils apprennent\p"
    .string "leurs capacités plus lentement.$"
