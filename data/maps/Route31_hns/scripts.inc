Route31_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE_HNS, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten, Route31_EventScript_RegisterWade
	goto_if_set FLAG_WADE_HAS_ITEM_HNS, Route31_EventScript_WadeGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_RematchWade
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_RegisterWade::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route31_Text_WadeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WADE_HNS
	release
	end

Route31_EventScript_RematchWade::
	trainerbattle_rematch TRAINER_WADE_HNS, Route31_Text_WadeRematchIntro, Route31_Text_WadeRematchDefeat
	msgbox Route31_Text_WadePostRematch, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeGiveItem::
	msgbox Route31_Text_WadeHasItem, MSGBOX_DEFAULT
	giveitem VAR_WADE_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route31_EventScript_WadeNoRoom
	clearflag FLAG_WADE_HAS_ITEM_HNS
	msgbox Route31_Text_WadeGaveItem, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_WadeNoRoom::
	msgbox Route31_Text_WadeNoRoom, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	msgbox Route31_Text_DescribeRest, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "ANTRE NOIRE...\p"
	.string "Si un Pokémon\n"
	.string "pouvait l'éclairer,\p"
	.string "on pourrait\n"
	.string "l'explorer...$"

Route31_Text_BugCatcherWade1_Seen:
	.string "J’ai attrapé plein\n"
	.string "de Pokémon. On\p"
	.string "va pouvoir faire\n"
	.string "un beau combat!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "Aaaaaaaaah!$"

Route31_Text_BugCatcherWade1_After:
	.string "Tu peux attraper un Pokémon même\n"
	.string "si tu en as six sur toi.\p"
	.string "Il sera transféré dans une Boîte\n"
	.string "du PC automatiquement.$"

Route31_Text_SleepyMan:
	.string "...Nnngneuh?\p"
	.string "J'ai trop marché pour trouver\n"
	.string "des Pokémon.\p"
	.string "J'ai mal aux pieds et j'ai\n"
	.string "sommeil.\p"
	.string "Si j'étais un Pokémon, je serais\n"
	.string "facile à choper...\p"
	.string "...Zzzz...$"

Route31_Text_SleepyManGotMail:
	.string "...Zzzz...Hein?\p"
	.string "C'est quoi? Tu as une LETTRE\n"
	.string "pour moi?$"

Route31_Text_SleepyManFail:
	.string "…Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} donne le Pokémon tenant\n"
	.string "la Lettre!$"

Route31_Text_ReadingMail:
	.string "Voyons ça…\p"
	.string "Merci de m'avoir apporté ça.\p"
	.string "Mon ami est quelqu'un de bien,\n"
	.string "et toi aussi!\p"
	.string "Je veux te rendre la pareille!\p"
	.string "Je sais! Je veux que tu prennes\n"
	.string "ceci!$"

Route31_Text_DescribeRest:
	.string "…Zzz…\p"
	.string "…Mmm… Repos!\p"
	.string "L'expression 'récupérer vite'\n"
	.string "est devenue 'Repos', tu vois?\p"
	.string "Cette capacité permet de dormir\n"
	.string "pour récupérer des PV.$"

Route31_Text_WrongMail:
	.string "Cette Lettre n’est pas pour\n"
	.string "moi... Zzz...$"

Route31_Text_MissingMail:
	.string "Pourquoi ce Pokémon est-il si\n"
	.string "spécial?\p"
	.string "Il n'a pas de LETTRE.$"

Route31_Text_DeclinedToHandOverMail:
	.string "Quoi? Tu ne veux rien?$"

Route31_Text_CantTakeLastMon:
	.string "Si je te prends ce Pokémon, avec\n"
	.string "qui vas-tu combattre?$"

Route31_Text_Youngster:
	.string "J’ai trouvé un bon Pokémon dans\n"
	.string "l’Antre Noir!\p"
	.string "Je vais l’entraîner\n"
	.string "pour battre le\p"
	.string "Champion de l’Arène\n"
	.string "de Mauville,\p"
	.string "Albert!$"

Route31_Text_Sign:
	.string "ROUTE 31\p"
	.string "MAUVILLE VILLE GRIOTTE$"

Route31_Text_WadeRegister:
	.string "Tu es génial! Je t'aime bien!\p"
	.string "Je cherche des Pokémon ici tous\n"
	.string "les jours.\p"
	.string "Dans les herbes, je trouve\n"
	.string "toutes sortes de BAIES.\p"
	.string "Si tu veux, je les partagerai\n"
	.string "avec toi.$"

Route31_Text_WadeRematchIntro:
	.string "Je t’attendais... Allons-y!$"

Route31_Text_WadeRematchDefeat:
	.string "Aaaaaaaaah!$"

Route31_Text_WadePostRematch:
	.string "Je t’appelle si\n"
	.string "je trouve un truc\p"
	.string "sympa. J’adore\n"
	.string "trouver des trucs!$"

Route31_Text_WadeHasItem:
	.string "Hé! Je te cherchais!\p"
	.string "J'ai trouvé quelque chose dans\n"
	.string "les hautes herbes.\p"
	.string "Tiens, c'est pour toi!$"

Route31_Text_WadeGaveItem:
	.string "Je te préviendrai si je trouve\n"
	.string "autre chose!$"

Route31_Text_WadeNoRoom:
	.string "Hum, ton SAC semble plein.\p"
	.string "Reviens quand tu auras de la\n"
	.string "place!$"

Route31_Text_DarkCaveSign:
	.string "Antre Noir$"
