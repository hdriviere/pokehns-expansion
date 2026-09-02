BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "Mon POKéMON est un {STR_VAR_2}.\n"
	.string "Tu connais? C’est assez mignon\p"
	.string "et plutôt joli.\p"
	.string "Celui-là, je serais fière de\n"
	.string "l’échanger!\p"
	.string "Tu veux échanger un {STR_VAR_1}\n"
	.string "contre mon {STR_VAR_2}?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Oh, c’est adorable! Merci! Je\n"
	.string "vais bien m’en occuper!\p"
	.string "Dis, j’espère que tu prendras\n"
	.string "bien soin de mon {STR_VAR_2}!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Oh, je suis désolée! Je ferai\n"
	.string "l’échange uniquement contre un\p"
	.string "{STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Oh, tu ne veux pas? Bon, pas de\n"
	.string "problème. Reviens quand tu veux.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Hi, hi! Un SKITTY, c’est encore\n"
	.string "plus mignon que je ne le\p"
	.string "pensais!$"
