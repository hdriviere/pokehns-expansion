GoldenrodCity_UndergroundEntrance_hns_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "Fiou! J’ai été provoqué en duel\n"
	.string "de Pokémon\p"
	.string "dans le tunnel, j’ai eu la peur\n"
	.string "de ma\p"
	.string "vie! Fais attention si tu y vas.$"


GoldenrodUnderground1_Text_Teacher:
	.string "Il y a des boutiques\n"
	.string "en bas... Mais\p"
	.string "il y a aussi\n"
	.string "des Dresseurs...\p"
	.string "J’ai peur d’y aller.$"
