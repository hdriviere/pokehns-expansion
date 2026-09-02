SaffronCity_Tunnel_NS_hns_MapScripts::
	.byte 0

SaffronCity_Tunnel_NS_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION, SaffronCity_Tunnel_NS_EventScript_BaldingManAfter
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Tunnel_NS_EventScript_BaldingManDetected
	closemessage
	release
	end

SaffronCity_Tunnel_NS_EventScript_BaldingManDetected::
	playse SE_PIN
	applymovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAFFRONTUNNEL_UNCLE_RAGE
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected, MSGBOX_DEFAULT
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_ITEM_UNDERGROUND_PATH_TM_EXPLOSION
SaffronCity_Tunnel_NS_EventScript_BaldingManAfter::
	msgbox SaffronCity_Tunnel_NS_Text_BaldingManGaveTm, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Tunnel_NS_Text_BaldingManIntro:
	.string "Tu n’as pas à...\p"
	.string "te méfier...\p"
	.string "de moi...\p"
	.string "Il y a plein de gens bizarres\p"
	.string "dans ces souterrains déserts.\p"
	.string "Et ils gênent...\p"
	.string "tout le monde...\p"
	.string "Ah... Qu’ils m’énervent...$"

SaffronCity_Tunnel_NS_Text_BaldingManCandybarDetected:
	.string "Ah!\n"
	.string "C'est un BONBON RAGE!\p"
	.string "Tu me le donnes?\n"
	.string "S'il te plaît!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveCandybar:
	.string "{PLAYER} donne le BONBON RAGE\n"
	.string "à l'homme du souterrain.\p"
	.string "Miam!\p"
	.string "Que c'est énervant!\p"
	.string "Mais c'est tellement bon!\p"
	.string "Miam miam!\p"
	.string "Aargh! Ça me met en rage!\p"
	.string "Miam miam!\p"
	.string "Aargh...\p"
	.string "...................Ouf!\p"
	.string "Je me sens beaucoup mieux!\n"
	.string "Merci pour le bonbon!\l"
	.string "Je veux que tu prennes ceci!$"

SaffronCity_Tunnel_NS_Text_BaldingManGaveTm:
	.string "La CT 64 contient........\p"
	.string "tic-\n"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic-\l"
	.string "            tac\l"
	.string "tic.....\l"
	.string "......................\l"
	.string "......................\l"
	.string "BOUM!!!$"
