CianwoodCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CianwoodCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CianwoodCity_EventScript_InitializeSuicune
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CianwoodCity_RemoveEusine::
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	end

CianwoodCity_OnFrame::
	map_script_2 VAR_GETFLY, 1, CianwoodCity_EventScript_Flytrigger
	.2byte 0

CianwoodCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CIANWOOD_CITY
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

CianwoodCity_EventScript_InitializeSuicune::
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 2, CianwoodCity_EventScript_InitializeNothing
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_InitializeNothing::
	setvar VAR_TEMP_0, 1
	end

CianwoodCity_EventScript_Flytrigger::
	lock
	playse SE_PIN
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_CIANWOOD_CHUCKSWIFE
	applymovement LOCALID_CIANWOOD_CHUCKSWIFE, CianwoodCity_Movement_ChucksWife
	waitmovement 0
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
	closemessage
	setvar VAR_GETFLY, 2
	goto_if_eq VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	release
	end

CianwoodCity_Movement_ChucksWife:
	walk_left
	walk_left
	walk_up
	walk_left
	face_up
	step_end

CianwoodCity_EventScript_Test::
	lock
	random 2
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	release
	end

CianwoodCity_EventScript_ChucksWife::
	lock
	faceplayer
	checkitem ITEM_HM_FLY
	goto_if_eq VAR_RESULT, TRUE, CianwoodCity_EventScript_ChucksWifeAlreadyHasFly
	msgbox CianwoodCity_Text_ChucksWifeEasierToFly, MSGBOX_DEFAULT
	goto_if_set FLAG_BADGE05_GET, CianwoodCity_EventScript_ChucksWifeGiveFly
	msgbox CianwoodCity_Text_ChucksWifeBeatChuck, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeGiveFly::
	msgbox CianwoodCity_Text_ChucksWifeGiveHM, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	msgbox CianwoodCity_Text_ChucksWifeFlySpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_ChucksWifeAlreadyHasFly::
	msgbox CianwoodCity_Text_ChucksWifeChubby, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_ChucksWifeEasierToFly:
	.string "Tu es venue par voie de mer? Ça\n"
	.string "a dû te prendre un moment...\p"
	.string "Si tes Pokémon\n"
	.string "connaissaient\p"
	.string "Vol, ça aurait été\n"
	.string "tellement plus simple!$"

CianwoodCity_Text_ChucksWifeBeatChuck:
	.string "Mais tu ne peux pas\n"
	.string "utiliser Vol sans\p"
	.string "le Badge de l’Arène.\n"
	.string "Reviens me voir quand\p"
	.string "tu auras vaincu le Champion de\n"
	.string "la ville.\p"
	.string "Je te donnerai quelque chose\n"
	.string "d’utile.$"

CianwoodCity_Text_ChucksWifeGiveHM:
	.string "C’est le Badge de l’Arène\n"
	.string "d’Irisia!\p"
	.string "Alors tu as bien mérité cette\n"
	.string "CS!$"

CianwoodCity_Text_ChucksWifeFlySpeech:
	.string "Avec la capacité\n"
	.string "Vol, tu peux revenir\p"
	.string "en un instant à\n"
	.string "n’importe quelle ville\p"
	.string "que tu as déjà visitée!$"

CianwoodCity_Text_ChucksWifeChubby:
	.string "Hoho, mon mari va\n"
	.string "s’entraîner encore\p"
	.string "plus durement après\n"
	.string "cette défaite...\p"
	.string "Mais c’est une\n"
	.string "bonne chose: il a\p"
	.string "pris du ventre, ces\n"
	.string "derniers temps...$"

CianwoodCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Youngster:
	.string "En utilisant Vol,\n"
	.string "tu peux revenir\p"
	.string "à Oliville en\n"
	.string "un instant!$"

CianwoodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokefanM:
	.string "En brisant les\n"
	.string "rochers au nord de\p"
	.string "la ville, tu peux\n"
	.string "avoir des surprises.\p"
	.string "Si tu veux essayer,\n"
	.string "il te faudra\p"
	.string "apprendre Eclate-Roc\n"
	.string "à un Pokémon.$"

CianwoodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Lass:
	.string "CHUCK, le CHAMPION d'ARENE\p"
	.string "s'entraîne avec ses Pokémon de\n"
	.string "type COMBAT.$"

CianwoodCity_EventScript_SuicuneTrigger::
	lock
	hidefollower 1
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_CIANWOOD_SUICUNE, CianwoodCity_Movement_Suicune3
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	delay 30
	playbgm MUS_HG_EUSINE, FALSE
	clearflag FLAG_HIDE_CIANWOOD_EUSINE
	addobject LOCALID_CIANWOOD_EUSINE
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine1
	waitmovement 0
	delay 55
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine2
	waitmovement 0 
	msgbox CianwoodCity_Text_EusineSuicune, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EUSINE_HNS, CianwoodCity_Text_EusineBeaten
	playbgm MUS_HG_EUSINE, FALSE
	msgbox CianwoodCity_Text_EusineAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CIANWOOD_EUSINE, CianwoodCity_Movement_Eusine3
	waitmovement 0
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setflag FLAG_HIDE_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_SUICUNE
	removeobject LOCALID_CIANWOOD_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 2
	setvar VAR_CIANWOOD_CITY_STATE, 2
	fadedefaultbgm
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, CianwoodCity_EventScript_DoneJohtoSuicune
	release
	end

CianwoodCity_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

CianwoodCity_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	face_down
	step_end

CianwoodCity_Movement_Suicune2:
	jump_down
	jump_2_down
	jump_right
	face_up
	step_end

CianwoodCity_Movement_Suicune3:
	jump_2_down
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

CianwoodCity_Movement_Eusine1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	step_end

CianwoodCity_Movement_Eusine2:
	face_up
	walk_up
	walk_up
	step_end

CianwoodCity_Movement_Eusine3:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CianwoodCity_Text_EusineSuicune:
	.string "Eusine: Salut, {PLAYER}.\p"
	.string "C’était... C’était SUICUNE,\n"
	.string "hein?\p"
	.string "Je l’ai à peine\n"
	.string "aperçu, mais j’ai\p"
	.string "cru le voir courir\n"
	.string "sur l’eau...\p"
	.string "Il est si beau et si élégant...\p"
	.string "Et il traverse villes et routes\n"
	.string "à une vitesse prodigieuse...\p"
	.string "Quel être extraordinaire...\p"
	.string "J’aimerais tellement pouvoir\n"
	.string "l’admirer de plus près...\p"
	.string "Je sais!\p"
	.string "Je vais me battre\n"
	.string "avec toi pour que\p"
	.string "SUICUNE remarque\n"
	.string "mes talents!\p"
	.string "En garde! {PLAYER}!$"

CianwoodCity_Text_EusineBeaten:
	.string "Pas le choix: je reconnais ma\n"
	.string "défaite!$"

CianwoodCity_Text_EusineAfter:
	.string "Tu es formidable, {PLAYER}!\p"
	.string "Les Pokémon doivent t'adorer.\p"
	.string "Je comprends tout.\p"
	.string "Je vais encore traquer le grand\n"
	.string "SUICUNE.\p"
	.string "On se reverra.\p"
	.string "A bientôt!$"

CianwoodCity_EventScript_CitySign::
	lock
	msgbox CianwoodCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_Sign:
	.string "IRISIA\p"
	.string "Un port entouré d'une mer bien\n"
	.string "déchaînée$"

CianwoodCity_EventScript_GymSign::
	lock
	msgbox CianwoodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_GymSign:
	.string "Arène d’Irisia Champion: Chuck\p"
	.string "Un homme qui laisse ses poings\p"
	.string "parler pour lui$"

CianwoodCity_EventScript_Pharmacy::
	lock
	msgbox CianwoodCity_Text_PharmacySign, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_Text_PharmacySign:
	.string "500 ans de Tradition\p"
	.string "PHARMACIE d'IRISIA\p"
	.string "Malades... Venez nombreux!$"

CianwoodCity_EventScript_CaveSign::
	lock
	msgbox CianwoodCity_Text_Safari, MSGBOX_SIGN
	closemessage
	release
	end

CianwoodCity_EventScript_Engineer::
	lock
	faceplayer
	msgbox CianwoodCity_Text_Engineer, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_Safari:
	.string "GROTTE FALAISE\n"
	.string "ROUTE DU PARC SAFARI$"

CianwoodCity_Text_Engineer:
	.string "Ce chemin est en construction.\p"
	.string "Nous préparons l'ouverture du\n"
	.string "nouveau PARC SAFARI!$"
