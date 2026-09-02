TrainerHill_Entrance_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_hns_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_hns_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_hns_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_hns_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_hns_OnFrame
	.byte 0

TrainerHill_Entrance_hns_OnTransition:
	clearflag FLAG_LIMIT_TO_50
	calculatemonstats
	setflag FLAG_TEMP_HIDE_FOLLOWER
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerHill_Entrance_hns_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_TryFaceAttendant
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_hns_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_hns_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_hns_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_hns_OnReturn:
	addobject LOCALID_TRAINER_HILL_HNS_NURSE
	addobject LOCALID_TRAINER_HILL_HNS_ATTENDANT
	addobject LOCALID_TRAINER_HILL_HNS_MAN
	addobject LOCALID_TRAINER_HILL_HNS_GIRL
	end

TrainerHill_Entrance_hns_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_hns_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_hns_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_hns_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_hns_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_hns_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_hns_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_Entrance_hns_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_hns_EventScript_WarpToEntranceCounter::
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE_HNS, 9, 6
	waitstate
	end

TrainerHill_Entrance_hns_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_hns_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_hns_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_hns_EventScript_EndExitChallenge

TrainerHill_Entrance_hns_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_hns_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_PlayerExitChallenge

TrainerHill_Entrance_hns_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_hns_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_hns_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_hns_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_HNS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_hns_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_hns_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AttendantEnd

TrainerHill_Entrance_hns_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_hns_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_hns_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_Closed
	msgbox TrainerHill_Entrance_hns_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_hns_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_hns_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers

TrainerHill_Entrance_hns_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_hns_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_hns_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_hns_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_hns_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_hns_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_hns_EventScript_CancelEntry
	end

TrainerHill_Entrance_hns_EventScript_Info::
	msgbox TrainerHill_Entrance_hns_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_hns_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_hns_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_hns_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_hns_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_hns_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_hns_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_hns_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_hns_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_hns_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_hns_EventScript_CancelEntry
	end

TrainerHill_Entrance_hns_EventScript_Closed::
	msgbox TrainerHill_Entrance_hns_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_hns_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_hns_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

TrainerHill_Entrance_hns_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_hns_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_hns_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_hns_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_hns_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Man2::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed2
	msgbox TrainerHill_Entrance_hns_Text_Money, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_ManTrainerHillClosed2::
	msgbox TrainerHill_Entrance_hns_Text_HereToGetMoney, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_hns_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_hns_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_hns_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_hns_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerHill_Entrance_hns_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

TrainerHill_Entrance_hns_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_hns_Pokemart_Basic:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

TrainerHill_Entrance_hns_Text_HereToGetMoney:
	.string "Je suis ici pour gagner de\n"
	.string "l'argent! Pourquoi? Parce que\p"
	.string "chaque arrivée au sommet\n"
	.string "rapporte une récompense!\p"
	.string "Je me demande quand ils\n"
	.string "ouvriront enfin. J'ai hâte!$"

TrainerHill_Entrance_hns_Text_Money:
	.string "Chaque fois que tu atteins le\n"
	.string "sommet, tu gagnes de l'argent.\p"
	.string "On peut gagner jusqu'à 1 000\n"
	.string "000¥ en terminant en moins de\p"
	.string "dix minutes!\p"
	.string "Au-delà, la récompense\n"
	.string "diminue...$"

TrainerHill_Entrance_hns_Text_StillGettingReady:
	.string "C’est le MONT DRESSEURS. Ici,\n"
	.string "vous pouvez combattre contre\p"
	.string "plein de DRESSEURS.\p"
	.string "Malheureusement, on est en\n"
	.string "pleine préparation. Revenez plus\p"
	.string "tard!$"

TrainerHill_Entrance_hns_Text_WelcomeToTrainerHill:
	.string "Bienvenue!\p"
	.string "C’est le MONT DRESSEURS. Ici,\n"
	.string "vous pouvez combattre contre\p"
	.string "plein de DRESSEURS.$"

TrainerHill_Entrance_hns_Text_SaveGameBeforeEnter:
	.string "C’est votre première visite ici?\p"
	.string "Avant d’entrer, vous devez\n"
	.string "sauvegarder la partie.$"

TrainerHill_Entrance_hns_Text_TrainersUpToFloorX:
	.string "Voyons voir… Les DRESSEURS ici\n"
	.string "présents sont…\p"
	.string "Ils sont jusqu’au niveau nº\n"
	.string "{STR_VAR_1}.$"

TrainerHill_Entrance_hns_Text_TrainersInEveryRoom:
	.string "Voyons voir… Les DRESSEURS ici\n"
	.string "présents sont…\p"
	.string "On dirait qu’il y a des\n"
	.string "DRESSEURS dans toutes les\p"
	.string "salles.$"

TrainerHill_Entrance_hns_Text_LikeToChallengeTrainers:
	.string "Voulez-vous affronter les\n"
	.string "DRESSEURS qui patientent?$"

TrainerHill_Entrance_hns_Text_TimeProgessGetSetGo:
	.string "OK, je compte sur vous pour\n"
	.string "avoir un beau spectacle.\p"
	.string "Je mets le chrono en marche.\p"
	.string "A vos marques…\p"
	.string "Prêts…\p"
	.string "Partez!$"

TrainerHill_Entrance_hns_Text_PleaseVisitUsAgain:
	.string "J’espère que vous reviendrez.$"

TrainerHill_Entrance_hns_Text_TooBadTremendousEffort:
	.string "Quel dommage.\p"
	.string "Vous avez pourtant fait de votre\n"
	.string "mieux.\p"
	.string "Mais n’hésitez pas à revenir\n"
	.string "nous voir.$"

TrainerHill_Entrance_hns_Text_HopeYouGiveItYourBest:
	.string "Faites de votre mieux!$"

TrainerHill_Entrance_hns_Text_MovedReceptionHereForSwitch:
	.string "Ça peut être assez mouvementé\n"
	.string "quand les DRESSEURS changent\p"
	.string "de place. C’est pour ça qu’on\n"
	.string "est installés ici.\p"
	.string "Désolé pour ça.$"

TrainerHill_Entrance_hns_Text_ThankYouForPlaying:
	.string "Merci d’avoir participé!$"

TrainerHill_Entrance_hns_Text_ExplainTrainerHill:
	.string "Au MONT DRESSEURS, il y a une\n"
	.string "épreuve de Contre-la-Montre.\p"
	.string "Vous devez aller de ce guichet\n"
	.string "au propriétaire qui se trouve\p"
	.string "sur le toit le plus vite\n"
	.string "possible.\p"
	.string "Les meilleurs temps sont\n"
	.string "affichés sur le Panneau des\p"
	.string "Temps. Essayez de défier vos\n"
	.string "amis!\p"
	.string "Vous ne gagnerez pas de points\n"
	.string "EXP. ni d’argent en battant les\p"
	.string "DRESSEURS sur votre chemin.$"

TrainerHill_Entrance_hns_Text_WhatSortOfTrainersAreAhead:
	.string "Qui sait quels DRESSEURS et\n"
	.string "quels POKéMON se trouvent sur\p"
	.string "mon chemin…\p"
	.string "Tout ce que je sais, c’est que\n"
	.string "rien ne m’arrêtera!$"

TrainerHill_Entrance_hns_Text_CantWaitToTestTheWaters:
	.string "Les DRESSEURS viennent de\n"
	.string "partout pour grimper sur le MONT\p"
	.string "DRESSEURS.\p"
	.string "J’ai hâte de commencer!\p"
	.string "J’écraserai tout ceux qui se\n"
	.string "trouveront sur mon passage!$"

TrainerHill_Entrance_hns_Text_FriendsTryingToReachTimeBoardTop:
	.string "Tu vois ce Panneau des Temps?\p"
	.string "Mes amis et moi voulons voir qui\n"
	.string "arrivera en haut le plus vite.$"

TrainerHill_Entrance_hns_Text_DoYouKnowWhenTheyOpen:
	.string "Tu sais quand est-ce que ça va\n"
	.string "ouvrir?\p"
	.string "J’attends ici car je veux être\n"
	.string "le premier DRESSEUR à entrer!$"
