LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "Utilise VITESSE + pour augmenter\n"
	.string "la VITESSE d’un POKéMON au\p"
	.string "combat.\p"
	.string "Ça lui donnera plus de chances\n"
	.string "de frapper le premier, un sacré\p"
	.string "avantage!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "Au sommet du MONT CHIMNEE, on\n"
	.string "trouve une spécialité locale\p"
	.string "qu’on ne peut acheter que\n"
	.string "là-haut.\p"
	.string "Donne-la à un POKéMON. Il sera\n"
	.string "ravi.$"

