CeruleanCity_Mart_hns_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "Tu croiseras beaucoup de\n"
	.string "dresseurs\p"
	.string "sur la route du CAP d'AZURIA.\p"
	.string "Ils voudront se mesurer à toi.$"

CeruleanMart_Text_CooltrainerF:
	.string "ONDINE est peutêtre la seule à\p"
	.string "pouvoir battre les dresseurs du\n"
	.string "CAP d'AZURIA.$"
