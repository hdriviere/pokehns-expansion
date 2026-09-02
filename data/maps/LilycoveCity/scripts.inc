LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "FLORA: Oh, hé? {PLAYER}{KUN},\n"
	.string "toi aussi tu fais tes achats?\p"
	.string "J’ai acheté tout un tas de\n"
	.string "POUPEES et de POSTERS.\p"
	.string "Bien sûr, j’ai aussi attrapé\n"
	.string "plein de POKéMON et je les\p"
	.string "entraîne  correctement aussi.\p"
	.string "En fait, j’aimerais plutôt\n"
	.string "savoir si toi, {PLAYER}{KUN}, tu\p"
	.string "dresses bien tes POKéMON.\p"
	.string "Je vais me battre contre toi\n"
	.string "pour que tu me montres tes\p"
	.string "POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "FLORA: Quoi? {PLAYER}{KUN}, tu\n"
	.string "n’avais pas dressé tes POKéMON?\p"
	.string "Ce n’est pas une très bonne\n"
	.string "performance pour un DRESSEUR…$"

LilycoveCity_Text_MayBattleMe:
	.string "FLORA: Viens te battre que je\n"
	.string "puisse voir ce que valent tes\p"
	.string "POKéMON!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "FLORA: Tes POKéMON ne pourront\n"
	.string "pas battre ceux que j’ai élevés,\p"
	.string "{PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Je me rappelle, {PLAYER}{KUN},\n"
	.string "la fois où on a combattu sur la\p"
	.string "ROUTE 103.\p"
	.string "Ce combat, {PLAYER}{KUN}, t’a\n"
	.string "permis de progresser, n’est-ce\p"
	.string "pas?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "FLORA: Je pense que je vais\n"
	.string "bientôt rentrer à BOURG-EN-VOL.\p"
	.string "J’ai attrapé un bon nombre de\n"
	.string "POKéMON, et mon POKéDEX se\p"
	.string "remplit, alors je vais montrer\n"
	.string "tout ça à mon papa.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, que vas-tu faire?\p"
	.string "Rassembler tous les BADGES et\n"
	.string "relever le défi de la LIGUE\p"
	.string "POKéMON?\p"
	.string "{PLAYER}{KUN}, pendant que tu\n"
	.string "rassembles les BADGES, je\p"
	.string "continue à remplir mon POKéDEX.\n"
	.string "J’aurai fini avant toi!\p"
	.string "A plus tard!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, que vas-tu faire?\p"
	.string "Vas-tu relever le défi de la\n"
	.string "LIGUE POKéMON?\p"
	.string "Ou vas-tu plutôt remplir ton\n"
	.string "POKéDEX?\p"
	.string "Tu as peut-être gagné le combat,\n"
	.string "mais je complèterai mon POKéDEX\p"
	.string "avant toi!\p"
	.string "A plus tard!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, que vas-tu faire?\p"
	.string "Vas-tu relever le défi de la\n"
	.string "ZONE DE COMBAT?\p"
	.string "Ou vas-tu plutôt remplir ton\n"
	.string "POKéDEX?\p"
	.string "Tu as peut-être gagné le combat,\n"
	.string "mais je complèterai mon POKéDEX\p"
	.string "avant toi!\p"
	.string "A plus tard!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRICE: Oh, hé, c’est {PLAYER}.\p"
	.string "Je fais une course pour mon\n"
	.string "papa. Non, je n’achète pas de\p"
	.string "POUPEE.\p"
	.string "En tout cas, ça fait un bout\n"
	.string "d’temps.\p"
	.string "On se fait un petit combat pour\n"
	.string "voir qui a le mieux dressé ses\p"
	.string "POKéMON?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRICE: Y a un problème? T’as pas\n"
	.string "confiance en toi?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRICE: Tu veux t’battre pour\n"
	.string "voir qui a le mieux dressé ses\p"
	.string "POKéMON?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRICE: Ouh, mais tu sais que je\n"
	.string "ne vais pas perdre contre toi,\p"
	.string "{PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Hum… T’as bien progressé.\p"
	.string "Je suis dégoûté! J’avais\n"
	.string "pourtant un avantage sur toi en\p"
	.string "tant que DRESSEUR.$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRICE: Je… Je compte rentrer à\n"
	.string "BOURG-EN-VOL.\p"
	.string "Tu sais, j’aide mon père à\n"
	.string "remplir son POKéDEX. Il commence\p"
	.string "à être bien garni, alors je\n"
	.string "devrais aller lui montrer.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, que vas-tu faire?\p"
	.string "Rassembler tous les BADGES et\n"
	.string "relever le défi de la LIGUE\p"
	.string "POKéMON?\p"
	.string "Je vais peut-être faire ça\n"
	.string "aussi…\p"
	.string "Enfin, de toute façon, il faut\n"
	.string "tenir bon!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, que vas-tu faire?\p"
	.string "Maintenant que tu es si robuste,\n"
	.string "tu vas relever le défi de la\p"
	.string "LIGUE POKéMON?\p"
	.string "Hé, même moi, si j’entraînais un\n"
	.string "peu plus mes POKéMON, je\p"
	.string "pourrais être plus fort que toi,\n"
	.string "{PLAYER}.\p"
	.string "Enfin, de toute façon, il faut\n"
	.string "tenir bon!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, que vas-tu faire?\p"
	.string "Relever le défi de la ZONE DE\n"
	.string "COMBAT?\p"
	.string "Ou terminer ton POKéDEX?\p"
	.string "Avec ta force, tu devrais\n"
	.string "envisager la ZONE DE COMBAT.\p"
	.string "Hé hé, si j'entraîne encore mes\n"
	.string "POKéMON, je deviendrai plus fort\p"
	.string "que toi, {PLAYER}.\p"
	.string "Je devrais peut-être aller à la\n"
	.string "ZONE DE COMBAT.\p"
	.string "Enfin bref, bon courage!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Hum, hum, hum…\p"
	.string "Aujourd’hui, on a ramené un plus\n"
	.string "gros butin dans notre PLANQUE\p"
	.string "secrète…\p"
	.string "Qu… Qui es-tu?! Je parlais tout\n"
	.string "seul!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Je suis juste un SBIRE, alors je\n"
	.string "ne sais pas ce que le CHEF\p"
	.string "pense…\p"
	.string "Mais en étant dans la TEAM AQUA,\n"
	.string "je vais réaliser de grandes\p"
	.string "choses.\p"
	.string "Qu… Qui es-tu?! Je parlais tout\n"
	.string "seul!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hé, toi!\p"
	.string "Ne va pas dans la caverne de la\n"
	.string "crique!\p"
	.string "Pourquoi? Mais parce que! Je\n"
	.string "suis adulte, tu n’as qu’à\p"
	.string "m’écouter!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Si le monde entier nous\n"
	.string "appartient, à nous la TEAM AQUA,\p"
	.string "ce sera aussi un endroit plus\n"
	.string "agréable pour les POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Là! WAILMER! Sortez de l’eau\n"
	.string "maintenant!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hum? Qu’est-ce que tu veux?\p"
	.string "Tu perturbes notre entraînement,\n"
	.string "alors tu pourrais pas déguerpir,\p"
	.string "par hasard?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Il y a une SALLE DE CONCOURS\n"
	.string "POKéMON dans cette ville.\p"
	.string "Ça veut dire qu’on peut y voir\n"
	.string "des POKéMON bien dressés venant\p"
	.string "des quatre coins du pays.\p"
	.string "Mon cœur déborde d’enthousiasme!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Tu as vu cette étrange caverne\n"
	.string "dans la crique, au bout de la\p"
	.string "ville?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Je vais apprendre de nouvelles\n"
	.string "capacités à mon POKéMON pour\p"
	.string "qu’il participe à un CONCOURS.\p"
	.string "Alors je vais aller voir\n"
	.string "l’EFFACEUR DE  CAPACITES, pour\p"
	.string "qu’il lui fasse oublier\n"
	.string "certaines CS.$"

LilycoveCity_Text_ImFromKanto:
	.string "Je viens de KANTO.\p"
	.string "La région de HOENN est très\n"
	.string "belle avec son eau et sa nature\p"
	.string "verdoyante.\p"
	.string "Hum? Attends une seconde…\p"
	.string "Y aurait-il des POKéMON rares\n"
	.string "qui ne vivent que dans cette\p"
	.string "zone?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "La TEAM AQUA entraîne ses\n"
	.string "WAILMER dans la crique.\p"
	.string "Nous, les MARINS, ça nous gêne!\n"
	.string "On ne peut pas aller en mer avec\p"
	.string "nos bateaux.$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Eh, t’es au courant?\p"
	.string "Quelqu’un a chassé la TEAM AQUA\n"
	.string "de la voie que nous empruntons!\p"
	.string "Les WAILMER ne sont plus dans la\n"
	.string "crique, alors on peut à nouveau\p"
	.string "sortir en mer.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Je faisais une petite sieste sur\n"
	.string "la plage, bercée par le bruit\p"
	.string "des vagues…\p"
	.string "quand quelqu’un m’a volé mon\n"
	.string "POKéMON!\p"
	.string "Qui est le ravisseur? La TEAM\n"
	.string "AQUA? Est-ce la TEAM AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Le POKéMON qui me manquait… Il\n"
	.string "est revenu sans que j’m’en\p"
	.string "aperçoive!$"

LilycoveCity_Text_ImArtDealer:
	.string "Je suis MARCHAND D’ART.\p"
	.string "J’achète et je vends des œuvres\n"
	.string "d’art, essentiellement des\p"
	.string "tableaux.\p"
	.string "J’ai entendu dire que le MUSEE,\n"
	.string "ici, exposait de magnifiques\p"
	.string "œuvres…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Même quand on vieillit et qu’on\n"
	.string "devient tout ridé, la mer semble\p"
	.string "toujours jeune  grâce à l’éclat\n"
	.string "radieux de la vie…\p"
	.string "Oh, oh, oh…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Il y a soixante ans, mon mari\n"
	.string "m’a demandée en mariage ici. La\p"
	.string "mer est toujours aussi belle.\p"
	.string "Aaaaaaaaaaaah…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hum, tu as entendu parler de\n"
	.string "l’étrange caverne dans cette\p"
	.string "crique?\p"
	.string "Il s’agissait d’une cavité\n"
	.string "naturelle, mais c’était avant\p"
	.string "que la TEAM AQUA ne vienne la\n"
	.string "restaurer.\p"
	.string "Ils se présentent comme les\n"
	.string "“amoureux de la nature”!\p"
	.string "Mais il y a une grande\n"
	.string "différence entre ce qu’ils\p"
	.string "disent et ce qu’ils font!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Cette caverne dans la crique…\p"
	.string "Je n’avais pas remarqué, mais\n"
	.string "elle est complètement vide\p"
	.string "maintenant.\p"
	.string "Ces vauriens de la TEAM AQUA,\n"
	.string "ils ont dû partir pour de bon.$"

LilycoveCity_Text_CitySign:
	.string "NENUCRIQUE\p"
	.string "“Là où la terre s’arrête, là où\n"
	.string "la mer commence.”$"

LilycoveCity_Text_ContestHallSign:
	.string "CONCOURS POKéMON “Participez aux\n"
	.string "CONCOURS avec vos amis!”$"

LilycoveCity_Text_MotelSign:
	.string "HOTEL CRIQUE CRACK\p"
	.string "“Souvenez-vous de nous comme les\n"
	.string "cracks de la crique.”$"

LilycoveCity_Text_MuseumSign:
	.string "MUSEE NENUCRIQUE\p"
	.string "“Exposition de la collection de\n"
	.string "chefs-d’œuvre POKéMON.”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSEE NENUCRIQUE\p"
	.string "“Exposition de la collection\n"
	.string "POKéMON de {PLAYER}.”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "EMBARCADERE DE NENUCRIQUE\p"
	.string "“Le ferry LE MARINA est en\n"
	.string "construction à POIVRESSEL.”\p"
	.string "“Il entrera bientôt en service.”$"

LilycoveCity_Text_HarborSign:
	.string "EMBARCADERE DE NENUCRIQUE\p"
	.string "“Profitez d’une merveilleuse\n"
	.string "croisière sur LE MARINA.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "FAN CLUB DES DRESSEURS POKéMON\p"
	.string "Des noms de DRESSEURS parsèment\n"
	.string "le panneau…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "CENTRE COMMERCIAL NENUCRIQUE\p"
	.string "“Marchandises à profusion et\n"
	.string "débordement d’enthousiasme!”\p"
	.string "“L’endroit idéal pour trouver\n"
	.string "tout ce qu’il vous faut!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "MAISON DE L’EFFACEUR DE\n"
	.string "CAPACITES\p"
	.string "“Toutes les capacités de POKéMON\n"
	.string "non désirées sont oubliées!”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Tu connais cet appareil appelé\n"
	.string "MIXEUR?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Il faut s’y mettre à plusieurs\n"
	.string "pour que ça tourne plus vite.\p"
	.string "J’ai entendu dire que plus ça\n"
	.string "tourne vite, meilleurs sont les\p"
	.string "{POKEBLOCK}S.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "On l’utilise pour fabriquer une\n"
	.string "sorte de bonbon appelé\p"
	.string "{POKEBLOCK}.\p"
	.string "Si tu donnes un bon {POKEBLOCK}\n"
	.string "à un POKéMON, sa condition va\p"
	.string "s’améliorer.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "J’ai entendu dire qu’il y aurait\n"
	.string "une tour au-delà de la mer.\p"
	.string "Je crois qu’on l’appelle le\n"
	.string "PILIER CELESTE.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "J’ai vu cette tour immense\n"
	.string "quelque part près du CHENAL 131.\p"
	.string "Est-ce possible?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "On vient juste d’arriver ici\n"
	.string "pour passer notre lune de miel.\p"
	.string "Et on a vu un POKéMON du type\n"
	.string "DRAGON voler très haut dans le\p"
	.string "ciel.\p"
	.string "Il y a vraiment des POKéMON\n"
	.string "comme ça à HOENN?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Pour notre lune de miel, on a\n"
	.string "l’intention de voir autant de\p"
	.string "POKéMON que possible.\p"
	.string "Alors imagine un peu ce qu’on a\n"
	.string "pu ressentir en voyant ce\p"
	.string "POKéMON rare.\p"
	.string "Il n’y a pas de mots pour\n"
	.string "l’expliquer!$"

