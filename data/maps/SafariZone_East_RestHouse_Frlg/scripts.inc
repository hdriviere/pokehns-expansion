SafariZone_East_RestHouse_Frlg_MapScripts::
	.byte 0

SafariZone_East_RestHouse_EventScript_Rocker::
	msgbox SafariZone_East_Text_CaughtChanseyAllWorthwhile, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_HowManyDidYouCatch, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_BaldingMan::
	msgbox SafariZone_East_Text_TiredFromAllTheFun, MSGBOX_NPC
	end

SafariZone_East_Text_HowManyDidYouCatch::
	.string "T'en as capturé combien? Moi\n"
	.string "j'suis naze!$"

SafariZone_East_Text_CaughtChanseyAllWorthwhile::
	.string "J'ai trouvé un LEVEINARD!\p"
	.string "J'ai bien fait de chercher\n"
	.string "pendant 4 heures!$"

SafariZone_East_Text_TiredFromAllTheFun::
	.string "Pffff! J'en ai marre!$"

