PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Regardez ce {STR_VAR_2}!\p"
	.string "Je l'ai attrapé hier pour fêter\n"
	.string "mon anniversaire!\p"
	.string "Oh, je vois que vous le voulez!\n"
	.string "Après tout, il est inestimable!\p"
	.string "Voilà ce que je propose: je\n"
	.string "pourrais l'échanger contre un\p"
	.string "{STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, c’est un {STR_VAR_1}?\p"
	.string "Ça ressemble à un {STR_VAR_2},\n"
	.string "la différence est subtile.\p"
	.string "Merci!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Non, non et non! Un {STR_VAR_1}\n"
	.string "sinon rien!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, pas d’échange alors?\p"
	.string "Pas de problème. Je n’insiste\n"
	.string "pas.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Je sais que j’aurais pu m’en\n"
	.string "trouver un moi-même…\p"
	.string "Mais je voulais un DRABY attrapé\n"
	.string "par un autre DRESSEUR…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "C’est un POKéDEX?\p"
	.string "Tu as rencontré beaucoup de\n"
	.string "POKéMON différents?\p"
	.string "J’aimerais bien être comme toi.$"

