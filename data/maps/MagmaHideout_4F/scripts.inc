MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Moi aussi je voudrais voir\n"
	.string "GROUDON… Mais ils ne me laissent\p"
	.string "même pas voir le bout de sa\n"
	.string "queue.\p"
	.string "C’est vraiment pas sympa.\p"
	.string "Oh non! Je viens de cracher le\n"
	.string "morceau!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Je devais être trop énervé pour\n"
	.string "pouvoir gagner ce combat.$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "En fait, je ne sais même pas si\n"
	.string "GROUDON a une queue…$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Wahaha! Bientôt… Très bientôt!\n"
	.string "Nous sommes sur le point de\p"
	.string "réussir!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr… J’y étais presque!$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAX! Un intrus vient vers vous!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Ne crois pas pouvoir passer\n"
	.string "facilement. Tu ne m’as pas\p"
	.string "encore battu!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "T’as juste eu de la chance!$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Allez… Encore un combat…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Héhéhé… Tu as réussi à venir\n"
	.string "jusqu’ici, alors je vais tout te\p"
	.string "raconter!\p"
	.string "C’est bien ça! GROUDON est en\n"
	.string "train de dormir, juste un peu\p"
	.string "plus loin.\p"
	.string "Mais MAX doit déjà être avec\n"
	.string "lui.\p"
	.string "Ce n’est plus qu’une question de\n"
	.string "secondes avant qu’il ne le\p"
	.string "réveille!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Je suis humilié… Encore une\n"
	.string "fois…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "Mais pendant que tu perdais ton\n"
	.string "temps avec moi, MAX a dû\p"
	.string "réveiller GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAX: GROUDON…\p"
	.string "Rien n’a encore pu te réveiller\n"
	.string "de ton sommeil dans ce bain de\p"
	.string "magma…\p"
	.string "Cet ORBE BLEU, il te manquait,\n"
	.string "n’est-ce pas?\p"
	.string "Je t’ai ramené l’ORBE BLEU. Que\n"
	.string "sa lumière te réveille!\p"
	.string "Et montre-moi… Montre-moi\n"
	.string "l’étendue de ta puissance!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAX: GROUDON! Que se passe-t-il?\p"
	.string "L’ORBE BLEU était bien la clef?!\p"
	.string "GROUDON! Où es-tu parti?$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAX: Oh, c’était donc toi?\p"
	.string "Tu n’as pas arrêté d’apparaître\n"
	.string "ici et là…\p"
	.string "Je comprends maintenant! C’est\n"
	.string "sûrement à cause de toi!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "D’où te vient cette maîtrise des\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAX: Il doit bien y avoir une\n"
	.string "raison pour que GROUDON soit\p"
	.string "parti comme ça…\p"
	.string "C’est ce que tu essaies de me\n"
	.string "dire, c’est ça?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Humpf… Et tu crois que je le\n"
	.string "savais pas?\p"
	.string "GROUDON parti, nous n’avons plus\n"
	.string "rien à faire dans ce volcan.\p"
	.string "Je pars à sa recherche, nos\n"
	.string "chemins se séparent ici!$"
