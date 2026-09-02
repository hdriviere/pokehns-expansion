MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Hé, comment ça va, futur MAITRE\n"
	.string "{PLAYER}?\p"
	.string "VOLTERE, le CHAMPION de LAVANDIA\n"
	.string "utilise des POKéMON du type\p"
	.string "ELECTRIK.\p"
	.string "Si tu utilises des POKéMON du\n"
	.string "type EAU, il n’en fera qu’une\p"
	.string "bouchée! Bzitt!\p"
	.string "Et il a placé des points de\n"
	.string "passage électrifiés dans toute\p"
	.string "l’ARENE!\p"
	.string "Allez, vas-y!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Waouh, électrisant! T’as réussi\n"
	.string "à ouvrir le passage!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Mon âme électrique va briser\n"
	.string "tous tes rêves, waouh, yé!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "C’était branché, amplifié,\n"
	.string "survolté, yé!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "Les POKéMON et la musique, tout\n"
	.string "est question de cœur. Waouh, yé!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "J’ai suivi l’entraînement de\n"
	.string "VOLTERE. Ça va être dur de me\p"
	.string "battre!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Je suis à plat…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "VOLTERE, notre CHAMPION, est ici\n"
	.string "depuis très, très longtemps.\p"
	.string "Il combattait déjà alors que ton\n"
	.string "père n’était pas né, le coriace!$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Cette ARENE est piégée de\n"
	.string "partout! Marrant, non?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "C’est pas marrant d’perdre…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "VOLTERE dit qu’il aime créer des\n"
	.string "petits pièges avec des\p"
	.string "interrupteurs.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Mon charme et les capacités de\n"
	.string "mes POKéMON vont te surprendre!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Je suis surprise par ta\n"
	.string "puissance!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "J’ai entendu dire que LAVANDIA\n"
	.string "avait été fondée par VOLTERE.\p"
	.string "Il était DRESSEUR bien avant\n"
	.string "qu’on ne le devienne nous-mêmes.\p"
	.string "Il doit en connaître des choses!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "J’adore les choses qui brillent!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh… Mes yeux sont trop fatigués…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "Le CHAMPION D’ARENE de LAVANDIA,\n"
	.string "VOLTERE, est encore là pour\p"
	.string "longtemps. Ça me rend heureux!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "J’ai abandonné l’idée de\n"
	.string "transformer la ville. J’y ai été\p"
	.string "contraint.\p"
	.string "Alors je passe mon temps à\n"
	.string "installer des portes piégées\p"
	.string "dans mon ARENE.\p"
	.string "Oh, mais que fais-tu ici?\p"
	.string "Comment? Tu dis que tu as réussi\n"
	.string "à passer toutes les portes\p"
	.string "piégées?\p"
	.string "Wahahahah! Ça, c’est surprenant!\p"
	.string "Alors moi, VOLTERE, le CHAMPION\n"
	.string "D’ARENE de LAVANDIA, je vais\p"
	.string "t’électriser!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah! Bon, j’ai perdu!\p"
	.string "Tu as réussi à me donner des\n"
	.string "frissons! Prends ce BADGE!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} reçoit le BADGE DYNAMO\n"
	.string "de la part de VOLTERE.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Avec le BADGE DYNAMO, un POKéMON\n"
	.string "peut utiliser ECLATE-ROC hors\p"
	.string "combat.\p"
	.string "Et ça le rend même un peu plus\n"
	.string "rapide.\p"
	.string "Hum… Tu devrais aussi prendre\n"
	.string "ça!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "Cette CT34 contient ONDE DE\n"
	.string "CHOC.\p"
	.string "C’est une capacité très fiable\n"
	.string "qui ne rate jamais. Tu peux\p"
	.string "compter dessus!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE VOLTERE dans le POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Ça me rend optimiste de voir un\n"
	.string "jeune DRESSEUR aussi prometteur\p"
	.string "que toi!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah! Continue et donne\n"
	.string "tout, mon p’tit!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "ARENE POKéMON de LAVANDIA$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "ARENE POKéMON de LAVANDIA\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR\n"
	.string "VOLTERE: {PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "VOLTERE: Aaah! Enfin! Je sais\n"
	.string "pourquoi tu es là. Tu es là pour\p"
	.string "affronter mes POKéMON!\p"
	.string "Wahahaha!\p"
	.string "Ça va faire des étincelles! Ne\n"
	.string "viens pas te plaindre après!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Wooh… Mes batteries sont vides…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "VOLTERE: Je n’ai plus qu’à\n"
	.string "encore recharger mes batteries.\p"
	.string "Quand ça sera fait, j’accepterai\n"
	.string "volontiers de t’affronter à\p"
	.string "nouveau.\p"
	.string "Reviens plus tard, d’accord?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "VOLTERE: Aaah! Enfin! Je sais\n"
	.string "pourquoi tu es là. Tu es là pour\p"
	.string "affronter mes POKéMON!\p"
	.string "Wahahaha!\p"
	.string "Oooh! Attends! Tu n’as qu’un\n"
	.string "POKéMON avec toi?\p"
	.string "Reviens me voir avec au moins\n"
	.string "deux POKéMON, d’accord?$"

