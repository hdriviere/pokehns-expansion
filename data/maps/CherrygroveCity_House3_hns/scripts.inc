CherrygroveCity_House3_hns_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "En combattant, les\n"
	.string "Pokémon gagnent\p"
	.string "de l’expérience\n"
	.string "et évoluent.$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "Les Pokémon évoluent?\p"
	.string "Je serais curieuse de voir ça!$"
