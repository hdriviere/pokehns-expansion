Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
	.string "Un POKéMON endormi bloque le\n"
	.string "chemin!$"

Text_SnorlaxWokeUp::
	.string "RONFLEX se réveille!\p"
	.string "Il est de mauvais poil! Il vous\n"
	.string "attaque!$"

Text_SnorlaxReturnedToMountains::
	.string "RONFLEX, une fois calmé, s'en\n"
	.string "retourne vers la montagne!$"

Text_WantToUsePokeFlute::
	.string "Tu veux utiliser la POKéFLUTE?$"

Text_PlayedPokeFlute::
	.string "{PLAYER} joue de la POKéFLUTE.$"

Route12_Text_NedIntro::
	.string "Ouais! Ça mord dans l'coin!$"

Route12_Text_NedDefeat::
	.string "Tsss! Trop p'tit!$"

Route12_Text_NedPostBattle::
	.string "Bouge pas! J'ai une touche!$"

Route12_Text_ChipIntro::
	.string "Patience! Pour pêcher, faut être\n"
	.string "tranquille!$"

Route12_Text_ChipDefeat::
	.string "Je l'ai laissé filer!$"

Route12_Text_ChipPostBattle::
	.string "Pour pêcher des POKéMON plus\n"
	.string "gros, il me faut une super\p"
	.string "CANNE!$"

Route12_Text_JustinIntro::
	.string "As-tu trouvé une PIERRE LUNE?$"

Route12_Text_JustinDefeat::
	.string "Aïe!$"

Route12_Text_JustinPostBattle::
	.string "J'aurais pu faire évoluer mes\n"
	.string "POKéMON avec une PIERRE LUNE!\p"
	.string "Et là, j'aurais gagné, c'est\n"
	.string "sûr!$"

Route12_Text_LucaIntro::
	.string "L'électricité, c'est ma\n"
	.string "spécialité!$"

Route12_Text_LucaDefeat::
	.string "Court-jus!$"

Route12_Text_LucaPostBattle::
	.string "L'eau conduit l'électricité.\n"
	.string "Planque tous tes POKéMON\p"
	.string "aquatiques!$"

Route12_Text_HankIntro::
	.string "Le PECHEUR FOU contre le KID des\n"
	.string "POKéMON!$"

Route12_Text_HankDefeat::
	.string "T'as gagné!$"

Route12_Text_HankPostBattle::
	.string "Tu m'as battu, mais… j'suis plus\n"
	.string "fort à la pêche!$"

Route12_Text_ElliotIntro::
	.string "Bon, j'ai du pain sur la\n"
	.string "planche!$"

Route12_Text_ElliotDefeat::
	.string "C'est pas facile…$"

Route12_Text_ElliotPostBattle::
	.string "C'est bon. Perdre ne me fait\n"
	.string "plus peur.$"

Route12_Text_AndrewIntro::
	.string "On ne sait jamais ce que l'on\n"
	.string "peut attraper!$"

Route12_Text_AndrewDefeat::
	.string "Hop, perdu!$"

Route12_Text_AndrewPostBattle::
	.string "J'arrête pas d'attraper des\n"
	.string "MAGICARPE, mais ils sont nuls!$"

Route12_Text_RouteSign::
	.string "ROUTE 12  LAVANVILLE au Nord$"

Route12_Text_SportfishingArea::
	.string "ZONE DE PECHE$"

Route12_Text_JesIntro::
	.string "JES: Si je gagne, je demande à\n"
	.string "GIA de m'épouser.$"

Route12_Text_JesDefeat::
	.string "JES: Tu aurais au moins pu faire\n"
	.string "semblant de perdre.$"

Route12_Text_JesPostBattle::
	.string "JES: Oh, GIA, pardonne-moi!$"

Route12_Text_JesNotEnoughMons::
	.string "JES: GIA et moi, on est ensemble\n"
	.string "pour la vie.\p"
	.string "On ne se battra pas avant que tu\n"
	.string "ramènes deux POKéMON.$"

Route12_Text_GiaIntro::
	.string "GIA: JES… Si on gagne, je\n"
	.string "t'épouse!$"

Route12_Text_GiaDefeat::
	.string "GIA: Oh… Mais pourquoi.$"

Route12_Text_GiaPostBattle::
	.string "GIA: JES, t'as fait exprès de\n"
	.string "perdre!$"

Route12_Text_GiaNotEnoughMons::
	.string "GIA: Je ne peux pas me battre\n"
	.string "sans JES!\p"
	.string "Reviens quand tu auras plus de\n"
	.string "POKéMON.$"
