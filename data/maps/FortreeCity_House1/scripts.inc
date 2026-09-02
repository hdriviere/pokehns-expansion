FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PLUSLE, FortreeCity_House1_Text_YouWillTradeWontYou, FortreeCity_House1_EventScript_DeclineTrade, FortreeCity_House1_EventScript_NotRequestedMon, FortreeCity_House1_Text_MonYouTakeCare
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Aaaah, j’en veux un! Il me faut\n"
	.string "un {STR_VAR_1}!\p"
	.string "Je ferais n’importe quoi pour en\n"
	.string "avoir un! C’est un vrai cri du\p"
	.string "cœur!\p"
	.string "Maintenant que tu es au courant,\n"
	.string "tu vas échanger ton {STR_VAR_1}\p"
	.string "contre un {STR_VAR_2}, n’est-ce\n"
	.string "pas?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Ouais, super!\p"
	.string "{STR_VAR_1}, bienvenue!\n"
	.string "{STR_VAR_2}, fais attention à\p"
	.string "toi!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Ah non, je ne pense pas! Ce\n"
	.string "n’est pas un {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Non? Tu ne veux pas faire\n"
	.string "d’échange? Même après que je\p"
	.string "t’ai ouvert mon cœur?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "A partir de maintenant, je vais\n"
	.string "rendre ce MUCIOLE très fort!\p"
	.string "J’espère que tu feras la même\n"
	.string "chose avec POSIPI!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Echanger des POKéMON avec\n"
	.string "d’autres…\p"
	.string "C’est comme échanger ses propres\n"
	.string "souvenirs avec quelqu’un\p"
	.string "d’autre.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZATON: Zigzaaa?$"

