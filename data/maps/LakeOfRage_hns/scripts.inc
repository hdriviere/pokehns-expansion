LakeOfRage_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE_HNS
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_HNS
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
	.string "{PLAYER}.\p"
	.string "Même ici, le froid garde\n"
	.string "mes sens aiguisés.\p"
	.string "Si tu souhaites me réaffronter,\n"
	.string "viens au DOJO.$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE_HNS, LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND_HNS, LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON_HNS, LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS_HNS, LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Secret_Power::
    finditem ITEM_TM_SECRET_POWER
    end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "DRACOLOSSE: Drrrrrrra!$"

LakeOfRage_Text_LanceForcedToEvolve:
    .string "Ce LAC est rempli de LEVIATOR et\n"
    .string "rien d'autre...\p"
    .string "Les MAGICARPE ont été forcés\n"
    .string "d'évoluer...$"

LakeOfRage_Text_LanceIntro1:
	.string "Tu es venu à cause des rumeurs?\p"
	.string "Tu es {PLAYER}?\n"
	.string "Moi, c'est PETER,l"
	.string "un Dresseur comme toi.$"

LakeOfRage_Text_LanceIntro2:
	.string "Cet homme m'a parlé de certaines\n"
	.string "rumeurs.\p"
	.string "Nous sommes venus enquêter...$"

LakeOfRage_Text_LanceIntro3:
	.string "J'ai vu ton combat tout\n"
	.string "à l'heure,l"
	.string "{PLAYER}.\p"
	.string "Tu es un Dresseur\n"
	.string "très talentueux.\p"
	.string "Si cela ne te dérange pas,\n"
	.string "peux-tu nous aider à enquêter?$"

LakeOfRage_Text_LanceRadioSignal:
    .string "PETER: Excellent!\p"
    .string "On dirait que\n"
    .string "quelque chose force\p"
    .string "les MAGICARPE du\n"
    .string "LAC à évoluer.\p"
    .string "Un mystérieux signal radio vient\n"
    .string "d'ACAJOU.\p"
    .string "Je t'y attendrai, {PLAYER}.$"

LakeOfRage_Text_LanceRefused:
    .string "Oh... Bon, si tu changes d'avis,\n"
    .string "tu pourras m'aider.$"

LakeOfRage_Text_LanceAskHelp:
	.string "PETER: Hum? Tu vas nous aider?$"

LakeOfRage_Text_GyaradosCry:
    .string "LEVIATOR: Tttooor!$"

LakeOfRage_Text_Gramps:
    .string "Les LEVIATOR sont en colère!\p"
    .string "Mauvais présage!$"

LakeOfRage_Text_GrampsCleared:
    .string "Haha! Les MAGICARPE mordent!$"

LakeOfRage_Text_SuperNerd:
    .string "On dit que ce lac a été créé par\n"
    .string "le déchaînement de LEVIATOR.\p"
    .string "Je me demande s’il y a un lien\n"
    .string "avec les récents événements...$"

LakeOfRage_Text_CooltrainerF:
    .string "J'ai la berlue ou quoi? J'ai vu\n"
    .string "un LEVIATOR rouge dans le LAC...\p"
    .string "Je croyais qu'il n'y avait que\n"
    .string "des LEVIATOR bleus?$"


LakeOfRage_Text_FisherAndreSeen:
    .string "Je vais te combattre avec le\n"
    .string "Pokémon que je viens d’attraper!$"

LakeOfRage_Text_FisherAndreBeaten:
    .string "J’suis peut-être un bon Pêcheur,\n"
    .string "mais j’suis un mauvais Dresseur.$"

LakeOfRage_Text_FisherAndreAfter:
    .string "J’suis un bon\n"
    .string "Pêcheur, moi.\p"
    .string "J’attrape des Pokémon\n"
    .string "toute la journée!$"


LakeOfRage_Text_FisherRaymondSeen:
    .string "Quoi que je fasse, j’attrape\n"
    .string "toujours le même Pokémon...$"

LakeOfRage_Text_FisherRaymondBeaten:
    .string "Ma ligne est tout emmêlée...$"

LakeOfRage_Text_FisherRaymondAfter:
    .string "Pourquoi je ne peux pas attraper\n"
    .string "de bons Pokémon?$"

LakeOfRage_Text_CooltrainermAaronSeen:
    .string "Si un dresseur éclabousse un\p"
    .string "autre dresseur, ça fini en duel.\p"
    .string "C'est la loi.$"

LakeOfRage_Text_CooltrainermAaronBeaten:
    .string "Whaa... Bon combat!$"

LakeOfRage_Text_CooltrainermAaronAfter:
    .string "Les Pokémon et leur dresseur\p"
    .string "deviennent forts en combattant\n"
    .string "régulièrement.$"

LakeOfRage_Text_CooltrainerfLoisSeen:
    .string "Qu'est-il arrivé au LEVIATOR\n"
    .string "rouge?\p"
    .string "Il est parti?\p"
    .string "Oh, zut! Je suis venue pour\n"
    .string "rien?\p"
    .string "Bon... COMBAT!$"

LakeOfRage_Text_CooltrainerfLoisBeaten:
    .string "Pas mal!$"

LakeOfRage_Text_CooltrainerfLoisAfter:
    .string "Au fait... J'ai vu un PAPILUSION\n"
    .string "rose.$"



LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
	.string "HOMER: Eh bien, bonjour!\p"
	.string "Je fais partie de la fratrie\n"
	.string "des jours de la semaine!\p"
	.string "Devine mon jour préféré!$"

LakeOfRage_Text_WesleyGivesGift:
    .string "Enchanté de faire ta\n"
    .string "connaissance. V'là un souvenir.$"

LakeOfRage_Text_WesleyGaveGift:
    .string "HOMER: La CEINT.\n"
    .string "NOIRE renforce\p"
    .string "le pouvoir des\n"
    .string "capacités de COMBAT.$"

LakeOfRage_Text_WesleyWednesday:
    .string "Homer: Avant de m’avoir trouvé,\n"
    .string "t’as dû rencontrer mes frères et\p"
    .string "sœurs.\p"
    .string "Ou alors t’es en veine?$"

LakeOfRage_Text_WesleyNotWednesday:
	.string "HOMER: Pas exactement...$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
    .string "LAC COLERE, aussi connu sous le\n"
    .string "nom de LAC LEVIATOR.$"

LakeOfRage_Text_FishingGuruSign:
    .string "Maison du Maître Pêcheur$"
