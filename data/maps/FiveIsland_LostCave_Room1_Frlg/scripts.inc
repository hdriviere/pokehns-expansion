FiveIsland_LostCave_Room1_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAWSON, FiveIsland_LostCave_Room1_Text_LawsonIntro, FiveIsland_LostCave_Room1_Text_LawsonDefeat
	msgbox FiveIsland_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room1_Text_LawsonIntro::
	.string "Aaaaah!\p"
	.string "Je croyais que c'étaient des\n"
	.string "ruines anciennes sans danger.\p"
	.string "Mais ça grouille de fantômes!$"

FiveIsland_LostCave_Room1_Text_LawsonDefeat::
	.string "Aaaaïlle! Pitiéééé!!$"

FiveIsland_LostCave_Room1_Text_LawsonPostBattle::
	.string "J'essaie de sortir d'ici, mais\n"
	.string "je me retrouve toujours au même\p"
	.string "endroit.\p"
	.string "Peut-être que le nombre de\n"
	.string "rochers est un indice…$"

