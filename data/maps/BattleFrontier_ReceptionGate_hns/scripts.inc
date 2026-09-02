BattleFrontier_ReceptionGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition_hns
	.byte 0

BattleFrontier_ReceptionGate_OnTransition_hns:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame_hns:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering_hns::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_FRONTIER_RECEPTION_GREETER
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene_hns
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene_hns::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_PLAYER
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter_hns
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit_hns
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter_hns:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown_hns:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter_hns:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit_hns:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott_hns:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike_hns
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall_hns
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner_hns::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry_hns
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems_hns
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode_hns::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_Level50_hns::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel_hns::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry_hns::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems_hns::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide_hns::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols_hns
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns
	end

BattleFrontier_ReceptionGate_EventScript_Symbols_hns::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle_hns::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints_hns::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout_hns
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide_hns::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay_hns:
	.string "C’est la première fois que vous\n"
	.string "venez? Par ici, s’il vous plaît!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier_hns:
	.string "Bienvenue à la ZONE DE COMBAT!\n"
	.string "Le summum des combats de\p"
	.string "POKéMON!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass_hns:
	.string "Pour votre première visite, nous\n"
	.string "devons vous délivrer le PASSE\p"
	.string "ZONE.\p"
	.string "Vous pourrez l’utiliser dans\n"
	.string "toute la ZONE DE COMBAT.\p"
	.string "Tenez!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass_hns:
	.string "{PLAYER} obtient le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass_hns:
	.string "{PLAYER} place la CARTE DE\n"
	.string "DRESSEUR dans le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier_hns:
	.string "Nous espérons que vous passerez\n"
	.string "un agréable moment à la ZONE DE\p"
	.string "COMBAT!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame_hns:
	.string "???: Tiens, mais c’est\n"
	.string "{PLAYER}{KUN}! Content de te\p"
	.string "voir ici!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay_hns:
	.string "GUIDE: Oh! SCOTT! Quel plaisir\n"
	.string "de vous voir!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere_hns:
	.string "SCOTT: Je suis très heureux de\n"
	.string "te voir ici!\p"
	.string "J’espère que tu prendras le\n"
	.string "temps de tout visiter.\p"
	.string "Naturellement, j’espère aussi\n"
	.string "que tu profiteras de l’essence\p"
	.string "même du combat.\p"
	.string "J’ai également une maison ici,\n"
	.string "n’hésite pas à me rendre visite.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities_hns:
	.string "Je suis là pour vous guider\n"
	.string "parmi les installations de la\p"
	.string "ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2_hns:
	.string "Sur quoi voulez-vous vous\n"
	.string "renseigner?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo_hns:
	.string "C’est la tour gigantesque\n"
	.string "considérée comme le symbole de\p"
	.string "la ZONE DE COMBAT.\p"
	.string "Il y a quatre types de SALLES DE\n"
	.string "COMBAT, pour les COMBATS SOLO,\p"
	.string "DUO, MULTI et MULTI LINK.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo_hns:
	.string "Le DOME DE COMBAT est un grand\n"
	.string "bâtiment en forme d’œuf.\p"
	.string "Des TOURNOIS DE COMBAT y ont\n"
	.string "lieu.\p"
	.string "Les TOURNOIS DE COMBAT se jouent\n"
	.string "en COMBATS SOLO ou DUO.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo_hns:
	.string "Le PALACE DE COMBAT est le\n"
	.string "bâtiment rouge à droite dans la\p"
	.string "ZONE DE COMBAT.\p"
	.string "Il contient deux types de HALLS\n"
	.string "DE COMBAT, pour les COMBATS SOLO\p"
	.string "et DUO.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo_hns:
	.string "Le DOJO DE COMBAT se trouve à la\n"
	.string "droite du centre de la ZONE DE\p"
	.string "COMBAT.\p"
	.string "Des TOURNOIS K.O. y ont lieu.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo_hns:
	.string "L’USINE DE COMBAT est le grand\n"
	.string "bâtiment tout près d’ici.\p"
	.string "On y propose le COMBAT ECHANGE.\p"
	.string "Ce défi peut prendre la forme de\n"
	.string "COMBATS SOLO ou de COMBATS DUO.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo_hns:
	.string "Le REPTILE DE COMBAT est le\n"
	.string "bâtiment qui a la forme d’un\p"
	.string "POKéMON, à la gauche du centre\n"
	.string "de la ZONE DE COMBAT.\p"
	.string "L’évènement appelé COMBAT HASARD\n"
	.string "y prend place.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo_hns:
	.string "La PYRAMIDE DE COMBAT est\n"
	.string "l’énorme pyramide.\p"
	.string "L’évènement appelé COMBAT QUETE\n"
	.string "y a lieu.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo_hns:
	.string "Le HALL DE CLASSEMENT se trouve\n"
	.string "près de la TOUR DE COMBAT.\p"
	.string "On peut y consulter les records\n"
	.string "des meilleurs DRESSEURS s’étant\p"
	.string "battus dans la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo_hns:
	.string "Le SERVICE D’ECHANGE se trouve\n"
	.string "près de la TOUR DE COMBAT.\p"
	.string "Vous pouvez y échanger les\n"
	.string "POINTS DE COMBAT obtenus dans la\p"
	.string "ZONE DE COMBAT contre des prix\n"
	.string "fabuleux.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules_hns:
	.string "Je peux vous expliquer les\n"
	.string "règles de base communes aux\p"
	.string "défis des différents bâtiments\n"
	.string "de la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat_hns:
	.string "Sur quel sujet désirez-vous\n"
	.string "obtenir des informations?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo_hns:
	.string "Pour tous les défis de la ZONE\n"
	.string "DE COMBAT, vous pouvez choisir\p"
	.string "entre niveau 50 et niveau libre.$"

BattleFrontier_ReceptionGate_Text_Level50Info_hns:
	.string "Niveau 50 est ouvert aux POKéMON\n"
	.string "dont le niveau est de 50 ou\p"
	.string "moins.\p"
	.string "Cependant, aucun des DRESSEURS\n"
	.string "que vous affronterez n’aura de\p"
	.string "POKéMON dont le niveau est\n"
	.string "inférieur à 50.\p"
	.string "C’est le niveau le plus bas pour\n"
	.string "les combats de la ZONE DE\p"
	.string "COMBAT.\p"
	.string "Pour commencer, nous vous\n"
	.string "conseillons donc de choisir\p"
	.string "niveau 50.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo_hns:
	.string "Niveau libre ne fixe pas de\n"
	.string "limite au niveau des POKéMON\p"
	.string "participant à un défi.\p"
	.string "Le niveau de vos adversaires\n"
	.string "sera ajusté en fonction du\p"
	.string "niveau de vos POKéMON.\p"
	.string "Cependant, aucun des DRESSEURS\n"
	.string "que vous affronterez n’aura de\p"
	.string "POKéMON dont le niveau est\n"
	.string "inférieur à 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo_hns:
	.string "Presque tous les POKéMON peuvent\n"
	.string "relever les défis de tous les\p"
	.string "bâtiments.\p"
	.string "Les OEUFS et certains POKéMON ne\n"
	.string "sont pas autorisés.\p"
	.string "Le nombre de POKéMON nécessaires\n"
	.string "pour participer varie selon\p"
	.string "l’endroit.\p"
	.string "Cependant, il est impossible\n"
	.string "d’inscrire deux POKéMON\p"
	.string "identiques.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo_hns:
	.string "Lorsque vous relevez un défi de\n"
	.string "la ZONE DE COMBAT, il ne faut\p"
	.string "pas que deux de vos POKéMON\n"
	.string "portent le même objet.\p"
	.string "Assurez-vous que les POKéMON que\n"
	.string "vous voulez inscrire à un défi\p"
	.string "portent tous des objets\n"
	.string "différents.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass_hns:
	.string "Je peux tout vous expliquer sur\n"
	.string "le PASSE ZONE.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1_hns:
	.string "Sur quoi voulez-vous vous\n"
	.string "renseigner?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo_hns:
	.string "Il y a sept bâtiments dans la\n"
	.string "ZONE DE COMBAT où gagner des\p"
	.string "symboles.\p"
	.string "Les DRESSEURS qui ont du succès\n"
	.string "peuvent se voir récompensés par\p"
	.string "des symboles.\p"
	.string "Pour obtenir un symbole, un\n"
	.string "DRESSEUR devra peut-être battre\p"
	.string "plusieurs DRESSEURS à la suite\n"
	.string "et remporter un évènement\p"
	.string "plusieurs fois.\p"
	.string "Obtenir des symboles n’est pas\n"
	.string "facile. Je vous souhaite bonne\p"
	.string "chance!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo_hns:
	.string "Il est possible d’enregistrer un\n"
	.string "combat sur votre PASSE ZONE.\p"
	.string "Vous pouvez par exemple\n"
	.string "enregistrer un combat contre un\p"
	.string "ou plusieurs amis.\p"
	.string "Vous pouvez également\n"
	.string "enregistrer un combat ayant eu\p"
	.string "lieu dans la ZONE DE COMBAT,\n"
	.string "sauf au REPTILE DE COMBAT et\p"
	.string "dans la PYRAMIDE DE COMBAT.\p"
	.string "Vous pouvez décider\n"
	.string "d’enregistrer ou non à la fin du\p"
	.string "combat.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo_hns:
	.string "Les POINTS DE COMBAT\n"
	.string "récompensent les DRESSEURS qui\p"
	.string "font de beaux combats dans la\n"
	.string "ZONE DE COMBAT.\p"
	.string "Vous pouvez échanger vos POINTS\n"
	.string "DE COMBAT contre des prix au\p"
	.string "SERVICE D’ECHANGE.$"

