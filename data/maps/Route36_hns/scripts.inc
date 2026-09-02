Route36_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK_HNS, Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN_HNS, Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten, Route36_EventScript_RegisterAlan
	goto_if_set FLAG_ALAN_HAS_ITEM_HNS, Route36_EventScript_AlanGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RematchAlan
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_RegisterAlan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route36_Text_AlanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALAN_HNS
	release
	end

Route36_EventScript_RematchAlan::
	trainerbattle_rematch TRAINER_ALAN_HNS, Route36_Text_AlanRematchIntro, Route36_Text_AlanRematchDefeat
	msgbox Route36_Text_AlanPostRematch, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanGiveItem::
	msgbox Route36_Text_AlanHasItem, MSGBOX_DEFAULT
	giveitem VAR_ALAN_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route36_EventScript_AlanNoRoom
	clearflag FLAG_ALAN_HAS_ITEM_HNS
	msgbox Route36_Text_AlanGaveItem, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanNoRoom::
	msgbox Route36_Text_AlanNoRoom, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "Utiliser la CARAPUCE À O?$"

Route36_Text_UsedSquirtbottle:
	.string "{PLAYER} utilise la CARAPUCE A\n"
	.string "O.$"

Route36_Text_SudowoodoAttacked:
	.string "L'arbre bizarre n'aime pas la\n"
	.string "CARAPUCE A O!\p"
	.string "L'arbre bizarre attaque!$"

Route36_Text_RockSmashGuy1:
	.string "Yaaatah!\p"
	.string "J'allais éclater cet arbre avec\n"
	.string "mon poing du dragon!\p"
	.string "Mais j'y arrive pas! J'suis nul!$"

Route36_Text_RockSmashGuy2:
	.string "Tu as battu l'arbre?\p"
	.string "Impressionnant! Tu as bien\n"
	.string "mérité ça.$"

Route36_Text_RockSmashGuy3:
	.string "C'est le terrible ECLATE-ROC.\p"
	.string "Tu peux éclater des rochers d'un\n"
	.string "seul coup!\p"
	.string "Si un rocher te bloque la route,\n"
	.string "éclate-le!$"

Route36_Text_OddTree:
	.string "Un drôle d'arbre bloque\n"
	.string "le passage.$"

Route36_Text_Lass1:
	.string "Sois prudent la nuit sur\n"
	.string "cette route!\p"
	.string "J'ai vu un Pokémon qui\n"
	.string "ressemblait à CANINOS, mais\l"
	.string "son aura était\l"
	.string "terrifiante.$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "L'arbre bizarre a disparu...\p"
	.string "Oh! C'était un Pokémon?\n"
	.string "Vraiment?$"

Route36_Text_PsychicMarkSeen:
	.string "Je suis... Puissant!$"

Route36_Text_PsychicMarkBeaten:
	.string "J'suis une tache!$"

Route36_Text_PsychicMarkAfter:
	.string "J'ai des pouvoirs psychiques\n"
	.string "mais...\p"
	.string "Je sais pas comment m'en servir.$"

Route36_Text_SchoolboyAlan1Seen:
	.string "J'ai étudié et je suis\n"
	.string "incollable! A l'attaque!$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "Oups! Me serais-je trompé?$"

Route36_Text_SchoolboyAlanAfter:
	.string "Pfff. J'étudie 5 heures par\n"
	.string "jour.\p"
	.string "Lire des livres ça suffit pas...\n"
	.string "Apparemment...$"

Route36_Text_MeetArthur:
	.string "JEROME: Qui es-tu?\n"
	.string "Moi, c'est JEROME de la fratrie\l"
	.string "des jours de la semaine.\p"
	.string "Devine mon jour préféré et je te\n"
	.string "donnerai une récompense.$"

Route36_Text_ArthurNope:
	.string "Ce n'est pas ça!$"

Route36_Text_ArthurGivesGift:
	.string "Tiens. Voilà pour toi.$"

Route36_Text_ArthurGaveGift:
	.string "JEROME: C'est pour un Pokémon\n"
	.string "avec\p"
	.string "des capacités du type ROCHE.\p"
	.string "Cela va améliorer ses attaques.$"

Route36_Text_ArthurThursday:
	.string "JEROME: Moi, c'est JEROME\n"
	.string "du jeudi,\l"
	.string "le cinquième des sept enfants.$"

Route36_Text_Sign:
	.string "ROUTE 36$"

Route36_Text_Sign_RuinsNorth:
	.string "Ruines d’Alpha Entrée Nord$"

Route36_Text_Tips1:
	.string "ASTUCE\p"
	.string "Les statistiques\n"
	.string "des Pokémon\p"
	.string "varient, même dans\n"
	.string "la même espèce.\p"
	.string "Et même si au début deux Pokémon\n"
	.string "se ressemblent...\p"
	.string "En grandissant ils n'auront pas\n"
	.string "les\p"
	.string "mêmes forces et faiblesses.$"

Route36_Text_Tips2:
	.string "ASTUCE\p"
	.string "Utiliser TUNNEL pour retourner\n"
	.string "au début d'un lieu.\p"
	.string "C'est très pratique pour\n"
	.string "explorer\p"
	.string "les grottes et les cavernes.$"

Route36_Text_AlanRegister:
	.string "Pfff. J'étudie 5 heures par\n"
	.string "jour.\p"
	.string "Lire des livres ça suffit pas...\n"
	.string "Apparemment...$"

Route36_Text_AlanRematchIntro:
	.string "J'ai étudié et je suis\n"
	.string "incollable! A l'attaque!$"

Route36_Text_AlanRematchDefeat:
	.string "Oups! Me serais-je trompé?$"

Route36_Text_AlanPostRematch:
	.string "Pfff. J'étudie 5 heures par\n"
	.string "jour.\p"
	.string "Lire des livres ça suffit pas...\n"
	.string "Apparemment...$"

Route36_Text_AlanHasItem:
	.string "Hé! J'ai trouvé quelque chose\n"
	.string "en étudiant!\p"
	.string "Tiens, c'est pour toi!$"

Route36_Text_AlanGaveItem:
	.string "Je te préviendrai si je trouve\n"
	.string "autre chose!$"

Route36_Text_AlanNoRoom:
	.string "Hmm, ton SAC est plein.\p"
	.string "Reviens quand tu auras\n"
	.string "de la place.$"
