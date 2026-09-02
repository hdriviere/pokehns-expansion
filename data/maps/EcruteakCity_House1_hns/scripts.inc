EcruteakCity_House1_hns_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "Ca s'est passé lorsque j'étais\n"
	.string "jeune.\p"
	.string "Le ciel est soudainement\n"
	.string "devenu noir. Un Pokémon\p"
	.string "gigantesque cachait\n"
	.string "les rayons du soleil.\p"
	.string "Je me demande quel Pokémon\n"
	.string "c'était...\p"
	.string "C'était comme un oiseau ou un\n"
	.string "dragon.$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "Ça existe vraiment,\n"
	.string "un Pokémon aussi\p"
	.string "grand? Si c’est le\n"
	.string "cas, il doit être\p"
	.string "suuuuper fort!$"
