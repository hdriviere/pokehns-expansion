DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Regarde-moi cette merveille!\p"
	.string "C’est un MOUCH. SOIE. C’est à la\n"
	.string "pointe de la mode!\p"
	.string "Oh, je vois une lueur dans tes\n"
	.string "yeux! Mon style éblouissant te\p"
	.string "plaît!\p"
	.string "Oh, tu me fais plaisir! Tiens,\n"
	.string "voilà. Je te le donne!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, tu n’as plus de place?\p"
	.string "Bon, écoute-moi bien, cet objet\n"
	.string "est indispensable! Il vaut bien\p"
	.string "tous les objets que j’ai sur\n"
	.string "moi.$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "Le MOUCH. SOIE augmente la\n"
	.string "puissance des attaques de type\p"
	.string "NORMAL.\p"
	.string "C’est un MOUCHOIR merveilleux\n"
	.string "assorti à presque tous les\p"
	.string "POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Ouah, tu as franchi la mer pour\n"
	.string "venir visiter MYOKARA?\p"
	.string "Tu es peut-être ici parce que tu\n"
	.string "as entendu parler de BASTIEN?\p"
	.string "Il est super cool… Tout le monde\n"
	.string "l’adore.$"

