Route14_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route14_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route14_TriggerSuicune_5::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_5
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_4::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_4
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_3::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_3
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_2::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto Route14_EventScript_Suicune

Route14_TriggerSuicune_1::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 60
	goto Route14_EventScript_Suicune

Route14_Movement_5:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_4:
	walk_right
	walk_right
	walk_right
	step_end

Route14_Movement_3:
	walk_right
	walk_right
	step_end

Route14_EventScript_Suicune::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE14_SUICUNE, Route14_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
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
	clearflag FLAG_HIDE_ROUTE14_EUSINE
	addobject LOCALID_ROUTE14_EUSINE
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineEnter
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 0
	msgbox Route14_Text_Eusine, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE14_EUSINE, Route14_Movement_EusineLeave
	waitmovement 0
	setflag FLAG_HIDE_ROUTE14_EUSINE
	setflag FLAG_HIDE_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_SUICUNE
	removeobject LOCALID_ROUTE14_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 5
	call_if_ge VAR_CERULEAN_CITY_STATE, 3, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

Route14_Movement_SuicuneLeave:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	step_end

Route14_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	walk_slow_right
	step_end

Route14_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER_HNS, Route14_Text_PokefanmCarterSeen, Route14_Text_PokefanmCarterBeaten, Route14_EventScript_RegisterCarter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route14_EventScript_RematchCarter
	msgbox Route14_Text_PokefanmCarterAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RegisterCarter::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_CarterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CARTER_HNS
	release
	end

Route14_EventScript_RematchCarter::
	trainerbattle_rematch TRAINER_CARTER_HNS, Route14_Text_CarterRematchIntro, Route14_Text_CarterRematchDefeat
	msgbox Route14_Text_CarterPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_CARTER_2_HNS, Route14_EventScript_RematchCarterTryGiveItem
	end

Route14_EventScript_RematchCarterTryGiveItem::
	checkitem ITEM_TM_THUNDER_WAVE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_THUNDER_WAVE
	closemessage
	end

Route14_EventScript_Roy::
	trainerbattle_single TRAINER_ROY_HNS, Route14_Text_BirdKeeperRoySeen, Route14_Text_BirdKeeperRoyBeaten
	msgbox Route14_Text_BirdKeeperRoyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR_HNS, Route14_Text_PokefanmTrevorSeen, Route14_Text_PokefanmTrevorBeaten, Route14_EventScript_RegisterTrevor
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route14_EventScript_RematchTrevor
	msgbox Route14_Text_PokefanmTrevorAfterBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RegisterTrevor::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route14_Text_TrevorRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TREVOR_HNS
	release
	end

Route14_EventScript_RematchTrevor::
	trainerbattle_rematch TRAINER_TREVOR_HNS, Route14_Text_TrevorRematchIntro, Route14_Text_TrevorRematchDefeat
	msgbox Route14_Text_TrevorPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_TREVOR_2_HNS, Route14_EventScript_RematchTrevorTryGiveItem
	end

Route14_EventScript_RematchTrevorTryGiveItem::
	checkitem ITEM_TM_WILL_O_WISP
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_WILL_O_WISP
	closemessage
	end



Route14_Text_Eusine:
	.string "Eusine: Encore toi, {PLAYER}!\p"
	.string "Cette fois, je ne\n"
	.string "me laisserai pas\p"
	.string "faire! Après tout ce\n"
	.string "temps passé à suivre\p"
	.string "SUICUNE, j’ai compris où il se\n"
	.string "dirigeait!\p"
	.string "Si j’ai raison,\n"
	.string "j’aimerais garder\p"
	.string "cette information pour\n"
	.string "moi tout seul, mais\p"
	.string "je ne peux pas me montrer\n"
	.string "égoïste\p"
	.string "devant SUICUNE...\p"
	.string "Alors je vais te donner un\n"
	.string "indice!\p"
	.string "SUICUNE se dirige\n"
	.string "vers le nord...\p"
	.string "Un endroit au\n"
	.string "bord de l’eau...\p"
	.string "Un peu surélevé...\p"
	.string "C’est là qu’il apparaîtra\n"
	.string "ensuite!\p"
	.string "Je ne sais pas\n"
	.string "exactement où ce\p"
	.string "lieu se trouve,\n"
	.string "mais je compte bien\p"
	.string "le découvrir avant toi!$"

Route14_Text_PokefanmTrevorSeen:
	.string "Le savais-tu?\p"
	.string "Les Pokémon sont plus amicaux\n"
	.string "s'ils\p"
	.string "sont entraînés dans un endroit\n"
	.string "familier.$"

Route14_Text_PokefanmTrevorBeaten:
	.string "Où ai-je rencontré ce CIZAYOX?$"

Route14_Text_PokefanmTrevorAfterBattle:
	.string "Y a-t-il un moyen de savoir où\n"
	.string "l'on\p"
	.string "a trouvé nos Pokémon?$"

Route14_Text_TrevorRegister:
	.string "Tu es intéressant!\n"
	.string "Je peux avoir ton numéro?$"

Route14_Text_TrevorRematchIntro:
	.string "Je me suis entraîné avec mes\n"
	.string "Pokémon en terrain connu!$"

Route14_Text_TrevorRematchDefeat:
	.string "Il me faut de nouveaux lieux…$"

Route14_Text_TrevorPostRematch:
	.string "L'amitié rend les Pokémon plus\n"
	.string "forts. J'en suis sûr!$"

Route14_Text_PokefanmCarterSeen:
	.string "Laisse-moi te présenter mon\n"
	.string "équipe, chèrement acquise.$"

Route14_Text_PokefanmCarterBeaten:
	.string "Awaaah!$"

Route14_Text_PokefanmCarterAfterBattle:
	.string "KAIMINUS, HÉRICENDRE, GERMIGNON…\p"
	.string "Ce mélange me semble équilibré.$"

Route14_Text_CarterRegister:
	.string "Tu connais bien les Pokémon de\n"
	.string "départ!\p"
	.string "Donne-moi ton numéro!$"

Route14_Text_CarterRematchIntro:
	.string "J'ai trouvé encore plus de rares\n"
	.string "Pokémon de départ à exhiber!\p"
	.string "Affronte-moi!$"

Route14_Text_CarterRematchDefeat:
	.string "Mes précieux Pokémon de départ…$"

Route14_Text_CarterPostRematch:
	.string "Il y a tant de Pokémon de départ\n"
	.string "de différentes régions à réunir!$"

Route14_Text_BirdKeeperRoySeen:
	.string "Je rêve de voler avec mes amis\n"
	.string "les Pokémon oiseaux.$"

Route14_Text_BirdKeeperRoyBeaten:
	.string "Flap flap! J’ai beau faire, je\n"
	.string "ne m’envole pas...$"

Route14_Text_BirdKeeperRoyAfterBattle:
	.string "Tu as des Pokémon qui ont appris\n"
	.string "la\p"
	.string "CS VOL, non? Tu as trop de\n"
	.string "chance.$"

Route14_EventScript_Pidgeotto::
	lockall
	faceplayer
	playmoncry SPECIES_PIDGEOTTO, CRY_MODE_NORMAL
	msgbox Route14_Text_Pidgeotto, MSGBOX_DEFAULT
	waitmoncry
	goto_if_set FLAG_GOT_ROUTE_14_AERIAL_ACE, Route14_EventScript_PidgeottoBlowPlayer
	msgbox Route14_Text_PidgeottoBerry, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route14_EventScript_PidgeottoBlowPlayer
	fadescreen FADE_TO_BLACK
	special Bag_ChooseBerry
	waitstate
	removeitem VAR_ITEM_ID, 1
	goto_if_ne VAR_ITEM_ID, ITEM_QUALOT_BERRY, Route14_EventScript_PidgeottoDislikedBerry
	msgbox Route14_Text_PidgeottoAteBerry, MSGBOX_DEFAULT
	giveitem ITEM_TM_AERIAL_ACE
	setflag FLAG_GOT_ROUTE_14_AERIAL_ACE
Route14_EventScript_PidgeottoBlowPlayer::
	closemessage
	playse SE_M_TWISTER
	call_if_eq VAR_FACING, DIR_EAST, Route14_EventScript_PidgeottoBlowPlayerLeft
	releaseall
	end
Route14_EventScript_PidgeottoDislikedBerry::
	msgbox Route14_Text_PidgeottoTurnedAway, MSGBOX_DEFAULT
	goto Route14_EventScript_PidgeottoBlowPlayer

Route14_EventScript_PidgeottoBlowPlayerLeft::
	applymovement LOCALID_ROUTE14_PIDGEOTTO, Route14_Movement_JumpLeft
	applymovement OBJ_EVENT_ID_PLAYER, Route14_Movement_Player_BlownLeft
	waitmovement 0
	return

Route14_Movement_Player_BlownUp:
	lock_facing_direction
	walk_up
	walk_up
	unlock_facing_direction
	step_end

Route14_Movement_Player_BlownLeft:
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
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	lock_facing_direction
	walk_left
	walk_left
	unlock_facing_direction
	step_end

Route14_Movement_JumpUp:
	jump_in_place_up
	step_end

Route14_Movement_JumpLeft:
	jump_in_place_left
	step_end

Route14_Movement_StuckPidgeottoJump0:
	jump_in_place_up
	step_end

Route14_Movement_StuckPidgeottoJump:
	jump_2_up
	jump_in_place_left_right
	jump_in_place_left_right
	face_left
	step_end

Route14_Text_Pidgeotto:
	.string "ROUCOUPS: Kaaaaa!$"
Route14_Text_PidgeottoBerry:
	.string "Donner une BAIE à ROUCOUPS?$"
Route14_Text_PidgeottoAteBerry:
	.string "ROUCOUPS s'est régalé avec la\n"
	.string "BAIE QUALOT!$"
Route14_Text_PidgeottoTurnedAway:
	.string "ROUCOUPS n'aime pas ça!$"
