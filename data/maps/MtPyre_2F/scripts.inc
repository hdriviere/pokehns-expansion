MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Souvenirs de mon cher SKITTY… A\n"
	.string "sa pensée, les larmes me\p"
	.string "viennent.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ouille, ouille… Des trous\n"
	.string "parsèment le sol ici et là.\p"
	.string "J’avais pas fait attention et je\n"
	.string "suis tombé de l’étage du dessus.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hé! Tu cherches des POKéMON?\n"
	.string "Alors tu m’as trouvé! Quelle\p"
	.string "audace!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Aïïïïe! Désolé, excuse-moi, je\n"
	.string "t’en prie!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Les gens venant rarement ici, je\n"
	.string "me disais qu’il y aurait des\p"
	.string "POKéMON rares.$"

MtPyre_2F_Text_LukeIntro:
	.string "KARL: C’est un défi.\p"
	.string "Hé, si je lui prouve que je suis\n"
	.string "génial, elle tombera amoureuse\p"
	.string "de moi. Je l’sais!\p"
	.string "Je sais! Je vais te mettre la\n"
	.string "pâtée pour lui montrer que je\p"
	.string "suis génial!$"

MtPyre_2F_Text_LukeDefeat:
	.string "KARL: Oh là là!$"

MtPyre_2F_Text_LukePostBattle:
	.string "KARL: On a perdu, mais c’est pas\n"
	.string "grave!\p"
	.string "Je reste avec toi, on va y\n"
	.string "arriver!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "KARL: Si tu veux m’affronter,\n"
	.string "apporte plus de POKéMON.\p"
	.string "Sinon, je ne pourrai pas montrer\n"
	.string "à ma copine à quel point je suis\p"
	.string "génial!$"

MtPyre_2F_Text_DezIntro:
	.string "ANNIE: Si je suis là, c’est\n"
	.string "parce qu’on a fait un pari avec\p"
	.string "mon petit ami.\p"
	.string "C’est effrayant, mais comme je\n"
	.string "suis avec mon petit ami, ça va.\p"
	.string "Je sais! Mon petit ami va être\n"
	.string "craquant quand il va te battre!$"

MtPyre_2F_Text_DezDefeat:
	.string "ANNIE: Aaaaah! J’ai peur!$"

MtPyre_2F_Text_DezPostBattle:
	.string "ANNIE: On s’aime tendrement,\n"
	.string "alors on s’en fiche de perdre!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "ANNIE: Pour nous affronter, il\n"
	.string "faut que tu aies au moins deux\p"
	.string "POKéMON.\p"
	.string "Mon petit ami est fort. Un seul\n"
	.string "POKéMON, ça ne suffira pas!$"

MtPyre_2F_Text_LeahIntro:
	.string "Je pressens un malheur… Pars\n"
	.string "avant qu’il ne soit trop tard!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Humm… Plutôt coriace!$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Dans ma famille, nous sommes\n"
	.string "DRESSEURS depuis des\p"
	.string "générations…\p"
	.string "Il est de mon devoir de protéger\n"
	.string "cette montagne…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Aaaaah! Je suis terrifié!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Nooon! J’ai perdu toute\n"
	.string "confiance en moi!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "J’ai peur dès que je vois\n"
	.string "quelque chose bouger…\p"
	.string "Je n’aurais pas dû venir\n"
	.string "m’entraîner ici…$"

