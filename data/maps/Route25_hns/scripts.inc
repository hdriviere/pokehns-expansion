Route25_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route25_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, Route25_EventScript_SetSuicuneSceneMid
	end

Route25_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_ROUTE25_EUSINE, 98, 14
	end

Route25_EventScript_MistyRematch::
    lock
    faceplayer
    msgbox Route25_Text_Misty, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CAPE_MISTY
    removeobject LOCALID_CAPE_MISTY
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_MISTY
    release
    end

Route25_Text_Misty:
	.string "ONDINE: J'adore le coucher de\n"
	.string "soleil ici!\p"
	.string "Il me donne le courage de\n"
	.string "continuer, tu sais?\p"
	.string "Bien!\p"
	.string "Si tu veux faire des vagues,\n"
	.string "retrouve-moi au DOJO de COMBAT!$"

Route25_EventScript_Dudley::
	trainerbattle_single TRAINER_DUDLEY_HNS, Route25_Text_SchoolboyDudleySeen, Route25_Text_SchoolboyDudleyBeaten
	msgbox Route25_Text_SchoolboyDudleyAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Ellen::
	trainerbattle_single TRAINER_ELLEN_HNS, Route25_Text_LassEllenSeen, Route25_Text_LassEllenBeaten
	msgbox Route25_Text_LassEllenAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joe::
	trainerbattle_single TRAINER_JOE_HNS, Route25_Text_SchoolboyJoeSeen, Route25_Text_SchoolboyJoeBeaten
	msgbox Route25_Text_SchoolboyJoeAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA_HNS, Route25_Text_LassLauraSeen, Route25_Text_LassLauraBeaten
	msgbox Route25_Text_LassLauraAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD_HNS, Route25_Text_CamperLloydSeen, Route25_Text_CamperLloydBeaten
	msgbox Route25_Text_CamperLloydAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON_HNS, Route25_Text_LassShannonSeen, Route25_Text_LassShannonBeaten
	msgbox Route25_Text_LassShannonAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Pat::
	trainerbattle_single TRAINER_PAT_HNS, Route25_Text_SupernerdPatSeen, Route25_Text_SupernerdPatBeaten
	msgbox Route25_Text_SupernerdPatAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kevin::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE25_GOT_NUGGET, Route25_EventScript_KevinAfter
	msgbox Route25_Text_CooltrainerKevinNugget, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE25_GOT_NUGGET
	msgbox Route25_Text_CooltrainerKevinSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KEVIN_HNS, Route25_Text_CooltrainerKevinBeaten
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_KevinAfter::
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_NPC
	end

Route25_EventScript_BillsHouseSign::
	msgbox Route25_Text_BillsHouseSign, MSGBOX_SIGN
	end

Route25_Trigger_MistyRight::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE25_MAN
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveRight
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route25_EventScript_Misty
Route25_Trigger_MistyLeft::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ROUTE25_MAN
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveLeft
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route25_EventScript_Misty
Route25_EventScript_Misty::
	msgbox Route25_Text_MistyDate, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_MISTY
	removeobject LOCALID_ROUTE25_MAN
	setflag FLAG_HIDE_ROUTE25_MISTY
	clearflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	setflag FLAG_HIDE_CERULEAN_GYM_POKEMON
	setvar VAR_CERULEAN_CITY_STATE, 3
	release
	end

Route25_Trigger_SuicuneLeft::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_Trigger_SuicuneRight::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_EventScript_SuicuneMerge::
	clearflag FLAG_HIDE_ROUTE25_EUSINE
	addobject LOCALID_ROUTE25_EUSINE
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route25_Text_Eusine1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineSide
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Route25_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SUICUNE_ENCOUNTERS, 7
	release
	end
	
Route25_Trigger_SuicuneRightRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	goto Route25_Trigger_SuicuneRight
Route25_Trigger_SuicuneLeftLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto Route25_Trigger_SuicuneLeft

Route25_Text_Eusine1:
	.string "Eusine: Haa... Haa... Je n’ai\n"
	.string "donc pas réussi...\p"
	.string "à te battre...\p"
	.string "... ... Fais pas cette tête, pas\n"
	.string "grave...\p"
	.string "Depuis notre première\n"
	.string "rencontre dans\p"
	.string "la Tour Cendrée\n"
	.string "de Rosalia, j’ai\p"
	.string "toujours su qu’au final, ce\n"
	.string "serait toi\p"
	.string "que SUICUNE choisirait.$"

Route25_Text_Eusine2:
	.string "Regarde-le!\p"
	.string "SUICUNE t'attend!\n"
	.string "Il attendait de combattre un\l"
	.string "Dresseur digne de sa confiance.$"

Route25_Text_Eusine3:
	.string "Eusine: {PLAYER}... C’était\n"
	.string "incroyable...\p"
	.string "Après avoir vu un tel combat, je\n"
	.string "n’ai plus aucun regret...\p"
	.string "Adieu, SUICUNE! Adieu...\n"
	.string "{PLAYER}!$"

Route25_EventScript_Eusine::
	msgbox Route25_Text_Eusine2, MSGBOX_NPC
	end

Route25_EventScript_Suicune::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route25_EventScript_SuicuneRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE25_SUICUNE
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 8, Route25_EventScript_SuicunePostGame
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 99, Route25_AdjustPlayer
	call_if_eq VAR_TEMP_0, 100, Route25_AdjustPlayerTwice
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_ROUTE25_EUSINE, DIR_NORTH
	msgbox Route25_Text_Eusine3, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_EUSINE
	setflag FLAG_HIDE_ROUTE25_EUSINE
	clearflag FLAG_HIDE_CELADON_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 8
	release
	end

Route25_EventScript_SuicuneRan::
	release
	end

Route25_AdjustPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_AdjustPlayerTwice::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_EventScript_SuicunePostGame::
	release
	end

Route25_Movement_EusineLeave:
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_Movement_EusineSide:
	walk_slow_left
	walk_slow_up
	step_end

Route25_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_slow_up
	step_end

Route25_Movement_Suicune1:
	jump_in_place_down
	step_end

Route25_Movement_WalkToSuicune:
	walk_up
	walk_up
	step_end

Route25_Movement_MistyLeave:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_ManLeaveRight:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route25_Movement_ManLeaveLeft:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route25_Movement_MistyWalkToPlayerRight:
	walk_fast_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
Route25_Movement_MistyWalkToPlayerLeft:
	walk_fast_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Route25_Text_MistyDate:
	.string "Ondine: Aaaah! Pourquoi t’es là,\n"
	.string "toi?\p"
	.string "Tu nous as dérangés!\p"
	.string "Alors laisse-moi\n"
	.string "te dire une chose!\p"
	.string "Les gens comme\n"
	.string "toi, c’est bon qu’à\p"
	.string "gâcher l’ambiance pour les\n"
	.string "autres!\p"
	.string "...\p"
	.string "... Oh? Tes Badges! Ils viennent\n"
	.string "des Arènes de Johto?\p"
	.string "Si tu en as 8, c’est que t’es\n"
	.string "pas une mauviette...\p"
	.string "OK. Viens à l’Arène d’Azuria. Je\n"
	.string "t’attends!\p"
	.string "Je suis Ondine, le Champion\n"
	.string "d’Azuria!$"

Route25_Text_SchoolboyDudleySeen:
	.string "Bats les six dresseurs pour\n"
	.string "gagner un prix!\p"
	.string "Tu crois en être capable?$"

Route25_Text_SchoolboyDudleyBeaten:
	.string "Whoa! Balèze.$"

Route25_Text_SchoolboyDudleyAfter:
	.string "J'ai fait de mon mieux.$"

Route25_Text_LassEllenSeen:
	.string "J'suis en deuz. Ca va barder!$"

Route25_Text_LassEllenBeaten:
	.string "Impossible!$"

Route25_Text_LassEllenAfter:
	.string "J'ai fait de mon mieux.$"

Route25_Text_SchoolboyJoeSeen:
	.string "Numéro 3! Tu vas en baver!$"

Route25_Text_SchoolboyJoeBeaten:
	.string "Ouille! Perdu!$"

Route25_Text_SchoolboyJoeAfter:
	.string "J'ai fait de mon mieux.$"

Route25_Text_LassLauraSeen:
	.string "Numéro 4! Tu tiens le coup?$"

Route25_Text_LassLauraBeaten:
	.string "Perdu? Moi aussi?$"

Route25_Text_LassLauraAfter:
	.string "J'ai fait de mon mieux.$"

Route25_Text_CamperLloydSeen:
	.string "OK! Numéro 5. COMBAAAAT!$"

Route25_Text_CamperLloydBeaten:
	.string "Whoa! Trop fort.$"

Route25_Text_CamperLloydAfter:
	.string "J'ai fait de mon mieux.$"

Route25_Text_LassShannonSeen:
	.string "Dernier rempart! Autant te le\n"
	.string "dire... Ça va être dur!$"

Route25_Text_LassShannonBeaten:
	.string "Sans blague?$"

Route25_Text_LassShannonAfter:
	.string "J'ai fait de mon mieux.$"

Route25_Text_SupernerdPatSeen:
	.string "Hin hin hin...\p"
	.string "Je n’ai aucun rapport avec les 6\n"
	.string "autres Dresseurs.\p"
	.string "Je suis juste là\n"
	.string "pour te battre au\p"
	.string "moment où tu es\n"
	.string "le plus à plat.$"

Route25_Text_SupernerdPatBeaten:
	.string "C’est pas vrai! T’es jamais à\n"
	.string "plat, toi?$"

Route25_Text_SupernerdPatAfter:
	.string "Pardon. Je ne tricherai plus...$"

Route25_Text_CooltrainerKevinNugget:
	.string "Tu as livré un\n"
	.string "combat de plus\p"
	.string "que prévu et tu as\n"
	.string "quand même gagné.\p"
	.string "Tu mérites bien ton prix!$"

Route25_Text_CooltrainerKevinSeen:
	.string "Mais après avoir vu ton combat,\n"
	.string "je\p"
	.string "voudrais tenter ma chance.\p"
	.string "Ca te dit? Alors c'est parti.$"

Route25_Text_CooltrainerKevinBeaten:
	.string "C’est la première fois que je\n"
	.string "fais un si beau combat!$"

Route25_Text_CooltrainerKevinAfter:
	.string "Quelle belle rencontre!\p"
	.string "Toi et ton équipe de Pokémon\n"
	.string "êtes vraiment impressionnants!$"

Route25_Text_BillsHouseSign:
	.string "Villa du Cap Chez Léo$"
