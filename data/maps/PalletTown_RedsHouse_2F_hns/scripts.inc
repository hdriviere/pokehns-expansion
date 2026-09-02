PalletTown_RedsHouse_2F_hns_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER} joue à la N64.\p"
	.string "Bon. On y va maintenant?$"

RedsHouse_Text_PC:
	.string "On n'a pas utilisé ceci depuis\n"
	.string "bien longtemps...$"
