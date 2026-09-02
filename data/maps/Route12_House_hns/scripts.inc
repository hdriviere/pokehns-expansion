Route12_House_hns_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "Je suis le petit frère du MAITRE\n"
	.string "PECHEUR.\p"
	.string "Tu aimes la pêche, toi! Ca se\n"
	.string "voit.\p"
	.string "J'ai raison, hein? Bien sûr que\n"
	.string "oui!$"

Route12_House_Text_GiveSuperRod:
	.string "Parfait! Très bien! J’en étais\n"
	.string "sûr!\p"
	.string "Si tu aimes tant\n"
	.string "la pêche que ça,\p"
	.string "je vais te donner\n"
	.string "cette Méga Canne!$"

Route12_House_Text_GaveSuperRod:
	.string "Essaie de pêcher un peu partout\n"
	.string "où il y a de l'eau.\p"
	.string "Souviens-toi: tu peux\n"
	.string "attraper plusieurs\p"
	.string "Pokémon grâce à\n"
	.string "différentes CANNES.$"

Route12_House_Text_DontWantSuperRod:
	.string "Ah bon? Je me serais trompé?$"

