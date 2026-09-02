OlivineCity_House3_hns_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "OLIVILLE est au bord de la mer!\p"
	.string "Et qui dit mer dit forcément\n"
	.string "poissons!\p"
	.string "Je pêche ici depuis 30 ans.\p"
	.string "Veux-tu te tourner vers la mer\n"
	.string "et t'essayer à la pêche?$"

OlivineCity_Text_GiveGoodRod:
	.string "Ah, ah, ah! Voilà un nouveau\n"
	.string "pêcheur en devenir!$"

OlivineCity_Text_GaveGoodRod:
	.string "Les poissons ne vivent pas\n"
	.string "seulement dans la mer, mais\l"
	.string "partout où il\l"
	.string "y a de l'eau.\p"
	.string "Au fait, ton POKéDEX indique les\n"
	.string "groupes de Pokémon à pêcher.\p"
	.string "Différents endroits peuvent\n"
	.string "abriter des poissons similaires.$"

OlivineCity_Text_DontWantGoodRod:
	.string "Quoiii? Tu n'aimes pas pêcher!?\n"
	.string "C'est incompréhensible!$"

OlivineCity_Text_HaveGoodRod:
	.string "Alors, ça mord?\n"
	.string "Tu en as attrapé un gros?$"
