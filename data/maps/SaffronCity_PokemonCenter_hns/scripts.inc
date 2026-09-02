SaffronCity_PokemonCenter_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY_HNS
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "Comment sont les CENTRES Pokémon\n"
	.string "de JOHTO?\p"
	.string "...Je vois. Ils sont comme ceux\n"
	.string "de KANTO.\p"
	.string "Je peux aller à JOHTO sans\n"
	.string "crainte dans ce cas!$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "Je viens de traverser la GROTTE.\p"
	.string "Il y avait du grabuge à la\n"
	.string "CENTRALE je crois...$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "Il y a une étrange grotte\n"
	.string "à AZURIA.\p"
	.string "En bon MONTAGNARD, je devrais\n"
	.string "l'explorer, mais même moi, cet\l"
	.string "endroit m'effraie.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "Les BUREAUX de la SYLPHE SARL et\n"
	.string "la\p"
	.string "STATION du TRAIN MAGNET sont les\p"
	.string "choses à voir à SAFRANIA.$"
