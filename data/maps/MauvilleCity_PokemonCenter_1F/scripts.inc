MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "L’homme qui est là-bas dit des\n"
	.string "choses étranges.\p"
	.string "Il est marrant, mais bizarre\n"
	.string "aussi. Je ne suis pas près de\p"
	.string "l’oublier!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "Quand j’ai échangé des données\n"
	.string "au CENTRE DE DONNEES, il y a eu\p"
	.string "une mise à jour de ce qui est à\n"
	.string "la mode à MYOKARA.\p"
	.string "Maintenant, j’ai les mêmes que\n"
	.string "mes amis!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "Un CENTRE DE DONNEES a ouvert à\n"
	.string "l’étage du CENTRE POKéMON.\p"
	.string "Je ne sais pas de quoi il s’agit\n"
	.string "au juste, mais ça a l’air sympa.\p"
	.string "Je passerai voir!$"

