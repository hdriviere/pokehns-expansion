FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Il se passe quelque chose\n"
	.string "d’étrange, je n’aime pas trop\p"
	.string "ça!\p"
	.string "J’ai aperçu quelqu’un entrer et\n"
	.string "sortir du LABO du PROF. KOSMO.$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Cela fait très longtemps que\n"
	.string "cette région est connue pour ses\p"
	.string "météorites.\p"
	.string "Un météorite se serait jadis\n"
	.string "écrasé, creusant le SITE\p"
	.string "METEORE.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Tu vois! Regarde! C’est mon cher\n"
	.string "AZURILL!\p"
	.string "Il est adroit, et en plus il est\n"
	.string "doux!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Azuzuuu.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "As-tu déjà affronté ADRIANE, le\n"
	.string "CHAMPION de l’ARENE de\p"
	.string "VERMILAVA?\p"
	.string "Son grand-père était célèbre. Il\n"
	.string "a fait partie du CONSEIL 4 de la\p"
	.string "LIGUE POKéMON.\p"
	.string "Ça ne me surprendrait pas de\n"
	.string "voir ADRIANE devenir un grand\p"
	.string "DRESSEUR à son tour.$"

FallarborTown_Text_BattleTentSign:
	.string "TENTE DE COMBAT d’AUTEQUIA “Que\n"
	.string "les meilleures équipes se\p"
	.string "rencontrent!”$"

FallarborTown_Text_TownSign:
	.string "AUTEQUIA “Une communauté\n"
	.string "agricole et ses petits jardins.”$"

FallarborTown_Text_MoveTutorSign:
	.string "MAISON DU MAITRE DES CAPACITES\n"
	.string "“Venez apprendre de nouvelles\p"
	.string "capacités à vos POKéMON!”$"

