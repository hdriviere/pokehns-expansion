LavenderTown_House1_hns_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "Hé, tu le crois, ça?\p"
	.string "Il paraît qu’il y a des gens qui\n"
	.string "arrêtent d’aimer leurs Pokémon\p"
	.string "et qui les abandonnent!\p"
	.string "Pépé recueille ces\n"
	.string "pauvres Pokémon\p"
	.string "abandonnés et\n"
	.string "en prend soin.$"
LavenderTown_House1_Text_Guy:
	.string "M. FUJI vit bien ici, mais il\n"
	.string "est absent. Il doit être à la\l"
	.string "MAISON DES SOUVENIRS.$"
LavenderTown_House1_Text_Marowak:
	.string ".............................$"

LavenderTown_House1_Text_Marowak2:
	.string "L'OSSATUEUR reste silencieux,\n"
	.string "mais il semble très heureux.$"
