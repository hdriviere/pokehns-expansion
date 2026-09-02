BattleFrontier_BattleArenaLobby_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame_hns
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp_hns
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp_hns:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth_hns::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame_hns:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus_hns::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge_hns::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge_hns::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch_hns::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge_hns::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge_hns::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_Attendant_hns::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge_hns::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge_hns::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge_hns::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR_HNS, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hns::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLv50_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons_hnsLvOpen_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hnsSaveFailed_hns::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge_hns::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge_hns::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen_hns::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor_hns
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor_hns
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor_hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults_hns::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard_hns::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules_hns::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard_hns
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules_hns::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena_hns:
	.string "Bienvenue au DOJO DE COMBAT!\p"
	.string "Ici, nous mettons à l’épreuve le\n"
	.string "cran des DRESSEURS!\p"
	.string "Je serai votre guide pour le\n"
	.string "TOURNOI K.O.!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge_hns:
	.string "Voulez-vous relever le défi du\n"
	.string "DOJO DE COMBAT?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns:
	.string "Nous attendrons votre prochain\n"
	.string "défi!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge_hns:
	.string "Au DOJO DE COMBAT, vous\n"
	.string "participez à un TOURNOI K.O.\p"
	.string "Les participants s’inscrivent\n"
	.string "avec une équipe de trois\p"
	.string "POKéMON.\p"
	.string "Ces POKéMON doivent être placés\n"
	.string "dans l’ordre dans lequel ils\p"
	.string "apparaîtront.\p"
	.string "Pendant un combat, ils\n"
	.string "apparaîtront l’un après l’autre\p"
	.string "dans l’ordre prédéfini.\p"
	.string "Un POKéMON qui entre au combat\n"
	.string "doit y rester jusqu’à la fin.\p"
	.string "S’il n’y a pas de vainqueur au\n"
	.string "bout de trois tours, l’ARBITRE\p"
	.string "intervient.\p"
	.string "Si vous voulez interrompre le\n"
	.string "défi, veuillez sauvegarder la\p"
	.string "partie.\p"
	.string "Si vous ne sauvegardez pas, vous\n"
	.string "ne pourrez pas reprendre ce\p"
	.string "défi.\p"
	.string "Si vous mettez K.O. sept\n"
	.string "DRESSEURS à la suite, nous vous\p"
	.string "remettons des POINTS DE COMBAT.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave_hns:
	.string "Avant de me suivre dans le DOJO\n"
	.string "DE COMBAT, vous devez\p"
	.string "sauvegarder. OK?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode_hns:
	.string "Au DOJO DE COMBAT, vous avez le\n"
	.string "choix entre niveau 50 et niveau\p"
	.string "libre. Que choisissez-vous?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons_hns:
	.string "Veuillez choisir les trois\n"
	.string "POKéMON que vous souhaitez\p"
	.string "inscrire.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen_hns:
	.string "Je regrette, cher DRESSEUR!\p"
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

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd_hns:
	.string "Revenez quand vous serez prêt.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50_hns:
	.string "Je regrette, cher DRESSEUR!\p"
	.string "Vous n’avez pas trois POKéMON\n"
	.string "aptes à participer.\p"
	.string "Il vous faut trois POKéMON\n"
	.string "différents pour participer.\p"
	.string "Il vous faut trois POKéMON\n"
	.string "différents de niveau 50 ou moins\p"
	.string "pour participer.\p"
	.string "Ils doivent aussi tenir des\n"
	.string "objets différents.\p"
	.string "Les OEUFS{STR_VAR_1} inaptes au\n"
	.string "combat.\p"
	.string "Revenez me voir quand vous aurez\n"
	.string "ce qu’il faut.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena_hns:
	.string "Suivez-moi dans le DOJO DE\n"
	.string "COMBAT.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown_hns:
	.string "Je regrette, cher DRESSEUR!\p"
	.string "Vous n’avez pas sauvegardé avant\n"
	.string "de quitter votre dernier défi.\p"
	.string "Dans ce cas, c’est la\n"
	.string "disqualification. Quel dommage!\p"
	.string "Bien entendu, vous pouvez\n"
	.string "recommencer un autre défi.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins_hns:
	.string "Toutes mes félicitations! Vous\n"
	.string "avez battu sept DRESSEURS à la\p"
	.string "suite!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement_hns:
	.string "Votre performance va être\n"
	.string "sauvegardée. Veuillez patienter.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize_hns:
	.string "Pour commémorer vos sept\n"
	.string "victoires d'affilée, nous vous\p"
	.string "remettons ce prix.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize_hns:
	.string "{PLAYER} reçoit {STR_VAR_1} en\n"
	.string "récompense.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize_hns:
	.string "Oh? Votre SAC semble plein.\p"
	.string "Libérez de la place, puis\n"
	.string "revenez chercher votre prix.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave_hns:
	.string "Merci d’avoir participé!\p"
	.string "Votre résultat va être\n"
	.string "sauvegardé. Veuillez patienter.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge_hns2_hns:
	.string "Nous attendrons votre prochain\n"
	.string "défi!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame_hns:
	.string "Nous vous attendions!\p"
	.string "Vous devez sauvegarder avant de\n"
	.string "me suivre dans le DOJO DE\p"
	.string "COMBAT. Veuillez patienter.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch_hns:
	.string "J’enregistre votre dernier\n"
	.string "combat au DOJO DE COMBAT sur\p"
	.string "votre PASSE ZONE?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack_hns:
	.string "J’ai perdu sur décision de\n"
	.string "l’ARBITRE… J’aurais dû attaquer…\p"
	.string "Mais je n’ai utilisé que des\n"
	.string "capacités défensives…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked_hns:
	.string "J’ai gagné sur décision de\n"
	.string "l’ARBITRE!\p"
	.string "Je n’ai pas arrêté de porter des\n"
	.string "coups et ça lui a plu!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw_hns:
	.string "Le combat a été déclaré nul.\p"
	.string "Il ne restait plus de temps et\n"
	.string "mes POKéMON et ceux de\p"
	.string "l’adversaire avaient le même\n"
	.string "niveau de PV.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant_hns:
	.string "Dans le DOJO DE COMBAT, l’ordre\n"
	.string "des POKéMON est très important.\p"
	.string "Si ton premier POKéMON a\n"
	.string "certains points faibles liés à\p"
	.string "son type, ton deuxième POKéMON\n"
	.string "doit les compenser, par exemple.\p"
	.string "Ça permet de créer une équipe\n"
	.string "efficace.$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed_hns:
	.string "Règles du TOURNOI K.O.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading_hns:
	.string "Quel chapitre voulez-vous lire?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules_hns:
	.string "Le TOURNOI K.O. n’a pas les\n"
	.string "mêmes règles que les combats\p"
	.string "normaux.\p"
	.string "Tout d’abord, un combat ne dure\n"
	.string "que trois tours.\p"
	.string "S’il n’y a pas de vainqueur au\n"
	.string "bout de trois tours, l’ARBITRE\p"
	.string "intervient.\p"
	.string "L’ARBITRE basera son choix sur\n"
	.string "la façon dont les POKéMON ont\p"
	.string "combattu.\p"
	.string "Aussi, un POKéMON qui entre au\n"
	.string "combat doit y rester jusqu’à la\p"
	.string "fin.$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules_hns:
	.string "Le premier critère de jugement\n"
	.string "est le “mental”. C’est\p"
	.string "l’agressivité des concurrents.\p"
	.string "Cela dépend du nombre de\n"
	.string "capacités offensives qui ont été\p"
	.string "utilisées.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules_hns:
	.string "Le second critère de jugement\n"
	.string "est la “technique”. C’est\p"
	.string "l’efficacité avec laquelle les\n"
	.string "POKéMON utilisent leurs\p"
	.string "capacités.\p"
	.string "Si une capacité est réussie, le\n"
	.string "niveau de technique augmente.\p"
	.string "Si une capacité a échoué, le\n"
	.string "niveau de technique diminue.\p"
	.string "Pour une capacité offensive, le\n"
	.string "niveau de technique augmente si\p"
	.string "la capacité est “super efficace”\n"
	.string "et diminue si elle n’est “pas\p"
	.string "très efficace”.\p"
	.string "Les capacités telles qu’ABRI et\n"
	.string "DETECTION ne comptent pas.\p"
	.string "Si l’adversaire a utilisé ABRI\n"
	.string "ou DETECTION et que l’attaque de\p"
	.string "votre POKéMON n’a pas pu\n"
	.string "l’atteindre, son niveau de\p"
	.string "technique ne descend pas.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules_hns:
	.string "Le troisième critère de jugement\n"
	.string "est le “physique”. Il dépend du\p"
	.string "nombre de PV restant à la fin du\n"
	.string "combat.\p"
	.string "Cela prend en compte les PV que\n"
	.string "le POKéMON avait au début et\p"
	.string "ceux qui lui restent à la fin.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon_hns:
	.string "Vous avez arraché la victoire à\n"
	.string "la PRO DU DOJO et battu sept\p"
	.string "DRESSEURS!\p"
	.string "Félicitations pour cette\n"
	.string "magnifique performance!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints_hns:
	.string "Cher DRESSEUR, votre cran vous\n"
	.string "rapporte des POINTS DE COMBAT.$"
