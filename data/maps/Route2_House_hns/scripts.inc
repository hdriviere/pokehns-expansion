Route2_House_hns_MapScripts::
	.byte 0

Route2_House_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROUTE2_NUGGET, Route2_House_EventScript_ManAfter
	msgbox Route2_House_Text_Fisher, MSGBOX_DEFAULT 
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_ROUTE2_NUGGET
	release
	end

Route2_House_EventScript_ManAfter::
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_House_Text_Fisher:
	.string "Hé! J'suis content de te voir.\p"
	.string "Ca fait longtemps qu'on ne m'a\n"
	.string "pas rendu visite.\p"
	.string "Et pour la peine, je vais\n"
	.string "t'offrir un p'tit cadeau.$"

Route2_House_Text_Fisher_GotNugget:
	.string "C’est ma Pépite. Prends-en soin!\p"
	.string "C’est ma Pépite, quand même!$"
