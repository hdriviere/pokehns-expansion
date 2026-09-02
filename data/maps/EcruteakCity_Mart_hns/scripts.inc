EcruteakCity_Mart_hns_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "Mon EVOLI a évolué en MENTALI.\p"
	.string "Mais l’EVOLI de mon ami a évolué\n"
	.string "en NOCTALI.\p"
	.string "Il a dû se\n"
	.string "passer un truc.\p"
	.string "Pourtant, on a\n"
	.string "tous les deux passé\p"
	.string "tout notre temps à élever notre\p"
	.string "Pokémon comme un EVOLI...$"

EcruteakMart_Text_Granny:
	.string "Si tu utilises RAPPEL, le\n"
	.string "Pokémon\p"
	.string "K.O. reviendra à lui.$"
