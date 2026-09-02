VioletCity_House1_hns_MapScripts::
	.byte 0

VioletCity_House1_EventScript_Kyle::
	lock
	faceplayer
	msgbox VioletCity_House1_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House1_EventScript_Rudy::
	lock
	faceplayer
	goto_if_set FLAG_VIOLET_NPC_TRADE_COMPLETED, VioletCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_ONIX, VioletCity_House1_Text_YouWillTradeWontYou, VioletCity_House1_EventScript_DeclineTrade, VioletCity_House1_EventScript_NotRequestedMon, VioletCity_House1_Text_MonYouTakeCare
	setflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	release
	end

VioletCity_House1_EventScript_DeclineTrade::
	msgbox VioletCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VioletCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_EventScript_TradeCompleted::
	msgbox VioletCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

VioletCity_House1_Text_YouWillTradeWontYou:
	.string "Je collectionne les Pokémon!\n"
	.string "Tu as un {STR_VAR_1}?\p"
	.string "Veux-tu l'échanger contre mon\n"
	.string "{STR_VAR_2}?$"

VioletCity_House1_Text_MonYouTakeCare:
	.string "Youpi! J'ai obtenu {STR_VAR_1}!\p"
	.string "Prends soin de {STR_VAR_2}!$"

VioletCity_House1_Text_ThisIsntAMon:
	.string "Euh, non, je ne crois pas.\n"
	.string "Ce n'est pas un {STR_VAR_1}.$"

VioletCity_House1_Text_YouWontTradeMe:
	.string "Tu ne veux pas échanger? Oh…$"

VioletCity_House1_Text_After:
	.string "Salut! Comment va l’ONIX que je\n"
	.string "t’ai échangé?$"

VioletCity_House1_Text_PokefanM:
	.string "Un Pokémon échangé grandit plus\n"
	.string "vite qu’un Pokémon attrapé.\p"
	.string "Mais si tu n’as pas\n"
	.string "assez de Badges,\p"
	.string "il risque de ne\n"
	.string "pas t’écouter.$"
