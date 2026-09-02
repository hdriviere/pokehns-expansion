GoldenrodCity_BillsHouse_hns_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
	.string "LEO: Salut, {PLAYER}! Rends-nous\n"
	.string "service et prends cet EVOLI.\p"
	.string "On nous l'a confié tandis que je\n"
	.string "travaillais sur mon système.\p"
	.string "Quelqu'un doit s'en occuper.\p"
	.string "Mais je n'aime pas sortir.\p"
	.string "Peux-tu jouer avec lui,\n"
	.string "{PLAYER}?$"

BillHouse_Text_CountingOnYou:
    .string "LEO: Je savais que je pouvais\p"
    .string "compter sur toi! T'es trop chou!\p"
    .string "Prends-en soin!$"

BillHouse_Text_ReceivedEevee:
    .string "{PLAYER} reçoit EVOLI!$"

BillHouse_Text_EeveeMayEvolve:
    .string "LEO: Le PROF.ORME affirme que\n"
    .string "les\p"
    .string "EVOLI pourraient évoluer en des\n"
    .string "formes encore inconnues.$"

BillHouse_Text_PartyFull:
    .string "Ah, c’est pas possible, tu ne\n"
    .string "peux pas transporter\p"
    .string "plus de Pokémon...$"

BillHouse_Text_NoEevee:
    .string "Ah bon...$"

BillHouse_Text_PopWontWork:
    .string "LEO: Mon papa... Il fait rien de\n"
    .string "la journée.\p"
    .string "On peut dire que c'est un\n"
    .string "flemmard!$"

BillHouse_Text_MomBeforeEcruteak:
    .string "Tu collectionnes les Pokémon?\n"
    .string "Mon fils LEO est un expert.\p"
    .string "Il est allé au CENTRE Pokémon de\n"
    .string "ROSALIA.\p"
    .string "Mon mari en revanche est au\p"
    .string "CASINO... Ne cherche pas à\n"
    .string "comprendre...$"

BillHouse_Text_MomAfterEcruteak:
	.string "Mon mari était autrefois connu\n"
	.string "comme Pokémaniac.\p"
	.string "LEO tient sûrement de son père.$"

BillHouse_Text_SisterUsefulNumber:
    .string "Es-tu dresseur?\p"
    .string "J'ai un numéro de téléphone\n"
    .string "utile pour toi.$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER} enregistre le numéro de\n"
    .string "téléphone de LEO.$"

BillHouse_Text_SisterRefusedNumber:
    .string "Mon frère a créé\n"
    .string "un système de\p"
    .string "stockage pour les\n"
    .string "Pokémon par PC.\p"
    .string "J'allais te donner le numéro de\n"
    .string "téléphone de LEO...$"

BillHouse_Text_SisterPhoneFull:
    .string "Mais tu ne peux plus enregistrer\n"
    .string "de numéros!$"

BillHouse_Text_SisterStorageSystem:
    .string "Mon grand frère LEO a fait un\p"
    .string "super système de stockage de\n"
    .string "Pokémon par PC.$"
