OlivineCity_Gym_hns_MapScripts::
	.byte 0

OlivineCity_Gym_EventScript_Gent::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Gent2
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Gent2::
	msgbox OlivineCity_Gym_Text_Gent2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow1::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC1
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveLeft4
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveLeft3
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveLeft2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveLeft1
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveLeft0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox OlivineCity_Gym_Text_Gent, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 6
	release
	end

OlivineCity_Gym_EventScript_MoveLeft0::
	turnobject VAR_TEMP_0, DIR_WEST
	return

OlivineCity_Gym_EventScript_MoveLeft1::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft2::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft3::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveLeft4::
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkLeft1
	waitmovement 0
	return

OlivineCity_Gym_Text_Gent:
	.string "Te voilà!\p"
	.string "Tu as dissimulé ta force pour le\n"
	.string "Champion de l’Arène, mais il est\p"
	.string "temps de montrer ce que tu sais\n"
	.string "faire!\p"
	.string "Allez, éblouis-nous!$"

OlivineCity_Gym_Text_Gent2:
	.string "Brillant, brillant! Tu vas\n"
	.string "pouvoir te frotter à toutes les\p"
	.string "régions du monde!\p"
	.string "Puisque tu possèdes Surf, tu\n"
	.string "ferais bien d’aller faire\p"
	.string "un tour au Lac Colère.$"

OlivineCity_Gym_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Lass2
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Lass2::
	msgbox OlivineCity_Gym_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_TriggerRow2::
	lock
	setvar VAR_TEMP_0, LOCALID_OLIVINE_CITY_GYM_NPC2
	playse SE_PIN
	applymovement VAR_TEMP_0, Common_Movement_ExclamationMark
	waitmovement VAR_TEMP_0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 6, OlivineCity_Gym_EventScript_MoveRight0
	call_if_eq VAR_TEMP_1, 7, OlivineCity_Gym_EventScript_MoveRight1
	call_if_eq VAR_TEMP_1, 8, OlivineCity_Gym_EventScript_MoveRight2
	call_if_eq VAR_TEMP_1, 9, OlivineCity_Gym_EventScript_MoveRight3
	call_if_eq VAR_TEMP_1, 10, OlivineCity_Gym_EventScript_MoveRight4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox OlivineCity_Gym_Text_Lass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 7
	release
	end

OlivineCity_Gym_EventScript_MoveRight0::
	turnobject VAR_TEMP_0, DIR_EAST
	return

OlivineCity_Gym_EventScript_MoveRight1::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight2::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight3::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_EventScript_MoveRight4::
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	applymovement VAR_TEMP_0, Common_Movement_WalkRight1
	waitmovement 0
	return

OlivineCity_Gym_Text_Lass:
	.string "Tu m’avais montré ta puissance\n"
	.string "dans le phare déjà!\p"
	.string "Maintenant, tu vas te frotter à\n"
	.string "Jasmine!\p"
	.string "Je suis avec toi!!!$"

OlivineCity_Gym_Text_Lass2:
	.string "Incroyable!\p"
	.string "Avec tout ce potentiel, tu dois\n"
	.string "viser toujours plus haut!\p"
	.string "Est-ce que tu connais la ville\n"
	.string "d’Acajou?$"

OlivineCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineCity_Gym_EventScript_GymGuideSick
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_GymGuideAfter
	msgbox OlivineCity_Gym_Text_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideSick::
	msgbox OlivineCity_Gym_Text_GymGuidePreText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_GymGuideAfter::
	msgbox OlivineCity_Gym_Text_GymGuideWinText, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymGuideText:
	.string "JASMINE utilise le type ACIER,\n"
	.string "découvert récemment.\p"
	.string "Elle est connue pour avoir\n"
	.string "non pas un, mais deux atouts.\p"
	.string "Le premier est un insecte\n"
	.string "de métall"
	.string "qui peut augmenter son ATTAQUE.\p"
	.string "Le feu lui fait mal, mais\n"
	.string "il peut parfois encaisser\l"
	.string "de puissants coups.\p"
	.string "Le second est un serpent\n"
	.string "de fer géantl"
	.string "doté de capacités redoutables.\p"
	.string "Approche-le avec prudence.\p"
	.string "Il paraît lent, mais je l'ai\n"
	.string "déjà vul"
	.string "frapper le premier grâce à une\l"
	.string "VITESSE surprenante.$"

OlivineCity_Gym_Text_GymGuideWinText:
	.string "C'est très étrange\p"
	.string "le type ACIER, hein?\p"
	.string "C'est la rencontre d'un nouveau\n"
	.string "genre!$"

OlivineCity_Gym_Text_GymGuidePreText:
	.string "JASMINE, la CHAMPIONNE d'ARENE\n"
	.string "est au PHARE.\p"
	.string "Elle s'occupe du Pokémon malade.\p"
	.string "Un dresseur puissant\n"
	.string "doit avoir un\p"
	.string "coeur charitable et\n"
	.string "être bienveillant.$"

OlivineCity_Gym_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Jasmine_Defeated
	msgbox OlivineCity_Gym_Text_JasmineSteelTypeIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_CianwoodCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_MahogCheckCianwood
	goto OlivineCity_Gym_EventScript_Jasmine_Battle1

OlivineCity_Gym_EventScript_JasmineVictory::
	message OlivineCity_Gym_Text_ReceivedMineralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OlivineCity_Gym_Text_JasmineBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_IRON_TAIL
	msgbox OlivineCity_Gym_Text_JasmineIronTailSpeech, MSGBOX_DEFAULT
	setvar VAR_OLIVINE_CITY_STATE, 8
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

OlivineCity_Gym_EventScript_CianwoodCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2

OlivineCity_Gym_EventScript_MahogCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, OlivineCity_Gym_EventScript_Jasmine_Battle3
	goto OlivineCity_Gym_EventScript_Jasmine_Battle2
	
OlivineCity_Gym_EventScript_Jasmine_Battle1::
	trainerbattle_no_intro TRAINER_JASMINE_1_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle2::
	trainerbattle_no_intro TRAINER_JASMINE_1_2_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Battle3::
	trainerbattle_no_intro TRAINER_JASMINE_1_3_HNS, OlivineCity_Gym_Text_JasmineBetterTrainer
	goto OlivineCity_Gym_EventScript_JasmineVictory

OlivineCity_Gym_EventScript_Jasmine_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_JASMINE, OlivineCity_Gym_EventScript_Jasmine_Trade
	msgbox OlivineCity_Gym_Text_JasmineGoodLuck, MSGBOX_DEFAULT
	closemessage
	release
	end


OlivineCity_Gym_Text_JasmineSteelTypeIntro:
	.string "...Merci pour ton aide au\n"
	.string "PHARE...\p"
	.string "Mais c'est un peu différent.\p"
	.string "Permets-moi de me présenter.\p"
	.string "Je suis JASMINE la\n"
	.string "CHAMPIONNE d'ARENE\p"
	.string "et j'utilise les\n"
	.string "Pokémon de type ACIER.\p"
	.string "...Ca te dit quelque chose le\n"
	.string "type ACIER?\p"
	.string "C'est un tout nouveau type de\n"
	.string "Pokémon.\p"
	.string "Hum...? Je peux commencer?$"

OlivineCity_Gym_Text_JasmineBetterTrainer:
	.string "...Bon bah t'es meilleur\n"
	.string "dresseur\p"
	.string "que moi, en compétence et en\n"
	.string "gentillesse.\p"
	.string "En accord avec les règles de la\p"
	.string "LIGUE, je te confie ce BADGE.$"

OlivineCity_Gym_Text_ReceivedMineralBadge:
	.string "{PLAYER} reçoit le BADGEMINERAL.$"

OlivineCity_Gym_Text_JasmineBadgeSpeech:
	.string "Le BADGE MINERAL augmente la\n"
	.string "DÉFENSE SPÉCIALE des Pokémon.\p"
	.string "...Euh... Prends aussi ceci...$"

OlivineCity_Gym_Text_JasmineIronTailSpeech:
	.string "Tu peux utiliser\n"
	.string "cette CT pour\p"
	.string "apprendre QUEUE DE\n"
	.string "FER à un Pokémon.$"

OlivineCity_Gym_Text_JasmineGoodLuck:
	.string "Hum... Je ne sais comment\n"
	.string "dire... Mais bonne chance!$"

OlivineCity_Gym_Text_JasmineRematchText:
	.string "...Félicitations,\n"
	.string "Maître de JOHTO.\p"
	.string "Tu es devenu si fort...\p"
	.string "Je me demande si j'ai progressé.\p"
	.string "Voudrais-tu le vérifier?\p"
	.string "Acceptes-tu une revanche?$"

OlivineCity_Gym_Text_JasmineRematchDefeatText:
	.string "...Tu es meilleur Dresseur\n"
	.string "que moi,l"
	.string "par ton talent comme ta bonté.$"

OlivineCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, OlivineCity_Gym_EventScript_Statue2
	msgbox OlivineCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_EventScript_Statue2::
	msgbox OlivineCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Gym_Text_GymStatue:
	.string "Arène d’Oliville$"

OlivineCity_Gym_Text_GymStatueCertified:
	.string "ARENE Pokémon D'OLIVILLE\p"
	.string "DRESSEURS CERTIFIÉS PAR JASMINE:\n"
	.string "{PLAYER}$"

OlivineCity_Gym_EventScript_Jasmine_Trade::
	goto_if_set FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED, OlivineCity_Gym_EventScript_JasmineTradeCompleted
	setvar VAR_0x8005, INGAME_TRADE_STEELIX
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox OlivineCity_Gym_Text_JasmineWantToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OlivineCity_Gym_EventScript_JasmineDeclineTrade
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox OlivineCity_Gym_Text_JasmineTakeCare, MSGBOX_DEFAULT
	setflag FLAG_OLIVINE_GYM_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_Gym_EventScript_JasmineDeclineTrade::
	msgbox OlivineCity_Gym_Text_JasmineDeclineTrade, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_EventScript_JasmineTradeCompleted::
	msgbox OlivineCity_Gym_Text_JasmineTradeCompleted, MSGBOX_DEFAULT
	release
	end

OlivineCity_Gym_Text_JasmineWantToTrade:
	.string "...Euh, {PLAYER}...\n"
	.string "J'ai quelque chose\n"
	.string "à te demander.\p"
	.string "J'élève ce STEELIX depuis qu'il\n"
	.string "n'était qu'un petit ONIX.\p"
	.string "Mais je crois que MÉTALLO serait\n"
	.string "plus heureux avec toi.\p"
	.string "Échangerais-tu l'un de\n"
	.string "tes Pokémon contre MÉTALLO?$"

OlivineCity_Gym_Text_JasmineTakeCare:
	.string "...Merci.\n"
	.string "Prends bien soin de MÉTALLO...$"

OlivineCity_Gym_Text_JasmineDeclineTrade:
	.string "...Oh... Ce n'est pas grave.\n"
	.string "Je comprends...$"

OlivineCity_Gym_Text_JasmineTradeCompleted:
	.string "...Comment va MÉTALLO?\n"
	.string "J'espère que tu en prends\n"
	.string "bien soin...$"
