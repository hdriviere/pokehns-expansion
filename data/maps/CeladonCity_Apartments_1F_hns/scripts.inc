CeladonCity_Apartments_1F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "Mes Pokémon me\n"
	.string "tiennent compagnie.\p"
	.string "La solitude,\n"
	.string "c'est du passé.\p"
	.string "Mon MIAOUSS m'apporte même de\n"
	.string "l'argent.$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "MANOIR CELADON SUITE du PATRON$"
