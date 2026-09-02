OlivineCity_House1_hns_MapScripts::
	.byte 0

OlivineCity_House1_EventScript_Tim::
	lock
	faceplayer
	goto_if_set FLAG_OLIVINE_NPC_TRADE_COMPLETED, OlivineCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_VOLTORB, OlivineCity_House1_Text_YouWillTradeWontYou, OlivineCity_House1_EventScript_DeclineTrade, OlivineCity_House1_EventScript_NotRequestedMon, OlivineCity_House1_Text_MonYouTakeCare
	setflag FLAG_OLIVINE_NPC_TRADE_COMPLETED
	release
	end

OlivineCity_House1_EventScript_DeclineTrade::
	msgbox OlivineCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox OlivineCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_EventScript_TradeCompleted::
	msgbox OlivineCity_House1_Text_After, MSGBOX_DEFAULT
	release
	end

OlivineCity_House1_Text_YouWillTradeWontYou:
	.string "Je collectionne les Pokémon!\n"
	.string "Tu as un {STR_VAR_1}?\p"
	.string "Veux-tu l'échanger contre mon\n"
	.string "{STR_VAR_2}?$"

OlivineCity_House1_Text_MonYouTakeCare:
	.string "Youpi! J'ai obtenu {STR_VAR_1}!\p"
	.string "Prends soin de toi, {STR_VAR_2}!$"

OlivineCity_House1_Text_ThisIsntAMon:
	.string "Euh, non, je ne crois pas.\n"
	.string "Ce n'est pas un {STR_VAR_1}.$"

OlivineCity_House1_Text_YouWontTradeMe:
	.string "Tu ne veux pas échanger? Oh...$"

OlivineCity_House1_Text_After:
	.string "Salut! Comment va mon VOLTORBE?$"
