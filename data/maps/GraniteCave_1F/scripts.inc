GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hé, toi! Il fait terriblement\n"
	.string "sombre là-dedans. Ça va être\p"
	.string "difficile à explorer.\p"
	.string "Ce type qui est passé tout à\n"
	.string "l’heure… PIERRE, je crois que\p"
	.string "c’était ça.\p"
	.string "Il savait utiliser FLASH, alors\n"
	.string "il n’a pas dû avoir de problème,\p"
	.string "mais…\p"
	.string "Pour nous, les MONTAGNARDS, la\n"
	.string "devise est d’aider ceux que l’on\p"
	.string "rencontre.\p"
	.string "Vas-y et bon courage!$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Apprends cette CS FLASH à un\n"
	.string "POKéMON et utilise-la.\p"
	.string "Ça permet d’éclairer même les\n"
	.string "cavernes les plus sombres.\p"
	.string "Mais pour l’utiliser, il faut le\n"
	.string "BADGE de l’ARENE POKéMON de\p"
	.string "MYOKARA.$"

