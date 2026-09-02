LakeOfRage_House2_hns_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "Le LAC COLERE est en fait un\n"
    .string "cratère\p"
    .string "créé par le déchaînement des\n"
    .string "LEVIATOR.\p"
    .string "Le cratère s'est peu à peu\n"
    .string "rempli\p"
    .string "d'eau de pluie et un LAC s'est\n"
    .string "formé.\p"
    .string "Cette histoire se\n"
    .string "transmet de génération\p"
    .string "en génération. Elle vient\n"
    .string "d'un de mes grands-pères.\p"
    .string "On pouvait attraper de vrais\p"
    .string "MAGICARPE en pleine forme ici!\p"
    .string "Je ne comprends pas ce qu'il se\n"
    .string "passe.$"

LakeOfRage_House2_Text_MenInBlack:
    .string "Ce LAC n'est plus normal depuis\p"
    .string "l'arrivée des hommes en noir.$"

LakeOfRage_House2_Text_LastMon:
	.string "Ne me laisse pas prendre\n"
	.string "ton dernier Pokémon!$"

LakeOfRage_House2_Text_WorldsLargest:
	.string "Le LAC COLERE est revenu\n"
	.string "à la normale.\p"
	.string "Les MAGICARPE sont revenus.\p"
	.string "Je peux encore réaliser\n"
	.string "mon rêve:l"
	.string "posséder le plus grand MAGICARPE\l"
	.string "du monde.\p"
	.string "Je paierai 2 000 ¥ pour chaque\n"
	.string "MAGICARPE, et 100 000 ¥ pour un\l"
	.string "MAGICARPE GÉANT!$"

LakeOfRage_House2_Text_ForMe:
	.string "Alors... Tu as un MAGICARPE\n"
	.string "pour moi?$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "Ah, tu as un MAGICARPE!\n"
    .string "Laisse-moi voir sa taille.$"

LakeOfRage_House2_Text_BigPayout:
	.string "Waouh! Celui-ci est\n"
	.string "exceptionnel!\p"
	.string "Je te tire mon chapeau!\p"
	.string "Voici quelque chose pour\n"
	.string "ta peine.$"

LakeOfRage_House2_Text_Bonus:
    .string "Ce qui compte, c’est d’avoir\n"
    .string "établi un record!\p"
    .string "A côté, ce cadeau a l’air d’un\n"
    .string "lot de consolation...$"

LakeOfRage_House2_Text_TooShort:
	.string "Waouh! Celui-ci est\n"
	.string "exceptionnel!\p"
	.string "...J'aimerais pouvoir le dire,\n"
	.string "mais j'en ai déjà vu\n"
	.string "un plus grand.\p"
	.string "Il vaut quand même\n"
	.string "quelque chose.$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "Quoi? Ce n'est pas un MAGICARPE!$"

LakeOfRage_House2_Text_Refused:
    .string "Alors... Tu n'as rien pris qui\p"
    .string "vaille la peine d'être montré?\n"
    .string "Peut-être la prochaine fois!$"
