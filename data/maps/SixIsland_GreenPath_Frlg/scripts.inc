SixIsland_GreenPath_Frlg_MapScripts::
	.byte 0

SixIsland_GreenPath_EventScript_RightRouteSign::
	msgbox SixIsland_GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_EventScript_LeftRouteSign::
	msgbox SixIsland_GreenPath_Text_RightRouteSign, MSGBOX_SIGN
	end

SixIsland_GreenPath_Text_JaclynIntro::
	.string "… Quoi?\p"
	.string "Je voulais arriver chez moi,\n"
	.string "mais le TELEPORT m'a amenée ici.$"

SixIsland_GreenPath_Text_JaclynDefeat::
	.string "Noooon!$"

SixIsland_GreenPath_Text_JaclynPostBattle::
	.string "J'suis trop stressée du cerveau!\p"
	.string "Je dois me concentrer\n"
	.string "correctement pour me TELEPORTER\p"
	.string "chez moi.$"

SixIsland_GreenPath_Text_LeftRouteSign::
	.string "CHEMIN VERT FORBUISSONS DROIT\n"
	.string "DEVANT$"

SixIsland_GreenPath_Text_RightRouteSign::
	.string "CHEMIN VERT Respectez la nature!$"

