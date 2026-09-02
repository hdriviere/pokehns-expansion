BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Je me demande s’il y aura des\n"
	.string "interviews de bons DRESSEURS\p"
	.string "aujourd’hui.$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Si j’ouvrais un restaurant ici,\n"
	.string "je ferais fortune!$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Pfiou…\p"
	.string "J’aurais besoin de faire le vide\n"
	.string "dans ma tête entre deux combats…\p"
	.string "Mais je n’arrête jamais de\n"
	.string "penser à ma stratégie.$"

