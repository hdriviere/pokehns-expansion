FuchsiaCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	lock
	setspeaker FuchsiaCity_Text_BaobaName
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	release
	end

FuchsiaCity_Text_BaobaName:
	.string "Baoba$"

FuchsiaCity_Text_Baoba:
	.string "DIRECTEUR BAOBA: {PLAYER}!\p"
	.string "C'est le DIRECTEUR BAOBA.\p"
	.string "Une chose affreuse est arrivée!\n"
	.string "Mon ancienne ZONE SAFARI de\l"
	.string "PARMANIE a été rachetée, puis\l"
	.string "rouverte!\p"
	.string "Et elle aurait plein de nouveaux\n"
	.string "Pokémon exotiques!\p"
	.string "Ça nuit à mes affaires!\p"
	.string "{PLAYER}, pars dans cette\n"
	.string "nouvelle ZONE SAFARI et attrape\l"
	.string "un Pokémon à me montrer. Je dois\l"
	.string "en savoir plus sur ces Pokémon\l"
	.string "'exotiques'.\p"
	.string "S'il te plaît, {PLAYER},\n"
	.string "mon affaire dépend de toi!$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "L’un des membres\n"
	.string "actuels du\p"
	.string "Conseil 4 était le\n"
	.string "Champion d’Arène\p"
	.string "de Parmanie.$"

FuchsiaCity_Text_PokefanM:
	.string "Le Champion d’Arène est\n"
	.string "maintenant la fille de Koga,\p"
	.string "qui est parti au Conseil 4!$"

FuchsiaCity_Text_Teacher:
	.string "La ZONE SAFARI a une nouvelle\n"
	.string "direction.\p"
	.string "Et elle regorge de nouveaux\n"
	.string "Pokémon!$"

FuchsiaCity_Text_Sign:
	.string "PARMANIE\p"
	.string "Le rose de la passion!$"

FuchsiaCity_Text_GymSign:
	.string "Arène de Parmanie\p"
	.string "Champion: Jeannine Miss\n"
	.string "je-sais-tout-sur-les-poisons.$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "Il y a une affiche...\p"
	.string "Le BUREAU du PARC SAFARI est\n"
	.string "fermé jusqu'à nouvel ordre.$"

FuchsiaCity_Text_SafariZone:
	.string "ZONE SAFARI DÉSORMAIS GÉRÉE PAR\n"
	.string "DEVON SARL$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "Le GARDIEN voyage à l'étranger.\p"
	.string "Ainsi, le PARC SAFARI est fermé.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "Ne rien jeter.\p"
	.string "Utilisez les poubelles.$"
