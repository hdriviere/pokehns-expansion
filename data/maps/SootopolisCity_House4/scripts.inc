SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Ecoute-moi bien, je vais te dire\n"
	.string "quelque chose d’intéressant.\p"
	.string "Il paraît qu’il existe, pas très\n"
	.string "loin d’ici, une vieille ruine\p"
	.string "dans la mer.\p"
	.string "Il y a peut-être là-bas des\n"
	.string "trésors qui ne demandent qu’à\p"
	.string "être découverts.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "D’anciens trésors…\p"
	.string "Ce serait formidable s’ils\n"
	.string "existaient vraiment, mais même\p"
	.string "si ce n’est pas le cas, ce\n"
	.string "serait merveilleux de faire un\p"
	.string "tour sous l’eau avec mon\n"
	.string "POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL: Zuzu.$"

