GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "Buena: Hein? Tu veux connaître\n"
	.string "le mot de passe d’aujourd’hui?\p"
	.string "Facile: c’est “AU SECOURS”!$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "Ecoutez la radio n'importe où! A\n"
	.string "bientôt!$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "Accès interdit au-delà de ce\n"
	.string "point.$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "Les berceuses de la radio\n"
	.string "peuvent endormir les Pokémon.$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "Qu’est-ce qu’ils comptent faire\n"
	.string "en envahissant la Tour Radio?$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "RONDOUDOU: Douuu...$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "Seul le personnel autorisé peut\n"
	.string "aller plus haut...\p"
	.string "Cette mesure vient\n"
	.string "d’être promulguée.\p"
	.string "Le directeur est\n"
	.string "bizarre, ces temps-ci.$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "Vous pouvez aller\n"
	.string "où vous voulez.\p"
	.string "Le directeur est\n"
	.string "redevenu gentil!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "Il y a trois ans, la Team Rocket\n"
	.string "a été obligée de se dissoudre.\p"
	.string "Mais nous revenons aujourd’hui\n"
	.string "en force!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "Gueuh! T'es pas cool, toi!$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "On te laissera pas nous empêcher\n"
	.string "de nous reformer!$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "On est la TEAM ROCKET, on est\n"
	.string "les exploiteurs de Pokémon!\p"
	.string "On est des pas\n"
	.string "beaux méchants qui\p"
	.string "font peur! Grrr.\n"
	.string "T'as peur, là?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "Tu veux défendre la justice?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "On n’est pas des\n"
	.string "super méchants...\p"
	.string "On fait juste\n"
	.string "c’qu’on veut!$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "Hé! Te mets pas en travers de\n"
	.string "notre route!$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "Pfff. J'abandonne.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "Nos CAIDS sont en train de\n"
	.string "contrôler cet endroit.\p"
	.string "Ils ont un super plan en tête.\n"
	.string "Je me demande ce que c'est...$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "Hahaha!\p"
	.string "Très ennuyeux. C'était trop\n"
	.string "facile d'envahir cet endroit!\p"
	.string "Allez les petits! Faites-moi\n"
	.string "encore rire!$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "Qu-qu-qui t’es toi?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "Quelqu’un de plus fort que moi?\p"
	.string "C’est impardonnable!$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "BUENA: Ecoutez tous l'émission\n"
	.string "LE MOT DE PASSE!\p"
	.string "Ecoutez pour connaître le mot de\n"
	.string "passe du jour!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
	.string "BUENA: Bonjour!\p"
	.string "Tu connais le mot de passe du\n"
	.string "jour?\p"
	.string "OK! Lequel est-ce?$"

GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
	.string "BUENA: C'est exact!\p"
	.string "Tiens, prends {STR_VAR_1}\n"
	.string "comme prix!$"

GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
	.string "BUENA: Bzzt! Dommage!\p"
	.string "Réessaie demain!$"

GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
	.string "BUENA: Aucune idée?\n"
	.string "Reviens quand tu seras prêt!$"

GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
	.string "BUENA: Tu as déjà deviné le mot\n"
	.string "de passe aujourd'hui!\p"
	.string "Réécoute l'émission demain!$"

GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
	.string "BUENA: Bonne réponse, mais ton\n"
	.string "SAC est plein!\p"
	.string "Fais de la place et reviens me\n"
	.string "parler!$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "1{SUPER_ER}: Ventes$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "CHRONIQUE Pokémon DU PROF.CHEN\p"
	.string "L'émission star à l'antenne!$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "Pour chacune Pour\n"
	.string "chacun Le soir\p"
	.string "Comme le matin RADIO\n"
	.string "Pokémon C'est bien...$"
