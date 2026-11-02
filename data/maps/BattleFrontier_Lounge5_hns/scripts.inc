BattleFrontier_Lounge5_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsEgg_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirl_hnsNoneShown_hns::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman_hns::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy_hns::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting_hns::
	.string "Hé, hé, hé! Je sais ce que les\n"
	.string "POKéMON pensent!\p"
	.string "S’il te plaît! Je peux voir tes\n"
	.string "POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown_hns::
	.string "Bouh! C’est pas sympa!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow_hns::
	.string "Hmm...\p"
	.string "Il dit aimer combattre! Il se\n"
	.string "battra même avec beaucoup de\p"
	.string "bobos!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow_hns::
	.string "Hmm...\p"
	.string "Il dit aimer combattre! Mais\n"
	.string "avec assez de bobos, il se\p"
	.string "souciera de lui-même!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow_hns::
	.string "Hmm...\p"
	.string "Il dit aimer combattre! Mais\n"
	.string "avec assez de bobos, il\p"
	.string "deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow_hns::
	.string "Hmm...\p"
	.string "Il dit prendre soin de lui! Mais\n"
	.string "avec assez de bobos, il\p"
	.string "ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow_hns::
	.string "Hmm...\p"
	.string "Il dit prendre soin de lui! Avec\n"
	.string "ou sans bobos, il se soucie\p"
	.string "toujours de lui-même!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow_hns::
	.string "Hmm...\p"
	.string "Il dit prendre soin de lui! Mais\n"
	.string "avec assez de bobos, il\p"
	.string "deviendra sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow_hns::
	.string "Hmm...\p"
	.string "Il dit aimer la ruse! Mais avec\n"
	.string "assez de bobos, il ripostera!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow_hns::
	.string "Hmm...\p"
	.string "Il dit aimer la ruse! Mais avec\n"
	.string "assez de bobos, il se souciera\p"
	.string "de lui-même!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow_hns::
	.string "Hmm...\p"
	.string "Il dit aimer la ruse! Même avec\n"
	.string "beaucoup de bobos, il restera\p"
	.string "sournois!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg_hns::
	.string "C’est n’importe quoi! Comment tu\n"
	.string "veux que je parle avec un\p"
	.string "OEUF!?!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon_hns::
	.string "Comme c’est mignon! Cette jeune\n"
	.string "fille prétend qu’elle peut\p"
	.string "comprendre les POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound_hns::
	.string "J’ai l’impression que cette\n"
	.string "fille dit quelque chose de\p"
	.string "profond.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot_hns::
	.string "J’ai une info!\p"
	.string "Cette fille joue souvent dans le\n"
	.string "bâtiment rouge!$"

