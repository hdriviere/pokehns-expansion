SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Tu es DRESSEUR, non?\p"
	.string "JUAN d’ATALANOPOLIS a de\n"
	.string "nombreux fans. Encore plus que\p"
	.string "son élève MARC!\p"
	.string "Et toi, tu en as?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, quelle puissance tu dois\n"
	.string "avoir!$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, mon p’tit… Tu es un peu\n"
	.string "solitaire.\p"
	.string "Essaie de travailler plus dur\n"
	.string "pour avoir des fans à tes côtés.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Les fans dévoués viennent même\n"
	.string "d’en dehors de HOENN.\p"
	.string "C’était la folie quand je suis\n"
	.string "allée au FAN CLUB DES DRESSEURS\p"
	.string "à NENUCRIQUE.$"

