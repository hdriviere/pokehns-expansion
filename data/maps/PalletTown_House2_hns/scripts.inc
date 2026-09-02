PalletTown_House2_hns_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "Nina: Mon petit frère est le\n"
	.string "Champion de l’Arène de Jadielle.\p"
	.string "Mais il est souvent\n"
	.string "absent, et ça pose\p"
	.string "beaucoup de problèmes\n"
	.string "aux Dresseurs.$"

PalletTown_House2_Text_OfferGrooming:
	.string "NINA: Salut! Ca tombe bien,\n"
	.string "j'allais faire du thé.\p"
	.string "En veux-tu?\p"
	.string "Oh, tes Pokémon sont sales.\p"
	.string "Tu veux que j'en bichonne un?$"

PalletTown_House2_Text_WhichMon:
	.string "Nina: Lequel veux-tu me confier?$"

PalletTown_House2_Text_Alright:
	.string "NINA: OK, je vais le faire beau\n"
	.string "en deux secondes.$"

PalletTown_House2_Text_AllDone:
	.string "NINA: Et voilà! C'est terminé.\p"
	.string "Tu vois? {STR_VAR_1} n'est-il\n"
	.string "pas élégant?\p"
	.string "Quel adorable Pokémon.$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "Nina: Je me fais toujours du thé\n"
	.string "à cette heure.\p"
	.string "Reviens quand tu veux!$"

PalletTown_House2_Text_Refused:
	.string "Nina: Tu ne veux pas que je m’en\n"
	.string "occupe? Très bien.\p"
	.string "Une tasse de thé, peut-être?$"

PalletTown_House2_Text_CantGroomEgg:
	.string "Nina: Huhuhu... Je ne peux pas\n"
	.string "m’occuper d’un Oeuf!$"
