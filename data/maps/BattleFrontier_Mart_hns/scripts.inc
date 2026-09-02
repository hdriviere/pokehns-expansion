BattleFrontier_Mart_hns_MapScripts::
	.byte 0

BattleFrontier_Mart_EventScript_Clerk_hns::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart_hns
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart_hns:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan_hns::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson_hns, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman_hns::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy_hns::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems_hns, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson_hns:
	.string "Nous sommes venus accompagner\n"
	.string "notre petit-fils.\p"
	.string "On en profite pour acheter\n"
	.string "quelques souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift_hns:
	.string "Que penses-tu de ça, chéri? Ça\n"
	.string "ferait un joli cadeau, non?\p"
	.string "PRO… TE… INE? Ça m’a l’air\n"
	.string "d’être délicieux!$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems_hns:
	.string "Dans la ZONE DE COMBAT, on n’a\n"
	.string "pas toujours le droit d’utiliser\p"
	.string "des objets en combat.\p"
	.string "Ça rend les choses encore plus\n"
	.string "difficiles!$"

