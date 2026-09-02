Gate_EcruteakCity_Route38_hns_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "Tu viens d'où?\p"
	.string "BOURG GEON?\p"
	.string "Le PROF.ORME y vit, non?\p"
	.string "Tu viens de loin, dis donc.$"
