RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Ce tableau liste les changements\n"
	.string "de statut pouvant toucher les\p"
	.string "POKéMON au combat.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Lire quel sujet?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON est empoisonné,\n"
	.string "ses PV diminuent régulièrement.\p"
	.string "Les effets du poison perdurent\n"
	.string "après un combat.\p"
	.string "Les PV d’un POKéMON empoisonné\n"
	.string "continuent à diminuer hors\p"
	.string "combat.\p"
	.string "L’ANTIDOTE remédie à\n"
	.string "l’empoisonnement.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON est paralysé, sa\n"
	.string "VITESSE diminue.\p"
	.string "Il peut aussi être dans\n"
	.string "l’incapacité de se déplacer\p"
	.string "pendant le combat.\p"
	.string "La paralysie persiste après le\n"
	.string "combat. L’ANTI-PARA permet d’y\p"
	.string "remédier.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON s’endort, il est\n"
	.string "dans l’incapacité d’attaquer.\p"
	.string "Le POKéMON peut se réveiller de\n"
	.string "lui-même, mais s’il est endormi\p"
	.string "à la fin du combat, il le\n"
	.string "restera ensuite.\p"
	.string "Le REVEIL le sortira de son\n"
	.string "sommeil.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Une brûlure réduit la puissance\n"
	.string "d’ATTAQUE et les PV de la\p"
	.string "victime.\p"
	.string "Une brûlure persiste après le\n"
	.string "combat. L’ANTI-BRULE permet d’y\p"
	.string "remédier.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Si un POKéMON est gelé, il n’est\n"
	.string "plus d’aucune aide.\p"
	.string "Il restera gelé après le combat.\n"
	.string "L’ANTIGEL permet de le dégeler.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Les élèves qui ne travaillent\n"
	.string "pas n’ont qu’un petit\p"
	.string "échantillon de ma VIVE GRIFFE.\p"
	.string "La manière dont tu utiliseras\n"
	.string "cet objet indiquera de façon\p"
	.string "évidente si tu apprends bien ou\n"
	.string "pas.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON qui porte VIVE GRIFFE\n"
	.string "pourra parfois augmenter sa\p"
	.string "vitesse et attaquer avant son\n"
	.string "adversaire.\p"
	.string "D’autres objets comme celui-ci\n"
	.string "sont faits pour être portés par\p"
	.string "un POKéMON.\p"
	.string "Mais celui-ci te donnera déjà\n"
	.string "matière à réfléchir!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Je vais dès maintenant faire un\n"
	.string "échange de POKéMON avec mon ami.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "J’ai toujours voulu un\n"
	.string "GRAINIPIOT et j’ai enfin réussi\p"
	.string "à en avoir un!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Les POKéMON peuvent porter des\n"
	.string "objets, mais ne savent pas\p"
	.string "utiliser les objets conçus par\n"
	.string "les hommes, tels que la POTION\p"
	.string "ou l’ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Tu sais combien certaines\n"
	.string "capacités peuvent troubler un\p"
	.string "POKéMON?\p"
	.string "Un POKéMON confus peut parfois\n"
	.string "se blesser sans le vouloir.\p"
	.string "Mais après le combat, il\n"
	.string "retrouve ses esprits.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON qui porte une BAIE se\n"
	.string "soignera lui-même…\p"
	.string "Il existe de nombreuses sortes\n"
	.string "d’objets qu’un POKéMON peut\p"
	.string "porter…\p"
	.string "C’est sûr, c’est pas facile\n"
	.string "d’arriver à tout noter…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "C’est le carnet de cet étudiant…\p"
	.string "On attrape les POKéMON avec des\n"
	.string "POKé BALLS.\p"
	.string "Jusqu’à six POKéMON peuvent\n"
	.string "accompagner un DRESSEUR.\p"
	.string "Un DRESSEUR est une personne qui\n"
	.string "attrape des POKéMON, les fait\p"
	.string "progresser et se bat avec eux.\p"
	.string "L’objectif du DRESSEUR est de\n"
	.string "battre les puissants CHAMPIONS\p"
	.string "qui attendent les adversaires\n"
	.string "dans les ARENES POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Salut! On s’est déjà vus, non?\n"
	.string "Je crois que c’était à\p"
	.string "CLEMENTI-VILLE.\p"
	.string "Je me présente. Je m’appelle\n"
	.string "SCOTT.\p"
	.string "Je voyage un peu partout à la\n"
	.string "recherche de DRESSEURS de\p"
	.string "talent.\p"
	.string "Plus précisément, je recherche\n"
	.string "des experts en combats de\p"
	.string "POKéMON.\p"
	.string "Alors dis-moi, qu’est-ce qui\n"
	.string "t’amène dans cette ECOLE? Es-tu\p"
	.string "aussi un DRESSEUR?\p"
	.string "La première chose que tu devrais\n"
	.string "faire est d’enseigner la\p"
	.string "capacité COUPE à un de tes\n"
	.string "POKéMON.\p"
	.string "Si je me souviens bien,\n"
	.string "quelqu’un dans cette ville\p"
	.string "possède COUPE.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm…\p"
	.string "Je ne connais pas le niveau de\n"
	.string "ces étudiants, mais il y a du\p"
	.string "potentiel.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Oh, qu’est-ce que c’est?\p"
	.string "C’est le BADGE ROCHE, n’est-ce\n"
	.string "pas? Je dois dire que je suis\p"
	.string "impressionné.\p"
	.string "Tu sais, j’aurais beaucoup aimé\n"
	.string "te voir en plein combat.\p"
	.string "Il est difficile d’imaginer quel\n"
	.string "genre de DRESSEUR tu es, à\p"
	.string "partir d’un BADGE de la LIGUE.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Salut! On s’est déjà vus, non?\n"
	.string "Je crois que c’était à\p"
	.string "CLEMENTI-VILLE.\p"
	.string "Je me présente. Je m’appelle\n"
	.string "SCOTT.\p"
	.string "Je voyage un peu partout à la\n"
	.string "recherche de DRESSEURS de\p"
	.string "talent.\p"
	.string "Plus précisément, je recherche\n"
	.string "des experts en combats de\p"
	.string "POKéMON.\p"
	.string "Oh, qu’est-ce que c’est?\p"
	.string "C’est le BADGE ROCHE, n’est-ce\n"
	.string "pas? Je dois dire que je suis\p"
	.string "impressionné.\p"
	.string "Tu sais, j’aurais beaucoup aimé\n"
	.string "te voir en plein combat.\p"
	.string "Il est difficile d’imaginer quel\n"
	.string "genre de DRESSEUR tu es, à\p"
	.string "partir d’un BADGE de la LIGUE.$"

