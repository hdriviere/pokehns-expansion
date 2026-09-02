BattleFrontier_Lounge6_hns_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader_hns::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted_hns
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns, BattleFrontier_Lounge6_EventScript_DeclineTrade_hns, BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade_hns::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon_hns::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted_hns::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade_hns:
	.string "Mon POKéMON est un {STR_VAR_2}.\n"
	.string "Tu connais? C’est assez mignon\p"
	.string "et plutôt joli.\p"
	.string "Celui-là, je serais fière de\n"
	.string "l’échanger!\p"
	.string "Tu veux échanger un {STR_VAR_1}\n"
	.string "contre mon {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt_hns:
	.string "Oh, c’est adorable! Merci! Je\n"
	.string "vais bien m’en occuper!\p"
	.string "Dis, j’espère que tu prendras\n"
	.string "bien soin de mon {STR_VAR_2}!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon_hns:
	.string "Oh, je suis désolée! Je ferai\n"
	.string "l’échange uniquement contre un\p"
	.string "{STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo_hns:
	.string "Oh, tu ne veux pas? Bon, pas de\n"
	.string "problème. Reviens quand tu veux.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined_hns:
	.string "Hi, hi! Un SKITTY, c’est encore\n"
	.string "plus mignon que je ne le\p"
	.string "pensais!$"
