BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "Bienvenue à l’USINE DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve le\n"
	.string "savoir des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI COMBAT ECHANGE SOLO.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Voulez-vous relever le défi du\n"
	.string "COMBAT ECHANGE SOLO?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "Le TOURNOI COMBAT ECHANGE SOLO\n"
	.string "se compose de COMBATS SOLO. Vous\p"
	.string "utilisez des POKéMON de\n"
	.string "location.\p"
	.string "Vous devez choisir trois POKéMON\n"
	.string "parmi les POKéMON de location.\p"
	.string "Ensuite, vous faites des COMBATS\n"
	.string "SOLO avec ces POKéMON.\p"
	.string "Si vous gagnez, vous pouvez\n"
	.string "échanger l’un des POKéMON de\p"
	.string "location.\p"
	.string "Si vous gagnez sept combats à la\n"
	.string "suite, vous gagnez des POINTS DE\p"
	.string "COMBAT.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie.\p"
	.string "Si vous ne sauvegardez pas,\n"
	.string "c’est la disqualification.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Nous espérons vous compter parmi\n"
	.string "nos participants une prochaine\p"
	.string "fois.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Que choisissez-vous: niveau 50\n"
	.string "ou niveau libre?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Avant de commencer, votre partie\n"
	.string "doit être sauvegardée. OK?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "Très bien. Nous garderons vos\n"
	.string "POKéMON en sécurité pendant\p"
	.string "l'épreuve.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Suivez-moi, je vous prie.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Merci d’avoir joué!\p"
	.string "Je vous rends vos POKéMON et\n"
	.string "reprends les POKéMON de\p"
	.string "location.\p"
	.string "Je dois sauvegarder vos données.\n"
	.string "Veuillez patienter.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Je vais vous rendre vos POKéMON\n"
	.string "en échange de nos POKéMON de\p"
	.string "location.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Félicitations! Vous avez gagné\n"
	.string "sept COMBATS ECHANGE à la suite!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "Pour votre série de 7 victoires,\n"
	.string "nous vous remettons ces Point(s)\p"
	.string "de Combat.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Oh, oh, oh!\p"
	.string "Vous avez le maximum de Points\n"
	.string "de Combat.\p"
	.string "Dépensez-en puis revenez nous\n"
	.string "voir.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "Nous vous attendions!\p"
	.string "Avant de reprendre votre défi,\n"
	.string "vous devez sauvegarder la\p"
	.string "partie.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Je regrette!\p"
	.string "Vous n’avez pas sauvegardé avant\n"
	.string "de quitter votre dernier défi.\p"
	.string "Dans ce cas, c’est la\n"
	.string "disqualification. C’est dommage!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Nous allons vous rendre vos POKéMON.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} reçoit le prix\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "Bienvenue à l’USINE DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve le\n"
	.string "savoir des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI COMBAT ECHANGE DUO.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Voulez-vous relever le défi du\n"
	.string "COMBAT ECHANGE DUO?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "Le TOURNOI COMBAT ECHANGE DUO se\n"
	.string "compose de COMBATS DUO. Vous\p"
	.string "utilisez des POKéMON de\n"
	.string "location.\p"
	.string "Vous devez choisir trois POKéMON\n"
	.string "parmi les POKéMON de location.\p"
	.string "Ensuite, vous faites des COMBATS\n"
	.string "DUO avec ces POKéMON.\p"
	.string "Si vous gagnez, vous pouvez\n"
	.string "échanger l’un des POKéMON de\p"
	.string "location.\p"
	.string "Si vous gagnez sept combats à la\n"
	.string "suite, vous gagnez des POINTS DE\p"
	.string "COMBAT.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie.\p"
	.string "Assurez-vous de bien\n"
	.string "sauvegarder, ou vous ne pourrez\p"
	.string "pas reprendre le défi.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Félicitations! Vous avez battu\n"
	.string "le CHEF D’USINE et gagné sept\p"
	.string "matchs à la suite!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "Votre savoir et votre\n"
	.string "intelligence vont être\p"
	.string "récompensés par des POINTS DE\n"
	.string "COMBAT!$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Je vous rends vos POKéMON et\n"
	.string "reprends les POKéMON de\p"
	.string "location.\p"
	.string "Je dois sauvegarder vos données.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Voulez-vous enregistrer votre\n"
	.string "dernier combat à l’USINE DE\p"
	.string "COMBAT sur votre PASSE ZONE?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Hé, dis-moi!\p"
	.string "Tu crois que c’est facile de se\n"
	.string "battre ici parce qu’on te prête\p"
	.string "des POKéMON?\p"
	.string "Eh bien, si tu penses ça, tu te\n"
	.string "mets le doigt dans l’œil!\p"
	.string "Crois-moi!\p"
	.string "Tu dois connaître énormément de\n"
	.string "choses sur les POKéMON et sur\p"
	.string "leurs capacités pour gagner ici!$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "A l’échange, j’ai pris un autre\n"
	.string "POKéMON… Ce n’était pas une très\p"
	.string "bonne idée…\p"
	.string "Ils nous ont écrasés…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Ça ne s’est pas du tout passé\n"
	.string "comme je l’avais prévu.\p"
	.string "Il faut bien étudier les POKéMON\n"
	.string "de l’adversaire pour savoir\p"
	.string "lequel choisir pendant l’échange\n"
	.string "à la fin du combat.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Tu sais, on te donne des infos\n"
	.string "sur l’adversaire avant les\p"
	.string "combats.\p"
	.string "Je m’y connais bien, mais je\n"
	.string "trouve que les infos ne sont pas\p"
	.string "très claires.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Je suis vraiment forte, mais je\n"
	.string "me lasse vite. Alors\p"
	.string "j'échangeais sans cesse mes\n"
	.string "POKéMON avant de combattre.\p"
	.string "À force de participer aux\n"
	.string "Échanges de Combat, j'ai\p"
	.string "remarqué que les POKéMON de\n"
	.string "location changeaient.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Règles du COMBAT ECHANGE.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "Lors d’un COMBAT ECHANGE, vous\n"
	.string "ne pouvez utiliser que trois\p"
	.string "POKéMON.\p"
	.string "Qu’ils aient été prêtés ou\n"
	.string "échangés, votre équipe ne peut\p"
	.string "pas avoir deux fois le même\n"
	.string "POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Vous pouvez échanger un POKéMON\n"
	.string "avec le DRESSEUR que vous venez\p"
	.string "de battre.\p"
	.string "Vous ne pouvez obtenir que les\n"
	.string "POKéMON se trouvant dans son\p"
	.string "équipe.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "A chaque fois que vous gagnez,\n"
	.string "vous pouvez échanger un de vos\p"
	.string "POKéMON avec un de ceux de votre\n"
	.string "adversaire.\p"
	.string "Vous ne pouvez pas faire\n"
	.string "d’échange avec le septième\p"
	.string "DRESSEUR.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Voici deux choses à savoir sur\n"
	.string "les échanges de POKéMON.\p"
	.string "Avant l’échange, vous ne pouvez\n"
	.string "pas connaître les stats du\p"
	.string "POKéMON que vous voulez\n"
	.string "recevoir.\p"
	.string "Les POKéMON de votre équipe sont\n"
	.string "alignés dans l’ordre où vous les\p"
	.string "avez loués.\p"
	.string "Cet ordre reste le même lorsque\n"
	.string "vous échangez des POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "En niveau libre, les POKéMON de\n"
	.string "location et les POKéMON des\p"
	.string "adversaires sont tous de niveau\n"
	.string "100.$"
