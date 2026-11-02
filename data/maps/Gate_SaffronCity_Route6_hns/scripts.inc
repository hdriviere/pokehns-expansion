Gate_SaffronCity_Route6_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "Bienvenue à Safrania, la ville\n"
	.string "du Train Magnétique!\p"
	.string "... Du moins,\n"
	.string "c’est ce que je dis\p"
	.string "d’habitude, mais à\n"
	.string "cause de l’incident\p"
	.string "à la Centrale, il n’y a plus de\n"
	.string "courant\p"
	.string "pour faire fonctionner le train.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "Le Train Magnétique est la\n"
	.string "fierté de Safrania.$"
