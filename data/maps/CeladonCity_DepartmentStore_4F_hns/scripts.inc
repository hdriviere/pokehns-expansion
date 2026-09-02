CeladonCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "Je viens acheter une LETR SURF\n"
	.string "pour l'envoyer à ma copine.\p"
	.string "Quoi, ils sont en rupture?$"

CeladonDeptStore4F_Text_Youngster:
	.string "C'est le seul endroit où acheter\n"
	.string "une LETR JOLIE.\p"
	.string "Enfin, c'était le cas. Ils sont\n"
	.string "en rupture de stock.$"

CeladonDeptStore4F_Text_Directory:
	.string "Offrir, c'est merveilleux!\p"
	.string "3EME: CADEAUX DU       SAGE$"
