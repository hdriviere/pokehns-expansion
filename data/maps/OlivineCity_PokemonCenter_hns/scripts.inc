OlivineCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "Le MARIN du CAFE D'OLIVILLE\n"
	.string "voisin\l"
	.string "est vraiment généreux.\p"
	.string "Il a appris FORCE à mon Pokémon.\p"
	.string "Maintenant, il déplace d'énormes\n"
	.string "rochers sans le moindre effort.$"

OlivineCity_Text_PokecenterTeacher:
	.string "À IRISIA, de l'autre côté\n"
	.string "de la mer, quelqu'un se vante\l"
	.string "de son Pokémon rare.$"
