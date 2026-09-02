VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "TIMMY: J’ai perdu contre toi,\n"
	.string "{PLAYER}, mais je ne me sens\p"
	.string "plus déprimé.\p"
	.string "Maintenant, j’ai un nouveau but\n"
	.string "dans la vie. Avec mon TARSAL, je\p"
	.string "vais\p"
	.string "parcourir les ARENES et devenir\n"
	.string "un grand DRESSEUR.\p"
	.string "Regarde-moi bien, {PLAYER}. Je\n"
	.string "vais devenir plus fort que toi.\p"
	.string "Quand ce sera le cas, je te\n"
	.string "défierai encore une fois.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "TIMMY: Regarde-moi bien,\n"
	.string "{PLAYER}. Je vais devenir plus\p"
	.string "fort que toi.\p"
	.string "Quand ce sera le cas, je te\n"
	.string "défierai encore une fois.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "TONTON: Oh! {PLAYER}{KUN}! TIMMY\n"
	.string "est juste à côté.\p"
	.string "Mais avant, j’ai quelque chose à\n"
	.string "te dire.\p"
	.string "Cet environnement naturel fait\n"
	.string "des merveilles sur la santé de\p"
	.string "TIMMY.\p"
	.string "Mais ce n’est pas seulement\n"
	.string "l’environnement. Les POKéMON lui\p"
	.string "donnent aussi beaucoup d’espoir.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "TIMMY est parti… Il suit son\n"
	.string "propre chemin…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "TONTON: C’est vrai? TIMMY est\n"
	.string "allé aussi loin tout seul…\p"
	.string "Eh bien, il faudra que je le\n"
	.string "félicite. C’est bien le fils de\p"
	.string "mon frère.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "SYLVIE: Qui es-tu? Oh, d’accord,\n"
	.string "j’y suis!\p"
	.string "Tu es {PLAYER}. TIMMY m’a parlé\n"
	.string "de toi.\p"
	.string "Je suis la cousine de TIMMY.\n"
	.string "Enchantée de te rencontrer!\p"
	.string "Je crois que TIMMY est bien plus\n"
	.string "enjoué et solide depuis qu’il\p"
	.string "est arrivé ici.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "SYLVIE: Ne t’inquiète pas pour\n"
	.string "TIMMY. Tout ira bien pour lui.\p"
	.string "Je connais bien mon petit\n"
	.string "cousin. En plus, il a un POKéMON\p"
	.string "avec lui.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Grâce à toi, je peux voir ma\n"
	.string "copine tous les jours.\p"
	.string "Si je suis content? Bien\n"
	.string "entendu!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Le petit ami de ma fille est un\n"
	.string "garçon très expansif et\p"
	.string "passionné.\p"
	.string "Il creuse jour et nuit un tunnel\n"
	.string "juste pour voir ma fille.\p"
	.string "Ma fille est un peu inquiète,\n"
	.string "donc elle va souvent voir si le\p"
	.string "tunnel est fini.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Incroyable, le petit ami de ma\n"
	.string "fille a creusé le tunnel de ses\p"
	.string "propres mains!\p"
	.string "C’est hallucinant!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Si quelque chose arrivait à\n"
	.string "TIMMY, je ne pourrais plus\p"
	.string "regarder ses parents en face…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "TIMMY était à ETERNARA?\p"
	.string "Ses parents, qui sont à\n"
	.string "CLEMENTI, seraient stupéfaits\p"
	.string "d’entendre ça!$"

