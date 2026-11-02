Route2_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_RobRegister:
	.string "Donne-moi ton numéro!$"

Route2_Text_RobRematchIntro:
	.string "J'ai attrapé plus d'insectes!\n"
	.string "Regarde-les!$"

Route2_Text_RobRematchDefeat:
	.string "Il me faut de meilleurs\n"
	.string "insectes!$"

Route2_Text_RobPostRematch:
	.string "J'ai tous les insectes\n"
	.string "de JADIELLE.\p"
	.string "Existe-t-il une meilleure FORÊT\l"
	.string "ailleurs?$"

Route2_Text_BugCatcherRob_Seen:
	.string "Mes Pokémon insecte sont forts.\n"
	.string "Tu vas perdre!$"

Route2_Text_BugCatcherRob_Beaten:
	.string "Tout perdu!$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "Je vais chercher des Pokémon\n"
	.string "Insecte plus forts!$"

Route2_Text_BugCatcherEd_Seen:
	.string "Ça pique de se\n"
	.string "balader en short dans\p"
	.string "les hautes herbes,\n"
	.string "tu trouves pas?$"

Route2_Text_BugCatcherEd_Beaten:
	.string "Aïeuuu!$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "Ouille, ça va piquer quand je\n"
	.string "prendrai un bain!$"

Route2_Text_BugCatcherDoug_Seen:
	.string "Pourquoi les filles\n"
	.string "n'aiment pas les\p"
	.string "Pokémon insecte? C'est\n"
	.string "quoi cette question?$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "Naaaaan!$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "Les insectes ça fait chprouit\p"
	.string "quand tu appuies dessus.\p"
	.string "Et ça c'est super mignon, non?$"

Route2_Text_Sign:
	.string "ROUTE 2\p"
	.string "JADIELLE ARGENTA$"

Route2_Text_DiglettsCaveSign:
	.string "CAVE TAUPIQUEUR$"
