CeladonCity_DepartmentStore_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "Je commence à me\n"
	.string "mettre au dressage\p"
	.string "de Pokémon, à cause\n"
	.string "de l’influence\p"
	.string "de mon fils...\p"
	.string "Ils ont vraiment beaucoup\n"
	.string "d’objets intéressants, par ici!$"

CeladonDeptStore2F_Text_Youngster:
	.string "Mon père a du mal à retenir tous\n"
	.string "les\p"
	.string "objets et leurs fonctions...$"

CeladonDeptStore2F_Text_Directory:
	.string "De bons objets pour\n"
	.string "de bons Dresseurs!\p"
	.string "1{SUPER_ER}:\n"
	.string "Marché du Dresseur$"
