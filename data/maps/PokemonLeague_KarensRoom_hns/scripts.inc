PokemonLeague_KarensRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2_HNS, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "MARION: Ah, te revoilà.\p"
    .string "J'espère que tu n'as pas oublié\n"
    .string "ma conviction:\p"
    .string "La vraie force naît de la\n"
    .string "confiance en ses Pokémon.\p"
    .string "Depuis notre dernière rencontre,\n"
    .string "le lien avec mes Pokémon s'est\l"
    .string "encore renforcé.\p"
    .string "Es-tu prêt face à mon équipe,\n"
    .string "unie par un lien indéfectible?\p"
    .string "Montre-moi la force du lien qui\n"
    .string "t'unit à tes Pokémon.$"

PokemonLeague_KarensRoom_Text_Before:
    .string "Je suis MARION du CONSEIL des 4.\p"
    .string "C'est toi {PLAYER}? C'est\n"
    .string "marrant.\p"
    .string "Moi j'aime les Pokémon des\n"
    .string "TENEBRES.\p"
    .string "Leur look noir et méchant est\p"
    .string "trop cool. Et ils sont forts\n"
    .string "aussi!\p"
    .string "Tu crois pouvoir les battre?\n"
    .string "Allez, essaie pour voir.\p"
    .string "C'est parti.$"

PokemonLeague_KarensRoom_Text_Beaten:
    .string "Vraiment, bien joué.  C’était\n"
    .string "tout bonnement exceptionnel.$"

PokemonLeague_KarensRoom_Text_Defeat:
    .string "Pokémon puissants.\p"
    .string "Pokémon faibles.\p"
    .string "Cette vision est faite pour les\n"
    .string "simples d'esprit.\p"
    .string "Les bons dresseurs gagnent avec\n"
    .string "leurs Pokémon favoris.\p"
    .string "J'aime ton style. Tu as du\n"
    .string "talent...\p"
    .string "Allez, va... Le MAITRE attend.$"
