Route10_PowerPlantBackRoom_hns_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDER
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	setvar VAR_VERMILION_CITY_SAMSON, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "PATRON: J'vais exploser! Faut\n"
	.string "que j'me défoule!\p"
	.string "Qui a cassé mon générateur? Qui?\p"
	.string "Je l'aimais tant! Comme mon\n"
	.string "bébé!\p"
	.string "Si j'attrape cette crapule, il\n"
	.string "aura\p"
	.string "droit à un coup d'ELECANON!$"

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "PATRON: Je vais m'le faire!\p"
	.string "Même s'il pleure, même s'il\n"
	.string "prie,\p"
	.string "je vais quand même me l'faire!\p"
	.string "Gahahahah!$"

Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "PATRON: Ah! Oui!\p"
	.string "C'est la PARTIE\n"
	.string "manquante de mon\p"
	.string "joli générateur!\n"
	.string "Tu l'as trouvée?$"

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "Wahah! Merci!\p"
	.string "Tiens! Prends cette CT!$"

Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "PATRON: Cette CT contient\n"
	.string "TONNERRE.\p"
	.string "Cette capacité est redoutable!\p"
	.string "Elle n'est pas vraiment précise,\n"
	.string "mais elle frappe très fort!$"

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "PATRON: Mon petit générateur\n"
	.string "chéri!\p"
	.string "Pompe l'électricité! Allez! Tu\n"
	.string "dois pomper!$"

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "Cette porte est dangereuse\n"
	.string "sans électricité.$"
