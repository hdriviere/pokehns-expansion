AlolaWater_hns_MapScripts::
	.byte 0


Alola_MelemeleSea_TrainerBattleSwimmer::
	trainerbattle_single TRAINER_MELEMELE_SWIMMER_2_HNS, Alola_MelemeleSea_TrainerBattleSwimmer_Text_0, Alola_MelemeleSea_TrainerBattleSwimmer_Text_1
	msgbox Alola_MelemeleSea_TrainerBattleSwimmer_Text_2, MSGBOX_AUTOCLOSE
	release
	end


Alola_MelemeleSea_TrainerBattleSwimmer_Text_0:
	.string "Que d'eau libre par ici!$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_1:
	.string "Aïe,\pje me suis froissé un muscle...$"

Alola_MelemeleSea_TrainerBattleSwimmer_Text_2:
	.string "Il y a de forts courants ici.\n"
	.string "Je crois qu'ils attirent des\l"
	.string "Pokémon puissants!$"
