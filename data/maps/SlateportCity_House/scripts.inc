SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mon POKéMON est PRESSE. C’est sa\n"
	.string "nature.\p"
	.string "Sa VITESSE est plus élevée que\n"
	.string "celle de mes autres POKéMON.\p"
	.string "La nature des POKéMON a\n"
	.string "peut-être un rapport avec leurs\p"
	.string "stats.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Tu es un DRESSEUR, n’est-ce pas?\p"
	.string "Tu dois vouloir te rendre à la\n"
	.string "TENTE DE COMBAT de POIVRESSEL,\p"
	.string "non?$"

