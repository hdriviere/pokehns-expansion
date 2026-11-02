LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_MIRROR_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Bienvenue à l’HERBORISTERIE, la\n"
	.string "maison des médicaments efficaces\p"
	.string "à bas prix!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Tu viens chercher des\n"
	.string "médicaments à base de plantes à\p"
	.string "VERMILAVA?\p"
	.string "C’est très honorable.\p"
	.string "Je t’aime bien! Prends ça!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Le CHARBON que je t’ai donné est\n"
	.string "utilisé pour faire des\p"
	.string "médicaments naturels.\p"
	.string "Il fait aussi des merveilles\n"
	.string "lorsqu’il est tenu par un\p"
	.string "POKéMON.\p"
	.string "Il augmente la puissance des\n"
	.string "attaques de type FEU.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "La médecine à base de plantes\n"
	.string "est extrêmement efficace. Mais\p"
	.string "tes POKéMON\p"
	.string "risquent de ne pas apprécier.\n"
	.string "Les médicaments sont très amers!$"

