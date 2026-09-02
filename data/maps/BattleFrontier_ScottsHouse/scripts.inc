BattleFrontier_ScottsHouse_MapScripts::
	.byte 0

BattleFrontier_ScottsHouse_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_4, BattleFrontier_ScottsHouse_EventScript_GivenBerry
	goto_if_set FLAG_TEMP_3, BattleFrontier_ScottsHouse_EventScript_GivenShield
	goto_if_set FLAG_TEMP_2, BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveItems
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveItems::
	goto_if_unset FLAG_SCOTT_GIVES_BATTLE_POINTS, BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier
	goto_if_unset FLAG_COLLECTED_ALL_SILVER_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols
	goto_if_unset FLAG_COLLECTED_ALL_GOLD_SYMBOLS, BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols
	goto BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveShield::
	goto_if_unset FLAG_RECEIVED_SILVER_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield
	goto_if_unset FLAG_RECEIVED_GOLD_SHIELD, BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_CheckSilverSymbols::
	goto_if_unset FLAG_SYS_TOWER_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_SILVER, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols, MSGBOX_DEFAULT
	giveitem ITEM_LANSAT_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_SILVER_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGoldSymbols::
	goto_if_unset FLAG_SYS_TOWER_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_DOME_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PALACE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_ARENA_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_FACTORY_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PIKE_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	goto_if_unset FLAG_SYS_PYRAMID_GOLD, BattleFrontier_ScottsHouse_EventScript_CheckGiveShield
	msgbox BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols, MSGBOX_DEFAULT
	giveitem ITEM_STARF_BERRY
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_BerryPocketFull
	setflag FLAG_COLLECTED_ALL_GOLD_SYMBOLS
	setflag FLAG_TEMP_4
	release
	end

BattleFrontier_ScottsHouse_EventScript_BerryPocketFull::
	msgbox BattleFrontier_ScottsHouse_Text_BerryPocketStuffed, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenBerry::
	msgbox BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_RandomComment::
	random 3
	goto_if_eq VAR_RESULT, 1, BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment
	goto_if_eq VAR_RESULT, 2, BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment
	msgbox BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_FrontierBrainComment::
	msgbox BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_ArtisanCaveComment::
	msgbox BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveSilverShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 50, BattleFrontier_ScottsHouse_EventScript_GiveSilverShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveSilverShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_SILVER_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_SILVER_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_NoRoomForShield::
	msgbox BattleFrontier_ScottsHouse_Text_ComeBackForThisLater, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_GivenShield::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_CheckGiveGoldShield::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_OPEN
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ge VAR_RESULT, 100, BattleFrontier_ScottsHouse_EventScript_GiveGoldShield
	goto BattleFrontier_ScottsHouse_EventScript_RandomComment
	end

BattleFrontier_ScottsHouse_EventScript_GiveGoldShield::
	msgbox BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow, MSGBOX_DEFAULT
	givedecoration DECOR_GOLD_SHIELD
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ScottsHouse_EventScript_NoRoomForShield
	setflag FLAG_RECEIVED_GOLD_SHIELD
	setflag FLAG_TEMP_3
	goto BattleFrontier_ScottsHouse_EventScript_GivenShield
	end

BattleFrontier_ScottsHouse_EventScript_GivenBattlePoints::
	msgbox BattleFrontier_ScottsHouse_Text_ExpectingGreatThings, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ScottsHouse_EventScript_WelcomeToFrontier::
	msgbox BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest
	msgbox BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing, MSGBOX_DEFAULT
	goto_if_eq VAR_SCOTT_STATE, 13, BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 9, BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints
	goto_if_ge VAR_SCOTT_STATE, 6, BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints
	goto BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end

BattleFrontier_ScottsHouse_EventScript_Give4BattlePoints::
	buffernumberstring STR_VAR_1, 4
	setvar VAR_0x8004, 4
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give3BattlePoints::
	buffernumberstring STR_VAR_1, 3
	setvar VAR_0x8004, 3
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give2BattlePoints::
	buffernumberstring STR_VAR_1, 2
	setvar VAR_0x8004, 2
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint::
	buffernumberstring STR_VAR_1, 1
	setvar VAR_0x8004, 1
	goto BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints
	end

BattleFrontier_ScottsHouse_EventScript_GiveBattlePoints::
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox BattleFrontier_ScottsHouse_Text_ExplainBattlePoints, MSGBOX_DEFAULT
	setflag FLAG_SCOTT_GIVES_BATTLE_POINTS
	setflag FLAG_TEMP_2
	release
	end

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayNorth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwaySouth::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayEast::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BattleFrontier_ScottsHouse_EventScript_ScottFaceAwayWest::
	applymovement LOCALID_SCOTTS_HOUSE_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BattleFrontier_ScottsHouse_Text_WelcomeToBattleFrontier:
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

BattleFrontier_ScottsHouse_Text_HowMuchEffortItTookToMakeReal:
	.string "Ce fut un très long voyage…\p"
	.string "J’ai pris la route pour me\n"
	.string "mettre à la recherche de\p"
	.string "DRESSEURS forts.\p"
	.string "J’ai bâti ce rêve au prix de\n"
	.string "tant d’efforts et de sacrifices!$"

BattleFrontier_ScottsHouse_Text_HaveThisAsMementoOfOurPathsCrossing:
	.string "Mais tout ça, c’est du passé! Je\n"
	.string "ne vais pas m’étendre sur le\p"
	.string "sujet!\p"
	.string "J’espère que tu vas pouvoir te\n"
	.string "battre jusqu’à plus soif, ici!\p"
	.string "{PLAYER}{KUN}, prends ça. C’est\n"
	.string "en souvenir de toutes les fois\p"
	.string "où nos chemins se sont croisés.$"

BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints:
	.string "{PLAYER} obtient {STR_VAR_1}\n"
	.string "POINT(S) DE COMBAT.$"

BattleFrontier_ScottsHouse_Text_ExplainBattlePoints:
	.string "SCOTT: Ton nombre de POINTS DE\n"
	.string "COMBAT est inscrit sur ton PASSE\p"
	.string "ZONE.\p"
	.string "Plus tu auras de succès dans la\n"
	.string "ZONE DE COMBAT, plus tu\p"
	.string "accumuleras de POINTS DE COMBAT.\p"
	.string "Utilise-les comme bon te semble.\n"
	.string "Tu peux les échanger contre des\p"
	.string "objets.$"

BattleFrontier_ScottsHouse_Text_ExpectingGreatThings:
	.string "Je vais te suivre de près. Je\n"
	.string "suis sûr que beaucoup de\p"
	.string "réussites t’attendent!$"

BattleFrontier_ScottsHouse_Text_WhyIGoSeekingTrainers:
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

BattleFrontier_ScottsHouse_Text_HaveYouMetFrontierBrain:
	.string "SCOTT: As-tu déjà rencontré un\n"
	.string "des MENEURS DE ZONE?\p"
	.string "Encore mieux, as-tu déjà obtenu\n"
	.string "des symboles?\p"
	.string "Les MENEURS DE ZONE ont été\n"
	.string "triés sur le volet. Ce sont les\p"
	.string "meilleurs!\p"
	.string "Mais je suis sûr que tu serais\n"
	.string "capable de leur faire peur!$"

BattleFrontier_ScottsHouse_Text_MayFindWildMonsInFrontier:
	.string "SCOTT: Tu ne t’entraînes pas que\n"
	.string "pour les combats, n’est-ce pas?\p"
	.string "Il me semble que tu travailles\n"
	.string "aussi à un POKéDEX.\p"
	.string "Eh bien, devine quoi!\p"
	.string "Il y a des POKéMON sauvages dans\n"
	.string "la ZONE DE COMBAT… Ouvre les\p"
	.string "yeux!$"

BattleFrontier_ScottsHouse_Text_YouveCollectedAllSilverSymbols:
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

BattleFrontier_ScottsHouse_Text_YouveCollectedAllGoldSymbols:
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

BattleFrontier_ScottsHouse_Text_SoGladIBroughtYouHere:
	.string "Je sais reconnaître un bon\n"
	.string "DRESSEUR quand j’en vois un.\p"
	.string "Je me félicite d’avoir décidé de\n"
	.string "t’inviter ici!$"

BattleFrontier_ScottsHouse_Text_BerryPocketStuffed:
	.string "La POCHE BAIES a l’air pleine.$"

BattleFrontier_ScottsHouse_Text_Beat50TrainersInARow:
	.string "SCOTT: Oh, on m’a raconté tes\n"
	.string "exploits à la TOUR DE COMBAT! Tu\p"
	.string "as battu plus de 50 DRESSEURS à\n"
	.string "la suite?\p"
	.string "C’est fantastique! Je veux que\n"
	.string "tu acceptes ça!$"

BattleFrontier_ScottsHouse_Text_Beat100TrainersInARow:
	.string "SCOTT: Oh! Tu sais, on m’a parlé\n"
	.string "de tes exploits à la TOUR DE\p"
	.string "COMBAT! Tu as battu plus de 100\n"
	.string "DRESSEURS à la suite?\p"
	.string "C’est incroyable, spectaculaire!\n"
	.string "Il faut que tu prennes ça!$"

BattleFrontier_ScottsHouse_Text_ExpectingToHearEvenGreaterThings:
	.string "Je me demande bien quelles\n"
	.string "surprises tu me réserves encore!$"

BattleFrontier_ScottsHouse_Text_ComeBackForThisLater:
	.string "Eh bien si tu n’as pas de place\n"
	.string "pour l’instant, reviens plus\p"
	.string "tard.$"

