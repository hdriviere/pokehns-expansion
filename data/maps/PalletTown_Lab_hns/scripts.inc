PalletTown_Lab_hns_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "Comment avance ton POKéDEX?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "CHEN: Ah, {PLAYER}! Merci\n"
	.string "d'avoir voyagé jusqu'à KANTO.\p"
	.string "Que penses-tu des dresseurs du\n"
	.string "coin? Plutôt forts, non?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "N'hésite pas à passer si tu es\n"
	.string "dans la région.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "CHEN: Woah! C'est génial, ça!\p"
	.string "Tu as gagné les BADGES de KANTO!\n"
	.string "Bravo!\p"
	.string "J'ai bien fait de te faire\n"
	.string "confiance.\p"
	.string "Dans ce cas, {PLAYER}, je vais\p"
	.string "faire en sorte que tu puisses\n"
	.string "aller au MONT ARGENT.\p"
	.string "Le MONT ARGENT est une montagne\n"
	.string "où\p"
	.string "vivent beaucoup de Pokémon\n"
	.string "sauvages.\p"
	.string "Cet endroit est trop dangereux\p"
	.string "pour le dresseur lambda, mais\n"
	.string "nous\p"
	.string "pouvons faire une exception pour\n"
	.string "toi, {PLAYER}.\p"
	.string "Va au PLATEAU INDIGO. Tu pourras\p"
	.string "accéder ensuite au MONT ARGENT.$"

PalletTown_Lab_Text_OakOpenIndigoPlateau:
	.string "Oh, à propos du PLATEAU INDIGO,\n"
	.string "maintenant que tu as obtenu les\l"
	.string "16 Badges, la LIGUE de KANTO\l"
	.string "acceptera de nouveau ton défi.\p"
	.string "Mais attention, PETER et son\n"
	.string "CONSEIL 4 ne te ménageront pas\l"
	.string "cette fois.\p"
	.string "Bonne chance, {PLAYER}!$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "CHEN: Hmm? Tu ne\n"
	.string "collectionnes pas\p"
	.string "les BADGES des\n"
	.string "ARENES de KANTO?\p"
	.string "Les CHAMPIONS d'ARENE de KANTO\p"
	.string "sont aussi forts que ceux de\n"
	.string "JOHTO.\p"
	.string "Je te conseille de les\n"
	.string "affronter.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "CHEN: Tu collectionnes les\n"
	.string "BADGES de KANTO.\p"
	.string "Cela doit être difficile, mais\n"
	.string "tu\p"
	.string "as beaucoup d'expérience à\n"
	.string "présent.\p"
	.string "Viens me voir si tu les as tous.\p"
	.string "J'aurai un cadeau pour toi.\p"
	.string "Bonne chance, {PLAYER}!$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "La CHRONIQUE PKMN du PROF à la\n"
	.string "radio\p"
	.string "ne passe pas ici, à KANTO.\p"
	.string "C'est bête... Je l'aime tant.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Grâce à ton travail\n"
	.string "sur le Pokédex, les\p"
	.string "recherches du PROF\n"
	.string "ont bien progressé.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "Ne le répète pas, mais la\n"
	.string "CHRONIQUE\p"
	.string "Pokémon du PROF. CHEN n'est pas\n"
	.string "en direct.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "Il y a un e-mail sur le PC.\p"
	.string "…\p"
	.string "PROF.CHEN, comment ça va bien?\n"
	.string "Ca bosse dur?\p"
	.string "Moi je bosse comme un barbare.\p"
	.string "On raconte que {PLAYER} est une\n"
	.string "vraie terreur...\p"
	.string "Et dire que c'est grâce à nous.\p"
	.string "ORME du BOURG GEON 8-)$"
