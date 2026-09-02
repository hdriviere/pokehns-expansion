SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo, ça baigne pour toi, futur\n"
	.string "MAITRE {PLAYER}?\p"
	.string "JUAN, le CHAMPION d’ATALANOPOLIS\n"
	.string "est le spécialiste des POKéMON\p"
	.string "du type EAU.\p"
	.string "Mais pour le rencontrer, il te\n"
	.string "faudra réussir à avancer sur un\p"
	.string "sol gelé…\p"
	.string "Ecoute, je suis désolé, mais\n"
	.string "c’est tout ce que je peux te\p"
	.string "dire.\p"
	.string "Pour le reste, il va falloir que\n"
	.string "tu te débrouilles!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Waouh! Tu as même battu JUAN,\n"
	.string "censé être le meilleur de tout\p"
	.string "HOENN!\p"
	.string "OK! Regarde ta CARTE DRESSEUR.\p"
	.string "Si tu as tous les BADGES, tu vas\n"
	.string "pouvoir relever le défi de la\p"
	.string "LIGUE POKéMON!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Laissez-moi vous demander.\n"
	.string "Saviez-vous que… Ah, je ne\p"
	.string "devrais point être si timide.\p"
	.string "Saviez-vous que j’ai appris à\n"
	.string "MARC tout ce qu’il sait sur les\p"
	.string "POKéMON?\p"
	.string "J’étais autrefois le CHAMPION de\n"
	.string "cette magnifique ARENE.\p"
	.string "Cependant, un concours de\n"
	.string "circonstances m’a forcé à\p"
	.string "revenir.\p"
	.string "Mais assez palabré. Nous\n"
	.string "devrions commencer notre match,\p"
	.string "ne pensez-vous pas?\p"
	.string "Préparez-vous à assister à une\n"
	.string "véritable démonstration de\p"
	.string "talent.\p"
	.string "Une œuvre sur le thème de l’eau\n"
	.string "composée par mes POKéMON et moi.$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ah ah ah, excellent! Très bien,\n"
	.string "la victoire est à vous.\p"
	.string "Je sens en vous l’existence\n"
	.string "d’une force qui vous permettra\p"
	.string "de surmonter les épreuves qui\n"
	.string "vous attendent.\p"
	.string "Cependant, si je vous compare à\n"
	.string "MARC ou bien à moi-même, je peux\p"
	.string "dire que vous manquez encore\n"
	.string "d’élégance.\p"
	.string "Peut-être devrais-je vous prêter\n"
	.string "mon habit?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Ah ah ah, je ne fais que me\n"
	.string "moquer!\p"
	.string "Plutôt que ma veste, je vous\n"
	.string "prie d’accepter ce BADGE PLUIE.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} reçoit le BADGE PLUIE\n"
	.string "de la part de JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Avec ce BADGE, tous vos POKéMON\n"
	.string "vous obéiront et feront tout ce\p"
	.string "que vous leur demanderez.\p"
	.string "Ce BADGE permet aussi d’utiliser\n"
	.string "la capacité CS CASCADE pour\p"
	.string "passer les chutes d’eau.\p"
	.string "Et pour que vous n’oubliiez\n"
	.string "jamais notre combat, prenez\p"
	.string "ceci…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La CT que je vous ai donnée\n"
	.string "contient VIBRAQUA.\p"
	.string "Avec ses vagues d’ultrasons,\n"
	.string "elle vous permettra parfois de\p"
	.string "rendre vos ennemis confus.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE JUAN dans le POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Les DRESSEURS qui ont rassemblé\n"
	.string "tous les BADGES de HOENN doivent\p"
	.string "faire route vers la destination\n"
	.string "ultime.\p"
	.string "La LIGUE POKéMON!\p"
	.string "Dirigez-vous vers la zone la\n"
	.string "plus à l’est de HOENN, jusqu’à\p"
	.string "l’île d’ETERNARA.\p"
	.string "La LIGUE POKéMON se trouve\n"
	.string "là-bas.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Mais il te reste encore un BADGE\n"
	.string "à obtenir à HOENN.\p"
	.string "Si tu veux affronter la LIGUE\n"
	.string "POKéMON, il te faut obtenir ce\p"
	.string "dernier BADGE du CHAMPION\n"
	.string "D’ARENE de CIMETRONELLE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "ARENE POKéMON d’ATALANOPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "ARENE POKéMON d’ATALANOPOLIS\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR\n"
	.string "JUAN: {PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, cette ARENE avait\n"
	.string "enfin retrouvé toute sa\p"
	.string "sérénité…\p"
	.string "Mais le cataclysme que vous êtes\n"
	.string "est de retour pour nous tester\p"
	.string "de nouveau!\p"
	.string "Eh bien j’accepte votre défi\n"
	.string "avec joie!\p"
	.string "Je serai ravi de vous affronter\n"
	.string "aussi souvent que vous le\p"
	.string "souhaitez!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, vous remportez la\n"
	.string "victoire! Vous m’avez de nouveau\p"
	.string "vaincu!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Si je vous demandais de\n"
	.string "devenir mon élève, vous\p"
	.string "refuseriez,  j’en suis certain.\p"
	.string "Je voudrais vous faire don de ma\n"
	.string "veste.\p"
	.string "Mais comme je l’imagine, vous la\n"
	.string "refuseriez de la même façon.\p"
	.string "Et cela, jeune DRESSEUR, est un\n"
	.string "signe certain de noblesse!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, cette ARENE avait\n"
	.string "enfin retrouvé toute sa\p"
	.string "sérénité…\p"
	.string "Mais le cataclysme que vous êtes\n"
	.string "est de retour pour nous tester\p"
	.string "de nouveau!\p"
	.string "Eh bien j’accepte votre défi\n"
	.string "avec joie!\p"
	.string "Ah, mais cessez cela! Vous\n"
	.string "n’avez qu’un POKéMON.\p"
	.string "Je souhaiterais que vous\n"
	.string "reveniez avec au moins deux\p"
	.string "POKéMON.$"

