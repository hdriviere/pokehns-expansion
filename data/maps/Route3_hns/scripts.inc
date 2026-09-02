Route3_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS_HNS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN_HNS, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY_HNS, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT_HNS, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "Ah! Il fait si beau!$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "Il fait beau mais j'ai froid,\n"
	.string "là...$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "La pluie ça mouille...$"

Route3_Text_YoungsterWarren_Seen:
	.string "Alors... Que faire...?$"

Route3_Text_YoungsterWarren_Beaten:
	.string "Pfff...perdu.$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "T’avais l’air balèze. C’est pour\n"
	.string "ça que j’étais intimidé.$"

Route3_Text_YoungsterJimmy_Seen:
	.string "Ha ha! Je cours comme le vent!$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "Ha ha! Génial!$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "Moi j'aime les shorts.\p"
	.string "C'est cool. C'est beau.$"

Route3_Text_FirebreatherBurt_Seen:
	.string "Venez! Venez voir!$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "Yaaah!$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "Je suis le plus grand crache-feu\n"
	.string "de KANTO.\p"
	.string "Mais je suis un dresseur nul...$"

Route3_Text_MtMoonSquareSign:
	.string "SQUARE du MONT SELENITE: En haut\n"
	.string "des escaliers.$"

