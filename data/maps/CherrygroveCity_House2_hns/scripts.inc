CherrygroveCity_House2_hns_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "Quand je n'étais qu'un mioche,\n"
	.string "j'étais un super dresseur!\p"
	.string "Un p'tit conseil: attrape tous\n"
	.string "les Pokémon!\p"
	.string "Traite-les avec la plus grande\n"
	.string "gentillesse!$"
