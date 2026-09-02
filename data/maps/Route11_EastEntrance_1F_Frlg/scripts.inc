Route11_EastEntrance_1F_Frlg_MapScripts::
	.byte 0

Route11_EastEntrance_1F_EventScript_TopGuard::
	msgbox Route11_EastEntrance_1F_Text_ManInLavenderRatesNames, MSGBOX_NPC
	end

Route11_EastEntrance_1F_EventScript_BottomGuard::
	msgbox Route11_EastEntrance_1F_Text_RockTunnelToReachLavender, MSGBOX_NPC
	end

@ Unclear where this is originally from
Route11_EastEntrance_1F_Text_BagIsFull::
	.string "{PLAYER}{KUN}の　バッグ\n"
	.string "いっぱい　みたい　だね$"

Route11_EastEntrance_1F_Text_ManInLavenderRatesNames::
	.string "C'est dur de donner un surnom\n"
	.string "sympa à ses POKéMON!\p"
	.string "A LAVANVILLE, un vieil homme\n"
	.string "juge les noms des POKéMON.\p"
	.string "Il peut même  t'aider à les\n"
	.string "renommer!$"

Route11_EastEntrance_1F_Text_RockTunnelToReachLavender::
	.string "Si tu veux aller à LAVANVILLE,\n"
	.string "passe par la GROTTE.\p"
	.string "Tu peux l'emprunter en passant\n"
	.string "par AZURIA.$"

