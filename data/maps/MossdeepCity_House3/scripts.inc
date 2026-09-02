MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hé, toi, DRESSEUR! Une MEGA\n"
	.string "CANNE, c’est vraiment super!\p"
	.string "Tu peux dire c’que tu veux, ce\n"
	.string "bébé peut attraper des POKéMON\p"
	.string "au fond de la mer!\p"
	.string "Qu’est-ce que t’en penses? Tu\n"
	.string "veux qu’on essaie, hein?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Tu paries, tu paries! Après\n"
	.string "tout, une MEGA CANNE, c’est\p"
	.string "super!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "S’il y a de l’eau, essaie de\n"
	.string "lancer ta CANNE et attends de\p"
	.string "voir si ça mord!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hum? T’aimes pas pêcher?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Essaie d’attraper les POKéMON au\n"
	.string "fond de la mer avec ta MEGA\p"
	.string "CANNE.$"

