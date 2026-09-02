MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition:
	call_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
	call_if_eq VAR_MOSSDEEP_SPACE_CENTER_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians::
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_RICH_BOY, 3, 2
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_GENTLEMAN, 1, 3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts::
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_6, 11, 2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_7, 15, 2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_5, 13, 4
	return

MossdeepCity_SpaceCenter_2F_OnFrame:
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts::
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_PlayerExit:
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_6
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_7
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_5
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal::
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma::
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
	release
	end

@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt7::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt5::
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Tabitha::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Maxie::
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_Steven::
	lockall
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_NOT_EFFECTIVE
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
	applymovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth::
	applymovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_StevenFight:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth:
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt

MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle::
	multi_2_vs_2 TRAINER_MAXIE_MOSSDEEP, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, TRAINER_TABITHA_MOSSDEEP, MossdeepCity_SpaceCenter_Text_TabithaDefeat, PARTNER_STEVEN
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha::
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 60
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	removeobject LOCALID_SPACE_CENTER_GRUNT_6
	removeobject LOCALID_SPACE_CENTER_GRUNT_7
	removeobject LOCALID_SPACE_CENTER_GRUNT_5
	removeobject LOCALID_SPACE_CENTER_TABITHA
	removeobject LOCALID_SPACE_CENTER_MAXIE
	setobjectxy LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 6
	turnobject LOCALID_SPACE_CENTER_2F_SCIENTIST, DIR_SOUTH
	setobjectxy LOCALID_SPACE_CENTER_2F_GENTLEMAN, 11, 8
	turnobject LOCALID_SPACE_CENTER_2F_GENTLEMAN, DIR_NORTH
	setobjectxy LOCALID_SPACE_CENTER_2F_RICH_BOY, 6, 2
	turnobject LOCALID_SPACE_CENTER_2F_RICH_BOY, DIR_NORTH
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
	fadescreen FADE_FROM_BLACK
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	removeobject LOCALID_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	removeobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 5, 6
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
	addobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	fadescreen FADE_FROM_BLACK
#ifdef BUGFIX
	releaseall
#endif
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer::
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth::
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_NORTH
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest::
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_EAST
	return

MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
	call_if_eq VAR_RESULT, FEMALE, MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall::
	pokenavcall MatchCall_Text_MayRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall::
	pokenavcall MatchCall_Text_BrendanRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets:
	.string "A ALGATIA, le temps est souvent\n"
	.string "ensoleillé et les vents sont\p"
	.string "stables.\p"
	.string "C’est l’endroit idéal pour\n"
	.string "lancer des fusées.$"

MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel:
	.string "Mais pourquoi la TEAM MAGMA veut\n"
	.string "nous voler notre carburant?$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut:
	.string "Si j’avais été un peu plus\n"
	.string "jeune, j’aurais bien aimé être\p"
	.string "astronaute…\p"
	.string "Non… Il n’est pas trop tard! Je\n"
	.string "vais essayer!$"

MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis:
	.string "Si la TEAM MAGMA vole notre\n"
	.string "carburant, je ne pourrai jamais\p"
	.string "aller dans l’espace!\p"
	.string "On ne peut pas les laisser\n"
	.string "partir comme ça!$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace:
	.string "J’espère qu’un jour, tout le\n"
	.string "monde pourra aller dans\p"
	.string "l’espace…$"

MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace:
	.string "Est-ce que la TEAM MAGMA\n"
	.string "souhaite également aller dans\p"
	.string "l’espace?$"

MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn:
	.string "C’est quoi ton problème?\p"
	.string "Tu es à un contre trois mais tu\n"
	.string "veux quand même te battre?$"

MossdeepCity_SpaceCenter_2F_Text_GoodAnswer:
	.string "Bonne réponse! Tu n’es pas aussi\n"
	.string "stupide que je pensais.$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro:
	.string "Plutôt téméraire à ce que je\n"
	.string "vois… OK, à moi l’honneur alors!$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat:
	.string "J’ai perdu! Mais…$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro:
	.string "Il est trop tôt pour te réjouir!\n"
	.string "Je suis le suivant.$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat:
	.string "J’ai perdu aussi! Mais…$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro:
	.string "J’imagine que tu souhaites faire\n"
	.string "une pause. Mais ne compte pas\p"
	.string "dessus.$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat:
	.string "On aurait dû faire une pause… On\n"
	.string "aurait vraiment dû…$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle:
	.string "On était trois, et regarde le\n"
	.string "résultat…$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle:
	.string "Perdre à trois contre un… On est\n"
	.string "trois fois plus ridicules.$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle:
	.string "Je me demande si on est vraiment\n"
	.string "utiles à notre chef…$"

MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou:
	.string "Héhéhé!\p"
	.string "On est venus jusqu’ici pour\n"
	.string "prendre le carburant, et tu es\p"
	.string "encore dans nos pattes!\p"
	.string "Si tu veux vraiment nous gêner,\n"
	.string "on va s’occuper définitivement\p"
	.string "de toi!$"

MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere:
	.string "MAX: Hors de mon chemin!\n"
	.string "N’essaie même pas d’intervenir!$"

MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel:
	.string "PIERRE: TEAM MAGMA…\p"
	.string "Pourquoi voulez-vous nous voler\n"
	.string "le carburant de notre fusée?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano:
	.string "MAX: Ha ha ha… Puisque tu es si\n"
	.string "curieux, tu mérites une\p"
	.string "explication.\p"
	.string "Nous voulons tout déverser dans\n"
	.string "le MONT CHIMNEE!\p"
	.string "GROUDON parti, nous n’avons plus\n"
	.string "besoin de cette montagne!\p"
	.string "Alors nous allons utiliser le\n"
	.string "carburant pour créer une énorme\p"
	.string "éruption!\p"
	.string "Ça va être terrible!$"

MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle:
	.string "PIERRE: {PLAYER}{KUN}! Tu vas\n"
	.string "m’aider?\p"
	.string "Affrontons-les ensemble! On y va\n"
	.string "maintenant?$"

MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly:
	.string "PIERRE: Allez, dépêche-toi!\n"
	.string "Prépare-toi vite!$"

MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand:
	.string "Tout ce que je souhaite… C’est\n"
	.string "étendre la surface de la terre…$"

MossdeepCity_SpaceCenter_Text_TabithaDefeat:
	.string "Je suis avec notre leader…$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided:
	.string "MAX: Nous n’arriverons pas à\n"
	.string "faire entrer le volcan en\p"
	.string "éruption…\p"
	.string "Nous n’avons pas réussi à\n"
	.string "contrôler GROUDON après l’avoir\p"
	.string "réveillé…\p"
	.string "Aurions-nous tort de vouloir\n"
	.string "étendre la terre?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Si… Si nous, la TEAM MAGMA,\n"
	.string "avons tort… … … … … … …\p"
	.string "Alors que penser de la TEAM\n"
	.string "AQUA?$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp:
	.string "MAX: Très bien… Nous allons vous\n"
	.string "laisser le carburant.\p"
	.string "Il y a des choses plus\n"
	.string "importantes auxquelles je dois\p"
	.string "penser…$"

MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome:
	.string "PIERRE: Pfiuu, on a eu chaud!\n"
	.string "Merci, {PLAYER}{KUN}!\p"
	.string "Je voudrais te donner quelque\n"
	.string "chose pour te remercier de ton\p"
	.string "aide.\p"
	.string "Passe me voir chez moi plus\n"
	.string "tard.\p"
	.string "Ah oui, je n’habite pas à\n"
	.string "MEROUVILLE, mais bien ici, sur\p"
	.string "cette île.$"
