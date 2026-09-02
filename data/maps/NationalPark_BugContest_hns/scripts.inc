NationalPark_BugContest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_BugContest_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NationalPark_BugContest_OnFrame
	.byte 0

NationalPark_BugContest_OnTransition::
	goto_if_eq VAR_BUG_CONTEST_STATE, 3, NationalPark_BugContest_EventScript_JudgeScene
	end

NationalPark_BugContest_OnFrame::
	map_script_2 VAR_BUG_CONTEST_STATE, 1, NationalPark_BugContest_EventScript_Enter
	map_script_2 VAR_BUG_CONTEST_STATE, 5, NationalPark_BugContest_EventScript_EnterSide
	map_script_2 VAR_BUG_CONTEST_STATE, 3, NationalPark_BugContest_EventScript_JudgeSceneActivate
	.2byte 0


NationalPark_BugContest_EventScript_BC1::
	lock
	faceplayer
	msgbox NationalParkBugContest_Text_ContestantShaun, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_BugContest_EventScript_BC2::
	lock
	faceplayer
	msgbox NationalParkBugContest_Text_Contestant2A, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_BugContest_EventScript_Belinda::
	lock
	faceplayer
	msgbox NationalParkBugContest_Text_ContestantBelinda, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_BugContest_EventScript_Boy::
	lock
	faceplayer
	msgbox NationalParkBugContest_Text_Contestant6A, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_BugContest_EventScript_RelaxationSquare::
	lock
	msgbox NationalParkBugContest_Text_Sign_RelaxationSquare, MSGBOX_SIGN
	closemessage
	release
	end

NationalPark_BugContest_EventScript_BattleSign::
	lock
	msgbox NationalParkBugContest_Text_Sign_BattleNotice, MSGBOX_SIGN
	closemessage
	release
	end

NationalPark_BugContest_EventScript_TrainerTips::
	lock
	msgbox NationalParkBugContest_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

NationalPark_BugContest_EventScript_Trash::
	lock
	msgbox NationalPark_BugContest_Text_Trash, MSGBOX_SIGN
	closemessage
	release
	end

NationalPark_BugContest_EventScript_JudgeScene::
	special ShowBugContestChosenMon
	setobjectxyperm VAR_RESULT, 20, 29
	setobjectxyperm LOCALID_BUGCONTEST_BUG1, 24, 29
	setobjectxyperm LOCALID_BUGCONTEST_BUG2, 22, 29
	setobjectxyperm LOCALID_BUGCONTEST_BUG3, 18, 29
	setobjectxyperm LOCALID_BUGCONTEST_BUG4, 16, 29

	setobjectxyperm LOCALID_BUGCONTEST_GIRL, 18, 28
	setobjectxyperm LOCALID_BUGCONTEST_BC1, 22, 28
	setobjectxyperm LOCALID_BUGCONTEST_BC2, 24, 28
	setobjectxyperm LOCALID_BUGCONTEST_BOY, 16, 28
	setobjectxyperm LOCALID_BUGCONTEST_ATTENDANT, 20, 26

	setobjectmovementtype LOCALID_BUGCONTEST_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_BUGCONTEST_BC1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_BUGCONTEST_BC2, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_BUGCONTEST_BOY, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_BUGCONTEST_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	end

NationalPark_BugContest_EventScript_JudgeSceneActivate::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto BugContestEventScript_Judging
	end


NationalPark_BugContest_EventScript_Enter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_BUG_CONTEST_STATE, 2
	msgbox NationlParkBugContest_Text_EnjoyTheContest, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

NationalPark_BugContest_EventScript_EnterSide::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	delay 20
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	addobject LOCALID_BUGCONTEST_ATTENDANT_SIDE
	setvar VAR_TEMP_1, 1
	setvar VAR_BUG_CONTEST_STATE, 2
	msgbox NationlParkBugContest_Text_EnjoyTheContest, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

NationalPark_BugContest_EventScript_Trigger::
	lock
	turnobject LOCALID_BUGCONTEST_ATTENDANT, DIR_EAST
	goto NationalPark_BugContest_EventScript_RetireChoice
NationalPark_BugContest_EventScript_Attendant::
	lock
	faceplayer
	msgbox NationalParkBugContest_Text_Attendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, BugContest_EventScript_TimesUp
	msgbox NationlParkBugContest_Text_EnjoyTheContest, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_BugContest_EventScript_RetireChoice::
	msgbox NationalParkBugContest_Text_Attendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, BugContest_EventScript_TimesUp
	msgbox NationlParkBugContest_Text_EnjoyTheContest, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

NationalPark_BugContest_Movement_AttendantSide:
	walk_in_place_left
	step_end

NationalPark_BugContest_Text_Trash:
	.string "Il n'y a rien ici.$"

NationlParkBugContest_Text_EnjoyTheContest:
	.string "RÉCEPTIONNISTE: Bon concours!$"

NationalParkBugContest_Text_Attendant:
	.string "RÉCEPTIONNISTE: Veux-tu\n"
	.string "mettre fin au concours?$"

NationalParkBugContest_Text_ContestantBelinda:
	.string "BELINDA: Je vais gagner!\n"
	.string "Ne viens pas m'embêter.$"

NationalParkBugContest_Text_Contestant2A:
	.string "ODILON: Mon PARASECT endort avec\n"
	.string "SPORE.$"

NationalParkBugContest_Text_ContestantShaun:
	.string "SHAUN: Gagner ne m'intéresse pas\n"
	.string "vraiment.\p"
	.string "Je cherche seulement des Pokémon\n"
	.string "rares.$"

NationalParkBugContest_Text_Contestant6A:
	.string "René: Il faut\n"
	.string "d’abord affaiblir\p"
	.string "un Pokémon Insecte\n"
	.string "avant de lancer\p"
	.string "une Poké Ball.$"

NationalParkBugContest_Text_Contestant7A:
	.string "SANDY: Pardon?\p"
	.string "Tu trouves ça bizarre qu'une\n"
	.string "fille\p"
	.string "attrape des Pokémon insecte?$"

NationalParkBugContest_Text_Contestant8A:
	.string "Arnaud: Je collectionne\n"
	.string "les Pokémon Insecte\p"
	.string "depuis ma plus\n"
	.string "tendre enfance.\p"
	.string "Je ne peux pas perdre!$"

NationalParkBugContest_Text_Contestant9A:
	.string "Gontran: Plutôt que de parler,\n"
	.string "tu devrais chercher des Pokémon.$"

NationalParkBugContest_Text_Contestant10A:
	.string "Cyril: J’ai\n"
	.string "étudié les Pokémon\p"
	.string "Insecte à fond.\n"
	.string "Je vais gagner...\p"
	.string "C’est sûr!$"

NationalParkBugContest_Text_Sign_RelaxationSquare:
	.string "AIRE DE REPOS du PARC NATUREL$"

NationalParkBugContest_Text_Sign_BattleNotice:
	.string "C'est quoi cette affiche?\p"
	.string "Se battre uniquement dans\n"
	.string "l'herbe.\p"
	.string "LE GARDIEN DU PARC NATUREL$"

NationalParkBugContest_Text_TrainerTips:
	.string "Le PARC NATUREL abrite des\n"
	.string "Pokémon différents pendant le\l"
	.string "CONCOURS DE\l"
	.string "CAPTURE D'INSECTE.$"
