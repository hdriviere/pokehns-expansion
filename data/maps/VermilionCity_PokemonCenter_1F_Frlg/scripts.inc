VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	setflag FLAG_GOT_VS_SEEKER
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
	.string "Deux POKéMON d'un même niveau\n"
	.string "sont différents.\p"
	.string "Un POKéMON élevé par un DRESSEUR\n"
	.string "est toujours plus fort qu'un\p"
	.string "POKéMON sauvage.$"

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
	.string "Mon POKéMON est empoisonné! Il\n"
	.string "est tombé dans les pommes\p"
	.string "pendant que je marchais!$"

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
	.string "C'est vrai qu'un POKéMON de haut\n"
	.string "niveau est très puissant…\p"
	.string "Mais tout POKéMON est vulnérable\n"
	.string "face à un certain élément.\p"
	.string "Il n'y a donc pas de POKéMON qui\n"
	.string "soit invincible.$"

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
	.string "T'as jamais eu envie de te\n"
	.string "battre avec quelqu'un que tu\p"
	.string "viens de\p"
	.string "voir? Je suis sûre que si!\p"
	.string "Et il y a des gens avec qui je\n"
	.string "veux combattre encore et encore.\p"
	.string "Alors j'utilise cet appareil.\n"
	.string "Tiens, prends-en un!$"

VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches::
	.string "Ça sert à trouver les DRESSEURS\n"
	.string "qui veulent une revanche.\p"
	.string "Mais avant de l'utiliser, il\n"
	.string "faut recharger ses batteries.$"

VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker::
	.string "Comment marche le CHERCHE VS?\n"
	.string "C'est pas compliqué.\p"
	.string "Quand il fonctionne, il envoie\n"
	.string "un signal que les DRESSEURS\p"
	.string "peuvent\p"
	.string "capter. Si un DRESSEUR veut un\n"
	.string "nouveau combat, il te le\p"
	.string "fera savoir. Charge ses\n"
	.string "batteries et utilise-le sur la\p"
	.string "route.$"
