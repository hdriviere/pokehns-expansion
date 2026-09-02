Route15_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE_HNS, Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY_HNS, Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten, Route15_EventScript_RegisterHillary
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchHillary
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterHillary::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_HillaryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HILLARY_HNS
	release
	end

Route15_EventScript_RematchHillary::
	trainerbattle_rematch TRAINER_HILLARY_HNS, Route15_Text_HillaryRematchIntro, Route15_Text_HillaryRematchDefeat
	msgbox Route15_Text_HillaryPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_HILLARY_2_HNS, Route15_EventScript_RematchHillaryTryGiveItem
	end

Route15_EventScript_RematchHillaryTryGiveItem::
	checkitem ITEM_TM_ENERGY_BALL
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_ENERGY_BALL
	closemessage
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP_HNS, Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY_HNS, Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY_HNS, Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY_HNS, Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten, Route15_EventScript_RegisterBilly
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_RematchBilly
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RegisterBilly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_BillyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY_HNS
	release
	end

Route15_EventScript_RematchBilly::
	trainerbattle_rematch TRAINER_BILLY_HNS, Route15_Text_BillyRematchIntro, Route15_Text_BillyRematchDefeat
	msgbox Route15_Text_BillyPostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_BILLY_2_HNS, Route15_EventScript_RematchBillyTryGiveItem
	end

Route15_EventScript_RematchBillyTryGiveItem::
	checkitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_TM_FACADE
	closemessage
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "Tu as vérifié que tu n’avais\n"
	.string "rien oublié?$"

Route15_Text_TeacherColetteBeaten:
	.string "Kyaaah!$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Quand j’étais petite, moi aussi\n"
	.string "j’oubliais souvent mes affaires.$"

Route15_Text_TeacherHillarySeen:
	.string "Avoir son matériel est\n"
	.string "important.\p"
	.string "Comme les dictées et les\n"
	.string "devoirs.$"

Route15_Text_TeacherHillaryBeaten:
	.string "J’ai perdu...$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "C’est important\n"
	.string "d’étudier, mais il\p"
	.string "ne faut pas négliger\n"
	.string "le sport pour autant!$"

Route15_Text_HillaryRegister:
	.string "Tu m'as donné une leçon!\n"
	.string "Puis-je avoir ton numéro?$"

Route15_Text_HillaryRematchIntro:
	.string "Cette fois, je te donnerai une\n"
	.string "leçon!$"

Route15_Text_HillaryRematchDefeat:
	.string "Retour à la case départ…$"

Route15_Text_HillaryPostRematch:
	.string "Former des Pokémon, c'est comme\n"
	.string "enseigner aux enfants. Patience!$"

Route15_Text_SchoolboyKippSeen:
	.string "Un p’tit instant, j’appelle ma\n"
	.string "maman.$"

Route15_Text_SchoolboyKippBeaten:
	.string "Allô maman? J'ai perdu!$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "Maman s'inquiète beaucoup pour\n"
	.string "moi.\p"
	.string "Alors je dois lui téléphoner...$"

Route15_Text_SchoolboyTommySeen:
	.string "En garde! Je n’ai pas\n"
	.string "l’intention de perdre!$"

Route15_Text_SchoolboyTommyBeaten:
	.string "J’ai oublié mes devoirs!!!$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Trop fort! On devient potes?\n"
	.string "Allez!!!$"

Route15_Text_SchoolboyJohnnySeen:
	.string "On va étudier à la TOUR RADIO de\p"
	.string "LAVANVILLE... Génial, non?$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "C’que t’es fort!$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "J’en ai assez de marcher... Je\n"
	.string "suis épuisé.$"

Route15_Text_SchoolboyBillySeen:
	.string "J'aime la purée! Combat!$"

Route15_Text_SchoolboyBillyBeaten:
	.string "... Super...$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "Si on avait un cours de Pokémon,\n"
	.string "je serais premier de la classe!$"

Route15_Text_BillyRegister:
	.string "J'aurais dû mieux écouter en\n"
	.string "classe.\p"
	.string "Je peux avoir ton numéro?$"

Route15_Text_BillyRematchIntro:
	.string "J'ai étudié dur!\n"
	.string "Regarde tout ce que j'ai appris!$"

Route15_Text_BillyRematchDefeat:
	.string "Je dois étudier davantage…$"

Route15_Text_BillyPostRematch:
	.string "Les livres ne suffisent pas.\n"
	.string "Il me faut aussi de l'expérience\l"
	.string "au combat!$"

Route15_Text_Sign:
	.string "ROUTE 15\p"
	.string "PARMANIE LAVANVILLE$"
