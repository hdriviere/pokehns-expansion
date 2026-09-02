SproutTower_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO_HNS, SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND_HNS, SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "Toutefois, la TOUR\n"
	.string "ne cédera pas même\p"
	.string "lors d'un grand\n"
	.string "et rude combat.$"

SproutTower_Text_SageNico_Beaten:
	.string "J'ai perdu... Je suis faible.$"

SproutTower_Text_SageNico_AfterBattle:
	.string "Le pilier flexible protège la\n"
	.string "TOUR de\p"
	.string "tout, même des séismes.$"

SproutTower_Text_SageEdmond_Seen:
	.string "Volez comme vents et feuilles!\n"
	.string "Combat!$"

SproutTower_Text_SageEdmond_Beaten:
	.string "Mais qu’est-ce que ça veut dire!$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "J’ai essayé de\n"
	.string "copier les gracieux\p"
	.string "mouvements de\n"
	.string "CHETIFLOR en combat...\p"
	.string "Mais je manque encore\n"
	.string "d’entraînement.$"

SproutTower_Text_2F_Statue:
	.string "C’est le Pokémon\n"
	.string "vénéré ici...\p"
	.string "Cette seule pensée\n"
	.string "impose le respect.$"
