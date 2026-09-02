MtMortar_1F_North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Protector::
    finditem ITEM_PROTECTOR
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER_HNS, MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS_HNS, MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "Cette fois, c’est la bonne!$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "Perdu...?$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "L'autre jour, un type du genre\p"
	.string "karaté kid voulait se battre...\n"
	.string "Il était fort.\p"
	.string "Y nous a tout cassé la tête.\p"
	.string "Il a continué son chemin en\n"
	.string "disant\p"
	.string "qu'il s'entraînait.$"

MountMortar2_Text_SupernerdMarkusSeen:
	.string "Hé! Guillaume!$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "Mince! C’était pas la bonne\n"
	.string "personne...$"

MountMortar2_Text_SupernerdMarkusAfter:
	.string "Je suis venu explorer le MONT\p"
	.string "CREUSET mais mon partenaire a\n"
	.string "disparu...\p"
	.string "As-tu vu un dresseur avec un\p"
	.string "HYPOCEAN qui lance CASCADE?$"
