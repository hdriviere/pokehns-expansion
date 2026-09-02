Route4_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK_HNS, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE_HNS, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON_HNS, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "J'entraîne des Pokémon. Un p'tit\n"
	.string "combat?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "Ack! Perdu...$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "Pour entraîner un\n"
	.string "Pokémon plus vite,\p"
	.string "mets-le en premier\n"
	.string "et retire-le tout\p"
	.string "de suite. Pas bête, hein?$"

Route4_Text_PicnickerHope_Seen:
	.string "Je vais gagner, je le sens. Ça\n"
	.string "va être ta fête, tu vas voir!$"

Route4_Text_PicnickerHope_Beaten:
	.string "Plein la tête!$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "Des MELOFEE apparaissent au MONT\p"
	.string "SELENITE, mais où exactement?$"

Route4_Text_PicnickerSharon_Seen:
	.string "Euh... C’est-à-dire que...$"

Route4_Text_PicnickerSharon_Beaten:
	.string "...$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "...........\p"
	.string "Je vais aller m'entraîner.....$"

Route4_Text_MtMoonSquareSign:
	.string "MONT SÉLÉNITE\n"
	.string "NOUVELLE ENTRÉE APRÈS\l"
	.string "UN ÉBOULEMENT\p"
	.string "REGARDEZ OÙ VOUS MARCHEZ$"
