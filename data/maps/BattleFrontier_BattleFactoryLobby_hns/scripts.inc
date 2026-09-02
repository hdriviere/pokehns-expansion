BattleFrontier_BattleFactoryLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead_hns
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins_hns, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead_hns, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave_hns
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMons_hnsSaveResults_hns
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle_hns::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge_hns::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume_hns
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant_hns::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant_hns::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle_hns
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay_hns, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant_hns
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM_HNS, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_FACTORY_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge_hns
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge_hns::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge_hns
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge_hns::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge_hns
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves_hns, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon_hns, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker_hns::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints_hns, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics_hns
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner_hns
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber_hns
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes_hns
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv_hns
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv_hns::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle_hns:
	.string "Bienvenue à l’USINE DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve le\n"
	.string "savoir des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI COMBAT ECHANGE SOLO.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge_hns:
	.string "Voulez-vous relever le défi du\n"
	.string "COMBAT ECHANGE SOLO?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge_hns:
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

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit_hns:
	.string "Nous espérons vous compter parmi\n"
	.string "nos participants une prochaine\p"
	.string "fois.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode_hns:
	.string "Que choisissez-vous: niveau 50\n"
	.string "ou niveau libre?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "Avant de commencer, votre partie\n"
	.string "doit être sauvegardée. OK?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping_hns:
	.string "D'accord. Je garderai vos\n"
	.string "Pokémon en sécurité pendant\p"
	.string "l'épreuve.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay_hns:
	.string "Par ici.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMons_hnsSaveResults_hns:
	.string "Merci d’avoir joué!\p"
	.string "Je vous rends vos POKéMON et\n"
	.string "reprends les POKéMON de\p"
	.string "location.\p"
	.string "Je dois sauvegarder vos données.\n"
	.string "Veuillez patienter.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons_hns:
	.string "Je vous rends vos Pokémon en\n"
	.string "échange de nos Pokémon de\p"
	.string "location.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins_hns:
	.string "Félicitations! Vous avez gagné\n"
	.string "sept COMBATS ECHANGE à la suite!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints_hnsForStreak_hns:
	.string "Pour vos sept victoires\n"
	.string "d'affilée, nous vous remettons\p"
	.string "des POINTS DE COMBAT.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints_hns:
	.string "Oh, oh, oh!\p"
	.string "Vous avez atteint la limite de\n"
	.string "POINTS DE COMBAT.\p"
	.string "Revenez après en avoir utilisés.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume_hns:
	.string "Nous vous attendions!\p"
	.string "Avant de reprendre votre défi,\n"
	.string "vous devez sauvegarder la\p"
	.string "partie.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting_hns:
	.string "Je regrette!\p"
	.string "Vous n’avez pas sauvegardé avant\n"
	.string "de quitter votre dernier défi.\p"
	.string "Dans ce cas, c’est la\n"
	.string "disqualification. C’est dommage!$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons_hns:
	.string "Nous allons vous rendre vos\n"
	.string "POKéMON personnels.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem_hns:
	.string "{PLAYER} reçoit {STR_VAR_1} en\n"
	.string "récompense.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle_hns:
	.string "Bienvenue à l’USINE DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve le\n"
	.string "savoir des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI COMBAT ECHANGE DUO.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge_hns:
	.string "Voulez-vous relever le défi du\n"
	.string "COMBAT ECHANGE DUO?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge_hns:
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

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead_hns:
	.string "Félicitations! Vous avez battu\n"
	.string "le CHEF D’USINE et gagné sept\p"
	.string "matchs à la suite!$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints_hns:
	.string "Votre savoir et votre\n"
	.string "intelligence vont être\p"
	.string "récompensés par des POINTS DE\n"
	.string "COMBAT!$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave_hns:
	.string "Je vous rends vos POKéMON et\n"
	.string "reprends les POKéMON de\p"
	.string "location.\p"
	.string "Je dois sauvegarder vos données.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch_hns:
	.string "Voulez-vous enregistrer votre\n"
	.string "dernier combat à l’USINE DE\p"
	.string "COMBAT sur votre PASSE ZONE?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves_hns:
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

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon_hns:
	.string "A l’échange, j’ai pris un autre\n"
	.string "POKéMON… Ce n’était pas une très\p"
	.string "bonne idée…\p"
	.string "Ils nous ont écrasés…$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons_hns:
	.string "Ça ne s’est pas du tout passé\n"
	.string "comme je l’avais prévu.\p"
	.string "Il faut bien étudier les POKéMON\n"
	.string "de l’adversaire pour savoir\p"
	.string "lequel choisir pendant l’échange\n"
	.string "à la fin du combat.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints_hns:
	.string "Tu sais, on te donne des infos\n"
	.string "sur l’adversaire avant les\p"
	.string "combats.\p"
	.string "Je m’y connais bien, mais je\n"
	.string "trouve que les infos ne sont pas\p"
	.string "très claires.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried_hns:
	.string "Je suis vraiment fort, mais je\n"
	.string "m'ennuie vite. Alors je\p"
	.string "n'arrêtais pas d'échanger mes\n"
	.string "Pokémon et de combattre.\p"
	.string "En participant souvent aux\n"
	.string "échanges de combat, j'ai\p"
	.string "remarqué que les Pokémon de\n"
	.string "location variaient.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed_hns:
	.string "Règles du COMBAT ECHANGE.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading_hns:
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules_hns:
	.string "Lors d’un COMBAT ECHANGE, vous\n"
	.string "ne pouvez utiliser que trois\p"
	.string "POKéMON.\p"
	.string "Qu’ils aient été prêtés ou\n"
	.string "échangés, votre équipe ne peut\p"
	.string "pas avoir deux fois le même\n"
	.string "POKéMON.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules_hns:
	.string "Vous pouvez échanger un POKéMON\n"
	.string "avec le DRESSEUR que vous venez\p"
	.string "de battre.\p"
	.string "Vous ne pouvez obtenir que les\n"
	.string "POKéMON se trouvant dans son\p"
	.string "équipe.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules_hns:
	.string "A chaque fois que vous gagnez,\n"
	.string "vous pouvez échanger un de vos\p"
	.string "POKéMON avec un de ceux de votre\n"
	.string "adversaire.\p"
	.string "Vous ne pouvez pas faire\n"
	.string "d’échange avec le septième\p"
	.string "DRESSEUR.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules_hns:
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

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules_hns:
	.string "En niveau libre, les POKéMON de\n"
	.string "location et les POKéMON des\p"
	.string "adversaires sont tous de niveau\n"
	.string "100.$"
