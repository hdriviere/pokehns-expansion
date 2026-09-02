VermilionCity_House1_hns_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_Fisher::
	msgbox VermilionCity_House1_Text_FishingDude, MSGBOX_NPC
	end
VermilionCity_House1_EventScript_Photo::
	msgbox VermilionCity_House1_Text_Photo, MSGBOX_NPC
	end
VermilionCity_House1_Text_FishingDude:
	.string "Je suis le grand frère des\n"
	.string "Maîtres Pêcheurs!\p"
	.string "Tu as rencontré le grand pêcheur\n"
	.string "du Lac Colère?\p"
	.string "Son rêve est de voir le plus\n"
	.string "gros MAGICARPE du monde.\p"
	.string "Si tu as envie, va lui montrer\n"
	.string "ceux que tu as déjà attrapés!\p"
	.string "Peut-être que l’un d’eux est le\n"
	.string "MAGICARPE de ses rêves...$"

VermilionCity_House1_Text_Photo:
	.string "C'est une photo de pêcheurs...\p"
	.string "Ils ont l'air de s'amuser...$"
