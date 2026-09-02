PokemonLeague_KogasRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_2_HNS, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "KOGA: Fwahahahaha!\p"
    .string "Te revoilà, brave challenger.\p"
    .string "Mes talents de ninja se sont\n"
    .string "encore affûtés.\p"
    .string "De nouveaux pièges sournois\n"
    .string "t'attendent.\p"
    .string "Poison, sommeil et bien plus...\n"
    .string "Tiens-toi prêt!\p"
    .string "Fwahahahaha!\p"
    .string "Montre-moi tes progrès!$"

PokemonLeague_KogasRoom_Text_Before:
    .string "Fwahahahaha!\p"
    .string "Moi c'est KOGA du CONSEIL des 4.\p"
    .string "J'suis un ninja! Comme à la\n"
    .string "télé!\p"
    .string "Je saute, je lance des\n"
    .string "shurikens... J'suis trop fort!\p"
    .string "Mais c'est pas tout...\p"
    .string "Tu vas voir ce que c'est la\n"
    .string "technique de maître!\p"
    .string "Fwahahahaha!\p"
    .string "La force c'est bien,\n"
    .string "mais le poison, le\p"
    .string "sommeil et la folie,\n"
    .string "c'est terrible!$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "Hmmm... Tu es un honorable\n"
    .string "adversaire.$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "J'ai combattu de toutes mes\n"
    .string "forces mais...\p"
    .string "Y'a pas moyen. Je ne suis pas\n"
    .string "assez fort.\p"
    .string "Va dans la prochaine salle.\n"
    .string "Bonne chance!$"
