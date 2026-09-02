MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "La puissance contenue dans le\n"
	.string "METEORITE…\p"
	.string "En l’amplifiant avec cette\n"
	.string "machine, l’activité volcanique\p"
	.string "du MONT CHIMNEE va s’intensifier\n"
	.string "instantanément…\p"
	.string "Son énergie va grandir à\n"
	.string "l’intérieur de ce cratère et…\p"
	.string "Hahaha…$"

MtChimney_Text_MaxieIntro:
	.string "MAX: Hum… Qui es-tu?\p"
	.string "… … … … … … … … … … … …\p"
	.string "J’ai entendu ARTHUR se plaindre\n"
	.string "d’un DRESSEUR qui se serait mêlé\p"
	.string "des affaires de la TEAM AQUA.\p"
	.string "Il devait parler de toi, je\n"
	.string "pense.\p"
	.string "Humpf! Alors tu veux également\n"
	.string "te mêler des affaires de la TEAM\p"
	.string "MAGMA?\p"
	.string "Ecoute-moi bien! Les êtres\n"
	.string "vivants ont besoin de la terre\p"
	.string "pour se développer.\p"
	.string "La terre représente tout! C’est\n"
	.string "le berceau de toute vie!\p"
	.string "C’est pour cela que la TEAM\n"
	.string "MAGMA s’est engagée à étendre la\p"
	.string "terre.\p"
	.string "Notre but est de faire prospérer\n"
	.string "les êtres humains et les\p"
	.string "POKéMON!\p"
	.string "Et pour cela, nous avons besoin\n"
	.string "de la puissance qui sommeille\p"
	.string "dans cette montagne…\p"
	.string "Oh, tu n’avais pas vraiment\n"
	.string "besoin de savoir tout ça…\p"
	.string "Mais peu importe! Je vais te\n"
	.string "montrer ce qu’il en coûte de se\p"
	.string "mêler de nos affaires!$"

MtChimney_Text_MaxieDefeat:
	.string "Quoi?!\p"
	.string "Moi, MAX, j’ai été pris au\n"
	.string "dépourvu?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAX: Ça suffit. Je pars pour\n"
	.string "cette fois.\p"
	.string "Mais n’espère pas ne plus\n"
	.string "entendre parler de la TEAM\p"
	.string "MAGMA.\p"
	.string "Hahaha…\p"
	.string "Même sans le METEORITE, si nous\n"
	.string "parvenons à obtenir l’ORBE…\p"
	.string "Alors là!$"

MtChimney_Text_TabithaIntro:
	.string "Hé, hé, hé!\p"
	.string "Alors t’as fait tout le chemin\n"
	.string "jusqu’ici!\p"
	.string "Mais il est trop tard! J’ai déjà\n"
	.string "remis le METEORITE du SITE\p"
	.string "METEORE au CHEF!$"

MtChimney_Text_TabithaDefeat:
	.string "Héhéhé…\p"
	.string "Même si j’ai perdu, si notre\n"
	.string "chef arrive à réveiller cette\p"
	.string "chose…$"

MtChimney_Text_TabithaPostBattle:
	.string "CHEF, vite! Donne-lui l’énergie\n"
	.string "du METEORITE!\p"
	.string "Héhéhé…$"

MtChimney_Text_Grunt2Intro:
	.string "Nous, la TEAM MAGMA, nous\n"
	.string "travaillons dur dans l’intérêt\p"
	.string "de tous.\p"
	.string "Si la puissance de cette chose\n"
	.string "étendait la terre, il y aurait\p"
	.string "plus d’espace pour vivre.\p"
	.string "Tout le monde serait heureux!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hum? Tu veux dire que j’ai\n"
	.string "perdu?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Notre CHEF dit que ça rendra\n"
	.string "tout le monde heureux.\p"
	.string "Mais pourquoi tout le monde se\n"
	.string "met en travers de notre route?$"

MtChimney_Text_Grunt1Intro:
	.string "S’il y avait plus de terre, je\n"
	.string "pourrais avoir ma propre maison!\p"
	.string "Je vais en construire une sur de\n"
	.string "la lave froide!$"

MtChimney_Text_Grunt1Defeat:
	.string "Mon rêve de grande maison…$"

MtChimney_Text_Grunt1PostBattle:
	.string "A ton âge, tu devrais être en\n"
	.string "train de jouer dans le sable!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Cette TEAM AQUA est agaçante…\n"
	.string "Ils font toujours échouer nos\p"
	.string "plans!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "Les METEORITES contiennent une\n"
	.string "puissance stupéfiante!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Tu ferais bien de pas te mêler\n"
	.string "de ça!\p"
	.string "Nous essayons de réveiller cette\n"
	.string "chose pour le bien de tous!$"

MtChimney_Text_AquasNameSimilar:
	.string "Nous sommes la TEAM MAGMA!\p"
	.string "Ils sont la TEAM AQUA!\p"
	.string "Ça m’énerve vraiment qu’ils\n"
	.string "utilisent un nom comme le nôtre!$"

MtChimney_Text_DouseThemInFire:
	.string "Yé! Fais-en du feu!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "On va continuer à créer plus de\n"
	.string "terre!$"

MtChimney_Text_Bufoh:
	.string "Youhou!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARTHUR: Grr, {PLAYER}!\p"
	.string "J’aurais dû me douter que tu\n"
	.string "pointerais le bout de ton nez!\p"
	.string "Vois par toi-même de quoi sont\n"
	.string "capables les fanatiques de la\p"
	.string "TEAM MAGMA!\p"
	.string "Ils essaient d’injecter la\n"
	.string "puissance du METEORITE volé à\p"
	.string "l’intérieur du volcan!\p"
	.string "A cause d’eux, le volcan risque\n"
	.string "d’entrer en éruption!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARTHUR: Arrrgh!\p"
	.string "Je veux arrêter ce MAX, mais je\n"
	.string "ne peux pas!\p"
	.string "Je suis trop occupé à me battre\n"
	.string "contre trois adversaires à la\p"
	.string "fois.$"

MtChimney_Text_ArchieThankYou:
	.string "ARTHUR: {PLAYER}! Merci!\p"
	.string "Grâce à ton aide, nous avons\n"
	.string "déjoué les plans de la TEAM\p"
	.string "MAGMA!\p"
	.string "Mais… Toi… De quel côté es-tu?\p"
	.string "Ah, peu importe…\p"
	.string "Nous resterons vigilants et\n"
	.string "continuerons de poursuivre la\p"
	.string "TEAM MAGMA.\p"
	.string "{PLAYER}, nous nous reverrons!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "La TEAM MAGMA est venue en\n"
	.string "force! Arrêtons! On ne fera pas\p"
	.string "le poids!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "S’ils étendent la terre, il y\n"
	.string "aura moins d’espace pour les\p"
	.string "POKéMON EAU!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Nous sommes la TEAM AQUA!\p"
	.string "Ils sont la TEAM MAGMA!\p"
	.string "Ça me fait mal au cœur qu’ils\n"
	.string "utilisent un nom qui ressemble\p"
	.string "au nôtre!$"

MtChimney_Text_Bushaa:
	.string "Bouhaha!$"

MtChimney_Text_LavaCookiesJust200:
	.string "Les LAVA COOKIES sont les\n"
	.string "spécialités locales du MONT\p"
	.string "CHIMNEE.\p"
	.string "Goûtes-en un. Ça ne coûte que\n"
	.string "200¥.$"

MtChimney_Text_ThankYouDear:
	.string "Merci, mon p’tit!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, tu ne peux pas acheter ce\n"
	.string "que tu veux, si tu n’as pas\p"
	.string "assez d’argent.$"

MtChimney_Text_OhFineThen:
	.string "Bon, très bien.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "Un METEORITE est placé sur une\n"
	.string "mystérieuse machine…\p"
	.string "Cette machine semble stocker de\n"
	.string "l’énergie dans le METEORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Un METEORITE est placé sur une\n"
	.string "mystérieuse machine…\p"
	.string "Voulez-vous retirer le\n"
	.string "METEORITE?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} retire le METEORITE de\n"
	.string "la mystérieuse machine.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} laisse le METEORITE à\n"
	.string "sa place.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Cette mystérieuse machine… Elle\n"
	.string "ne répond pas.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} SENTIER SINUROC\n"
	.string "VERMILAVA DROIT DEVANT$"

MtChimney_Text_ShelbyIntro:
	.string "Je suis allée aux sources\n"
	.string "chaudes pour revigorer mes os\p"
	.string "fatigués. Maintenant, je me sens\n"
	.string "forte!$"

MtChimney_Text_ShelbyDefeat:
	.string "Oh, ça alors! Quel DRESSEUR tu\n"
	.string "fais!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Eh bien, j’ai perdu. Je ne peux\n"
	.string "plus me considérer comme étant\p"
	.string "EXPERT, hein?$"

MtChimney_Text_ShelbyRegister:
	.string "Merci, mon p’tit! C’était\n"
	.string "amusant. Comme si je m’étais\p"
	.string "battue contre mes\n"
	.string "petits-enfants.\p"
	.string "Reviens me voir quand tu veux\n"
	.string "pour une revanche.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Si tu réussis à toucher le cœur\n"
	.string "de tes POKéMON, tu devrais\p"
	.string "pouvoir accomplir de grandes\n"
	.string "choses.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Oh, ça alors! Quel DRESSEUR tu\n"
	.string "fais!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Peut-être ton cœur ne fait-il\n"
	.string "plus qu’un avec celui de tes\p"
	.string "POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "J’ai le feu en moi, bébé. J’en\n"
	.string "peux plus! Il faut que j’me\p"
	.string "batte!$"

MtChimney_Text_MelissaDefeat:
	.string "Oh, oh! C’était un combat\n"
	.string "torride!$"

MtChimney_Text_MelissaPostBattle:
	.string "La chaleur du MONT CHIMNEE avive\n"
	.string "le feu qui brûle en moi, bébé!$"

MtChimney_Text_SheilaIntro:
	.string "Je suis enfin parvenue au MONT\n"
	.string "CHIMNEE. Je veux que mon POKéMON\p"
	.string "combatte!$"

MtChimney_Text_SheilaDefeat:
	.string "La façon dont tu te bats… C’est\n"
	.string "comme une éruption du MONT\p"
	.string "CHIMNEE!$"

MtChimney_Text_SheilaPostBattle:
	.string "Comme je l’ai dit, je suis enfin\n"
	.string "parvenue au MONT CHIMNEE. Ce\p"
	.string "serait dommage que ce ne soit\n"
	.string "qu’en touriste…\p"
	.string "Je veux gagner quelques combats\n"
	.string "et ramener des COOKIES en\p"
	.string "souvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Depuis ma baignade dans les\n"
	.string "sources chaudes, je suis en\p"
	.string "super forme!\p"
	.string "Je suis sûre que je vais gagner!$"

MtChimney_Text_ShirleyDefeat:
	.string "Atchoum! Je prends froid hors de\n"
	.string "l’eau.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Je vais devoir prendre un autre\n"
	.string "bain dans les sources chaudes.\p"
	.string "Tu viens?\p"
	.string "Je plaisante!$"

MtChimney_Text_SawyerIntro:
	.string "C’est une belle montagne! Pleine\n"
	.string "de gens pour te tenir compagnie!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, tu as le feu, toi!$"

MtChimney_Text_SawyerPostBattle:
	.string "Je ferais mieux d’aller me\n"
	.string "baigner avec les gens du coin!$"

MtChimney_Text_SawyerRegister:
	.string "J’aime les petites boules de feu\n"
	.string "comme toi.\p"
	.string "Laisse-moi t’enregistrer dans\n"
	.string "mon POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Je suis entouré de gens chauds\n"
	.string "comme la braise, je ne peux pas\p"
	.string "perdre!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Tu as autant le feu qu’avant!$"

MtChimney_Text_SawyerPostRematch:
	.string "En fait, il fait un peu trop\n"
	.string "chaud ici. Je dois être un peu\p"
	.string "trop habillé.$"
