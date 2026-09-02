Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "Prenez votre envol, mes braves\n"
	.string "Pokémon!$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "J’ai envie de\n"
	.string "m’envoler à l’autre\p"
	.string "bout du monde\n"
	.string "avec mes Pokémon.$"

Route38_Text_BirdKeeperTobyAfter:
	.string "Je vais entraîner\n"
	.string "mes Pokémon à Irisia\p"
	.string "pour leur apprendre\n"
	.string "la capacité Vol.$"

Route38_Text_SchoolboyChad1Seen:
	.string "J'vais te montrer ce que j'ai\n"
	.string "appris aujourd'hui.$"

Route38_Text_SchoolboyChad1Beaten:
	.string "Faut que j'étudie encore un peu.$"

Route38_Text_SchoolboyChadAfter:
	.string "Les études ça me prend la tête.\p"
	.string "Je préfère les Pokémon.\p"
	.string "Alors moi, jouer, c'est mon\n"
	.string "truc.$"

Route38_Text_ChadRegister:
	.string "Les études ça me prend la tête.\p"
	.string "Je préfère les Pokémon.\p"
	.string "Alors moi, jouer, c'est mon\n"
	.string "truc.$"

Route38_Text_ChadRematchIntro:
	.string "J'vais te montrer ce que j'ai\n"
	.string "appris aujourd'hui.$"

Route38_Text_ChadRematchDefeat:
	.string "Faut que j'étudie encore un peu.$"

Route38_Text_ChadPostRematch:
	.string "Les études ça me prend la tête.\p"
	.string "Je préfère les Pokémon.\p"
	.string "Alors moi, jouer, c'est mon\n"
	.string "truc.$"

Route38_Text_LassDana1Seen:
	.string "Tu as l'air de t'y connaître en\n"
	.string "Pokémon.\p"
	.string "Tu veux bien me donner des\n"
	.string "conseils?$"

Route38_Text_LassDana1Beaten:
	.string "Je vois. C'est pas mal.$"

Route38_Text_LassDanaAfter:
	.string "Je vais te dire un truc...\p"
	.string "Le lait du RANCH MEUMEU est\n"
	.string "super bon.$"

Route38_Text_BeautyValerieSeen:
	.string "Hé! T’es mimi comme Dresseur! Je\n"
	.string "peux voir ton équipe de Pokémon?$"

Route38_Text_BeautyValerieBeaten:
	.string "Merci de me l’avoir montrée!$"

Route38_Text_BeautyValerieAfter:
	.string "Les Pokémon, ça me calme les\n"
	.string "nerfs.$"

Route38_Text_SailorHarrySeen:
	.string "Moi j’ai voyagé! Je connais\n"
	.string "plein de Pokémon!$"

Route38_Text_SailorHarryBeaten:
	.string "Cette force! Tu as un niveau\n"
	.string "mondial!$"

Route38_Text_SailorHarryAfter:
	.string "Les gens de toutes les contrées\n"
	.string "vivent heureux avec les Pokémon.$"

Route38_Text_BeautyOliviaSeen:
	.string "Tu ne trouves pas\n"
	.string "que mes Pokémon\p"
	.string "et moi-même avons\n"
	.string "une classe folle?$"

Route38_Text_BeautyOliviaBeaten:
	.string "On boit du LAIT MEUMEU tous les\n"
	.string "jours.$"

Route38_Text_BeautyOliviaAfter:
	.string "Le LAIT MEUMEU est bon pour la\n"
	.string "forme\p"
	.string "mais ils n'en vendent qu'une\p"
	.string "bouteille à la fois.$"

Route38_Text_Sign:
	.string "ROUTE 38\p"
	.string "OLIVILLE ROSALIA$"

Route38_Text_TrainerTips:
	.string "ASTUCE\p"
	.string "Vous pouvez arrêter l'évolution\n"
	.string "d' un Pokémon.\p"
	.string "Appuyez sur B pendant\n"
	.string "l'évolution.\p"
	.string "Cela surprendra le Pokémon et le\n"
	.string "fera s'arrêter.$"


Route38_Text_WaterSign:
	.string "BAIGNADE ET PÊCHE INTERDITES\n"
	.string "EAU RÉSERVÉE À L'AGRICULTURE\p"
	.string "-CONSEIL DE ROSALIA$"

Route38_Text_DanaRegister:
	.string "Je vais te dire un truc...\p"
	.string "Le lait du RANCH MEUMEU est\n"
	.string "super bon.$"

Route38_Text_DanaRematchIntro:
	.string "Tu as l'air de t'y connaître en\n"
	.string "Pokémon.\p"
	.string "Tu veux bien me donner des\n"
	.string "conseils?$"

Route38_Text_DanaRematchDefeat:
	.string "Je vois. C'est pas mal.$"

Route38_Text_DanaPostRematch:
	.string "Je vais te dire un truc...\p"
	.string "Le lait du RANCH MEUMEU est\n"
	.string "super bon.$"

Route38_Text_DanaHasItem:
	.string "Hé! J'ai trouvé quelque chose\n"
	.string "d'intéressant!\p"
	.string "Tiens, c'est pour toi!$"

Route38_Text_DanaGaveItem:
	.string "Je te préviendrai si je trouve\n"
	.string "autre chose!$"

Route38_Text_DanaNoRoom:
	.string "Hmm, ton SAC est plein.\p"
	.string "Reviens quand tu auras\n"
	.string "de la place.$"
