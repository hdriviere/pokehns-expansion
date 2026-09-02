VioletCity_House2_hns_MapScripts::
	.byte 0

VioletCity_House2_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VioletCity_NicknameHouse_Text_Bird, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_NicknameHouse_Text_Teacher:
	.string "Pour donner des noms rigolos à\n"
	.string "ses Pokémon...\p"
	.string "Elle utilise le nom de ses plats\n"
	.string "préférés.$"

VioletCity_NicknameHouse_Text_Lass:
	.string "J’ai appelé mon ROUCOOL Melba!$"

VioletCity_NicknameHouse_Text_Bird:
	.string "Melba: Rouuu!$"
