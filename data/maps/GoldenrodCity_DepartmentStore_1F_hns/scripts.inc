GoldenrodCity_DepartmentStore_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "Bienvenue au CENTRE COMMERCIAL\n"
    .string "de DOUBLONVILLE.$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "Le CENTRE COMMERCIAL a un tas de\n"
    .string "bons produits.\p"
    .string "Mais certains objets ne sont\p"
    .string "disponibles qu'en prix à gagner\n"
    .string "au CASINO.$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "Je vais encore faire plein de\n"
    .string "shopping aujourd’hui!$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "Maman est la reine des courses!\p"
    .string "Elle achète toujours les trucs\n"
    .string "un peu moins chers!$"

GoldenrodDeptStore1_Text_Directory:
	.string "RDC ACCUEIL\n"
	.string "VOUS ETES ICI.\p"
	.string "1ER MARCHE DES DRESSEURS\p"
	.string "2E COLLECTION COMBAT\p"
	.string "3E BOITE A PHARMACIE\p"
	.string "4E COIN DES CT\p"
	.string "5E PLACE TRANQUILLE\p"
	.string "TOIT PANORAMIQUE$"
