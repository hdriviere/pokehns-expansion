LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.string "Les POKéMON sont les partenaires\n"
	.string "des hommes. Ils ne sont pas nos\p"
	.string "outils.\p"
	.string "Malheureusement, certaines\n"
	.string "personnes ne veulent pas\p"
	.string "comprendre ça…$"

LilycoveCity_House1_Text_Kecleon:
	.string "KECLEON: Kécléééon?$"

