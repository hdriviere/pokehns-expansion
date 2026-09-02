BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "DOME DE COMBAT “La voie toute\n"
	.string "tracée vers la célébrité!”$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "USINE DE COMBAT “Nos POKéMON\n"
	.string "sont les plus forts!”$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "REPTILE DE COMBAT “Choisissez un\n"
	.string "des trois chemins!”$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Voici la TOUR DE COMBAT.\p"
	.string "Les DRESSEURS y amènent leurs\n"
	.string "meilleurs POKéMON pour\p"
	.string "participer à des matchs\n"
	.string "éliminatoires.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Bonjour, vous venez pour le\n"
	.string "ferry? Puis-je voir votre PASSE\p"
	.string "BATEAU?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} n'a pas de PASSE\n"
	.string "BATEAU…\p"
	.string "Je suis absolument désolée.\p"
	.string "Il vous faut un PASSE pour\n"
	.string "embarquer à bord du ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} montre son PASSE\n"
	.string "BATEAU.\p"
	.string "Parfait! Vous pouvez entrer!\p"
	.string "Où voulez-vous aller?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "POIVRESSEL? C'est parti!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "NENUCRIQUE? C'est parti!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Revenez nous voir une autre\n"
	.string "fois!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Veuillez embarquer à bord du\n"
	.string "ferry et attendre le départ.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Alors, où voulez-vous aller?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Je suis meilleur que tous mes\n"
	.string "copains. Mais ici… Je suis nul!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Je veux aller à la TOUR DE\n"
	.string "COMBAT, mais je ne la trouve\p"
	.string "pas. Pourtant, j’ai une carte de\n"
	.string "la ZONE DE COMBAT.\p"
	.string "Cet endroit est vraiment\n"
	.string "immense!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Mon intention était de relever\n"
	.string "un défi dès mon arrivée ici.\p"
	.string "Mais en chemin, j’ai eu le mal\n"
	.string "de mer… Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Tout le monde ne peut pas venir\n"
	.string "ici, tu sais.\p"
	.string "Seuls les DRESSEURS dont le\n"
	.string "talent a été reconnu sont ici.\p"
	.string "Beaucoup de DRESSEURS n’ont\n"
	.string "jamais entendu parler de la ZONE\p"
	.string "DE COMBAT.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Dis…\p"
	.string "Tu penses qu’on peut participer\n"
	.string "même si on n’a pas de POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Heu… Ben, c’est ce qu’on m’a\n"
	.string "dit.\p"
	.string "Enfin, je crois…\p"
	.string "Et tu te souviens de ce que m’a\n"
	.string "dit le colosse?\p"
	.string "Il m’a dit qu’il me prêterait\n"
	.string "des POKéMON!$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "C’est l’USINE DE COMBAT. Tu peux\n"
	.string "y louer des POKéMON très forts.\p"
	.string "Mais au fait… Je me demande qui\n"
	.string "élève ces POKéMON de location!?!$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "J’ai peur d’aller au REPTILE DE\n"
	.string "COMBAT à cause de SEVIPER…\p"
	.string "Mais je ne suis pas venue ici\n"
	.string "pour rien! Je vais me battre! …\p"
	.string "J’ai peur…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Jouons à pierre, papier,\n"
	.string "ciseaux! Un, deux, trois!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Oui! J’ai gagné! Je vais relever\n"
	.string "le défi du REPTILE DE COMBAT!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, non… J’ai perdu.\p"
	.string "Ce n’est pas mon jour de chance.\n"
	.string "Je vais attendre demain pour\p"
	.string "relever le défi du REPTILE DE\n"
	.string "COMBAT.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Je suis persuadé que je suis la\n"
	.string "seule personne ici qui préfère\p"
	.string "la pêche aux combats.\p"
	.string "Comment? Il n’y a rien à pêcher\n"
	.string "ici? C’est dommage, c’est un bel\p"
	.string "endroit…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Aujourd’hui, je n’arrêterai de\n"
	.string "combattre que quand j’aurai un\p"
	.string "symbole!$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Tu veux relever le défi du DOME\n"
	.string "DE COMBAT?\p"
	.string "Je te souhaite bonne chance. Ce\n"
	.string "serait amusant, si l’on se\p"
	.string "retrouvait face à face lors d’un\n"
	.string "combat.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Papy, par ici! Le DOME DE COMBAT\n"
	.string "est là! Vas-y, papy!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "C’est donc ça, le DOME DE\n"
	.string "COMBAT? Aucun GENTLEMAN ne\p"
	.string "pourra me battre!\p"
	.string "Mais où est l’entrée?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Il n’y a pas si longtemps, il\n"
	.string "n’y avait rien à cet endroit.\p"
	.string "Mais maintenant, regarde!\n"
	.string "Incroyable! Il faut que j’emmène\p"
	.string "ma mère ici.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Je suis enfin arrivée à la ZONE\n"
	.string "DE COMBAT!\p"
	.string "Mon physique avantageux et ma\n"
	.string "technique me feront sûrement\p"
	.string "gagner!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Miam, miam…\p"
	.string "On dirait que tout le monde est\n"
	.string "très fort ici.\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Miam, miam…\p"
	.string "Il y a un certain temps, j’ai\n"
	.string "rencontré cette femme au REPTILE\p"
	.string "DE COMBAT.\p"
	.string "Elle avait un regard effrayant,\n"
	.string "ça m’a fichu la frousse.\p"
	.string "Miam, miam…\p"
	.string "Elle m’a hurlé dessus: “Arrête\n"
	.string "de manger!” et s’est mise à\p"
	.string "rire!\p"
	.string "J’en ai eu la chair de poule…\n"
	.string "J’entends encore son rire…\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Non mais, écoute ce que tu dis!\n"
	.string "Ça ne veut rien dire, ça!\p"
	.string "Lors du dernier match, il m’a\n"
	.string "regardée et j’ai vu des\p"
	.string "étincelles dans ses yeux!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Quoi??? Pfft!\p"
	.string "Si je n’avais pas été assis à\n"
	.string "côté de toi, il ne t’aurait même\p"
	.string "pas regardée!\p"
	.string "Ce sont mes encouragements qui\n"
	.string "ont attiré le regard de la STAR\p"
	.string "DU DOME!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, chut! Mettez-la un peu en\n"
	.string "sourdine!\p"
	.string "Vous, les fans, vous devriez\n"
	.string "vous contenter des CHAMPION\p"
	.string "D’ARENE!\p"
	.string "La STAR DU DOME est à moi! C’est\n"
	.string "mon idole!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Ces gens qui se disputent\n"
	.string "là-bas…\p"
	.string "C’est dur à croire, mais ils\n"
	.string "étaient DRESSEURS, avant. Ils\p"
	.string "étaient bons.\p"
	.string "Ils avaient une force incroyable\n"
	.string "et ils étaient même célèbres!\p"
	.string "Mais ils se sont fait écraser\n"
	.string "par un DRESSEUR lors d’un\p"
	.string "tournoi.\p"
	.string "Leur défaite a été telle qu’ils\n"
	.string "ont été subjugués par lui.\p"
	.string "Maintenant, ce sont des fans.\n"
	.string "Ils vont au DOME DE COMBAT tous\p"
	.string "les jours pour l’encourager.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Il paraît que quelqu’un a vu un\n"
	.string "POKéMON avec une queue\p"
	.string "incroyablement longue dans la\n"
	.string "ZONE DE COMBAT.\p"
	.string "Il doit être adorable…\p"
	.string "Les défis peuvent bien attendre!\n"
	.string "Je vais tenter de trouver cette\p"
	.string "charmante créature!$"

