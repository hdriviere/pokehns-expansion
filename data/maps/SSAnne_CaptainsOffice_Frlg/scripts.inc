SSAnne_CaptainsOffice_Frlg_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_GOT_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	call EventScript_RestorePrevTextColor
	delay 50
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	giveitem_msg SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain, ITEM_HM01, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_GOT_HM01
	setvar VAR_MAP_SCENE_VERMILION_CITY, 1
	release
	end

@ Unused
SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
	.string "CAPITAINE: Blorf. J'suis pas\n"
	.string "bien. Beurp…$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
	.string "{PLAYER} tape dans le dos du\n"
	.string "CAPITAINE!\p"
	.string "Tap tap… Tap tap…$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
	.string "CAPITAINE: Merci moussaillon! Ça\n"
	.string "va beaucoup mieux…\p"
	.string "Mille sabords! Tu veux voir la\n"
	.string "capacité COUPE?\p"
	.string "Je pourrais te la montrer, mais\n"
	.string "j'suis malade.\p"
	.string "Je sais! Prends ça! C'est une\n"
	.string "CAPSULE SECRETE!\p"
	.string "Elle contient la capacité COUPE.\n"
	.string "Enseigne-la à tes POKéMON\p"
	.string "pour l'utiliser quand tu veux!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
	.string "{PLAYER} obtient CS01!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
	.string "Avec COUPE, tu peux abattre les\n"
	.string "petits arbres.\p"
	.string "Tu devrais essayer sur les\n"
	.string "arbres près de CARMIN SUR MER.$"

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
	.string "CAPITAINE: Haaaa!\p"
	.string "Maintenant que je suis guéri, on\n"
	.string "va lever l'ancre!\p"
	.string "L'OCEANE va bientôt partir!\p"
	.string "Bon vent! Nous reviendrons\n"
	.string "bientôt à CARMIN SUR MER!$"

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
	.string "Ha zut! Tu n'as plus de place\n"
	.string "pour cet objet!$"

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
	.string "Quoi?!? Il a mangé ça???$"

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
	.string "Comment guérir le mal de mer… Le\n"
	.string "CAPITAINE lit le manuel!$"

