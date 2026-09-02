SafariZoneGate_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE_HNS
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Les gens qui viennent\n"
	.string "très souvent au\p"
	.string "Centre Pokémon\n"
	.string "sont ceux qui\p"
	.string "s’occupent le mieux de leurs\n"
	.string "Pokémon!\p"
	.string "Tu crois pas?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "Quand on est au bord\n"
	.string "de l’épuisement,\p"
	.string "après avoir traîné\n"
	.string "sur un chemin de\p"
	.string "montagne interminable, voir le\n"
	.string "toit\p"
	.string "d’un Centre Pokémon, c’est comme\p"
	.string "apercevoir une oasis après avoir\p"
	.string "traversé le désert!$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Le Parc Safari, on y rit! Le\n"
	.string "Parc Safari, c’est la vie!\p"
	.string "... C’est une\n"
	.string "chanson de ma\p"
	.string "composition. J’aime\n"
	.string "la chanter en me\p"
	.string "promenant dans le parc!$"
