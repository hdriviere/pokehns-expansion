Route5_House_hns_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "Griiiiiiiiih!!!\p"
	.string "Je sens une présence maléfique\n"
	.string "planer sur toi!\p"
	.string "Tu auras besoin de ce talisman!$"

Route5_House_Text_Granny2:
	.string "Tu l’as échappé\n"
	.string "belle... Mais tu\p"
	.string "n’as plus rien à\n"
	.string "craindre maintenant!$"

Route5_House_Text_Woman:
	.string "Ma grand-mère est passionnée par\n"
	.string "ses exorcismes...\p"
	.string "Excuse-la si elle t’a fait peur.$"
