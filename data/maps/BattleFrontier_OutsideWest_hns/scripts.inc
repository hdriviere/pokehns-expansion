BattleFrontier_OutsideWest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition_hns
	.byte 0

BattleFrontier_OutsideWest_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_EventScript_Sailor_hns::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_AsYouLike_hns
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	hideobjectat LOCALID_BATTLE_FRONTIER_SAILOR_HNS, MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS
	setvar VAR_0x8004, LOCALID_FARAWAY_BATTLE_FRONTIER_HNS_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_OLIVINE_CITY_PORT_INSIDE_HNS, 8, 16
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_AsYouLike_hns::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign_hns, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2_hns::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1_hns::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_Maniac2_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hns::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns::
	return

BattleFrontier_OutsideWest_EventScript_Girl_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass_hns::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM_hns::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2_hns::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1_hns::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2_hns::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF_hns::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign_hns:
	.string "DOME DE COMBAT “La voie toute\n"
	.string "tracée vers la célébrité!”$"

BattleFrontier_OutsideWest_Text_BattleFactorySign_hns:
	.string "USINE DE COMBAT “Nos POKéMON\n"
	.string "sont les plus forts!”$"

BattleFrontier_OutsideWest_Text_BattlePikeSign_hns:
	.string "REPTILE DE COMBAT “Choisissez un\n"
	.string "des trois chemins!”$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns:
	.string "Voici la TOUR DE COMBAT.\p"
	.string "Les DRESSEURS y amènent leurs\n"
	.string "meilleurs POKéMON pour\p"
	.string "participer à des matchs\n"
	.string "éliminatoires.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket_hns:
	.string "Bonjour, vous prenez le ferry?\n"
	.string "Puis-je voir votre PASSE BATEAU?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard_hns:
	.string "{PLAYER} n'a pas le PASSE\n"
	.string "BATEAU...\p"
	.string "Je suis vraiment désolé.\p"
	.string "Il vous faut un PASSE BATEAU\n"
	.string "pour monter à bord.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo_hns:
	.string "{PLAYER} montre le PASSE BATEAU.\p"
	.string "Parfait! C'est tout ce qu'il\n"
	.string "faut!\p"
	.string "Où souhaitez-vous aller?$"

BattleFrontier_OutsideWest_Text_SlateportItIs_hns:
	.string "En route pour POIVRESSEL!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs_hns:
	.string "En route pour NÉNUCRIQUE!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime_hns:
	.string "Reprenez le bateau avec nous une\n"
	.string "autre fois!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry_hns:
	.string "Montez à bord du ferry et\n"
	.string "attendez le départ.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo_hns:
	.string "Alors, où souhaitez-vous aller?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns:
	.string "Je suis meilleur que tous mes\n"
	.string "copains. Mais ici… Je suis nul!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns:
	.string "Je veux aller à la TOUR DE\n"
	.string "COMBAT, mais je ne la trouve\p"
	.string "pas. Pourtant, j’ai une carte de\n"
	.string "la ZONE DE COMBAT.\p"
	.string "Cet endroit est vraiment\n"
	.string "immense!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns:
	.string "Mon intention était de relever\n"
	.string "un défi dès mon arrivée ici.\p"
	.string "Mais en chemin, j’ai eu le mal\n"
	.string "de mer… Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns:
	.string "Tout le monde ne peut pas venir\n"
	.string "ici, tu sais.\p"
	.string "Seuls les DRESSEURS dont le\n"
	.string "talent a été reconnu sont ici.\p"
	.string "Beaucoup de DRESSEURS n’ont\n"
	.string "jamais entendu parler de la ZONE\p"
	.string "DE COMBAT.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns:
	.string "Dis…\p"
	.string "Tu penses qu’on peut participer\n"
	.string "même si on n’a pas de POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns:
	.string "Heu… Ben, c’est ce qu’on m’a\n"
	.string "dit.\p"
	.string "Enfin, je crois…\p"
	.string "Et tu te souviens de ce que m’a\n"
	.string "dit le colosse?\p"
	.string "Il m’a dit qu’il me prêterait\n"
	.string "des POKéMON!$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns:
	.string "C’est l’USINE DE COMBAT. Tu peux\n"
	.string "y louer des POKéMON très forts.\p"
	.string "Mais au fait… Je me demande qui\n"
	.string "élève ces POKéMON de location!?!$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns:
	.string "J’ai peur d’aller au REPTILE DE\n"
	.string "COMBAT à cause de SEVIPER…\p"
	.string "Mais je ne suis pas venue ici\n"
	.string "pour rien! Je vais me battre! …\p"
	.string "J’ai peur…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns:
	.string "Jouons à pierre, papier,\n"
	.string "ciseaux! Un, deux, trois!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns:
	.string "Oui! J’ai gagné! Je vais relever\n"
	.string "le défi du REPTILE DE COMBAT!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns:
	.string "Oh, non… J’ai perdu.\p"
	.string "Ce n’est pas mon jour de chance.\n"
	.string "Je vais attendre demain pour\p"
	.string "relever le défi du REPTILE DE\n"
	.string "COMBAT.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns:
	.string "Je suis persuadé que je suis la\n"
	.string "seule personne ici qui préfère\p"
	.string "la pêche aux combats.\p"
	.string "Comment? Il n’y a rien à pêcher\n"
	.string "ici? C’est dommage, c’est un bel\p"
	.string "endroit…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns:
	.string "Aujourd’hui, je n’arrêterai de\n"
	.string "combattre que quand j’aurai un\p"
	.string "symbole!$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns:
	.string "Tu veux relever le défi du DOME\n"
	.string "DE COMBAT?\p"
	.string "Je te souhaite bonne chance. Ce\n"
	.string "serait amusant, si l’on se\p"
	.string "retrouvait face à face lors d’un\n"
	.string "combat.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns:
	.string "Papy, par ici! Le DOME DE COMBAT\n"
	.string "est là! Vas-y, papy!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns:
	.string "C’est donc ça, le DOME DE\n"
	.string "COMBAT? Aucun GENTLEMAN ne\p"
	.string "pourra me battre!\p"
	.string "Mais où est l’entrée?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns:
	.string "Il n’y a pas si longtemps, il\n"
	.string "n’y avait rien à cet endroit.\p"
	.string "Mais maintenant, regarde!\n"
	.string "Incroyable! Il faut que j’emmène\p"
	.string "ma mère ici.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns:
	.string "Je suis enfin arrivée à la ZONE\n"
	.string "DE COMBAT!\p"
	.string "Mon physique avantageux et ma\n"
	.string "technique me feront sûrement\p"
	.string "gagner!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns:
	.string "Miam, miam…\p"
	.string "On dirait que tout le monde est\n"
	.string "très fort ici.\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns:
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

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns:
	.string "Non mais, écoute ce que tu dis!\n"
	.string "Ça ne veut rien dire, ça!\p"
	.string "Lors du dernier match, il m’a\n"
	.string "regardée et j’ai vu des\p"
	.string "étincelles dans ses yeux!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns:
	.string "Quoi??? Pfft!\p"
	.string "Si je n’avais pas été assis à\n"
	.string "côté de toi, il ne t’aurait même\p"
	.string "pas regardée!\p"
	.string "Ce sont mes encouragements qui\n"
	.string "ont attiré le regard de la STAR\p"
	.string "DU DOME!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns:
	.string "Oh, chut! Mettez-la un peu en\n"
	.string "sourdine!\p"
	.string "Vous, les fans, vous devriez\n"
	.string "vous contenter des CHAMPION\p"
	.string "D’ARENE!\p"
	.string "La STAR DU DOME est à moi! C’est\n"
	.string "mon idole!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns:
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

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns:
	.string "Il paraît que quelqu’un a vu un\n"
	.string "POKéMON avec une queue\p"
	.string "incroyablement longue dans la\n"
	.string "ZONE DE COMBAT.\p"
	.string "Il doit être adorable…\p"
	.string "Les défis peuvent bien attendre!\n"
	.string "Je vais tenter de trouver cette\p"
	.string "charmante créature!$"

