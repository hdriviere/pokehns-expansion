SaffronCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_OnFrame::
	map_script_2 VAR_SAFFRON_CITY_STATE, 0,  SaffronCity_EventScript_BaobaCall
	.2byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_EventScript_BaobaCall::
	lock
	setspeaker SaffronCity_Text_BaobaName
	pokenavcall SaffronCity_Text_Baoba
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	setvar VAR_SAFFRON_CITY_STATE, 1
	release
	end

SaffronCity_Text_BaobaName:
	.string "Baoba$"

SaffronCity_Text_Baoba:
	.string "DIRECTEUR BAOBA: {PLAYER}!\p"
	.string "C'est le DIRECTEUR BAOBA.\p"
	.string "Je t'appelle pour t'annoncer que\n"
	.string "la ZONE SAFARI s'est encore\l"
	.string "agrandie!\p"
	.string "Enfin, ma ZONE SAFARI est\n"
	.string "entièrement achevée!\p"
	.string "Tu te rappelles où elle est?\p"
	.string "Juste à l'ouest d'IRISIA!\n"
	.string "À bientôt!$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "J'adore GOUPIX! :D$"

SaffronCity_Text_Lass1:
	.string "Une fille experte en imitation\n"
	.string "vit ici.\p"
	.string "Elle imite même les gens avec\n"
	.string "qui\p"
	.string "elle parle. C'est un peu lourd.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La COPIEUSE semble malheureuse.\n"
	.string "Elle\p"
	.string "dit avoir perdu sa Poké POUPEE\n"
	.string "préférée: MELOFEE.$"

SaffronCity_Text_PokefanM:
	.string "Tu viens de JOHTO?\p"
	.string "Tu peux retourner\n"
	.string "chez toi en une\p"
	.string "seconde si le TRAIN\n"
	.string "MAGNET fonctionne.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "Tu viens de Johto?\p"
	.string "Tu peux retourner\n"
	.string "chez toi en un\p"
	.string "clin d’œil avec le\n"
	.string "Train Magnétique.$"

SaffronCity_Text_CooltrainerM:
	.string "J’allais à l’Arène pour faire\n"
	.string "plein de combats...\p"
	.string "Et puis j’suis entré dans\n"
	.string "l’Arène abandonnée d’à côté.\p"
	.string "J’avais l’air un peu crétin.$"

SaffronCity_Text_CooltrainerF:
	.string "La SYLPHE SARL est célèbre pour\n"
	.string "ses produits Pokémon.\p"
	.string "C'est pour ça que la TEAM ROCKET\p"
	.string "voulait la contrôler...$"

SaffronCity_Text_Fisher:
	.string "(bouffe)(mâche)\p"
	.string "On dit qu'il y a du tintouin à\n"
	.string "la CENTRALE.\p"
	.string "(bouffe)(mâche)$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "(bouffe)(mâche)\p"
	.string "On dit qu'il y avait du tintouin\n"
	.string "à la CENTRALE.\p"
	.string "(bouffe)(mâche) J'ai plus faim!$"

SaffronCity_Text_Youngster1:
	.string "J’ai toujours le cœur\n"
	.string "qui bat plus fort\p"
	.string "quand je marche dans\n"
	.string "une rue inconnue!$"

SaffronCity_Text_Youngster2:
	.string "À JADIELLE, il existe une SALLE\n"
	.string "DE CONCOURS où se réunissent des\l"
	.string "Dresseurs venus de partout.$"

SaffronCity_Text_Lass2:
	.string "On a parlé de notre ville à la\n"
	.string "radio.\p"
	.string "Ca fait plaisir. C'est pas tous\n"
	.string "les jours.$"

SaffronCity_Text_Sign:
	.string "SAFRANIA\p"
	.string "Le berceau doré du commerce$"

SaffronCity_Text_GymSign:
	.string "CHAMPION d'ARENE de SAFRANIA:\n"
	.string "MORGANE\p"
	.string "La maîtresse des Pokémon PSY!$"

SaffronCity_Text_FightingDojoSign:
	.string "DOJO Bienvenue à tous!$"

SaffronCity_Text_SilphCoSign:
	.string "BUREAUX de la SYLPHE SARL$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "MAISON DE M.PSY$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "STATION du TRAIN MAGNET de\n"
	.string "SAFRANIA$"
