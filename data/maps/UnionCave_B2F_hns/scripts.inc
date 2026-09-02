UnionCave_B2F_hns_MapScripts::
	.byte 0

UnionCave_B2F_EventScript_CooltrainerNick::
	trainerbattle_single TRAINER_NICK_HNS, UnionCave_B2F_Text_CooltrainermNickSeen, UnionCave_B2F_Text_CooltrainermNickBeaten
	msgbox UnionCave_B2F_Text_CooltrainermNickAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfGwen::
	trainerbattle_single TRAINER_GWEN_HNS, UnionCave_B2F_Text_CooltrainerfGwenSeen, UnionCave_B2F_Text_CooltrainerfGwenBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfGwenAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_CooltrainerfEmma::
	trainerbattle_single TRAINER_EMMA_HNS, UnionCave_B2F_Text_CooltrainerfEmmaSeen, UnionCave_B2F_Text_CooltrainerfEmmaBeaten
	msgbox UnionCave_B2F_Text_CooltrainerfEmmaAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B2F_EventScript_Lapras::
	lock
	faceplayer
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_LAPRAS, 20
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, UnionCave_B2F_EventScript_LaprasRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_UNION_CAVE_LAPRAS
	setflag FLAG_HIDE_UNION_CAVE_LAPRAS
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

UnionCave_B2F_EventScript_LaprasRan::
	release
	end


UnionCave_B2F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

UnionCave_B2F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

UnionCave_B2F_EventScript_Item_MaxRevive::
	finditem ITEM_MAX_REVIVE
	end

UnionCave_B2F_Text_CooltrainermNickSeen:
	.string "Il existe 2 types de personnes.\p"
	.string "Ceux qui ont la classe, et ceux\n"
	.string "qui l'ont pas.\p"
	.string "Toi... T'as la classe?$"

UnionCave_B2F_Text_CooltrainermNickBeaten:
	.string "Eblouissant!$"

UnionCave_B2F_Text_CooltrainermNickAfter:
	.string "Tes Pokémon ont la super classe!\n"
	.string "Et c'est bien.\p"
	.string "Et tu vas encore t'améliorer!$"

UnionCave_B2F_Text_CooltrainerfGwenSeen:
	.string "Je m’entraîne. Ça te tente?$"

UnionCave_B2F_Text_CooltrainerfGwenBeaten:
	.string "Aaah, ça suffit! T’es trop\n"
	.string "balèze pour moi!$"

UnionCave_B2F_Text_CooltrainerfGwenAfter:
	.string "Je vais continuer à m’entraîner\n"
	.string "seule!$"

UnionCave_B2F_Text_CooltrainerfEmmaSeen:
	.string "J'irais n'importe où avec le\n"
	.string "Pokémon de mes rêves.\p"
	.string "C'est ça la beauté d'être\n"
	.string "dresseur.$"

UnionCave_B2F_Text_CooltrainerfEmmaBeaten:
	.string "Vive l'amour! Vive les fleurs!$"

UnionCave_B2F_Text_CooltrainerfEmmaAfter:
	.string "Une fois par semaine, un Pokémon\n"
	.string "vient au bord de l’eau.\p"
	.string "Je veux le voir, ce Pokémon!!!$"
