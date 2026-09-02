BattleFrontier_ScottsHouse_hns_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott_hns::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems_hns::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols_hns::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield_hns
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull_hns::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry_hns::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment_hns::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment_hns::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield_hns::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield_hns::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield_hns
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield_hns
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints_hns::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier_hns::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints_hns::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints_hns::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints_hns::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint_hns::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints_hns::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayNorth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwaySouth_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayEast_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_Scott_hnsFaceAwayWest_hns::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier_hns:
	.string "SCOTT: Bonjour toi! Bienvenue!\n"
	.string "Désolé, je sais que c’est un peu\p"
	.string "petit.\p"
	.string "Je suis content de t’accueillir\n"
	.string "dans la ZONE DE COMBAT,\p"
	.string "{PLAYER}{KUN}.\p"
	.string "Mon rêve s’est enfin réalisé! Ça\n"
	.string "m’a pris des années et beaucoup\p"
	.string "d’efforts, mais j’y suis enfin\n"
	.string "parvenu.$"

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal_hns:
	.string "Ce fut un très long voyage…\p"
	.string "J’ai pris la route pour me\n"
	.string "mettre à la recherche de\p"
	.string "DRESSEURS forts.\p"
	.string "J’ai bâti ce rêve au prix de\n"
	.string "tant d’efforts et de sacrifices!$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing_hns:
	.string "Mais tout ça, c’est du passé! Je\n"
	.string "ne vais pas m’étendre sur le\p"
	.string "sujet!\p"
	.string "J’espère que tu vas pouvoir te\n"
	.string "battre jusqu’à plus soif, ici!\p"
	.string "{PLAYER}{KUN}, prends ça. C’est\n"
	.string "en souvenir de toutes les fois\p"
	.string "où nos chemins se sont croisés.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints_hns:
	.string "{PLAYER} obtient {STR_VAR_1}\n"
	.string "POINTS DE COMBAT.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints_hns:
	.string "SCOTT: Ton nombre de POINTS DE\n"
	.string "COMBAT est inscrit sur ton PASSE\p"
	.string "ZONE.\p"
	.string "Plus tu auras de succès dans la\n"
	.string "ZONE DE COMBAT, plus tu\p"
	.string "accumuleras de POINTS DE COMBAT.\p"
	.string "Utilise-les comme bon te semble.\n"
	.string "Tu peux les échanger contre des\p"
	.string "objets.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings_hns:
	.string "Je vais te suivre de près. Je\n"
	.string "suis sûr que beaucoup de\p"
	.string "réussites t’attendent!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers_hns:
	.string "SCOTT: Chaque DRESSEUR est\n"
	.string "unique. Chacun a sa propre\p"
	.string "histoire.\p"
	.string "Mais au combat, ils doivent\n"
	.string "laisser tout ça derrière eux!\p"
	.string "Ils sont tous DRESSEURS!\p"
	.string "J’aime cette pureté. Face au\n"
	.string "combat, les DRESSEURS sont tous\p"
	.string "égaux.\p"
	.string "C’est pourquoi je voyage à la\n"
	.string "recherche de DRESSEURS dignes de\p"
	.string "ce nom et que je les invite ici.$"

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain_hns:
	.string "SCOTT: As-tu déjà rencontré un\n"
	.string "des MENEURS DE ZONE?\p"
	.string "Encore mieux, as-tu déjà obtenu\n"
	.string "des symboles?\p"
	.string "Les MENEURS DE ZONE ont été\n"
	.string "triés sur le volet. Ce sont les\p"
	.string "meilleurs!\p"
	.string "Mais je suis sûr que tu serais\n"
	.string "capable de leur faire peur!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier_hns:
	.string "SCOTT: Tu ne t’entraînes pas que\n"
	.string "pour les combats, n’est-ce pas?\p"
	.string "Il me semble que tu travailles\n"
	.string "aussi à un POKéDEX.\p"
	.string "Eh bien, devine quoi!\p"
	.string "Il y a des POKéMON sauvages dans\n"
	.string "la ZONE DE COMBAT… Ouvre les\p"
	.string "yeux!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols_hns:
	.string "SCOTT: Tout se passe bien dans\n"
	.string "la ZONE DE COMBAT?\p"
	.string "Attends un instant… Oh!\p"
	.string "Ton PASSE ZONE! Tu as tous les\n"
	.string "symboles argent!\p"
	.string "C’est impressionnant! Mais ça ne\n"
	.string "me surprend pas vraiment!\p"
	.string "D’ordinaire, je ne fais pas ce\n"
	.string "genre de choses, mais là c’est\p"
	.string "exceptionnel!\p"
	.string "Je veux que tu prennes ça. Je\n"
	.string "suis sûr que tu en feras bon\p"
	.string "usage.$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols_hns:
	.string "SCOTT: J’espère que ton séjour\n"
	.string "dans la ZONE DE COMBAT se passe\p"
	.string "bien.\p"
	.string "Mais, attends… Alors là, je n’en\n"
	.string "crois pas mes yeux!\p"
	.string "Ton PASSE ZONE! Tu as obtenu\n"
	.string "tous les symboles or!\p"
	.string "C’est prodigieux! Tu es plus\n"
	.string "incroyable que ce que je\p"
	.string "pensais!\p"
	.string "… … … … … …\p"
	.string "{PLAYER}, tu dois accepter ça!\p"
	.string "Je suis sûr que tu sauras\n"
	.string "apprécier ce cadeau à sa juste\p"
	.string "valeur!$"

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere_hns:
	.string "Je sais reconnaître un bon\n"
	.string "DRESSEUR quand j’en vois un.\p"
	.string "Je me félicite d’avoir décidé de\n"
	.string "t’inviter ici!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed_hns:
	.string "La POCHE BAIES a l’air pleine.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow_hns:
	.string "SCOTT: Oh, on m’a raconté tes\n"
	.string "exploits à la TOUR DE COMBAT! Tu\p"
	.string "as battu plus de 50 DRESSEURS à\n"
	.string "la suite?\p"
	.string "C’est fantastique! Je veux que\n"
	.string "tu acceptes ça!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow_hns:
	.string "SCOTT: Oh! Tu sais, on m’a parlé\n"
	.string "de tes exploits à la TOUR DE\p"
	.string "COMBAT! Tu as battu plus de 100\n"
	.string "DRESSEURS à la suite?\p"
	.string "C’est incroyable, spectaculaire!\n"
	.string "Il faut que tu prennes ça!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings_hns:
	.string "Je me demande bien quelles\n"
	.string "surprises tu me réserves encore!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater_hns:
	.string "Eh bien si tu n’as pas de place\n"
	.string "pour l’instant, reviens plus\p"
	.string "tard.$"

