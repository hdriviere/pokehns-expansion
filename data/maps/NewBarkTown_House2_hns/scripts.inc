NewBarkTown_House2_hns_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "Ah! {PLAYER}!\p"
	.string "Mon mari est très occupé... J’ai\n"
	.string "peur qu’il se surmène!\p"
	.string "Quand il se plonge\n"
	.string "dans ses recherches\p"
	.string "sur les Pokémon, il\n"
	.string "en oublie de manger!$"

NewBarkTown_House2_Text_ElmsSon:
	.string "Moi, quand je serai grand, je\n"
	.string "veux être l’assistant de papa!\p"
	.string "Et je serai un super Professeur\n"
	.string "en Pokémon!$"
