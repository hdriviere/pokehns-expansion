BattleFrontier_Lounge7_MapScripts::
	.byte 0

@special ChooseMonForMoveTutor
BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end


BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Oh, oh!\p"
	.string "Tu auras du mal à le croire,\n"
	.string "mais dans le temps, j’étais un\p"
	.string "DRESSEUR hors pair.\p"
	.string "On disait que j’étais le CANON\n"
	.string "le plus doué du coin!\p"
	.string "… … … … … …\p"
	.string "Comment? Je sais, c’est dur à\n"
	.string "croire.\p"
	.string "Je ne suis pas comme cette\n"
	.string "vantarde en face. Moi, j’ai\p"
	.string "vraiment du talent!\p"
	.string "Je vais te le prouver. Je peux\n"
	.string "enseigner à tes POKéMON des\p"
	.string "capacités particulières mais\n"
	.string "mignonnes.\p"
	.string "Bien sûr, ce ne sera pas\n"
	.string "gratuit. Si tu payais ces\p"
	.string "capacités avec des POINTS DE\n"
	.string "COMBAT?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Oh, oh!\p"
	.string "Tu veux des capacités\n"
	.string "particulières mais mignonnes\p"
	.string "pour tes POKéMON?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Bien! Quelle capacité veux-tu?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "{STR_VAR_1}, n’est-ce pas?\n"
	.string "{STR_VAR_2} POINTS DE COMBAT,\p"
	.string "d’accord?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Maintenant, choisis le POKéMON à\n"
	.string "qui je dois enseigner cette\p"
	.string "capacité.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Mais enfin… Tu n’as pas assez de\n"
	.string "POINTS DE COMBAT!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Je suis douée, non? Je prends\n"
	.string "tes POINTS DE COMBAT, merci!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Oh? Tu as changé d’avis…\p"
	.string "Si tu veux que je te montre à\n"
	.string "quel point je suis douée,\p"
	.string "reviens me voir!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Hi, hi, hi!\p"
	.string "C’est difficile à imaginer, à\n"
	.string "présent, mais j’ai été un\p"
	.string "DRESSEUR fantastique.\p"
	.string "On disait que j’étais la plus\n"
	.string "forte des NAGEUSE, rien que ça!\p"
	.string "… … … … … …\p"
	.string "Comment? Tu ne me crois pas,\n"
	.string "évidemment.\p"
	.string "Je ne suis pas comme cette\n"
	.string "menteuse en face. J’ai vraiment\p"
	.string "du talent!\p"
	.string "Je peux te le prouver. Je peux\n"
	.string "enseigner des capacités\p"
	.string "difficiles mais belles à tes\n"
	.string "POKéMON.\p"
	.string "Bien sûr, ce ne sera pas\n"
	.string "gratuit. Si tu payais ces\p"
	.string "capacités avec des POINTS DE\n"
	.string "COMBAT?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Hi, hi, hi!\p"
	.string "Tu veux que j’enseigne des\n"
	.string "capacités difficiles mais belles\p"
	.string "à tes POKéMON?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Ces deux vieilles dames\n"
	.string "n’arrêtent pas de se critiquer,\p"
	.string "comme si elles se détestaient.\p"
	.string "Mais si c’était vrai, elles ne\n"
	.string "seraient pas toujours ensemble\p"
	.string "ici, non?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quand j’étais encore un GAMIN,\n"
	.string "ces deux femmes étaient fortes\p"
	.string "et magnifiques.\p"
	.string "Elles faisaient des ravages\n"
	.string "parmi les DRESSEURS.\p"
	.string "Mais malgré leur âge, elles sont\n"
	.string "toujours très fortes.\p"
	.string "On peut même dire qu’elles ont\n"
	.string "fait mûrir leurs capacités\p"
	.string "POKéMON.\p"
	.string "Tout de même… Je ne peux pas\n"
	.string "m’empêcher de penser…\p"
	.string "Vieillir, c’est bien cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Regagne jusqu’à la moitié des PV\n"
	.string "max du lanceur.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflige des dégâts selon le\n"
	.string "niveau du lanceur.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Aspire la moitié des dégâts sur\n"
	.string "l’ennemi endormi.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un coup de poing d’une puissance\n"
	.string "incroyable.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Un coup de pied super puissant\n"
	.string "et intense.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Une attaque en charge. Peut pa-\n"
	.string "ralyser l’ennemi.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "Envoie de gros rochers. Peut\n"
	.string "apeurer l’ennemi.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Renvoie toute attaque physique,\n"
	.string "2 fois plus fort.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Un faible choc électrique qui\n"
	.string "paralyse l’ennemi.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Une danse de combat pour booster\n"
	.string "l’ATTAQUE.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "S’enroule, cache les faiblesses.\n"
	.string "Monte la DEFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Attaque sonore qui ne peut être\n"
	.string "lancée qu’endormi.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Envoie de la boue au visage et\n"
	.string "rend moins précis.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Envoie des rayons en forme\n"
	.string "d’étoile. Touche toujours.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Attaque glaciale. Baisse la\n"
	.string "VITESSE de l’ennemi.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Encaisse les attaques du tour et\n"
	.string "conserve 1 PV.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copie les effets de l’ennemi et\n"
	.string "les passe au lanceur.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Un poing de glace pouvant geler\n"
	.string "l’ennemi.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Un poing électri- que pouvant\n"
	.string "para- lyser l’ennemi.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Un poing de feu pouvant brûler\n"
	.string "l’ennemi.$"
