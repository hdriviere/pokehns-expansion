CeruleanCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CERULEAN_GYM_ROCKET
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_HNS, CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA_HNS, CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER_HNS, CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON D'AZURIA\n"
    .string "CHAMPIONNE: ONDINE\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON D'AZURIA\n"
    .string "CHAMPIONNE: ONDINE\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED,\n"
    .string "{PLAYER}$"

CeruleanGym_Text_Note:
	.string "Désolée, je m'absente un moment.\n"
	.string "ONDINE, CHAMPIONNE d'ARÈNE\p"
	.string "Puisque ONDINE est sortie, nous\n"
	.string "aussi.\l"
	.string "LES DRESSEURS de l'ARÈNE$"


CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY_HNS, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers_hns
	msgbox CeruleanGym_Text_Misty_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	msgbox CeruleanGym_Text_Misty_ExplainTM, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_CAPE_MISTY
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanGym_Text_GruntIntro:
	.string "Oups! Pardon! Tu vas bien?\p"
	.string "J'suis occupé. Pas le temps. Au\n"
	.string "revoir. Tu m'as pas vu, OK?$"

CeruleanGym_Text_GruntBigMistake:
	.string "... Oh non! Tu m'as déjà vu!\p"
	.string "J'ai fait une énorme erreur!$"

CeruleanGym_Text_GruntBye:
	.string "Hé toi! Tu oublies que tu m'as\n"
	.string "vu,\p"
	.string "OK? Allez... Adieu!\p"
	.string "Adieuuuu!$"

CeruleanGym_Text_Note1:
	.string "Désolée, je m'absente un moment.\n"
	.string "ONDINE, CHAMPIONNE d'ARÈNE\p"
	.string "Puisque ONDINE est sortie, nous\n"
	.string "aussi. LES DRESSEURS de l'ARÈNE$"

CeruleanGym_Text_MistyIntro:
	.string "Ondine: Ah! Enfin!\n"
	.string "Tu vas voir ce que\p"
	.string "ça coûte de gâcher\n"
	.string "mes rendez-vous!\p"
	.string "Tu as peut-être\n"
	.string "plein de Badges\p"
	.string "de Johto, mais tu\n"
	.string "vas quand même te\p"
	.string "prendre une sacrée raclée.\p"
	.string "Tu ne peux rien contre mes\n"
	.string "Pokémon de type Eau!$"

CeruleanGym_Text_MistyWinLoss:
	.string "ONDINE: OK. T'es pas naze...\p"
	.string "Je le reconnais...\p"
	.string "Tiens. V'là le BADGECASCADE.$"

CeruleanGym_Text_ReceivedBadge:
	.string "{PLAYER} reçoit le BADGECASCADE.$"

CeruleanGym_Text_MistyFightDone:
	.string "ONDINE: Y a-t-il\n"
	.string "des dresseurs\p"
	.string "doués à JOHTO? Un\n"
	.string "peu comme toi...\p"
	.string "Je vais y aller un jour. Ca me\p"
	.string "fera de l'entraînement.$"

CeruleanGym_Text_MistyRematch:
	.string "ONDINE: Waouh, tu es maintenant\n"
	.string "MAÎTRE de KANTO!\p"
	.string "C'est incroyable! Tu as fait du\n"
	.string "chemin, {PLAYER}.\p"
	.string "Mais je ne reculerai pas.\p"
	.string "Veux-tu me réaffronter?$"

CeruleanGym_Text_MistyRematchDefeat:
	.string "ONDINE: Tu es vraiment fort…$"

CeruleanGym_Text_SwimmerfDianaSeen:
	.string "Désolée d'avoir été absente. On\n"
	.string "y va!$"

CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "OK! T'as gagné!$"

CeruleanGym_Text_SwimmerfDianaAfter:
	.string "Je vais nager tranquillement.$"

CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "Je nage trop bien. Ca t'énerve?$"

CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "Ooh! Impressionnant!$"

CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "Ne crâne pas trop...\p"
	.string "ONDINE va te faire mal...$"

CeruleanGym_Text_SwimmermParkerSeen:
	.string "Gloups...\p"
	.string "C’est moi le premier! A\n"
	.string "l’attaque!$"

CeruleanGym_Text_SwimmermParkerBeaten:
	.string "Impossible...$"

CeruleanGym_Text_SwimmermParkerAfter:
	.string "ONDINE s'est bien améliorée\n"
	.string "depuis un certain temps.\p"
	.string "Fais bien attention, ou tu vas\n"
	.string "le regretter!$"

CeruleanGym_Text_GuideIntro:
	.string "Hé! Graine de star!\p"
	.string "Quand ONDINE\n"
	.string "était partie,\p"
	.string "j'suis allé me\n"
	.string "balader. Hé hé hé!$"

CeruleanGym_Text_GuideWin:
	.string "Whoa! Tu es un p'tit tigre!\p"
	.string "Quel beau combat! Comme\n"
	.string "toujours, quoi!$"

CeruleanGym_Text_Misty_GiveTM:
	.string "Tiens, prends aussi ceci.$"

CeruleanGym_Text_Misty_ExplainTM:
	.string "C'est la CT VIBRAQUA.\p"
	.string "Elle inflige des dégâts et peut\n"
	.string "aussi rendre confus!$"
