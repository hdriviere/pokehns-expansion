LavenderTown_House2_Frlg_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseMon
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	goto_if_lt VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_CheckCanRateMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseNewNickname
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
	.string "Salut tout le monde! Je suis le\n"
	.string "SPECIALISTE DES NOMS!\p"
	.string "Dis-moi, tu serais pas du genre\n"
	.string "à vouloir donner un p'tit nom à\p"
	.string "un de tes POKéMON?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
	.string "Le surnom de quel POKéMON\n"
	.string "veux-tu que je juge?$"

LavenderTown_House2_Text_GiveItANicerName::
	.string "{STR_VAR_1}? Mouais, c'est pas\n"
	.string "mal!\p"
	.string "Mais tu voudrais pas que je lui\n"
	.string "donne un nom un peu… plus… qui\p"
	.string "aurait plus de… Mieux, quoi!\p"
	.string "Bon, alors?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
	.string "Bon, alors quel va être le\n"
	.string "nouveau surnom?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
	.string "Très bien! A partir de\n"
	.string "maintenant, ce POKéMON sera\p"
	.string "surnommé {STR_VAR_1}!\p"
	.string "C’est mieux qu’avant! Tu en as\n"
	.string "de la chance!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
	.string "Je vois. Reviens me voir.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
	.string "Ça y est! A partir de\n"
	.string "maintenant, ce POKéMON sera\p"
	.string "surnommé {STR_VAR_1}!\p"
	.string "Ce surnom ne semble pas très\n"
	.string "différent de l’autre et\p"
	.string "pourtant, il sonne mieux!\p"
	.string "Tu en as de la chance!$"

LavenderTown_House2_Text_TrulyImpeccableName::
	.string "{STR_VAR_1}? C'est un nom\n"
	.string "parfait, fais-moi confiance, je\p"
	.string "m'y connais!\p"
	.string "Prends soin de {STR_VAR_1}.$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
	.string "Voyons, voyons… Ce n’est qu’un\n"
	.string "OEUF!$"

