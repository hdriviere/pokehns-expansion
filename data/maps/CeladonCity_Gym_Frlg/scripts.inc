CeladonCity_Gym_Frlg_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
	famechecker FAMECHECKER_ERIKA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
	famechecker FAMECHECKER_ERIKA, 4
	msgbox CeladonCity_Gym_Text_ErikaPostBattle
	release
	end

CeladonCity_Gym_EventScript_DefeatedErika::
	famechecker FAMECHECKER_ERIKA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_DEFEATED_ERIKA
	setflag FLAG_BADGE04_GET
	set_gym_trainers_frlg 4
	goto CeladonCity_Gym_EventScript_GiveTM19
	end

CeladonCity_Gym_EventScript_GiveTM19::
	msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis
	checkitemspace ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM19
	giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
	setflag FLAG_GOT_TM19_FROM_ERIKA
	msgbox CeladonCity_Gym_Text_ExplainTM19
	release
	end

CeladonCity_Gym_EventScript_NoRoomForTM19::
	msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	famechecker FAMECHECKER_ERIKA, 2
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	famechecker FAMECHECKER_ERIKA, 3
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_ErikaIntro::
	.string "Bienvenue. Il fait beau,\n"
	.string "n'est-ce pas?\p"
	.string "J'aime la vie. J'aime les fleurs\n"
	.string "et les chansons. C'est chou,\p"
	.string "non?\p"
	.string "Moi c'est ERIKA, le CHAMPION de\n"
	.string "l'ARENE de CELADOPOLE.\p"
	.string "L'arrangement floral est ma\n"
	.string "spécialité. Mes POKéMON sont du\p"
	.string "type PLANTE.\p"
	.string "Hein? Tu veux te battre? Bah…\n"
	.string "C'est sûr?\p"
	.string "Très bien. Mais tu sais quoi? Tu\n"
	.string "vas\p"
	.string "perdre!{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeladonCity_Gym_Text_ErikaDefeat::
	.string "Oh! J'ai perdu?\p"
	.string "Je dois avouer que tu sais te\n"
	.string "battre avec tes POKéMON.\p"
	.string "Bien joué. Je te confie le BADGE\n"
	.string "PRISME, c'est mérité.$"

CeladonCity_Gym_Text_ErikaPostBattle::
	.string "Tu recherches des POKéMON? Ta\n"
	.string "quête est noble.\p"
	.string "Pour ma part, je collectionne\n"
	.string "les POKéMON les plus beaux.$"

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
	.string "Le BADGE PRISME fera obéir les\n"
	.string "POKéMON jusqu'au Niveau 50.\p"
	.string "Il permet aussi aux POKéMON\n"
	.string "d'utiliser FORCE hors des\p"
	.string "combats.\p"
	.string "Prends également ceci.$"

CeladonCity_Gym_Text_ReceivedTM19FromErika::
	.string "{PLAYER} reçoit la CT19!$"

CeladonCity_Gym_Text_ExplainTM19::
	.string "CT19:  GIGA-SANGSUE.\p"
	.string "La moitié des dégâts infligés\n"
	.string "soigneront ton POKéMON!\p"
	.string "C'est une super capacité. T'es\n"
	.string "pas d'accord?$"

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
	.string "Ton inventaire est plein.$"

CeladonCity_Gym_Text_KayIntro::
	.string "Il faut que je te dise un truc\n"
	.string "sur cette ARENE.\p"
	.string "Seules les belles filles sont\n"
	.string "autorisées à entrer!$"

CeladonCity_Gym_Text_KayDefeat::
	.string "Je… J'fais pas le poids!$"

CeladonCity_Gym_Text_KayPostBattle::
	.string "Pfff! ERIKA va gagner, c'est\n"
	.string "sûr!$"

CeladonCity_Gym_Text_BridgetIntro::
	.string "J'suis belle! Hein? Hein?$"

CeladonCity_Gym_Text_BridgetDefeat::
	.string "Hein? Mes cheveux!$"

CeladonCity_Gym_Text_BridgetPostBattle::
	.string "Un POKéMON PLANTE est fort face\n"
	.string "aux POKéMON EAU!\p"
	.string "Il aura aussi l'avantage face\n"
	.string "aux types SOL et ROCHE!$"

CeladonCity_Gym_Text_TinaIntro::
	.string "On se connaît, non?$"

CeladonCity_Gym_Text_TinaDefeat::
	.string "… Tu m'as ouvert les yeux!$"

CeladonCity_Gym_Text_TinaPostBattle::
	.string "Oh, c'est ERIKA que tu\n"
	.string "cherchais… Pas moi…$"

CeladonCity_Gym_Text_TamiaIntro::
	.string "Mes jolis petits POKéMON!\p"
	.string "Les POKéMON PLANTE sont si\n"
	.string "faciles à faire évoluer…\p"
	.string "Combat!!!$"

CeladonCity_Gym_Text_TamiaDefeat::
	.string "Waouargh!$"

CeladonCity_Gym_Text_TamiaPostBattle::
	.string "Dans cette ARENE, on ne se bat\n"
	.string "qu'avec des POKéMON PLANTE.\p"
	.string "En fait, on les utilise aussi\n"
	.string "pour faire des compositions\p"
	.string "florales!$"

CeladonCity_Gym_Text_LisaIntro::
	.string "C'est interdit aux POKéMON\n"
	.string "INSECTE ou FEU ici!$"

CeladonCity_Gym_Text_LisaDefeat::
	.string "Oh! Toi!$"

CeladonCity_Gym_Text_LisaPostBattle::
	.string "Notre CHAMPION a beau être\n"
	.string "calme, elle fait beaucoup\p"
	.string "parler d'elle.$"

CeladonCity_Gym_Text_LoriIntro::
	.string "Toi… Je vais… Je vais t'écraser\n"
	.string "comme une puce.$"

CeladonCity_Gym_Text_LoriDefeat::
	.string "Qu… Qu… Hein?$"

CeladonCity_Gym_Text_LoriPostBattle::
	.string "J'ai bientôt rancard. Il va\n"
	.string "falloir que je me prépare.$"

CeladonCity_Gym_Text_MaryIntro::
	.string "Bienvenue dans l'ARENE de\n"
	.string "CELADOPOLE!\p"
	.string "Les filles sont plus fortes que\n"
	.string "les garçons. Oh que oui!$"

CeladonCity_Gym_Text_MaryDefeat::
	.string "Oh! Pourquoi?$"

CeladonCity_Gym_Text_MaryPostBattle::
	.string "Ce n'était pas ma meilleure\n"
	.string "équipe! Tu vas voir ta tête la\p"
	.string "prochaine fois!$"

CeladonCity_Gym_Text_GymStatue::
	.string "ARENE POKéMON de CELADOPOLE\n"
	.string "CHAMPION: ERIKA\p"
	.string "VAINQUEURS: {RIVAL}$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
	.string "ARENE POKéMON de CELADOPOLE\n"
	.string "CHAMPION: ERIKA\p"
	.string "VAINQUEURS: {RIVAL}, {PLAYER}$"

