GoldenrodCity_House1_hns_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	@special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "Veux-tu modifier le réglage des\n"
	.string "couleurs chromatiques uniques?$"

GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "Couleurs chromatiques modifiées!\p"
	.string "Consulte ce réglage dans le\n"
	.string "VISUALISEUR DE DEFIS d'un PC.$"

GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "Ce sont les infos…\p"
	.string "La POLICE recherche ce GARÇON\n"
	.string "AUX CHEVEUX ROUGES!\p"
	.string "TOI, tu connais son nom?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Salut! Je suis le SPECIALISTE\n"
	.string "DES NOMS, le devin des noms!\p"
	.string "Je serai ravi de juger le surnom\n"
	.string "de ton Pokémon.$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Bon... Bon... Quel surnom de\n"
	.string "Pokémon veux-tu\p"
	.string "que j’examine?$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hum… {STR_VAR_1}, c'est ça?\p"
	.string "Tu lui as donné un joli nom.\p"
	.string "Et si je proposais\n"
	.string "un nom encore meilleur?$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, bien. Quel sera son nouveau\n"
	.string "surnom?$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Voilà! Désormais, ce Pokémon\n"
	.string "s'appellera {STR_VAR_1}!\p"
	.string "Ce nom est bien meilleur!\n"
	.string "Quelle chance pour toi!$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Je vois.\n"
	.string "Reviens me voir.$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Voilà! Désormais, ce Pokémon\n"
	.string "s'appellera {STR_VAR_1}!\p"
	.string "Il semble inchangé, mais\n"
	.string "il est pourtant bien supérieur!\p"
	.string "Quelle chance pour toi!$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "Hum… {STR_VAR_1}, c'est ça!\p"
	.string "Ce surnom est magnifique!\n"
	.string "Il est absolument irréprochable!\p"
	.string "Chéris bien ton {STR_VAR_1}\n"
	.string "dès maintenant.$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Voyons, voyons.\n"
	.string "Ce n'est qu'un OEUF!$"
