SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Je suis le SPECIALISTE DES NOMS!\n"
	.string "Je donne des conseils sur les\p"
	.string "surnoms à choisir.\p"
	.string "Et si j’examinais le surnom que\n"
	.string "tu as donné à l’un de tes\p"
	.string "POKéMON?$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Le surnom de quel POKéMON\n"
	.string "veux-tu que je juge?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hum… {STR_VAR_1}, c’est ça?\n"
	.string "C’est pas mal, ce surnom que tu\p"
	.string "lui as donné.\p"
	.string "Mais que dirais-tu de lui en\n"
	.string "donner un meilleur?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Bon, alors quel va être le\n"
	.string "nouveau surnom?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Très bien! A partir de\n"
	.string "maintenant, ce POKéMON sera\p"
	.string "surnommé {STR_VAR_1}!\p"
	.string "C’est mieux qu’avant! Tu en as\n"
	.string "de la chance!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Je vois. Reviens me voir.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Ça y est! A partir de\n"
	.string "maintenant, ce POKéMON sera\p"
	.string "surnommé {STR_VAR_1}!\p"
	.string "Ce surnom ne semble pas très\n"
	.string "différent de l’autre et\p"
	.string "pourtant, il sonne mieux!\p"
	.string "Tu en as de la chance!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hum… C’est {STR_VAR_1}!\p"
	.string "C’est un magnifique surnom! Rien\n"
	.string "à redire!\p"
	.string "Tu ferais bien de chouchouter\n"
	.string "ton {STR_VAR_1} à partir de\p"
	.string "maintenant.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Voyons, voyons… Ce n’est qu’un\n"
	.string "OEUF!$"

