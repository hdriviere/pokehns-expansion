Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mon grand frère est le MANIAQUE\n"
	.string "DES FOSSILES… C’est un gentil\p"
	.string "garçon passionné de FOSSILES…\p"
	.string "Il adore creuser des trous,\n"
	.string "aussi… Il a creusé ce trou tout\p"
	.string "seul…\p"
	.string "Tiens, prends ça, tu pourras\n"
	.string "utiliser TUNNEL, comme mon grand\p"
	.string "frère…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Si ton POKéMON utilise TUNNEL\n"
	.string "dans une caverne, tu retournes à\p"
	.string "l’entrée…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Des roches aux formes étranges\n"
	.string "sont disposées dans la vitrine.$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSITION DES STRATES… LA\n"
	.string "PLUIE, L’EROSION ET LA TERRE…\p"
	.string "PIERRES, TERRE ET AUTRES\n"
	.string "ROCHERS…\p"
	.string "C’est rempli de livres.$"

