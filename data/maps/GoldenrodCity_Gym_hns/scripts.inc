GoldenrodCity_Gym_hns_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE_HNS, GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET_HNS, GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA_HNS, GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA_HNS, GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1_HNS, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE DOUBLONVILLE$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE DOUBLONVILLE\p"
	.string "CHAMPIONNE: BLANCHE\p"
	.string "DRESSEURS VAINQUEURS: {PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
    .string "Salut! Moi c'est BLANCHE!\p"
    .string "Tout le monde\n"
    .string "aime les Pokémon,\p"
    .string "alors moi je fais\n"
    .string "comme les autres!\p"
    .string "Les Pokémon sont super-super\n"
    .string "mignons pas vrai?\p"
    .string "Ca te dirait de te\n"
    .string "bastonner un peu? Je\p"
    .string "préfère te prévenir,\n"
    .string "je suis très forte!$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
    .string "Sniff-sniff...\p"
    .string "...Waaaaaaah! T'es un peu nul!\p"
    .string "Tu ne devrais\n"
    .string "pas te prendre au\p"
    .string "sérieux! Tu es très\n"
    .string "jeune après tout!$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
    .string "Waouaouah!\p"
    .string "Waaaaah!\p"
    .string "Sniff et re-sniff ...T'es pas\n"
    .string "cool!$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
    .string "...sniff...\p"
    .string "Quoi? Qu'est-ce que tu veux? Un\n"
    .string "BADGE?\p"
    .string "Oh, d'accord. J'avais oublié.\n"
    .string "Prends le BADGE PLAINE.$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
    .string "{PLAYER} reçoit le BADGE PLAINE.$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
    .string "Le BADGE PLAINE permet à tes\p"
    .string "Pokémon d'utiliser FORCE hors\n"
    .string "des combats.\p"
    .string "Il accroît aussi la VITESSE de\n"
    .string "tes Pokémon.\p"
    .string "Oh, prends aussi ceci!$"

GoldenrodCity_Gym_Text_WhitneyAttract:
    .string "C'est ATTRACTION! Cela développe\n"
    .string "le\p"
    .string "charme et le pouvoir\n"
    .string "d'attraction des Pokémon.\p"
    .string "N'est-ce pas en\n"
    .string "parfaite harmonie\p"
    .string "avec mon gentil\n"
    .string "caractère?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
	.string "Ah, ça fait du bien de pleurer!$"

GoldenrodCity_Gym_Text_WhitneyRematch:
	.string "Salut! C'est toi!\p"
	.string "Waouh, tu es le Maître de JOHTO?\p"
	.string "Tu es vraiment incroyable!\p"
	.string "Je veux mesurer ta force.\p"
	.string "Tu veux m'accorder une revanche?$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "Waouaouah!\p"
    .string "Waaaaah!\p"
    .string "Sniff et re-sniff ...T'es pas\n"
    .string "cool!$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "Y sont mignons mes Pokémon!\p"
    .string "Y sont terribles itou!$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "Zut... Je croyais que tu étais\n"
    .string "faible...$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "Et moi, j'suis mimi?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
    .string "Je préfère les Pokémon mignons\n"
    .string "plutôt que les Pokémon forts.\p"
    .string "Mais j'en ai un multifonction,\n"
    .string "il est mignon et fort à la fois!$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
    .string "Oh, non, non, non!$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
    .string "J'essaie de battre BLANCHE\n"
    .string "mais... C'est déprimant.\p"
    .string "Je suis relax! Si je perds, je\p"
    .string "travaillerai dur pour la\n"
    .string "prochaine fois!$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
    .string "Ah! Blanche a fait son caprice!\p"
    .string "Elle s’arrête au\n"
    .string "bout d’un moment.\p"
    .string "Elle fait toujours\n"
    .string "ça quand elle perd.$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
    .string "Oh, tu es un sacré\n"
    .string "numéro, toi! Et mimi\p"
    .string "en plus! Je t’aime\n"
    .string "bien, mais tu ne\p"
    .string "passeras pas comme ça!$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
    .string "Voyons voir... Oups, c'est fini?$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
    .string "Whaou, tu dois être cool pour me\n"
    .string "battre comme ça! Continue!$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
    .string "Fais de ton mieux ou je t'aurai!$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
    .string "Noon! Oh, MIAOUSS, je suis\n"
    .string "désolée!$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
    .string "J’ai pourtant\n"
    .string "appris à MIAOUSS\p"
    .string "des attaques pour\n"
    .string "parer chaque type.$"

GoldenrodCity_Gym_Text_GymGuide:
	.string "Yo! Futur Maître!\p"
	.string "Cette ARENE est dirigée par\n"
	.string "BLANCHE, experte du type NORMAL.\p"
	.string "Gare à son équipe adorable.\p"
	.string "Certains Pokémon de cette ARENE\n"
	.string "ont aussi le type FEE, découvert\p"
	.string "récemment.\p"
	.string "Explore la ROUTE 34 s'il te faut\n"
	.string "un type COMBAT ou POISON.$"

GoldenrodCity_Gym_Text_GymGuideWin:
    .string "T'as gagné?\n"
    .string "Super! J'étais\p"
    .string "occupé à mater\n"
    .string "ces jolies filles.$"
