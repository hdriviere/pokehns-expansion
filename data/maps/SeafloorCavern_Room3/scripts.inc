SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Comment t’as fait pour venir\n"
	.string "jusqu’ici sans sous-marin? Quel\p"
	.string "môme impressionnant!\p"
	.string "Mais… C’est pas pour autant\n"
	.string "qu’on va te laisser te mêler de\p"
	.string "nos affaires.\p"
	.string "Et j’voudrais avoir ma revanche\n"
	.string "pour ce qui s’est passé au\p"
	.string "CENTRE METEO…\p"
	.string "Je vais te faire goûter à la\n"
	.string "douleur! Tu ferais mieux de\p"
	.string "renoncer!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Ouille!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha! Quelle puissance tu\n"
	.string "as!\p"
	.string "C’est vraiment dommage que tu ne\n"
	.string "sois pas membre de la TEAM AQUA.\p"
	.string "Tu aurais pu prendre du plaisir\n"
	.string "dans le fabuleux monde que notre\p"
	.string "CHEF nous a promis…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Pour réaliser notre rêve, nous\n"
	.string "avons besoin de la puissance des\p"
	.string "POKéMON.\p"
	.string "Mais il y a toujours des\n"
	.string "enquiquineurs comme toi qui\p"
	.string "utilisent leurs POKéMON pour\n"
	.string "contrecarrer nos plans!\p"
	.string "Rien ne se passe jamais comme\n"
	.string "prévu!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Graaah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Tu sais, nous ne remettons pas\n"
	.string "en question les motifs de notre\p"
	.string "CHEF.\p"
	.string "Mais tu es là, à vouloir stopper\n"
	.string "nos plans.\p"
	.string "Peut-être que… Tu dois avoir tes\n"
	.string "raisons…$"

