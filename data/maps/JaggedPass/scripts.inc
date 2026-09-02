JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "Le SENTIER SINUROC du MONT\n"
	.string "CHIMNEE…\p"
	.string "J’ai toujours rêvé d’un endroit\n"
	.string "pareil…\p"
	.string "Ce relief accidenté… J’adore ça!$"

JaggedPass_Text_EricDefeat:
	.string "La défaite me laisse amer!$"

JaggedPass_Text_EricPostBattle:
	.string "Oui, je peux perdre avec les\n"
	.string "POKéMON…\p"
	.string "Mais s’il s’agissait de notre\n"
	.string "amour pour la montagne, je te\p"
	.string "battrais!$"

JaggedPass_Text_DianaIntro:
	.string "Tu n’te promènes pas ici par\n"
	.string "hasard. T’es pas là pour\p"
	.string "pique-niquer!$"

JaggedPass_Text_DianaDefeat:
	.string "Oooh, non! Ce sol est trop\n"
	.string "bosselé…$"

JaggedPass_Text_DianaPostBattle:
	.string "Tu savais ça?\p"
	.string "Les plus habiles utilisent leur\n"
	.string "VELO pour passer ce col très\p"
	.string "accidenté.$"

JaggedPass_Text_DianaRegister:
	.string "Tu reviendras un jour par ici?\n"
	.string "Si c’est le cas, j’aimerais bien\p"
	.string "refaire un match avec toi.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Un pique-nique, c’est toujours\n"
	.string "sympa. Exactement comme les\p"
	.string "POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Si j’ai perdu, c’est juste à\n"
	.string "cause de ce sol trop bosselé!$"

JaggedPass_Text_DianaPostRematch:
	.string "Je vais oublier ma défaite et\n"
	.string "apprécier cette randonnée à\p"
	.string "travers les bosses.$"

JaggedPass_Text_EthanIntro:
	.string "C’est dur de marcher sur le\n"
	.string "SENTIER SINUROC.\p"
	.string "Mais c’est super pour\n"
	.string "s’entraîner!$"

JaggedPass_Text_EthanDefeat:
	.string "On essayait encore de trouver\n"
	.string "une bonne prise, alors que tout\p"
	.string "était déjà terminé.$"

JaggedPass_Text_EthanPostBattle:
	.string "Si j’avais un VELO CROSS, je\n"
	.string "pourrais sauter sur ces rebords\p"
	.string "rocheux.$"

JaggedPass_Text_EthanRegister:
	.string "J’arriverai à te battre quand je\n"
	.string "me serai habitué à ces bosses!\p"
	.string "Tu peux m’enregistrer dans ton\n"
	.string "POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Je suis habitué à toutes ces\n"
	.string "bosses. Maintenant, je chante en\p"
	.string "grimpant.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "C’est quand même pas facile de\n"
	.string "se battre sur ce sol tout\p"
	.string "bosselé…$"

JaggedPass_Text_EthanPostRematch:
	.string "Il faudrait que j’aille à\n"
	.string "LAVANDIA pour que RODOLPHE me\p"
	.string "donne un VELO CROSS.$"

JaggedPass_Text_GruntIntro:
	.string "Quoi? Qu’est-ce que tu fais là?\p"
	.string "Qu’est-ce que je fais dans un\n"
	.string "endroit pareil?\p"
	.string "Ça te regarde?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "J’aurais dû rester caché dans la\n"
	.string "PLANQUE…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "OK, OK… Je dois l’avouer, tu\n"
	.string "sais te battre!\p"
	.string "Ne t’inquiète pas pour moi. Tu\n"
	.string "peux aller où tu veux!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Ce rocher semble réagir à la\n"
	.string "présence du SCEAU MAGMA!$"

JaggedPass_Text_JulioIntro:
	.string "Ça fait super peur de descendre\n"
	.string "la montagne d’un coup!$"

JaggedPass_Text_JulioDefeat:
	.string "J’ai l’impression de tomber en\n"
	.string "morceaux…$"

JaggedPass_Text_JulioPostBattle:
	.string "Mon vélo s’est pris tellement de\n"
	.string "bosses que je ne sens plus mon\p"
	.string "dos.$"

JaggedPass_Text_AutumnIntro:
	.string "Je gravis cette colline chaque\n"
	.string "jour. J’ai confiance en ma\p"
	.string "force!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hum… Qu’est-ce qui s’est passé?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Est-ce que tu sais ce qu’est\n"
	.string "cette étrange avancée rocheuse\p"
	.string "un peu plus loin?$"

