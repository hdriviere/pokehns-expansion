OlivineCity_Mart_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "Est-ce que ton Pokémon connait\p"
	.string "la capacité\n"
	.string "qui permet de\p"
	.string "transporter des\n"
	.string "personnes sur l'eau?$"

OlivineCity_Text_MartLass:
	.string "Le PAPILUSION que j’ai reçu de\n"
	.string "mon chéri qui est à l’étranger\p"
	.string "tenait une Lettre!\p"
	.string "Tu veux savoir ce qui est écrit?\n"
	.string "Hé bien...\p"
	.string "C’est un S.E.C.R.E.T.!$"
