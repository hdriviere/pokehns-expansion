Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "M. MARCO: Attends, mon p’tit!\n"
	.string "PIKO, viens ici!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hein? Tu es {PLAYER}{KUN}! Tu as\n"
	.string "sauvé mon PIKO adoré! Nous te\p"
	.string "devons une fière chandelle!\p"
	.string "Comment? Tu veux embarquer avec\n"
	.string "moi?\p"
	.string "Humm…\p"
	.string "Alors comme ça, tu as une LETTRE\n"
	.string "à destination de MYOKARA et un\p"
	.string "paquet à déposer à POIVRESSEL?\p"
	.string "Tu ne dois pas avoir le temps de\n"
	.string "t’ennuyer!\p"
	.string "Quoi qu’il en soit, pas de\n"
	.string "problème. Je peux t’aider.\p"
	.string "Tu as frappé à la bonne porte!\n"
	.string "On met le cap sur MYOKARA.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "M. MARCO: VILLAGE MYOKARA, nous\n"
	.string "voilà!\p"
	.string "Levons l'ancre! PIKO, mon\n"
	.string "chouchou, on met les voiles!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "M. MARCO: Ah bon? Ta livraison\n"
	.string "peut attendre?\p"
	.string "Dans ce cas, reviens me voir\n"
	.string "quand tu voudras mettre les\p"
	.string "voiles!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "M. MARCO: Ohé! Je vois très bien\n"
	.string "ce que tu veux dire!\p"
	.string "Tu dois livrer une LETTRE à\n"
	.string "MYOKARA et un paquet à\p"
	.string "POIVRESSEL.\p"
	.string "Ça n’me pose pas d’problème. Je\n"
	.string "suis l’homme de la situation!\p"
	.string "On mettra d’abord le cap sur\n"
	.string "MYOKARA.$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "M. MARCO: Ohé! Je vois très bien\n"
	.string "ce que tu veux dire!\p"
	.string "Tu dois livrer un paquet au\n"
	.string "CAPT. POUPE à POIVRESSEL.\p"
	.string "Ça n’me pose pas d’problème. Je\n"
	.string "suis l’homme de la situation!\p"
	.string "On mettra d’abord le cap sur\n"
	.string "MYOKARA.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "M. MARCO: Ohé! Je peux\n"
	.string "appareiller quand tu veux!\p"
	.string "Bien! Où va-t-on, mon pote?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "M. MARCO: Ah bon? Bah, PIKO te\n"
	.string "doit la vie.\p"
	.string "Tu peux revenir quand tu veux et\n"
	.string "je mettrai les voiles pour toi!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PIKO: Pii pi-hiorou!$"

