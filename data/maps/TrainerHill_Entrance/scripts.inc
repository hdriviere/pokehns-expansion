TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "C’est le MONT DRESSEURS. Ici,\n"
	.string "vous pouvez combattre contre\p"
	.string "plein de DRESSEURS.\p"
	.string "Malheureusement, on est en\n"
	.string "pleine préparation. Revenez plus\p"
	.string "tard!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Bienvenue!\p"
	.string "C’est le MONT DRESSEURS. Ici,\n"
	.string "vous pouvez combattre contre\p"
	.string "plein de DRESSEURS.$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "C’est votre première visite ici?\p"
	.string "Avant d’entrer, vous devez\n"
	.string "sauvegarder la partie.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Voyons voir… Les DRESSEURS ici\n"
	.string "présents sont…\p"
	.string "Ils sont jusqu’au niveau nº\n"
	.string "{STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Voyons voir… Les DRESSEURS ici\n"
	.string "présents sont…\p"
	.string "On dirait qu’il y a des\n"
	.string "DRESSEURS dans toutes les\p"
	.string "salles.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Voulez-vous affronter les\n"
	.string "DRESSEURS qui patientent?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "OK, je compte sur vous pour\n"
	.string "avoir un beau spectacle.\p"
	.string "Je mets le chrono en marche.\p"
	.string "A vos marques…\p"
	.string "Prêts…\p"
	.string "Partez!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "J’espère que vous reviendrez.$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Quel dommage.\p"
	.string "Vous avez pourtant fait de votre\n"
	.string "mieux.\p"
	.string "Mais n’hésitez pas à revenir\n"
	.string "nous voir.$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Faites de votre mieux!$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Ça peut être assez mouvementé\n"
	.string "quand les DRESSEURS changent\p"
	.string "de place. C’est pour ça qu’on\n"
	.string "est installés ici.\p"
	.string "Désolé pour ça.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Merci d'avoir participé!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
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

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, désolé, mais vous ne semblez\n"
	.string "avoir qu'un seul POKéMON.\p"
	.string "Il vous en faut au moins deux\n"
	.string "pour participer à cette épreuve.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hum! Hum!\p"
	.string "Te voilà enfin! Oui, te voilà!\p"
	.string "Non, ne dis rien! Je sais\n"
	.string "pourquoi tu as fait tout ce\p"
	.string "chemin!\p"
	.string "Tu voulais me voir, moi le\n"
	.string "propriétaire du MONT DRESSEURS…\p"
	.string "Tu veux faire équipe avec moi!\n"
	.string "Youhou!\p"
	.string "Hein? Ah non?\p"
	.string "En tout cas, tu as fait de très\n"
	.string "beaux combats pour arriver ici!\p"
	.string "Bravo!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Tu es un DRESSEUR hors du commun\n"
	.string "et j’ai un cadeau un peu spécial\p"
	.string "pour toi!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh? Ton SAC est carrément plein.\n"
	.string "J’attendrai que tu reviennes!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh… Avec quelle rapidité tu as\n"
	.string "grimpé jusqu’ici!\p"
	.string "C’est formidable! Tu avais\n"
	.string "vraiment hâte de me voir!\p"
	.string "Ça me fait très plaisir. Ton\n"
	.string "temps va être reporté sur le\p"
	.string "Panneau des Temps!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Mais, quel dommage… Tu n’as pas\n"
	.string "été assez rapide.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Je pense que ça me ferait encore\n"
	.string "plus plaisir si tu étais encore\p"
	.string "plus rapide.\p"
	.string "Ensuite, je serais ravi de\n"
	.string "devenir ton partenaire!\p"
	.string "Nous nous reverrons!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "J'ai fait construire la COLLINE\n"
	.string "DRESSEUR pour une seule et\p"
	.string "unique raison!\p"
	.string "Trouver le partenaire idéal avec\n"
	.string "qui former une équipe!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min\n"
	.string "{STR_VAR_2},{STR_VAR_3} s$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Qui sait quels DRESSEURS et\n"
	.string "quels POKéMON se trouvent sur\p"
	.string "mon chemin…\p"
	.string "Tout ce que je sais, c’est que\n"
	.string "rien ne m’arrêtera!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Les DRESSEURS viennent de\n"
	.string "partout pour grimper sur le MONT\p"
	.string "DRESSEURS.\p"
	.string "J’ai hâte de commencer!\p"
	.string "J’écraserai tout ceux qui se\n"
	.string "trouveront sur mon passage!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Tu vois ce Panneau des Temps?\p"
	.string "Mes amis et moi voulons voir qui\n"
	.string "arrivera en haut le plus vite.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Tu sais quand est-ce que ça va\n"
	.string "ouvrir?\p"
	.string "J’attends ici car je veux être\n"
	.string "le premier DRESSEUR à entrer!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Voulez-vous retourner à la\n"
	.string "réception?$"
