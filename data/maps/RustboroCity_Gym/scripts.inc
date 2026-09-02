RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Hé, ça va?\p"
	.string "Ecoute! Tu veux devenir le\n"
	.string "MAITRE?\p"
	.string "Je n’suis pas DRESSEUR moi, mais\n"
	.string "je peux te donner des conseils\p"
	.string "pour gagner.\p"
	.string "Marché conclu! Nous viserons\n"
	.string "donc le titre de MAITRE POKéMON!\p"
	.string "Ton devoir en tant que DRESSEUR\n"
	.string "est de rassembler des BADGES,\p"
	.string "c’est ça?\p"
	.string "Il s’agit d’une tâche difficile\n"
	.string "car les CHAMPIONS sont très\p"
	.string "forts.\p"
	.string "Alors c’est là que j’interviens!\n"
	.string "Je suis là pour te donner de\p"
	.string "bons conseils!\p"
	.string "ROXANNE, CHAMPION D’ARENE de\n"
	.string "cette ville, utilise des POKéMON\p"
	.string "du type ROCHE.\p"
	.string "Le type ROCHE se caractérise par\n"
	.string "sa résistance, mais il supporte\p"
	.string "mal les capacités des types EAU\n"
	.string "et PLANTE.\p"
	.string "Reviens me voir si tu arrives à\n"
	.string "battre le CHAMPION D’ARENE.\p"
	.string "Allez, vas-y!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Waouh! Quelle victoire\n"
	.string "époustouflante! Mes\p"
	.string "encouragements ont servi!\p"
	.string "Génial! Vérifie ta CARTE\n"
	.string "DRESSEUR.\p"
	.string "Le BADGE ROCHE, que tu as\n"
	.string "obtenu, doit y être enregistré\p"
	.string "correctement.\p"
	.string "Autrement dit…\p"
	.string "Tu as fait le premier pas vers\n"
	.string "le titre de MAITRE POKéMON!\p"
	.string "Tu peux en tirer de la\n"
	.string "satisfaction!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Ne prends pas les DRESSEURS\n"
	.string "D’ARENE à la légère! Tu vas voir\p"
	.string "pourquoi on est meilleurs!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Tu as trop de force pour moi…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Tu n’as encore rien vu de\n"
	.string "l’étonnante puissance du type\p"
	.string "ROCHE!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Si tu ne réussis pas à me\n"
	.string "battre, tu n’auras aucune chance\p"
	.string "face à ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Waouh! Tu as un certain\n"
	.string "potentiel!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE est plus forte que moi à\n"
	.string "plusieurs égards.\p"
	.string "Tu ferais bien de te méfier!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Je sais qu’on est au milieu de\n"
	.string "la ville. Et alors?\p"
	.string "Mes POKéMON ROCHE ont besoin de\n"
	.string "place pour s’exprimer!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh non, non! Tu sais te battre\n"
	.string "toi!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Je dois laisser la main à notre\n"
	.string "CHAMPION.\p"
	.string "Malgré son jeune âge, elle a su\n"
	.string "choisir intelligemment les\p"
	.string "POKéMON ROCHE.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Salut! Je suis ROXANNE, CHAMPION\n"
	.string "de l’ARENE POKéMON de\p"
	.string "MEROUVILLE.\p"
	.string "Je suis devenue CHAMPION pour\n"
	.string "appliquer dans les combats ce\p"
	.string "que j’ai appris à l’ECOLE DE\n"
	.string "DRESSEURS.\p"
	.string "Tu voudrais bien me montrer\n"
	.string "comment tu te bats, et avec\p"
	.string "quels POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Bon… J’ai perdu…\p"
	.string "Apparemment, j’ai encore bien\n"
	.string "des choses à apprendre…\p"
	.string "Je comprends.\p"
	.string "Les règles de la LIGUE POKéMON\n"
	.string "stipulent que le CHAMPION doit\p"
	.string "re- mettre ceci au DRESSEUR qui\n"
	.string "l’a battu.\p"
	.string "Alors accepte ce BADGE ROCHE\n"
	.string "officiel de la LIGUE POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} reçoit le BADGE ROCHE\n"
	.string "de la part de ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Le BADGE ROCHE augmente la\n"
	.string "puissance d’ATTAQUE de tes\p"
	.string "POKéMON.\p"
	.string "Il leur permet d’utiliser\n"
	.string "l’attaque  de la CS COUPE en\p"
	.string "dehors des combats.\p"
	.string "Accepte également ça!$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Cette CT39 contient TOMBEROCHE.\p"
	.string "La chute de pierres inflige des\n"
	.string "dommages et la VITESSE diminue.\p"
	.string "Si tu utilises une CT, l’attaque\n"
	.string "est immédiatement enseignée à un\p"
	.string "POKéMON.\p"
	.string "Sache qu’une CT ne s’utilise\n"
	.string "qu’une fois. Réfléchis bien\p"
	.string "avant de t’en servir!$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Puisque tu as tant de force, tu\n"
	.string "ferais bien de combattre\p"
	.string "d’autres CHAMPIONS.\p"
	.string "En affrontant plein de\n"
	.string "DRESSEURS, tu devrais apprendre\p"
	.string "beaucoup de choses.$"

RustboroCity_Gym_Text_GymStatue:
	.string "ARENE POKéMON de MEROUVILLE$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "ARENE POKéMON de MEROUVILLE\p"
	.string "NOUVEAU DRESSEUR RECONNU PAR\n"
	.string "ROXANNE: {PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … … … … … … … Bip!\p"
	.string "ROXANNE: C’est bien {PLAYER}?\n"
	.string "Ici ROXANNE de MEROUVILLE.\p"
	.string "J’ai appris de BASTIEN que tu\n"
	.string "progresses très rapidement en\p"
	.string "tant que DRESSEUR.\p"
	.string "Bon, je ferais mieux d’oublier\n"
	.string "que tu m’as battue.\p"
	.string "Mais je te promets d’améliorer\n"
	.string "mon ARENE pour que tu puisses\p"
	.string "nous affronter de nouveau.\p"
	.string "J’espère t’y revoir très\n"
	.string "bientôt!\p"
	.string "… … … … … … … … … … … Clic!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Vous avez enregistré le CHAMPION\n"
	.string "D’ARENE ROXANNE dans le POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Je suis ravie de te\n"
	.string "revoir!\p"
	.string "Je suis sûre que nous avons\n"
	.string "énormément progressé depuis\p"
	.string "notre dernière rencontre.\p"
	.string "Voyons voir à quel point!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr… Encore perdu…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: J’ai encore beaucoup à\n"
	.string "apprendre au sujet des POKéMON.\p"
	.string "Cette prise de conscience ne\n"
	.string "fait qu’attiser mon amour pour\p"
	.string "les combats!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Je suis ravie de te\n"
	.string "revoir!\p"
	.string "Je suis sûre que nous avons\n"
	.string "énormément progressé depuis\p"
	.string "notre dernière rencontre.\p"
	.string "Voyons voir à quel point!\p"
	.string "Oh, mais… Tu n’as qu’un POKéMON\n"
	.string "avec toi?\p"
	.string "Reviens me voir avec au moins\n"
	.string "deux POKéMON, s’il te plaît.$"
