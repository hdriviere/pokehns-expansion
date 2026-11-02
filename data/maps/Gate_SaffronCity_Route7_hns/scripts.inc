Gate_SaffronCity_Route7_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "Il paraît qu’il y a eu un\n"
	.string "incident à la Centrale...\p"
	.string "Elle est de l’autre côté, vers\n"
	.string "Lavanville.$"

Route7_Text_SaffronGuard_Serious:
	.string "Je prends mon travail\n"
	.string "de vigile très au\p"
	.string "sérieux. Oh! Mais\n"
	.string "c’est un Pokédex!\p"
	.string "Tu peux passer!$"
