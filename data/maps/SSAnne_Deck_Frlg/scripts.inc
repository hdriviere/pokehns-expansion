SSAnne_Deck_Frlg_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_ShipDepartingSoon::
	.string "La fête est finie! Nous allons\n"
	.string "bientôt lever l'ancre!$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
	.string "Nyah! Briquer le pont, c'est un\n"
	.string "travail épuisant!$"

SSAnne_Deck_Text_FeelSeasick::
	.string "Gueuh! J'suis malaaaaade…\p"
	.string "Je vais bientôt vom…$"

SSAnne_Deck_Text_EdmondIntro::
	.string "Hé! Toi, là!\p"
	.string "Tu danses? Un tango?$"

SSAnne_Deck_Text_EdmondDefeat::
	.string "… Belle technique!$"

SSAnne_Deck_Text_EdmondPostBattle::
	.string "Tu sais combien il y a de\n"
	.string "POKéMON différents? Hein, tu\p"
	.string "l'sais, hein?$"

SSAnne_Deck_Text_TrevorIntro::
	.string "Hoï! T'as le mal de mer?$"

SSAnne_Deck_Text_TrevorDefeat::
	.string "Oh! Beau combat!$"

SSAnne_Deck_Text_TrevorPostBattle::
	.string "Mon pôpa, y dit qu'y a 100\n"
	.string "POKéMON différents. J'suis sûr\p"
	.string "qu'y en a plus…$"

