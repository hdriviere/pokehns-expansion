FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Personne ne me croit, mais j’ai\n"
	.string "vraiment vu ce POKéMON\p"
	.string "gigantesque dans le ciel.\p"
	.string "J’ai eu l’impression qu’il\n"
	.string "volait vers le CHENAL 131.\p"
	.string "Snifff… Hum… Tu… euh… sens le\n"
	.string "brûlé.\p"
	.string "Tu étais sur un volcan ou\n"
	.string "quelque chose comme ça?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Je veux aller à l’ARENE POKéMON,\n"
	.string "mais quelque chose bloque le\p"
	.string "passage.\p"
	.string "Après tout le mal que je me suis\n"
	.string "donné pour venir m’entraîner sur\p"
	.string "la ROUTE 120!$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "J’ai des POKéMON qui font ma\n"
	.string "joie et ma fierté. Cette fois,\p"
	.string "je battrai ALIZEE.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Le sol absorbe l’eau de pluie et\n"
	.string "les arbres poussent en puisant\p"
	.string "cette eau…\p"
	.string "Notre CIMETRONELLE existe grâce\n"
	.string "à l’eau et à la terre.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "C’est une VILLE formée de\n"
	.string "maisons construites dans les\p"
	.string "arbres.\p"
	.string "Ici, on est tous en forme et\n"
	.string "dynamiques. Probablement grâce à\p"
	.string "ce mode de vie!\p"
	.string "Même moi, j’ai l’impression\n"
	.string "d’avoir rajeuni de trente ans.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "C’est bien de vivre en haut des\n"
	.string "arbres.\p"
	.string "Mais parfois, des POKéMON du\n"
	.string "type INSECTE passent par les\p"
	.string "fenêtres.\p"
	.string "Ça peut faire très peur.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Certains POKéMON évoluent quand\n"
	.string "ils sont échangés! C’est ce\p"
	.string "qu’on raconte!$"

FortreeCity_Text_SomethingUnseeable:
	.string "Quelque chose d’invisible bloque\n"
	.string "la voie.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Quelque chose d’invisible bloque\n"
	.string "la voie.\p"
	.string "Voulez-vous utiliser le DEVON\n"
	.string "SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} utilise le DEVON SCOPE.\p"
	.string "Un POKéMON invisible devient\n"
	.string "tout à coup visible!\p"
	.string "Le POKéMON, effrayé, s’enfuit!$"

FortreeCity_Text_CitySign:
	.string "CIMETRONELLE “Là où les cimes\n"
	.string "des arbres sont en harmonie avec\p"
	.string "la nature.”$"

FortreeCity_Text_GymSign:
	.string "ARENE POKéMON de CIMETRONELLE\n"
	.string "CHAMPION: ALIZEE\p"
	.string "“Celle qui utilise les oiseaux\n"
	.string "et prend son envol dans le\p"
	.string "monde.”$"

