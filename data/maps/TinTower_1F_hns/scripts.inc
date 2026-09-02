TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "Selon la légende...\p"
	.string "Lorsque les âmes des Pokémon et\n"
	.string "des\p"
	.string "humains se réunissent, un\n"
	.string "Pokémon\p"
	.string "aux couleurs de l'arc-en-ciel\n"
	.string "descend des cieux...\p"
	.string "Est-il possible que les Pokémon\p"
	.string "légendaires mettent les humains\n"
	.string "à l'épreuve?$"

TinTower_1F_Sage2_Text:
	.string "Lorsque la TOUR de CUIVRE brûla,\p"
	.string "trois Pokémon\n"
	.string "sans nom ont,\p"
	.string "paraîtil, péri\n"
	.string "dans les flammes...\p"
	.string "Toutefois...\p"
	.string "Un Pokémon couleur\n"
	.string "arc-en-ciel...\p"
	.string "Ou plus précisément...\p"
	.string "HO-OH, descendit du ciel et\n"
	.string "redonna\p"
	.string "la vie aux trois Pokémon.\p"
	.string "Ils se nomment...\p"
	.string "SUICUNE, ENTEI et RAIKOU.\p"
	.string "Et voilà ce qu'on raconte.$"

TinTower_1F_Sage3_Text:
	.string "On dit que les deux TOURS furent\p"
	.string "construites pour sceller\n"
	.string "l'amitié\p"
	.string "entre Pokémon et humains.\p"
	.string "C'était il y a 700 ans, mais\p"
	.string "l'idée reste la même\n"
	.string "aujourd'hui.$"

TinTower_1F_Sage4_Text1:
	.string "HO-OH a dû arriver ici, à la\n"
	.string "TOUR FERRAILLE!$"

TinTower_1F_Sage4_Text2:
	.string "Les Pokémon légendaires sont\n"
	.string "censés\p"
	.string "posséder trois pouvoirs...\p"
	.string "La foudre qui a frappé la TOUR.\p"
	.string "Le feu qui a brûlé la TOUR.\p"
	.string "Et la pluie qui a éteint le\n"
	.string "feu...$"

TinTower_1F_Sage6_Text2:
	.string "On dit que le\n"
	.string "Pokémon légendaire\p"
	.string "SUICUNE est le plus\n"
	.string "proche de HO-OH.\p"
	.string "Il y aurait aussi un lien avec\n"
	.string "les\p"
	.string "Pokémon connus sous le nom de...\n"
	.string "ZARBI.\p"
	.string "Les ZARBI et SUICUNE doivent\p"
	.string "être liés en un sens...$"

TinTower_1F_EusineHoOh_Text:
	.string "Je le savais.\p"
	.string "Je savais que tu verrais\n"
	.string "le Pokémon\l"
	.string "aux couleurs de l'arc-en-ciel,\l"
	.string "<PLAYER>.\p"
	.string "Tout s'est passé comme prévu.\n"
	.string "Mes recherches se\l"
	.string "défendent plutôt bien!\p"
	.string "Je vais continuer à étudier les\n"
	.string "Pokémon pour devenir un célèbre\l"
	.string "POKéMANIAC!$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE: Incroyable! Fabuleux!\n"
	.string "Jamais je n'avais vu tel combat.\p"
	.string "C'était vraiment inspirant.\n"
	.string "SUICUNE était puissant, mais toi\p"
	.string "encore plus, <PLAYER>.\n"
	.string "On dit que le pouvoir mystique\p"
	.string "de SUICUNE appelle un Pokémon\n"
	.string "aux couleurs de l'arc-en-ciel.\p"
	.string "Peut-être que les événements\n"
	.string "d'aujourd'hui feront apparaître\p"
	.string "ce Pokémon. Je vais approfondir\n"
	.string "mon étude des légendes.\p"
	.string "Merci pour ce combat fabuleux.\p"
	.string "À plus tard, <PLAYER>!$"
