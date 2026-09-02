FuchsiaCity_House2_hns_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "Mon pépé est le GARDIEN du PARC\n"
	.string "SAFARI.\p"
	.string "Enfin... Il l'était.\p"
	.string "Il a décidé\n"
	.string "de prendre des\p"
	.string "vacances et de\n"
	.string "voyager tout seul.\p"
	.string "Il a démissionné juste comme ça.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "Les gens étaient déçus\n"
	.string "d'apprendre\p"
	.string "la fermeture du PARC SAFARI mais\n"
	.string "pépé est si têtu.$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "C'est la photo d'un vieil homme\p"
	.string "entouré de Pokémon.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "C'est la photo d'une\n"
	.string "grande plaine verdoyante\p"
	.string "avec des Pokémon\n"
	.string "rares tout partout.$"
