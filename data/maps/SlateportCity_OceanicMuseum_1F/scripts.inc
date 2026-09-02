SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Bienvenue au MUSEE\n"
	.string "OCEANOGRAPHIQUE.\p"
	.string "L’entrée coûte 50¥. Voulez-vous\n"
	.string "entrer?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Bonne visite!$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh, désolée, mais vous ne\n"
	.string "semblez pas avoir suffisamment\p"
	.string "d’argent.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh, vous faites partie du groupe\n"
	.string "qui est entré tout à l’heure?\p"
	.string "Ils doivent déjà être loin. Vous\n"
	.string "feriez bien de les rattraper!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Nous, la TEAM AQUA, nous\n"
	.string "existons  pour le bien de tous!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "On nous a dit de nous regrouper\n"
	.string "ici, alors on l’a fait, mais…\p"
	.string "Notre CHEF, le pivot du groupe,\n"
	.string "n’est pas là.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Si je piquais tout ce qu’il y a\n"
	.string "ici, est-ce que ça me rendrait\p"
	.string "riche?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Ce que j’apprends ici, je peux\n"
	.string "m’en servir pour agir de façon\p"
	.string "infâme…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Si cet imbécile n’avait pas\n"
	.string "échoué à MEROUVILLE, on n’en\p"
	.string "serait pas là.$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Je n’avais pas les 50¥, alors\n"
	.string "j’ai dû parlementer avec la\p"
	.string "réceptionniste.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Je veux tirer des enseignements\n"
	.string "de la mer et m’en servir pour\p"
	.string "combattre.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Je suis tout excité quand je\n"
	.string "vois la mer!\p"
	.string "Le CAPT. POUPE est un exemple\n"
	.string "pour moi!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "La mer est sans limite et d’une\n"
	.string "infinie profondeur…\p"
	.string "Il doit y avoir de nombreux\n"
	.string "POKéMON dont on ignore tout.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Je veux un POKéMON de la mer.\p"
	.string "Je crois que ce serait sympa de\n"
	.string "le tenir contre moi.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Héééé! Qu’est-ce que tu fais là?\p"
	.string "Moi? Je suis le membre de la\n"
	.string "TEAM AQUA que tu as déjà\p"
	.string "affronté. Tu t’souviens? C’était\n"
	.string "dans le TUNNEL MERAZON!\p"
	.string "Tiens, prends ça! Et\n"
	.string "pardonne-moi!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Cette CT te sera plus utile qu’à\n"
	.string "moi.\p"
	.string "J’espère ne jamais te revoir!\n"
	.string "Ouahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Allez, viens! Prends ça et\n"
	.string "laisse-moi partir!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Un liquide bleu forme une\n"
	.string "spirale à l’intérieur d’un\p"
	.string "récipient en verre.\p"
	.string "“C’est un tourbillon reproduit\n"
	.string "artificiellement avec du vent.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Une balle rouge monte et descend\n"
	.string "à l’intérieur d’un récipient en\p"
	.string "verre.\p"
	.string "“C’est une expérience simulant\n"
	.string "une CASCADE avec la flottabilité\p"
	.string "de la balle.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "C’est un échantillon provenant\n"
	.string "du fond de l’océan.\p"
	.string "“Les débris de toutes formes de\n"
	.string "vie se sont au fur et à mesure\p"
	.string "amassés au fond de la mer,\n"
	.string "formant des couches\p"
	.string "sédimentaires.”\p"
	.string "“L’analyse de ces sédiments\n"
	.string "révèle le temps passé.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "C’est un échantillon de sable de\n"
	.string "plage.\p"
	.string "“Les roches des montagnes sont\n"
	.string "détrempées par les rivières, ce\p"
	.string "qui les rend friables et les\n"
	.string "décompose.”\p"
	.string "“Elles sont réduites en\n"
	.string "poussière et deviennent le sable\p"
	.string "des plages.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "DEVINETTE SUR LA MER 1 Pourquoi\n"
	.string "l’eau de mer est-elle bleue?\p"
	.string "Les rayons de lumière sont\n"
	.string "composés de nombreuses couleurs.\p"
	.string "La plupart d’entre eux perdent\n"
	.string "leur couleur lorsqu’ils\p"
	.string "traversent l’eau.\p"
	.string "Mais les rayons bleus, eux, sont\n"
	.string "réfléchis, rendant la mer bleue.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "DEVINETTE SUR LA MER 2 Pourquoi\n"
	.string "l’eau de mer est-elle salée?\p"
	.string "L’eau de mer contient du sel\n"
	.string "dissous sous forme d’ions sodium\p"
	.string "et chlorure.\p"
	.string "Ces ions proviennent des roches\n"
	.string "et la pluie les transporte dans\p"
	.string "la mer.\p"
	.string "La concentration en sel dissous\n"
	.string "rend la mer salée.$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "DEVINETTE SUR LA MER 3 Quelle\n"
	.string "est la plus vaste? La mer ou la\p"
	.string "terre?\p"
	.string "La mer couvre environ 70% de la\n"
	.string "planète et la terre, le reste.\p"
	.string "La mer est donc au moins deux\n"
	.string "fois plus vaste que la terre.$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "C’est un fossile à stries\n"
	.string "ondulées.\p"
	.string "“Le fond de l’océan est drainé\n"
	.string "par la marée.”\p"
	.string "“Le mouvement de l’eau de mer\n"
	.string "dessine des stries et des creux\p"
	.string "sur le sol.”\p"
	.string "“Si ce sol se fossilise, on\n"
	.string "parle d’ondulation.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Un engin étrange pivote sous un\n"
	.string "dôme en verre.\p"
	.string "Peut-être est-ce pour mesurer la\n"
	.string "profondeur de quelque chose…$"

