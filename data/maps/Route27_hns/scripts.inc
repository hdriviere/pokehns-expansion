Route27_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	setspeaker Route27_Text_BaobaName
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_Text_BaobaName:
	.string "Baoba$"

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    setflag FLAG_VISITED_KANTO
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
    
    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_DragonClaw::
    finditem ITEM_TM_DRAGON_CLAW
    end

Route27_EventScript_Item_Destiny_Knot::
    finditem ITEM_DESTINY_KNOT
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE_HNS, Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN_HNS, Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA_HNS, Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten, Route27_EventScript_RegisterReena
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchReena
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterReena::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_ReenaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_REENA_HNS
	release
	end

Route27_EventScript_RematchReena::
	trainerbattle_rematch TRAINER_REENA_HNS, Route27_Text_ReenaRematchIntro, Route27_Text_ReenaRematchDefeat
	msgbox Route27_Text_ReenaPostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN_HNS, Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT_HNS, Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE_HNS, Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten, Route27_EventScript_RegisterJose
	goto_if_set FLAG_JOSE_HAS_ITEM_HNS, Route27_EventScript_JoseGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route27_EventScript_RematchJose
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_RegisterJose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route27_Text_JoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOSE_HNS
	release
	end

Route27_EventScript_RematchJose::
	trainerbattle_rematch TRAINER_JOSE_HNS, Route27_Text_JoseRematchIntro, Route27_Text_JoseRematchDefeat
	msgbox Route27_Text_JosePostRematch, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseGiveItem::
	msgbox Route27_Text_JoseHasItem, MSGBOX_DEFAULT
	giveitem VAR_JOSE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route27_EventScript_JoseNoRoom
	clearflag FLAG_JOSE_HAS_ITEM_HNS
	msgbox Route27_Text_JoseGaveItem, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JoseNoRoom::
	msgbox Route27_Text_JoseNoRoom, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT_HNS, Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
    .string "Hé!$"

Route27_Text_FisherMessage:
    .string "Tu sais ce que tu viens de\n"
    .string "faire?\p"
    .string "Tu viens de faire ton premier\n"
    .string "pas à Kanto!\p"
    .string "Regarde la carte de ton\n"
    .string "Pokématos!$"

Route27_Text_CooltrainermBlakeSeen:
    .string "Quelle force se dégage de toi!\n"
    .string "Je te prie d’accepter ce défi!$"

Route27_Text_CooltrainermBlakeBeaten:
    .string "Huf!$"

Route27_Text_CooltrainermBlakeAfter:
    .string "La compréhension vient à force\n"
    .string "d’arpenter le chemin.\p"
    .string "Ne fais pas\n"
    .string "attention,\p"
    .string "j’essayais juste\n"
    .string "d’être philosophe.$"

Route27_Text_CooltrainermBrianSeen:
    .string "Hum... Tu es de taille!$"

Route27_Text_CooltrainermBrianBeaten:
    .string "Comme je le pensais!$"

Route27_Text_CooltrainermBrianAfter:
    .string "Les meilleurs savent se\n"
    .string "reconnaître entre eux!$"

Route27_Text_CooltrainerfReenaSeen:
    .string "Tu devrais faire attention aux\p"
    .string "Pokémon sauvages du coin.$"

Route27_Text_CooltrainerfReenaBeaten:
    .string "Oh! Quelle force!$"

Route27_Text_CooltrainerfReenaAfter:
    .string "T'es jeune, mais...\p"
    .string "T'es balèze! Oh que oui!$"

Route27_Text_ReenaRegister:
    .string "T'es jeune, mais...\p"
    .string "T'es balèze! Oh que oui!$"

Route27_Text_ReenaRematchIntro:
    .string "Tu devrais faire attention aux\p"
    .string "Pokémon sauvages du coin.$"

Route27_Text_ReenaRematchDefeat:
    .string "Oh! Quelle force!$"

Route27_Text_ReenaPostRematch:
    .string "T'es jeune, mais...\p"
    .string "T'es balèze! Oh que oui!$"

Route27_Text_CooltrainerfMeganSeen:
    .string "C'est rare de voir quelqu'un\n"
    .string "ici.\p"
    .string "Tu t'entraînes en solitaire?$"

Route27_Text_CooltrainerfMeganBeaten:
    .string "Ben ça alors!$"

Route27_Text_CooltrainerfMeganAfter:
    .string "Moi j'étudie les\n"
    .string "formes antérieures\p"
    .string "et postérieures aux\n"
    .string "évolutions des Pokémon.\p"
    .string "Un Pokémon évolué est toujours\n"
    .string "plus fort.\p"
    .string "Mais il apprend des capacités\n"
    .string "plus tardivement.$"

Route27_Text_PsychicGilbertSeen:
    .string "Ne dis rien! Je vais lire dans\n"
    .string "tes pensées...\p"
    .string "Hmmmmmm...\p"
    .string "Je sais! Tu veux te mesurer à la\n"
    .string "Ligue!$"

Route27_Text_PsychicGilbertBeaten:
    .string "Je le savais!$"

Route27_Text_PsychicGilbertAfter:
    .string "Tu vas cartonner à la LIGUE...\n"
    .string "C'est sûr!\p"
    .string "Je le sais. Je le sens.$"

Route27_Text_BirdKeeperJoseSeen:
    .string "Piou! Piou! Piouuu!$"

Route27_Text_BirdKeeperJoseBeaten:
    .string "Piou!$"

Route27_Text_BirdKeeperJoseAfter:
    .string "Nous autres Ornithologues\n"
    .string "utilisons un sifflet\p"
    .string "pour imiter le\n"
    .string "cri des Pokémon et\p"
    .string "leur donner des ordres.$"

Route27_Text_JoseRegister:
    .string "Nous autres Ornithologues\n"
    .string "utilisons un sifflet\p"
    .string "pour imiter le\n"
    .string "cri des Pokémon et\p"
    .string "leur donner des ordres.$"

Route27_Text_JoseRematchIntro:
    .string "Piou! Piou! Piouuu!$"

Route27_Text_JoseRematchDefeat:
    .string "Piou!$"

Route27_Text_JosePostRematch:
    .string "Nous autres Ornithologues\n"
    .string "utilisons un sifflet\p"
    .string "pour imiter le\n"
    .string "cri des Pokémon et\p"
    .string "leur donner des ordres.$"

Route27_Text_JoseHasItem:
    .string "Hé! J'ai trouvé un objet\n"
    .string "brillant en observant les\l"
    .string "oiseaux!\p"
    .string "Tiens, il est pour toi!$"

Route27_Text_JoseGaveItem:
    .string "Je trouve toutes sortes de\n"
    .string "choses ici, sur la ROUTE 27.\p"
    .string "Je te préviendrai si je trouve\n"
    .string "autre chose!$"

Route27_Text_JoseNoRoom:
    .string "Hmm, ton SAC est plein.\p"
    .string "Reviens quand tu auras de la\n"
    .string "place.$"

TohjoFalls_Text_Sign:
    .string "Chutes Tohjo La frontière entre\n"
    .string "Kanto et Johto$"

Route27_Text_FisherScottSeen:
    .string "Moi j'suis en pleine forme!\p"
    .string "J'me sens capable de battre\n"
    .string "l'MAITRE de la LIGUE!$"

Route27_Text_FisherScottBeaten:
    .string "Allons bon... C’est pas mon\n"
    .string "jour...$"

Route27_Text_FisherScottAfter:
    .string "Comme pour la\n"
    .string "pêche, faut jamais\p"
    .string "abandonner au\n"
    .string "milieu d’un combat!$"
