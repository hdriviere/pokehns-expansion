CeruleanCity_House2_hns_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "On raconte qu’un drôle de type\n"
	.string "rôde dans le coin.\p"
	.string "Si c’est un voleur, il va\n"
	.string "entendre parler de moi!$"

CeruleanPolice_Text_PokefanF:
	.string "Il y a longtemps, on a été\n"
	.string "cambriolés...$"

CeruleanPolice_Text_Diglett:
	.string "TAUPIQUEUR: Taupi!$"
