UnionCave_B1F_hns_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP_HNS, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD_HNS, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW_HNS, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN_HNS, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "Ça fait longtemps\n"
	.string "que je n’ai pas eu\p"
	.string "de compagnie. Un\n"
	.string "combat à l’improviste?$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "Uurggh...$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "Je suis perdu depuis longtemps!\p"
	.string "C'est pas trop grave mais...\n"
	.string "J'ai faim!$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "De la visite, ça faisait\n"
	.string "longtemps!$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "Wahahah! T'es pas drôle!$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "Je vis ici.\p"
	.string "Toi aussi tu veux vivre ici?\p"
	.string "Y'a de la place... Alors tu\n"
	.string "veux?$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "Qui va là? Yaaah! Laissez-nous\n"
	.string "tranquilles, moi et mon Pokémon!$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "Va-t'en... Ouste!$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "Seul avec mes Pokémon. C'est la\n"
	.string "fête.$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "Je suis venu ici pour mes études\n"
	.string "sur les Pokémon.\p"
	.string "Je vais te montrer mes\n"
	.string "résultats... en direct!$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "Plein la tête! Ouille!$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "Je vais révéler mes recherches\n"
	.string "au monde.\p"
	.string "Je serai aussi célèbre que le\n"
	.string "PROF.ORME!$"
