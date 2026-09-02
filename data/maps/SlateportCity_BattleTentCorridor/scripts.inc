SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Vous voulez un bon petit conseil\n"
	.string "pour les CONCOURS?\p"
	.string "Enchaîner certaines capacités\n"
	.string "peut parfois attirer davantage\p"
	.string "l'attention.\p"
	.string "Si vous maîtrisez vos\n"
	.string "enchaînements, votre démo\p"
	.string "rapportera gros.\p"
	.string "Mais vos adversaires peuvent\n"
	.string "tenter de perturber votre\p"
	.string "POKéMON.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Mon papa est JUGE de CONCOURS.\p"
	.string "Plus tard, je serai peut-être\n"
	.string "JUGE ou CHAMPION d'ARENE. Que\p"
	.string "choisir?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Hé, je suis vraiment furax, tu\n"
	.string "vois. Je voulais savoir pourquoi\p"
	.string "mon POKéMON ne gagnait jamais.\p"
	.string "Alors j'ai dit ses quatre\n"
	.string "vérités au JUGE, mais il n'a\p"
	.string "rien voulu entendre! Quelle\n"
	.string "galère!\p"
	.string "Hé, toi! Pas un mot, compris?\n"
	.string "Prends plutôt ça!$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "C'est la CT41, tu vois? Elle\n"
	.string "contient TOURMENTE.\p"
	.string "Elle empêche l'adversaire\n"
	.string "d'utiliser deux fois de suite la\p"
	.string "même capacité.\p"
	.string "Mais écoute, je ne cherche pas à\n"
	.string "te tourmenter!$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "PRESENTATEUR: Oh là là! Quel\n"
	.string "superbe POKéMON!\p"
	.string "Venez donc participer à nos\n"
	.string "splendides CONCOURS!\p"
	.string "Vous réussirez, j'en suis\n"
	.string "certain! Mon œil ne me trompe\p"
	.string "jamais!$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JUGE: Bonjour! Je vois que vous\n"
	.string "êtes DRESSEUR!\p"
	.string "Alors vous ne pouvez pas manquer\n"
	.string "un CONCOURS POKéMON!\p"
	.string "Procurez-vous un PASSE CONCOURS\n"
	.string "à VERGAZON et inscrivez-vous\p"
	.string "quand vous voudrez!$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "C'est l'heure des démos! Par\n"
	.string "quoi vais-je commencer?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Ils n'ont guère prêté attention\n"
	.string "à la démo de mon POKéMON…\p"
	.string "Pff! Ce JUGE ne sait pas\n"
	.string "reconnaître le talent.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, bonjour! Il faut être un\n"
	.string "vrai passionné pour s'approcher\p"
	.string "autant.\p"
	.string "Votre enthousiasme mérite un\n"
	.string "conseil avisé.\p"
	.string "Quand une capacité plaît\n"
	.string "beaucoup, le public\p"
	.string "s'enthousiasme.\p"
	.string "Et le POKéMON qui fait sa démo\n"
	.string "au comble de l'excitation…\p"
	.string "Disons qu'il peut s'attendre à\n"
	.string "une belle surprise!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Je n'y arriverai pas! Je suis\n"
	.string "encore plus paniqué que mon\p"
	.string "POKéMON.\p"
	.string "Je tremble et mon cœur\n"
	.string "s'emballe!$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Un combat et un CONCOURS sont\n"
	.string "différents, mais ils se\p"
	.string "ressemblent aussi.\p"
	.string "Il faut travailler dur et croire\n"
	.string "au POKéMON qu'on a élevé.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Ce POKéMON semble au sommet de\n"
	.string "sa forme!\p"
	.string "Un POKéMON bien noté lors du\n"
	.string "second jugement paraît plus\p"
	.string "détendu pendant les démos.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Regardez-moi ce triste\n"
	.string "spectacle!\p"
	.string "Hé hé, mon POKéMON est largement\n"
	.string "meilleur que tous ceux-là!$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Quand un POKéMON fait une démo\n"
	.string "pleine d'énergie, vous n'avez\p"
	.string "pas envie de bouger avec lui?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "CONCOURS POKéMON\n"
	.string "SCENE DE RANG HYPER!$"
