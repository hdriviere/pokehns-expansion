SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Je suis le MAITRE DE LA FORME!\n"
	.string "J’ai tout ce qu’il vous faut!$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh? Ton {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Bien joué!\p"
	.string "En récompense, voici ce RUBAN\n"
	.string "pour ton POKéMON.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} reçoit le RUBAN.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} met le RUBAN  sur\n"
	.string "{STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Il faut que tu fasses plus\n"
	.string "d’efforts.\p"
	.string "Si tu le fais, je donnerai\n"
	.string "quelque chose de chouette à ton\p"
	.string "POKéMON.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh! Ton {STR_VAR_1}, ce RUBAN\n"
	.string "lui va bien!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La lumière du phare se voit à\n"
	.string "des kilomètres à la ronde.\p"
	.string "Je me demande si ça n’effraie\n"
	.string "pas les POKéMON dans la mer.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Oh, regarde ça!\p"
	.string "Les algues que l’on peut prendre\n"
	.string "par ici sont fraîches et pleines\p"
	.string "de vie.\p"
	.string "C’est comme si elles allaient se\n"
	.string "cabrer et attaquer!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Là où l’eau est propre, se\n"
	.string "regroupent les fruits de la\p"
	.string "généreuse récolte.\p"
	.string "Et là où les gens se\n"
	.string "rassemblent, s’établit un\p"
	.string "marché.\p"
	.string "C’est ainsi qu’une ville se crée\n"
	.string "et se développe.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Faire ses achats là où l’on peut\n"
	.string "sentir le souffle de l’océan…\p"
	.string "POIVRESSEL est un lieu si\n"
	.string "merveilleux!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Si tu mets des POUPEES ou des\n"
	.string "COUSSINS par terre, ils seront\p"
	.string "salis.\p"
	.string "Je vais acheter des BRIQUES pour\n"
	.string "que mes POUPEES et mes COUSSINS\p"
	.string "ne soient pas salis.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Coool! Je vais bientôt aller me\n"
	.string "battre dans une TENTE DE COMBAT.\p"
	.string "Mais avant, il faut que\n"
	.string "j’attrape quelques POKéMON!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Pfou… Je suis claqué…\p"
	.string "Je suis venu à pied de LAVANDIA.\p"
	.string "Cette ville est immense. Si\n"
	.string "j’avais su, je serais venu en\p"
	.string "VELO.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "POUPE, celui qui a fondé ce\n"
	.string "MUSEE, est aussi à la tête d’une\p"
	.string "équipe d’exploration\n"
	.string "sous-marine.\p"
	.string "Alors tout le monde l’appelle\n"
	.string "CAPT. POUPE.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Qu’est-ce que c’est que ça?\n"
	.string "Cette longue file…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Lorsque j’étais enfant, je\n"
	.string "venais souvent au MUSEE.\p"
	.string "Après avoir vu les expositions,\n"
	.string "je songeais aux mystères de la\p"
	.string "mer.$"

SlateportCity_Text_QuitPushing:
	.string "Hé, toi! Arrête de pousser! Tu\n"
	.string "vois pas que c’est la file\p"
	.string "d’attente?$"

SlateportCity_Text_AquaHasPolicy:
	.string "La TEAM AQUA a une règle\n"
	.string "concernant le rassemblement et\p"
	.string "la dispersion sur le lieu de\n"
	.string "l’action.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Notre CHEF est brillant.\p"
	.string "Mais que veut-il faire avec ce\n"
	.string "MUSEE?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Je me demande en quoi va\n"
	.string "consister le prochain projet.\p"
	.string "Enervé, notre CHEF est\n"
	.string "effrayant, alors j’ferais bien\p"
	.string "d’pas tout faire rater.$"

SlateportCity_Text_ShouldTakeItAll:
	.string "S’il y a quelque chose au MUSEE\n"
	.string "qui peut être utile, on n’a qu’à\p"
	.string "se servir!$"

SlateportCity_Text_DontButtIn:
	.string "Hé, toi, là! On ne coupe pas la\n"
	.string "queue!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Une longue file d’attente, hein?\p"
	.string "Ça me rappelle quand je faisais\n"
	.string "la queue pour acheter les jeux\p"
	.string "qui cartonnaient.$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Pourquoi on fait la queue pour\n"
	.string "payer? On n’a qu’à entrer après\p"
	.string "tout!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Quoi? Quoi?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Tu veux lire ce panneau? Je vais\n"
	.string "le lire pour toi!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Voyons…\p"
	.string "Hum… Je crois que ça dit que la\n"
	.string "vie dans la mer est éternelle.\p"
	.string "Ouaip, je suis sûr que c’est ce\n"
	.string "qui est écrit.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grumpf…\p"
	.string "J’aurais dû apporter ma Game Boy\n"
	.string "Advance pour jouer dans la file\p"
	.string "d’attente…\p"
	.string "Grumpf…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Quand tout sera terminé, on ira\n"
	.string "ensemble aux sources chaudes!\p"
	.string "C’est ce que dit notre leader.\n"
	.string "J’ai super hâte!$"

SlateportCity_Text_SeaIsSoWet:
	.string "La mer est tellement vaste…\p"
	.string "La mer peut-elle être faite des\n"
	.string "larmes versées par les POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Tu sais ce qu’ils font des\n"
	.string "bateaux devenus trop usagés pour\p"
	.string "naviguer?\p"
	.string "Ils les font couler dans la mer\n"
	.string "pour qu’ils servent de refuge\p"
	.string "aux POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "A chaque fois que je viens ici,\n"
	.string "je me laisse emporter et\p"
	.string "j’achète trop.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Si tu veux changer le surnom de\n"
	.string "l’un de tes POKéMON, va voir le\p"
	.string "SPECIALISTE DES NOMS.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Tu ne peux pas donner de surnom\n"
	.string "à un POKéMON échangé.\p"
	.string "L’amour du premier DRESSEUR de\n"
	.string "ce POKéMON est contenu dans ce\p"
	.string "surnom.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Une TENTE DE COMBAT a été\n"
	.string "récemment construite à\p"
	.string "POIVRESSEL.\p"
	.string "Les ARENES sont marrantes, mais\n"
	.string "les TENTES DE COMBAT, c’est\p"
	.string "autre chose.\p"
	.string "Tu devrais y aller si tu veux te\n"
	.string "battre contre des POKéMON\p"
	.string "redoutables.$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "J’espérais qu’il y aurait une\n"
	.string "grande star pour avoir un\p"
	.string "autographe.\p"
	.string "Mais qui est cet homme\n"
	.string "interviewé? Ne serait-ce pas le\p"
	.string "CAPT. POUPE?$"

SlateportCity_Text_InterviewerSoCool:
	.string "La journaliste est tellement\n"
	.string "sympa et si jolie.\p"
	.string "Quand je serai grande, je serai\n"
	.string "reporter international!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Le CAPT. POUPE dit qu’ils ont\n"
	.string "trouvé quelque chose au fond de\p"
	.string "la mer.\p"
	.string "Je me demande ce que c’est…\n"
	.string "Qu’est-ce que ça pourrait bien\p"
	.string "être?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Que se passe-t-il ici?\p"
	.string "Le bon CAPITAINE est-il revenu\n"
	.string "du fond de l’océan avec une\p"
	.string "grosse prise?$"

SlateportCity_Text_AmIOnTV:
	.string "Hé! Tu regardes? Est-ce que je\n"
	.string "passe à la télé?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Une interview à la télé! Là! Le\n"
	.string "CAPITAINE est célèbre!$"

SlateportCity_Text_BigSmileForCamera:
	.string "GUY: OK, CAPT. POUPE, un sourire\n"
	.string "à la caméra!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "INES: Je vois, je vois. Vous\n"
	.string "avez vécu une expérience\p"
	.string "inestimable…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. POUPE: En effet! Nous\n"
	.string "comptons progresser grâce à\p"
	.string "notre exploration.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "INES: Merveilleux, CAPT. POUPE!\n"
	.string "Merci de nous avoir accordé un\p"
	.string "peu de votre précieux temps.\p"
	.string "Nous espérons vous revoir pour\n"
	.string "discuter de nouvelles\p"
	.string "découvertes!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPT. POUPE: Ouh…\p"
	.string "C’était la première fois qu’on\n"
	.string "me filmait pour passer à la\p"
	.string "télé. C’était stressant.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh, {PLAYER}{KUN}! Tu as l’air\n"
	.string "en pleine forme!\p"
	.string "Nous avons fait une grande\n"
	.string "découverte en explorant les\p"
	.string "fonds marins.\p"
	.string "Nous avons trouvé une caverne\n"
	.string "sous-marine sur le CHENAL 128.\p"
	.string "Nous pensons qu’il s’agit de\n"
	.string "l’habitat d’un POKéMON que nous\p"
	.string "croyions disparu.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Hum, hum… CAPT. POUPE, je\n"
	.string "suppose.\p"
	.string "Nous, la TEAM AQUA, allons\n"
	.string "prendre le contrôle de votre\p"
	.string "sous-marin!\p"
	.string "Il est inutile de vous y\n"
	.string "opposer! Nous comptons sur votre\p"
	.string "coopération!\p"
	.string "Hum, hum… Il ne vous reste plus\n"
	.string "qu’à découvrir ce que la TEAM\p"
	.string "AQUA a prévu de faire!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. POUPE: Qu’est-ce que ça\n"
	.string "pouvait bien être?\p"
	.string "On aurait dit quelqu’un avec un\n"
	.string "mégaphone…\p"
	.string "D’où ce son venait-il?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Ça vient de l’EMBARCADERE!\p"
	.string "Le sous-marin! Ils essaient de\n"
	.string "le prendre!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}! Viens avec moi!$"

SlateportCity_Text_BattleTentSign:
	.string "TENTE DE COMBAT de POIVRESSEL\n"
	.string "“Pour les meilleurs POKéMON!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“Recherche marin capable de\n"
	.string "naviguer sur tous les courants.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“Le ferry LE MARINA desservant\n"
	.string "les embarcadères de POIVRESSEL\p"
	.string "et NENUCRIQUE sera bientôt\n"
	.string "terminé.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "CHANTIER NAVAL DE POUPE\p"
	.string "“L’embarquement sur le ferry LE\n"
	.string "MARINA entre POIVRESSEL et\p"
	.string "NENUCRIQUE se fait a\n"
	.string "l’EMBARCADERE.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "FAN CLUB POKéMON “Pour tous les\n"
	.string "fans de POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“La mer infinie supporte toutes\n"
	.string "les formes de vie.”\p"
	.string "MUSEE OCEANOGRAPHIQUE$"

SlateportCity_Text_CitySign:
	.string "POIVRESSEL\p"
	.string "“Le port où le chemin des hommes\n"
	.string "et celui des POKéMON se\p"
	.string "croisent.”$"

SlateportCity_Text_MarketSign:
	.string "MARCHE DE POIVRESSEL “Des objets\n"
	.string "uniques introuvables ailleurs!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "EMBARCADERE DE POIVRESSEL\p"
	.string "“Le ferry LE MARINA est en\n"
	.string "construction au CHANTIER NAVAL.”\p"
	.string "“Il devrait entrer en service\n"
	.string "sous peu.”$"

SlateportCity_Text_HarborSign:
	.string "EMBARCADERE DE POIVRESSEL\p"
	.string "“Profitez d’une merveilleuse\n"
	.string "croisière sur LE MARINA.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "MAISON DU SPECIALISTE DES NOMS\n"
	.string "“Conseil en surnoms de POKéMON.”$"

SlateportCity_Text_ExplainBerries:
	.string "Si un POKéMON sauvage est\n"
	.string "blessé, il se soigne en mâchant\p"
	.string "des BAIES.\p"
	.string "Tu le savais?\p"
	.string "En voyant ça, quelqu’un a eu\n"
	.string "l’idée de faire des médicaments\p"
	.string "à base de BAIES.\p"
	.string "Tu le savais?\p"
	.string "Pour transformer des BAIES en\n"
	.string "médicaments, il faut les réduire\p"
	.string "en poudre.\p"
	.string "Tu le savais?\p"
	.string "On dirait que tu t’intéresses\n"
	.string "aux BAIES!\p"
	.string "J’ai quelque chose qui va\n"
	.string "sûrement te plaire!$"

SlateportCity_Text_ExplainBerryPowder:
	.string "J’ai récemment fait installer\n"
	.string "des machines pour broyer les\p"
	.string "BAIES dans les CENTRES POKéMON.\p"
	.string "Les BROYEURS DE BAIES se\n"
	.string "trouvent dans la SALLE LINK\p"
	.string "DIRECT.\p"
	.string "Tu le savais?\p"
	.string "Pourrais-tu aller faire de la\n"
	.string "POUDRE BAIE pour moi en\p"
	.string "utilisant ces machines?\p"
	.string "Je ferai une préparation juste\n"
	.string "pour toi si tu arrives à broyer\p"
	.string "des BAIES et à me ramener la\n"
	.string "POUDRE BAIE.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "M’as-tu amené de la POUDRE BAIE?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Contre quoi veux-tu l’échanger?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Je vais te donner 1 {STR_VAR_1}\n"
	.string "contre la POUDRE BAIE.$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Hmm. Tu n’as pas assez de POUDRE\n"
	.string "BAIE.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Cette POUDRE BAIE a l’air bonne.\n"
	.string "Ça fera de bons médicaments.\p"
	.string "Tu veux échanger ce qui te reste\n"
	.string "de POUDRE BAIE contre autre\p"
	.string "chose?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "OK! Reviens-me voir quand tu\n"
	.string "auras plus de POUDRE BAIE!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Reviens me voir si tu veux\n"
	.string "échanger de la POUDRE BAIE\p"
	.string "contre des médicaments.\p"
	.string "Je fais toujours des affaires\n"
	.string "ici.\p"
	.string "Tu le savais?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: Hein? C’est pas la\n"
	.string "première fois qu’on se\p"
	.string "rencontre, non?\p"
	.string "Est-ce que je me suis déjà\n"
	.string "présenté? Je m’appelle SCOTT.\p"
	.string "Je viens de voir la TEAM AQUA\n"
	.string "partir d’ici en trombe.\p"
	.string "Laisse-moi deviner… C’est toi\n"
	.string "qui les as fait fuir?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hum… Peut-être…\p"
	.string "Peut-être que ce DRESSEUR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Très bien! Je pense que\n"
	.string "nous allons devenir amis.\p"
	.string "Echangeons nos numéros pour les\n"
	.string "enregistrer dans nos POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Vous avez enregistré SCOTT dans\n"
	.string "le POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: J’aimerais bien rester un\n"
	.string "peu avec toi, mais je veux aussi\p"
	.string "garder un œil sur les autres\n"
	.string "gens talentueux.\p"
	.string "Alors je vais visiter les autres\n"
	.string "villes pendant quelque temps\p"
	.string "encore.\p"
	.string "A bientôt, {PLAYER}{KUN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: Oh, mais… C’est bien toi,\n"
	.string "{PLAYER}{KUN}!\p"
	.string "{PLAYER}{KUN}, je suis sûr que\n"
	.string "tu veux participer au défi de la\p"
	.string "TENTE DE COMBAT!\p"
	.string "C’est une bonne idée! C’est même\n"
	.string "une très bonne idée!\p"
	.string "Après tout, les bons DRESSEURS\n"
	.string "se doivent d’aller dans les\p"
	.string "TENTES DE COMBAT!\p"
	.string "Donne-toi à fond!$"
