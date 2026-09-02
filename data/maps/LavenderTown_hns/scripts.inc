LavenderTown_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "C’est un gros immeuble, hein?\n"
	.string "C’est la Tour Radio de Kanto!$"

LavenderTown_Text_Teacher:
	.string "Il y a aussi\n"
	.string "beaucoup d’émissions\p"
	.string "intéressantes\n"
	.string "à Kanto!$"

LavenderTown_Text_Gramps:
	.string "Les gens viennent\n"
	.string "de loin pour saluer\p"
	.string "le départ des âmes\n"
	.string "des pauvres Pokémon.$"

LavenderTown_Text_Youngster:
	.string "Il faut une Pokéflûte pour\n"
	.string "réveiller un Pokémon endormi.\p"
	.string "Tout le monde sait ça, voyons!$"

LavenderTown_Text_Sign:
	.string "LAVANVILLE\p"
	.string "La ville d'un pourpre royal$"

LavenderTown_Text_KantoRadioStationSign:
	.string "STATION de RADIO de KANTO\p"
	.string "Vos émissions favorites!$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "Bénévolat de Lavanville$"

LavenderTown_Text_SoulHouseSign:
	.string "MAISON DES AMES\p"
	.string "Que les âmes des Pokémon\n"
	.string "reposent en paix$"
