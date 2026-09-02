Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_WINSTRATE_HOUSE_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "C’est la première fois que je\n"
	.string "vois un DRESSEUR qui maîtrise\p"
	.string "aussi bien ses POKéMON.\p"
	.string "Mais il vaut mieux que je te\n"
	.string "prévienne, mon fils est plus\p"
	.string "fort que toi.\p"
	.string "Il a même relevé le défi de la\n"
	.string "LIGUE POKéMON, j’te signale.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Nous utilisons ce BRAC. MACHO\n"
	.string "pour améliorer l’entraînement de\p"
	.string "nos POKéMON.\p"
	.string "Je ne sais pas si tu en auras\n"
	.string "besoin, mais comme tu nous as\p"
	.string "tous battus ici, nous t’offrons\n"
	.string "notre BRAC. MACHO.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Lorsqu’on parle de combats de\n"
	.string "POKéMON, on est souvent très\p"
	.string "passionnés.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Maman est plus forte que papa.\p"
	.string "Je suis plus forte que maman.\p"
	.string "Et mémé est plus forte que moi!\p"
	.string "Mais mon grand frère est encore\n"
	.string "plus fort que mémé.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Aucun doute, tu es très robuste.\p"
	.string "Mais si tu te mesurais à mon\n"
	.string "petit-fils, tu pleurerais comme\p"
	.string "un bébé.\p"
	.string "Notre famille n’a jamais vu un\n"
	.string "DRESSEUR aussi fort que lui.\p"
	.string "En ce moment, il doit défier le\n"
	.string "MAITRE de la LIGUE POKéMON.\p"
	.string "Tel que je connais mon\n"
	.string "petit-fils, il est peut-être\p"
	.string "déjà le MAITRE!$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "En ce moment, mon petit-fils\n"
	.string "doit défier le MAITRE de la\p"
	.string "LIGUE POKéMON.\p"
	.string "Tel que je le connais, il est\n"
	.string "peut-être déjà le MAITRE!$"

