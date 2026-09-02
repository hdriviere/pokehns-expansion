MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Non! La TEAM MAGMA est arrivée\n"
	.string "avant nous!\p"
	.string "On ne peut pas toujours arriver\n"
	.string "après eux!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Je pensais que tu étais de la\n"
	.string "TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Eh! En effet, tu as une grande\n"
	.string "force… Mais nous sommes\p"
	.string "nombreux!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah! Dommage pour toi!\p"
	.string "En arrivant plus tôt, tu\n"
	.string "n’aurais eu que cette minable\p"
	.string "TEAM MAGMA à affronter.\p"
	.string "Mais maintenant, tu vas devoir\n"
	.string "nous affronter nous, la\p"
	.string "redoutable TEAM AQUA!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urrrgh…\p"
	.string "J’aurais dû te laisser affronter\n"
	.string "la TEAM MAGMA en premier!$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Tu n’y connais rien. Arrête de\n"
	.string "nous ennuyer!$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Hé, je me rappelle de toi!\n"
	.string "C’était au MONT CHIMNEE!!\p"
	.string "Tu ne fais partie d’aucune TEAM,\n"
	.string "alors qu’est-ce que tu fais ici?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Si tu dois gêner quelqu’un, que\n"
	.string "ce soit au moins la TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Hé, c’est pas grave! On a gagné\n"
	.string "du temps!\p"
	.string "A l’heure qu’il est, le CHEF a\n"
	.string "dû réussir à obtenir ce qu’il\p"
	.string "voulait!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, je sais! Tu voulais faire\n"
	.string "partie de la TEAM MAGMA mais ils\p"
	.string "n’ont pas voulu de toi!\p"
	.string "Mais ne pense pas non plus\n"
	.string "pouvoir entrer dans la TEAM\p"
	.string "AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Si tu tiens tant que ça à faire\n"
	.string "partie de la TEAM… On va y\p"
	.string "réfléchir…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Il y a une très bonne entente\n"
	.string "entre nous et notre chef.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARTHUR: MAX, de la TEAM MAGMA, a\n"
	.string "été plus rapide que nous.\p"
	.string "Mais nous avons aussi ce que\n"
	.string "nous voulions.\p"
	.string "L’ORBE ROUGE du MONT MEMORIA… Il\n"
	.string "est enfin en notre possession!\p"
	.string "… Nous pouvons maintenant\n"
	.string "accomplir notre ultime objectif!\p"
	.string "OK, à tous les membres! Repli\n"
	.string "immédiat!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, non… C’est pas possible…\p"
	.string "Après l’ORBE BLEU, l’ORBE ROUGE\n"
	.string "a également été dérobé…\p"
	.string "Il ne faut jamais séparer l’ORBE\n"
	.string "BLEU  de l’ORBE ROUGE. Ils\p"
	.string "forment un tout.\p"
	.string "Qu’est-ce que ces hommes veulent\n"
	.string "faire avec les deux ORBES?\p"
	.string "… … … … … … … … Hum…\p"
	.string "Oh oui, c’est bien la TEAM MAGMA\n"
	.string "qui est d’abord venue voler\p"
	.string "l’ORBE BLEU?\p"
	.string "Eh bien, dans leur hâte, ils ont\n"
	.string "oublié ça derrière eux.\p"
	.string "Je n’arrive pas à voir à quoi ça\n"
	.string "peut servir.\p"
	.string "Je voudrais que tu le prennes.\n"
	.string "Ça pourrait t’être utile.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "L’ORBE BLEU et l’ORBE ROUGE qui\n"
	.string "ont été volés…\p"
	.string "Ils ne doivent jamais être\n"
	.string "séparés… Quelque chose de\p"
	.string "terrible va se passer…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Alors… Tu dis que KYOGRE et\n"
	.string "GROUDON se sont réveillés…\p"
	.string "On dit que l’ORBE BLEU et l’ORBE\n"
	.string "ROUGE peuvent apaiser la colère\p"
	.string "de KYOGRE et GROUDON…\p"
	.string "On raconte aussi que le vrai\n"
	.string "propriétaire des ORBES est\p"
	.string "toujours vivant.\p"
	.string "Pourtant, personne ne sait\n"
	.string "exactement qui il est, ou ce\p"
	.string "qu’il est.\p"
	.string "Ça pourrait être un humain, ou\n"
	.string "bien un POKéMON… Personne ne\p"
	.string "sait vraiment…$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Les deux hommes qui avaient\n"
	.string "dérobé les ORBES sont revenus\p"
	.string "les rendre de leur plein gré.\p"
	.string "Ces hommes…\p"
	.string "Ils ne sont peut-être pas si\n"
	.string "méchants que ça après tout…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Les esprits de la terre, de la\n"
	.string "mer et du ciel…\p"
	.string "C’est ce que les POKéMON\n"
	.string "ancestraux sont censés incarner…\p"
	.string "Tout comme les POKéMON et nous,\n"
	.string "la nature aussi est vivante…\p"
	.string "Les POKéMON ancestraux nous\n"
	.string "l’ont enseigné…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Au MONT MEMORIA, les esprits des\n"
	.string "POKéMON trépassés sont apaisés.\p"
	.string "C’est un endroit en hauteur,\n"
	.string "d’où l’on domine toute la région\p"
	.string "de HOENN…\p"
	.string "Les esprits désincarnés doivent\n"
	.string "y trouver réconfort…\p"
	.string "C’est une coïncidence que tu\n"
	.string "sois là…\p"
	.string "Veux-tu entendre mon récit? Un\n"
	.string "récit longtemps raconté à HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "C’était il y a très longtemps…\p"
	.string "Le monde était ravagé par un\n"
	.string "conflit acharné entre le POKéMON\p"
	.string "de la terre et le POKéMON de la\n"
	.string "mer…\p"
	.string "Le POKéMON de la terre érigea\n"
	.string "des montagnes et créa des\p"
	.string "continents.\p"
	.string "Le POKéMON de la mer souleva des\n"
	.string "vagues et découpa des océans.\p"
	.string "Leur duel acharné sévissait sans\n"
	.string "fin.\p"
	.string "Le monde fut englouti par de\n"
	.string "violentes tempêtes et des\p"
	.string "brasiers ardents.\p"
	.string "L’ORBE BLEU et l’ORBE ROUGE\n"
	.string "mirent fin à ce désastre.\p"
	.string "La lumière jaillit des deux\n"
	.string "ORBES et apaisa les adversaires\p"
	.string "furieux.\p"
	.string "Puis, les deux POKéMON finirent\n"
	.string "par disparaître dans les\p"
	.string "profondeurs de la terre…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Je vois… Eh bien, ça aussi c’est\n"
	.string "bien…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAX: {PLAYER}…\p"
	.string "… … … … … … … … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "C’est mon devoir de transmettre\n"
	.string "les légendes d’HOENN aux\p"
	.string "générations futures.\p"
	.string "Et cette crise qui vient de\n"
	.string "prendre fin à ATALANOPOLIS a\p"
	.string "réécrit la légende…\p"
	.string "As-tu le temps d’écouter la\n"
	.string "nouvelle légende d’HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "C’était il y a très longtemps…\p"
	.string "Le monde était ravagé par un\n"
	.string "conflit acharné entre le POKéMON\p"
	.string "de la terre et le POKéMON de la\n"
	.string "mer…\p"
	.string "Le POKéMON de la terre érigea\n"
	.string "des montagnes et créa des\p"
	.string "continents.\p"
	.string "Le POKéMON de la mer souleva des\n"
	.string "vagues et découpa des océans.\p"
	.string "Leur duel acharné sévissait sans\n"
	.string "fin.\p"
	.string "Le monde fut englouti par de\n"
	.string "violentes tempêtes et des\p"
	.string "brasiers ardents.\p"
	.string "C’est alors qu’apparut un\n"
	.string "POKéMON surgissant d’une\p"
	.string "tempête.\p"
	.string "Le POKéMON, d’un vert vif comme\n"
	.string "un joyau, réussit à calmer les\p"
	.string "deux POKéMON enragés.\p"
	.string "Sa tâche accomplie, le POKéMON\n"
	.string "vert retourna là-haut dans le\p"
	.string "ciel…$"

