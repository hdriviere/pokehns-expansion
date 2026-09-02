FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. KOSMO: Oh… Je n’aurais\n"
	.string "jamais dû me laisser rouler dans\p"
	.string "la farine et avouer à la TEAM\n"
	.string "MAGMA où on peut trouver des\p"
	.string "METEORITES…\p"
	.string "Ce METEORITE du SITE METEORE… Il\n"
	.string "ne sera jamais à moi,\p"
	.string "maintenant…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh! Hein?\p"
	.string "Mais, cet objet…\p"
	.string "C’est impossible!?!\p"
	.string "Est-ce le METEORITE que la TEAM\n"
	.string "MAGMA a pris au SITE METEORE?\p"
	.string "S’il te plaît, tu peux me le\n"
	.string "donner?\p"
	.string "Je suis prêt à te l’échanger\n"
	.string "contre un objet de valeur. Que\p"
	.string "dirais-tu d’une CT?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. KOSMO: Cette CT est le\n"
	.string "symbole de ma gratitude à ton\p"
	.string "égard.\p"
	.string "N’hésite pas à l’utiliser!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. KOSMO: Oh, je n’arrive pas\n"
	.string "à y croire. C’est vraiment super\p"
	.string "génial!\p"
	.string "Ça va faire avancer mes\n"
	.string "recherches!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. KOSMO: Oh, mais… Je suis\n"
	.string "extrêmement déçu…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. KOSMO: S’il te plaît, tu\n"
	.string "peux me donner ce METEORITE?\p"
	.string "Je suis prêt à te l’échanger\n"
	.string "contre un objet de valeur. Que\p"
	.string "dirais-tu d’une CT?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "Le PROF. KOSMO est parti au SITE\n"
	.string "METEORE, sur la ROUTE 114, avec\p"
	.string "des types de la TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Pauvre PROF. KOSMO… Il est si\n"
	.string "déprimé… Ça me fend le cœur.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Regarde le PROF. KOSMO… Il est\n"
	.string "tellement content! C’est génial!$"

