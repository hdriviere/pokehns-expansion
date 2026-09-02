Route44_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_HNS, Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten, Route44_EventScript_RegisterWilton
	goto_if_set FLAG_WILTON_HAS_ITEM_HNS, Route44_EventScript_WiltonGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchWilton
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_HNS
	release
	end

Route44_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_HNS, Route44_Text_WiltonRematchIntro, Route44_Text_WiltonRematchDefeat
	msgbox Route44_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonGiveItem::
	msgbox Route44_Text_WiltonHasItem, MSGBOX_DEFAULT
	giveitem VAR_WILTON_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route44_EventScript_WiltonNoRoom
	clearflag FLAG_WILTON_HAS_ITEM_HNS
	msgbox Route44_Text_WiltonGaveItem, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_WiltonNoRoom::
	msgbox Route44_Text_WiltonNoRoom, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR_HNS, Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE_HNS, Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten, Route44_EventScript_RegisterVance
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route44_EventScript_RematchVance
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_RegisterVance::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route44_Text_VanceRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VANCE_HNS
	release
	end

Route44_EventScript_RematchVance::
	trainerbattle_rematch TRAINER_VANCE_HNS, Route44_Text_VanceRematchIntro, Route44_Text_VanceRematchDefeat
	msgbox Route44_Text_VancePostRematch, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL_HNS, Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH_HNS, Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN_HNS, Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL_HNS, Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
    .string "Aaah! T’as fait fuir ce PTITARD\n"
    .string "juste quand j’allais l’attraper!\p"
    .string "Tu vas payer!$"

Route44_Text_FisherWilton1Beaten:
    .string "Je te pardonne.$"

Route44_Text_FisherWiltonHugePoliwag:
    .string "Ce PTITARD était énorme!\p"
    .string "Il faisait 5 mètres au moins!$"

Route44_Text_WiltonRegister:
    .string "Ce PTITARD était énorme!\p"
    .string "Il faisait 5 mètres au moins!$"

Route44_Text_WiltonRematchIntro:
    .string "Aaah! T’as fait fuir ce PTITARD\n"
    .string "juste quand j’allais l’attraper!\p"
    .string "Tu vas payer!$"

Route44_Text_WiltonRematchDefeat:
    .string "Je te pardonne.$"

Route44_Text_WiltonPostRematch:
    .string "Ce PTITARD était énorme!\p"
    .string "Il faisait 5 mètres au moins!$"

Route44_Text_WiltonHasItem:
	.string "Hé! J'ai pêché autre chose\n"
	.string "qu'un Pokémon!\p"
	.string "Tiens, c'est pour toi!$"

Route44_Text_WiltonGaveItem:
	.string "Je te préviendrai si je pêche\n"
	.string "autre chose!$"

Route44_Text_WiltonNoRoom:
	.string "Hmm, ton SAC est plein.\p"
	.string "Reviens quand tu auras\n"
	.string "de la place.$"

Route44_Text_FisherEdgarSeen:
    .string "Je pêche, je pêche,\n"
    .string "encore et encore!\p"
    .string "Je gagne, je gagne,\n"
    .string "toujours plus!\p"
    .string "C’est ça mon lien avec les\n"
    .string "Pokémon.$"

Route44_Text_FisherEdgarBeaten:
    .string "Hmmmm...$"

Route44_Text_FisherEdgarAfter:
    .string "100 victoires pour 101 défaites.\p"
    .string "La poisse! Je\n"
    .string "ferais mieux\p"
    .string "d’arrêter la casse\n"
    .string "dès maintenant.$"

Route44_Text_BirdKeeperVance1Seen:
    .string "Tu sais quoi que ce soit sur les\n"
    .string "Pokémon Oiseaux légendaires?$"

Route44_Text_BirdKeeperVance1Beaten:
    .string "Alors toi, tu rigoles pas!$"

Route44_Text_BirdKeeperVanceBirds:
    .string "ARTIKODIN, ELECTHOR et\p"
    .string "SULFURA sont les trois Pokémon\n"
    .string "oiseaux légendaires.\p"
    .string "On dit qu'il y en a d'autres...$"

Route44_Text_VanceRegister:
    .string "ARTIKODIN, ELECTHOR et\p"
    .string "SULFURA sont les trois Pokémon\n"
    .string "oiseaux légendaires.\p"
    .string "On dit qu'il y en a d'autres...$"

Route44_Text_VanceRematchIntro:
    .string "Tu sais quoi que ce soit sur les\n"
    .string "Pokémon Oiseaux légendaires?$"

Route44_Text_VanceRematchDefeat:
    .string "Alors toi, tu rigoles pas!$"

Route44_Text_VancePostRematch:
    .string "ARTIKODIN, ELECTHOR et\p"
    .string "SULFURA sont les trois Pokémon\n"
    .string "oiseaux légendaires.\p"
    .string "On dit qu'il y en a d'autres...$"

Route44_Text_PsychicPhilSeen:
    .string "J'vais gagner! Pour sûr!$"

Route44_Text_PsychicPhilBeaten:
    .string "Qu... Comm... Hein?$"

Route44_Text_PsychicPhilAfter:
    .string "Etre sûr de soi, c'est\n"
    .string "important.$"

Route44_Text_PokemaniacZachSeen:
    .string "Je veux des Pokémon rares, à\n"
    .string "n’importe quel prix!$"

Route44_Text_PokemaniacZachBeaten:
    .string "Oooh, la beeeelle équipe de\n"
    .string "Pokémon que voilà!$"

Route44_Text_PokemaniacZachAfter:
    .string "Si un Pokémon\n"
    .string "est d'une couleur\p"
    .string "inhabituelle, il\n"
    .string "a plus de valeur.\p"
    .string "Quoi? On m'aurait menti?$"

Route44_Text_CooltrainermAllenSeen:
    .string "Tu as du talent, ça se voit.\p"
    .string "Mais... Comment dire... J'suis\n"
    .string "le plus fort.$"

Route44_Text_CooltrainermAllenBeaten:
    .string "... Perdu, et en beauté!$"

Route44_Text_CooltrainermAllenAfter:
    .string "Whoa! Tous ces Badges!\p"
    .string "Au fait, tu sais\n"
    .string "si Mortimer de\p"
    .string "l’Arène de Rosalia\n"
    .string "s’entraîne toujours?\p"
    .string "Il m’a taillé en pièces la\n"
    .string "dernière fois.$"

Route44_Text_CooltrainerfCybilSeen:
    .string "Tu m’as l’air digne d’un combat.\p"
    .string "Un Dresseur a\n"
    .string "l’instinct pour\p"
    .string "repérer les challenges\n"
    .string "intéressants.$"

Route44_Text_CooltrainerfCybilBeaten:
    .string "Non, non et encore non!$"

Route44_Text_CooltrainerfCybilAfter:
    .string "Les combats forment la jeunesse.\p"
    .string "Moi j’ai beaucoup\n"
    .string "combattu et voilà\p"
    .string "le résultat: je\n"
    .string "suis Topdresseur.$"

Route44_Text_Sign1:
    .string "ROUTE 44 ROUTE DE GLACE Tout\n"
    .string "droit$"

Route44_Text_Sign2:
    .string "ROUTE 44\p"
    .string "ACAJOU EBENELLE$"
