IndigoPlateau_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_PokemonCenter_OnFrame 
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Pokecenter_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 0, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 2, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 3, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 4, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 5, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 6, IndigoPlateau_PokemonCenter_Enter
	.2byte 0

IndigoPlateau_PokemonCenter_Enter::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setvar VAR_LEAGUE_STATE, 1
	end

IndigoPlateau_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU_HNS
	end


IndigoPlateau_EventScript_Cooltrainer::
	msgbox IndigoPlateau_Text_CooltrainerM, MSGBOX_NPC
	end

IndigoPlateau_EventScript_BlackBelt::
	msgbox IndigoPlateau_Text_Blackbelt, MSGBOX_NPC
	end

IndigoPlateau_EventScript_ShigyNinja::
	msgbox IndigoPlateau_Text_ShigyNinja, MSGBOX_NPC
	end

IndigoPlateau_Text_ShigyNinja:
	.string "Bravo d'être arrivé jusqu'ici!\p"
	.string "Au fil des ans, j'ai vu passer\n"
	.string "des tas de Dresseurs, tous aussi\l"
	.string "uniques les uns que les autres.\p"
	.string "Tu peux être fier d'être allé\n"
	.string "aussi loin!\p"
	.string "Maintenant, va les battre!$"

IndigoPlateau_Text_Blackbelt:
	.string "La LIGUE POKéMON n'accepte pas\n"
	.string "de nouveaux challengers pour le\l"
	.string "moment.\p"
	.string "Veuillez revenir plus tard.$"

IndigoPlateau_Text_CooltrainerM:
    .string "La Ligue Pokémon\n"
    .string "évalue ta capacité\p"
    .string "à vaincre tous\n"
    .string "les membres\p"
    .string "du terrible Conseil 4.\p"
    .string "Et si tu perds, tu dois tout\n"
    .string "recommencer depuis le début!$"

IndigoPlateau_EventScript_Silver::
	lock
	faceplayer 
	goto_if_set FLAG_DAILY_BEAT_SILVER, IndigoPlateau_EventScript_SilverBeat
	msgbox IndigoPlateau_Text_RivalEntrance1, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, IndigoPlateau_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, IndigoPlateau_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, IndigoPlateau_Silver_Battle_Chikorita
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BEAT_SILVER
	release
	end

IndigoPlateau_EventScript_SilverBeat::
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Text_RivalEntrance1:
    .string "Minute!\p"
    .string "Tu vas relever le défi de la\n"
    .string "LIGUE Pokémon?\p"
    .string "T'es pas bien dans ta tête, toi?\p"
    .string "Mes Pokémon surentraînés vont te\p"
    .string "casser les reins. C'est bon?\p"
    .string "{PLAYER}! COMBAAAAT!$"

IndigoPlateau_Text_RivalWin:
    .string "......\p"
    .string "OK. J'ai perdu...$"

IndigoPlateau_Text_RivalAfter:
    .string "....ZUT.... Encore perdu.\p"
    .string "Y'a un truc que je comprends\n"
    .string "pas. Faut qu'je pense.\p"
    .string "Et penser... Moi j'aime pas.$"

IndigoPlateau_EventScript_Psychic::
	lock
	faceplayer
	msgbox IndigoPlateau_Text_TeleportGuy1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_EventScript_PsychicTeleport
	msgbox IndigoPlateau_Text_TeleportGuyNo, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_EventScript_PsychicTeleport::
	msgbox IndigoPlateau_Text_TeleportGuyYes, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playbgm MUS_HG_NEW_BARK, FALSE
	delay 60
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	applymovement2 LOCALID_INDIGOPLATEAU_ABRA, IndigoPLateau_Movement_Abra
	waitmovement 0
	fadescreen FADE_TO_WHITE
	warpteleport MAP_NEW_BARK_TOWN_HNS, 20, 12
	waitstate
	release
	end
	
IndigoPLateau_Movement_Abra:
	jump_in_place_right
	jump_in_place_right
	step_end

IndigoPlateau_EventScript_Abra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	msgbox IndigoPlateau_Text_Abra, MSGBOX_DEFAULT
	waitmoncry
	release
	end

IndigoPlateau_Text_TeleportGuy1:
    .string "Ah! Tu défies le CONSEIL des 4?\p"
    .string "Tu crois avoir les épaules?\p"
    .string "Si tu veux encore t'entraîner,\n"
    .string "mon ABRA peut t'aider.\p"
    .string "Il peut te TELEPORTER chez toi.\p"
    .string "Veux-tu retourner chez toi?$"

IndigoPlateau_Text_TeleportGuyYes:
    .string "Très bien. Pense fort à ta\n"
    .string "maison.$"

IndigoPlateau_Text_TeleportGuyNo:
    .string "OK. Alors bon courage!$"

IndigoPlateau_Text_Abra:
    .string "ABRA: Aabra...$"
