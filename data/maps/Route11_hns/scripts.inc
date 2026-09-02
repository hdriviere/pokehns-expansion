Route11_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN_HNS, Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON_HNS, Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN_HNS, Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL_HNS, Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_EventScript_Item_Grass_Knot::
    finditem ITEM_TM_GRASS_KNOT
    end

Route11_Text_Engineer:
	.string "J'ai vu un étrange Pokémon\n"
	.string "grimper aux arbres, mais il ne\l"
	.string "ressemblait\l"
	.string "pas à FÉROSINGE...$"

Route11_Text_YoungsterOwenSeen:
	.string "Y'a pas de triche à Pokémon.\p"
	.string "Etre honnête, ça c'est chouette!$"

Route11_Text_YoungsterOwenBeaten:
	.string "Hein? Impossible!$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "J'ai combattu avec honneur.\p"
	.string "Je ne regrette rien de rien.$"

Route11_Text_YoungsterJasonSeen:
	.string "Porter des shorts dans l'herbe,\n"
	.string "ça\p"
	.string "pique à donf...  Pas cool.$"

Route11_Text_YoungsterJasonBeaten:
	.string "Aïeuuuuuuu!$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "Je vais attraper d’autres\n"
	.string "Pokémon dans les herbes.$"

Route11_Text_PsychicHermanSeen:
	.string "...$"

Route11_Text_PsychicHermanBeaten:
	.string "...$"

Route11_Text_PsychicHermanAfterBattle:
	.string "...\p"
	.string "Je n’aurai pas dû fermer les\n"
	.string "yeux...$"

Route11_Text_PsychicFidelSeen:
	.string "Je vois tout...\p"
	.string "Présent, futur... Combat!$"

Route11_Text_PsychicFidelBeaten:
	.string "Heu... Je n’avais pas prévu ta\n"
	.string "force!$"

Route11_Text_PsychicFidelAfterBattle:
	.string "La force de la volonté...\p"
	.string "C’est la confiance dans ton\n"
	.string "équipe qui fait ta force.$"

Route11_Text_Sign:
	.string "ROUTE 11$"
