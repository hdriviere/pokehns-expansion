CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "Tiens donc... Peu de monde vient\n"
	.string "me rendre visite ici...\p"
	.string "Dans ma jeunesse,\n"
	.string "j’étais Dresseur\p"
	.string "de Pokémon. Je\n"
	.string "mettais toutes mes\p"
	.string "forces à escalader telle ou\n"
	.string "telle tour,\p"
	.string "ou à explorer le fond de la\n"
	.string "mer...\p"
	.string "Et maintenant, je\n"
	.string "vis ici, sur cette\p"
	.string "plage, écoutant\n"
	.string "le chant du vent\p"
	.string "et des vagues...$"

CianwoodCity_Text_BellTowerStory:
	.string "Connais-tu la Tour Carillon de\n"
	.string "Rosalia?\p"
	.string "On trouve au sommet\n"
	.string "de cette Tour une\p"
	.string "cloche appelée le\n"
	.string "Glas Transparent.\p"
	.string "Il ne sonne jamais, même quand\p"
	.string "le vent se déchaîne.\p"
	.string "Mais il existe un moyen, et un\n"
	.string "seul, de le faire tinter...\p"
	.string "Et c’est...\p"
	.string "D’avoir un Glas\n"
	.string "Transparent identique\p"
	.string "à celui qui est au\n"
	.string "sommet de la Tour.\p"
	.string "J’ai passé de\n"
	.string "longues années à\p"
	.string "chercher ce Glas...\n"
	.string "mais j’ai échoué...$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "As-tu entendu\n"
	.string "parler de la cascade\p"
	.string "qui coule au fond\n"
	.string "des Tourb’Iles?\p"
	.string "On trouve au pied\n"
	.string "de cette cascade\p"
	.string "une cloche appelée\n"
	.string "le Glas Tempête.\p"
	.string "Il ne sonne jamais, même quand\p"
	.string "les vagues se déchaînent.\p"
	.string "Mais il existe un moyen, et un\n"
	.string "seul, de le faire tinter...\p"
	.string "Et c’est...\p"
	.string "D’avoir un Glas\n"
	.string "Tempête identique\p"
	.string "à celui qui est au\n"
	.string "pied de la cascade.\p"
	.string "J’ai passé de\n"
	.string "longues années à\p"
	.string "chercher ce Glas...\n"
	.string "mais j’ai échoué...$"

CianwoodCity_Text_ClearBellReaction:
	.string "Comment?! Tu as trouvé le Glas\n"
	.string "Transparent?!\p"
	.string "Tu as réussi là où j’ai\n"
	.string "échoué... Je vois... Tu es...\p"
	.string "... ... Je l’entends...\p"
	.string "Le Glas Transparent\n"
	.string "en haut de la Tour\p"
	.string "résonne jusqu’ici,\n"
	.string "porté par le vent...$"

CianwoodCity_Text_TidalBellReaction:
	.string "Comment?! Tu as trouvé le Glas\n"
	.string "Tempête?!\p"
	.string "Tu as réussi là où j’ai\n"
	.string "échoué... Je vois... Tu es...\p"
	.string "... ... Je l’entends...\p"
	.string "Le Glas Tempête au\n"
	.string "cœur des Tourb’Iles\p"
	.string "résonne jusqu’ici,\n"
	.string "porté par le vent...$"
