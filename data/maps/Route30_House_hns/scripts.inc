Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "Suis le chemin vers le nord.\p"
	.string "Tu y verras la maison\n"
	.string "de M.Pokémon.\p"
	.string "Mais avant, laisse-moi te parler\n"
	.string "des BAIES!\p"
	.string "Les Pokémon se soignent avec\n"
	.string "des BAIES.\p"
	.string "Ils peuvent même manger celles\n"
	.string "qu'ils tiennent en combat.\p"
	.string "FARGAS peut changer les BAIES en\n"
	.string "BALLS à ECORCIA.\p"
	.string "Tiens. Je t'en donne une!$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Les arbres portent des BAIES.\p"
	.string "Elles repoussent après quelques\n"
	.string "heures.$"
