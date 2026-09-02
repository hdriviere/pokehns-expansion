NewSinjoh_House2_hns_MapScripts::
	.byte 0


NewSinjoh_House2_EventScripts_DeskLady::
    lock
	msgbox NewSinjoh_House2_DeskLady_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_DeskLady_Text::
    .string "Bonjour, mon enfant...\p"
	.string "Bienvenue dans la...\n"
	.string "Disons, la bibliothèque du\l"
	.string "NOUVEAU SINJOH.\p"
	.string "Nous conservons ici toutes les\n"
	.string "archives de l'histoire locale,\l"
	.string "ainsi que les ouvrages importés\l"
	.string "d'autres régions...$"

NewSinjoh_House2_EventScript_Torkoal::
	lock
	faceplayer
	playmoncry SPECIES_TORKOAL, 0
	msgbox NewSinjoh_Hosue2_Text_CryTorkoal, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Hosue2_Text_CryTorkoal:
	.string "Charbooo?$"

NewSinjoh_House2_EventScript_BookShelf_North::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_North MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_North:
    .string "Elle déborde de vieux livres\n"
	.string "reliés en cuir.\p"
	.string "La langue est méconnaissable.$"

NewSinjoh_House2_EventScript_BookShelf_South::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_South MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_South:
    .string "Elle déborde de livres sur les\n"
	.string "Pokémon.\p"
	.string "Ils semblent plus récents, plus\n"
	.string "familiers.$"
