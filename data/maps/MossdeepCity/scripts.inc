MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "C’est PIERRE qui m’a donné ça,\n"
	.string "mais je ne sais pas à quoi ça\p"
	.string "sert au juste.\p"
	.string "Je crois qu’on appelle ça la\n"
	.string "ROCHE ROYALE. Tu la veux?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Pourquoi en voudrais-tu? C’est\n"
	.string "bizarre.\p"
	.string "Tu peux la garder, mais il ne\n"
	.string "faut pas que PIERRE le sache.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "La maison de PIERRE est juste\n"
	.string "là!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Hé, tu trouves aussi! Qu’est-ce\n"
	.string "qu’on peut bien pouvoir faire\p"
	.string "avec de drôles de pierres?$"

MossdeepCity_Text_WailmerWatching:
	.string "Aux alentours d’ALGATIA, tu peux\n"
	.string "voir des WAILMER sauvages.\p"
	.string "Ça s’appelle, euh… Comment c’est\n"
	.string "déjà…\p"
	.string "Attends, attends, attends…\p"
	.string "L’observation de WAILMER!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Ce CENTRE SPATIAL insulaire a\n"
	.string "lancé de très grosses fusées.\p"
	.string "Mais ils sont très inquiets\n"
	.string "depuis qu’ils ont reçu une\p"
	.string "certaine lettre.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Ce CENTRE SPATIAL insulaire a\n"
	.string "lancé de très grosses fusées.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "J’ai appris d’un ami MARIN que\n"
	.string "la TEAM AQUA s’est installée à\p"
	.string "NENUCRIQUE.\p"
	.string "J’ai aussi appris que quelqu’un\n"
	.string "s’est mêlé de leurs affaires!\p"
	.string "Mais ALGATIA est déjà la cible\n"
	.string "de la TEAM MAGMA.\p"
	.string "Si tu veux savoir ce qu’ils\n"
	.string "manigancent, tu devrais aller au\p"
	.string "CENTRE SPATIAL.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Je suis MARIN, la mer est donc\n"
	.string "très importante pour moi.\p"
	.string "Mais tu sais, après un long\n"
	.string "voyage en mer, je me sens\p"
	.string "soulagé de poser le pied à\n"
	.string "terre.$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Ça ne serait pas charmant?\p"
	.string "Si le monde entier était\n"
	.string "recouvert de plantes et de\p"
	.string "fleurs comme cette île?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Toute forme de vie, même\n"
	.string "terrestre, a besoin de la mer\p"
	.string "pour vivre.\p"
	.string "La vie, une fois consumée, n’est\n"
	.string "plus que poussière qui retourne\p"
	.string "à la terre.\p"
	.string "Et la mer est toujours reliée à\n"
	.string "la terre.\p"
	.string "Oui, comme le rivage ici.$"

MossdeepCity_Text_SurfExhilarating:
	.string "C’est sympa de voyager sur un\n"
	.string "bateau.\p"
	.string "Mais traverser la mer avec un\n"
	.string "POKéMON qui utilise SURF…\p"
	.string "Là, c’est un voyage grisant!\n"
	.string "T’es pas d’accord, mon p’tit?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Cette pierre a un sens\n"
	.string "particulier pour les gens du\p"
	.string "CENTRE SPATIAL.\p"
	.string "Ils l’ont posée là et fait le\n"
	.string "vœu que leurs fusées volent en\p"
	.string "toute sécurité.\p"
	.string "Tu fais comment, toi, pour faire\n"
	.string "un vœu? T’attends de voir une\p"
	.string "étoile filante?\p"
	.string "Moi, je jette une pièce dans une\n"
	.string "fontaine pour que mon vœu se\p"
	.string "réalise.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "C’est une pierre blanche.$"

MossdeepCity_Text_GymSign:
	.string "ARENE POKéMON d’ALGATIA\n"
	.string "CHAMPIONS: TATIA et LEVY\p"
	.string "“La combinaison mystique!”$"

MossdeepCity_Text_CitySign:
	.string "ALGATIA “Notre slogan: chérir\n"
	.string "les POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "CENTRE SPATIAL D’ALGATIA\n"
	.string "“L’endroit le plus proche de\p"
	.string "l’espace.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: Comment ça va,\n"
	.string "{PLAYER}{KUN}? Pour moi ça roule\p"
	.string "en tout cas!\p"
	.string "J’ai entendu dire que le\n"
	.string "CHAMPION D’ARENE d’ALGATIA est\p"
	.string "assez fort, alors je viens voir\n"
	.string "ça de mes propres yeux.\p"
	.string "Mais il y a quelque chose\n"
	.string "d’étrange qui se passe ici.\p"
	.string "Les gens parlent d’une lettre et\n"
	.string "du CENTRE SPATIAL…\p"
	.string "Mais tout ça ne me concerne pas\n"
	.string "de toute façon.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahhh… C’est tellement bon de\n"
	.string "laisser les embruns caresser mon\p"
	.string "visage…\p"
	.string "En parlant de la mer, tu connais\n"
	.string "cette ville insulaire,\p"
	.string "ATALANOPOLIS?\p"
	.string "Je crois qu’ils ont un nouveau\n"
	.string "CHAMPION dans leur ARENE.\p"
	.string "Il paraît que ce nouveau\n"
	.string "CHAMPION était le mentor de\p"
	.string "MARC.$"

