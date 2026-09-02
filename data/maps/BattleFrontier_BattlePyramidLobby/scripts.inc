BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Bienvenue à la PYRAMIDE DE\n"
	.string "COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve le\n"
	.string "courage des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "COMBAT QUETE.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "Avez-vous le courage de relever\n"
	.string "le défi du COMBAT QUETE?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Nous attendrons votre prochain\n"
	.string "défi avec impatience.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "Lors du COMBAT QUETE, vous devez\n"
	.string "explorer la PYRAMIDE et essayer\p"
	.string "d’en atteindre le sommet.\p"
	.string "Chacun des sept niveaux de la\n"
	.string "PYRAMIDE est un labyrinthe. Ils\p"
	.string "sont truffés de DRESSEURS et de\n"
	.string "POKéMON sauvages.\p"
	.string "Vous devez y entrer avec trois\n"
	.string "POKéMON ne portant aucun objet.\p"
	.string "On vous fournira un SAC DE\n"
	.string "COMBAT pour y mettre les objets.\p"
	.string "Si vous échouez, vous perdez les\n"
	.string "objets placés dans le SAC DE\p"
	.string "COMBAT.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, sélectionnez “REPOS” et\p"
	.string "sauvegardez la partie.\p"
	.string "Assurez-vous de bien\n"
	.string "sauvegarder, ou vous ne pourrez\p"
	.string "pas reprendre le défi.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "La PYRAMIDE offre deux\n"
	.string "possibilités: niveau 50 et\p"
	.string "niveau libre. Que\n"
	.string "choisissez-vous?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Très bien. Choisissez les trois\n"
	.string "POKéMON qui vont vous\p"
	.string "accompagner.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Il y a un petit problème!\p"
	.string "Vous n’avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Souvenez-vous que vous devez\n"
	.string "leur reprendre les objets qu’ils\p"
	.string "portent.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au\n"
	.string "combat.\p"
	.string "On en reparlera quand vous aurez\n"
	.string "ce qu’il faut.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "Il y a un petit problème!\p"
	.string "Vous n’avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON\n"
	.string "différents de niveau 50 ou moins\p"
	.string "pour participer.\p"
	.string "Souvenez-vous que vous devez\n"
	.string "leur reprendre les objets qu’ils\p"
	.string "portent.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au\n"
	.string "combat.\p"
	.string "On en reparlera quand vous aurez\n"
	.string "ce qu’il faut.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd:
	.string "On en reparlera quand vous aurez\n"
	.string "ce qu'il faut.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Pour accéder à la PYRAMIDE DE\n"
	.string "COMBAT, votre partie doit être\p"
	.string "sauvegardée. OK?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Très bien. Je vais vous\n"
	.string "accompagner dans la PYRAMIDE DE\p"
	.string "COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Nous gardons votre SAC pendant\n"
	.string "votre exploration, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "Tenez, prenez votre ancien SAC\n"
	.string "DE COMBAT en échange.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "Tenez, prenez ce SAC DE COMBAT\n"
	.string "en échange.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} a échangé le SAC avec\n"
	.string "le SAC DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Ce type de plaque permet d’être\n"
	.string "transporté au niveau supérieur\p"
	.string "de la PYRAMIDE.\p"
	.string "J’espère que tout va bien se\n"
	.string "passer pour vous!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Il y a un gros problème!\p"
	.string "Vous n’avez pas sauvegardé avant\n"
	.string "de quitter votre dernier défi.\p"
	.string "Dans ce cas, c’est la\n"
	.string "disqualification. C’est dommage!\p"
	.string "Je vous rends votre SAC, tenez.\p"
	.string "{PLAYER} a récupéré le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Quel plaisir de vous revoir!\p"
	.string "Vous avez conquis la PYRAMIDE!\n"
	.string "Ce fut splendide!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Il y a un petit problème!\p"
	.string "Au moins un de vos POKéMON porte\n"
	.string "un objet.\p"
	.string "Malheureusement, les objets\n"
	.string "obtenus dans la PYRAMIDE doivent\p"
	.string "rester ici.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Tous les objets vont être placés\n"
	.string "dans votre SAC DE COMBAT,\p"
	.string "{PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Le SAC DE COMBAT ne peut pas\n"
	.string "contenir tous vos objets, je\p"
	.string "suis désolé.\p"
	.string "Choisissez les objets à laisser\n"
	.string "dans le SAC DE COMBAT et avec\p"
	.string "vos POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Au moins un POKéMON porte encore\n"
	.string "un objet.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Choisissez les objets à laisser\n"
	.string "dans le SAC DE COMBAT et avec\p"
	.string "vos POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} rend tous les objets\n"
	.string "tenus par les POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "Votre SAC DE COMBAT va être\n"
	.string "conservé pour votre prochain\p"
	.string "défi.\p"
	.string "{PLAYER} a rendu le SAC DE\n"
	.string "COMBAT et a repris le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Votre résultat va être\n"
	.string "sauvegardé. Veuillez patienter.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "En souvenir de votre conquête de\n"
	.string "la PYRAMIDE DE COMBAT, acceptez\p"
	.string "ceci.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} reçoit le prix\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah… Votre SAC semble plein.\p"
	.string "Rangez son contenu avant de\n"
	.string "revenir.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Que c’est décevant…\p"
	.string "Voici votre SAC.\p"
	.string "{PLAYER} a récupéré le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Nous attendrons votre prochain\n"
	.string "défi avec impatience.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Nous attendions votre arrivée\n"
	.string "avec impatience!\p"
	.string "Voici votre prix pour avoir\n"
	.string "conquis la PYRAMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Bienvenue à toi…\p"
	.string "Je serais ravie de te dire les\n"
	.string "malheurs qui t’attendent dans la\p"
	.string "PYRAMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … … … … … … … …\p"
	.string "… … … … … … Ah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Je vois une pluie d’étincelles…\p"
	.string "Dans cette pluie, je vois tes\n"
	.string "POKéMON lutter contre la\p"
	.string "paralysie…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Je vois du poison…\p"
	.string "Oui, tes POKéMON souffrent d’un\n"
	.string "empoisonnement…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Je vois des flammes rouges…\p"
	.string "Tes POKéMON souffrent de\n"
	.string "brûlures…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Je ressens la pression d’une\n"
	.string "fureur incontrôlable…\p"
	.string "C’est une malédiction…\p"
	.string "Et je vois les POINTS DE POUVOIR\n"
	.string "de tes POKéMON se faire drainer.\p"
	.string "Ils sont obligés d’utiliser\n"
	.string "LUTTE…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Je vois des POKéMON voler à\n"
	.string "haute altitude…\p"
	.string "Tes POKéMON sont frustrés face à\n"
	.string "l’échec de leurs capacités de\p"
	.string "type SOL…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Je sens une énergie incroyable\n"
	.string "provenant du sol…\p"
	.string "Je vois tes POKéMON incapables\n"
	.string "d’échapper à son emprise…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Je vois des POKéMON de type\n"
	.string "GLACE…\p"
	.string "Tes POKéMON luttent contre le\n"
	.string "froid mordant de la glace…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Je vois une myriade de capacités\n"
	.string "dangereuses pour celui qui les\p"
	.string "utilise…\p"
	.string "Tes POKéMON en souffrent…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Je vois des POKéMON de type PSY…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités de type PSY…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Je vois des POKéMON de type\n"
	.string "ROCHE…\p"
	.string "Et je vois tes POKéMON souffrir\n"
	.string "à cause de capacités de type\p"
	.string "ROCHE…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Je vois des POKéMON de type\n"
	.string "COMBAT…\p"
	.string "Tes POKéMON sont assaillis\n"
	.string "d’attaques de type COMBAT…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "DANSE PLUIE… ZENITH…\n"
	.string "TEMPETESABLE… GRELE…\p"
	.string "Je vois des POKéMON qui se\n"
	.string "renforcent avec les conditions\p"
	.string "climatiques…\p"
	.string "Tes POKéMON sont perdus, les\n"
	.string "capacités sont de tous types…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Je vois des POKéMON de type\n"
	.string "INSECTE…\p"
	.string "Tes POKéMON subissent des\n"
	.string "attaques de différentes sortes…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Je vois des POKéMON de type\n"
	.string "TENEBRES…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités de type TENEBRES…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Je vois des POKéMON de type EAU…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités de type EAU…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Je vois des POKéMON de type\n"
	.string "SPECTRE…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités de type SPECTRE…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Je vois des POKéMON de type\n"
	.string "ACIER…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités très puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Je vois des POKéMON volants…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités très puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Je vois ceux qui dérivent du\n"
	.string "pouvoir de la pierre…\p"
	.string "Je sens le feu, l’eau et\n"
	.string "l’électricité…\p"
	.string "Tes POKéMON doivent affronter\n"
	.string "ces trois pouvoirs…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Je vois des POKéMON de type\n"
	.string "NORMAL…\p"
	.string "Tes POKéMON sont aux prises avec\n"
	.string "des capacités très puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Que tu me croies ou non n’a\n"
	.string "aucune importance…\p"
	.string "Tu as le pouvoir de modifier ton\n"
	.string "avenir… Je te souhaite de\p"
	.string "réussir…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "J’ai un secret pour toi.\p"
	.string "Si tu cours, tu risques\n"
	.string "d’attirer l’attention des\p"
	.string "DRESSEURS et ils voudront se\n"
	.string "battre contre toi.\p"
	.string "Pour les éviter, il faut se\n"
	.string "faire discret et passer\p"
	.string "lentement à côté d’eux.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Ahhhhh!\p"
	.string "J’avais plein d’objets, mais ils\n"
	.string "se sont envolés quand j’ai\p"
	.string "perdu!\p"
	.string "Ouin!!!!!!!!!!!!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Vous voilà de retour! Vous avez\n"
	.string "réussi l’impossible!\p"
	.string "Vous avez battu le ROI PYRAMIDE\n"
	.string "et conquis la PYRAMIDE DE\p"
	.string "COMBAT!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Jeune intrépide! Votre courage\n"
	.string "va être récompensé par des\p"
	.string "POINTS DE COMBAT!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Règles du COMBAT QUETE.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Une fois la PYRAMIDE conquise,\n"
	.string "les POKéMON sauvages qui s’y\p"
	.string "trouvent sont remplacés par\n"
	.string "d’autres.\p"
	.string "Il faut en profiter pour les\n"
	.string "observer et apprendre à\p"
	.string "connaître de nouveaux POKéMON\n"
	.string "sauvages.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Des DRESSEURS vous attendent à\n"
	.string "l’intérieur de la PYRAMIDE.\p"
	.string "A chaque niveau, il y a jusqu’à\n"
	.string "huit DRESSEURS.\p"
	.string "Quand vous en battez un, vous\n"
	.string "recevez une information\p"
	.string "importante.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Les labyrinthes de la PYRAMIDE\n"
	.string "changent à chaque fois que vous\p"
	.string "y entrez.\p"
	.string "Les labyrinthes sont très peu\n"
	.string "éclairés. Vous devez avancer\p"
	.string "avec précaution.\p"
	.string "Quand vous battez un POKéMON\n"
	.string "sauvage ou un DRESSEUR, la\p"
	.string "lumière s’intensifie.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "Le SAC DE COMBAT sera votre SAC\n"
	.string "dans la PYRAMIDE.\p"
	.string "Il y a deux SACS DE COMBAT: un\n"
	.string "pour niveau 50 et un pour niveau\p"
	.string "libre.\p"
	.string "Chacun peut contenir 99\n"
	.string "exemplaires de dix types\p"
	.string "d’objets différents.\p"
	.string "Le contenu du SAC DE COMBAT est\n"
	.string "perdu si vous échouez.$"

