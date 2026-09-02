CianwoodShop_hns_MapScripts::
	.byte 0

CianwoodShop_EventScriptMan::	
	setvar VAR_OLIVINE_CITY_STATE, 4
	giveitem ITEM_SECRET_POTION
	end

CianwoodCity_EventScript_Pharmacist::
	lock
	faceplayer
	checkitem ITEM_SECRET_POTION
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_PharmacistAfter
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, CianwoodCity_EventScript_PharmacistAfter
	msgbox CianwoodCity_Text_PharmacistGivePotion, MSGBOX_DEFAULT
	giveitem ITEM_SECRET_POTION
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 4
	release
	end

CianwoodCity_EventScript_PharmacistAfter::
	msgbox CianwoodCity_Text_PharmacistDescribePotion, MSGBOX_DEFAULT
	closemessage
	release
	end


CianwoodCity_Text_PharmacistGivePotion:
	.string "Ton Pokémon semble en pleine\p"
	.string "forme. Quelque chose te\n"
	.string "tracasse?\p"
	.string "...\p"
	.string "Le PHARE Pokémon est en danger?\p"
	.string "J'ai pigé!\p"
	.string "Ca devrait faire l'affaire.$"

CianwoodCity_Text_ReceivedSecretpotion:
	.string "{PLAYER} reçoit la POTIONSECRET.$"

CianwoodCity_Text_PharmacistDescribePotion:
	.string "Ma POTIONSECRET est un peu trop\n"
	.string "forte, alors je ne la donne\l"
	.string "qu'en cas d'urgence.$"
