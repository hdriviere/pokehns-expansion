GoldenrodCity_DepartmentStore_7F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT_HNS
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F_HNS
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_ROOF_NERD
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
    .string "Fouiiii!\p"
    .string "Je vais souvent sur le toit pour\p"
    .string "me reposer après les courses.$"

GoldenrodDeptStore_Text_RoofFisher:
    .string "Pardon? Comment ça un adulte n'a\n"
    .string "pas le droit de faire ça?\p"
    .string "Je veux toutes les poupées!$"

GoldenrodDeptStore_Text_RoofTwin:
    .string "Ils font des prix spéciaux ici\n"
    .string "de temps en temps.$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
    .string "Oh!$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
    .string "Tu me lâches, ouais?$"

GoldenrodDeptStore_Text_RoofPokefanM:
    .string "Je veux acheter un truc mais je\n"
    .string "n'ai\p"
    .string "pas assez d'argent sur moi...\p"
    .string "Je vais peut-être vendre les\n"
    .string "BAIES que j'ai trouvées.$"

GoldenrodDeptStore_Text_RoofTeacher:
    .string "Oh! Tout est si bon marché!\p"
    .string "Mon SAC est plein à craquer!$"

GoldenrodDeptStore_Text_RoofBugCatcher:
    .string "Mes Pokémon sont\n"
    .string "toujours empoisonnés\p"
    .string "ou paralysés au\n"
    .string "mauvais moment.\p"
    .string "Je vais donc acheter TOTAL SOIN.\p"
    .string "Il en reste, tu crois?$"
