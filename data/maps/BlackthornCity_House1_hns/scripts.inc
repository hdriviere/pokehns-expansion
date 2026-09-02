BlackthornCity_House1_hns_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "Un clan de dresseurs commandant\p"
	.string "les dragons vit ici à EBENELLE.\p"
	.string "C'est pour cela qu'il y a\n"
	.string "beaucoup\p"
	.string "de légendes sur les dragons dans\n"
	.string "cette ville.$"

BlackthornCity_House1_Text_Dratini:
	.string "MINIDRACO: Draa!$"
