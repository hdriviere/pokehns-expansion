.equ TRAINER_VISITING, VAR_TEMP_1

SevenIsland_House_Room1_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_House_Room1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SevenIsland_House_Room1_OnFrame
	.byte 0

SevenIsland_House_Room1_OnTransition::
	special ValidateEReaderTrainer
	call_if_eq VAR_RESULT, 0, SevenIsland_House_Room1_EventScript_SetTrainerVisitingLayout
	call_if_ne VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 0, SevenIsland_House_Room1_EventScript_MoveOldWomanToDoor
	end

SevenIsland_House_Room1_EventScript_SetTrainerVisitingLayout::
	setvar TRAINER_VISITING, TRUE
	setobjectxyperm LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, 4, 2
	setobjectmovementtype LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_SEVEN_ISLAND_HOUSE_ROOM1_DOOR_OPEN
	return

SevenIsland_House_Room1_EventScript_MoveOldWomanToDoor::
	setobjectxyperm LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, 3, 2
	setobjectmovementtype LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

SevenIsland_House_Room1_OnFrame::
	map_script_2 VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 1, SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle
	map_script_2 VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 2, SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle
	map_script_2 VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 3, SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle
	.2byte 0

SevenIsland_House_Room1_EventScript_OldWomanCommentOnBattle::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerReEnterRoom
	waitmovement 0
	applymovement LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN, SevenIsland_House_Room1_Movement_OldWomanWalkBehindPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SEVEN_ISLAND_HOUSE_OLD_WOMAN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call_if_eq VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 1, SevenIsland_House_Room1_EventScript_BattleWonComment
	call_if_eq VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 2, SevenIsland_House_Room1_EventScript_BattleLostComment
	call_if_eq VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 3, SevenIsland_House_Room1_EventScript_BattleTiedComment
	special LoadPlayerParty
	setvar VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1, 0
	releaseall
	end

SevenIsland_House_Room1_EventScript_BattleWonComment::
	msgbox SevenIsland_House_Room1_Text_AstoundingBattle
	return

SevenIsland_House_Room1_EventScript_BattleLostComment::
	msgbox SevenIsland_House_Room1_Text_FeelYourDisappointment
	return

SevenIsland_House_Room1_EventScript_BattleTiedComment::
	msgbox SevenIsland_House_Room1_Text_DrawWasIt
	return

SevenIsland_House_Room1_Movement_PlayerReEnterRoom::
	walk_down
	step_end

SevenIsland_House_Room1_Movement_OldWomanWalkBehindPlayer::
	walk_right
	walk_in_place_faster_down
	step_end

SevenIsland_House_Room1_EventScript_OldWoman::
	lock
	faceplayer
	special ValidateEReaderTrainer
	call_if_eq VAR_RESULT, 1, SevenIsland_House_Room1_EventScript_InvalidVisitingTrainer
	goto_if_eq TRAINER_VISITING, TRUE, SevenIsland_House_Room1_EventScript_TrainerVisiting
	msgbox SevenIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles
	release
	end

SevenIsland_House_Room1_EventScript_InvalidVisitingTrainer::
	msgbox SevenIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles
	release
	end

SevenIsland_House_Room1_EventScript_TrainerVisiting::
	special SavePlayerParty
	special BufferEReaderTrainerName
	msgbox SevenIsland_House_Room1_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SevenIsland_House_Room1_EventScript_DeclineBattle
	call SevenIsland_House_Room1_EventScript_ChooseParty
	goto_if_eq VAR_RESULT, 0, SevenIsland_House_Room1_EventScript_DeclineBattle
	msgbox SevenIsland_House_Room1_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SevenIsland_House_Room1_EventScript_DeclineBattle
	special LoadPlayerParty
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, SevenIsland_House_Room1_EventScript_DeclineBattle
	special SavePlayerParty
	special ReducePlayerPartyToSelectedMons
	msgbox SevenIsland_House_Room1_Text_DontHoldAnythingBack
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SevenIsland_House_Room1_EventScript_EnterBattleRoomNorth
	call_if_eq VAR_FACING, DIR_EAST, SevenIsland_House_Room1_EventScript_EnterBattleRoomEast
	call_if_eq VAR_FACING, DIR_WEST, SevenIsland_House_Room1_EventScript_EnterBattleRoomWest
	warp MAP_SEVEN_ISLAND_HOUSE_ROOM2, 3, 1
	waitstate
	release
	end

SevenIsland_House_Room1_EventScript_DeclineBattle::
	special LoadPlayerParty
	msgbox SevenIsland_House_Room1_Text_OhYouWontBattle
	release
	end

SevenIsland_House_Room1_EventScript_ChooseParty::
	msgbox SevenIsland_House_Room1_Text_LimitThreeMonsPerSide
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	return

SevenIsland_House_Room1_EventScript_EnterBattleRoomNorth::
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room1_Movement_OldWomanMoveAsideLeft
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomNorth
	waitmovement 0
	return

SevenIsland_House_Room1_EventScript_EnterBattleRoomEast::
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room1_Movement_OldWomanMoveAsideRight
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomEast
	waitmovement 0
	return

SevenIsland_House_Room1_EventScript_EnterBattleRoomWest::
	applymovement VAR_LAST_TALKED, SevenIsland_House_Room1_Movement_OldWomanMoveAsideLeft
	applymovement LOCALID_PLAYER, SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomWest
	waitmovement 0
	return

SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomNorth::
	delay_16
	walk_up
	walk_up
	step_end

SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomEast::
	delay_16
	walk_right
	walk_up
	step_end

SevenIsland_House_Room1_Movement_PlayerEnterBattleRoomWest::
	delay_16
	walk_left
	walk_up
	step_end

SevenIsland_House_Room1_Movement_OldWomanMoveAsideLeft::
	walk_left
	walk_in_place_faster_right
	step_end

SevenIsland_House_Room1_Movement_OldWomanMoveAsideRight::
	walk_right
	walk_in_place_faster_left
	step_end

SevenIsland_House_Room1_EventScript_Box::
	msgbox SevenIsland_House_Room1_Text_SlightBreezeAroundBox, MSGBOX_SIGN
	end

SevenIsland_House_Room1_Text_OnlyEnjoymentWatchingBattles::
	.string "Je sais que c'est dur à croire,\n"
	.string "mais quand j'étais plus jeune,\p"
	.string "j'adorais être sur les routes\n"
	.string "pour affronter tous les\p"
	.string "DRESSEURS\p"
	.string "que je pouvais rencontrer.\p"
	.string "Maintenant, ma seule source de\n"
	.string "distraction est de me rappeler\p"
	.string "du passé en regardant des\n"
	.string "combats.$"

SevenIsland_House_Room1_Text_SlightBreezeAroundBox::
	.string "Il y a un courant d'air derrière\n"
	.string "les cartons.$"

SevenIsland_House_Room1_Text_ChallengeVisitingTrainer::
	.string "Ah! Bienvenue, mon ami!\p"
	.string "Je vais vous révéler quelque\n"
	.string "chose. Une pièce secrète se\p"
	.string "trouve au sous-sol.\p"
	.string "Un DRESSEUR nommé {STR_VAR_1}\n"
	.string "vous y attend.\p"
	.string "Vous êtes bien venu affronter\n"
	.string "{STR_VAR_1}, n'est-ce pas?$"

SevenIsland_House_Room1_Text_OhYouWontBattle::
	.string "Oh… Tu ne veux pas te battre?\p"
	.string "Je vois, je vois. …\p"
	.string "Bon, si jamais tu changes\n"
	.string "d'avis.$"

SevenIsland_House_Room1_Text_LimitThreeMonsPerSide::
	.string "Ah! Tu veux bien te battre\n"
	.string "alors!\p"
	.string "Donc ça valait le coup que je\n"
	.string "déplace tous ces cartons.\p"
	.string "… … Mais il y a juste un\n"
	.string "problème.\p"
	.string "La salle n'est pas très solide,\n"
	.string "tu sais.\p"
	.string "Je peux te demander de ne\n"
	.string "prendre que trois POKéMON\p"
	.string "avec toi pour pas tout casser?$"

SevenIsland_House_Room1_Text_SaveProgressBeforeBattle::
	.string "Bien! Veux-tu sauvegarder avant\n"
	.string "de combattre?$"

SevenIsland_House_Room1_Text_DontHoldAnythingBack::
	.string "Parfait. Bon courage.$"

@ Unused
SevenIsland_House_Room1_Text_StrVar1_1::
	.string "{STR_VAR_1}$"

SevenIsland_House_Room2_Text_MatchEndedUpDraw::
	.string "Il y a égalité.$"

SevenIsland_House_Room1_Text_DrawWasIt::
	.string "Match nul, hein?\p"
	.string "Mais laisse-moi te dire que le\n"
	.string "match était époustouflant.\p"
	.string "Je dirais que c'était un combat\n"
	.string "d'une grande profondeur!$"

@ Unused
SevenIsland_House_Room1_Text_StrVar1_2::
	.string "{STR_VAR_1}$"

SevenIsland_House_Room1_Text_AstoundingBattle::
	.string "Bravo! Toutes mes félicitations!\p"
	.string "J'en ai les larmes aux yeux!\p"
	.string "Je n'avais encore jamais vu\n"
	.string "quelqu'un maîtriser ainsi toutes\p"
	.string "ces capacités! Un vrai combat de\n"
	.string "titans!\p"
	.string "Pfiu, laisse-moi un moment pour\n"
	.string "m'en remettre.$"

@ Unused
SevenIsland_House_Room1_Text_StrVar1_3::
	.string "{STR_VAR_1}$"

SevenIsland_House_Room1_Text_FeelYourDisappointment::
	.string "Quel dommage! Je comprends ta\n"
	.string "déception.\p"
	.string "Mais c'est dans la défaite qu'on\n"
	.string "devient un vrai DRESSEUR.\p"
	.string "Sers-toi de ce combat comme\n"
	.string "d'une leçon, et tu verras,\p"
	.string "tu t'en souviendras plus tard\n"
	.string "comme d'un bon souvenir.$"

