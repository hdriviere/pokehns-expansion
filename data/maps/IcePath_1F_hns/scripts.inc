IcePath_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

IcePath_1F_EventScript_Item_PpUp::
	finditem ITEM_PP_UP
	end
IcePath_1F_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end
IcePath_1F_EventScript_Item_HM_Waterfall::
	finditem ITEM_HM_WATERFALL
	end

IcePath_1F_EventScript_KimonoGirl::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	goto_if_eq VAR_FACING, DIR_SOUTH, IcePath_1F_EventScript_KimonoGirlPushPrompt
	msgbox IcePath_1F_Text_Stuck1, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	release
	end

IcePath_1F_Trigger_KimonoGirl::
	lock
	msgbox IcePath_1F_Text_Leave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

IcePath_1F_EventScript_KimonoGirlPushPrompt::
	msgbox IcePath_1F_Text_Stuck2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused
IcePath_1F_EventScript_KimonoGirlPush::
	msgbox IcePath_1F_Text_Shove, MSGBOX_AUTOCLOSE
	closemessage
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, IcePath_Movement_PlayerJump
	waitmovement 0
	waitse
	playse SE_M_ICY_WIND
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoSlide
	waitmovement 0
	msgbox IcePath_1F_Text_Thanks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ICEPATH1_KIMONO, IcePath_Movement_KimonoLeave
	waitmovement LOCALID_ICEPATH1_KIMONO
	setflag FLAG_HIDE_ICE_PATH_KIMONO
	removeobject LOCALID_ICEPATH1_KIMONO
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_ICE_PATH_STATE, 1
	release
	end

IcePath_1F_EventScript_KimonoGirlRefused::
	msgbox IcePath_1F_Text_Cruel, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IcePath_1F_EventScript_KimonoGirlPush
	goto_if_eq VAR_RESULT, FALSE, IcePath_1F_EventScript_KimonoGirlRefused

IcePath_Movement_PlayerJump:
	jump_in_place_down
	step_end

IcePath_Movement_KimonoSlide:
	slide_down
	slide_down
	slide_down
	slide_down
	walk_in_place_fast_down
	face_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

IcePath_Movement_KimonoLeave:
	walk_down
	walk_down
	walk_down
	step_end

IcePath_1F_Text_Leave:
	.string "DANSEUSE: ...............$"

IcePath_1F_Text_Stuck1:
    .string "Tiens donc, {PLAYER}... Quelle\n"
    .string "plaisante surprise de te\p"
    .string "rencontrer ici!\p"
    .string "En fait... Mes sandales se sont\n"
    .string "prises dans la\p"
    .string "glace, et je ne peux plus\n"
    .string "bouger...\p"
    .string "Les sandales d’été, dans la\n"
    .string "neige glacée... Bref.\p"
    .string "Ce n’est pas le\n"
    .string "moment de faire de\p"
    .string "la poésie! Peux-tu\n"
    .string "me venir en aide?\p"
    .string "Il faudrait que tu me pousses\n"
    .string "dans le dos...$"

IcePath_1F_Text_Stuck2:
	.string "Tiens donc, {PLAYER}...\n"
	.string "Quelle surprise de te voir ici!\p"
	.string "En fait... Mes sandales sont\n"
	.string "prises dans la glace.\p"
	.string "Je ne peux plus bouger.\p"
	.string "Mes tongs ont été surgelées\n"
	.string "avec le sol.\p"
	.string "Hi, hi.\p"
	.string "Ce n'est pourtant pas drôle.\n"
	.string "Peux-tu me pousser dans le dos?$"

IcePath_1F_Text_Shove:
	.string "....POUSSE!....$"

IcePath_1F_Text_Cruel:
	.string "Ne sois pas si cruel.\n"
	.string "Tu vas me pousser, n'est-ce pas?$"

IcePath_1F_Text_Thanks:
    .string "Tu es bien aimable...\p"
    .string "Merci infiniment!$"
