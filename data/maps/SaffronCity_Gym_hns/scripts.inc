SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "MORGANE: Je savais que tu\n"
	.string "viendrais.\p"
	.string "J'ai eu une vision il y a trois\n"
	.string "ans.\p"
	.string "T'en veux après mon BADGE, non?\p"
	.string "Je n'aime pas combattre mais en\p"
	.string "tant que CHAMPIONNE, je me dois\n"
	.string "de\p"
	.string "confier mon BADGE à celui ou\n"
	.string "celle qui le mérite.\p"
	.string "Comme tu insistes, prépare-toi à\n"
	.string "mes pouvoirs psy!$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "MORGANE: Ta force est grande...\p"
	.string "Je ne l'avais pas prévu. Zut.\p"
	.string "Prédire le futur c'est pas si\p"
	.string "facile! Ne te moque pas trop...\p"
	.string "Bon. Tu as bien mérité le BADGE\n"
	.string "MARAIS.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} reçoit le BADGE MARAIS.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "MORGANE: Le BADGE MARAIS\n"
	.string "renforce\p"
	.string "les pouvoirs occultes...\p"
	.string "Et ça... C'est pas de la\n"
	.string "gnognotte.\p"
	.string "Tu deviendras un MAITRE! Je le\n"
	.string "sens!$"

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "Tiens, prends aussi ceci.$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "Elle contient PERMUTALENT.\p"
	.string "Cette capacité échange le talent\n"
	.string "du lanceur et celui de sa cible.\p"
	.string "Utilise-la avec sagesse...$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "MORGANE: Ton amour pour tes\n"
	.string "Pokémon a\p"
	.string "brouillé mes pouvoirs psy...\p"
	.string "L'amour... Quelle force!$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "MORGANE: Ah, le MAÎTRE de KANTO.\p"
	.string "J'ai senti ton retour.\p"
	.string "Ta puissance s'est accrue.\p"
	.string "Je sens encore ton aura.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "MORGANE: Ton amour pour tes\n"
	.string "Pokémon a encore submergé mes\l"
	.string "pouvoirs psychiques...$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "Que la force de tous ceux que tu\n"
	.string "as vaincus m’accompagne!$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Tu... Tu es trop fort!$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "Quelle est la source de ta\n"
	.string "force?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "Je vais prendre ton âme!$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "Pourquoi tant de haine?$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "Ton âme est très puissante. Et\n"
	.string "ça c'est bien.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "Gnihihihihi! Forces occultes!\p"
	.string "Ténèbres... Pâté de foie!$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "Même les lignes\n"
	.string "de la main le\p"
	.string "disent... J’ai\n"
	.string "perdu, j’ai perdu!$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "Le psychisme, c'est dur à dire.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "Le Dojo d’à côté était jadis\n"
	.string "l’Arène de cette ville.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "Inatteignable...$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "Le Roi du Karaté, maître du\n"
	.string "Dojo...\p"
	.string "Même lui s’est fait retourner\n"
	.string "comme une crêpe par Morgane.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "Hé! Graine de star!\p"
	.string "Un bon dresseur comme toi sait\p"
	.string "comment battre des Pokémon du\n"
	.string "type PSY, non?\p"
	.string "Tu vas faire un beau combat!\p"
	.string "Bonne chance!$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "Quelle belle rencontre!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
	.string "ARÈNE POKéMON DE SAFRANIA\n"
	.string "CHAMPIONNE: MORGANE\p"
	.string "DRESSEURS VAINQUEURS:\n"
	.string "BLUE, RED$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "ARÈNE POKéMON DE SAFRANIA\n"
	.string "CHAMPIONNE: MORGANE\p"
	.string "DRESSEURS VAINQUEURS:\n"
	.string "BLUE, RED, {PLAYER}$"
