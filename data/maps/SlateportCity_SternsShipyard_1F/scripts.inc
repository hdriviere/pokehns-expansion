SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Hum… Si ceci va ici et si cela\n"
	.string "va là…\p"
	.string "Mais, où va cette chose? Et ça,\n"
	.string "alors?\p"
	.string "Aaargh! Ça n’a ni queue ni tête!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hum? Salut, je suis ARCHIBALD.\p"
	.string "Le CAPT. POUPE m’a chargé de\n"
	.string "concevoir un ferry.\p"
	.string "Oh! Ça, là… C’est le PACK DEVON?\p"
	.string "Mais, hum… Ça ne va pas…\p"
	.string "Le CAPT. POUPE est sorti. Il a\n"
	.string "dit qu’il avait du travail.\p"
	.string "Pourrais-tu aller trouver le\n"
	.string "CAPT. POUPE et le lui remettre?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "ARCHIBALD: Où le CAPT. POUPE\n"
	.string "peut-il bien être allé?\p"
	.string "Pourrais-tu aller trouver le\n"
	.string "CAPT. POUPE et lui remettre ce\p"
	.string "paquet?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "ARCHIBALD: Construire des\n"
	.string "bateaux est un art.\p"
	.string "Bien des choses ne peuvent être\n"
	.string "résolues rien que par des\p"
	.string "calculs.\p"
	.string "Il me faudrait les conseils d’un\n"
	.string "vieux loup de mer…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "ARCHIBALD: Salut! M. MARCO nous\n"
	.string "a rejoints pour nous proposer\p"
	.string "son aide.\p"
	.string "Grâce à l’expérience du\n"
	.string "navigateur, l’assemblage du\p"
	.string "ferry suit son cours.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "ARCHIBALD: Le ferry est enfin\n"
	.string "terminé!\p"
	.string "Le nouveau LE MARINA est une\n"
	.string "merveille de technologie. Aucun\p"
	.string "doute!\p"
	.string "Mais j’ai le sentiment que nous\n"
	.string "pouvons encore l’améliorer.\p"
	.string "Tu sais, la technologie est en\n"
	.string "perpétuelle évolution.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "M. MARCO: Ah, {PLAYER}{KUN}! Ça\n"
	.string "faisait longtemps!\p"
	.string "Hé, depuis notre dernière\n"
	.string "rencontre, le vieux loup de mer\p"
	.string "est d’humeur folâtre.\p"
	.string "Alors j’ai décidé d’aider\n"
	.string "ARCHIBALD à construire un ferry.\p"
	.string "Hé, après tout, un ferry pourra\n"
	.string "transporter plein de gens.\p"
	.string "Mais, tu sais, cet ARCHIBALD,\n"
	.string "c’est vraiment quelqu’un!\p"
	.string "Avec ses connaissances et mon\n"
	.string "expérience, je suis sûr qu’on va\p"
	.string "pouvoir construire un imposant\n"
	.string "bateau, hé, hé!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Les saisons, le temps, le\n"
	.string "coefficient de marée…\p"
	.string "Ces paramètres, parmi d’autres,\n"
	.string "influent sur l’état de la mer.\p"
	.string "C’est vrai! La mer est comme un\n"
	.string "être vivant!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "J’ai facilement le mal de mer.\n"
	.string "Alors je reste souvent aider\p"
	.string "ici.$"

