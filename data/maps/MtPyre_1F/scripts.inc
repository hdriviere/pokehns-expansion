MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Toutes sortes d’êtres se\n"
	.string "promènent sur les versants du\p"
	.string "MONT MEMORIA…\p"
	.string "On ne sait jamais ce qui peut\n"
	.string "arriver. Prends ça. C’est pour\p"
	.string "ton bien.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Fais tenir cette RUNE PURIF. à\n"
	.string "l’un de tes POKéMON.\p"
	.string "Ça éloignera les POKéMON\n"
	.string "sauvages.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Es-tu là pour présenter tes\n"
	.string "respects aux esprits des défunts\p"
	.string "POKéMON?\p"
	.string "Tu dois prendre grand soin de\n"
	.string "tes POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "C’est ici que repose mon\n"
	.string "ZIGZATON. C’est un endroit que\p"
	.string "je chéris…$"

