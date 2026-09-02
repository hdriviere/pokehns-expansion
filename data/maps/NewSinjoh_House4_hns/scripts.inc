NewSinjoh_House4_hns_MapScripts::
	.byte 0

NewSinjoh_Cafe_Script_Sister::
	lock
	faceplayer
	message NewSinjoh_Cafe_Text_ResturantGreeting
	waitmessage
	pokemart NewSinjoh_Cafe_Pokemart_Resturant
	msgbox NewSinjoh_Cafe_Text_ResturantEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Cafe_Pokemart_Resturant:
	.2byte ITEM_YACHE_BERRY
    .2byte ITEM_LANSAT_BERRY
    .2byte ITEM_ROWAP_BERRY
    .2byte ITEM_BERRY_JUICE
	.2byte ITEM_SODA_POP
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_LEEK
	.2byte ITEM_BIG_ROOT
	.2byte ITEM_NONE
	release
	end

NewSinjoh_Cafe_Text_ResturantGreeting:
	.string "B-bonjour! Bienvenue au café!\n"
	.string "Que puis-je faire pour toi?$"

NewSinjoh_Cafe_Text_ResturantEnd:
	.string "Reviens nous voir!$"

NewSinjoh_Cafe_EventScript_BaldingMan::
	msgbox NewSinjoh_Cafe_Text_BaldingMan, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_BaldingMan:
	.string "Une famille d'ici tient ce café\n"
	.string "depuis aussi loin qu'on s'en\l"
	.string "souvienne.\p"
	.string "Leur plus jeune fille, là-bas,\n"
	.string "n'a pas l'habitude de servir\l"
	.string "d'étrangers.$"

NewSinjoh_Cafe_EventScript_ScientistF::
	msgbox NewSinjoh_Cafe_Text_ScientistF, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_ScientistF:
	.string "Cette boisson est trop booonne!\n"
	.string ".......\p"
	.string ".......\p"
	.string "Hahaha\p"
	.string ".......$"

NewSinjoh_Cafe_EventScript_ScientistM::
	lock
	faceplayer
	msgbox NewSinjoh_Cafe_Text_ScientistM, MSGBOX_DEFAULT
	closemessage
	release
	end

NewSinjoh_Cafe_Text_ScientistM:
	.string "Veuillez excuser ma collègue...\p"
	.string "Les boissons sont plus fortes\n"
	.string "que celles dont nous avons\l"
	.string "l'habitude à HOENN.\p"
	.string "J'ai tenté de la prévenir, mais\n"
	.string "elle voulait se détendre.\p"
	.string "Cette expédition de recherche a\n"
	.string "été éprouvante pour nous tous.$"

NewSinjoh_Cafe_EventScript_Gentleman::
	msgbox NewSinjoh_Cafe_Text_Gentleman, MSGBOX_NPC
	end

NewSinjoh_Cafe_Text_Gentleman:
	.string "Tu regardes quoi, gamin?\p"
	.string "Un homme et son Pokémon peuvent\n"
	.string "bien manger à la même table.$"

NewSinjoh_EventScript_Scyther::
	lock
	faceplayer
	playmoncry SPECIES_SCYTHER, 0
	msgbox NewSinjoh_Text_Scyther, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Scyther:
	.string "Insééé!$"
