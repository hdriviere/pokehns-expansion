MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "RAPPEL est fabuleux!\p"
	.string "Si tu en donnes à un POKéMON\n"
	.string "K.O., il reprend connaissance.\p"
	.string "Mais attention, RAPPEL ne\n"
	.string "restitue pas les PP des\p"
	.string "capacités déjà utilisés.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "MAX REPOUSSE maintient les\n"
	.string "POKéMON faibles à l’écart.\p"
	.string "Parmi tous les REPOUSSES, c’est\n"
	.string "celui qui dure le plus\p"
	.string "longtemps.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Les FILET BALLS et les SCUBA\n"
	.string "BALLS sont des POKé BALLS rares,\p"
	.string "qui ne sont fabriquées qu’à\n"
	.string "ALGATIA.\p"
	.string "La FILET BALL est efficace\n"
	.string "contre les POKéMON des types\p"
	.string "INSECTE et EAU.\p"
	.string "La SCUBA BALL est plus efficace\n"
	.string "contre les POKéMON qui vivent au\p"
	.string "fond de la mer.$"

