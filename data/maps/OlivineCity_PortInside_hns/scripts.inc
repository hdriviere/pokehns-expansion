OlivineCity_PortInside_hns_MapScripts::
	.byte 0


OlivineCity_PortInside_EventScript_Oak::
	lock
	playbgm MUS_HG_OAK, FALSE
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_OLIVINEPORT_OAK
	turnobject LOCALID_OLIVINEPORT_OAK, DIR_NORTH
	msgbox OlivineCity_PortInside_Text_Nationaldex1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakFixDex
	waitmovement 0
	delay 30
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_ITEM
	message OlivineCity_PortInside_Text_Nationaldex2
	waitfanfare
	delay 50
	msgbox OlivineCity_PortInside_Text_Nationaldex3, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_OLIVINEPORT_OAK
	msgbox OlivineCity_PortInside_Text_Nationaldex4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OlivineCity_PortInside_Movement_PlayerMoveOver
	waitmovement 0
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakLeave
	waitmovement 0
	setflag FLAG_HIDE_OLIVINE_PORT_OAK
	playse SE_EXIT
	removeobject LOCALID_OLIVINEPORT_OAK
	fadedefaultbgm
	waitse
	release
	end

OlivineCity_PortInside_Movement_OakFixDex:
	walk_in_place_up
	walk_in_place_up
	step_end

OlivineCity_PortInside_Movement_PlayerMoveOver:
	walk_up
	walk_left
	face_right
	step_end

OlivineCity_PortInside_Movement_OakLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_PortInside_Text_Nationaldex1:
	.string "PROF. CHEN: Bonjour, {PLAYER}!\n"
	.string "Tu commences à avoir l'allure\l"
	.string "d'un Maître!\p"
	.string "Il est temps que ton POKéDEX\n"
	.string "soit digne de ton rang.\p"
	.string "Passe-le-moi un instant...\p"
	.string "Je vais lui ajouter\n"
	.string "le MODE NATIONAL.$"
OlivineCity_PortInside_Text_Nationaldex2:
	.string "Le Mode National a été ajouté au\n"
	.string "Pokédex de {PLAYER}!$"
OlivineCity_PortInside_Text_Nationaldex3:
	.string "PROF. CHEN: Compléter le POKéDEX\n"
	.string "NATIONAL ne sera pas facile...\p"
	.string "Mais je sais que tu feras\n"
	.string "de ton mieux pour nous!$"
OlivineCity_PortInside_Text_Nationaldex4:
	.string "Quoi! C’est déjà si tard?!\p"
	.string "Je dois être à Doublonville pour\n"
	.string "mon émission de radio...\p"
	.string "Tu vas tenter ta chance à Kanto\n"
	.string "maintenant, non?\p"
	.string "Mon Laboratoire\n"
	.string "se trouve dans un\p"
	.string "petit village appelé\n"
	.string "Bourg Palette.\p"
	.string "Si tu passes par là, viens me\n"
	.string "montrer ton Pokédex!$"

OlivinePort_EventScript_CooltrainerF::
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher1::
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher2::
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
	end

OlivinePort_EventScript_Youngster::
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
	end

OlivinePort_EventScript_Sailor::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivinePort_EventScript_Sailor_AfterKanto
	msgbox OlivinePort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivinePort_EventScript_Sailor_MaidenVoyage
	msgbox OlivinePort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_AfterKanto::
	message OlivinePort_Text_WhereSail
	multichoice 20, 0, MULTI_OLIVINE_HARBOR, FALSE
	switch VAR_RESULT
	case 0, OlivinePort_EventScript_ChoseVermilion
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
	case 2, OlivinePort_EventScript_ChoseBirthIsland
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
	case 4, OlivinePort_EventScript_ChoseBattleFrontier
	case 5, OlivinePort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
	release
	end

OlivinePort_EventScript_ChoseVermilion::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE_HNS, 8, 9
	waitstate
	release
	end

OlivinePort_EventScript_ChoseSouthernIsland::
	closemessage
	delay 20
	checkitem ITEM_EON_TICKET
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR_HNS, 13, 22
	waitstate
	release
	end

OlivinePort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR_HNS, 13, 23
	waitstate
	release
	end

OlivinePort_EventScript_ChoseFarawayIsland::
	closemessage
	delay 20
	checkitem ITEM_OLD_SEA_MAP
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE_HNS, 13, 38
	waitstate
	release
	end	

OlivinePort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST_HNS, 20, 67
	waitstate
	release
	end	

OlivinePort_EventScript_Sailor_MaidenVoyage::
	msgbox OlivinePort_Text_FlashTicket, MSGBOX_DEFAULT
	call OlivinePort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	clearflag FLAG_HIDE_SSAQUA_SAILOR
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	warpsilent MAP_SSAQUA_1F_HNS, 29, 3
	waitstate
	release
	end

OlivinePort_EventScript_EnterShip::
	msgbox OlivinePort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, OlivinePort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_BoatLeave
	applymovement LOCALID_OLIVINEPORT_BOAT, OlivinePort_Movement_BoatLeave
	waitmovement LOCALID_OLIVINEPORT_BOAT
	setrespawn HEAL_LOCATION_OLIVINE_CITY_HNS
	return

OlivinePort_EventScript_Sailor_Refused::
	msgbox OlivinePort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_NoCredentials::
	msgbox OlivinePort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

OlivinePort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

OlivinePort_Movement_BoatLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OlivinePort_Text_NoPass:
	.string "{PLAYER} essaie de montrer\n"
	.string "{STR_VAR_1}...\p"
	.string "...Mais pas de {STR_VAR_1}!\p"
	.string "Désolé!\n"
	.string "Tu ne peux embarquer qu'avec\l"
	.string "{STR_VAR_1}.$"

OlivinePort_Text_SailorGetOnBoard:
    .string "Le départ est proche. Tout le\n"
    .string "monde à bord.$"

OlivinePort_Text_CantBoard:
    .string "On ne monte plus à bord.$"

OlivinePort_Text_WhereSail:
	.string "Où veux-tu aller?$"

OlivinePort_Text_AskBoard:
    .string "Bienvenue sur le BATEAU EXPRESS:\n"
    .string "L'AQUARIA.\p"
    .string "Allez-vous monter à bord?$"

OlivinePort_Text_AskTicket:
    .string "Puis-je voir votre PASSE BATEAU?$"

OlivinePort_Text_ComeAgain:
    .string "A bientôt!$"

OlivinePort_Text_FlashTicket:
    .string "{PLAYER} montre son PASSE\n"
    .string "BATEAU.\p"
    .string "Parfait. Merci bien!$"

OlivinePort_Text_NoTicket:
    .string "{PLAYER} voudrait bien montrer\n"
    .string "son PASSE BATEAU...\p"
    .string "Mais... Pas de TICKET!\p"
    .string "Désolé! On ne monte à bord\p"
    .string "que sur présentation d'un PASSE.$"

OlivinePort_Text_FishingGuru1:
    .string "Les KOKIYAS sont faciles à\n"
    .string "choper\p"
    .string "dans le coin. Ils sont plus\n"
    .string "rares ailleurs.$"

OlivinePort_Text_FishingGuru2:
    .string "Combien de CANNES as-tu?\p"
    .string "Des CANNES différentes attrapent\n"
    .string "des Pokémon différents.$"

OlivinePort_Text_Youngster:
    .string "L'AQUARIA a des propulseurs pour\n"
    .string "foncer sur l'eau!$"

OlivinePort_Text_CooltrainerF:
    .string "Il y a plein de Pokémon à KANTO.\p"
    .string "J'aimerais tant y aller...$"

OlivinePort_Text_SailorBeforeHOF:
    .string "On ne veut pas que tu tombes à\n"
    .string "l'eau\p"
    .string "alors tu ne peux pas passer.$"
