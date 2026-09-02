SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MONT MEMORIA…\p"
	.string "Au sommet reposent deux orbes\n"
	.string "l’un à côté de l’autre. Tu le\p"
	.string "savais?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "C’est ça, deux orbes côte à\n"
	.string "côte…\p"
	.string "Les voir ensemble… C’est\n"
	.string "apaisant…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Non. C’est vrai? Tu devrais\n"
	.string "peut-être y aller pour voir…$"

