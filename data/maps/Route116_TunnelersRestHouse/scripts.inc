Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "C’est le TUNNEL MERAZON, là-bas…\p"
	.string "Au début, de nombreux ouvriers\n"
	.string "perçaient les rochers avec\p"
	.string "d’énormes engins. Mais nous\n"
	.string "avons dû arrêter.\p"
	.string "On s’est rendu compte que les\n"
	.string "travaux avaient un effet négatif\p"
	.string "sur les POKéMON sauvages de la\n"
	.string "région.\p"
	.string "Maintenant, nous n’avons plus\n"
	.string "rien à faire, à part flâner.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Il y a un homme qui creuse un\n"
	.string "TUNNEL vers VERGAZON, tout seul.\p"
	.string "Il veut absolument passer.\p"
	.string "Il affirme que s’il creuse petit\n"
	.string "à petit sans utiliser de\p"
	.string "machine, il ne dérangera pas les\n"
	.string "POKéMON et n’abîmera pas\p"
	.string "l’écosystème environnant.\p"
	.string "Je me demande s’il a déjà fini.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Pour atteindre VERGAZON sans\n"
	.string "utiliser ce TUNNEL, tu devras\p"
	.string "naviguer jusqu’à MYOKARA, puis\n"
	.string "jusqu’à POIVRESSEL et enfin\p"
	.string "passer par LAVANDIA.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Tu as entendu? Le TUNNEL pour\n"
	.string "VERGAZON est enfin terminé!\p"
	.string "Parfois, si l’on souhaite très\n"
	.string "fort quelque chose, ça se\p"
	.string "réalise.$"

