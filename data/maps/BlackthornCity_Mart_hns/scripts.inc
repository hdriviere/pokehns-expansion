BlackthornCity_Mart_hns_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "Tu ne peux pas acheter de RAPPEL\p"
	.string "MAX mais il permet de ramener un\n"
	.string "Pokémon évanoui en pleine forme.\p"
	.string "Fais attention, ça\n"
	.string "ne restaure pas les\p"
	.string "POINTS DE POUVOIR\n"
	.string "des attaques.$"

BlackthornMart_Text_BlackBelt:
	.string "Le Max Repousse\n"
	.string "empêche les Pokémon\p"
	.string "de niveau inférieur\n"
	.string "de s’approcher de\p"
	.string "toi.\p"
	.string "C’est le Repousse le plus\n"
	.string "puissant de tous.$"
