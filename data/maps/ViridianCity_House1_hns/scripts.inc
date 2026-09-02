ViridianCity_House1_hns_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "Est-ce que tu\n"
	.string "réfléchis assez\p"
	.string "avant de donner un\n"
	.string "surnom à un Pokémon?\p"
	.string "En leur donnant des\n"
	.string "noms intéressants,\p"
	.string "tu rendras les\n"
	.string "échanges avec d’autres\p"
	.string "Dresseurs encore plus amusants!$"

ViridianCity_House1_Text_Lass:
	.string "Mon PIAFABEC\n"
	.string "s’appelle Piaffy,\p"
	.string "et mon RATTATA\n"
	.string "s’appelle Rattatami!$"

ViridianCity_House1_Text_Speary:
	.string "PIAFFY: Piaaaa!$"

ViridianCity_House1_Text_Rattey:
	.string "Rattatami: Rataaa!$"

