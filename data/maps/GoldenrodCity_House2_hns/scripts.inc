GoldenrodCity_House2_hns_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "Une fois lorsque je me battais,\n"
    .string "mes\p"
    .string "Pokémon ne pouvaient plus\n"
    .string "attaquer.\p"
    .string "Les POINTS de POUVOIR, ou PP,\p"
    .string "de mes attaques étaient épuisés.$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "Même s’il est en\n"
    .string "pleine forme, il\p"
    .string "peut arriver qu’un\n"
    .string "Pokémon ne puisse\p"
    .string "plus attaquer!\p"
    .string "Il faut alors soit\n"
    .string "utiliser un objet\p"
    .string "soit l’emmener dans\n"
    .string "un Centre Pokémon.$"
