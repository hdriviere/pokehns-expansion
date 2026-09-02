CianwoodGym_hns_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "Arène d’Irisia$"

CianwoodGym_Text_GymStatueCertified:
	.string "ARENE Pokémon D'IRISIA\p"
	.string "DRESSEURS CERTIFIÉS PAR CHUCK:\n"
	.string "{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "WAHAHAHA, {PLAYER}!\n"
	.string "Je suis en plein entraînement!\p"
	.string "Si tu veux un autre combat,\n"
	.string "viens au DOJO de SAFRANIA!$"

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "On se retrouve au DOJO!\n"
	.string "WAHAHAHAHAHA!$"

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "WAHAHAH!\p"
	.string "Te voilà toi! Laisse-moi te dire\n"
	.string "que je suis une bête!\p"
	.string "Mes Pokémon explosent la roche\n"
	.string "et fracassent les os!\p"
	.string "Regarde ça!$"

CianwoodGym_Text_ChuckIntro2:
	.string "Urgh... ...\p"
	.string "Aaaaargh!!!$"

CianwoodGym_Text_ChuckIntro3:
	.string "Alors! Ça t’en bouche un coin,\n"
	.string "hein!\p"
	.string "Quoi? Ça n’a aucun rapport avec\n"
	.string "les Pokémon?\p"
	.string "Ouais, c’est pas faux. Allez,\n"
	.string "finissons-en!$"

CianwoodGym_Text_ChuckLoss:
	.string "Hein? Koi? Méheeuu j'ai pas\n"
	.string "gagné là?\p"
	.string "A propos, je peux te\n"
	.string "dire un truc? Je pense\p"
	.string "que tu mérites le\n"
	.string "bon vieux BADGE CHOC!$"

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER} reçoit le BADGE CHOC.$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "Avec le BADGE CHOC tous les\n"
	.string "Pokémon\p"
	.string "jusqu'au niveau 70 et même les\n"
	.string "échangés t'obéiront.\p"
	.string "Il permet aussi à tes Pokémon\p"
	.string "d'utiliser VOL hors des combats.\p"
	.string "Tiens, attrape ça!$"

CianwoodGym_Text_ChuckTMSpeech:
	.string "C'est MITRA-POING.\p"
	.string "Cette capacité agit lentement,\n"
	.string "mais inflige d'énormes dégâts.\p"
	.string "Évite juste d'être touché avant!$"

CianwoodGym_Text_ChuckAfter:
	.string "WAHAHAH! J'ai aimé me battre\n"
	.string "contre toi!\p"
	.string "Mais une défaite signifie le\n"
	.string "plus souvent qu'on a perdu!\p"
	.string "Donc dorénavant je vais\n"
	.string "m'entraîner 24 heures sur 24!$"

CianwoodGym_Text_ChuckRematch:
	.string "WAHAHAH! Maître de JOHTO!\p"
	.string "Tu en redemandes!\p"
	.string "Je vois que tu as progressé!\p"
	.string "Prêt à découvrir qui est\n"
	.string "le plus fort?$"

CianwoodGym_Text_ChuckRematchDefeat:
	.string "Quoi? Hein? J'ai perdu?\n"
	.string "Encore?$"

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI_HNS, CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "Mes Pokémon et moi sommes liés\n"
	.string "par une grande amitié.\p"
	.string "Notre liaison ne mourra jamais!$"

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "C'est pas vrai!$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "Toi aussi tu sembles\n"
	.string "avoir lié une très\p"
	.string "forte complicité\n"
	.string "avec tes Pokémon!$"

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_HNS, CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "Nous autres, les\n"
	.string "vaillants artistes\p"
	.string "martiaux, n’avons\n"
	.string "peur de rien!$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "C'est choquant!$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "Les Pokémon de\n"
	.string "combat sont un\p"
	.string "peu effrayés par\n"
	.string "les Pokémon psy...$"


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_HNS, CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "Je n’ai besoin\n"
	.string "de rien. Même pas\p"
	.string "des mots. Je fais\n"
	.string "parler mes poings!$"

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "...$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "J’ai perdu, rien à redire.$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG_HNS, CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "Nos poings furieux vont tailler\n"
	.string "ton équipe en pièces!$"

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "En... en pièces!$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "Mes Pokémon ont perdu, ma fierté\n"
	.string "en a pris un coup!$"
