LavenderTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN_HNS
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "Au Nord de LAVANVILLE se trouve\n"
	.string "la\p"
	.string "GROTTE. Traversela pour accéder\n"
	.string "à la CENTRALE.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "Une émission de radio diffuse la\n"
	.string "musique de la FLÛTE POKé.\p"
	.string "Oh? Ta radio doit recevoir une\n"
	.string "EXTENSION pour la capter.\p"
	.string "La TOUR RADIO de la ville peut\n"
	.string "peut-être t'en fournir une?$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "Si la Centrale\n"
	.string "ne marche pas, le\p"
	.string "Train Magnétique ne\n"
	.string "peut pas circuler.\p"
	.string "Et même la Tour Radio ne peut\n"
	.string "plus rien émettre non plus.$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "Le DIRECTEUR de la STATION de\n"
	.string "RADIO était content.\p"
	.string "Il dit que les émissions peuvent\p"
	.string "reprendre depuis la réparation\n"
	.string "de la CENTRALE.$"
