Route8_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE_HNS, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS_HNS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE_HNS, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM_HNS, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM_HNS, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "Nous sommes la “Fédération des\n"
	.string "Dresseurs de Pokémon de Kanto”.\p"
	.string "On va te faire ta fête!$"

Route8_Text_BikerDwayneBeaten:
	.string "P-p-pardon!$"

Route8_Text_BikerDwayneAfter:
	.string "La “Fédération\n"
	.string "des Dresseurs de\p"
	.string "Pokémon de Kanto”\n"
	.string "est invincible!$"

Route8_Text_BikerHarrisSeen:
	.string "La police a fermé notre\n"
	.string "SOUTERRAIN!\p"
	.string "C'est injuste! C'est\n"
	.string "dégueulasse!$"

Route8_Text_BikerHarrisBeaten:
	.string "P-p-pardon!$"

Route8_Text_BikerHarrisAfter:
	.string "Battu par quelqu’un de Johto...$"

Route8_Text_BikerZekeSeen:
	.string "On est la FEDERATION des\n"
	.string "dresseurs de KANTO. On est cool!$"

Route8_Text_BikerZekeBeaten:
	.string "Oups! Pardon!$"

Route8_Text_BikerZekeAfter:
	.string "On va essayer de n'plus\n"
	.string "déranger... Pardon.$"

Route8_Text_SupernerdSamSeen:
	.string "Comment ça marche un Train\n"
	.string "Magnétique?$"

Route8_Text_SupernerdSamBeaten:
	.string "Moi je veux voir le TRAIN\n"
	.string "MAGNET...$"

Route8_Text_SupernerdSamAfter:
	.string "La puissance magnétique, c'est\n"
	.string "terrible!$"

Route8_Text_SupernerdTomSeen:
	.string "Hmm... Tu en as des bô BADGES.$"

Route8_Text_SupernerdTomBeaten:
	.string "Pas mal... Je m'y attendais!$"

Route8_Text_SupernerdTomAfter:
	.string "Les BADGES donnent l'avantage en\n"
	.string "combat.$"

Route8_Text_LockedDoor:
	.string "C'est fermé...$"

Route8_Text_UndergroundPathSign:
	.string "L'affiche est déchirée.\p"
	.string "C'est impossible de la lire...$"
