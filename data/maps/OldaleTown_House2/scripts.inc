OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Lorsque les POKéMON se battent,\n"
	.string "ils gagnent de l’expérience et\p"
	.string "deviennent plus forts.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Si les POKéMON de ton équipe\n"
	.string "deviennent plus forts, tu\p"
	.string "pourras voyager plus loin.$"

