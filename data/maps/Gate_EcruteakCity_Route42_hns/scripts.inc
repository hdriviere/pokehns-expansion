Gate_EcruteakCity_Route42_hns_MapScripts::
	.byte 0

Gate_EcruteakCity_Route42_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route42_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route42_Text_EcruteakGateOfficer:
	.string "Le MONT CREUSET est un\n"
	.string "labyrinthe.\p"
	.string "Fais attention à ne pas te\n"
	.string "perdre.$"

