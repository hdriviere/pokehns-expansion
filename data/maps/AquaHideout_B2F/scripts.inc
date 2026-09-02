AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT
	setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hé, hé, hé…\p"
	.string "On avait sous-estimé tes\n"
	.string "compétences!\p"
	.string "Mais cette fois, ça y est!\p"
	.string "Je suis un cran au-dessus des\n"
	.string "SBIRES que tu as vus.\p"
	.string "Je n’vais pas flancher. Je vais\n"
	.string "te pulvériser!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hé, hé, hé… Alors moi aussi,\n"
	.string "j’ai perdu…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hé, hé, hé!\p"
	.string "Pendant que je m’amusais avec\n"
	.string "toi, notre CHEF a terminé ses\p"
	.string "préparatifs!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hé, hé, hé!\p"
	.string "Notre CHEF est déjà en route\n"
	.string "vers une caverne sous la mer!\p"
	.string "Si tu veux te lancer à sa\n"
	.string "poursuite, tu ferais bien de\p"
	.string "chercher dans le vaste océan\n"
	.string "derrière NENUCRIQUE.\p"
	.string "Mais est-ce que tu vas la\n"
	.string "trouver? Hé, hé, hé!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Ouaaah, ça m’fatigue d’attendre!\n"
	.string "En plus, tu m’dois un combat!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Fatigué d’attendre… Vaincu et\n"
	.string "abasourdi…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "CHEF… C’est assez bien?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Les téléporteurs, c’est la\n"
	.string "fierté et la réussite de notre\p"
	.string "PLANQUE!\p"
	.string "Tu n’sais pas trop où tu es,\n"
	.string "n’est-ce pas?\p"
	.string "Décontenancer et fatiguer\n"
	.string "l’ennemi, puis lui serrer la\p"
	.string "vis! C’est notre plan!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Qu’est-ce qui ne va pas chez\n"
	.string "toi? Tu ne montres pas le\p"
	.string "moindre signe de fatigue.$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Ça m’rappelle… Je ne sais plus\n"
	.string "où j’ai mis la MASTER BALL.\p"
	.string "Si je n’ai pas réussi à la\n"
	.string "garder, le CHEF va me passer un\p"
	.string "savon…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "La première chose que j’ai dû\n"
	.string "faire en arrivant ici, c’est\p"
	.string "comprendre comment ces\n"
	.string "téléporteurs fonctionnent.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "J’étais trop occupé à penser aux\n"
	.string "téléporteurs…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Je vais devoir apprendre comment\n"
	.string "me battre plus efficacement.$"
