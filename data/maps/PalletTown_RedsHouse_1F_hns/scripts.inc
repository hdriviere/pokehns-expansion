PalletTown_RedsHouse_1F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "Salut!\p"
	.string "RED est parti il y a longtemps.\p"
	.string "Il n'a même pas appelé... Je ne\p"
	.string "sais vraiment pas ce qu'il fait\n"
	.string "en ce moment.\p"
	.string "A vrai dire, je me fais du\n"
	.string "souci.$"

RedsHouse_Text_Mom2:
	.string "J’ai peur qu’il se\n"
	.string "blesse ou qu’il tombe\p"
	.string "malade... Mais c’est\n"
	.string "un grand garçon!$"

RedsHouse_Text_TV:
	.string "Il y a des émissions qui ne\n"
	.string "passent pas à JOHTO.$"
