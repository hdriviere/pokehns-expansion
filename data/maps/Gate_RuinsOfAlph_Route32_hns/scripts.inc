Gate_RuinsOfAlph_Route32_hns_MapScripts::
	.byte 0


Gate_RuinsOfAlph_Route32_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route32_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route32_Text_PokefanM:
	.string "Oh! Tu t’intéresses\n"
	.string "aux Ruines d’Alpha?\p"
	.string "Tu veux devenir\n"
	.string "scientifique?$"

Gate_RuinsOfAlph_Route32_Text_Youngster:
	.string "Les panneaux de pierre\n"
	.string "sont illustrés! Et\p"
	.string "ils bougent... A\n"
	.string "quoi ça peut servir?$"
