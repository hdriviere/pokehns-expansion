ViridianCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_OnFrame::
	map_script_2 VAR_OAK_MT_SILVER_CALL, 1, ViridianCity_EventScript_OakCall
	.2byte 0

ViridianCity_EventScript_OakCall::
	lock
	setspeaker ViridianCity_Text_OakName
	pokenavcall ViridianCity_Text_OakCall
	waitmessage
	delay 30
	setvar VAR_OAK_MT_SILVER_CALL, 2
	release
	end

ViridianCity_Text_OakName:
	.string "CHEN$"

ViridianCity_Text_OakCall:
	.string "CHEN: Ah, {PLAYER}!\p"
	.string "Passe me voir dans mon LABO\n"
	.string "à BOURG PALETTE quand tu en\l"
	.string "auras l'occasion.$"

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_DREAM_EATER, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisher, MSGBOX_NPC
	giveitem ITEM_TM_DREAM_EATER
	setflag FLAG_GOT_VIRIDIAN_TM_DREAM_EATER
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "Hé, toi! Je viens de m'enfiler\p"
	.string "un double café et j'ai la\n"
	.string "patate!\p"
	.string "Faut qu'je parle à quelqu'un\n"
	.string "alors... Ecoute-moi!\p"
	.string "J'ai pas l'air mais je suis un\p"
	.string "expert en capture de Pokémon.\p"
	.string "Tu me crois, hein?$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "Ouais, hein! Ouais! Tant mieux!$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "Quoi? Espèce de sale...\p"
	.string "Si j’étais plus jeune, hein!\n"
	.string "J’t’apprendrais! Tu verrais!$"

ViridianCity_Text_GrampsNearGym:
	.string "Cette ARENE vient juste d'avoir\n"
	.string "un CHAMPION officiel.\p"
	.string "Un jeune homme de PALETTE est\n"
	.string "devenu\p"
	.string "le CHAMPION mais il se balade\n"
	.string "beaucoup.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "Vas-tu affronter le CHAMPION?\p"
	.string "Bonne chance. T'en auras besoin.$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "...Zzzzz...\p"
	.string "Bâââille!\p"
	.string "J'ai dû m'assoupir au soleil.\p"
	.string "Quoi? Je te rappelle quelqu'un?\p"
	.string "Je ne sais pas...\n"
	.string "Tiens, prends ça.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
	.string "Waaah... J’ai dormi sous le\n"
	.string "soleil.\p"
	.string "... J’ai fait un\n"
	.string "rêve bizarre. Y’avait\p"
	.string "un SOPORIFIK qui\n"
	.string "mangeait mes rêves.\p"
	.string "... Tiens? C’est quoi? D’où\n"
	.string "vient cette CT?\p"
	.string "Hmmm... C’est ta faute!\p"
	.string "Tiens, prends-la!$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "CT42 contient DEVOREVE...\p"
	.string "...Zzzzz...$"

ViridianCity_Text_Youngster:
	.string "On dit qu’il y a plein\n"
	.string "d’objets invisibles\p"
	.string "qui jonchent le sol\n"
	.string "de la Forêt de Jade!$"

ViridianCity_Text_Sign:
	.string "JADIELLE\p"
	.string "Le paradis vert éternel$"

ViridianCity_Text_GymSign:
	.string "Arène de Jadielle Champion: ...\p"
	.string "Le reste est illisible...$"

ViridianCity_Text_WelcomeSign:
	.string "Bienvenue à JADIELLE, la porte\p"
	.string "vers le PLATEAU INDIGO$"

ViridianCity_Text_TrainerHouseSign:
	.string "CLUB des DRESSEURS\p"
	.string "Réservé aux meilleurs$"
