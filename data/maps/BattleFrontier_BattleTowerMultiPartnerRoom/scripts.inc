BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Veuillez choisir le DRESSEUR qui\n"
	.string "sera votre partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, vous n’avez pas trouvé\n"
	.string "de partenaire.\p"
	.string "Voulez-vous arrêter de chercher\n"
	.string "et retourner au guichet\p"
	.string "d’inscription?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Alors je vous prie de choisir\n"
	.string "l’un de ces DRESSEURS comme\p"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Merci d’avoir choisi un\n"
	.string "partenaire.\p"
	.string "Je vais maintenant vous mener à\n"
	.string "votre SALLE DE COMBAT MULTI.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Je suis le disciple nº\n"
	.string "{STR_VAR_2} de {STR_VAR_1}.\p"
	.string "Appelez-moi {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Sur les conseils de {STR_VAR_1},\n"
	.string "j'ai amené un {STR_VAR_3} avec\p"
	.string "{STR_VAR_2}, et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Laissez-moi faire équipe avec\n"
	.string "vous.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Merci! Je vais m'inscrire tout\n"
	.string "de suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Je voulais vraiment faire équipe\n"
	.string "avec vous, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Je suis le disciple nº\n"
	.string "{STR_VAR_2} de {STR_VAR_1}. Je\p"
	.string "m'appelle {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "J'ai suivi les conseils de\n"
	.string "{STR_VAR_1} et choisi un\p"
	.string "{STR_VAR_3} avec {STR_VAR_2}, et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "S'il vous plaît, faisons équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Merci beaucoup! Mon inscription\n"
	.string "sera vite terminée!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, j'espérais pouvoir\n"
	.string "faire équipe avec vous…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Hum, je m’appelle {STR_VAR_3}.\n"
	.string "Je suis l’apprenti nº\p"
	.string "{STR_VAR_1} de {STR_VAR_2}.\p"
	.string "Sniff…\p"
	.string "Je suis désolé! Je ne supporte\n"
	.string "pas cette pression…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} m’a conseillé. J’ai\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1}\p"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Sniff… S’il te plaît, fais\n"
	.string "équipe avec moi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Vraiment? Tu veux bien? Super!\n"
	.string "Extra!\p"
	.string "Oh… Je suis désolé… Ce sont des\n"
	.string "larmes de joie…\p"
	.string "Je vais nous inscrire tout de\n"
	.string "suite. Surtout, reste ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, mais… Sniff… Ouin!!!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Bonjour! Je suis {STR_VAR_3}! Je\n"
	.string "suis l’apprenti nº {STR_VAR_1}\p"
	.string "de {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} a choisi mon équipe!\n"
	.string "J’ai un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}! Plutôt pas mal,\p"
	.string "hein?\p"
	.string "Allez, vas-y! Fais équipe avec\n"
	.string "moi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Ouais, super! Je vais\n"
	.string "m’inscrire, alors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Mais pourquoi, d’abord? Je veux\n"
	.string "faire équipe avec toi, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Je suis {STR_VAR_3}, l’apprenti\n"
	.string "nº {STR_VAR_2} de {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "J’ai demandé conseil à\n"
	.string "{STR_VAR_3}. Un {STR_VAR_1} qui\p"
	.string "utilise {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}, voilà ce que j’ai.\p"
	.string "S’il te plaît, tu veux bien\n"
	.string "faire équipe avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Merci! Je vais nous inscrire\n"
	.string "tout de suite!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, j’avais tellement\n"
	.string "envie de faire équipe avec toi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Oh… Ça me fait plaisir que tu\n"
	.string "viennes me parler.\p"
	.string "Je m’appelle {STR_VAR_3}. Je\n"
	.string "suis l’apprentie nº {STR_VAR_1}\p"
	.string "de {STR_VAR_2}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} a bien voulu me\n"
	.string "conseiller. Je lui dois tant de\p"
	.string "choses!\p"
	.string "Dans mon équipe, j’ai un\n"
	.string "{STR_VAR_2} qui utilise\p"
	.string "{STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "{STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}. Je sais que j’en\p"
	.string "demande trop…\p"
	.string "Tu vas sûrement refuser, mais tu\n"
	.string "veux bien qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Vraiment? Je n’arrive pas à le\n"
	.string "croire! On va faire équipe! Je…\p"
	.string "Je serai à la hauteur!\p"
	.string "Bon… Je vais vite nous inscrire\n"
	.string "avant que tu ne changes d’avis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Je comprends… Je ne suis pas à\n"
	.string "la hauteur…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Salut, je m’appelle {STR_VAR_3}.\n"
	.string "Je suis l’apprentie nº\p"
	.string "{STR_VAR_1} de {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "C’est {STR_VAR_3} qui a fait mon\n"
	.string "équipe! J’ai un {STR_VAR_1} avec\p"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "et un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}.\p"
	.string "Pas mal, non? Alors, on fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "D’accord! J’espère qu’on va bien\n"
	.string "s’entendre! Je vais nous\p"
	.string "inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Quoi? Tu refuses? Tu ne sais pas\n"
	.string "ce que tu perds!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Je m’appelle {STR_VAR_3}. Je\n"
	.string "suis TRIATHLETE. Je n’arrête\p"
	.string "pas! Footing, entraînement,\n"
	.string "danse…\p"
	.string "Et je suis aussi l’apprenti nº\n"
	.string "{STR_VAR_1} de {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "Voilà ce que {STR_VAR_3} m’a\n"
	.string "conseillé. Un {STR_VAR_1} qui\p"
	.string "utilise {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "et un {STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2}.\p"
	.string "Malgré tout ce que j’ai à faire,\n"
	.string "j’ai trouvé le temps de les\p"
	.string "dresser!\p"
	.string "On fait équipe et on voit ce que\n"
	.string "ça donne?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Merci! Tu as l’esprit sportif!\n"
	.string "Ne bouge pas, je vais nous\p"
	.string "inscrire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "Je vois. Pour ta gouverne, je\n"
	.string "déteste qu’on me fasse perdre\p"
	.string "mon temps!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Bonjour! Comment ça va?\p"
	.string "Je suis {STR_VAR_3}, l’apprentie\n"
	.string "nº {STR_VAR_1} de {STR_VAR_2}.\p"
	.string "Enchantée!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Ecoute, écoute! C’est\n"
	.string "{STR_VAR_3} qui a composé mon\p"
	.string "équipe POKéMON. J’ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}. Je les ai bien\p"
	.string "dressés!\p"
	.string "Tu veux qu’on fasse équipe? Je\n"
	.string "suis sûre qu’on ira bien\p"
	.string "ensemble!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Super, on va bien s’amuser! Je\n"
	.string "vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Quelle méchanceté! Je suis sûre\n"
	.string "que tu vas le regretter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Je me présente, je m’appelle\n"
	.string "{STR_VAR_3}.\p"
	.string "Je suis l’apprentie nº\n"
	.string "{STR_VAR_1} de {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "J’ai suivi les conseils de\n"
	.string "{STR_VAR_3} et dans mon équipe\p"
	.string "j’ai un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}.\p"
	.string "On fait équipe ensemble? S’il te\n"
	.string "plaît!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… J’en suis ravie! Je vais\n"
	.string "donner tout ce que j’ai!\p"
	.string "Allez, je vais nous inscrire!\n"
	.string "Attends-moi ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "J’espérais vraiment être ta\n"
	.string "partenaire, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Hé, tu m’as parlée! Ça me fait\n"
	.string "tellement plaisir!\p"
	.string "Je m’appelle {STR_VAR_3}! Je\n"
	.string "suis l’apprentie nº {STR_VAR_1}\p"
	.string "de {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "J’ai écouté {STR_VAR_3} et j’ai\n"
	.string "dressé un {STR_VAR_1} qui\p"
	.string "utilise {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "et un {STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2}.\p"
	.string "Tu veux bien exaucer mon\n"
	.string "souhait? J’aimerais faire équipe\p"
	.string "avec toi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Oh… C’est un jour merveilleux!\n"
	.string "Merci infiniment! Je vais nous\p"
	.string "inscrire sur le champ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Oh! Tu n’as donc aucun cœur?\n"
	.string "Mais je t’admire, tu sais…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Bonjour! Je suis l’apprenti nº\n"
	.string "{STR_VAR_1} de {STR_VAR_2}!\p"
	.string "Je m’appelle {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mon mentor {STR_VAR_3} m’a\n"
	.string "conseillé un {STR_VAR_1} avec\p"
	.string "{STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "un {STR_VAR_1} avec {STR_VAR_2}.\p"
	.string "Pas mal, non? On fait équipe,\n"
	.string "alors?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Excellent! Je vais nous inscrire\n"
	.string "vite fait!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Je me méfierai de toi à\n"
	.string "l’avenir, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Tu sais quoi? C’est le dernier\n"
	.string "jour de la TOUR DE COMBAT!\p"
	.string "… … … … … … Mais non, je rigole!\p"
	.string "On m’appelle {STR_VAR_3}.\n"
	.string "Normal, c’est mon nom! Je suis\p"
	.string "l’apprenti nº 1 000 de\n"
	.string "{STR_VAR_1}. Non, je suis le nº\p"
	.string "{STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} m’a recommandé les\n"
	.string "{STR_VAR_2} utilisant\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "et les {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}. J’en ai dix de\p"
	.string "chaque. Je rigole, j’en ai qu’un\n"
	.string "de chaque!\p"
	.string "Alors, on fait équipe, toi et\n"
	.string "moi? Qu’en dis-tu?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Youpi! Allez, je te donne un\n"
	.string "POKéMON!\p"
	.string "Tu m’as pas cru, j’espère! Je\n"
	.string "passe au guichet d’inscription\p"
	.string "et je reviens!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Tu me le paieras! Je vais faire\n"
	.string "de ta vie un enfer!\p"
	.string "Mais non, je rigole! Ha, ha, ha!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Salut, DRESSEUR! J’attends ici\n"
	.string "depuis des heures!\p"
	.string "Non, je ne suis pas un requin\n"
	.string "blanc… Je suis {STR_VAR_3}, le\p"
	.string "MARIN chantant!\p"
	.string "Je suis l’apprenti nº\n"
	.string "{STR_VAR_1} de {STR_VAR_2}. Avec\p"
	.string "moi, ça va swinguer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Les conseils de {STR_VAR_3}, je\n"
	.string "les ai suivis, et mon équipe a\p"
	.string "bien grandi! J’ai un {STR_VAR_1}\n"
	.string "avec {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "et un {STR_VAR_1} avec\n"
	.string "{STR_VAR_2}!\p"
	.string "Faisons équipe, nom d’une pipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hé, hé, j’aime ton style! Je\n"
	.string "vais nous inscrire, je file!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Hé, {PLAYER}! Tu me surprends!\n"
	.string "Moi, j’étais partant!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yahou, yippie! Oh, je t’en prie,\n"
	.string "reste!\p"
	.string "Je m’appelle {STR_VAR_3}! Je\n"
	.string "suis l’apprenti nº {STR_VAR_1}\p"
	.string "de {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} m’a dit quoi faire.\n"
	.string "J’ai un {STR_VAR_1} avec\p"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "et un {STR_VAR_1} avec\n"
	.string "{STR_VAR_2}.\p"
	.string "Qu’en dis-tu? Me choisiras-tu?\p"
	.string "Laisse-moi être ton partenaire!\n"
	.string "Allez… Accepte, partenaire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Oh, ça me fait tellement\n"
	.string "plaisir! Je ne sais pas quoi\p"
	.string "dire!\p"
	.string "Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Tu me rejettes? {PLAYER}, ton\n"
	.string "comportement est abject!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Oh, je tousse!\p"
	.string "Désolé, j’ai pris froid. Mes\n"
	.string "POKéMON vont bien, eux.\p"
	.string "Je m’appelle {STR_VAR_3}. Je\n"
	.string "suis l’apprenti nº {STR_VAR_1}\p"
	.string "de {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "{STR_VAR_3} a formé mon équipe.\n"
	.string "J’ai un {STR_VAR_2} qui utilise\p"
	.string "{STR_VAR_1} et aussi un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "{STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Je les entraîne tous les jours,\n"
	.string "qu’il pleuve, qu’il neige, qu’il\p"
	.string "vente!\p"
	.string "C’est d’ailleurs pour ça que\n"
	.string "j’ai pris froid, je pense.\p"
	.string "Maintenant que tu me connais un\n"
	.string "peu, tu veux qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Merci! Ça me fait plaisir! Je\n"
	.string "n’arrête pas de tousser…  Allez,\p"
	.string "je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Tu ne veux pas? Quel dommage,\n"
	.string "{PLAYER}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Bonjour! Il y a trop de monde,\n"
	.string "ici…\p"
	.string "Je m’appelle {STR_VAR_3}. Je\n"
	.string "suis l’apprenti nº {STR_VAR_2}\p"
	.string "de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} m’a conseillé cette\n"
	.string "équipe…  Un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ça me met mal à l’aise de te\n"
	.string "parler…  Mais veux-tu qu’on\p"
	.string "fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, merci! J’ai peur mais je\n"
	.string "ferai de mon mieux!\p"
	.string "Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Tu ne peux pas refuser! Je crois\n"
	.string "que je vais faire un malaise…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Je m’appelle {STR_VAR_3}, je\n"
	.string "suis l’apprenti nº {STR_VAR_1}\p"
	.string "de {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "Je dois mon équipe à\n"
	.string "{STR_VAR_3}.\p"
	.string "J’ai suivi ses conseils. J’ai un\n"
	.string "{STR_VAR_1} avec {STR_VAR_2} et\p"
	.string "un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{STR_VAR_1} avec {STR_VAR_2}.\p"
	.string "Si tu es d’accord, j’aimerais\n"
	.string "être ton partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Tu acceptes? Tu ne le\n"
	.string "regretteras pas!\p"
	.string "Je vais nous inscrire et nous\n"
	.string "pourrons commencer!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Tu refuses? Ton humour est\n"
	.string "totalement déplacé.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Je m’appelle {STR_VAR_1}. Je\n"
	.string "suis une FILLETTE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "J’ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et puis un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}. C’est tout ce que\p"
	.string "j’ai avec moi.\p"
	.string "On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Merci! Je vais nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Tu ne veux pas de moi comme\n"
	.string "partenaire? Tu vas t’en mordre\p"
	.string "les doigts!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Salut!\p"
	.string "Je suis GAMIN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Tu veux savoir ce que j’ai? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On va faire équipe, toi et moi,\n"
	.string "non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Chouette! Je vais nous inscrire,\n"
	.string "alors!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Tu as tort! Avec tes POKéMON et\n"
	.string "les miens, on serait\p"
	.string "invincibles!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Bien le bonjour! Je suis\n"
	.string "MONTAGNARD {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Tu veux savoir ce que j’ai avec\n"
	.string "moi? Un {STR_VAR_1} qui utilise\p"
	.string "{STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "et un {STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2}!\p"
	.string "Pas trop mal, non? Tu veux qu’on\n"
	.string "fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "D’accord! Je vais au guichet et\n"
	.string "je reviens.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "Dommage, j’aurais aimé me battre\n"
	.string "à tes côtés.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Bonjour! Je m’appelle\n"
	.string "{STR_VAR_1} et je suis un CANON!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Tu sais ce que j’ai dressé? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu’en penses-tu? Tu veux qu’on\n"
	.string "fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Merveilleux! Je vais au guichet!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Quel dommage!\p"
	.string "Toi et moi, nous aurions fait\n"
	.string "une belle équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Bonjour, toi!\p"
	.string "Tu sais qui je suis? Je suis\n"
	.string "{STR_VAR_1} le PECHEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "Mon équipe se compose d’un\n"
	.string "{STR_VAR_1} avec {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "d’un {STR_VAR_1} avec\n"
	.string "{STR_VAR_2}.\p"
	.string "Qu’en dis-tu? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bien, bien! Je me charge de\n"
	.string "tout!\p"
	.string "Je vais nous inscrire tout de\n"
	.string "suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "Oh, c’est bien dommage…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Ravie de te rencontrer. Je suis\n"
	.string "MADEMOISELLE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Je suis accompagnée d’un\n"
	.string "{STR_VAR_2} maîtrisant\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "et d’un {STR_VAR_2} maîtrisant\n"
	.string "{STR_VAR_1}.\p"
	.string "M’acceptes-tu comme partenaire?\n"
	.string "Cela me ferait tant plaisir!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Je te remercie du fond du cœur.\n"
	.string "Je m’occupe de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Je suis sûre que tu vas le\n"
	.string "regretter. Cependant, je\p"
	.string "respecte ta décision.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Je m'appelle {STR_VAR_1}. Je\n"
	.string "suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Voyons ce que j’ai… Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "C’est mon équipe!\p"
	.string "Dis, tu veux bien qu’on soit\n"
	.string "partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Merci! Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "C’est dommage, je sais qu’on\n"
	.string "aurait été très forts ensemble!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Bonjour! Je suis le SCOUT\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Regarde ce que j’ai! Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Je te propose que nous fassions\n"
	.string "équipe, tous les deux! Tu es\p"
	.string "d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Bien!\p"
	.string "Je m’occupe de l’inscription,\n"
	.string "partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Tu sais, mes POKéMON valent le\n"
	.string "détour. J’espère que tu ne le\p"
	.string "regretteras pas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Bonjour! Je suis l’ELEVE\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "J’ai dressé un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "{STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "C’est plutôt bien, non? Tu veux\n"
	.string "qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Merci! Je m’occupe de\n"
	.string "l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "Je suis déçu…\p"
	.string "En me battant avec toi, j’aurais\n"
	.string "pu apprendre un tas de choses…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Bonjour. Je suis RICHARD\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Tu ne devineras jamais ce que\n"
	.string "j’ai! Un {STR_VAR_2} utilisant\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Si tu le souhaites, tu peux\n"
	.string "faire équipe avec moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "C’est intelligent de ta part!\n"
	.string "Avec moi, impossible de perdre!\p"
	.string "Je m’occupe de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Tu vas le regretter! Je suis le\n"
	.string "meilleur dans cette pièce!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah! Je suis KARATEKA\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "J’ai un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Sois sympa, choisis-moi comme\n"
	.string "partenaire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah! Je vais nous inscrire\n"
	.string "illico presto!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Je comprends… Ce n’est que\n"
	.string "partie remise…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Bonjour! Je suis FLOTTEUR\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Voilà ce que j’ai… Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\n"
	.string "Tu veux bien qu’on fasse équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Merci! Je vais nous inscrire\n"
	.string "immédiatement!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Ensemble, on aurait pu battre\n"
	.string "n’importe qui, j’en suis sûre!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Bien le bonjour… Je suis\n"
	.string "MYSTIMANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "J’ai sur moi un {STR_VAR_1} qui\n"
	.string "utilise {STR_VAR_2} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2}…\p"
	.string "Je t’en supplie… Choisis-moi\n"
	.string "comme partenaire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Je te remercie… Je vais nous\n"
	.string "inscrire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "J’espérais tant qu’on fasse\n"
	.string "équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Comment ça va? Je m’appelle\n"
	.string "{STR_VAR_1}. Je suis un ELEVEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "J’ai deux POKéMON pas mal du\n"
	.string "tout! Un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Qu’en penses-tu? Tu penses qu’on\n"
	.string "devrait faire équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Je te remercie!\p"
	.string "Ne bouge pas, je vais au guichet\n"
	.string "d’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "J’aurais préféré que tu dises\n"
	.string "oui, bien sûr… Mais tant pis!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Bonjour! Je m’appelle\n"
	.string "{STR_VAR_1}. Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Tu veux savoir ce que j’ai? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Alors? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "C’est parti! Je vais nous\n"
	.string "inscrire sur le champ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Toi et moi, on aurait fait un\n"
	.string "carton! Tu ne sais pas ce que tu\p"
	.string "rates…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Bonjour! Je m’appelle\n"
	.string "{STR_VAR_1}! Je suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "J’ai bien entraîné mes POKéMON!\n"
	.string "J’ai un {STR_VAR_2} qui utilise\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Il y a pire, non? Tu veux de moi\n"
	.string "comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "Très bien! Je cours nous\n"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "J’aurais bien aimé combattre à\n"
	.string "tes côtés…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Je suis COMBATTANTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "J’ai dressé un {STR_VAR_1} qui\n"
	.string "utilise {STR_VAR_2} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "{STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2}!\p"
	.string "Alors, ça te plaît? Si on\n"
	.string "faisait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Oh, merci!\p"
	.string "Je m’occupe de l’inscription, ne\n"
	.string "bouge pas!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Je suis sûre qu’ensemble, on\n"
	.string "aurait été imbattables…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Je m'appelle {STR_VAR_1}. Je\n"
	.string "suis TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "J’ai un {STR_VAR_2} à qui j’ai\n"
	.string "appris {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "{STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}!\p"
	.string "On ferait une équipe du\n"
	.string "tonnerre, tous les deux! Non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Merci!\p"
	.string "Il ne reste plus qu’à nous\n"
	.string "inscrire. J’y cours!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "C’est dommage. Je me faisais une\n"
	.string "telle joie à l’idée de combattre\p"
	.string "à tes côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Moi? Je suis FLOTTEUR\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Ce que j’ai? Un {STR_VAR_2} qui\n"
	.string "connaît {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}!\p"
	.string "Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "D’accord!\p"
	.string "Je vais nous inscrire! Ça va\n"
	.string "déménager!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Mes POKéMON sont forts… C’est\n"
	.string "bête que tu ne veuilles pas de\p"
	.string "moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Bonjour! Je suis GUITARISTE\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Regarde qui est là… Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "On pourrait pas rêver mieux,\n"
	.string "non? Alors, on fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Super! Je vais m’occuper des\n"
	.string "formalités au guichet. Je\p"
	.string "reviens!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Mes POKéMON sont les meilleurs!\n"
	.string "Tu risques de le regretter!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Ravi de faire ta connaissance.\n"
	.string "Je suis {STR_VAR_1}, un vrai\p"
	.string "GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Mon cher {STR_VAR_1} avec\n"
	.string "{STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "mon cher {STR_VAR_1} avec\n"
	.string "{STR_VAR_2} sont ici.\p"
	.string "Puis-je te demander de me\n"
	.string "choisir comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Je te remercie de ta confiance.\n"
	.string "Reste ici, je m’occupe de\p"
	.string "l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "Cela m’aurait fait tant plaisir…\p"
	.string "J’espère que nous aurons\n"
	.string "l’occasion de faire équipe une\p"
	.string "autre fois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Bonjour, je m’appelle\n"
	.string "{STR_VAR_1}. Je suis POKéFAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "Avec moi, j’ai un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Est-ce que ça te plaît? On fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Merci! Je m’occupe de\n"
	.string "l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Tu ne sais pas reconnaître de\n"
	.string "bons POKéMON quand tu en vois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Je suis {STR_VAR_1}. Je suis un\n"
	.string "EXPERT!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "J’ai élevé un {STR_VAR_2} qui\n"
	.string "connaît {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "{STR_VAR_2} qui connaît\n"
	.string "{STR_VAR_1}!\p"
	.string "Que dirais-tu de faire équipe\n"
	.string "avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Parfait! Je vais de ce pas nous\n"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "Je doute que tu aies fait le bon\n"
	.string "choix…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Bonjour, bonjour! Je suis EXPERT\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "J’ai élevé mes POKéMON avec\n"
	.string "soin. J’ai un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}. Voilà!\p"
	.string "Voudrais-tu faire équipe avec\n"
	.string "moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bien, bien. Je vais de suite\n"
	.string "nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "D’accord. On remet ça à une\n"
	.string "prochaine fois, alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Je suis DRACOLOGUE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "Mon équipe se compose d’un\n"
	.string "{STR_VAR_2} utilisant\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "et d’un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Qu’est-ce que tu en dis? Tu me\n"
	.string "prends comme partenaire?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Je te promets de faire de mon\n"
	.string "mieux! Je m’occupe de\p"
	.string "l’inscription, d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Tu sais, tu ne trouveras pas\n"
	.string "mieux que moi, ici!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Je suis l’ORNITHOLOGUE\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quels POKéMON j’ai? Un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "et un {STR_VAR_2} avec\n"
	.string "{STR_VAR_1}.\p"
	.string "Tu ne penses pas qu’on ferait\n"
	.string "une bonne équipe, toi et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Super, merci! Je vais m’occuper\n"
	.string "de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mes POKéMON et moi sommes très\n"
	.string "forts. Quel dommage pour toi!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Je suis NINJA FAN {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mon équipe de POKéMON comporte\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1}\p"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Faisons équipe, tous les deux!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Ouais! Je me charge de\n"
	.string "l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Tu vas regretter de ne pas avoir\n"
	.string "mes POKéMON à tes côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Bonjour! Je suis SŒUR PARASOL\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Je ne suis pas seule. J’ai avec\n"
	.string "moi un {STR_VAR_2} utilisant\p"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "N’est-ce pas merveilleux? Tu\n"
	.string "veux faire équipe avec nous?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Merci beaucoup!\p"
	.string "Je vais nous inscrire au\n"
	.string "guichet. Nous ferons de notre\p"
	.string "mieux!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mes POKéMON sont incroyablement\n"
	.string "forts. Quelle déception…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Bonjour! Je suis {STR_VAR_1}\n"
	.string "l’ENTOMOMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "Oui, j’ai trouvé mes POKéMON.\n"
	.string "J’ai un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "et {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "C’est tout ce que j’ai trouvé.\p"
	.string "Ça t’intéresse de faire équipe\n"
	.string "avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Compris! Super!\p"
	.string "Je m’occupe de l’inscription. Ça\n"
	.string "ne prendra pas longtemps!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Avec mes POKéMON, on aurait\n"
	.string "gagné à coup sûr, tu sais?…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Bonjour! Je suis MARIN\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Mes POKéMON sont ma fierté! J’ai\n"
	.string "un {STR_VAR_2} utilisant\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec moi,\n"
	.string "n’est-ce pas?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "J’en étais sûr! Je m’occupe de\n"
	.string "l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "Avec mes POKéMON et moi, c’était\n"
	.string "pourtant la victoire assurée!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Bonjour, je suis COLLEC\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "J’ai ici deux beaux spécimens:\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1}\p"
	.string "et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "C’est le nec plus ultra en\n"
	.string "matière de POKéMON, non? On fait\p"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, super!\p"
	.string "Ne perdons pas de temps. Je vais\n"
	.string "nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Ça me chiffonne un peu… Tu\n"
	.string "n’aimes pas mes POKéMON…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Bonjour, je m’appelle\n"
	.string "{STR_VAR_1}. Je suis un POKéMON\p"
	.string "RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Je suis escorté par un\n"
	.string "{STR_VAR_1} qui utilise\p"
	.string "{STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Tu ne penses pas qu’on ferait\n"
	.string "une équipe du tonnerre, toi et\p"
	.string "moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "C’est super! Je vais m’occuper\n"
	.string "de l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La prochaine fois, choisis mes\n"
	.string "POKéMON où je risque de me\p"
	.string "vexer…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Je suis {STR_VAR_1}, une POKéMON\n"
	.string "RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Voici mon équipe: j’ai un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}!\p"
	.string "Tu veux faire équipe avec mes\n"
	.string "petits protégés et moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "Nous ferons de notre mieux,\n"
	.string "c’est promis! Je vais nous\p"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "J’espère que tu nous choisiras,\n"
	.string "la prochaine fois…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Ravie de faire ta connaissance.\n"
	.string "Je suis AROMA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Je sillonne les chemins avec un\n"
	.string "{STR_VAR_2} utilisant\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "J’espère qu’ils te conviennent.\n"
	.string "Tu veux bien qu’on soit\p"
	.string "partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Ton choix m’honore. Je vais au\n"
	.string "guichet d’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Cela me ferait plaisir de faire\n"
	.string "équipe avec toi une prochaine\p"
	.string "fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Tu veux savoir qui je suis? Je\n"
	.string "suis RUINEMANIAC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Les POKéMON qui m’accompagnent\n"
	.string "sont un {STR_VAR_2} utilisant\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}!\p"
	.string "Intrigant, n’est-ce pas? Si nous\n"
	.string "faisions équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "C’est une sage décision! Je me\n"
	.string "charge des formalités\p"
	.string "d’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hum… Mes POKéMON sont très forts\n"
	.string "pourtant…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "J’ai amené un {STR_VAR_2} qui\n"
	.string "sait utiliser {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}. Impressionnant, je\p"
	.string "sais!\p"
	.string "Dis, tu ne crois pas qu’on\n"
	.string "devrait faire équipe, toi et\p"
	.string "moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool! Je vais vite au guichet\n"
	.string "d’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "On aurait pourtant bien combattu\n"
	.string "ensemble.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Je suis TOPDRESSEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "L’équipe que j’ai formée\n"
	.string "comporte un {STR_VAR_2}\p"
	.string "utilisant {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "Ça correspond à ce que tu\n"
	.string "cherches? On fait équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "J’espérais que tu dirais ça! Je\n"
	.string "vais nous inscrire, alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Je pensais qu’on aurait fait une\n"
	.string "belle équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Bonjour! Je suis POKéMANIAC\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Tu te demandes ce que j’ai? Un\n"
	.string "{STR_VAR_2} qui utilise\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}. Oui, rien que ça!\p"
	.string "Je sais que ça t’impressionne.\n"
	.string "Allez, faisons équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Excellente décision! Je vais\n"
	.string "nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Rien ne peut arrêter mes\n"
	.string "POKéMON! Tu vas regretter ta\p"
	.string "décision!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Salut, toi! Je m’appelle\n"
	.string "{STR_VAR_1}! Je suis un\p"
	.string "SALTIMBANQUE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Voici le fruit de mon\n"
	.string "entraînement: un {STR_VAR_2} qui\p"
	.string "utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Alors, qu’en dis-tu? On fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "Bien! Je m’occupe de\n"
	.string "l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Quel dommage. Promets-moi qu’on\n"
	.string "fera équipe la prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Je suis CAMPEUR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "J’ai dressé un {STR_VAR_1} qui\n"
	.string "sait utiliser {STR_VAR_2} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1} qui sait utiliser\n"
	.string "{STR_VAR_2}.\p"
	.string "On s’amuserait bien si on était\n"
	.string "dans la même équipe! Alors, on\p"
	.string "essaie?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Super! Sur ce, je vais nous\n"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Bon, une prochaine fois, alors!\n"
	.string "J’aimerais bien combattre à tes\p"
	.string "côtés!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Bonjour! Je suis PIQUE-NIQUE\n"
	.string "{STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "J’ai avec moi un {STR_VAR_2} qui\n"
	.string "utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ça te dirait de faire équipe\n"
	.string "avec moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Eh bien, merci! Je me charge de\n"
	.string "l’inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "D’accord. J’espère qu’on fera\n"
	.string "équipe une prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Je suis KINESISTE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Les deux POKéMON que j’ai\n"
	.string "dressés sont un {STR_VAR_2}\p"
	.string "utilisant {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "Qu’en dis-tu? On est\n"
	.string "partenaires?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Très bien! Je vais nous\n"
	.string "inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "D’accord. Mais tu dois me\n"
	.string "promettre qu’on fera équipe\p"
	.string "bientôt.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Je suis KINESISTE {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "J'ai avec moi… un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Ce sont mes disciples.\p"
	.string "Je suis sûre que tout cela\n"
	.string "t’intrigue… Si tu veux, nous\p"
	.string "pouvons faire équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Merci. Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "J’espère qu’il y aura une autre\n"
	.string "occasion. Tu m’intrigues…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Je suis ELEVE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Mes POKéMON? J'ai un {STR_VAR_1}\n"
	.string "qui utilise {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "un {STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2}.\p"
	.string "Ça me plairait bien d’être ta\n"
	.string "partenaire. Tu es d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Oh, merci! Je vais aller au\n"
	.string "guichet pour nous inscrire!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Hein? La prochaine fois alors,\n"
	.string "non?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Coucou! Je suis {STR_VAR_1}, un\n"
	.string "ELEVEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Voici les POKéMON que j’ai\n"
	.string "dressés: un  {STR_VAR_1} qui\p"
	.string "utilise {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "et un {STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2}.\p"
	.string "C’est plutôt tentant, je sais.\n"
	.string "On fait équipe, d’accord?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Parfait! Laisse-moi m’occuper de\n"
	.string "l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Je comprends, mais la prochaine\n"
	.string "fois, tu ne pourras pas refuser!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Je suis {STR_VAR_1}. Je suis une\n"
	.string "POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Mes POKéMON chéris sont un\n"
	.string "{STR_VAR_2} qui utilise\p"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ne sont-ils pas mignons? Il faut\n"
	.string "absolument qu’on fasse équipe!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Je te remercie! Je m’occupe de\n"
	.string "l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Mes POKéMON chéris sont les\n"
	.string "meilleurs, crois-moi. Mais c’est\p"
	.string "toi qui décides!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Bonjour! Je suis {STR_VAR_1},\n"
	.string "une NAGEUSE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "J'ai entraîné un {STR_VAR_1} qui\n"
	.string "sait utiliser {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "un {STR_VAR_1} qui sait utiliser\n"
	.string "{STR_VAR_2}.\p"
	.string "Si on faisait équipe, toi et\n"
	.string "moi?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "Super! Je vais nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Si jamais on se rencontre de\n"
	.string "nouveau, tu ne pourras pas\p"
	.string "refuser!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Oui? Je m’appelle {STR_VAR_1} et\n"
	.string "je suis TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "J’ai quelques POKéMON qui se\n"
	.string "défendent: un {STR_VAR_2} avec\p"
	.string "{STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Ce serait sympa si on faisait\n"
	.string "équipe, tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Merveilleux! Je vais nous\n"
	.string "inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "Tu me laisseras être ton\n"
	.string "partenaire la prochaine fois,\p"
	.string "j’espère.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Je suis {STR_VAR_1}, une\n"
	.string "TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}, voilà ce que j’ai.\p"
	.string "Qu’en penses-tu? Je pense qu’on\n"
	.string "ferait une bonne équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "J’aime cette réponse! Je\n"
	.string "m’occupe de l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Promets-moi que tu me donneras\n"
	.string "bientôt ma chance…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Bonjour, bonjour! Je suis\n"
	.string "{STR_VAR_1}, un NAGEUR!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Regarde quels POKéMON j’ai\n"
	.string "dressés! Un {STR_VAR_2} qui\p"
	.string "utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}!\p"
	.string "Pas mal, non? Alors, on fait\n"
	.string "équipe?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Quel honneur! Je me charge de\n"
	.string "l’inscription!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "On remet ça à une prochaine\n"
	.string "fois, d’accord?$"

