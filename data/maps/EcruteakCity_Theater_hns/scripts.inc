EcruteakCity_Theater_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_Theater_OnTransition
	.byte 0

EcruteakCity_Theater_OnTransition::
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_MapScript_SetRocketSceneActive
	call_if_eq VAR_ECRUTEAK_CITY_THEATER, 8, EcruteakCity_Theater_MapScript_SetKimonoMovement
	end

EcruteakCity_Theater_MapScript_SetRocketSceneActive::
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	return

EcruteakCity_Theater_MapScript_SetKimonoMovement::
	setobjectmovementtype LOCALID_ECRUTEAK_ZUKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_NAOKO, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_MIKI, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SAYO, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_KUNI, MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE
	setobjectmovementtype LOCALID_ECRUTEAK_SISTER, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	return

EcruteakCity_Theater_EventScript_RocketEventTrigger::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 60
	turnobject LOCALID_ECRUTEAK_ROCKET, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanUp
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakCity_Theater_Text_KimonoRocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakCity_Theater_Text_Rocket2, MSGBOX_DEFAULT
	applymovement LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoGirlMoveBack
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketDance
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakCity_Theater_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setvar VAR_ECRUTEAK_CITY_THEATER, 1
	releaseall
	end

EcruteakCity_Theater_Movement_RocketDance:
	walk_in_place_down
	delay_2
	walk_in_place_right
	delay_2
	face_up
	delay_2
	face_left
	delay_8
	walk_in_place_down
	delay_2
	walk_in_place_left
	delay_2
	face_up
	delay_8
	face_right
	step_end

EcruteakCity_Theater_Movement_CameraPanUp:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

EcruteakCity_Theater_Movement_CameraPanDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

EcruteakCity_Theater_Movement_KimonoGirlMoveBack:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

EcruteakCity_Theater_Text_Rocket1:
	.string "SBIRE: Ça suffit, cette danse\n"
	.string "trop sérieuse!\p"
	.string "Fais-moi plutôt un tamure!$"

EcruteakCity_Theater_Text_KimonoRocket1:
	.string "DANSEUSE: ...Vous ne devriez pas\n"
	.string "m'imposer une telle demande.$"

EcruteakCity_Theater_Text_Rocket2:
	.string "SBIRE: Quoi?\p"
	.string "Tu refuses de respecter\n"
	.string "les désirs du client?$"

EcruteakCity_Theater_Text_Rocket3:
	.string "Il faut te faire un dessin?\n"
	.string "J’vais te montrer, moi!\p"
	.string "Whoua ha ha!$"

EcruteakCity_Theater_EventScript_Rocket::
	lock
	faceplayer
	msgbox EcruteakCity_Theater_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_33_HNS, EcruteakCity_Theater_Text_RocketBeaten
	msgbox EcruteakCity_Theater_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakCity_Theater_Movement_RocketLeave
	waitmovement 0
	setflag FLAG_HIDE_ECRUTEAK_ROCKET
	removeobject LOCALID_ECRUTEAK_ROCKET
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_EventScript_PostRocketLeft
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_EventScript_PostRocketRight
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_EventScript_PostRocketTop
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakCity_Theater_Text_KimonoRocket3, MSGBOX_DEFAULT
	closemessage	
	setvar VAR_ECRUTEAK_CITY_THEATER, 2
	release
	end
	
EcruteakCity_Theater_EventScript_PostRocketLeft::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketRight::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakCity_Theater_EventScript_PostRocketTop::
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_Movement_RocketLeave:
	jump_2_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

EcruteakCity_Theater_Text_RocketSeen:
	.string "Qu’est-ce tu veux?\p"
	.string "T’es là pour me pourrir mon\n"
	.string "groove?$"

EcruteakCity_Theater_Text_RocketBeaten:
	.string "Bon OK, j’suis pas un monstre\n"
	.string "non plus.$"

EcruteakCity_Theater_Text_RocketAfter:
	.string "Ça va pas le\n"
	.string "faire... Si on\p"
	.string "découvre que je\n"
	.string "suis là à glander\p"
	.string "alors qu’on a un super plan en\n"
	.string "route...\p"
	.string "Je vais redevenir le\n"
	.string "Sbire d’un Sbire...\p"
	.string "La victoire réside\n"
	.string "dans la fuite parfois!$"

EcruteakCity_Theater_Text_KimonoRocket3:
	.string "Tu t’appelles\n"
	.string "{PLAYER}, c’est bien\p"
	.string "cela? Ta victoire\n"
	.string "fut éclatante!\p"
	.string "La manière dont tu as élevé tes\n"
	.string "Pokémon, avec douceur et fermeté\p"
	.string "à la fois, est exceptionnelle!\p"
	.string "A n’en point douter, tu es...\p"
	.string "Oublie ces derniers mots. Ce ne\n"
	.string "sont que mes élucubrations.$"


EcruteakCity_Theater_EventScript_KimonoGirl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent
	msgbox EcruteakCity_Theater_Text_KimonoDone, MSGBOX_DEFAULT
	closemessage
	release
	end
EcruteakCity_Theater_EventScript_KimonoGirlDuringEvent::
	msgbox EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Zuki::
	lock
	faceplayer
	goto_if_ge VAR_ECRUTEAK_CITY_THEATER, 8, EcruteakCity_Theater_EventScript_ZukiAfterLegendary
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 6, EcruteakCity_Theater_EventScript_ZukiBattle
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_ZukiDuringRocket
	msgbox EcruteakCity_Theater_Text_Kimono, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiAfterLegendary::
	msgbox EcruteakCity_Theater_Text_ZukiAfterAll, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_ZukiDuringRocket::
	msgbox EcruteakCity_Theater_Text_KimonoGirlBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Text_Kimono:
	.string "Nous répétons chaque\n"
	.string "jour, sans jamais\p"
	.string "faillir, notre danse\n"
	.string "dans la salle de\p"
	.string "spectacle pour ne jamais\n"
	.string "l’oublier, car\p"
	.string "tel est notre destin.\p"
	.string "Il en va de même avec nos\n"
	.string "Pokémon.\p"
	.string "Chaque jour, sans faillir, nous\n"
	.string "consacrons un peu de temps à\p"
	.string "leur développement.$"

EcruteakCity_Theater_EventScript_SurfGuy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_SurfGuyDuringRocket
	goto_if_unset FLAG_RECEIVED_HM_SURF, EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf
	msgbox EcruteakCity_Theater_Text_SurfGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_SurfGuy_GiveSurf::
	msgbox EcruteakCity_Theater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakCity_Theater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	release
	end

EcruteakCity_Theater_EventScript_SurfGuyDuringRocket::
	msgbox EcruteakCity_Theater_Text_SurfGuyRocket, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_TriggerSurfGuy::
	lock
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakCity_Theater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakCity_Theater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_CITY_THEATER, 3
	applymovement LOCALID_SURF_GUY, EcruteakCity_Theater_Movement_SurfGuy2
	waitmovement 0 
	release
	end

EcruteakCity_Theater_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox EcruteakCity_Theater_Text_Psyduck, MSGBOX_DEFAULT
	waitmoncry
	release
	end


EcruteakCity_Theater_EventScript_Boy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_BoyDuringRocket
	msgbox EcruteakCity_Theater_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_BoyDuringRocket::
	msgbox EcruteakCity_Theater_Text_BoyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Granny::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrannyDuringRocket
	msgbox EcruteakCity_Theater_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrannyDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrannyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_Theater_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GrampsDuringRocket
	msgbox EcruteakCity_Theater_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GrampsDuringRocket::
	msgbox EcruteakCity_Theater_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_Girl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_THEATER, 1, EcruteakCity_Theater_EventScript_GirlDuringRocket
	msgbox EcruteakCity_Theater_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_GirlDuringRocket::
	msgbox EcruteakCity_Theater_Text_GirlBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_EventScript_FancyPanel::
	lock
	msgbox EcruteakCity_Theater_Text_FancyPanel, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_SurfGuy1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

EcruteakCity_Theater_Movement_SurfGuy2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EcruteakCity_Theater_Text_SurfGuyRocket:
	.string "Qu'est-ce qui lui prend, à ce\n"
	.string "Sbire de la Team Rocket?\p"
	.string "Il ennuie cette danseuse!\p"
	.string "Tu es Dresseur, n'est-ce pas?\n"
	.string "Aide-la, je t'en prie!$"

EcruteakCity_Theater_Text_SurfGuyGiveSurf:
	.string "Incroyable!\p"
	.string "Malgré ton âge, tu as du courage\n"
	.string "à revendre!\p"
	.string "Tiens, pour exprimer ma\n"
	.string "gratitude, je te donne ça!$"

EcruteakCity_Theater_Text_SurfGuyGaveSurf:
	.string "Grâce à Surf, tu peux avancer\n"
	.string "sur l’eau!$"

EcruteakCity_Theater_Text_SurfGuyAfter:
	.string "Les danseuses en kimono ne sont\n"
	.string "douées pour danser,\l"
	.string "mais aussi au combat Pokémon!\p"
	.string "Elles ne combattent toutefois\n"
	.string "que pour de bonnes raisons.\p"
	.string "Pourrais-tu les battre si elles\n"
	.string "montraient tout leur talent?$"

EcruteakCity_Theater_Text_Psyduck:
	.string "PSYKOKWAK: Psykooo!$"

EcruteakCity_Theater_Text_BoyBefore:
	.string "Eeeeek!$"

EcruteakCity_Theater_Text_Boy:
	.string "Non!\p"
	.string "C’était ma seule chance de me\n"
	.string "rapprocher d’une danseuse!$"

EcruteakCity_Theater_Text_Granny:
	.string "Ce vieux passe tout son temps\n"
	.string "avec son PSYKOKWAK.\p"
	.string "Il voudrait faire danser des\n"
	.string "Pokémon qui utilisent Surf.\p"
	.string "Peut-être qu’il\n"
	.string "veut leur faire\p"
	.string "faire de la natation\n"
	.string "synchronisée...$"

EcruteakCity_Theater_Text_GrannyBefore:
	.string "Oh! Oooooh!\p"
	.string "Si seulement je n'avais pas\n"
	.string "mal au ventre, j'apprendrais\l"
	.string "la politesse à ce sale type...$"

EcruteakCity_Theater_Text_Gramps:
	.string "Ce que les danseuses en kimono\n"
	.string "sont élégantes!\p"
	.string "Mais elles\n"
	.string "doivent suivre\p"
	.string "un entraînement\n"
	.string "extrêmement rigoureux\p"
	.string "avant de pouvoir se donner en\p"
	.string "spectacle.\p"
	.string "J’imagine que quand on aime, on\n"
	.string "ne compte pas...$"

EcruteakCity_Theater_Text_GrampsBefore:
	.string "Oh! Oooooh!\p"
	.string "Si seulement je n'avais pas\n"
	.string "mal au dos, j'apprendrais\l"
	.string "la politesse à ce sale type...$"

EcruteakCity_Theater_Text_Girl:
	.string "Les danseuses en kimono sont\n"
	.string "comme mes grandes sœurs!\p"
	.string "Un jour, je serai comme elles!$"

EcruteakCity_Theater_Text_GirlBefore:
	.string "Cette drôle de danse me plaît!$"

EcruteakCity_Theater_Text_FancyPanel:
	.string "C'est un joli paravent décoré de\n"
	.string "fleurs.$"

EcruteakCity_Theater_Trigger_PreBattleCutsceneLeft::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneTop::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiTop
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiTop
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene

EcruteakCity_Theater_Trigger_PreBattleCutsceneRight::
	lock
	applymovement2 OBJ_EVENT_ID_PLAYER, EcruteakCity_Theater_Movement_PlayerWalkToZukiRight
	applymovement2 OBJ_EVENT_ID_FOLLOWER, EcruteakCity_Theater_Movement_MonWalkToZukiRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	lockall
	goto EcruteakCity_Theater_EventScript_LegendaryCutscene


EcruteakCity_Theater_Movement_PlayerWalkToZukiLeft:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiLeft:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiTop:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiTop:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

EcruteakCity_Theater_Movement_PlayerWalkToZukiRight:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end
EcruteakCity_Theater_Movement_MonWalkToZukiRight::
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


EcruteakCity_Theater_Movement_KimonoSpin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	step_end

EcruteakCity_Theater_EventScript_LugiaBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA
	return
EcruteakCity_Theater_EventScript_HoohBuffer::
	bufferspeciesname STR_VAR_1, SPECIES_HO_OH
	return
EcruteakCity_Theater_EventScript_LegendaryCutscene::
	call_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_LugiaBuffer
	call_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_HoohBuffer 
	msgbox EcruteakCity_Theater_Text_ZukiSeen, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 6
EcruteakCity_Theater_EventScript_ZukiBattle::
	msgbox EcruteakCity_Theater_Text_ZukiSeenAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, EcruteakCity_Theater_EventScript_LegendaryDenied
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakCity_Theater_Movement_SouthCorrection
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_Theater_Movement_WestCorrection
	call_if_eq VAR_FACING, DIR_EAST, EcruteakCity_Theater_Movement_EastCorrection
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 1, 2, 0, 0
	trainerbattle_no_intro TRAINER_ZUKI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_ZUKI, EcruteakCity_Theater_Movement_ZukiWalkUp
	waitmovement 0
EcruteakCity_Theater_EventScript_NaokoBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_NaokoSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 1, 0, 1, 1, 0
	trainerbattle_no_intro TRAINER_NAOKO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_NAOKO, EcruteakCity_Theater_Movement_NaokoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_MikiBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_MikiSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 1, 2, 0
	trainerbattle_no_intro TRAINER_MIKI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_MIKI, EcruteakCity_Theater_Movement_MikiWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_SayoBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_SayoSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 2, 1, 0, 0
	trainerbattle_no_intro TRAINER_SAYO_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_SAYO, EcruteakCity_Theater_Movement_SayoWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_KuniBattle::
	playse SE_M_PETAL_DANCE
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KimonoSpin
	waitmovement 0
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkToPlayer
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_KuniSeen, MSGBOX_DEFAULT
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 0, 1, 0
	trainerbattle_no_intro TRAINER_KUNI_HNS, EcruteakCity_Theater_Text_KimonoGirlBeaten
	applymovement2 LOCALID_ECRUTEAK_KUNI, EcruteakCity_Theater_Movement_KuniWalkBack
	waitmovement 0
EcruteakCity_Theater_EventScript_BeatGauntlet::
	applymovement2 LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_ZukiDone, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, EcruteakCity_Theater_EventScript_Lugia
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, EcruteakCity_Theater_EventScript_Hooh

	EcruteakCity_Theater_Movement_SouthCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_WestCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

	EcruteakCity_Theater_Movement_EastCorrection::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakCity_Theater_EventScript_Lugia::
	giveitem ITEM_TIDAL_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement2 LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_WEST
	msgbox EcruteakCity_Theater_Text_GirlLugia, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEAK_ZUKI
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	msgbox EcruteakCity_Theater_Text_ZukiLugia, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_COMPLETED_LUGIA, 2
	setvar VAR_COMPLETED_HO_OH, 3
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end
EcruteakCity_Theater_EventScript_Hooh::
	giveitem ITEM_CLEAR_BELL
	closemessage
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	addobject LOCALID_ECRUTEAK_SISTER
	applymovement2 LOCALID_ECRUTEAK_SISTER, EcruteakCity_Theater_Movement_Sister
	waitmovement 0
	msgbox EcruteakCity_Theater_Text_GirlHooh, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEAK_ZUKI
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	msgbox EcruteakCity_Theater_Text_ZukiHooh, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK

	removeobject LOCALID_ECRUTEAK_ZUKI
	removeobject LOCALID_ECRUTEAK_MIKI
	removeobject LOCALID_ECRUTEAK_NAOKO
	removeobject LOCALID_ECRUTEAK_KUNI
	removeobject LOCALID_ECRUTEAK_SAYO
	removeobject LOCALID_ECRUTEAK_MIKI

	removeobject LOCALID_ECRUTEAK_SISTER
	playse SE_EXIT
	delay 120
	fadescreenswapbuffers FADE_FROM_BLACK

	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setvar VAR_COMPLETED_HO_OH, 2
	setvar VAR_COMPLETED_LUGIA, 3
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setvar VAR_NEWBARKTOWN_LABSTATE, 9
	setvar VAR_ECRUTEAK_CITY_THEATER, 7
	release
	end

EcruteakCity_Theater_Movement_Sister:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	step_end

EcruteakCity_Theater_EventScript_LegendaryDenied::
	msgbox EcruteakCity_Theater_Text_ZukiNo, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Theater_Movement_ZukiWalkUp:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end
EcruteakCity_Theater_Movement_NaokoWalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_NaokoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_MikiWalkBack:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

EcruteakCity_Theater_Movement_SayoWalkToPlayer:
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end
EcruteakCity_Theater_Movement_SayoWalkBack:
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Movement_KuniWalkToPlayer:
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end
EcruteakCity_Theater_Movement_KuniWalkBack:
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end

EcruteakCity_Theater_Text_KimonoGirlBeaten:
	.string "...$"

EcruteakCity_Theater_Text_ZukiSeen:
	.string "Bienvenue à toi. Je suis TAMAO.\p"
	.string "Nos chemins se sont déjà croisés\n"
	.string "à MAUVILLE.\p"
	.string "Pour faire venir {STR_VAR_1},\n"
	.string "il nous fallait quelqu'un\n"
	.string "véritablement lié aux Pokémon.\p"
	.string "Nous avons demandé à M. POKéMON\n"
	.string "de confier cet OEUF MYSTERE à\l"
	.string "une personne prometteuse.\p"
	.string "M. POKéMON a confié l'OEUF au\n"
	.string "PROF. ORME, qui te l'a remis.\p"
	.string "Mais la pureté seule ne suffit\n"
	.string "pas\l"
	.string "pour affronter la puissance\l"
	.string "de ce Pokémon.$"

EcruteakCity_Theater_Text_ZukiSeenAgain:
	.string "Je vais mettre à l'épreuve\n"
	.string "tes talents de Dresseur.\p"
	.string "Es-tu prêt, {PLAYER}?$"

EcruteakCity_Theater_Text_ZukiNo:
	.string "Ainsi soit-il. Nous attendrons\n"
	.string "ton retour.$"

EcruteakCity_Theater_Text_NaokoSeen:
	.string "Quelle force tu as là!\p"
	.string "Tu m'as secourue dans le BOIS\n"
	.string "AUX CHENES.\p"
	.string "Je suis UMEKO, celle qui\n"
	.string "souvent s'égare.\p"
	.string "Je t'ai vu vaincre la Team\n"
	.string "Rocket au PUITS RAMOLOSS\l"
	.string "et aider FARGAS.\p"
	.string "Voyons maintenant de quoi toi\n"
	.string "et tes Pokémon êtes capables!$"

EcruteakCity_Theater_Text_MikiSeen:
	.string "Quel Dresseur remarquable!\p"
	.string "Je me souviens que tu as chassé\n"
	.string "le Sbire de la Team Rocket\n"
	.string "qui était ici.\p"
	.string "Je t'en remercie.\p"
	.string "Mais je suis aussi Dresseuse.\p"
	.string "Une femme avisée ne dévoile\n"
	.string "jamais tous ses talents!\p"
	.string "Je suis SATSUKI, la danseuse!\p"
	.string "Permets-moi de défier\n"
	.string "tes Pokémon!$"

EcruteakCity_Theater_Text_SayoSeen:
	.string "Quel superbe esprit combatif!\p"
	.string "Tu m'as libérée de la glace\n"
	.string "en me poussant.\p"
	.string "Je patine en sandales.\n"
	.string "Je suis SAKURA, la danseuse!\p"
	.string "Je t'ai entendu réussir\n"
	.string "l'épreuve de l'Ancien dans\l"
	.string "l'ANTRE DU DRAGON.\p"
	.string "Permets-moi de défier\n"
	.string "tes Pokémon!$"

EcruteakCity_Theater_Text_KuniSeen:
	.string "Je suis la dernière.\p"
	.string "Tu as été digne de confiance\n"
	.string "dans le DOUBLON-TUNNEL.\p"
	.string "Je suis KOMOMO, celle qui\n"
	.string "virevolte même sous terre!\p"
	.string "Je t'ai vu déjouer le plan de\n"
	.string "la Team Rocket à la TOUR RADIO.\p"
	.string "Montre-moi maintenant ta force!\n"
	.string "Permets-moi de défier\n"
	.string "tes Pokémon!$"

EcruteakCity_Theater_Text_ZukiDone:
	.string "Aucune erreur n’est possible!\p"
	.string "Tu es digne de posséder cet\n"
	.string "objet.\p"
	.string "Prends-le!$"

EcruteakCity_Theater_Text_GirlHooh:
	.string "Maîtresses!\p"
	.string "Je viens de voir l'ombre d'un\n"
	.string "gigantesque Pokémon planer\l"
	.string "sur la TOUR FERRAILLE!\p"
	.string "Se pourrait-il que...$"

EcruteakCity_Theater_Text_GirlLugia:
	.string "Maîtresses!\p"
	.string "L’ombre d’un gigantesque Pokémon\n"
	.string "plane sur les Tourb’Iles!\p"
	.string "Se pourrait-il que...$"

EcruteakCity_Theater_Text_ZukiHooh:
	.string "TAMAO: Jeune {PLAYER}!\n"
	.string "Nous partons sans plus attendre\l"
	.string "pour la TOUR FERRAILLE!$"

EcruteakCity_Theater_Text_ZukiLugia:
	.string "Tamao: Jeune {PLAYER}! Nous\n"
	.string "partons sans plus attendre\p"
	.string "pour les Tourb’Iles!$"

EcruteakCity_Theater_Text_KimonoDone:
	.string "Nous sommes en pleine\n"
	.string "répétition!$"

EcruteakCity_Theater_Text_ZukiAfterAll:
	.string "Merci pour ton aide précieuse.\p"
	.string "Tu as prouvé que le lien entre\n"
	.string "les humains peut s'étendre\n"
	.string "à celui\l"
	.string "qui les unit aux Pokémon...\p"
	.string "Merci d'avoir été à la hauteur\n"
	.string "de nos espoirs, {PLAYER}!\p"
	.string "Si cette expérience t'a appris\n"
	.string "quelque chose, remercie\n"
	.string "M. POKéMON\l"
	.string "et le PROF. ORME, pas nous...$"

EcruteakCity_Theater_Text_KimonoGirlsBeforeBattle:
	.string "Lorsque tu auras\n"
	.string "fini de te préparer,\p"
	.string "parle à notre\n"
	.string "sœur aînée, Tamao,\p"
	.string "au centre de l’estrade.$"
