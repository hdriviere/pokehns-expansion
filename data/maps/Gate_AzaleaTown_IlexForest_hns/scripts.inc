Gate_AzaleaTown_IlexForest_hns_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "Le Bois aux Chênes est vaste!\n"
	.string "Veillez à ne pas vous perdre!$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "Le BOIS AUX CHENES est surveillé\n"
	.string "par son protecteur.\p"
	.string "Ne fais pas de bêtises!$"
