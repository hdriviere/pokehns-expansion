Route41_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE_HNS, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "L'eau est bonne par ici.\p"
	.string "Tu veux combattre? Pas de\n"
	.string "problème!$"

Route41_Text_SwimmermCharlieBeaten:
	.string "J'suis tout fripé!$"

Route41_Text_SwimmermCharlieAfter:
	.string "C'est trop relax de faire la\n"
	.string "planche!$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE_HNS, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "J’suis fatigué. Si je gagne, tu\n"
	.string "me prêtes ton équipe, OK?$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "Pfff... pff...$"

Route41_Text_SwimmermGeorgeAfter:
	.string "Irisia est si loin.\n"
	.string "Mais c’est trop\p"
	.string "tard pour retourner\n"
	.string "à Oliville...\p"
	.string "Que faire?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE_HNS, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "Tu vois ces îles\n"
	.string "bloquées par les\p"
	.string "siphons? Sûr qu’elles\n"
	.string "ont un secret!$"

Route41_Text_SwimmermBerkeBeaten:
	.string "Pour avoir autant de force, t’as\n"
	.string "un secret toi aussi, obligé!$"

Route41_Text_SwimmermBerkeAfter:
	.string "Par une nuit noire et\n"
	.string "profonde...\p"
	.string "J'ai vu ce Pokémon géant voler\n"
	.string "depuis les îles.\p"
	.string "Il répandait ses plumes de ses\n"
	.string "ailes d'argent.$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_HNS, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Les vagues sont dangereuses ici.\p"
	.string "Elles empêchent de nager\n"
	.string "calmement.$"

Route41_Text_SwimmermKirkBeaten:
	.string "J'suis crevé!$"

Route41_Text_SwimmermKirkAfter:
	.string "Les courants m'empêchent\n"
	.string "d'atteindre cette île.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW_HNS, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "Tu cherches le secret des\n"
	.string "TOURB'ILES?$"

Route41_Text_SwimmermMathewBeaten:
	.string "Ooh!!! Quelle endurance!$"

Route41_Text_SwimmermMathewAfter:
	.string "Il y a un secret aux\n"
	.string "TOURB'ILES...\p"
	.string "Il y fait noir! Ca c'est sûr!$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE_HNS, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Je vais aux TOURB'ILES.\p"
	.string "Je vais les explorer avec un\n"
	.string "ami.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "Oh...? Ah bon.$"

Route41_Text_SwimmerfKayleeAfter:
	.string "On dit qu'il y a un gros Pokémon\n"
	.string "au fond des TOURB'ILES.\p"
	.string "Je me demande ce que c'est...$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE_HNS, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Cool, t'es à dada sur ton\n"
	.string "Pokémon.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "Quelle déception!$"

Route41_Text_SwimmerfSusieAfter:
	.string "Il n’y a pas une histoire avec\n"
	.string "un garçon monté sur un LOKHLASS?$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE_HNS, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "Il fait si beau! Quel plaisir!$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "Ohhh!$"

Route41_Text_SwimmerfDeniseAfter:
	.string "Un coup de soleil est vite\n"
	.string "arrivé.\p"
	.string "Moi je mets pas de crème.\p"
	.string "Je veux garder l'eau propre.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA_HNS, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Si tu es naze, fais la planche!\p"
	.string "Bon... On s'bat?$"

Route41_Text_SwimmerfKaraBeaten:
	.string "Oh! Tu en as de l'énergie, toi.$"

Route41_Text_SwimmerfKaraAfter:
	.string "J'entends des cris venant des\n"
	.string "ILES.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY_HNS, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "La nuit tombée, des\n"
	.string "STARI se réunissent\p"
	.string "à Oliville au\n"
	.string "bord de l’eau.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "Oh...$"

Route41_Text_SwimmerfWendyAfter:
	.string "Le cœur des STARI\n"
	.string "s’allume en même\p"
	.string "temps. C’est beau\n"
	.string "mais... ça fait peur.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "TENTACRUEL: Cruooo...$"

Route41_Text_TentacruelAttack:
	.string "TENTACRUEL: CRUOOOOOO!$"

Route41_Text_TentacruelHeal:
	.string "Le TENTACRUEL utilise SOIN!\n"
	.string "Il récupère toute son énergie!$"
