CeladonCity_Apartments_RoofHouse_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_SLEEP_TALK, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_SLEEP_TALK
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "Je vais te raconter une histoire\n"
	.string "terrifiante...$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "... Oh là! Ça n’a aucun intérêt\n"
	.string "pendant la\p"
	.string "journée! Reviens cette nuit!$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "Il était une fois, un petit\n"
	.string "garçon\p"
	.string "qui reçut une nouvelle\n"
	.string "BICYCLETTE.\p"
	.string "Il voulut l'essayer tout de\n"
	.string "suite.\p"
	.string "Il s'amusait\n"
	.string "et n'avait pas\p"
	.string "remarqué que la nuit\n"
	.string "commençait à tomber...\p"
	.string "Tout en pédalant comme un\n"
	.string "furieux\p"
	.string "pour rentrer chez lui dans la\n"
	.string "nuit noire, son vélo ralentit!\p"
	.string "Les pédales devinrent lourdes!\p"
	.string "Epuisé, il s'arrêta mais la\n"
	.string "bicyclette roula vers l'arrière!\p"
	.string "Il lui semblait que le vélo\n"
	.string "était\p"
	.string "maudit et tentait de l'entraîner\n"
	.string "vers les ténèbres!\p"
	.string "...\p"
	.string ".......\p"
	.string "YAHAAAAAAHA!\p"
	.string "Il montait en fait la pente de\n"
	.string "la PISTE CYCLABLE!\p"
	.string "... Super histoire!\p"
	.string "Merci. Merci. Tu\n"
	.string "aimes tant ma belle\p"
	.string "histoire, voilà\n"
	.string "pour toi: la CT03!$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "La CT82 contient BLABLA DODO.\p"
	.string "Elle permet à un Pokémon endormi\n"
	.string "d'utiliser une capacité au\l"
	.string "hasard.\p"
	.string "Bonne chance pour dormir après\n"
	.string "cette histoire terrifiante!$"
