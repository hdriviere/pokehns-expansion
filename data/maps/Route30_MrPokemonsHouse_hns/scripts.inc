Route30_MrPokemonsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_MRPOKEMON
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, FALSE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "Bonjour! Tu dois être {PLAYER}.\p"
	.string "Le PROF.ORME a dit que tu\n"
	.string "viendrais.$"

MrPokemonHouse_Text_Intro2:
	.string "Voilà ce que je voudrais que le\n"
	.string "PROF.ORME examine.$"

MrPokemonHouse_Text_GotEgg:
	.string "{PLAYER} reçoit l'OEUF MYSTERE.$"

MrPokemonHouse_Text_Intro3:
	.string "Je connais un couple d'amis qui\n"
	.string "dirige une PENSION pour Pokémon.\p"
	.string "Ils m'ont donné cet OEUF.\p"
	.string "Il m'a paru louche alors j'ai\n"
	.string "écrit au PROF.ORME.\p"
	.string "En ce qui concerne\n"
	.string "les évolutions de\p"
	.string "Pokémon, le PROF.ORME\n"
	.string "est incollable.$"


MrPokemonHouse_Text_Intro4:
	.string "Même le PROF.CHEN le reconnaît.$"

MrPokemonHouse_Text_Intro5:
	.string "A mon avis, le PROF.ORME aura\n"
	.string "une explication.$"

MrPokemonHouse_Text_Heal:
	.string "Tu retournes voir le PROF.ORME?\p"
	.string "Tiens. Tes Pokémon devraient se\n"
	.string "reposer.$"

MrPokemonHouse_Text_DependingOnYou:
	.string "Je compte sur toi!$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "C'est beau la vie! Il y a\n"
	.string "toujours\p"
	.string "quelque chose à découvrir!$"

MrPokemonHouse_Text_OakIntro:
	.string "CHEN: Ahaa! C'est toi {PLAYER}!\p"
	.string "Moi c'est CHEN! Je suis un\n"
	.string "chercheur Pokémon.\p"
	.string "Je suis venu rendre visite à mon\n"
	.string "vieil ami... M.Pokémon!\p"
	.string "On m'a dit que tu rendais\n"
	.string "service au\p"
	.string "PROF.ORME, alors je t'attendais.\p"
	.string "Oh! C'est quoi ça? Un Pokémon\n"
	.string "rare!\p"
	.string "Voyons...\p"
	.string "Hmm... Je vois!\p"
	.string "Je comprends pourquoi le\n"
	.string "PROF.ORME\p"
	.string "t'a confié un Pokémon pour cette\n"
	.string "mission.\p"
	.string "Pour des chercheurs comme moi\p"
	.string "et le PROF.ORME, les Pokémon\n"
	.string "sont des amis.\p"
	.string "Il a tout de suite compris que\n"
	.string "tu\p"
	.string "ferais attention à ton Pokémon.\p"
	.string "...Ah!\p"
	.string "On peut te faire confiance.\p"
	.string "Ca te dirait de me rendre\n"
	.string "service?\p"
	.string "Regarde ça: c'est une nouvelle\n"
	.string "version du Pokédex.\p"
	.string "Il enregistre automatiquement\n"
	.string "les\p"
	.string "données sur les Pokémon vus ou\n"
	.string "pris.\p"
	.string "C'est une encyclopédie moderne!$"

MrPokemonHouse_Text_GetDex:
	.string "{PLAYER} reçoit le Pokédex!$"

MrPokemonHouse_Text_OakParting:
	.string "Rencontre un maximum de Pokémon\n"
	.string "et\p"
	.string "complète le Pokédex!\p"
	.string "Bon. Je dois y aller.\p"
	.string "J'ai une émission de radio à\n"
	.string "faire à DOUBLONVILLE.\p"
	.string "{PLAYER}, je compte sur toi!$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "Oh? Cette ECAILLE! C'est quoi?\n"
	.string "Un LEVIATOR rouge?\p"
	.string "C'est dingue! Je la veux...\p"
	.string "{PLAYER}, veux-tu l'échanger?\p"
	.string "Je peux te donner le MULTI EXP\n"
	.string "du PROF.CHEN.$"

MrPokemonHouse_Text_Disappointed:
	.string "Quel dommage! Une chose aussi\n"
	.string "rare...$"

MrPokemonHouse_Text_ExpShare:
	.string "J'ai aussi un objet spécial\n"
	.string "pour toi.$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "Il y a plein de magazines du\n"
	.string "monde entier!\p"
	.string "... Les titres sont\n"
	.string "illisibles...$"

MrPokemonHouse_Text_BrokenComputer:
	.string "Un gros ordinateur! ... Il a\n"
	.string "l’air cassé...$"

MrPokemonHouse_Text_StrangeCoins:
	.string "Un tas de pièces\n"
	.string "jamais vues! Elles\p"
	.string "sont peut-être\n"
	.string "d’un autre pays?$"

MrPokemonHouse_Text_GotExpShare:
	.string "{PLAYER} reçoit le MULTI EXP!$"
