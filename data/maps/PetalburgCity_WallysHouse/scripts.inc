PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Tu es… Ah, tu dois être\n"
	.string "{PLAYER}{KUN}, n’est-ce pas?\p"
	.string "Merci d’avoir joué avec TIMMY.\p"
	.string "Il est faible et maladif depuis\n"
	.string "qu’il est tout petit.\p"
	.string "Nous l’avons envoyé chez des\n"
	.string "parents à VERGAZON pour quelque\p"
	.string "temps.\p"
	.string "L’air qu’on y respire est bien\n"
	.string "meilleur qu’ici.\p"
	.string "Comment ça? Où est TIMMY? Il est\n"
	.string "déjà parti, notre TIMMY.\p"
	.string "Je me demande où il peut bien\n"
	.string "être en ce moment.$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Comment va notre TIMMY?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Merci d’avoir\n"
	.string "accepté de venir.\p"
	.string "Notre TIMMY est en meilleure\n"
	.string "santé depuis qu’il est allé à\p"
	.string "VERGAZON.\p"
	.string "Et c’est à toi que nous le\n"
	.string "devons!\p"
	.string "Quand TIMMY a quitté la ville,\n"
	.string "tu l’as aidé à attraper un\p"
	.string "POKéMON, pas vrai?\p"
	.string "Je pense que ça l’a rendu très\n"
	.string "heureux.\p"
	.string "En fait, il n’y a pas que lui.\n"
	.string "Cela m’a aussi rendu heureux,\p"
	.string "moi son père.\p"
	.string "Quelle chance pour lui d’avoir\n"
	.string "comme camarade quelqu’un d’aussi\p"
	.string "bien que toi!\p"
	.string "Ce n’est pas pour te flatter,\n"
	.string "mais j’aimerais que tu acceptes\p"
	.string "ça.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Si ton POKéMON peut utiliser\n"
	.string "SURF, tu découvriras toutes\p"
	.string "sortes de lieux.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "TIMMY va bientôt rentrer. Je\n"
	.string "l’attends avec impatience.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Ah? Tu as vu TIMMY à ETERNARA?\p"
	.string "Oh, {PLAYER}{KUN}, ne dis pas\n"
	.string "n’importe quoi!\p"
	.string "Même s’il va mieux, il n’a pas\n"
	.string "pu aller aussi loin tout seul.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "TIMMY était très content de nous\n"
	.string "dire qu’il avait attrapé un\p"
	.string "POKéMON.\p"
	.string "Ça faisait une éternité que je\n"
	.string "ne l’avais pas vu sourire comme\p"
	.string "ça.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "N’en parle pas à mon mari…\p"
	.string "Mais notre TIMMY a quitté\n"
	.string "VERGAZON sans rien dire à\p"
	.string "personne.\p"
	.string "Tu sais, TIMMY est frêle, mais\n"
	.string "il a beaucoup de volonté.\p"
	.string "Je suis sûre qu’il rentrera\n"
	.string "bientôt sain et sauf.$"

