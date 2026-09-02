EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "Salut, je suis LEO. Et toi qui\n"
	.string "es-tu?\p"
	.string "{PLAYER}, hein? Tu arrives au\n"
	.string "bon moment.$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "Je viens de terminer\n"
	.string "les réglages de mon SYSTÈME\l"
	.string "DE STOCKAGE Pokémon.\p"
	.string "Tu connais le PC où tu déposes\n"
	.string "tous tes Pokémon?\p"
	.string "C'est moi qui l'ai conçu!\p"
	.string "Maintenant qu'il est installé,\n"
	.string "mon PC fonctionne dans tous les\l"
	.string "CENTRES Pokémon de JOHTO\n"
	.string "et KANTO.\p"
	.string "Je dois vite rentrer\n"
	.string "à DOUBLONVILLEl"
	.string "pour voir ma famille.\p"
	.string "Passe quand tu veux!\p"
	.string "Salut!$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "La façon dont les KIMONO dansent\n"
	.string "est\p"
	.string "merveilleuse. Comme lorsqu'elles\n"
	.string "utilisent leurs Pokémon.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "Tu veux te battre contre\n"
	.string "plus d'adversaires,\p"
	.string "non? Il y a un\n"
	.string "endroit fait pour toi.\p"
	.string "Où ça?\p"
	.string "Après OLIVILLE.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "MORTIMER, le CHAMPION d'ARENE\n"
	.string "est trooop cool.\p"
	.string "Ses Pokémon sont bien balèzes.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "LAC COLERE...\p"
	.string "Là où le LEVIATOR apparaît...\p"
	.string "Ca sent l'embrouille. Je sais!$"
