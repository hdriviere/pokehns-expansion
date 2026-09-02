SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_HARBOR_MAIL
	pokemartlistend

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man::
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
	.string "Il doit y avoir certains\n"
	.string "produits intéressants au MARCHE.\p"
	.string "Mais certains objets ne sont en\n"
	.string "vente que dans les BOUTIQUES\p"
	.string "POKéMON.$"

SlateportCity_Mart_Text_GreatBallIsBetter:
	.string "La SUPER BALL est plus efficace\n"
	.string "que la POKé BALL pour attraper\p"
	.string "des POKéMON.\p"
	.string "Avec ça, je devrais pouvoir\n"
	.string "attraper ce POKéMON\p"
	.string "insaisissable…$"

