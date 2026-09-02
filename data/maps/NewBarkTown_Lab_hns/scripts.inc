.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, NewBarkTown_Lab_EventScript_Elm_AfterEggCheck
	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
NewBarkTown_Lab_EventScript_Elm_AfterEggCheck:
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}!\p"
	.string "Que fais-tu ici?\p"
	.string "Mon assistant t'attend toujours\n"
	.string "à MAUVILLE!$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ELM
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	@callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	@callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	@callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, NewBarkTown_Lab_EventScript_GiveStarter_Chikorita
	call_if_eq VAR_STARTER_MON, 1, NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil
	call_if_eq VAR_STARTER_MON, 2, NewBarkTown_Lab_EventScript_GiveStarter_Totodile
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_GiveStarter_Chikorita::
	call_if_unset FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_1, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Cyndaquil::
	call_if_unset FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_2, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_Totodile::
	call_if_unset FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_NotShiny
	call_if_set FLAG_SHINY_STARTER_3, NewBarkTown_Lab_EventScript_GiveStarter_Shiny
	return

NewBarkTown_Lab_EventScript_GiveStarter_NotShiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_NEVER
	return

NewBarkTown_Lab_EventScript_GiveStarter_Shiny::
	givemon PLAYER_STARTER_SPECIES, 5, ITEM_NONE, BALL_POKE, NATURE_RANDOM, NUM_ABILITY_PERSONALITY, MON_GENDER_RANDOM, 0, 0, 0, 0, 0, 0, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, USE_RANDOM_IVS, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, SHINY_MODE_ALWAYS	
	return

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	setflag FLAG_ENABLE_CONDITION
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_START_NUZLOCKE
	setflag FLAG_EXP_SHARE_ENABLED
	removeitem ITEM_MYSTERY_EGG
	release
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ELM
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	checkspecies SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGETIC
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	checkspecies SPECIES_TOGEKISS
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "Je ne devrais pas toucher à ça!$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "PROF.ORME: {PLAYER}! Te voilà!\p"
	.string "J'ai un service à te demander.\p"
	.string "Je mène actuellement des\n"
	.string "recherches sur les Pokémon.\p"
	.string "J'aimerais que tu m'aides,\n"
	.string "{PLAYER}.\p"
	.string "Vois-tu…\p"
	.string "Je rédige une étude que je veux\n"
	.string "présenter à une conférence.\p"
	.string "Mais certains points m'échappent\n"
	.string "encore.\p"
	.string "Alors!\p"
	.string "J'aimerais que tu entraînes un\n"
	.string "Pokémon capturé récemment.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "Merci, {PLAYER}!\p"
	.string "Tu es chic!$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Mais... J'en ai besoin!$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Quand je publierai mes travaux,\n"
	.string "nous percerons sûrement mieux\p"
	.string "les nombreux mystères des\n"
	.string "Pokémon.\p"
	.string "Tu peux compter là-dessus!$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "Oh! J'ai reçu un mail!\p"
	.string "… … … … … … … …\n"
	.string "Hum… Oui…\p"
	.string "D'accord…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Ecoute voir.\p"
	.string "J'ai un ami du nom de M.Pokémon.\p"
	.string "Il découvre sans cesse de drôles\n"
	.string "de trucs.\p"
	.string "Il vient de m'envoyer un e-mail\p"
	.string "disant qu'il a quelque chose à\n"
	.string "me montrer.\p"
	.string "C'est tentant mais j'ai vraiment\n"
	.string "trop de travail...\p"
	.string "Attends!\p"
	.string "Je sais!\p"
	.string "{PLAYER}, peux-tu y aller pour\n"
	.string "moi?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Je veux que tu entraînes l'un\p"
	.string "des Pokémon dans ces BALLS.\p"
	.string "Il sera ton nouvel ami,\n"
	.string "{PLAYER}!\p"
	.string "Allez! Choisis!$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "PROF.ORME: Hep! Où vas-tu?$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "Tu prends {STR_VAR_1},\n"
	.string "le Pokémon {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "Tu veux {STR_VAR_1},\n"
	.string "le Pokémon {STR_VAR_2}?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "Tu préfères {STR_VAR_1},\n"
	.string "le Pokémon {STR_VAR_2}?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "PROF.ORME: Fais le bon choix!\p"
	.string "Ton partenaire est très\n"
	.string "important.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "PROF.ORME: C'est un très bon\n"
	.string "Pokémon!$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER} reçoit {STR_VAR_1}!$"

NewBarkTown_Lab_Text_Nickname:
	.string "Veux-tu donner un surnom à\n"
	.string "{STR_VAR_1}?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "M.Pokémon habite un peu après\n"
	.string "VILLE GRIOTTE, la ville voisine.\p"
	.string "Le chemin est presque direct,\n"
	.string "tu ne peux pas te perdre.\p"
	.string "Au cas où, tu as mon numéro.\n"
	.string "Appelle-moi s'il arrive quelque\p"
	.string "chose!$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Si un Pokémon sauvage apparaît,\n"
	.string "défie-le avec ton Pokémon adoré!$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "Si un Pokémon sauvage apparaît,\n"
	.string "fais combattre ton Pokémon!\p"
	.string "S'il est blessé, soigne-le avec\n"
	.string "la machine à ma droite,\p"
	.string "ou dans un Centre Pokémon.\p"
	.string "Je compte sur toi!$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} reçoit le numéro de\n"
	.string "tél. du PROF.ORME.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "M.Pokémon parcourt le monde et\n"
	.string "trouve des objets rares.\p"
	.string "Dommage qu'ils soient seulement\n"
	.string "rares et rarement utiles…$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Cela contient un Pokémon attrapé\n"
	.string "par le PROF.ORME.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ORME: {PLAYER}, c'est affreux...\p"
	.string "Au fait, quelle est la grande\n"
	.string "découverte de M.Pokémon?$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} confie l'OEUF MYSTERE\n"
	.string "au PROF.ORME.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "PROF.ORME: Ca?$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Mais… C'est un OEUF de Pokémon?\p"
	.string "Si c'est un vrai, c'est une\n"
	.string "grande découverte!\p"
	.string "ORME: Quoi?!?\p"
	.string "Le PROF.CHEN t'a donné un\n"
	.string "Pokédex?\p"
	.string "{PLAYER}, c'est vrai?\n"
	.string "C-c'est incroyable!\p"
	.string "Il a l'œil pour trouver les bons\n"
	.string "Dresseurs pleins d'avenir.\p"
	.string "{PLAYER}… Tu dois avoir les\n"
	.string "épaules pour devenir Maître.\p"
	.string "Tu as aussi l'air de bien\n"
	.string "t'entendre avec les Pokémon.\p"
	.string "Tu devrais partir à la conquête\n"
	.string "des Arènes.\p"
	.string "La plus proche est celle de\n"
	.string "MAUVILLE.\p"
	.string "…{PLAYER}. La route vers la\n"
	.string "victoire sera longue.\p"
	.string "Va parler à ta maman avant de\n"
	.string "partir.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "PROF.ORME: N'abandonne pas!\p"
	.string "Je t'appelle si j'ai du nouveau\n"
	.string "sur cet OEUF.$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ORME: {PLAYER}? N'as-tu pas vu\n"
	.string "mon assistant?\p"
	.string "Il aurait dû te rencontrer avec\p"
	.string "l'OEUF au CENTRE Pokémon de\n"
	.string "MAUVILLE.\p"
	.string "Tu as dû le rater. Va le voir\n"
	.string "là-bas.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ORME: L'OEUF a-t-il évolué?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER}? Je croyais que l'OEUF\n"
	.string "avait éclos.\p"
	.string "Où est le Pokémon?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ORME: {PLAYER}, tu es en pleine\n"
	.string "forme!$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "Quoi? Ce Pokémon!?!$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "L'OEUF a éclos! Donc les Pokémon\n"
	.string "naissent à partir d'OEUFS...\p"
	.string "Mais ce n'est peut-être pas le\n"
	.string "cas pour tous les Pokémon.\p"
	.string "Et beh, on a encore du boulot\n"
	.string "avant de tout savoir.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Merci, {PLAYER}! Tu aides mes\p"
	.string "recherches sur les Pokémon!\p"
	.string "Voilà pour toi! Cadeau!$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "C'est une PIERRE STASE.\p"
	.string "Certaines espèces\n"
	.string "de Pokémon évoluent\p"
	.string "lorsqu'elles atteignent\n"
	.string "un certain niveau.\p"
	.string "Un Pokémon tenant une PIERRE\n"
	.string "STASE n'évoluera pas.\p"
	.string "Donne-la à un Pokémon que tu ne\n"
	.string "veux pas faire évoluer.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ORME: {PLAYER}, je t'appelle si\n"
	.string "j'ai du nouveau.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "...(soupir)... Ce Pokémon\n"
	.string "volé...\p"
	.string "Je me demande comment il va.\p"
	.string "On dit qu'un Pokémon élevé par\p"
	.string "un méchant p'tit bonhomme tourne\n"
	.string "mal lui aussi.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "Merci, {PLAYER}! Tu aides mes\p"
	.string "recherches sur les Pokémon!\p"
	.string "Voilà pour toi! Cadeau!$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "Cette MASTER BALL est la\n"
	.string "meilleure des BALLS!\p"
	.string "Elle attrape n'importe quel\p"
	.string "Pokémon à tous les coups.\p"
	.string "On ne la donne qu'aux grands\n"
	.string "chercheurs Pokémon.\p"
	.string "Tu l'utiliseras mieux que moi,\n"
	.string "{PLAYER}!$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "Au fait…\p"
	.string "De belles femmes en kimono sont\n"
	.string "venues te chercher au Labo.\p"
	.string "Elles t'attendent à la Salle de\n"
	.string "Danse de ROSALIA!\p"
	.string "Les choses sont devenues très\n"
	.string "sérieuses depuis cet OEUF…\p"
	.string "J'espère que tu persévéreras\n"
	.string "jusqu'au bout!$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF.ORME: Les danseuses en\n"
	.string "kimono t'attendent à la Salle\p"
	.string "de Danse de ROSALIA.$"

NewBarkTown_Lab_Text_League:
	.string "PROF.ORME: Haha, félicitations!\p"
	.string "Dire que tout a commencé avec un\n"
	.string "OEUF peu ordinaire!\p"
	.string "Que t'ont dit les danseuses en\n"
	.string "kimono?\p"
	.string "Ah, ce ne sont pas mes affaires!\p"
	.string "Tu as accompli tout cela avec\n"
	.string "toute ton âme!\p"
	.string "Après de telles prouesses, tu\n"
	.string "peux vaincre la Ligue Pokémon!\p"
	.string "Allez! Va au PLATEAU INDIGO!\p"
	.string "Tu sais où il se trouve?\p"
	.string "Suis la ROUTE 27 puis la ROUTE\n"
	.string "26: il sera droit devant toi!$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ORME: {PLAYER}! Te voilà!\p"
	.string "J'ai quelque chose pour toi.\p"
	.string "C'est un... PASSE BATEAU!\p"
	.string "Tu peux aller attraper des\n"
	.string "Pokémon à KANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "Le bateau part d'OLIVILLE.\p"
	.string "Mais ça tu le sais déjà,\n"
	.string "{PLAYER}.\p"
	.string "Après tout, tu as déjà bien\n"
	.string "voyagé.\p"
	.string "Dis bonjour au PROF.CHEN à KANTO\n"
	.string "pour moi!$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "C'est l'OEUF de\n"
	.string "Pokémon que le\p"
	.string "PROF.ORME était en\n"
	.string "train d'étudier.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, prends ceci pour ta\n"
	.string "mission.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "On n'est que trois, alors nous\n"
	.string "sommes toujours occupés.$"

NewBarkTown_Lab_Text_AideSave:
	.string "N'oublie pas de sauvegarder ta\n"
	.string "partie régulièrement!\p"
	.string "Appuie sur START, puis choisis\n"
	.string "SAUVER!$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Il y avait du vacarme dehors...\p"
	.string "Lorsque je suis allé jeter un\n"
	.string "oeil, on avait volé un Pokémon.\p"
	.string "C'est impensable, il\n"
	.string "faut vraiment ne pas\p"
	.string "avoir de coeur pour\n"
	.string "faire une telle chose!\p"
	.string "...(soupir)... Ce Pokémon volé.\p"
	.string "Je me demande comment il va.\p"
	.string "On dit que les Pokémon élevés\p"
	.string "par un méchant deviennent\n"
	.string "mauvais.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER}!\p"
	.string "Utilise ceci pour compléter ton\n"
	.string "Pokédex!$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Pour compléter ton Pokédex, tu\n"
	.string "dois attraper des Pokémon.\p"
	.string "Lance des Poké\n"
	.string "BALLS sur les\p"
	.string "Pokémon sauvages\n"
	.string "pour les attraper.$"

NewBarkTown_Lab_Text_Officer1:
	.string "J'ai entendu dire qu'un Pokémon\n"
	.string "a été volé ici...\p"
	.string "Je viens de recevoir des infos\n"
	.string "du PROF.ORME.\p"
	.string "Apparemment, c'était\n"
	.string "un jeune garnement aux\p"
	.string "longs cheveux rouges...\n"
	.string "Racaille-racaille!\p"
	.string "Quuooi?\p"
	.string "Tu as combattu un dresseur comme\n"
	.string "ça?\p"
	.string "As-tu retenu son nom?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "Il s'appelait donc {RIVAL}.$"

NewBarkTown_Lab_Text_Officer2:
	.string "Merci pour ta coopération!$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "Tu as bien retenu son nom?!$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "Ah, {PLAYER}!\p"
	.string "Où en est ton Pokédex?\p"
	.string "Je suis occupé, mais appelle-moi\n"
	.string "et je suivrai tes progrès!$"
