Route40_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON_HNS, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "Il faut s'échauffer avant de se\n"
	.string "baigner.\p"
	.string "Tout le monde sait ça!$"

Route40_Text_SwimmermSimonBeaten:
	.string "Aïe! Une crampe!$"

Route40_Text_SwimmermSimonAfter:
	.string "IRISIA est assez loin d'ici.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL_HNS, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "T'as la flemme ou quoi?\p"
	.string "Nage au lieu de monter sur ton\n"
	.string "Pokémon!$"

Route40_Text_SwimmermRandallBeaten:
	.string "Zut de flûte.$"

Route40_Text_SwimmermRandallAfter:
	.string "Nager, c'est bon pour la santé.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE_HNS, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "Tu vas à IRISIA?\p"
	.string "On s'bat d'abord?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "C'est perdu!$"

Route40_Text_SwimmerfElaineAfter:
	.string "En tout cas, je nage mieux que\n"
	.string "toi. Ouais!$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA_HNS, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "J'adore les Pokémon marins!$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "Oups!$"

Route40_Text_SwimmerfPaulaAfter:
	.string "Je me laisse porter par les\n"
	.string "vagues.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "IRISIA est de l'autre côté de la\n"
	.string "mer.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Je suis venue à OLIVILLE pour\p"
	.string "voir les beaux paysages...\p"
	.string "La mer, c'est bô.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "Tu es allé au MONT DRESSEURS?\p"
	.string "Je crois que de nombreux\n"
	.string "Dresseurs puissants s'y sont\l"
	.string "déjà réunis.\p"
	.string "Mais avec tous tes BADGES,\n"
	.string "tu devrais bien t'en sortir.$"

Route40_Text_Monica:
	.string "LUCIE: Enchantée.\n"
	.string "Je suis LUCIE de la fratrie\l"
	.string "des jours de la semaine.\p"
	.string "Je parie que tu ne devineras pas\n"
	.string "mon jour préféré!$"

Route40_Text_MonicaGivesGift:
	.string "C'est exact!\p"
	.string "En gage de notre amitié,\n"
	.string "j'ai un cadeau pour toi!$"

Route40_Text_MonicaGaveGift:
	.string "LUCIE: C'est un objet qui\n"
	.string "améliore\p"
	.string "les capacités du type VOL.\p"
	.string "Tu devrais le donner à un\n"
	.string "Pokémon oiseau.$"

Route40_Text_MonicaMonday:
	.string "Lucie: Mes frères et sœurs sont\n"
	.string "un peu partout.\p"
	.string "Trouve-les tous!$"

Route40_Text_MonicaNotMonday:
	.string "LUCIE: On est pas lundi\n"
	.string "aujourd'hui! Dommage...$"

Route40_Text_MonicaNope:
	.string "Ce n'est pas celui-là.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
