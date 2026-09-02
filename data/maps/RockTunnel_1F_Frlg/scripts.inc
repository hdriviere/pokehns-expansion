RockTunnel_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	.byte 0

RockTunnel_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
	.string "Il est long ce tunnel, oh oui!$"

RockTunnel_1F_Text_LennyDefeat::
	.string "Rôooh! T'as gagné!$"

RockTunnel_1F_Text_LennyPostBattle::
	.string "Attention aux ONIX! Ils\n"
	.string "apparaissent souvent ici.\p"
	.string "Ils pourraient facilement\n"
	.string "t'écrabouiller, fais attention!$"

RockTunnel_1F_Text_OliverIntro::
	.string "Bon, bon, bon, je suis perdu…$"

RockTunnel_1F_Text_OliverDefeat::
	.string "Hein? Par où je sors maintenant?$"

RockTunnel_1F_Text_OliverPostBattle::
	.string "Ce POKéMON endormi sur la route\n"
	.string "12 m'a obligé à faire un détour.$"

RockTunnel_1F_Text_LucasIntro::
	.string "Un profane comme toi me doit le\n"
	.string "respect!$"

RockTunnel_1F_Text_LucasDefeat::
	.string "Perdu!$"

RockTunnel_1F_Text_LucasPostBattle::
	.string "Tu as le niveau des meilleurs\n"
	.string "montagnards!$"

RockTunnel_1F_Text_AshtonIntro::
	.string "Baston POKéMON! C'est parti!$"

RockTunnel_1F_Text_AshtonDefeat::
	.string "Partie terminée!$"

RockTunnel_1F_Text_AshtonPostBattle::
	.string "Bon, il me faut un NOSFERAPTI!$"

RockTunnel_1F_Text_LeahIntro::
	.string "Hep!\p"
	.string "Dans le noir, fais gaffe où tu\n"
	.string "mets les pieds!$"

RockTunnel_1F_Text_LeahDefeat::
	.string "J'ai rien compris!$"

RockTunnel_1F_Text_LeahPostBattle::
	.string "J'ai vu un MACHOC dans ce\n"
	.string "tunnel!$"

RockTunnel_1F_Text_DanaIntro::
	.string "Je viens de loin pour ces\n"
	.string "POKéMON sauvages!$"

RockTunnel_1F_Text_DanaDefeat::
	.string "Oh! Plus de POKéMON!$"

RockTunnel_1F_Text_DanaPostBattle::
	.string "Dire que je pensais que tu ne\n"
	.string "savais pas te battre.$"

RockTunnel_1F_Text_ArianaIntro::
	.string "T'as des POKéMON! OK, bastooonn!$"

RockTunnel_1F_Text_ArianaDefeat::
	.string "T'es coriace toi!$"

RockTunnel_1F_Text_ArianaPostBattle::
	.string "Hé ben! Me voilà en sueur!$"

RockTunnel_1F_Text_RouteSign::
	.string "GROTTE AZURIA - LAVANVILLE$"
