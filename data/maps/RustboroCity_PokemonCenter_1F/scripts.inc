RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mon POKéMON est NAIF et celui de\n"
	.string "mon ami est JOVIAL. C’est leur\p"
	.string "nature.\p"
	.string "C’est fascinant de voir comme\n"
	.string "les POKéMON ont leur caractère!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Tout comme chez les hommes, il\n"
	.string "existe des POKéMON mâles et\p"
	.string "femelles.\p"
	.string "Mais la différence entre les\n"
	.string "deux sexes ne saute pas aux\p"
	.string "yeux.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "L’homme de la maison voisine m’a\n"
	.string "donné une CS!\p"
	.string "Je l’ai apprise à mon POKéMON\n"
	.string "pour qu’il COUPE les petits\p"
	.string "arbres.$"

