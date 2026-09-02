GoldenrodCity_DepartmentStore_4F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "J’aime les Pokémon forts! Alors\n"
    .string "je leur donne plein de Protéine\p"
    .string "pour monter leur attaque!$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "Le Fer, ça fait monter la\n"
    .string "Défense des Pokémon!$"

GoldenrodDeptStore_Text_4FGameboyKid:
	.string "Une rumeur disait que certains\n"
	.string "Pokémon n'évoluaient qu'après\p"
	.string "un échange par Câble Link.\p"
	.string "Pff…\p"
	.string "Quelle désinformation.\p"
	.string "Les Pokémon concernés sont:\p"
	.string "MACHOPEUR, KADABRA, SPECTRUM et…\n"
	.string "euh, GRAVALANCH.\p"
	.string "Mais tous évoluent en gagnant\n"
	.string "des niveaux.$"

GoldenrodDeptStore4_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore4_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore4_Pokemart:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

GoldenrodDeptStore_Text_4FDirectory:
    .string "Améliorez vos Pokémon!\n"
    .string "3{SUPER_E}: Pharmacie$"
