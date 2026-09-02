VermilionCity_Mart_Frlg_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_CooltrainerF::
	msgbox VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_BaldingMan::
	msgbox VermilionCity_Mart_Text_TeamRocketAreWickedPeople, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VermilionCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
VermilionCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

VermilionCity_Mart_Text_TeamRocketAreWickedPeople::
	.string "Il y en a, des très méchants,\n"
	.string "qui utilisent les POKéMON pour\p"
	.string "des actes criminels.\p"
	.string "La TEAM ROCKET fait du trafic de\n"
	.string "POKéMON rares.\p"
	.string "Ils abandonnent sur le bord de\n"
	.string "la route les POKéMON trop\p"
	.string "faibles!\p"
	.string "Ouais, ils sont comme ça dans la\n"
	.string "TEAM ROCKET.$"

VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer::
	.string "Les POKéMON peuvent être gentils\n"
	.string "ou méchants, cela dépend de leur\p"
	.string "DRESSEUR.$"

