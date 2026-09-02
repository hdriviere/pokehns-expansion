CherrygroveCity_House1_hns_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "Tu veux savoir si t’es un\n"
	.string "Dresseur fort ou mauvais?\p"
	.string "Alors va dans les\n"
	.string "Arènes de chaque\p"
	.string "ville de Johto et\n"
	.string "collectionne les Badges!$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "Quand je serai grand, je serai\n"
	.string "un CHAMPION d'ARENE!\p"
	.string "Je fais combattre mes Pokémon\n"
	.string "contre\p"
	.string "ceux de mon ami pour qu'ils\n"
	.string "progressent!$"
