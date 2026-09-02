Route6_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX_HNS, PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN_HNS, PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_EventScript_Item_Silver_Wind::
    finditem ITEM_TM_SILVER_WIND
    end

Route6_Text_PokefanM:
	.string "Ils disent que\n"
	.string "le souterrain\p"
	.string "restera fermé tant\n"
	.string "que le problème à\p"
	.string "la Centrale ne sera pas résolu!$"

Route6_Text_UndergroundPathSign:
	.string "SOUTERRAIN\p"
	.string "AZURIA CARMIN SUR MER$"

PokefanM_Text_RexSeen:
	.string "Mon CERFROUSSE est le plus\n"
	.string "mignon du monde.$"

PokefanM_Text_RexBeaten:
	.string "Mon CERFROUSSE!$"

PokefanM_Text_RexAfter:
	.string "Regarde comme mon CERFROUSSE est\n"
	.string "adorable!\p"
	.string "N'est-il pas assez mignon pour\n"
	.string "faire fondre ton cœur?$"

PokefanM_Text_AllanSeen:
	.string "Mon GRANBULL est le plus mignon\n"
	.string "du monde.$"

PokefanM_Text_AllanBeaten:
	.string "Mon GRANBULL!$"

PokefanM_Text_AllanAfter:
	.string "Regarde comme mon GRANBULL est\n"
	.string "adorable!\p"
	.string "N'est-il pas assez mignon pour\n"
	.string "faire fondre ton cœur?$"
