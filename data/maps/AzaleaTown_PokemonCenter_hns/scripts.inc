AzaleaTown_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN_HNS
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "Est-ce que ton Pokémon connait\n"
	.string "des CS?\p"
	.string "Ces actions peuvent\n"
	.string "être réalisées\p"
	.string "même si le Pokémon\n"
	.string "est évanoui.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "Un certain LEO a créé le système\n"
	.string "de stockage des Pokémon sur PC.\p"
	.string "Le PC de LEO peut stocker\n"
	.string "30 Pokémon par BOITE.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "Le PC de Léo peut garder jusqu’à\n"
	.string "30 Pokémon par Boîte!$"

AzaleaPokecenter_Text_PokefanF:
	.string "Connais-tu les NOIGRUMES?\p"
	.string "Ouvre-en un, vide-le et place\n"
	.string "un dispositif spécial.\p"
	.string "Tu pourras attraper des Pokémon\n"
	.string "avec.\p"
	.string "Avant les Poké Balls,\n"
	.string "tout le monde en utilisait.$"
