Route24_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 16, 8
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 16, 9
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31_HNS, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE24_GRUNT
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "Hé toi! Moi yé souis dé la TEAM\n"
	.string "ROCKET!\p"
	.string "Yé souis de oune autre pays. Mé\n"
	.string "moi souper pouissant!\p"
	.string "Si arrété énérgie ici pas bien\n"
	.string "pour lé amis à moi!\p"
	.string "Ma mission cé oune sécré alors\n"
	.string "pas té dire!\p"
	.string "Mé! Si toi mé gagné, cé dé\p"
	.string "l'honor de té dire lé secret à\n"
	.string "moi.\p"
	.string "Alors! COMBAT!$"

Route24_Text_RocketBeaten:
	.string "Oh noes! Incrédible!\p"
	.string "Vous êtes très château...\n"
	.string "palais... Euh, non! Fort!\p"
	.string "De taille je ne suis pas.$"

Route24_Text_RocketAfter:
	.string "OK. Moi lé dire la secret.\p"
	.string "PARTIE MACH. jé la volé moi.\p"
	.string "La planqué aussi dans ARENE\n"
	.string "AZURIA.\p"
	.string "Dans l'eau tu la cherches au\n"
	.string "milieu.\p"
	.string "Dans l'ARENE, OK? Tout compris?\p"
	.string "Ma toi tu oublies pas moi!\p"
	.string "TEAM ROCKET te battre!\p"
	.string "Ils viennent de JOHTO mes amis\n"
	.string "et\p"
	.string "ta tête te la cassent, oh oui.$"

Route24_Text_RocketDisappears:
	.string "...\p"
	.string "Qué dit? TEAM ROCKET cassé? Par\n"
	.string "toi en plous?\p"
	.string "Oh, non! Qué yé dois faire moi?$"



Route24_Text_Woman:
	.string "Quelle vue magnifique, non?$"
Route24_Text_Man:
	.string "Je resterais ici des heures.$"

Route24_Text_WomanRocket:
	.string "Personne ne me bouscule!$"
Route24_Text_ManRocket:
	.string "Personne ne pousse ma copine!$"

Route24_Text_WomanAfterRocket:
	.string "Mais qu'est-ce qui lui a pris?$"
Route24_Text_ManAfterRocket:
	.string "C'était un ROCKET?$"
