FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES @ Specifically supposed to teach level up moves
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Je suis le MAITRE DES CAPACITES.\p"
	.string "Je connais absolument toutes les\n"
	.string "attaques que les POKéMON peuvent\p"
	.string "apprendre. Et je peux enseigner\n"
	.string "ces attaques à d’autres POKéMON.\p"
	.string "Je peux enseigner une attaque à\n"
	.string "l’un de tes POKéMON, si tu veux.\p"
	.string "Je peux le faire en échange\n"
	.string "d’une ECAILLECOEUR. Je les\p"
	.string "collectionne.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! Génial! C’est une\n"
	.string "ECAILLECOEUR d’une belle taille!\p"
	.string "Tu veux que j’enseigne une\n"
	.string "attaque à un de tes POKéMON?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "A quel POKéMON dois-je\n"
	.string "l’enseigner?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Quelle attaque dois-je\n"
	.string "enseigner?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Désolé…\p"
	.string "Apparemment, il n’y a aucune\n"
	.string "attaque que je puisse apprendre\p"
	.string "à ce POKéMON.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} donne une ECAILLECOEUR\n"
	.string "en échange.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "Si tu veux que j’enseigne une\n"
	.string "attaque à ton POKéMON, reviens\p"
	.string "avec une ECAILLECOEUR.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Quoi? Mais je ne peux pas\n"
	.string "apprendre une attaque à un OEUF.$"

