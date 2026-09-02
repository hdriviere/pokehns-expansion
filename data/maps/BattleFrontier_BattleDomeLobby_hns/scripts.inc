BattleFrontier_BattleDomeLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume_hns
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleDomeLobby_OnResume_hns:
	dome_initresultstree
	end

BattleFrontier_BattleDomeLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleDomeLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting_hns, MSGBOX_DEFAULT
	closemessage
	dome_set DOME_DATA_WIN_STREAK, 0
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_WonChallenge_hns::
	call BattleFrontier_EventScript_IncrementWinStreak
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce_hns
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker_hns, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle_hns

BattleFrontier_BattleDomeLobby_EventScript_LostChallenge_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns
	waitmessage
	special LoadPlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	frontier_checkairshow
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle_hns::
	dome_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_RecordBattle_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns2_hns
	waitmessage
	dome_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome_hns::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles_hns
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	dome_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
	dome_inittrainers
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	dome_settrainers
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor_hns
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR_HNS, 23, 6
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge_hns
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns, MSGBOX_DEFAULT
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsWalkToDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsWalkToDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor_hns
	waitdooranim
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsEnterDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor_hns
	waitdooranim
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsWalkToDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsWalkToDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant_hnsEnterDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant_hnsEnterDoor_hns::
	applymovement LOCALID_DOME_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge_hns::
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge_hns
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor_hns::
	opendoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor_hns::
	opendoor 17, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor_hns::
	closedoor 5, 4
	return

BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor_hns::
	closedoor 17, 4
	return

BattleFrontier_BattleDomeLobby_Movement_WalkToDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree_hns::
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
	call_if_eq VAR_RESULT, 0, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50_hns
	call_if_eq VAR_RESULT, 1, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50_hns
	call_if_eq VAR_RESULT, 2, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen_hns
	call_if_eq VAR_RESULT, 3, BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen_hns
	fadescreen FADE_TO_BLACK
	dome_showprevtourneytree
	waitstate
	end

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen_hns, MSGBOX_SIGN
	return

BattleFrontier_BattleDomeLobby_EventScript_Man_hnsiac_hns::
	dome_getwinnersname
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Lass_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_FatMan_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully_hns, MSGBOX_NPC
	end

@ A few OutsideWest event scripts are inserted here instead, two of which are unused
BattleFrontier_OutsideWest_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction_hns, MSGBOX_NPC
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup_hns
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree_hns
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO_hns
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO_hns::
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleDomeLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle_hns:
	.string "Bienvenue au DOME DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve la\n"
	.string "tactique des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI DE COMBAT SOLO.$"

BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge_hns:
	.string "Voulez-vous participer à un\n"
	.string "TOURNOI DE COMBAT SOLO?$"

BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain_hns:
	.string "A une prochaine fois peut-être!$"

BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge_hns:
	.string "Le TOURNOI DE COMBAT SOLO est,\n"
	.string "comme son nom l’indique, un\p"
	.string "tournoi constitué de COMBATS\n"
	.string "SOLO.\p"
	.string "Tous les DRESSEURS qui y\n"
	.string "participent doivent avoir trois\p"
	.string "POKéMON.\p"
	.string "Lors des combats, l’un des trois\n"
	.string "POKéMON est gardé en réserve.\p"
	.string "Les deux autres POKéMON peuvent\n"
	.string "se battrent l’un après l’autre.\p"
	.string "Etudiez les trois POKéMON de\n"
	.string "l’adversaire avant de choisir\p"
	.string "les deux POKéMON que vous\n"
	.string "envoyez au combat.\p"
	.string "Vous devez vaincre quatre\n"
	.string "DRESSEURS pour remporter le\p"
	.string "tournoi.\p"
	.string "Des POINTS DE COMBAT sont remis\n"
	.string "au vainqueur du tournoi.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie.\p"
	.string "Assurez-vous de bien\n"
	.string "sauvegarder, ou vous ne pourrez\p"
	.string "pas reprendre le défi.$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns:
	.string "Avant de vous conduire au DÔME\n"
	.string "DE COMBAT, je dois sauvegarder.\p"
	.string "D'accord?$"

BattleFrontier_BattleDomeLobby_Text_WhichLevelMode_hns:
	.string "Le tournoi propose deux niveaux\n"
	.string "de défi: niveau 50 et niveau\p"
	.string "libre. Que choisissez-vous?$"

BattleFrontier_BattleDomeLobby_Text_SelectThreeMons_hns:
	.string "Veuillez choisir les trois\n"
	.string "POKéMON que vous souhaitez\p"
	.string "inscrire.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "Je regrette!\p"
	.string "Vous n’avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Ils doivent aussi tenir des\n"
	.string "objets différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au\n"
	.string "combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu’il faut.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Revenez nous voir quand votre\n"
	.string "équipe sera prête.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "Je regrette!\p"
	.string "Vous n’avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON\n"
	.string "différents de niveau 50 ou moins\p"
	.string "pour participer.\p"
	.string "Ils doivent aussi tenir des\n"
	.string "objets différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au\n"
	.string "combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu’il faut.$"

BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome_hns:
	.string "Veuillez me suivre dans le DOME\n"
	.string "DE COMBAT.$"

BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting_hns:
	.string "Je regrette!\p"
	.string "Vous n’avez pas sauvegardé avant\n"
	.string "de quitter votre dernier défi.\p"
	.string "Dans ce cas, c’est la\n"
	.string "disqualification. C’est dommage!$"

BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney_hns:
	.string "Félicitations pour avoir\n"
	.string "remporté ce TOURNOI DE COMBAT!$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize_hns:
	.string "Voici votre prix pour votre\n"
	.string "victoire au TOURNOI DE COMBAT.$"

@ Used by Verdanturf Tent
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} reçoit {STR_VAR_1} en\n"
	.string "récompense.$"

@ Unused
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom_hns:
	.string "Oh, votre SAC semble plein.\p"
	.string "Libérez de la place dans votre\n"
	.string "SAC, puis revenez me voir.$"

BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying_hns:
	.string "Merci d’avoir participé!$"

BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved_hns:
	.string "Vos données\n"
	.string "vont être\p"
	.string "sauvegardées.\n"
	.string "Veuillez patienter.$"

BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou_hns:
	.string "Nous vous attendions!$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge_hns2_hns:
	.string "Avant de vous conduire au DÔME\n"
	.string "DE COMBAT, je dois sauvegarder.\p"
	.string "D'accord?$"

BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle_hns:
	.string "Bienvenue au DOME DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve la\n"
	.string "tactique des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI DE COMBAT DUO.$"

BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge_hns:
	.string "Voulez-vous participer à un\n"
	.string "TOURNOI DE COMBAT DUO?$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge_hns:
	.string "Le TOURNOI DE COMBAT DUO est,\n"
	.string "comme son nom l’indique, un\p"
	.string "tournoi constitué de COMBATS\n"
	.string "DUO.\p"
	.string "Tous les DRESSEURS qui y\n"
	.string "participent doivent avoir trois\p"
	.string "POKéMON.\p"
	.string "Lors des combats, l’un des trois\n"
	.string "POKéMON est gardé en réserve.\p"
	.string "Les deux autres POKéMON doivent\n"
	.string "faire un COMBAT DUO.\p"
	.string "Etudiez les trois POKéMON de\n"
	.string "l’adversaire avant de choisir\p"
	.string "les deux POKéMON que vous\n"
	.string "envoyez au combat.\p"
	.string "Vous devez vaincre quatre\n"
	.string "DRESSEURS pour remporter le\p"
	.string "tournoi.\p"
	.string "Des POINTS DE COMBAT sont remis\n"
	.string "au vainqueur du tournoi.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie.\p"
	.string "Assurez-vous de bien\n"
	.string "sauvegarder, ou vous ne pourrez\p"
	.string "pas reprendre le défi.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50_hns:
	.string "Résultats du dernier TOURNOI DE\n"
	.string "COMBAT SOLO niveau 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50_hns:
	.string "Résultats du dernier TOURNOI DE\n"
	.string "COMBAT DUO niveau 50.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen_hns:
	.string "Résultats du dernier TOURNOI DE\n"
	.string "COMBAT SOLO niveau libre.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen_hns:
	.string "Résultats du dernier TOURNOI DE\n"
	.string "COMBAT DUO niveau libre.$"

BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough_hns:
	.string "Tu as assisté au dernier TOURNOI\n"
	.string "DE COMBAT?\p"
	.string "{STR_VAR_1}, le vainqueur, était\n"
	.string "vraiment balèze!\p"
	.string "Tu devrais consulter les\n"
	.string "résultats sur le panneau à côté\p"
	.string "du PC.$"

BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier_hns:
	.string "La ZONE DE COMBAT… J’ai rêvé\n"
	.string "d’un tel endroit pendant des\p"
	.string "années.$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_BattleDomeSign2_hns:
	.string "DOME DE COMBAT  Devenez une star\n"
	.string "incontestable!$"

@ Functionally unused
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction_hns:
	.string "?????? Construction en cours!$"

BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation_hns:
	.string "Quand un DRESSEUR remporte\n"
	.string "plusieurs tournois au DOME DE\p"
	.string "COMBAT, il devient une vraie\n"
	.string "star.\p"
	.string "C’est ce qui attire les\n"
	.string "DRESSEURS au DOME DE COMBAT.\p"
	.string "Un DRESSEUR qui enchaîne les\n"
	.string "victoires est vraiment une star.$"

BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound_hns:
	.string "Au premier tour, j’ai affronté\n"
	.string "un habitué du DOME DE COMBAT.\p"
	.string "Je me suis fait ratatiner…$"

BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully_hns:
	.string "J’aurais gagné si j’avais mis ce\n"
	.string "POKéMON en réserve.\p"
	.string "Avant de choisir quels POKéMON\n"
	.string "tu envoies au combat, regarde\p"
	.string "bien ceux de l’adversaire.$"

BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker_hns:
	.string "Félicitations!\p"
	.string "Vous avez battu la STAR DU DOME\n"
	.string "et remporté le TOURNOI DE\p"
	.string "COMBAT!$"

BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints_hns:
	.string "Votre excellente tactique va\n"
	.string "être récompensée en POINTS DE\p"
	.string "COMBAT!$"

BattleFrontier_BattleDomeLobby_Text_RecordLastMatch_hns:
	.string "Voulez-vous enregistrer votre\n"
	.string "dernier combat au DOME DE COMBAT\p"
	.string "sur votre PASSE ZONE?$"

BattleFrontier_BattleDomeLobby_Text_RulesAreListed_hns:
	.string "Règles du TOURNOI DE COMBAT.$"

BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading_hns:
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules_hns:
	.string "Les DRESSEURS s’affrontent\n"
	.string "suivant la force de leurs\p"
	.string "POKéMON.\p"
	.string "Cela évite que les DRESSEURS\n"
	.string "forts ne se rencontrent dès le\p"
	.string "début.$"

BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree_hns:
	.string "Dans la salle d’attente, le\n"
	.string "guide vous donne accès au\p"
	.string "“TABLEAU”.\p"
	.string "Ce tableau des rencontres\n"
	.string "contient différentes\p"
	.string "informations.\p"
	.string "Vous pouvez y consulter les\n"
	.string "résultats, les POKéMON détenus\p"
	.string "par les DRESSEURS et les styles\n"
	.string "de combat des DRESSEURS.$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules_hns:
	.string "Si deux POKéMON adverses\n"
	.string "s’évanouissent au même moment,\p"
	.string "un double K.O., ce sont les\n"
	.string "ARBITRES qui désignent le\p"
	.string "vainqueur.$"
