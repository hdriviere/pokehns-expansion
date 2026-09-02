BlackthornCity_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY_HNS, BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN_HNS, BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL_HNS, BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_HNS, BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_HNS, BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1_HNS, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers_hns
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
    .string "Je suis SANDRA.\p"
    .string "Je suis la reine des dragons.\p"
    .string "Je peux même tenir tête au\n"
    .string "CONSEIL des 4 de la LIGUE.\p"
    .string "Tu veux toujours te battre?\p"
    .string "...Bon. C'est parti!\p"
    .string "Je vais pas y aller mollo!$"

BlackthornGym_Text_ClairWinText:
    .string "Perdu?\p"
    .string "J'y crois pas!! Il y a sûrement\n"
    .string "une erreur...$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
    .string "Ce n'est pas possible.\p"
    .string "J'ai peut-être perdu mais tu\n"
    .string "n'as\p"
    .string "pas les épaules pour la LIGUE\n"
    .string "Pokémon.\p"
    .string "Tu devrais relever le défi des\n"
    .string "utilisateurs de dragons.\p"
    .string "Derrière cette ARENE se trouve\n"
    .string "l'ANTRE du DRAGON.\p"
    .string "Il y a un petit temple au\n"
    .string "centre. Vas-y.\p"
    .string "Si tu arrives à prouver ta\n"
    .string "valeur,\p"
    .string "tu seras digne de porter le\n"
    .string "BADGE!$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
    .string "Et alors?\p"
    .string "On a peur maintenant?$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
    .string "Tu en as mis du temps!\p"
    .string "Tiens! Prends ça!$"

BlackthornGym_Text_ClairText_DescribeTM:
	.string "Elle contient DRACOGRIFFE.\p"
	.string "Tu comprendras bien son effet.$"

BlackthornGym_Text_ClairText_League:
    .string "Et ben alors?\p"
    .string "Tu ne vas pas à la LIGUE\n"
    .string "Pokémon?\p"
    .string "Tu sais où c'est, n'est-ce pas?\p"
    .string "Va d'abord au BOURG GEON.\p"
    .string "SURFE ensuite vers l'est. Le\n"
    .string "chemin sera rude.\p"
    .string "Ne perds pas à la LIGUE Pokémon!\p"
    .string "Si tu perds, de quoi j'aurai\n"
    .string "l'air, moi?\p"
    .string "Fais de ton mieux.$"

BlackthornGym_Text_ClairAfterLeague:
	.string "Tu as réussi, hein?\p"
	.string "Tu es désormais\n"
	.string "le Maître de JOHTO.$"

BlackthornGym_Text_ClairRematchText:
	.string "Tu as réussi, hein?\p"
	.string "Tu es désormais\n"
	.string "le Maître de JOHTO.\p"
	.string "Tu as prouvé ta force,\n"
	.string "mais peux-tu\l"
	.string "encore me vaincre?\p"
	.string "En tant que Maître Dragon,\n"
	.string "je ne me retiendrai pas.\p"
	.string "Pas cette fois.\p"
	.string "Veux-tu prendre ta revanche?$"

BlackthornGym_Text_ClairRematchDefeatText:
	.string "J'ai perdu?\p"
	.string "Encore?\p"
	.string "Je n'y crois pas.\n"
	.string "Il doit y avoir\l"
	.string "une erreur...$"

BlackthornGym_Text_CooltrainermCodySeenText:
	.string "Je viens d'obtenir le droit\n"
	.string "d'utiliser des Pokémon Dragon!$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
    .string "Zut! Il me faut un dragon!$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
    .string "Les membres de la confrérie des\p"
    .string "dragons ne peuvent utiliser des\n"
    .string "Pokémon dragon que si\p"
    .string "le MAITRE le permet.$"

BlackthornGym_Text_CooltrainerfFranSeenText:
    .string "Un dresseur quelconque ne\n"
    .string "passera pas!\p"
    .string "SANDRA ne le permettrait pas!$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
    .string "Pffff. Perdu...$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
    .string "Oulà! La SANDRA elle sera furax!$"

BlackthornGym_Text_CooltrainermPaulSeenText:
    .string "Tu vas voir ce\n"
    .string "qu’il en coûte de\p"
    .string "se frotter à un\n"
    .string "Dracologue débutant!$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
    .string "Mes Pokémon dragon ont perdu?$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
    .string "PETER voulait te revoir?\n"
    .string "Mensonge!$"

BlackthornGym_Text_CooltrainermMikeSeenText:
    .string "Mes chances de perdre? Même pas\n"
    .string "une sur mille!$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
    .string "Je ne suis plus très bon en\n"
    .string "maths.$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
    .string "Je connais mes défauts...\p"
    .string "On recommence? Non? Bon et bien\n"
    .string "merci pour la leçon...$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
    .string "Le type Dragon regroupe des\n"
    .string "Pokémon sacrés, pleins de vie.\p"
    .string "Tu ne pourras pas les battre si\n"
    .string "tu ne te donnes pas à fond.$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
    .string "Bien joué!$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
    .string "Les dragons sont faibles face\n"
    .string "aux attaques de type DRAGON.$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_GymGuy3
	msgbox BlackthornGym_Text_GuideGotoDragonsDen, MSGBOX_DEFAULT
	release
	end

BlackthornGym_EventScript_GymGuy3::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
	.string "Yo, futur Maître!\p"
	.string "Le voyage fut long, mais nous\n"
	.string "touchons presque au but!\p"
	.string "Tu peux compter sur moi!\p"
	.string "SANDRA admire PETER, le Maître\n"
	.string "Dragon, mais elle a forgé sa\l"
	.string "propre identité.\p"
	.string "Son équipe est composée\n"
	.string "de dragons venus de la mer.\p"
	.string "Les dragons sont censés craindre\n"
	.string "les capacités de type GLACE.\p"
	.string "Mais il te faudra aussi des\n"
	.string "capacités DRAGON ou FÉE\l"
	.string "pour gagner.\p"
	.string "Tu peux le faire!$"

BlackthornGym_Text_GuideGotoDragonsDen:
	.string "Tu as été formidable\n"
	.string "contre SANDRA!\p"
	.string "Elle supporte parfois mal\n"
	.string "la défaite.\p"
	.string "Tu dois apparemment aller dans\n"
	.string "l'ANTRE DU DRAGON pour obtenir\l"
	.string "ce BADGE!$"

BlackthornGym_Text_GuideWinText:
    .string "Bien joué! Beau combat!\p"
    .string "Il ne reste plus que le\n"
    .string "challenge de la LIGUE Pokémon.\p"
    .string "Tu es sur le point de devenir\n"
    .string "MAITRE Pokémon!$"


BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_BADGE08_GET, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "Arène d’Ebènelle$"

BlackthornGym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON D'ÉBÈNELLE\p"
	.string "CHAMPIONNE: SANDRA\p"
	.string "DRESSEURS VAINQUEURS: {PLAYER}$"
