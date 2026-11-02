BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Hé, hé, hé! Je sais ce que les\n"
	.string "POKéMON pensent!\p"
	.string "S’il te plaît! Je peux voir tes\n"
	.string "POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Bouh! C’est pas sympa!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se\n"
	.string "battre! Même couvert de bobos,\p"
	.string "il se battra!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se\n"
	.string "battre! Mais s'il se retrouve\p"
	.string "couvert de bobos, il se met à\n"
	.string "pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime se\n"
	.string "battre! Mais s'il se retrouve\p"
	.string "couvert de bobos, il deviendra\n"
	.string "sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de\n"
	.string "lui! Mais s'il est couvert de\p"
	.string "bobos, il ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de\n"
	.string "lui! Il ne pense qu'à lui, qu'il\p"
	.string "soit ou non couvert de bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il prend soin de\n"
	.string "lui! Mais s'il se retrouve\p"
	.string "couvert de bobos, il deviendra\n"
	.string "sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être\n"
	.string "sournois! Mais s'il est couvert\p"
	.string "de bobos, il ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être\n"
	.string "sournois! Mais s'il se retrouve\p"
	.string "couvert de bobos, il se met à\n"
	.string "pleurnicher!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "Hum…\p"
	.string "Celui-là dit qu'il aime être\n"
	.string "sournois! Il aime être sournois\p"
	.string "même quand il est couvert de\n"
	.string "bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "C’est n’importe quoi! Comment tu\n"
	.string "veux que je parle avec un\p"
	.string "OEUF!?!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Comme c’est mignon! Cette jeune\n"
	.string "fille prétend qu’elle peut\p"
	.string "comprendre les POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "J’ai l’impression que cette\n"
	.string "fille dit quelque chose de\p"
	.string "profond.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "J’ai une info!\p"
	.string "Cette fille joue souvent dans le\n"
	.string "bâtiment rouge!$"

