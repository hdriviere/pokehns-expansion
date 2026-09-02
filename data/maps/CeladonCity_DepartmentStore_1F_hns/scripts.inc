CeladonCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "Bienvenue au CENTRE COMMERCIAL\n"
    .string "de CELADOPOLE!\p"
    .string "Les informations sont sur le\n"
    .string "mur.$"

CeladonDeptStore_Text_1FGentleman:
    .string "Ce CENTRE COMMERCIAL appartient\n"
    .string "à\p"
    .string "la même chaîne que celui de\n"
    .string "DOUBLONVILLE.\p"
    .string "Ils ont été rénovés en même\n"
    .string "temps.$"

CeladonDeptStore_Text_1FTeacher:
    .string "C'est la première fois que je\n"
    .string "viens ici.\p"
    .string "C'est grand...\p"
    .string "Je vais me perdre. C'est sûr.$"

CeladonDeptStore_Text_1FDirectory:
    .string "RDC:  COMPTOIR       SERVICE\p"
    .string "1ER:  MARCHE DU       DRESSEUR\p"
    .string "2EME: MARCHE AUX       CT\p"
    .string "3EME: CADEAUX DU       SAGE\p"
    .string "4EME: POTIONS, etc\p"
    .string "5EME: ESPACE TOIT$"
