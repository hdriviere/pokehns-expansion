Route32_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN_HNS, Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH_HNS, Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten, Route32_EventScript_RegisterRalph
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchRalph
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterRalph::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_RalphRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RALPH_HNS
	release
	end

Route32_EventScript_RematchRalph::
	trainerbattle_rematch TRAINER_RALPH_HNS, Route32_Text_RalphRematchIntro, Route32_Text_RalphRematchDefeat
	msgbox Route32_Text_RalphPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY_HNS, Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT_HNS, Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON_HNS, Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND_HNS, Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ_HNS, Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten, Route32_EventScript_RegisterLiz
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_RematchLiz
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RegisterLiz::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route32_Text_LizRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LIZ_HNS
	release
	end

Route32_EventScript_RematchLiz::
	trainerbattle_rematch TRAINER_LIZ_HNS, Route32_Text_LizRematchIntro, Route32_Text_LizRematchDefeat
	msgbox Route32_Text_LizPostRematch, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER_HNS, Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SLOWPOKETAIL_MAN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE32_BALDINGMAN
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Item_Bullet_Seed::
    finditem ITEM_TM_BULLET_SEED
    end
	
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "Hé!! On se calme, la jeunesse!$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "{PLAYER}, c'est ça? Un type avec\n"
	.string "des\p"
	.string "lunettes te cherchait.\p"
	.string "Il t'attend au CENTRE Pokémon.$"

Route32_Text_CooltrainerM_SproutTower:
	.string "As-tu visité la TOUR CHETIFLOR?\p"
	.string "Si tu vas à MAUVILLE, tu dois\p"
	.string "aller t'y entraîner.\p"
	.string "C'est le devoir de tout\n"
	.string "dresseur!$"

Route32_Text_CooltrainerM_VioletGym:
	.string "As-tu visité l'ARENE Pokémon?\p"
	.string "Tu peux y mettre tes compétences\n"
	.string "à l'épreuve.\p"
	.string "Tous les dresseurs doivent y\n"
	.string "aller!$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "Tu as de bons Pokémon, tu sais.\p"
	.string "Ils ont dû s'entraîner autour de\n"
	.string "MAUVILLE.\p"
	.string "Les combats dans l'ARENE t'ont\p"
	.string "donné de l'expérience, non?\p"
	.string "En souvenir de MAUVILLE, accepte\n"
	.string "ceci.\p"
	.string "Cela améliore les capacités du\n"
	.string "type PLANTE.$"

Route32_Text_CooltrainerM_Experiences:
	.string "Ta visite à Mauville te servira\n"
	.string "dans ton voyage.$"

Route32_Text_SlowpokeTailOffer:
	.string "Hé toi! Ca te dit une bonne\n"
	.string "QUEUERAMOLOS?\p"
	.string "J'te fais un prix: 1000000¥!\p"
	.string "C'est pour toi!$"

Route32_Text_ThoughtKidsLoaded:
	.string "T’as pas assez d’argent!\p"
	.string "Tss! Et moi qui pensais\n"
	.string "que les enfants de\p"
	.string "nos jours étaient\n"
	.string "pleins de tunes...$"

Route32_Text_RefusedSlowpokeTail:
	.string "T’en veux pas? Alors dégage!\n"
	.string "Dégage!$"

Route32_Text_FisherJustin_Seen:
	.string "Ouah!\p"
	.string "Tu m’as fait peur et j’ai lâché\n"
	.string "ma proie!$"

Route32_Text_FisherJustin_Beaten:
	.string "Splash!$"

Route32_Text_FisherJustin_After:
	.string "L’essence de\n"
	.string "la pêche et du\p"
	.string "combat de Pokémon,\n"
	.string "c’est le calme.$"

Route32_Text_FisherRalph1_Seen:
	.string "La pêche et les Pokémon, c'est\n"
	.string "de la balle.\p"
	.string "J'suis pas du genre à perdre!$"

Route32_Text_FisherRalph1_Beaten:
	.string "J’ai été trop rapide...$"

Route32_Text_FisherRalph1_After:
	.string "La pêche, c’est la\n"
	.string "passion d’une vie.\p"
	.string "Les Pokémon, c’est\n"
	.string "des amis pour la vie.$"

Route32_Text_RalphRegister:
	.string "La pêche, c’est la\n"
	.string "passion d’une vie.\p"
	.string "Les Pokémon, c’est\n"
	.string "des amis pour la vie.$"

Route32_Text_RalphRematchIntro:
	.string "La pêche et les Pokémon, c'est\n"
	.string "de la balle.\p"
	.string "J'suis pas du genre à perdre!$"

Route32_Text_RalphRematchDefeat:
	.string "J’ai été trop rapide...$"

Route32_Text_RalphPostRematch:
	.string "La pêche, c’est la\n"
	.string "passion d’une vie.\p"
	.string "Les Pokémon, c’est\n"
	.string "des amis pour la vie.$"

Route32_Text_FisherHenry_Seen:
	.string "Mes Pokémon? Frais pêchés du\n"
	.string "matin!$"

Route32_Text_FisherHenry_Beaten:
	.string "Splash!$"

Route32_Text_FisherHenry_After:
	.string "Les Pokémon bien\n"
	.string "entraînés sont\p"
	.string "plus forts que ceux\n"
	.string "fraîchement attrapés.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "On s'connaît? Tu veux crâner?\p"
	.string "On va voir ça!$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "T'es balèze!$"

Route32_Text_YoungsterAlbert_After:
	.string "Je serai le plus fort avec mes\n"
	.string "Pokémon favoris.\p"
	.string "Je n'utilise pas les\n"
	.string "gros Pokémon super\p"
	.string "balèzes que tout\n"
	.string "le monde choisit.$"

Route32_Text_YoungsterGordon_Seen:
	.string "J’ai trouvé des\n"
	.string "super Pokémon dans\p"
	.string "les hautes herbes!\n"
	.string "Regarde-moi ça!$"

Route32_Text_YoungsterGordon_Beaten:
	.string "Et ben ça alors.$"

Route32_Text_YoungsterGordon_After:
	.string "Y'a plein de trucs dans l'herbe.$"

Route32_Text_CamperRoland_Seen:
	.string "Ce regard... Tu m’intrigues.$"

Route32_Text_CamperRoland_Beaten:
	.string "Hmm, dommage.$"

Route32_Text_CamperRoland_After:
	.string "Evite les regards si tu ne veux\n"
	.string "pas te battre.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Ah-ha. Ouais. Vers midi.\p"
	.string "Quoi? Combat? J'suis au tél!\p"
	.string "Bon d'accord. Mais rapide.$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "Oh! Il faut que je me calme!$"

Route32_Text_PicnickerLiz1_After:
	.string "J'avais une copine au téléphone.$"

Route32_Text_LizRegister:
	.string "J'avais une copine au téléphone.$"

Route32_Text_LizRematchIntro:
	.string "Ah-ha. Ouais. Vers midi.\p"
	.string "Quoi? Combat? J'suis au tél!\p"
	.string "Bon d'accord. Mais rapide.$"

Route32_Text_LizRematchDefeat:
	.string "Oh! Il faut que je me calme!$"

Route32_Text_LizPostRematch:
	.string "J'avais une copine au téléphone.$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "Ce BADGE! Il vient de MAUVILLE!\p"
	.string "T'as battu ALBERT?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "Hum... Je ne suis pas encore\n"
	.string "prêt.$"

Route32_Text_BirdKeeperPeter_After:
	.string "Je vais encore m’entraîner dans\n"
	.string "l’Arène de Mauville.$"

Route32_Text_RoarIntro:
	.string "GROAAARH!!!\p"
	.string "LES GENS S’ENFUIENT QUAND JE\n"
	.string "CRIE, MAIS TOI TU T’APPROCHES!\p"
	.string "T’ES SUPER! VOILA POUR TOI!!!$"

Route32_Text_RoarOutro:
	.string "GRAAAAAH! C'EST HURLEMENT!\p"
	.string "CA FAIT PEUR AUX Pokémon!$"

Route32_Text_MeetFrieda:
	.string "VANESSA: Ouaiis!\p"
	.string "Je suis VANESSA, de la FAMILLE\n"
	.string "DE LA SEMAINE! Enchantée!\p"
	.string "Devine mon jour préféré et je te\n"
	.string "donnerai une récompense.$"

Route32_Text_FriedaGivesGift:
	.string "Voilà un PIC VENIN pour toi!$"

Route32_Text_FriedaGaveGift:
	.string "VANESSA: Donne-le\n"
	.string "à un Pokémon qui\p"
	.string "a des capacités\n"
	.string "du type POISON.\p"
	.string "Oh!\p"
	.string "C'est terrible!\p"
	.string "Tu verras à quel point ça peut\n"
	.string "les améliorer!$"

Route32_Text_FriedaFriday:
	.string "Vanessa: Ouais! Quel est le\n"
	.string "meilleur jour de la semaine?\p"
	.string "Moi j’aime le vendredi, hé oui!\p"
	.string "T’es pas d’accord?$"

Route32_Text_FriedaNope:
	.string "VANESSA: Pas celui-là!$"

Route32_Text_Sign1:
	.string "ROUTE 32\p"
	.string "MAUVILLE ECORCIA$"

Route32_Text_Sign2:
	.string "Ruines d’Alpha Entrée Est$"

Route32_Text_Sign3:
	.string "Direction Caves Jumelles$"
