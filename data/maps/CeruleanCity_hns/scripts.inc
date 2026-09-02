CeruleanCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "Voici la CAVERNE AZURÉE.\p"
    .string "Des Pokémon d'une force terrible\n"
    .string "y vivent.\p"
    .string "Seuls des Dresseurs d'exception\n"
    .string "peuvent y entrer.\p"
    .string "Il faudrait déjà être assez fort\n"
    .string "pour devenir MAÎTRE de la LIGUE\l"
    .string "POKéMON de KANTO.\p"
    .string "Et avoir accompli un véritable\n"
    .string "exploit.$"

CeruleanCity_Text_CooltrainerM1:
	.string "Si tu cherches la\n"
	.string "Centrale de Kanto,\p"
	.string "suis la Route 9\n"
	.string "jusqu’au bout, à l’est.\p"
	.string "Il paraît qu’ils ont un\n"
	.string "problème...$"

CeruleanCity_Text_CooltrainerM2:
	.string "Tu collectionnes tous les\n"
	.string "Pokémon différents?\p"
	.string "Ca doit pas être super facile...\n"
	.string "Mais ça doit être rigolo, non?$"

CeruleanCity_Text_SuperNerd:
	.string "Le CAP au Nord est un bon\n"
	.string "endroit\p"
	.string "pour un rencard! Les filles\n"
	.string "adorent ça!$"

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "FLAGADOSS: Gaaa?$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_CITY_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_CITY_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_CITY_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "Mon FLAGADOSS et moi on va trop\n"
	.string "bien ensemble!$"

CeruleanCity_Text_CooltrainerF2:
	.string "FLAGADOSS! Lance CHOC MENTAL!$"

CeruleanCity_Text_CooltrainerF3:
	.string "...$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "Je suis le plus\n"
	.string "grand fan d’Ondine,\p"
	.string "le Champion de\n"
	.string "l’Arène d’Azuria!$"

CeruleanCity_Text_Fisher_RocketTip:
	.string "J'ai vu ce drôle de type aller\n"
	.string "vers le CAP d'AZURIA.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "La grotte au nord de la ville\n"
	.string "abrite des Pokémon extrêmement\l"
	.string "puissants.$"

CeruleanCity_Text_Youngster2:
	.string "Quoi?\p"
	.string "Mon CHERCH'OBJET vient de\n"
	.string "sonner...$"

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "AZURIA\p"
	.string "Entourée d'une étrange aura\n"
	.string "bleue$"

CeruleanCity_Text_GymSign:
	.string "Arène d’Azuria Champion: Ondine\p"
	.string "Notre sirène favorite!$"

CeruleanCity_Text_BikeShopSign:
	.string "Il y a une affiche...\p"
	.string "Les CYCLES A GOGO sont à\n"
	.string "DOUBLONVILLE à JOHTO...$"

CeruleanCity_Text_PoliceSign:
	.string "Il y a une affiche...\p"
	.string "Attention\n"
	.string "aux voleurs!\p"
	.string "Construisons notre\n"
	.string "bonheur ensemble!\p"
	.string "Police d’Azuria$"

CeruleanCity_Text_CapeSign:
	.string "CAP d'AZURIA Tout droit$"

CeruleanCity_Text_LockedDoor:
	.string "C'est fermé...$"
