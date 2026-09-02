CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, tu dois être {PLAYER}{KUN}.\n"
	.string "J’ai entendu parler de tes\p"
	.string "exploits.\p"
	.string "Je m’appelle MARC.\p"
	.string "J’étais autrefois le CHAMPION\n"
	.string "D’ARENE d’ATALANOPOLIS.\p"
	.string "Mais j’ai dû confier la garde de\n"
	.string "l’ARENE à JUAN, mon mentor.\p"
	.string "… … … … … … … … … … … …\p"
	.string "GROUDON et KYOGRE, les deux\n"
	.string "POKéMON qui s’affrontent, sont\p"
	.string "considérés comme des POKéMON\n"
	.string "ancestraux.\p"
	.string "Mais il n’existe pas que deux\n"
	.string "POKéMON ancestraux.\p"
	.string "Il y en a un autre ailleurs.\p"
	.string "Quelque part, se trouve un\n"
	.string "POKéMON ancestral appelé\p"
	.string "RAYQUAZA.\p"
	.string "On raconte que dans le passé,\n"
	.string "c’est RAYQUAZA qui avait calmé\p"
	.string "les deux combattants.\p"
	.string "Malheureusement, je n’ai aucune\n"
	.string "idée sur l’endroit où peut bien\p"
	.string "se cacher RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "MARC: {PLAYER}{KUN}, mais\n"
	.string "peut-être sais-tu, toi, où se\p"
	.string "trouve RAYQUAZA?\p"
	.string "Si tu le sais, je t’en prie,\n"
	.string "dis-le moi.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "MARC: La GROTTE ORIGINE?\p"
	.string "Mais c’est ici! Ce n’est pas\n"
	.string "possible!\p"
	.string "S’il te plaît, essaie de\n"
	.string "réfléchir à l’endroit où\p"
	.string "RAYQUAZA pourrait bien se\n"
	.string "trouver.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "MARC: Le MONT MEMORIA?\p"
	.string "Mais la vieille femme que j’ai\n"
	.string "rencontrée là-bas n’y a fait\p"
	.string "aucune allusion…\p"
	.string "Et je doute vraiment qu’elle ait\n"
	.string "essayé de me cacher quoi que ce\p"
	.string "soit.\p"
	.string "{PLAYER}{KUN}, est-ce que tu\n"
	.string "pourrais y réfléchir plus\p"
	.string "sérieusement?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "MARC: Hein? Tu ne te souviens\n"
	.string "plus? Hmm… C’est un problème…\p"
	.string "Tu ne peux vraiment pas t’en\n"
	.string "souvenir?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "MARC: Le PILIER CELESTE?\p"
	.string "C’est ça! Il doit se trouver au\n"
	.string "PILIER CELESTE!\p"
	.string "{PLAYER}{KUN}, il n’y a pas un\n"
	.string "instant à perdre! Rendons-nous\p"
	.string "de suite au PILIER CELESTE!$"

