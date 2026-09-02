BattleFrontier_ExchangeServiceCorner_hns_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokeBallClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPokeBallShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PowerClerk_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF_hns::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl_hns::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize_hns:
	.string "Bonjour! Vous êtes au SERVICE\n"
	.string "D’ECHANGE.\p"
	.string "Nous échangeons vos POINTS DE\n"
	.string "COMBAT contre de magnifiques\p"
	.string "prix.\p"
	.string "Veuillez choisir un objet.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls_hns:
	.string "Oh, ce que c’est beau!\n"
	.string "J’aimerais tout avoir! Les jolis\p"
	.string "COUSSINS! Les grosses POUPEES!\n"
	.string "Les petites POUPEES! J’aimerais\p"
	.string "tout avoir!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant_hns:
	.string "Dis à maman ce que tu veux.\p"
	.string "Si tu veux quelque chose, je\n"
	.string "ferai tout pour te l’offrir, mon\p"
	.string "chéri!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher_hns:
	.string "Si j’arrive à me procurer ces\n"
	.string "objets,  mes POKéMON vont\p"
	.string "devenir plus forts.\p"
	.string "Oui, plutôt deux fois qu’une! Il\n"
	.string "me faut ces objets!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll_hns:
	.string "Tiens? Mais qu’est-ce que tu\n"
	.string "regardes, là?\p"
	.string "Arrête de reluquer ma poupée\n"
	.string "comme ça.\p"
	.string "Si tu en veux une, tu n’as qu’à\n"
	.string "l’acheter! Pas vrai, LIPPOUTI?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord_hns:
	.string "Dis, tu savais ça?\p"
	.string "Si tu rejoues et améliores ton\n"
	.string "résultat dans un bâtiment de la\p"
	.string "ZONE DE COMBAT, tu obtiens plus\n"
	.string "de POINTS DE COMBAT.$"
