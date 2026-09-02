CherrygroveCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGrove_Pokecenter_OnTransition
	.byte 0

CherryGrove_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	end

CherryGrove_Pokecenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_Chansey::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox CherryGrove_Pokecenter_Text_Chansey, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	closemessage
	end

CherryGrove_Pokecenter_Text_Fisher:
	.string "Heureusement qu’on\n"
	.string "peut laisser autant\p"
	.string "de Pokémon qu’on\n"
	.string "veut gratuitement!$"

CherryGrove_Pokecenter_Text_Gentleman:
	.string "Le PC posé là-bas\n"
	.string "peut être utilisé\p"
	.string "par n’importe quel\n"
	.string "Dresseur, alors\p"
	.string "ne te gêne pas!$"

CherryGrove_Pokecenter_Text_Lass:
	.string "On dit qu'une casserole sous\n"
	.string "surveillance ne bout jamais.\p"
	.string "Au Centre Pokémon, l'horloge\n"
	.string "fait filer le temps!$"

CherryGrove_Pokecenter_Text_Chansey:
	.string "LEVEINARD: Leveiiinard!$"
