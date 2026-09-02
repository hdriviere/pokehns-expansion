GoldenrodCity_UndergroundSwitches_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodUnderground1_OnLoad
	.byte 0

GoldenrodUnderground1_OnLoad::
	setvar VAR_TEMP_0, 0
	call_if_set FLAG_COMPLETED_SWITCHES, GoldenrodUnderground1_ClearTheWay
	clearflag FLAG_GOLDENROD_SWITCH_1
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	end

GoldenrodUnderground1_ClearTheWay::
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	return

@ Added an antisoft lock, using wall panels
@ Added more anti softlock 

GoldenrodCity_UndergroundSwitches_InDoorAntiLock::
	lock
	msgbox GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NoOp
	warp MAP_GOLDENROD_CITY_UNDERGROUND_SWITCHES_HNS, 2, 25, 5
	waitstate
	release
	end

GoldenrodCity_UndergroundSwitches_InDoorAntiLock2::
	lock
	setvar VAR_TEMP_0, 1
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock::
	lock
	msgbox GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP
	closemessage
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_TP::
	warp MAP_GOLDENROD_CITY_UNDERGROUND_SWITCHES_HNS, 2, 25, 5
	waitstate
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_AntiSoftLock_Text::
	.string "Tu sembles bloqué.\p"
	.string "Retourner à l'entrée et\n"
	.string "réinitialiser les interrupteurs?$"

@ 3->2->1

@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel1::
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_Panel1Activate @lock all
	clearflag FLAG_GOLDENROD_SWITCH_1
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch1Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel1Activate:: @unlock basic
	setflag FLAG_GOLDENROD_SWITCH_1
	goto_if_set FLAG_GOLDENROD_SWITCH_ORDER, GoldenrodCity_UndergroundSwitches_EventScript_Panel1ActivateCorrect
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_Panel1ActivateCorrect:: @unlock the right path
	playse SE_CLICK
	setflag FLAG_COMPLETED_SWITCHES
	msgbox GoldenrodUnderground_Text_Switch1, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end
@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel2:: @lock all
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_2, GoldenrodCity_UndergroundSwitches_EventScript_Panel2Activate
	clearflag FLAG_GOLDENROD_SWITCH_2
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2Activate:: @unlock basic
	setflag FLAG_GOLDENROD_SWITCH_2
	goto_if_set FLAG_GOLDENROD_SWITCH_1, GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateWrong
	goto_if_set FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateCorrect
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateWrong:: @unlock basic
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_Panel2ActivateCorrect:: @unlock item2
	setflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_Switch2, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4	
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6	
	special DrawWholeMapView
	waitse
	release
	end


@==============================================================================================================================================
GoldenrodCity_UndergroundSwitches_EventScript_Panel3:: @lock all
	lock
	goto_if_unset FLAG_GOLDENROD_SWITCH_3, GoldenrodCity_UndergroundSwitches_EventScript_Panel3Activate
	clearflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_BANG
	msgbox GoldenrodUnderground_Text_Switch3Off, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Panel3Activate:: @unlock item 1
	setflag FLAG_GOLDENROD_SWITCH_3
	clearflag FLAG_GOLDENROD_SWITCH_ORDER
	playse SE_CLICK
	msgbox GoldenrodUnderground_Text_Switch3, MSGBOX_DEFAULT
	closemessage
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1
	call GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5
	call GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6
	special DrawWholeMapView
	waitse
	release
	end

@==============================================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall1::
	setmetatile 5, 7, 0x399, FALSE
	setmetatile 6, 7, 0x39A, FALSE
	setmetatile 7, 7, 0x39B, FALSE

	setmetatile 5, 8, 0x3A1, FALSE
	setmetatile 6, 8, 0x3A2, FALSE
	setmetatile 7, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall2::
	setmetatile 14, 7, 0x399, FALSE
	setmetatile 15, 7, 0x39A, FALSE
	setmetatile 16, 7, 0x39B, FALSE

	setmetatile 14, 8, 0x3A1, FALSE
	setmetatile 15, 8, 0x3A2, FALSE
	setmetatile 16, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall3::
	setmetatile 23, 7, 0x399, FALSE
	setmetatile 24, 7, 0x39A, FALSE
	setmetatile 25, 7, 0x39B, FALSE

	setmetatile 23, 8, 0x3A1, FALSE
	setmetatile 24, 8, 0x3A2, FALSE
	setmetatile 25, 8, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall4::
	setmetatile 5, 11, 0x399, FALSE
	setmetatile 6, 11, 0x39A, FALSE
	setmetatile 7, 11, 0x39B, FALSE

	setmetatile 5, 12, 0x3A1, FALSE
	setmetatile 6, 12, 0x3A2, FALSE
	setmetatile 7, 12, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall5::
	setmetatile 14, 11, 0x399, FALSE
	setmetatile 15, 11, 0x39A, FALSE
	setmetatile 16, 11, 0x39B, FALSE

	setmetatile 14, 12, 0x3A1, FALSE
	setmetatile 15, 12, 0x3A2, FALSE
	setmetatile 16, 12, 0x3A3, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_CreateWall6::
	setmetatile 23, 11, 0x399, FALSE
	setmetatile 24, 11, 0x39A, FALSE
	setmetatile 25, 11, 0x39B, FALSE

	setmetatile 23, 12, 0x3A1, FALSE
	setmetatile 24, 12, 0x3A2, FALSE
	setmetatile 25, 12, 0x3A3, FALSE
	return
@======================================================================================================================

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall1::
	setmetatile 5, 7, 0x378, FALSE
	setmetatile 6, 7, 0x379, FALSE
	setmetatile 7, 7, 0x37A, FALSE
	
	setmetatile 5, 8, 0x380, FALSE
	setmetatile 6, 8, 0x381, FALSE
	setmetatile 7, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall2::
	setmetatile 14, 7, 0x378, FALSE
	setmetatile 15, 7, 0x379, FALSE
	setmetatile 16, 7, 0x37A, FALSE
	
	setmetatile 14, 8, 0x380, FALSE
	setmetatile 15, 8, 0x381, FALSE
	setmetatile 16, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall3::
	setmetatile 23, 7, 0x378, FALSE
	setmetatile 24, 7, 0x379, FALSE
	setmetatile 25, 7, 0x37A, FALSE
	
	setmetatile 23, 8, 0x380, FALSE
	setmetatile 24, 8, 0x381, FALSE
	setmetatile 25, 8, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall4::
	setmetatile 5, 11, 0x378, FALSE
	setmetatile 6, 11, 0x379, FALSE
	setmetatile 7, 11, 0x37A, FALSE
	
	setmetatile 5, 12, 0x380, FALSE
	setmetatile 6, 12, 0x381, FALSE
	setmetatile 7, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall5::
	setmetatile 14, 11, 0x378, FALSE
	setmetatile 15, 11, 0x379, FALSE
	setmetatile 16, 11, 0x37A, FALSE
	
	setmetatile 14, 12, 0x380, FALSE
	setmetatile 15, 12, 0x381, FALSE
	setmetatile 16, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_RemoveWall6::
	setmetatile 23, 11, 0x378, FALSE
	setmetatile 24, 11, 0x379, FALSE
	setmetatile 25, 11, 0x37A, FALSE
	
	setmetatile 23, 12, 0x380, FALSE
	setmetatile 24, 12, 0x381, FALSE
	setmetatile 25, 12, 0x382, FALSE
	return

GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerTop::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	@clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 9
	release
	end


GoldenrodCity_UndergroundSwitches_EventScript_SilverTriggerBot::
	lock
	playse SE_EXIT
	waitse
	playse SE_PIN
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	addobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	waitmovement 0
	msgbox GoldenrodUnderground_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, GoldenrodCity_UndergroundSwitches_EventScript_Totodile
	call_if_eq VAR_STARTER_MON, 2, GoldenrodCity_UndergroundSwitches_EventScript_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox GoldenrodUnderground_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_SILVER, GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	removeobject LOCALID_GOLDENROD_UNDERGROUND_SILVER
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 9
	release
	end

GoldenrodCity_UndergroundSwitches_EventScript_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_4_HNS, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_4_HNS, GoldenrodUnderground_Text_SilverWin
	return

GoldenrodCity_UndergroundSwitches_EventScript_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_4_HNS, GoldenrodUnderground_Text_SilverWin
	return



GoldenrodCity_UndergroundSwitches_Movement_SilverEnterTop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveTop:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_right
	step_end


GoldenrodCity_UndergroundSwitches_Movement_SilverEnterBot:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundSwitches_Movement_SilverLeaveBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end	

GoldenrodCity_UndergroundSwitches_EventScript_Grunt10::
    trainerbattle_single TRAINER_GRUNT_10_HNS, GoldenrodUnderground_Text_GruntM11Seen, GoldenrodUnderground_Text_GruntM11Beaten
	msgbox GoldenrodUnderground_Text_GruntM11After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt20::
    trainerbattle_single TRAINER_GRUNT_20_HNS, GoldenrodUnderground_Text_GruntM25Seen, GoldenrodUnderground_Text_GruntM25Beaten
	msgbox GoldenrodUnderground_Text_GruntM25After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Duncan::
    trainerbattle_single TRAINER_DUNCAN_HNS, GoldenrodUnderground_Text_BurglarDuncanSeen, GoldenrodUnderground_Text_BurglarDuncanBeaten
	msgbox GoldenrodUnderground_Text_BurglarDuncanAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Eddie::
    trainerbattle_single TRAINER_EDDIE_HNS, GoldenrodUnderground_Text_BurglarEddieSeen, GoldenrodUnderground_Text_BurglarEddieBeaten
	msgbox GoldenrodUnderground_Text_BurglarEddieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt11::
    trainerbattle_single TRAINER_GRUNT_11_HNS, GoldenrodUnderground_Text_GruntM13Seen, GoldenrodUnderground_Text_GruntM13Beaten
	msgbox GoldenrodUnderground_Text_GruntM13After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Grunt27::
    trainerbattle_single TRAINER_GRUNT_27_HNS, GoldenrodUnderground_Text_GruntF3Seen, GoldenrodUnderground_Text_GruntF3Beaten
	msgbox GoldenrodUnderground_Text_GruntF3After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_Revive::
	finditem ITEM_MAX_REVIVE
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_MaxPotion::
	finditem ITEM_MAX_POTION
	end

GoldenrodCity_UndergroundSwitches_EventScript_Item_SmokeBall::
	finditem ITEM_SMOKE_BALL
	end

GoldenrodUnderground_Text_SilverBefore:
    .string "Attends!\p"
    .string "Je t'ai vu, alors je t'ai suivi.\p"
    .string "Je ne veux pas t'avoir dans les\n"
    .string "pattes face à la TEAM ROCKET.\p"
    .string "…Une seconde. Tu m'as battu,\n"
    .string "pas vrai?\p"
    .string "C'était juste un coup de chance.\p"
    .string "J'ai entraîné mon équipe.\p"
    .string "Je vais enfin régler ma dette!$"

GoldenrodUnderground_Text_SilverWin:
    .string "... Pourquoi? Pourquoi je perds\n"
    .string "encore?\p"
    .string "J’ai récupéré les\n"
    .string "Pokémon les plus\p"
    .string "forts, je retiens\n"
    .string "pas mes coups...\p"
    .string "Alors pourquoi?$"

GoldenrodUnderground_Text_SilverAfter:
    .string "C'est... Incroyable...\p"
    .string "Ce qu'a dit PETER est donc vrai?\p"
    .string "Je m'occupe mal de mes Pokémon?\p"
    .string "Amour...\p"
    .string "Confiance...\p"
    .string "Est-ce aussi important?\p"
    .string "Est-ce la raison de ma défaite?\p"
    .string "Je ne comprends plus rien...\p"
    .string "Mais ce n'est pas la fin.\p"
    .string "Pas maintenant... Pas comme ça.\p"
    .string "Je serai le plus grand dresseur\n"
    .string "de\p"
    .string "Pokémon de tous les temps!$"

GoldenrodUnderground_Text_SilverLoss:
    .string "Voilà de quoi je suis capable!\p"
    .string "Je vais finir d’anéantir la Team\n"
    .string "Rocket, puis j’irai écraser\p"
    .string "ce Peter pour de bon!$"

GoldenrodUnderground_Text_GruntM11Seen:
    .string "Ouvre un truc et un autre se\n"
    .string "ferme.\p"
    .string "C'est dur d'avancer, hein?$"

GoldenrodUnderground_Text_GruntM11Beaten:
    .string "Zut de flûte! J'suis perdu!$"

GoldenrodUnderground_Text_GruntM11After:
    .string "Moi aussi je m'y perds: le\n"
    .string "premier\p"
    .string "interrupteur à activer est au\n"
    .string "bout et après...$"

GoldenrodUnderground_Text_GruntM25Seen:
    .string "Kwahaha!\p"
    .string "Les volets te posent un\n"
    .string "problème?\p"
    .string "Bats-moi et je te confie un\n"
    .string "p'tit secret!$"

GoldenrodUnderground_Text_GruntM25Beaten:
    .string "Hmmm... Dommage.$"

GoldenrodUnderground_Text_GruntM25After:
    .string "OK. Un conseil!\p"
    .string "Change l'ordre d'activation.\p"
    .string "Et l'ordre de fermeture des\n"
    .string "volets changera.$"

GoldenrodUnderground_Text_BurglarDuncanSeen:
    .string "Envoie ton blé!$"

GoldenrodUnderground_Text_BurglarDuncanBeaten:
    .string "Pitié!$"

GoldenrodUnderground_Text_BurglarDuncanAfter:
    .string "Je revends les affaires que je\n"
    .string "vole. C’est ça, être méchant!$"

GoldenrodUnderground_Text_BurglarEddieSeen:
    .string "C’est là qu’ils bazardent les\n"
    .string "projets abandonnés.\p"
    .string "Je cherche des restes à voler.$"

GoldenrodUnderground_Text_BurglarEddieBeaten:
    .string "Yarglah!$"

GoldenrodUnderground_Text_BurglarEddieAfter:
    .string "Le DEPOT SOUTERRAIN?\p"
    .string "Pourquoi tu veux y aller?\p"
    .string "Y'a rien du tout dans le coin.$"

GoldenrodUnderground_Text_GruntM13Seen:
    .string "Je m'en fiche si tu ne sais pas\n"
    .string "par où aller.\p"
    .string "Si tu viens ici, tu dois\n"
    .string "t'attendre aux conséquences!$"

GoldenrodUnderground_Text_GruntM13Beaten:
    .string "Gueuh! Tu te crois balèze ou\n"
    .string "quoi?$"

GoldenrodUnderground_Text_GruntM13After:
    .string "T'as un sacré courage pour\n"
    .string "t'attaquer à la ROCKET.$"

GoldenrodUnderground_Text_GruntF3Seen:
    .string "Alors, on a perdu\n"
    .string "son chemin? Non,\p"
    .string "t’as pas l’air\n"
    .string "d’avoir peur.\p"
    .string "Attends... MOI je\n"
    .string "vais t’apprendre\p"
    .string "ce que c’est\n"
    .string "que la terreur!$"

GoldenrodUnderground_Text_GruntF3Beaten:
    .string "Comment oses-tu?$"

GoldenrodUnderground_Text_GruntF3After:
    .string "Va où tu veux! Va-t'en! Je m'en\n"
    .string "fiche!$"

GoldenrodUnderground_Text_Switch1:
    .string "INTERRUPTEUR 1 activé.$"

GoldenrodUnderground_Text_Switch2:
    .string "INTERRUPTEUR 2 activé.$"

GoldenrodUnderground_Text_Switch3:
    .string "INTERRUPTEUR 3 activé.$"

GoldenrodUnderground_Text_Switch1Off:
    .string "INTERRUPTEUR 1 désactivé.$"

GoldenrodUnderground_Text_Switch2Off:
    .string "INTERRUPTEUR 2 désactivé.$"

GoldenrodUnderground_Text_Switch3Off:
    .string "INTERRUPTEUR 3 désactivé.$"
