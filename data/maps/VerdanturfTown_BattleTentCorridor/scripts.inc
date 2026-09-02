VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "À quel CONCOURS participez-vous?\n"
	.string "Vous voulez un conseil?\p"
	.string "Dans un CONCOURS de BEAUTE, par\n"
	.string "exemple, la beauté n'est\p"
	.string "sûrement pas le seul critère du\n"
	.string "premier tour.\p"
	.string "Il faut trouver comment mieux\n"
	.string "élever ses POKéMON.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "J'ai élevé mon POKéMON pour\n"
	.string "qu'il soit beau.\p"
	.string "J'ai découvert qu'il pouvait\n"
	.string "participer à un CONCOURS de\p"
	.string "BEAUTE!\p"
	.string "Je suis si heureux de l'avoir\n"
	.string "élevé avec amour…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Mon POKéMON est imbattable!\p"
	.string "Il est cool, robuste, beau,\n"
	.string "gracieux et intelligent. Il est\p"
	.string "parfait!\p"
	.string "Je pourrais aussi bien viser la\n"
	.string "victoire dans tous les CONCOURS.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "CONCOURS POKéMON\n"
	.string "SCENE DE RANG NORMAL!$"
