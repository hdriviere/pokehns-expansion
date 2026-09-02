FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FALLARBOR_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest::
	applymovement LOCALID_FALLARBOR_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_FALLARBOR_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting:
	.string "Oh, bonjour. Qui es-tu?\p"
	.string "D’accord, tu t’appelles\n"
	.string "{PLAYER}{KUN}. Tu es DRESSEUR,\p"
	.string "apparemment.\p"
	.string "Cela veut donc dire que tu\n"
	.string "utilises ce programme de Gestion\p"
	.string "de Stocks de POKéMON que j’ai\n"
	.string "développé.\p"
	.string "Enfin, c’est une conclusion que\n"
	.string "je tire d’un processus de\p"
	.string "déduction simple.\p"
	.string "Tu me parles parce que tu veux\n"
	.string "accéder à quelque chose sur ce\p"
	.string "PC.\p"
	.string "Oh, pardon, je ne me suis pas\n"
	.string "présentée. Je m’appelle ANNETTE.\p"
	.string "Enchantée. Je suis contente que\n"
	.string "tu utilises la Gestion de\p"
	.string "Stocks.\p"
	.string "Si tu en as l’occasion, viens me\n"
	.string "rendre visite. J’habite sur la\p"
	.string "ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Je me demande à quoi\n"
	.string "ressemblaient les POKéMON durant\p"
	.string "la préhistoire.\p"
	.string "Le MANIAQUE DES FOSSILES qui vit\n"
	.string "en bordure de la ville doit le\p"
	.string "savoir.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "Dans les champs d’AUTEQUIA, nous\n"
	.string "mettons de jeunes plants en\p"
	.string "terre. Ce sont des arbres très\n"
	.string "vivaces qui poussent dans la\p"
	.string "cendre volcanique.$"

