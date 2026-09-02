SilphCo_6F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
	.string "La TEAM ROCKET a investi tout\n"
	.string "l'immeuble!$"

SilphCo_6F_Text_BetterGetBackToWork::
	.string "Allez, hop!  Au boulot!$"

SilphCo_6F_Text_HelpMePlease::
	.string "Pitié, pitié… Aidez-moi!$"

SilphCo_6F_Text_WeGotEngaged::
	.string "On va s'marier! Haha!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
	.string "Regarde-moi ça! Quel froussard\n"
	.string "celui-là!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
	.string "Il a besoin de quelqu'un… Alors\n"
	.string "je vais l'épouser!$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
	.string "La TEAM ROCKET veut dominer le\n"
	.string "monde avec des POKéMON!$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
	.string "Tu as fait fuir la TEAM ROCKET!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
	.string "Les produits POKéMON de la\n"
	.string "SYLPHE devaient les intéresser.$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
	.string "Travaille donc pour la SYLPHE\n"
	.string "quand tu auras l'âge!$"

SilphCo_6F_Text_Grunt1Intro::
	.string "Je suis l'un des 4 FRERES\n"
	.string "ROCKET!$"

SilphCo_6F_Text_Grunt1Defeat::
	.string "Oups… Dans le vent!$"

SilphCo_6F_Text_Grunt1PostBattle::
	.string "Pas grave! Mes frères me\n"
	.string "vengeront!$"

SilphCo_6F_Text_TaylorIntro::
	.string "Quel pourri ce PDG!\p"
	.string "Il a décidé de me muter au siège\n"
	.string "de TRIFOUILLI!$"

SilphCo_6F_Text_TaylorDefeat::
	.string "Zut!$"

SilphCo_6F_Text_TaylorPostBattle::
	.string "TRIFOUILLI? C'est au beau milieu\n"
	.string "de nulle part!$"

SilphCo_6F_Text_Grunt2Intro::
	.string "Tu oses défier la TEAM ROCKET?$"

SilphCo_6F_Text_Grunt2Defeat::
	.string "C'est pas juste.$"

SilphCo_6F_Text_Grunt2PostBattle::
	.string "Si t'es gentil, t'es pas\n"
	.string "méchant!$"

SilphCo_6F_Text_FloorSign::
	.string "SYLPHE SARL. 5ème étage.$"

