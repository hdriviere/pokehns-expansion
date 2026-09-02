AzaleaTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_OnFrame
	.byte 0

AzaleaTown_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_MapScript_Hide_Silver
	end
	
AzaleaTown_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_EventScript_GSBall
	.2byte 0

AzaleaTown_MapScript_Hide_Silver:
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	end

AzaleaTown_EventScript_Trigger:: @flagheap
	setflag FLAG_VISITED_AZALEA_TOWN
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	setflag FLAG_HIDE_KURT_2
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	setflag FLAG_HIDE_CELEBI
	setflag FLAG_HIDE_ILEX_FOREST_KURT
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	

	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
	clearflag FLAG_ITEM_SLOWPOKE_WELL_RAIN_DANCE
	clearflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	clearflag FLAG_HIDE_KURT_1
	clearflag FLAG_GOT_CHARCOAL
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
	clearflag FLAG_MOVE_TUTOR_TAUGHT_HEADBUTT

	removeitem ITEM_HM_SURF
	setvar VAR_AZALEA_TOWN_STATE, 1
	end

AzaleaTown_EventScript_Rocket1::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Rocket2::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_EventScript_Gramps2
	msgbox AzaleaTown_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Gramps2::
	msgbox AzaleaTown_Text_GrampsAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Lass::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Youngster::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Slowpoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	msgbox AzaleaTown_Text_Slowpoke1, MSGBOX_DEFAULT
	waitmoncry
	release
	end


AzaleaTown_EventScript_GymSign::
	lock
	msgbox AzaleaTown_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_KurtSign::
	lock
	msgbox AzaleaTown_Text_KurtsHouseSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_KilnSign::
	lock
	msgbox AzaleaTown_Text_CharcoalKilnSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_IlexSign::
	lock
	msgbox AzaleaTown_Text_IlexForestSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_WellSign::
	lock
	msgbox AzaleaTown_Text_SlowpokeWellSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_AzaleaSign::
	lock
	msgbox AzaleaTown_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_SilverTriggerTop::
	lock
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
	addobject LOCALID_AZALEA_TOWN_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveTop
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	setvar VAR_AZALEA_TOWN_STATE, 6
	fadedefaultbgm
	release
	end

AzaleaTown_EventScript_SilverTriggerBot::
	lock
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
	addobject LOCALID_AZALEA_TOWN_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveBot
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	setvar VAR_AZALEA_TOWN_STATE, 6
	fadedefaultbgm
	release
	end

AzaleaTown_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_2_HNS, AzaleaTown_Text_RivalWin
	return

AzaleaTown_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_2_HNS, AzaleaTown_Text_RivalWin
	return

AzaleaTown_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_2_HNS, AzaleaTown_Text_RivalWin
	return


AzaleaTown_EventScript_GSBall::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_PlayerGSBall
	waitmovement 0
	clearflag FLAG_HIDE_AZALEA_TOWN_KURT
	addobject LOCALID_AZALEA_TOWN_KURT_GS
	opendoor 19, 11
	waitdooranim
	waitmovement 0
	closedoor 19, 11
	waitdooranim
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_Kurt2
	playse SE_M_PETAL_DANCE
	waitmovement 0
	msgbox AzaleaTown_Text_Kurt1, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	msgbox AzaleaTown_Text_Kurt2, MSGBOX_DEFAULT
	giveitem ITEM_GS_BALL
	waitse
	playse SE_M_PETAL_DANCE
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_M_PETAL_DANCE
	waitse
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox AzaleaTown_Text_Kurt3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_KurtLeave
	delay 60
	opendoor 19, 11
	waitdooranim
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
	removeobject LOCALID_AZALEA_TOWN_KURT_GS
	closedoor 19, 11
	waitdooranim
	setvar VAR_AZALEA_TOWN_STATE, 9
	release
	end

AzaleaTown_Movement_Silver_EnterTop:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_EnterBot:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_LeaveTop:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_LeaveBot:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	step_end

AzaleaTown_Movement_Player_LeaveTop:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

AzaleaTown_Movement_Player_LeaveBot:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

AzaleaTown_Movement_Kurt1:
	walk_down
	step_end

AzaleaTown_Movement_Kurt2:
	walk_down
	walk_down
	walk_down
	face_right
	delay_8
	face_left
	delay_8
	face_down
	step_end

AzaleaTown_Movement_PlayerGSBall:
	walk_down
	walk_down
	walk_down
	face_left
	delay_16
	face_right
	delay_8
	face_up
	step_end

AzaleaTown_Movement_KurtLeave:
	walk_up
	walk_up
	walk_up
	step_end

AzaleaTown_Text_RivalBefore:
	.string "...Dis-moi quelque chose, p'tit\n"
	.string "bouchon...\p"
	.string "Est-ce vrai que la TEAM ROCKET\n"
	.string "est de retour?\p"
	.string "Quoi? Tu les as battus? Hah!\n"
	.string "Arrête de mentir.\p"
	.string "Naan, t'aimes pas crâner, toi!\n"
	.string "Allez, baston...$"

AzaleaTown_Text_RivalWin:
	.string "...Humpff! Vilains Pokémon!\p"
	.string "Ouvre bien tes oreilles mon\n"
	.string "p'tit\p"
	.string "chat, t'as gagné parce que mes\n"
	.string "Pokémon se sont couchés tard...$"

AzaleaTown_Text_RivalAfter:
	.string "Je déteste les minus.\p"
	.string "Pokémon ou dresseur, c'est du\n"
	.string "kif-kif.\p"
	.string "Je vais devenir surpuissant et\n"
	.string "balayer les minus.\p"
	.string "Et c'est pareil pour la TEAM\n"
	.string "ROCKET.\p"
	.string "Ils sont redoutés\n"
	.string "parce qu'ils agissent\p"
	.string "en groupe, mais un par\n"
	.string "un ils sont faibles.\p"
	.string "Je les déteste tous!\p"
	.string "Hors de ma vue minus! Quelqu'un\p"
	.string "comme toi ne peut rien\n"
	.string "m'apporter...$"

AzaleaTown_Text_RivalLoss:
	.string "Pfff! J’étais sûr que c’était du\n"
	.string "bluff...$"

AzaleaTown_Text_Rocket1:
	.string "C'est dangereux d'entrer ici, je\n"
	.string "monte la garde.\p"
	.string "J'suis trop cool, tu ne trouves\n"
	.string "pas?$"

AzaleaTown_Text_Rocket2:
	.string "T’as entendu parler\n"
	.string "des Queues de\p"
	.string "RAMOLOSS? Il paraît\n"
	.string "que c’est bon...\p"
	.string "J’suis un bon gars, tu trouves\n"
	.string "pas?$"

AzaleaTown_Text_GrampsBefore:
	.string "Les RAMOLOSS ont déserté la\n"
	.string "ville.\p"
	.string "Il paraît que des\n"
	.string "gens vendent des\p"
	.string "Queues de RAMOLOSS,\n"
	.string "alors forcément...$"

AzaleaTown_Text_GrampsAfter:
	.string "Les RAMOLOSS sont de retour.\p"
	.string "A mon avis, ils devaient traîner\n"
	.string "quelque part.$"

AzaleaTown_Text_Teacher:
	.string "Es-tu ici pour FARGAS, celui qui\n"
	.string "fabrique les BALLS?\p"
	.string "Il n'y a pas que toi.$"

AzaleaTown_Text_Youngster:
	.string "Traverse Ecorcia et tu trouveras\n"
	.string "le Bois aux Chênes.\p"
	.string "Mais de petits arbustes bloquent\n"
	.string "le passage.\p"
	.string "Heureusement, le Pokémon du\n"
	.string "charbonnier peut les couper!$"

AzaleaTown_Text_Slowpoke1:
	.string "RAMOLOSS:..........\p"
	.string "...............BÂILLE?$"

AzaleaTown_Text_Kurt1:
	.string "Le BOIS AUX CHENES est agité!\p"
	.string "Que se passe-t-il?$"

AzaleaTown_Text_Kurt2:
	.string "{PLAYER}, voilà ta GS BALL!$"

AzaleaTown_Text_Kurt3:
	.string "Peux-tu voir pourquoi le BOIS\n"
	.string "AUX CHENES est si agité?$"

AzaleaTown_Text_Sign:
	.string "ECORCIA La ville où les\p"
	.string "gens et les petits Pokémon sont\n"
	.string "bien contents d'habiter$"

AzaleaTown_Text_KurtsHouseSign:
	.string "MAISON DE FARGAS$"

AzaleaTown_Text_GymSign:
	.string "Arène d’Ecorcia Champion: Hector\p"
	.string "Maestro des Pokémon Insecte$"

AzaleaTown_Text_SlowpokeWellSign:
	.string "PUITS RAMOLOSS\p"
	.string "Aussi connu sous le nom de...\n"
	.string "PUITS de PLUIE.\p"
	.string "Les gens du coin\n"
	.string "pensent que le\p"
	.string "baillement du RAMOLOSS\n"
	.string "invoque la pluie.\p"
	.string "Les archives montrent qu'un\p"
	.string "baillement de RAMOLOSS a mis fin\n"
	.string "à 400 ans de sécheresse.$"

AzaleaTown_Text_CharcoalKilnSign:
	.string "FOUR A CHARBON$"

AzaleaTown_Text_IlexForestSign:
	.string "BOIS AUX CHENES\p"
	.string "On y entre par la porte.$"
