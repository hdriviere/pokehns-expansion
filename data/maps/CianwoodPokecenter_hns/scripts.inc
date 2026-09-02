CianwoodPokecenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	@callnative DisableStaticRandomizer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "Parmi les Pokémon Eau, TENTACOOL\n"
	.string "est de très loin le meilleur!$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "Tu sembles avoir besoin\n"
	.string "d'un Pokémon Eau.\p"
	.string "Tiens, prends celui-ci.\n"
	.string "J'en ai beaucoup.$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "As-tu rencontré le Pokémaniac?\p"
	.string "Il se vante sans cesse sur ses\n"
	.string "Pokémon rares.$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "Les dresseurs de l'ARENE sont\n"
	.string "des grosses brutes.\p"
	.string "Je veux pas qu'ils s'en prennent\n"
	.string "à moi.\p"
	.string "Un conseil: le CHAMPION utilise\n"
	.string "le type COMBAT.\p"
	.string "Tu devrais donc utiliser des\n"
	.string "Pokémon PSY.\p"
	.string "Mets son équipe K.O. avant\n"
	.string "qu'elle\p"
	.string "n'utilise la force.\p"
	.string "Et les rochers au milieu de\n"
	.string "l'ARENE?\p"
	.string "Bouge-les correctement pour\n"
	.string "accéder au CHAMPION.\p"
	.string "Si tu ne peux plus progresser,\n"
	.string "sors.$"

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER}! Tu as gagné! Je le\n"
	.string "savais rien qu'en te voyant!$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "J'adore frimer avec mes Pokémon.\p"
	.string "Et toi? C'est ton truc?\p"
	.string "Je vais faire plein de combats\p"
	.string "et frimer avec mes jolis\n"
	.string "Pokémon!$"
