OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	map_script_2 VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	setspeaker OlivineCity_Text_BaobaName
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_BaobaName:
	.string "Baoba$"

OlivineCity_Text_Baoba:
	.string "Ah, c’est toi {PLAYER}! C’est\n"
	.string "moi, M. Baoba!\p"
	.string "Désolé pour l’attente! Le parc\n"
	.string "est enfin ouvert!\p"
	.string "Tu sais où il est?\p"
	.string "Tu vois le portail creusé dans\n"
	.string "la roche à Irisia?\p"
	.string "Tu le passes, et\n"
	.string "si tu continues\p"
	.string "à marcher, tu\n"
	.string "arriveras au Safari!\p"
	.string "Bon, c’est un peu éloigné, mais\n"
	.string "viens, ça vaut vraiment le coup!$"

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0
	
	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "Encore toi?\n"
	.string "Inutile d'être sur tes gardes.\p"
	.string "Je ne m'occupe pas des minables\n"
	.string "dans ton genre.\p"
	.string "À propos de faibles,\n"
	.string "la Championne de cette ville\l"
	.string "est absente.\p"
	.string "Elle soignerait un Pokémon\n"
	.string "maladel"
	.string "au PHARE.\p"
	.string "Pfff! Quelle pleurnicheuse!\n"
	.string "Qu'elle abandonne ce Pokémon!\p"
	.string "Un Pokémon qui ne peut combattre\n"
	.string "ne vaut rien!\p"
	.string "Va donc t'entraîner au PHARE.\p"
	.string "Qui sait? Tu deviendras\n"
	.string "peut-être un Dresseur\l"
	.string "un peu moins mauvais!$"

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_ChargeBeam::
	finditem ITEM_TM_CHARGE_BEAM
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "CAFE D'OLIVILLE\n"
	.string "DE BONS PLATS COPIEUX\l"
	.string "POUR LES MARINS COSTAUDS$"

OlivineCity_Text_EonTicketWoman1:
	.string "Je m'appelle MARIE!\p"
	.string "Je plaisante, mais j'adore\n"
	.string "son émission de radio!$"

OlivineCity_Text_EonTicketWoman2:
	.string "Tu dois être {PLAYER}!!!\p"
	.string "Incroyable! Le Maître!\p"
	.string "J'ai entendu parler de toi dans\n"
	.string "l'émission de MARIE!\p"
	.string "Tiens, prends ceci!$"

OlivineCity_Text_EonTicketWoman3:
	.string "Je n'arrive pas à croire que\n"
	.string "j'ai rencontré le Maître!!!$"

OlivineCity_Text_Sailor1:
	.string "Les routes sombres sont\n"
	.string "dangereuses la nuit.\p"
	.string "Dans la pénombre la plus totale,\p"
	.string "la mer est encore plus traître!\p"
	.string "Sans la lumière du PHARE pour\n"
	.string "les\p"
	.string "guider, aucun navire ne peut\n"
	.string "naviguer.$"

OlivineCity_Text_YoungsterPokegear:
	.string "Ce serait pas un Pokématos que\n"
	.string "tu as là?\p"
	.string "Quelle chance! Qu’il est beau!$"

OlivineCity_Text_YoungsterPokedex:
	.string "Heu, t'as un joli Pokédex! C'est\p"
	.string "vraiment très impressionnant.$"

OlivineCity_Text_Sailor2:
	.string "La LIGUE classe JASMINE comme\n"
	.string "la sixième Championne d'Arène\l"
	.string "la plus forte!\p"
	.string "Ha! N'importe quoi.\p"
	.string "FREDO ne pourrait jamais blesser\n"
	.string "les Pokémon ACIER de JASMINE!\p"
	.string "C'est de la bureaucratie.\p"
	.string "Elle est redoutable, ça oui!$"

OlivineCity_Text_Sign:
	.string "OLIVILLE\p"
	.string "Le port vers d'autres horizons$"

OlivineCity_Text_PortSign:
	.string "PORT d'OLIVILLE PORT DU BATEAU\n"
	.string "EXPRESS$"

OlivineCity_Text_GymSign:
	.string "Arène d’Oliville Champion:\n"
	.string "Jasmine\p"
	.string "La demoiselle à la défense\n"
	.string "d’acier$"

OlivineCity_Text_LighthouseSign:
	.string "PHARE d'OLIVILLE Aussi connu\n"
	.string "sous le nom de PHARE SCINTILLANT$"

OlivineCity_Text_BattleTowerSign:
	.string "MONT DRESSEURS ET\n"
	.string "TENTES DE COMBAT PLUS LOIN\p"
	.string "OUVERTURE EN COURS!$"

OlivineCity_Text_Machoke:
	.string "MACHOPEUR: CHO!$"
