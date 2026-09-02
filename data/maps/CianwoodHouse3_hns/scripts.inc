CianwoodHouse3_hns_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	goto_if_set FLAG_BADGE01_GET, CianwoodCity_EventScript_KirkReturnShuckie
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "Je suis choqué!\p"
	.string "Un garnement de ton âge avec\p"
	.string "l'oeil mauvais et des cheveux\n"
	.string "longs, s'est infiltré chez moi.\p"
	.string "Il m'a fait grandpeur et\n"
	.string "chapardé mon Pokémon adoré!\p"
	.string "Il m'en reste un mais que faire\n"
	.string "s'il revient?\p"
	.string "Tu as l'air fort. Peux-tu\p"
	.string "t'occuper de mon Pokémon un\n"
	.string "petit moment?$"

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "Je, je te fais confiance!\n"
	.string "Prends-en soin!$"

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER} reçoit un Pokémon.$"

CianwoodCity_Text_ManiacPartyFull:
	.string "Tu as trop de Pokémon...$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "Oh, oh non... Comment je vais\n"
	.string "faire s’il revient?$"

CianwoodCity_Text_ManiacHowsdoing:
	.string "Mon Pokémon va bien?$"

CianwoodCity_Text_ManiacAskReturn:
	.string "Salut! Comment va mon Pokémon?\p"
	.string "Je pense être en\n"
	.string "sécurité maintenant,\p"
	.string "serait-il possible\n"
	.string "de le récupérer?$"

CianwoodCity_Text_ManiacThankYou:
	.string "Merci!$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "Hé, tu n'as pas mon Pokémon avec\n"
	.string "toi.$"

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "Mon Pokémon s’est attaché à\n"
	.string "toi... Compris! Je te le donne!\p"
	.string "En échange, tu devras en prendre\n"
	.string "soin!$"

CianwoodCity_Text_ManiacRobbed:
	.string "Hein? Quelque chose cloche.$"

CianwoodCity_Text_ManiacRobbed2:
	.string "C’est... C’est vrai?! Alors tu\n"
	.string "es semblable à mon agresseur!$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "Ce qui est important\n"
	.string "pour un Pokémon,\p"
	.string "c’est d’être avec\n"
	.string "une personne qui\p"
	.string "l’aime et prend soin de lui.$"

CianwoodCity_Text_ManiacLastMon:
	.string "Si je reprends mon Pokémon, avec\n"
	.string "quoi\p"
	.string "vas-tu pouvoir combattre?$"


CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER} rend CARAT.$"
