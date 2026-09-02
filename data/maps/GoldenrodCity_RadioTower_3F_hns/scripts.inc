GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "Un lecteur de CARTE MAGN.$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER} insère la Carte\n"
	.string "Magnétique.$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "La porte est ouverte.$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "2{SUPER_E}: Personnel$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "MUSIQUE Pokémon avec DJ BEN$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "Nous avons un  enregistrement de\p"
	.string "tous les cris de Pokémon connus.\p"
	.string "Nous en avons près de 200\n"
	.string "différents.$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "Les Pokémon sont les partenaires\n"
	.string "chéris des Dresseurs, non?\p"
	.string "C’est vraiment\n"
	.string "affreux d’ordonner\p"
	.string "des choses\n"
	.string "aussi horribles\p"
	.string "aux Pokémon!$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "Nous diffusons\n"
	.string "des émissions\p"
	.string "distrayantes sans\n"
	.string "jamais nous arrêter.\p"
	.string "Je vais essayer de garder le\n"
	.string "micro 24 heures sur 24!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "Leur chef s’est barricadé\n"
	.string "derrière cette porte.\p"
	.string "Mais le directeur peut l’ouvrir!\n"
	.string "Il est au 4{SUPER_E}...\p"
	.string "Sauve-le! Par pitié!$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "Le directeur est-il en sécurité?$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "Merci! Tu es trop cool!\p"
	.string "Prends ceci en récompense.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "Elle renferme Zénith.\n"
	.string "En l’utilisant,\p"
	.string "tu renforces\n"
	.string "temporairement\p"
	.string "les capacités de type Feu.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "C’était vraiment du grand\n"
	.string "spectacle!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "On m’a donné des ordres précis.\p"
	.string "Je dois éliminer\n"
	.string "tous ceux qui se\p"
	.string "dressent contre\n"
	.string "la Team Rocket!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "De quoi?!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "J'ai échoué dans ma mission…\p"
	.string "AMOS va être furieux…$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "Quel plaisir de commander les\n"
	.string "Pokémon pour le crime!$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "Arrête ça!$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "Pfff... Je me sens super\n"
	.string "inutile!\p"
	.string "Mes Pokémon sont nuls et moches!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "Pourquoi le truc s'est ouvert?\p"
	.string "C'est toi qui as fait ça?$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "J'suis fichu!$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "Quoi?! Tu as échappé à nos\n"
	.string "hommes du SOUTERRAIN?\p"
	.string "Comment t'as fait?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "Quelqu’un que je ne connais pas\n"
	.string "qui se balade? T’es qui toi?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "Psss! J'faisais pas attention!$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "Bwahahaha... Cet\n"
	.string "endroit est parfait\p"
	.string "pour diffuser nos\n"
	.string "ondes partout...$"
