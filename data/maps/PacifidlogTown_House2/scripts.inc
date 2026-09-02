PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Hum-hum!\p"
	.string "Je suis la personne la plus\n"
	.string "influente du FAN CLUB POKéMON.\p"
	.string "Je suis le petit frère du\n"
	.string "PRESIDENT.\p"
	.string "Je suis ici en vacances, avec\n"
	.string "mes POKéMON, bien entendu.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ah! Ton POKéMON…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Il t’aime énormément, pas de\n"
	.string "doute.\p"
	.string "Un POKéMON aussi adorable et\n"
	.string "adoré mérite bien une CT comme\p"
	.string "ça, non?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hmm… Ce n’est pas mal, mais ce\n"
	.string "n’est pas génial non plus.\p"
	.string "Toi, en tant que DRESSEUR, tu\n"
	.string "dois faire plus d’efforts.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Il a un regard mauvais.\p"
	.string "Un POKéMON aussi effrayant\n"
	.string "mérite une CT comme ça.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Lorsqu’un POKéMON t’aime\n"
	.string "beaucoup, la puissance de RETOUR\p"
	.string "est augmentée.\p"
	.string "S’il ne t’aime pas, la puissance\n"
	.string "de FRUSTRATION est augmentée.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "Je devrais bientôt recevoir une\n"
	.string "ou deux bonnes CT. Tu veux\p"
	.string "savoir dans combien de jours?\n"
	.string "{STR_VAR_1}, je pense…\p"
	.string "Reviens me voir à ce moment-là.\n"
	.string "Je te donnerai une CT qui\p"
	.string "correspond à ton POKéMON.$"

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILL: Uriii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Il a l’air d’être très ami avec\n"
	.string "le DRESSEUR.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL: Uuuurill!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Il n’a pas l’air d’aimer\n"
	.string "beaucoup le DRESSEUR.$"

