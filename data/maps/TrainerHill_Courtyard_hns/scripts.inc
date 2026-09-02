TrainerHill_Courtyard_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "Waouh, la COLLINE DRESSEURS est\n"
	.string "immense!\p"
	.string "Elle doit abriter de nombreuses\n"
	.string "espèces de Pokémon!$"

BattleTowerOutsideBeautyText:
	.string "Dans les TENTES DE COMBAT, seuls\n"
	.string "trois Pokémon sont autorisés.\p"
	.string "C'est si difficile de décider\n"
	.string "lesquels envoyer au combat...$"

BattleTowerOutsideSailorText:
	.string "J'ai pris une perm'.\p"
	.string "Je dois gagner! Oh que oui!$"

BattleTowerOutsideSignText:
	.string "{UP_ARROW} ENTRÉE DE LA COLLINE\n"
	.string "DRESSEURS\p"
	.string "Gravissez les sommets, Dresseurs\n"
	.string "au sang chaud!\p"
	.string "{RIGHT_ARROW} TENTES DE COMBAT.$"

BattleTower_Battle_Tent_Text_Factory:
	.string "TENTE DE COMBAT: USINE Trouvez\n"
	.string "le Pokémon ultime!$"

BattleTower_Battle_Tent_Text_Palace:
	.string "TENTE DE COMBAT: PALACE Admirez\n"
	.string "les combats!$"

BattleTower_Battle_Tent_Text_Arena:
	.string "TENTE DE COMBAT: DOJO Que les\n"
	.string "meilleures équipes se\p"
	.string "réunissent!$"

BattleTowerOutsideText_Closed:
	.string "La COLLINE DRESSEURS est fermée\n"
	.string "pour réparations.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_LeftMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_RightMoveTutor_hns
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	goto BattleFrontier_Lounge7_EventScript_ElementalMoveTutor
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop1
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPDecorShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPVitaminShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk2::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPHoldItemShop2
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PowerClerk::
	lock
	faceplayer
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special CreateBPPowerShop
	waitstate
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "Salut! Si tu cherches l'ÉCHANGE\n"
	.string "MIRACLE, il se trouve désormais\p"
	.string "dans chaque CENTRE POKéMON.\n"
	.string "Amuse-toi bien!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Bonjour! Vous êtes au SERVICE\n"
	.string "D’ECHANGE.\p"
	.string "Nous échangeons vos POINTS DE\n"
	.string "COMBAT contre de magnifiques\p"
	.string "prix.\p"
	.string "Veuillez choisir un objet.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, ce que c’est beau!\n"
	.string "J’aimerais tout avoir! Les jolis\p"
	.string "COUSSINS! Les grosses POUPEES!\n"
	.string "Les petites POUPEES! J’aimerais\p"
	.string "tout avoir!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Dis à maman ce que tu veux.\p"
	.string "Si tu veux quelque chose, je\n"
	.string "ferai tout pour te l’offrir, mon\p"
	.string "chéri!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Si j’arrive à me procurer ces\n"
	.string "objets,  mes POKéMON vont\p"
	.string "devenir plus forts.\p"
	.string "Oui, plutôt deux fois qu’une! Il\n"
	.string "me faut ces objets!$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Tiens? Mais qu’est-ce que tu\n"
	.string "regardes, là?\p"
	.string "Arrête de reluquer ma poupée\n"
	.string "comme ça.\p"
	.string "Si tu en veux une, tu n’as qu’à\n"
	.string "l’acheter! Pas vrai, LIPPOUTI?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Dis, tu savais ça?\p"
	.string "Si tu rejoues et améliores ton\n"
	.string "résultat dans un bâtiment de la\p"
	.string "ZONE DE COMBAT, tu obtiens plus\n"
	.string "de POINTS DE COMBAT.$"
