EcruteakCity_SageOffice1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "Le glas d'étain sonne clairement\n"
	.string "pour ceux que la tour protège.$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SAGEOFFICE_SAGE
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "La TOUR FERRAILLE est interdite\n"
	.string "à ceux qui n'en sont pas dignes.\p"
	.string "Désolé, mais tu dois partir.$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "La TOUR FERRAILLE est\n"
	.string "inaccessible à\p"
	.string "tous ceux qui n'ont pas le BADGE\p"
	.string "de l'ARENE de ROSALIA.\p"
	.string "Ah!\p"
	.string "Le BADGE de l'ARENE de ROSALIA!\n"
	.string "Vous pouvez passer.$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "Il y a un problème.\p"
	.string "Excusez-moi, mais vous devez\n"
	.string "partir.\p"
	.string "...Poyé polomi...\p"
	.string "Le TRIO des SAGES dit de drôles\n"
	.string "de trucs...$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "Un événement capital\n"
	.string "s'est produit.\p"
	.string "Pardonne-moi, mais je dois te\n"
	.string "demander de partir.\p"
	.string "..............................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "Ah!\p"
	.string "Le son de ce GLAS TRANSPARENT!\p"
	.string "C'est... C'est sublime!\p"
	.string "Je n'avais encore jamais entendu\n"
	.string "un son aussi beau!\p"
	.string "Le timbre de ce glas reflète\n"
	.string "l'âme de celui qui le porte.\p"
	.string "Toi...\p"
	.string "Tu parviendras peut-être à\n"
	.string "traverser la TOUR FERRAILLE.\p"
	.string "Je t'en prie, avance.$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Je vous en prie.$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "Le timbre de ce glas reflète\n"
	.string "l'âme de celui qui le porte.\p"
	.string "Toi...\n"
	.string "Tu en es vraiment digne.$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TOUR FERRAILLE est d'une pure\n"
	.string "beauté.\p"
	.string "Elle apaise tous ceux qui la\n"
	.string "regardent.$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "La TOUR FERRAILLE\n"
	.string "tremble! Un\p"
	.string "Pokémon doit s'être\n"
	.string "posé au sommet!$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "Deux tours... Deux Pokémon...\p"
	.string "Mais lorsqu'une d'entre elles a\p"
	.string "brûlé, les deux\n"
	.string "Pokémon se sont\p"
	.string "envolés et ne sont\n"
	.string "jamais revenus.$"
