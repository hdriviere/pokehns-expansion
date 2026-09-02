DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hé, comment ça va, futur MAITRE\n"
	.string "{PLAYER}?\p"
	.string "BASTIEN, le CHAMPION D’ARENE de\n"
	.string "MYOKARA a des POKéMON de type\p"
	.string "COMBAT.\p"
	.string "Si tu comptes te battre contre\n"
	.string "lui avec des POKéMON de type\p"
	.string "NORMAL, tu risques la déception.\p"
	.string "Les POKéMON COMBAT infligent de\n"
	.string "sérieux dégâts aux POKéMON de\p"
	.string "type NORMAL. Sois prudent!\p"
	.string "En plus, l’ARENE est plongée\n"
	.string "dans l’obscurité la plus totale.\p"
	.string "Mais elle s’illuminera quand tu\n"
	.string "auras vaincu les DRESSEURS sur\p"
	.string "ton chemin.\p"
	.string "Bon, allez, c’est parti!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Ouah! Il y a trop de lumière,\n"
	.string "ici!\p"
	.string "Toi aussi, tu as l’air d’être\n"
	.string "une lumière!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "La puissance est ma raison\n"
	.string "d’être! Allez, bats-toi!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Pas assez de puissance…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Ta compétence a surpassé ma\n"
	.string "force! Ta technique est\p"
	.string "impressionnante!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Inutile de déranger BASTIEN! Je\n"
	.string "vais t’écraser moi-même!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Mais… Comment? Comment as-tu pu\n"
	.string "gagner si facilement?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Je ne vais pas rester sur une\n"
	.string "défaite. Je vais me motiver pour\p"
	.string "l’entraînement!\p"
	.string "Un jour, je deviendrai CHAMPION\n"
	.string "D’ARENE…\p"
	.string "Non, je deviendrai MAITRE de la\n"
	.string "LIGUE POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Comment oses-tu me provoquer?\n"
	.string "Bon, tu ne viendras pas pleurer!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Ouiiiiiiiiiin! J’ai perdu!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "J’ai l’habitude de me battre\n"
	.string "dans le noir pour endurcir mon\p"
	.string "cœur.\p"
	.string "Mais il fait toujours si noir\n"
	.string "que je n’ai jamais vu le visage\p"
	.string "de BASTIEN…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ouh… Fais attention, tu vas\n"
	.string "tomber!$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, toi… Je n’ai pas envie de te\n"
	.string "connaître!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Je te souhaite de te perdre et\n"
	.string "de te retrouver à l’entrée!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Tu vas voir! On ne la fait pas à\n"
	.string "un vieux loup de mer comme moi!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Je t’assure, ce n’est pas mon\n"
	.string "genre de perdre comme ça!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Je crois que tu as bien mérité\n"
	.string "de voir notre CHAMPION D’ARENE.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Si tu veux aller plus loin, tu\n"
	.string "devras d’abord me passer sur le\p"
	.string "corps!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr! Sans commentaire…$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Tu as gagné! Va chercher ce\n"
	.string "BADGE!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Je suis BASTIEN! Le CHAMPION\n"
	.string "D’ARENE de MYOKARA!\p"
	.string "J’ai résisté aux vagues\n"
	.string "déchaînées de la région et je me\p"
	.string "suis endurci dans les cavernes\n"
	.string "obscures!\p"
	.string "Alors, comme ça, tu viens me\n"
	.string "défier? Voyons donc de quoi tu\p"
	.string "es capable!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Pfffou, bon sang! Tu as fait\n"
	.string "plus de vagues que je ne\p"
	.string "l’aurais imaginé!\p"
	.string "Tu m’as submergé!\p"
	.string "Je l’admets, tu m’as vaincu.\n"
	.string "Prends ce BADGE!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} reçoit le BADGE POING\n"
	.string "de la part de BASTIEN.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Le BADGE POING oblige tous les\n"
	.string "POKéMON jusqu’au niveau 30, même\p"
	.string "ceux échangés, à obéir sans\n"
	.string "poser de question.\p"
	.string "Et tu pourras aussi utiliser la\n"
	.string "CS FLASH en dehors des combats.\p"
	.string "Si tu veux, tu peux aussi\n"
	.string "utiliser cette CAPSULE\p"
	.string "TECHNIQUE.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Cette CT08 contient GONFLETTE.\p"
	.string "C’est une technique qui permet\n"
	.string "de booster l’ATTAQUE et la\p"
	.string "DEFENSE.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE BASTIEN dans le POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Je vois que tes talents ont\n"
	.string "causé un raz-de-marée\p"
	.string "d’admiration parmi les\n"
	.string "DRESSEURS, l’autre jour!$"

DewfordTown_Gym_Text_GymStatue:
	.string "ARENE POKéMON du VILLAGE MYOKARA$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "ARENE POKéMON du VILLAGE MYOKARA\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR\n"
	.string "BASTIEN: {PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BASTIEN: La vague se retire,\n"
	.string "mais elle revient toujours sur\p"
	.string "le rivage.\p"
	.string "Toi… Une telle vague de talent…\n"
	.string "Je savais que tu reviendrais!\p"
	.string "Montre-moi tes progrès!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Waouh! Je me suis de nouveau\n"
	.string "fait submerger!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BASTIEN: Les combats sont vastes\n"
	.string "et profonds. On n’en voit pas le\p"
	.string "fond! Exactement comme la mer de\n"
	.string "HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BASTIEN: La vague se replie,\n"
	.string "mais elle revient toujours sur\p"
	.string "le rivage.\p"
	.string "Une telle vague de talent comme\n"
	.string "toi… Je savais que tu\p"
	.string "reviendrais!\p"
	.string "Oh? Tu n’as qu’un POKéMON apte\n"
	.string "au combat?\p"
	.string "Je suis désolé, mais je préfère\n"
	.string "que tu reviennes avec au moins\p"
	.string "deux POKéMON.$"
