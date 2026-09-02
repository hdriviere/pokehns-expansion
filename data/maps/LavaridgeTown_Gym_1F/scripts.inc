LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hé, comment ça va, futur MAITRE\n"
	.string "{PLAYER}?\p"
	.string "ADRIANE, CHAMPION D’ARENE de\n"
	.string "VERMILAVA, utilise des POKéMON\p"
	.string "FEU.\p"
	.string "Sa passion des POKéMON est plus\n"
	.string "ardente qu’un volcan.\p"
	.string "Ne t’approche pas trop, tu\n"
	.string "pourrais te brûler! Arrose-la\p"
	.string "avec de l’eau et attaque-la sans\n"
	.string "pitié!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Eh ben! Quelle bataille\n"
	.string "flamboyante!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Ouille ouille ouille! Bon sang,\n"
	.string "c’est brûlant!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "J’ai été aveuglé par la sueur\n"
	.string "qui me coulait dans les yeux…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "S’enterrer dans le sable chaud\n"
	.string "est excellent pour la\p"
	.string "circulation sanguine.\p"
	.string "C’est très efficace contre les\n"
	.string "rhumatismes.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "J’essaie de libérer mon stress.\n"
	.string "J’espère que tu ne viens pas\p"
	.string "pour m’énerver!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "J’espère qu’ADRIANE va te rôtir!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Pffiou…\p"
	.string "C’est étouffant de rester trop\n"
	.string "longtemps dans le sable chaud…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Tu commences à fatiguer. Tu\n"
	.string "préfèrerais sûrement te reposer\p"
	.string "dans le sable chaud, n’est-ce\n"
	.string "pas?\p"
	.string "Mais tu sais sans doute qu’en\n"
	.string "tant que DRESSEUR, tu dois\p"
	.string "garder une volonté à toute\n"
	.string "épreuve.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Quand on joue avec le feu, on se\n"
	.string "brûle…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Tu as vraiment du talent… Mais\n"
	.string "ADRIANE, notre CHAMPION, en a\p"
	.string "encore plus.\p"
	.string "Si tu ne fais pas attention, tu\n"
	.string "vas sérieusement te brûler.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Est-ce que tes POKéMON peuvent\n"
	.string "supporter une chaleur de 200\p"
	.string "degrés?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Ça ne devait pas être assez\n"
	.string "chaud…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La température du magma est de\n"
	.string "200 degrés.\p"
	.string "Tes POKéMON m’ont battu, donc\n"
	.string "ils devraient survivre dans du\p"
	.string "magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Mmmh… D’accord, je vais me\n"
	.string "battre contre toi.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Ouille, quelle puissance!$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "En tant que DRESSEUR, je vais\n"
	.string "devenir jolie et puissante,\p"
	.string "comme ADRIANE.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Allez, battons-nous! Je suis\n"
	.string "chaud!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Malgré la chaleur, j’ai encore\n"
	.string "trop froid aux yeux…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Le combat brûle dans tes veines.\n"
	.string "Tu devrais avoir tes chances\p"
	.string "face à notre CHAMPION.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Tu vois cette flamme dans mon\n"
	.string "regard? C’est la flamme de la\p"
	.string "victoire!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Quelque chose m’a échappé.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Bon, et alors? Je sais marcher\n"
	.string "sur du charbon ardent, moi\p"
	.string "d’abord!\p"
	.string "Mais je ne te conseille pas\n"
	.string "d’essayer!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "J’aime les montagnes, donc\n"
	.string "j’aime aussi les volcans.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "J’ai perdu complètement le\n"
	.string "contrôle de la situation.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Je reste ici car je suis un fan\n"
	.string "d’ADRIANE. Quel regard de\p"
	.string "braise!\p"
	.string "Hé, hé, hé.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Bienvenue… Heu, non, attends.\p"
	.string "Misérable DRESSEUR, je suis\n"
	.string "contente de voir que tu as\p"
	.string "réussi à arriver ici!\p"
	.string "Par les pouvoirs qui me sont\n"
	.string "conférés… Heu, non, attends.\p"
	.string "Je m’appelle ADRIANE et je suis\n"
	.string "le CHAMPION de cette ARENE!\p"
	.string "Heu… Je ne suis pas CHAMPION\n"
	.string "depuis très longtemps, mais ne\p"
	.string "me sous-estime pas!\p"
	.string "Grâce aux techniques de mon\n"
	.string "grand-père, je vais te prouver,\p"
	.string "heu… que mes attaques sont\n"
	.string "puissantes!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh non… Je suppose que j’ai été\n"
	.string "prétentieuse…\p"
	.string "Je… Je ne suis devenue CHAMPION\n"
	.string "D’ARENE que très récemment.\p"
	.string "J’ai essayé de devenir quelqu’un\n"
	.string "que je ne suis pas.\p"
	.string "Je dois agir plus spontanément.\n"
	.string "Sinon, mes POKéMON seront\p"
	.string "confus.\p"
	.string "Merci pour cette leçon. Tu as\n"
	.string "bien mérité ceci.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} reçoit le BADGE CHALEUR\n"
	.string "de la part d’ADRIANE.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Avec le BADGE CHALEUR, tous les\n"
	.string "POKéMON jusqu’au niveau 50\p"
	.string "t’obéiront sans discuter, même\n"
	.string "ceux que tu as échangés avec tes\p"
	.string "amis.\p"
	.string "Il permet aussi à tes POKéMON\n"
	.string "d’utiliser FORCE en dehors des\p"
	.string "combats.\p"
	.string "C’est un gage de ma sympathie.\n"
	.string "Ne sois pas timide. Prends-le!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "La CT50 contient SURCHAUFFE.\p"
	.string "Cette attaque inflige de sérieux\n"
	.string "dégâts à l’adversaire.\p"
	.string "En revanche, elle fait aussi\n"
	.string "baisser l’ATTAQUE SPECIALE du\p"
	.string "POKéMON qui l’utilise. Il faut\n"
	.string "éviter de l’utiliser lors des\p"
	.string "longs combats.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE ADRIANE dans le POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Ta technique me rappelle\n"
	.string "quelqu’un…\p"
	.string "Oh, je sais! Tu te bats comme\n"
	.string "NORMAN, le CHAMPION D’ARENE de\p"
	.string "CLEMENTI-VILLE.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "ARENE POKéMON de VERMILAVA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "ARENE POKéMON de VERMILAVA\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR\n"
	.string "ADRIANE: {PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "ADRIANE: Je ne vais pas me\n"
	.string "dégonfler après une défaite.\p"
	.string "J’aime les POKéMON. J’aime me\n"
	.string "battre. Et surtout… j’adore\p"
	.string "cette ARENE!\p"
	.string "Allez, que la fièvre du combat\n"
	.string "s’empare de nous!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Waouh! Un vrai volcan en\n"
	.string "éruption!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "ADRIANE: J’ai perdu, mais j’ai\n"
	.string "eu ce que je voulais.\p"
	.string "Ce combat était chaud comme la\n"
	.string "braise.\p"
	.string "J’espère qu’il y en aura encore\n"
	.string "beaucoup d’autres!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "ADRIANE: Je ne vais pas me\n"
	.string "dégonfler après une défaite.\p"
	.string "J’aime les POKéMON. J’aime me\n"
	.string "battre. Et surtout… j’adore\p"
	.string "cette ARENE!\p"
	.string "Allez, que le feu du combat\n"
	.string "s’empare de nous!\p"
	.string "Mais, attends. Tu n’as qu’un\n"
	.string "seul POKéMON qui peut se battre?\p"
	.string "Désolée, mais je ne me battrai\n"
	.string "pas tant que tu n’en auras pas\p"
	.string "au moins deux.$"
