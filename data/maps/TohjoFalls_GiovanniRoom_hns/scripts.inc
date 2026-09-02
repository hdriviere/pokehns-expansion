TohjoFalls_GiovanniRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TohjoFalls_GiovanniRoom_OnTransition
	.byte 0

TohjoFalls_GiovanniRoom_OnTransition::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, TRUE, TohjoFalls_GiovanniRoom_SetScene
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 0
	end

TohjoFalls_GiovanniRoom_SetScene::
	setflag FLAG_HIDE_TOHJO_GIOVANNI
	goto_if_ne VAR_TOHJO_FALLS_GIOVANNI_STATE, 0, TohjoFalls_GiovanniRoom_DoNothing
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 1
	end

TohjoFalls_GiovanniRoom_DoNothing::
	end

TohjoFalls_GiovanniRoom_EventScript_Radio::
	msgbox TohjoFalls_GiovanniRoom_Text_RadioObject, MSGBOX_SIGN
	end

TohjoFalls_GiovanniRoom_Text_RadioObject::
	.string "Une radio...\n"
	.string "La batterie est à plat...$"

TohjoFalls_GiovanniRoom_CancelScene::
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 0
	end

TohjoFalls_EventScript_GiovanniSceneRight::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	goto TohjoFalls_EventScript_GiovanniScene

TohjoFalls_EventScript_GiovanniSceneLeft::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	goto TohjoFalls_EventScript_GiovanniScene

TohjoFalls_EventScript_GiovanniScene::
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, TohjoFalls_GiovanniRoom_CancelScene
	lock
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiSpin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	@playse SE_M_PETAL_DANCE
	@delay 10
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	clearflag FLAG_HIDE_TOHJO_GIOVANNI
	addobject LOCALID_TOHJOFALLS_GIOVANNI
	waitse
	playbgm MUS_HG_RADIO_ROCKET, FALSE
	fadescreen FADE_FROM_WHITE
	delay 50
	turnobject  OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox TohjoFalls_GiovanniRoom_Text_Radio, MSGBOX_DEFAULT
	closemessage
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp1
	waitmovement 0
	waitmovement OBJ_EVENT_ID_FOLLOWER
	playse SE_PIN
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_TOHJOFALLS_GIOVANNI
	turnobject LOCALID_TOHJOFALLS_GIOVANNI, DIR_SOUTH
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniIntro, MSGBOX_DEFAULT
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, Common_Movement_WalkDown1
	waitmovement 0
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GIOVANNI_HNS, TohjoFalls_GiovanniRoom_Text_GiovanniDefeat
	playbgm MUS_HG_RADIO_ROCKET, FALSE
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, TohjoFalls_Movement_GiovanniTakenAback
	waitmovement 0
	msgbox TohjoFalls_GiovanniRoom_Text_GiovanniAfter, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_TOHJOFALLS_GIOVANNI, TohjoFalls_Movement_GiovanniLeave
	waitmovement 0 
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_TOHJOFALLS_GIOVANNI
	playse SE_EXIT
	fadescreen FADE_FROM_BLACK
	delay 30

	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement2 OBJ_EVENT_ID_FOLLOWER, TohjoFalls_Movement_CelebiSpin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	@playse SE_M_PETAL_DANCE
	@delay 10
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	fadedefaultbgm
	fadescreen FADE_FROM_WHITE
	setvar VAR_TOHJO_FALLS_GIOVANNI_STATE, 2
	release
	end

TohjoFalls_Movement_CelebiBegin:
	jump_in_place_up
	jump_in_place_up
	step_end

TohjoFalls_Movement_CelebiSpin:
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

TohjoFalls_Movement_GiovanniTakenAback:
	lock_facing_direction
	walk_slow_up
	unlock_facing_direction
	walk_slow_right
	walk_slow_right
	step_end

TohjoFalls_Movement_GiovanniLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	walk_in_place_down
	step_end

TohjoFalls_GiovanniRoom_Text_Radio:
	.string "RADIO: ... ...\n"
	.string "Hum, nous sommes la TEAM ROCKET!\l"
	.string "Après trois ans de préparation,\l"
	.string "nous renaissons de nos cendres!\l"
	.string "GIOVANNI! Nous entendez-vous?\l"
	.string "On a réussi!\l"
	.string "Où est notre chef?\l"
	.string "Est-ce qu'il nous écoute?$"

TohjoFalls_GiovanniRoom_Text_GiovanniIntro:
	.string "GIOVANNI: ...\p"
	.string "Je ne sais pas ce que vous venez\n"
	.string "faire ici, mais ce n'est pas un\l"
	.string "endroit pour des gamins comme\l"
	.string "vous.\p"
	.string "Ce regard...\p"
	.string "Tu me rappelles cet enfant...\p"
	.string "Celui qui, il y a trois ans,\n"
	.string "m'a barré le passage...\p"
	.string "Tu as les mêmes yeux que lui...\p"
	.string "...\p"
	.string "Es-tu là pour m'empêcher de\n"
	.string "rejoindre mes troupes, qui\l"
	.string "m'appellent à DOUBLONVILLE?$"

TohjoFalls_GiovanniRoom_Text_GiovanniBeforeBattle:
	.string "Mes anciens subordonnés ont\n"
	.string "toujours besoin de moi...\p"
	.string "Je ne laisserai pas la cuisante\n"
	.string "erreur d'il y a 3 ans se\l"
	.string "reproduire!$"

TohjoFalls_GiovanniRoom_Text_GiovanniDefeat:
	.string "Mais qui es-tu?$"

TohjoFalls_GiovanniRoom_Text_GiovanniAfter:
	.string "Giovanni: Pou... Pourquoi...!\p"
	.string "Aurais-je passé ces trois années\n"
	.string "en vain?\p"
	.string "Pourquoi mes projets\n"
	.string "sont-ils toujours\p"
	.string "mis en pièces par\n"
	.string "de simples mômes?\p"
	.string "Les rêves de grandeur\n"
	.string "de la Team Rocket\p"
	.string "s’évaporent et\n"
	.string "disparaissent...$"
