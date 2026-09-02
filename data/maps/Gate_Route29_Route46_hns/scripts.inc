Gate_Route29_Route46_hns_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "On ne peut pas escalader les\n"
	.string "bords.\p"
	.string "Mais on peut sauter\n"
	.string "par-dessus quand\p"
	.string "on descend pour\n"
	.string "aller plus vite!$"

Gate_Route29_Route46_Text_Youngster:
	.string "Les Pokémon qui apparaissent\n"
	.string "là-bas sont un peu différents.\p"
	.string "Si tu veux tous les attraper, il\n"
	.string "faut chercher un peu partout!$"
