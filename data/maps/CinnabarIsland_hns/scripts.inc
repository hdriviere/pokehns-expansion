CinnabarIsland_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
	.string "AUGUSTE: Je n'abandonnerai pas\n"
	.string "avant d'avoir rebâti l'ARÈNE\l"
	.string "de CRAMOIS'ÎLE!\p"
	.string "D'ici là, je serai au DOJO\n"
	.string "DE COMBAT.$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "T'es qui toi?\p"
	.string "T'es dresseur, ça se voit...\p"
	.string "Moi c'est BLUE.\p"
	.string "J'ai été un MAITRE pendant un\n"
	.string "temps.\p"
	.string "Enfin, pendant quelques minutes.\p"
	.string "Juste avant que RED me batte...\p"
	.string "Je le hais ce type...\p"
	.string "Bon tu veux quoi? Tu veux\n"
	.string "t'battre?\p"
	.string "Désolé mais j'ai pas la tête à\n"
	.string "ça.\p"
	.string "Regarde autour de toi...\p"
	.string "Un volcan explose et une ville\p"
	.string "disparaît d'un coup.\p"
	.string "Faire du POKé POKé c'est bien\n"
	.string "joli\p"
	.string "mais on peut se faire balayer\n"
	.string "par\p"
	.string "une catastrophe naturelle à tout\n"
	.string "moment...\p"
	.string "...\p"
	.string "C'est comme ça. On y peut rien.\p"
	.string "Mais bon. J'suis quand même un\n"
	.string "dresseur.\p"
	.string "Et un balèze en plus. J'te\n"
	.string "l'avais dit, non?\p"
	.string "Si tu cherches un bon combat,\n"
	.string "viens à l'ARENE de JADIELLE.\p"
	.string "Et ça sera ta p'tite fête.$"

CinnabarIsland_Text_Blue:
	.string "T'es qui toi?\p"
	.string "T'es dresseur, ça se voit...\p"
	.string "Moi c'est BLUE.\p"
	.string "J'ai été un MAITRE pendant un\n"
	.string "temps.\p"
	.string "Enfin, pendant quelques minutes.\p"
	.string "Juste avant que RED me batte...\p"
	.string "Je le hais ce type...\p"
	.string "Bon tu veux quoi? Tu veux\n"
	.string "t'battre?\p"
	.string "Désolé mais j'ai pas la tête à\n"
	.string "ça.\p"
	.string "Regarde autour de toi...\p"
	.string "Un volcan explose et une ville\p"
	.string "disparaît d'un coup.\p"
	.string "Faire du POKé POKé c'est bien\n"
	.string "joli\p"
	.string "mais on peut se faire balayer\n"
	.string "par\p"
	.string "une catastrophe naturelle à tout\n"
	.string "moment...\p"
	.string "...\p"
	.string "C'est comme ça. On y peut rien.\p"
	.string "Mais bon. J'suis quand même un\n"
	.string "dresseur.\p"
	.string "Et un balèze en plus. J'te\n"
	.string "l'avais dit, non?\p"
	.string "Si tu cherches un bon combat,\n"
	.string "viens à l'ARENE de JADIELLE.\p"
	.string "Et ça sera ta p'tite fête.$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "Il y a un mot...\p"
	.string "L'ARENE de CRAMOIS'ILE est\n"
	.string "déplacée aux ILES ECUME.\p"
	.string "AUGUSTE$"

CinnabarIsland_Text_Sign:
	.string "CRAMOIS'ILE\p"
	.string "Rouge comme le feu$"
