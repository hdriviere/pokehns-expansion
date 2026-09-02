LavenderTown_SoulHouse_hns_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "M.FUJI: Bienvenue à toi.\p"
	.string "Hmm... Tu as l'air d'être un\n"
	.string "dresseur\p"
	.string "de Pokémon doux et attentionné.\p"
	.string "Ceux qui aiment les Pokémon\n"
	.string "viennent ici saluer leur âme.\p"
	.string "Tu peux présenter ici tes\n"
	.string "condoléances.\p"
	.string "Cela leur fera plaisir.$"

SoulHouse_Text_Teacher:
	.string "Il y a d'autres tombes de\n"
	.string "Pokémon ici, je crois.\p"
	.string "Beaucoup de pièces ne sont\n"
	.string "réservées qu'à M.FUJI.$"

SoulHouse_Text_Lass:
	.string "J'suis venue avec ma môman pour\n"
	.string "voir les tombes de Pokémon...$"

SoulHouse_Text_Granny:
	.string "Les Pokémon que j'ai perdus...\p"
	.string "Je les aimais comme mes\n"
	.string "petitsenfants...$"
