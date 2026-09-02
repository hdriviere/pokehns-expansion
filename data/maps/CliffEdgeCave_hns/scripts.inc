CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "À une bifurcation souterraine,\n"
	.string "une voie est souvent la bonne et\l"
	.string "l'autre mène à une impasse.\p"
	.string "Mais tous veulent essayer\n"
	.string "les deux.$"
