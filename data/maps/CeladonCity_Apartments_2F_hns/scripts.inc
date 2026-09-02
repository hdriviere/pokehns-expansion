CeladonCity_Apartments_2F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} allume le PC.\p"
	.string "…\p"
	.string "Quelqu'un était en train\n"
	.string "d'écrire un e-mail...\p"
	.string "...J'espère que vous viendrez à\n"
	.string "KANTO.\p"
	.string "Vous verrez à quel point les\n"
	.string "choses ont changé ici.\p"
	.string "Vous verrez même des Pokémon qui\p"
	.string "n'existent pas à JOHTO.\p"
	.string "Pour le PRODUCTEUR\p"
	.string "...$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "BUREAU DE DÉVELOPPEMENT HEART &\n"
	.string "SOUL$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "Salut à tous, Patch 15--\p"
	.string "Pardon, je veux dire...\p"
	.string "Salut! Je suis le DIRECTEUR\n"
	.string "du JEU!\p"
	.string "J'ai créé cartes, tilesets,\n"
	.string "scripts et bien plus encore.\p"
	.string "Mais rien n'aurait été possible\n"
	.string "sans les autres développeurs et\l"
	.string "les testeurs.\p"
	.string "Merci d'avoir joué! J'espère que\n"
	.string "POKéMON HEART & SOUL vous a plu.$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "Nous reconstruisons ce jeu avec\n"
	.string "pokeemerald-expansion!$"

CeladonMansion2F_Text_TixoRebel:
	.string "Tu connais THE EGGENING?\n"
	.string "C'était un bug des tests qui\l"
	.string "changeait au hasard des Pokémon\l"
	.string "en ŒUFS!\p"
	.string "J'ai développé le correctif!$"

CeladonMansion2F_Text_Phant:
	.string "J'adore les DEMAKES!\p"
	.string "Tu as joué à SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH?\l"
	.string "C'est moi qui l'ai traduit!\p"
	.string "Mon prochain DEMAKE portera\n"
	.string "peut-être sur ALOLA!$"

CeladonMansion2F_Text_Exclsior:
	.string "J'ai créé les sprites de surf\n"
	.string "propres à chaque Pokémon!\p"
	.string "Le projet étant OPEN SOURCE, tu\n"
	.string "peux y ajouter tes fonctions!$"

CeladonMansion2F_Text_DaniRaibow:
	.string "Salut!\p"
	.string "Je sais repérer les problèmes\n"
	.string "et corriger les petits.\p"
	.string "Tu veux une blague?\p"
	.string "PETER a voulu apprendre\n"
	.string "DRACO-SOUFFLE à DRACOLOSSE.\p"
	.string "Mais DRACOLOSSE allait trop vite\n"
	.string "avec VITESSE EXTRÊME: il n'a pas\l"
	.string "pu la rattraper!$"
