Route24_Frlg_MapScripts::
	.byte 0

Route24_EventScript_Rocket::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	call Route24_EventScript_BattleRocket
	release
	end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom
	release
	end

Route24_EventScript_RocketPostBattle::
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	release
	end

Route24_EventScript_RocketTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketApproachPlayer
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketMotionToPlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
	call Route24_EventScript_BattleRocket
	releaseall
	end

Route24_EventScript_BattleRocket::
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
	message Route24_Text_JoinTeamRocket
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_ROUTE24_ROCKET
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	setvar VAR_MAP_SCENE_ROUTE24, 1
	return

Route24_EventScript_RocketApproachPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproachPlayer
	waitmovement 0
	return

Route24_EventScript_RocketMotionToPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route24_EventScript_NoRoomForNuggetTrigger::
	msgbox Route24_Text_YouDontHaveAnyRoom
	closemessage
	applymovement LOCALID_PLAYER, Route24_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
	release
	end

Route24_EventScript_RocketWalkBackToPos::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketWalkBackToPos
	waitmovement 0
	return

Route24_Movement_RocketApproachPlayer::
	walk_left
	step_end

Route24_Movement_RocketWalkBackToPos::
	walk_right
	walk_in_place_faster_left
	step_end

Route24_Movement_WalkDown::
	walk_down
	step_end

Route24_Text_JustEarnedFabulousPrize::
	.string "Félicitations! Tu as battu les 5\n"
	.string "DRESSEURS!\p"
	.string "Tu as gagné un fabuleux prix!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
	.string "{PLAYER} obtient: PEPITE!$"

Route24_Text_YouDontHaveAnyRoom::
	.string "Ton inventaire est plein!$"

Route24_Text_JoinTeamRocket::
	.string "Veux-tu rejoindre les rangs de\n"
	.string "la TEAM ROCKET?\p"
	.string "Nous sommes un groupe de\n"
	.string "criminels spécialisés en\p"
	.string "POKéMON!\p"
	.string "Ça t'intéresse?\p"
	.string "Vraiment?\p"
	.string "Allez, viens!\p"
	.string "Bon, je t'ai dit de venir avec\n"
	.string "nous!\p"
	.string "Je vois…\p"
	.string "Je vais devoir me montrer plus\n"
	.string "persuasif!$"

Route24_Text_RocketDefeat::
	.string "Arrgh! Pas mal!$"

Route24_Text_YoudBecomeTopRocketLeader::
	.string "Tu pourrais vite devenir un chef\n"
	.string "au sein de la TEAM ROCKET!\p"
	.string "Allez, je te laisse y penser, ne\n"
	.string "laisse pas passer cette chance.$"

Route24_Text_ShaneIntro::
	.string "Je suis au courant de tes\n"
	.string "exploits!$"

Route24_Text_ShaneDefeat::
	.string "Oh, je pensais avoir une chance.$"

Route24_Text_ShanePostBattle::
	.string "Je me cache, les gens sur le\n"
	.string "pont me font peur!$"

Route24_Text_EthanIntro::
	.string "OK! J'suis le numéro 5! Je vais\n"
	.string "t'écraser!$"

Route24_Text_EthanDefeat::
	.string "Ah! Purée!$"

Route24_Text_EthanPostBattle::
	.string "Pas de regret, j'ai fait de mon\n"
	.string "mieux!$"

Route24_Text_ReliIntro::
	.string "Je suis le numéro 4! T'en as pas\n"
	.string "eu assez?$"

Route24_Text_ReliDefeat::
	.string "Tu… … m'as battue!$"

Route24_Text_ReliPostBattle::
	.string "J'ai participé, et j'ai perdu!$"

Route24_Text_TimmyIntro::
	.string "Je suis le numéro 3! C'est pas\n"
	.string "gagné!$"

Route24_Text_TimmyDefeat::
	.string "Oh! Tu m'as écrasé!$"

Route24_Text_TimmyPostBattle::
	.string "J'ai fait de mon mieux!$"

Route24_Text_AliIntro::
	.string "Je suis le numéro 2! Ça rigole\n"
	.string "plus!$"

Route24_Text_AliDefeat::
	.string "Ben… Tu m'as battue?$"

Route24_Text_AliPostBattle::
	.string "J'ai fait de mon mieux, j'ai pas\n"
	.string "de regret!$"

Route24_Text_CaleIntro::
	.string "Voici le PONT PEPITE! 5\n"
	.string "DRESSEURS le défendent!\p"
	.string "Bats-les tous pour remporter un\n"
	.string "prix fabuleux!\p"
	.string "Tu crois pouvoir y arriver?$"

Route24_Text_CaleDefeat::
	.string "Haha! Bien joué!$"

Route24_Text_CalePostBattle::
	.string "J'ai fait de mon mieux. Si si!\n"
	.string "C'est vrai!$"
