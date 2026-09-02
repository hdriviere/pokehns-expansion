GoldenrodCity_RadioTower_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2_HNS, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "T-toi! T-tu es là pour me\n"
	.string "s-sauver?$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "Alors... Tu t'y attendais?\p"
	.string "Et oui! Je suis un imposteur!\p"
	.string "Cette mascarade était nécessaire\p"
	.string "à notre invasion! Ha ha ha ha\n"
	.string "ha!\p"
	.string "Veux-tu savoir où est caché le\n"
	.string "vrai DIRECTEUR?\p"
	.string "J'vais te le dire. Mais\n"
	.string "d'abord... COMBAT!!!!$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "OK, OK. Je vais parler.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "Le boss a caché le DIRECTEUR\n"
	.string "dans l'ENTREPOT SOUTERRAIN.\p"
	.string "Il est au fond du SOUTERRAIN.\p"
	.string "Je suis gentil: je te donne\n"
	.string "la CLE SOUS-SOL pour atteindre\p"
	.string "l'ENTREPOT SOUTERRAIN.\p"
	.string "Mais tu n'iras pas jusque-là.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "Le boss a caché le DIRECTEUR\n"
	.string "dans l'ENTREPOT SOUTERRAIN.\p"
	.string "Il est au fond du SOUTERRAIN.\p"
	.string "La CLE SOUS-SOL mène à\n"
	.string "l'ENTREPOT SOUTERRAIN.\p"
	.string "Mais tu n'iras pas jusque-là.$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2_HNS GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER_HNS, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "Tu te souviens de moi dans la\n"
	.string "PLANQUE d'ACAJOU?\p"
	.string "Mon boss m'a grondée, mais je\n"
	.string "suis devenue plus forte.\p"
	.string "J'avais perdu. Pas cette fois!$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "Ce n'est pas possible!\p"
	.string "Je me suis battue à fond, mais\n"
	.string "j'ai encore perdu…\p"
	.string "Je suis désolée, GIOVANNI…$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{PLAYER}, c'est ça?\p"
	.string "Une peste comme toi ne voit pas\p"
	.string "la grandeur de la TEAM ROCKET.\p"
	.string "C'est dommage. Tu as pourtant du\n"
	.string "talent.$"

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "Oh? Tu es déjà là?\p"
	.string "Tu dois avoir un sacré talent.\p"
	.string "Nous allons contrôler\n"
	.string "cette STATION de\p"
	.string "RADIO pour annoncer\n"
	.string "au monde notre retour.\p"
	.string "Cela devrait faire revenir notre\n"
	.string "chef\p"
	.string "GIOVANNI de son entraînement\n"
	.string "solo.\p"
	.string "La gloire passée de la TEAM sera\n"
	.string "restituée.\p"
	.string "Et toi minable, tu vas pas nous\n"
	.string "agacer longtemps.$"

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "Non! Pardonnez-moi, Maître\n"
	.string "Giovanni!$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "Impossible!\p"
	.string "Nos rêves se brisent.\p"
	.string "Je suis pas digne.\p"
	.string "Comme GIOVANNI l'a fait jadis,\n"
	.string "je\p"
	.string "vais dissoudre la TEAM ROCKET.\p"
	.string "Adieu.$"

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "DIRECTEUR: Merci {PLAYER}!\p"
	.string "Ton courage a sauvé les Pokémon\n"
	.string "du monde entier.\p"
	.string "Ce n'est pas grand chose, mais\n"
	.string "c'est pour toi.$"

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "Une tour se trouvait autrefois\n"
	.string "ici, à DOUBLONVILLE.\p"
	.string "Elle était vieille et fragile.\p"
	.string "Nous l'avons remplacée par la\n"
	.string "TOUR RADIO.\p"
	.string "Cette aile fut déterrée pendant\n"
	.string "les travaux.\p"
	.string "De nombreux Pokémon vivaient\n"
	.string "jadis à DOUBLONVILLE.\p"
	.string "Peut-être…\p"
	.string "Cette aile serait liée à la TOUR\n"
	.string "FERRAILLE de ROSALIA…\p"
	.string "Bon, je retourne à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "Une tour se trouvait autrefois\n"
	.string "ici, à DOUBLONVILLE.\p"
	.string "Elle était vieille et fragile.\p"
	.string "Nous l'avons remplacée par la\n"
	.string "TOUR RADIO.\p"
	.string "Cette aile fut déterrée pendant\n"
	.string "les travaux.\p"
	.string "De nombreux Pokémon vivaient\n"
	.string "jadis à DOUBLONVILLE.\p"
	.string "Peut-être…\p"
	.string "Cette aile a un lien avec les\n"
	.string "TOURB'ILES, près d'IRISIA…\p"
	.string "Bon, je retourne à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "Ah!\p"
	.string "Cela me rappelle quelque chose…\p"
	.string "L'aile que je t'ai donnée semble\n"
	.string "liée au Pokémon légendaire.\p"
	.string "Mais cette aile seule ne suffira\n"
	.string "pas à le faire apparaître…\p"
	.string "Il faudrait aussi autre chose…\n"
	.string "Enfin, quelque chose comme ça.\p"
	.string "Qu'est-ce que c'était déjà…\p"
	.string "Je ne m'en souviens plus.$"

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "Non, ce n’est rien! C’était ce\n"
	.string "qu’on appelle une feinte!\p"
	.string "Allez, cette fois, je retourne à\n"
	.string "mon bureau pour de vrai!$"

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "DIRECTEUR: Salut, {PLAYER}!\p"
	.string "Tu sais, j'adore les Pokémon.\p"
	.string "J'ai construit cette TOUR RADIO\p"
	.string "pour crier au monde mon amour.\p"
	.string "Mais les gens aiment-ils nos\n"
	.string "émissions?$"

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "BEN: Tu écoutes notre musique?$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "4{SUPER_E}: Bureau de la\n"
	.string "Direction$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "4EME STUDIO 1$"
