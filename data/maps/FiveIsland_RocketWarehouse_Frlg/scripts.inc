.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

FiveIsland_RocketWarehouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_RocketWarehouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_RocketWarehouse_OnTransition
	.byte 0

FiveIsland_RocketWarehouse_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
	end

FiveIsland_RocketWarehouse_OnLoad::
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	end

FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry::
	setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
	setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
	return

FiveIsland_RocketWarehouse_EventScript_Cage::
	lockall
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FiveIsland_RocketWarehouse_EventScript_CageUnlocked
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_CageUnlocked::
	msgbox FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Computer::
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end

FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
	lockall
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Gideon::
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, FiveIsland_RocketWarehouse_EventScript_DefeatedGideon
	goto_if_set FLAG_IS_CHAMPION, FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid::
	famechecker FAMECHECKER_GIOVANNI, 5
	msgbox FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedGideon::
	msgbox FiveIsland_RocketWarehouse_Text_GideonPostBattle
	setflag FLAG_RECOVERED_SAPPHIRE
	giveitem ITEM_SAPPHIRE
	release
	end

FiveIsland_RocketWarehouse_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin2::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WAREHOUSE_GRUNT2
	removeobject LOCALID_WAREHOUSE_GRUNT3
	removeobject LOCALID_WAREHOUSE_ADMIN2
	removeobject LOCALID_WAREHOUSE_ADMIN1
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin1::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_Admin1PostBattle
	closemessage
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	playse SE_PIN
	call FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	special DrawWholeMapView
	waitse
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1::
	goto_if_eq PLAYER_X_POS, 27, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar::
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch::
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen::
	.string "Il y a beaucoup de POKéMON\n"
	.string "enfermés dans leur cachot…$"

FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled::
	.string "La porte du cachot est ouverte.\n"
	.string "Les POKéMON se sont enfuis.$"

FiveIsland_RocketWarehouse_Text_Grunt2Intro::
	.string "Tu savais que c'était l'ENTREPOT\n"
	.string "ROCKET en venant ici?$"

FiveIsland_RocketWarehouse_Text_Grunt2Defeat::
	.string "Qu'est-ce que tu crois faire?$"

FiveIsland_RocketWarehouse_Text_Grunt2PostBattle::
	.string "La TEAM ROCKET? Perdre? De\n"
	.string "quelle planète tu viens?$"

FiveIsland_RocketWarehouse_Text_Grunt1Intro::
	.string "Oh, tes POKéMON sont balèzes. Tu\n"
	.string "voudrais pas les vendre?\p"
	.string "Oh? Tu veux te battre?$"

FiveIsland_RocketWarehouse_Text_Grunt1Defeat::
	.string "Oh, mais… C'est trop!$"

FiveIsland_RocketWarehouse_Text_Grunt1PostBattle::
	.string "On peut te faire un super prix\n"
	.string "si tu nous vends tes POKéMON!$"

FiveIsland_RocketWarehouse_Text_Grunt3Intro::
	.string "Les autres m'ont déjà parlé de\n"
	.string "toi.\p"
	.string "Mais quelqu'un comme toi ne peut\n"
	.string "pas connaître GIOVANNI.$"

FiveIsland_RocketWarehouse_Text_Grunt3Defeat::
	.string "Ne te moque pas.$"

FiveIsland_RocketWarehouse_Text_Grunt3PostBattle::
	.string "Ne te mêle pas des affaires des\n"
	.string "adultes, tu n'es pas de taille.$"

FiveIsland_RocketWarehouse_Text_Admin1Intro::
	.string "Je me moque de savoir si ce que\n"
	.string "je fais est bien ou mal…\p"
	.string "J'obéis aveuglément aux ordres\n"
	.string "de GIOVANNI.$"

FiveIsland_RocketWarehouse_Text_Admin1Defeat::
	.string "Je… Je suis à bout de forces…$"

FiveIsland_RocketWarehouse_Text_Admin1PostBattle::
	.string "Il faut toujours agir selon sa\n"
	.string "conscience.\p"
	.string "Je comprends maintenant…$"

FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
	.string "Je viens de faire en sorte que\n"
	.string "tu puisses repasser par ici.\p"
	.string "Pourquoi n'irais-tu pas te\n"
	.string "reposer un peu avant de\p"
	.string "continuer?\p"
	.string "L'ADMIN juste après est un bien\n"
	.string "meilleur DRESSEUR que moi.\p"
	.string "Tu dois t'attendre à un combat\n"
	.string "très difficile.$"

FiveIsland_RocketWarehouse_Text_Admin2Intro::
	.string "Nous en avons assez que tu\n"
	.string "viennes gêner nos plans.\p"
	.string "Faire courir la rumeur que la\n"
	.string "TEAM ROCKET a été démantelée.\p"
	.string "Il est évident que tu cherches à\n"
	.string "semer la confusion dans nos\p"
	.string "rangs.\p"
	.string "Mais nous ne sommes pas stupides\n"
	.string "au point de croire ces\p"
	.string "mensonges.\p"
	.string "Je vais te montrer pourquoi il\n"
	.string "ne faut pas se mêler de nos\p"
	.string "affaires!$"

FiveIsland_RocketWarehouse_Text_Admin2Defeat::
	.string "Urgh… Comment as-tu pu?\p"
	.string "… C'est le badge de GIOVANNI!\p"
	.string "Alors c'est vrai?\p"
	.string "La TEAM ROCKET a vraiment été\n"
	.string "démantelée?$"

FiveIsland_RocketWarehouse_Text_Admin2PostBattle::
	.string "Nous allons quitter cet\n"
	.string "ENTREPOT.\p"
	.string "Mais ne crois pas que tout soit\n"
	.string "fini.\p"
	.string "Je vais trouver GIOVANNI. Et je\n"
	.string "vais faire renaître la TEAM\p"
	.string "ROCKET.\p"
	.string "On se reverra!$"

FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText::
	.string "Des graphiques et du texte sont\n"
	.string "affichés sur l'ordinateur.\p"
	.string "“Influence des ondes magnétiques\n"
	.string "sur l'évolution des POKéMON”…\p"
	.string "C'est trop compliqué…$"

FiveIsland_RocketWarehouse_Text_GideonIntro::
	.string "J'avais presque réussi à vendre\n"
	.string "le SAPHIR pour une très belle\p"
	.string "somme…\p"
	.string "Et il fallait que tu arrives et\n"
	.string "viennes gâcher mon affaire!\p"
	.string "Hin hin hin… Pas de pitié pour\n"
	.string "toi!$"

FiveIsland_RocketWarehouse_Text_GideonDefeat::
	.string "Non, non et non!$"

FiveIsland_RocketWarehouse_Text_GideonPostBattle::
	.string "Si je ne peux pas le vendre, il\n"
	.string "ne me sert plus à rien.\p"
	.string "Prends-le!$"

FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe::
	.string "Quoi encore? Va-t-en,\n"
	.string "laisse-moi.$"

FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair::
	.string "Quoi, encore toi?\p"
	.string "Tu n'es pas le gamin de\n"
	.string "GIOVANNI, n'est-ce pas?\p"
	.string "Non, impossible! Son gamin a les\n"
	.string "cheveux rouges.\p"
	.string "Tu n'as aucune raison de venir\n"
	.string "encore m'importuner.$"

