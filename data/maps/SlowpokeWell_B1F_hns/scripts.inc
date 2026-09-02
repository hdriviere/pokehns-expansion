SlowpokeWell_B1F_hns_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21_HNS, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22_HNS, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_HNS, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1_HNS, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE_HNS, 15, 4
	waitstate
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "Fargas: Oh! {PLAYER}!\p"
	.string "Le garde a décampé quand je lui\n"
	.string "ai crié dessus...\p"
	.string "Et puis je suis\n"
	.string "descendu dans le\p"
	.string "puits, mais j’me\n"
	.string "suis planté et...\p"
	.string "Je peux plus bouger.\p"
	.string "Pfff! Si j’étais en forme, mes\n"
	.string "Pokémon les auraient punis...\p"
	.string "C’est vraiment trop bête.\n"
	.string "{PLAYER}, va leur mettre une\p"
	.string "raclée à ma place!$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "FARGAS: Bravo, {PLAYER}!\p"
	.string "La TEAM ROCKET a décampé.\p"
	.string "Mon dos va mieux. Allez... On se\n"
	.string "casse.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "Grrah! Je montais la garde quand\n"
	.string "un\p"
	.string "vieux dingue est venu me crier\n"
	.string "dessus.\p"
	.string "Il m'a fichu une telle trouille\n"
	.string "que je suis tombé ici.\p"
	.string "... Tu sais quoi? Je vais calmer\n"
	.string "mes nerfs sur ta face!$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "Grrah! C'est pas mon jour!$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Bah... Bien sûr qu'on vend des\p"
	.string "queues de RAMOLOSS volées.\p"
	.string "On ferait n'importe quoi pour le\n"
	.string "pognon.\p"
	.string "Et oui! La TEAM ROCKET c'est pas\p"
	.string "d'la rigolade! On est des\n"
	.string "méchants!$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "Kesstu veux?\p"
	.string "Si tu viens nous embêter, ça va\n"
	.string "barder!$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "Attends voir la prochaine fois!$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "LANCE: La TEAM ROCKET a été\n"
	.string "dissoute il y a trois ans.\p"
	.string "Le boss est entré dans la\n"
	.string "clandestinité.\p"
	.string "Mais nous avons poursuivi nos\n"
	.string "activités dans l'ombre!\p"
	.string "Un petit obstacle comme toi ne\n"
	.string "gênera guère notre mission.\p"
	.string "Tu devras vivre dans la terreur\n"
	.string "de nos prochains coups!$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Ha-ha-ha!\p"
	.string "Arrêter de couper les QUEUES de\n"
	.string "RAMOLOSS?\p"
	.string "Tu es dingue! Notre réputation,\n"
	.string "tu y as pensé?$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Argh... Trop fort...$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "On a besoin de sous à la TEAM\n"
	.string "ROCKET...\p"
	.string "C'est pas facile d'être un\n"
	.string "SBIRE!$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "Arrêter de voler les QUEUES?\p"
	.string "C'est ça, oui... T'as raison...$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "Sale môme!$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "Les QUEUES de RAMOLOSS? Ca\n"
	.string "repousse vite!\p"
	.string "Alors on peut les vendre, non?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "Un RAMOLOSS sans QUEUE...\p"
	.string "Hein? Il a une LETTRE. On la\n"
	.string "lit?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} lit la Lettre.\p"
	.string "Sois sage et\n"
	.string "occupe-toi bien de\p"
	.string "la maison avec papy\n"
	.string "et le RAMOLOSS.\p"
	.string "Bisous.              Papa.$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "Un RAMOLOSS à la queue coupée...$"
