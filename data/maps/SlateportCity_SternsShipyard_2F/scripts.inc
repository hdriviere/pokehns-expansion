SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.string "Concevoir un grand bateau relève\n"
	.string "plus de la construction d’un\p"
	.string "vaste bâtiment que de\n"
	.string "l’assemblage d’un véhicule.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.string "C’est étrange qu’un bateau fait\n"
	.string "d’acier puisse flotter, non?\p"
	.string "S’il flotte, c’est dû à ce que\n"
	.string "l’on appelle le principe de\p"
	.string "flottabilité.$"

