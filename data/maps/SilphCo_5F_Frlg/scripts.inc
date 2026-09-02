SilphCo_5F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
	.string "La TEAM ROCKET cherche un\n"
	.string "intrus. C'est toi, non?$"

SilphCo_5F_Text_YoureOurHeroThankYou::
	.string "La TEAM ROCKET est battue! Tu\n"
	.string "nous as sauvés!$"

SilphCo_5F_Text_Grunt1Intro::
	.string "Il paraît qu'un gosse se balade\n"
	.string "dans le coin…$"

SilphCo_5F_Text_Grunt1Defeat::
	.string "Vlan!$"

SilphCo_5F_Text_Grunt1PostBattle::
	.string "C'est pas très malin d'provoquer\n"
	.string "la TEAM ROCKET!$"

SilphCo_5F_Text_BeauIntro::
	.string "Nous étudions la technologie des\n"
	.string "POKé BALLS!$"

SilphCo_5F_Text_BeauDefeat::
	.string "PAF! J'suis mauvais!$"

SilphCo_5F_Text_BeauPostBattle::
	.string "Nous recherchons la POKé BALL\n"
	.string "ultime, capable de tout\p"
	.string "attraper!$"

SilphCo_5F_Text_DaltonIntro::
	.string "Mais?\p"
	.string "C'est pas pour les p'tits\n"
	.string "morveux ici!$"

SilphCo_5F_Text_DaltonDefeat::
	.string "Non! Mon Dieu!$"

SilphCo_5F_Text_DaltonPostBattle::
	.string "Tu n'es qu'au 4ème étage! Le\n"
	.string "chef est encore loin!$"

SilphCo_5F_Text_Grunt2Intro::
	.string "Cause meilleur à la grande TEAM\n"
	.string "ROCKET!$"

SilphCo_5F_Text_Grunt2Defeat::
	.string "Kheu… Kheu…$"

SilphCo_5F_Text_Grunt2PostBattle::
	.string "Ce qui me rappelle…\p"
	.string "SMOGO évolue en SMOGOGO!$"

SilphCo_5F_Text_PorygonFirstVRMon::
	.string "C'est un RAPPORT sur les\n"
	.string "POKéMON!\p"
	.string "PORYGON: POKéMON virtuel, créé\n"
	.string "par le LABO POKéMON!$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
	.string "C'est un RAPPORT sur les\n"
	.string "POKéMON!\p"
	.string "Il existe plus de 350 attaques\n"
	.string "pour les POKéMON!$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
	.string "C'est un RAPPORT sur les\n"
	.string "POKéMON!\p"
	.string "Certains POKéMON évoluent quand\n"
	.string "ils sont échangés.$"

SilphCo_5F_Text_FloorSign::
	.string "SYLPHE SARL. 4ème étage.$"

SilphCo_5F_Text_RocketBossLookingForStrongMons::
	.string "Ces types qui ont pris\n"
	.string "l'immeuble…\p"
	.string "Leur chef a dit qu'il cherchait\n"
	.string "des POKéMON costauds.\p"
	.string "J'espère que notre PDG a réussi\n"
	.string "à leur échapper.$"
