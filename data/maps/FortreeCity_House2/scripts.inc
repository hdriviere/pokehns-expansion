FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Les humains… Les POKéMON…\p"
	.string "Leurs pouvoirs cachés se\n"
	.string "développent lorsqu’ils vivent en\p"
	.string "milieu naturel…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Laisse la vieille dame que je\n"
	.string "suis voir si ton pouvoir caché\p"
	.string "s’est éveillé…\p"
	.string "J’ai une pièce dans une main.\p"
	.string "Dans quelle main l’ai-je cachée?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Oui, c’est juste!\p"
	.string "On va réessayer.\p"
	.string "Dans quelle main est la pièce?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Oui, c’est juste!\p"
	.string "On va réessayer.\p"
	.string "Dans quelle main est la pièce?\n"
	.string "La droite ou la gauche?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Superbe! Ton pouvoir caché\n"
	.string "s’est réveillé!\p"
	.string "Tiens, prends ça et révèle le\n"
	.string "pouvoir caché de tes POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "PUISSANCE CACHEE est une\n"
	.string "capacité qui diffère selon les\p"
	.string "POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Non, dommage. Tu n’as pas fait\n"
	.string "le bon choix.$"

