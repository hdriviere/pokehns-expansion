PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "De quelle couleur est ta CARTE\n"
	.string "DE DRESSEUR? La mienne est\p"
	.string "cuivrée!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "PACIFIVILLE flotte au-dessus\n"
	.string "d’une colonie de CORAYON.\p"
	.string "Ça semble incroyable, non?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "On dit que les ancêtres des\n"
	.string "habitants de PACIFIVILLE sont\p"
	.string "nés sur des bateaux, pour y\n"
	.string "vivre et y mourir.\p"
	.string "Je crois qu’ils vivaient comme\n"
	.string "ça parce qu’ils cherchaient\p"
	.string "quelque chose.$"

