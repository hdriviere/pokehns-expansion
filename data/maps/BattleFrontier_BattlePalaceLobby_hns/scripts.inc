BattleFrontier_BattlePalaceLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge_hns, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded_hns
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded_hns
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge_hns::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting_hns, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant_hns::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge_hns
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle_hns
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns2_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe_hns, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR_HNS, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge_hns::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge_hns
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle_hns, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge_hns
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge_hns::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge_hns
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor_hns::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant_hns
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor_hns
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor_hns
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor_hns
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant_hns::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor_hns::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor_hns::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor_hns::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor_hns::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor_hns:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway_hns, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics_hns
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature_hns
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves_hns
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered_hns
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger_hns
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger_hns::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle_hns:
	.string "Bienvenue au PALACE DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve\n"
	.string "l’esprit des DRESSEURS!\p"
	.string "Je serai votre guide dans les\n"
	.string "HALLS DE COMBAT SOLO.$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge_hns:
	.string "Voulez-vous relever le défi d’un\n"
	.string "HALL DE COMBAT SOLO?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge_hns:
	.string "Au PALACE DE COMBAT, il y a\n"
	.string "plusieurs salles réservées aux\p"
	.string "COMBATS SOLO, que l’on appelle\n"
	.string "les HALLS DE COMBAT SOLO.\p"
	.string "Les COMBATS SOLO qui y ont lieu\n"
	.string "sont un peu particuliers. Une\p"
	.string "importante règle y est ajoutée.\p"
	.string "Les DRESSEURS peuvent seulement\n"
	.string "faire entrer et sortir leurs\p"
	.string "POKéMON.\p"
	.string "Les DRESSEURS ne peuvent pas\n"
	.string "donner d’autres ordres à leurs\p"
	.string "POKéMON.\p"
	.string "Les POKéMON agiront conformément\n"
	.string "à leur nature et se battront\p"
	.string "seuls.\p"
	.string "Vous devez placer votre\n"
	.string "confiance en vos POKéMON et les\p"
	.string "regarder.\p"
	.string "Si vous réalisez l’exploit de\n"
	.string "battre sept DRESSEURS à la\p"
	.string "suite, vous recevrez des POINTS\n"
	.string "DE COMBAT.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie.\p"
	.string "Assurez-vous de bien\n"
	.string "sauvegarder, ou vous ne pourrez\p"
	.string "pas reprendre le défi.$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified_hns:
	.string "Revenez quand vous aurez\n"
	.string "fortifié votre esprit et vos\p"
	.string "POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge_hns:
	.string "Il y a deux HALLS DE COMBAT:\n"
	.string "niveau 50 et niveau libre. Que\p"
	.string "choisissez-vous?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "Je regrette…\p"
	.string "Vous n’avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON\n"
	.string "différents pour participer.\p"
	.string "Ces POKéMON doivent être de\n"
	.string "niveau 50 ou moins.\p"
	.string "Ils doivent aussi tenir des\n"
	.string "objets différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au\n"
	.string "combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu’il faut.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Revenez lorsque vous serez prêt.$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "Je regrette…\p"
	.string "Vous n’avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON\n"
	.string "différents pour participer.\p"
	.string "Ils doivent aussi tenir des\n"
	.string "objets différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au\n"
	.string "combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu’il faut.$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons_hns:
	.string "Très bien. Maintenant, veuillez\n"
	.string "choisir vos trois POKéMON.$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns2_hns:
	.string "Avant d’accéder à un HALL DE\n"
	.string "COMBAT, votre partie doit être\p"
	.string "sauvegardée. OK?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe_hns:
	.string "Très bien. Suivez-moi, je vous\n"
	.string "prie.$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded_hns:
	.string "Ce fut un privilège de pouvoir\n"
	.string "assister à un tel combat.\p"
	.string "Votre résultat va être\n"
	.string "sauvegardé. Je vous demande de\p"
	.string "patienter un peu.$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak_hns:
	.string "Sept victoires consécutives…\p"
	.string "Les liens qui unissent votre\n"
	.string "esprit à vos POKéMON sont\p"
	.string "solides et sincères.$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded_hns:
	.string "Votre résultat va être\n"
	.string "sauvegardé. Je vous demande de\p"
	.string "patienter un peu.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak_hns:
	.string "Pour vos sept victoires\n"
	.string "d'affilée, nous vous remettons\p"
	.string "des POINTS DE COMBAT.$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize_hns:
	.string "Malheureusement, vous ne pouvez\n"
	.string "rien porter d’autre.\p"
	.string "Je vous demande de faire de la\n"
	.string "place dans votre SAC et de\p"
	.string "revenir me voir.$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting_hns:
	.string "Nous vous attendions…$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge_hns:
	.string "Avant d’accéder à un HALL DE\n"
	.string "COMBAT, votre partie doit être\p"
	.string "sauvegardée. OK?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge_hns:
	.string "Je regrette!\p"
	.string "Vous n’avez pas sauvegardé avant\n"
	.string "de quitter votre dernier défi.\p"
	.string "C’est malheureux, mais nous\n"
	.string "avons dû vous disqualifier.$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} reçoit {STR_VAR_1} en\n"
	.string "récompense.$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink_hns:
	.string "Pour un DRESSEUR hardi comme\n"
	.string "moi, il faut des POKéMON hardis\p"
	.string "aussi!\p"
	.string "L’attaque est la meilleure des\n"
	.string "défenses! Il faut attaquer sans\p"
	.string "cesse!\p"
	.string "Mais ce n’est pas de ça que je\n"
	.string "voulais parler.\p"
	.string "De temps en temps, il y a une\n"
	.string "fille super mignonne qui passe\p"
	.string "par ici.\p"
	.string "Elle dit qu’elle est capable de\n"
	.string "savoir ce que les POKéMON\p"
	.string "pensent.\p"
	.string "Je ne sais pas si c’est vrai,\n"
	.string "mais en tout cas elle est super\p"
	.string "mignonne!\p"
	.string "Hé! Pourquoi tu me regardes\n"
	.string "comme ça?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere_hns:
	.string "Hum…\p"
	.string "Apparemment, ici c’est la nature\n"
	.string "des POKéMON ainsi que les\p"
	.string "capacités qu’ils connaissent qui\n"
	.string "sont importantes.\p"
	.string "En fait, il faut que les\n"
	.string "capacités qu’ils connaissent\p"
	.string "soient en accord avec leur\n"
	.string "nature.\p"
	.string "Si un POKéMON est en difficulté\n"
	.string "et n’est pas à la hauteur de son\p"
	.string "potentiel, il faut se demander\n"
	.string "si ses capacités correspondent\p"
	.string "bien à sa nature.$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms_hns:
	.string "Mon POKéMON est très docile, en\n"
	.string "temps normal.\p"
	.string "Mais dès qu’il est dans un HALL\n"
	.string "DE COMBAT, il n’est plus le\p"
	.string "même. Il devient méchant!\p"
	.string "Je t’assure, il me fait peur!$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway_hns:
	.string "Je me demande quelle est la\n"
	.string "nature d’un POKéMON qui\p"
	.string "affaiblit l’ennemi petit à petit\n"
	.string "pour prendre la tête.\p"
	.string "Ce serait surprenant qu’il soit\n"
	.string "LACHE de nature.\p"
	.string "Non, ça ne peut pas être ça.$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle_hns:
	.string "Bienvenue au PALACE DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve\n"
	.string "l’esprit des DRESSEURS!\p"
	.string "Je prends les inscriptions pour\n"
	.string "les HALLS DE COMBAT DUO.$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge_hns:
	.string "Voulez-vous relever le défi d’un\n"
	.string "HALL DE COMBAT DUO?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge_hns:
	.string "Au PALACE DE COMBAT, il y a\n"
	.string "plusieurs salles réservées aux\p"
	.string "COMBATS DUO, que l’on appelle\n"
	.string "les HALLS DE COMBAT DUO.\p"
	.string "Les COMBATS DUO qui y ont lieu\n"
	.string "sont un peu particuliers. Une\p"
	.string "importante règle y est ajoutée.\p"
	.string "Les DRESSEURS peuvent seulement\n"
	.string "faire entrer et sortir leurs\p"
	.string "POKéMON.\p"
	.string "Les DRESSEURS ne peuvent pas\n"
	.string "donner d’autres ordres à leurs\p"
	.string "POKéMON.\p"
	.string "Les POKéMON agiront conformément\n"
	.string "à leur nature et se battront\p"
	.string "seuls.\p"
	.string "Vous devez placer votre\n"
	.string "confiance en vos POKéMON et les\p"
	.string "regarder.\p"
	.string "Si vous réalisez l’exploit de\n"
	.string "battre sept DRESSEURS à la\p"
	.string "suite, vous recevrez des POINTS\n"
	.string "DE COMBAT.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie.\p"
	.string "Assurez-vous de bien\n"
	.string "sauvegarder, ou vous ne pourrez\p"
	.string "pas reprendre le défi.$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers_hns:
	.string "Battre le CAPT. PALACE et sept\n"
	.string "DRESSEURS de suite…$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints_hns:
	.string "Les liens qui vous unissent à\n"
	.string "vos POKéMON vont se voir\p"
	.string "récompensés par des POINTS DE\n"
	.string "COMBAT.$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch_hns:
	.string "Voulez-vous enregistrer votre\n"
	.string "dernier combat au PALACE DE\p"
	.string "COMBAT sur votre PASSE ZONE?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed_hns:
	.string "Règles des HALLS DE COMBAT.$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading_hns:
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics_hns:
	.string "Ici, les POKéMON doivent penser\n"
	.string "et se battre par eux-mêmes.\p"
	.string "A la différence des POKéMON\n"
	.string "sauvages, ceux qui vivent avec\p"
	.string "des humains ont un comportement\n"
	.string "spécifique à leur nature.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature_hns:
	.string "La nature d’un POKéMON lui\n"
	.string "dictera peut-être d’attaquer\p"
	.string "coûte que coûte.\p"
	.string "Un autre POKéMON pourra préférer\n"
	.string "se protéger du danger.\p"
	.string "Un autre aimera peut-être\n"
	.string "contrarier et déconcerter ses\p"
	.string "ennemis.\p"
	.string "Selon sa nature, un POKéMON\n"
	.string "préférera certaines capacités,\p"
	.string "qu’il saura mieux utiliser que\n"
	.string "les autres.\p"
	.string "Certaines capacités ne lui\n"
	.string "plairont pas et il aura du mal à\p"
	.string "les utiliser.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves_hns:
	.string "Les capacités offensives font\n"
	.string "subir des dommages immédiats à\p"
	.string "l’ennemi.\p"
	.string "Les capacités défensives servent\n"
	.string "à se préparer à l’attaque\p"
	.string "ennemie, à se soigner ou autre.\p"
	.string "Il y a aussi d’autres capacités\n"
	.string "visant à affaiblir l’ennemi en\p"
	.string "provoquant des problèmes de\n"
	.string "statut comme l’empoisonnement ou\p"
	.string "la paralysie.\p"
	.string "Les POKéMON choisiront leurs\n"
	.string "capacités parmi ces trois\p"
	.string "catégories.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered_hns:
	.string "Sans les ordres de son DRESSEUR,\n"
	.string "il se peut qu’un POKéMON\p"
	.string "n’utilise pas efficacement\n"
	.string "certaines capacités.\p"
	.string "Un POKéMON utilise mal les\n"
	.string "capacités qu’il n’aime pas.\p"
	.string "Si un POKéMON ne connaît que des\n"
	.string "capacités contraires à sa\p"
	.string "nature, il ne sera pas à la\n"
	.string "hauteur de son potentiel.$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger_hns:
	.string "Il se peut qu’un POKéMON se\n"
	.string "mette à utiliser des capacités\p"
	.string "contraires à sa nature s’il est\n"
	.string "en danger.\p"
	.string "Si un POKéMON commence à agir\n"
	.string "bizarrement, surveillez-le bien.$"

