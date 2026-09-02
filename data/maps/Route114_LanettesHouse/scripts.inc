Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "ANNETTE: Oh! {PLAYER}{KUN}!\p"
	.string "Je suis désolée. C’est la\n"
	.string "pagaille. Quand je suis plongée\p"
	.string "dans mes recherches, je n’ai pas\n"
	.string "le temps de ranger…\p"
	.string "C’est très embarrassant… Si tu\n"
	.string "n’en parles à personne, je te\p"
	.string "donne ça.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Je peux te donner un conseil sur\n"
	.string "mon programme de Gestion de\p"
	.string "Stocks de POKéMON?\p"
	.string "Tu peux organiser tes BOITES\n"
	.string "pour savoir quels POKéMON elles\p"
	.string "contiennent.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Ce sont les notes d’ANNETTE. Il\n"
	.string "y a des informations sur les\p"
	.string "BOITES.\p"
	.string "Concevoir des BOITES pouvant\n"
	.string "contenir 30 POKéMON chacune.\p"
	.string "Chaque DRESSEUR doit pouvoir\n"
	.string "stocker 420 POKéMON sur son PC.\p"
	.string "Continuer à lire?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Ajouter un système de marquage\n"
	.string "pour faciliter l’organisation\p"
	.string "des POKéMON.\p"
	.string "Le nom et le fond de chaque\n"
	.string "BOITE pourront être modifiés\p"
	.string "pour satisfaire les POKéMON\n"
	.string "stockés.\p"
	.string "Continuer à lire?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Quand un POKéMON est stocké, il\n"
	.string "est envoyé dans la dernière\p"
	.string "BOITE ouverte.\p"
	.string "Si cette BOITE est pleine, le\n"
	.string "POKéMON reçu sera stocké dans la\p"
	.string "suivante.\p"
	.string "En bref, la dernière BOITE\n"
	.string "ouverte devient la BOITE dans\p"
	.string "laquelle les POKéMON seront\n"
	.string "envoyés.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} ferme le cahier.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Il y a un e-mail sur le PC.\p"
	.string "… … … … … … …\p"
	.string "Votre programme de Gestion de\n"
	.string "Stocks est plus performant que\p"
	.string "le mien.\p"
	.string "La simplicité d’utilisation en\n"
	.string "fait un outil à la fois amusant\p"
	.string "et utile.\p"
	.string "Je suis très content d’avoir\n"
	.string "participé à son développement.\p"
	.string "J’espère que vous continuerez\n"
	.string "vos recherches sur la Gestion de\p"
	.string "Stocks.\p"
	.string "De la part de LEO. … … … … … … …\n"
	.string "…$"

