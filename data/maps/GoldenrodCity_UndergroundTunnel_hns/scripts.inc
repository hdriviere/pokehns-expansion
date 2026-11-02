GoldenrodCity_UndergroundTunnel_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end
	
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	releaseall
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
	.string "Ces membres de la\n"
	.string "Team Rocket tout\p"
	.string "de noir vêtus vont\n"
	.string "et viennent depuis\p"
	.string "tout à l’heure complètement\n"
	.string "affolés...\p"
	.string "Je me demandais\n"
	.string "justement ce qui leur\p"
	.string "prenait... Ça veut\n"
	.string "dire que tu les as...\p"
	.string "Ha! Quelle force tu as!\p"
	.string "Tu serais peut-être\n"
	.string "même capable de\p"
	.string "faire venir le\n"
	.string "légendaire Po...$"

GoldenrodCity_UndergroundTunnel_Text_Kimono2:
	.string "Ohohoho! Ce n’est rien!\p"
	.string "Bien, je dois m’éclipser à\n"
	.string "présent.$"

GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC_HNS, GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU_HNS, GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC_HNS, GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD_HNS, GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother2
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
    .string "Bienvenue au SALON Pokémon!\p"
    .string "Je suis le cadet et le moins\n"
    .string "cher des FRERES COIFFEURS.\p"
    .string "J'peux\n"
    .string "m'occuper de\p"
    .string "tes Pokémon pour\n"
    .string "300¥.\p"
    .string "Alors? Ca te dit oui ou non?$"

GoldenrodUnderground_Text_YoungerBrotherAskWhich:
    .string "De quel Pokémon je m'occupe?$"

GoldenrodUnderground_Text_YoungerBrotherLookCool:
    .string "OK! Y va être trop cool!$"

GoldenrodUnderground_Text_YoungerBrotherAllDone:
    .string "Et voilà! Fini!$"

GoldenrodUnderground_Text_YoungerBrotherDisappointed:
    .string "Vraiment? Quel dommage!$"

GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
    .string "Tu n’as pas assez d’argent...$"

GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
    .string "Je ne fais qu'un toilettage par\n"
    .string "jour. Au revoir.$"



GoldenrodUnderground_Text_OlderBrotherOffer:
    .string "Bienvenue! Je\p"
    .string "m'occupe du SALON Pokémon!\p"
    .string "Je suis l'aîné et le meilleur\n"
    .string "des FRERES COIFFEURS.\p"
    .string "Je peux toiletter\n"
    .string "tes Pokémon\p"
    .string "pour juste\n"
    .string "500¥.\p"
    .string "Veux-tu que je m'en occupe?$"

GoldenrodUnderground_Text_OlderBrotherAskWhich:
    .string "Quel Pokémon veux-tu me confier?$"

GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
    .string "Bien! Il va être magnifique!$"

GoldenrodUnderground_Text_OlderBrotherAllDone:
    .string "Et voilà! Fini!$"

GoldenrodUnderground_Text_OlderBrotherThatsAShame:
    .string "Vraiment? Quel dommage!$"

GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
    .string "Tu n’as pas assez d’argent...$"

GoldenrodUnderground_Text_OlderBrotherOnePerDay:
    .string "Je ne fais qu'un toilettage par\n"
    .string "jour. Au revoir.$"

GoldenrodUnderground_Text_SupernerdEricSeen:
    .string "Je me suis fait virer du CASINO.\p"
    .string "J'étais juste en train de\n"
    .string "tricher avec mon Pokémon!$"

GoldenrodUnderground_Text_SupernerdEricBeaten:
    .string "... Grrr...$"

GoldenrodUnderground_Text_SupernerdEricAfterBattle:
    .string "Décidément, il faut la jouer à\n"
    .string "la loyale.$"

GoldenrodUnderground_Text_SupernerdTeruSeen:
    .string "Fais-tu attention aux types de\n"
    .string "Pokémon pendant les combats?\p"
    .string "Apprends les faiblesses\n"
    .string "et les avantages des\p"
    .string "types pour devenir\n"
    .string "plus terrible!$"

GoldenrodUnderground_Text_SupernerdTeruBeaten:
    .string "Oh, oh, oh!$"

GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
    .string "Je connais tous les types de\n"
    .string "Pokémon.\p"
    .string "Mais je n'en utilise qu'un seul.$"

GoldenrodUnderground_Text_PokemaniacIssacSeen:
    .string "Mon Pokémon s’est\n"
    .string "fait toiletter!\p"
    .string "Regarde comme il\n"
    .string "est beau et fort!$"

GoldenrodUnderground_Text_PokemaniacIssacBeaten:
    .string "Yaaaaaaaah!$"

GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
    .string "Les Pokémon t’aimeront plus si\n"
    .string "tu les fais toiletter.$"

GoldenrodUnderground_Text_PokemaniacDonaldSeen:
    .string "Tu as des Pokémon rares avec\n"
    .string "toi, je me trompe?\p"
    .string "J'veux les voir!$"

GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
    .string "Graah! Perdu! Ca craint!$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "Hier soir, près du magasin de\n"
	.string "VELOS, j'ai eu l'impression\p"
	.string "On m'observait depuis les toits…$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
    .string "Tu remplis un Pokédex? Voilà un\n"
    .string "conseil.\p"
    .string "MARIO, le MONTAGNARD de la ROUTE\n"
    .string "33 est sympa.\p"
    .string "Il t'appellera s'il voit des\n"
    .string "Pokémon rares.$"

GoldenrodUnderground_Text_DoorsLocked:
    .string "C'est fermé...$"

GoldenrodUnderground_Text_DoorIsOpen:
    .string "C'est ouvert.$"

GoldenrodUnderground_Text_KeyOpenedDoor:
    .string "La CLE SOUS-SOL a ouvert la\n"
    .string "porte.$"

GoldenrodUnderground_Text_NoEntry:
    .string "ENTREE INTERDITE$"
