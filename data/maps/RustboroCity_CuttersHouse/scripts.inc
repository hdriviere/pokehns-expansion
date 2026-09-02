RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Ton air déterminé… La souplesse\n"
	.string "de tes mouvements…\p"
	.string "Tes POKéMON bien entraînés… Tu\n"
	.string "es à l’évidence un DRESSEUR\p"
	.string "averti!\p"
	.string "Non, attends, ne dis rien! Je\n"
	.string "devine tout rien qu’à te voir.\p"
	.string "Je suis sûr que tu seras capable\n"
	.string "de faire bon usage de cette CS.\p"
	.string "Ne sois pas modeste ni timide!\n"
	.string "Allez, prends-la!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Cette CS, c’est COUPE.\p"
	.string "Une CS, c’est une capacité qui\n"
	.string "peut être utilisée en dehors\p"
	.string "d’un combat.\p"
	.string "Tout POKéMON ayant appris COUPE\n"
	.string "peut abattre les petits arbres\p"
	.string "si son DRESSEUR possède le BADGE\n"
	.string "ROCHE.\p"
	.string "Et contrairement à une CT, une\n"
	.string "CS peut s’utiliser plusieurs\p"
	.string "fois.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Quand ils ont agrandi\n"
	.string "MEROUVILLE, mon papa les a\p"
	.string "aidés.\p"
	.string "Il a fait utiliser COUPE à son\n"
	.string "POKéMON pour qu’il déboise le\p"
	.string "terrain.$"

