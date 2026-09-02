Route26_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE_HNS, Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN_HNS, Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten, Route26_EventScript_RegisterGaven
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchGaven
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterGaven::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_GavenRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GAVEN_HNS
	release
	end

Route26_EventScript_RematchGaven::
	trainerbattle_rematch TRAINER_GAVEN_HNS, Route26_Text_GavenRematchIntro, Route26_Text_GavenRematchDefeat
	msgbox Route26_Text_GavenPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE_HNS, Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_HNS, Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten, Route26_EventScript_RegisterBeth
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route26_EventScript_RematchBeth
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RegisterBeth::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route26_Text_BethRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BETH_HNS
	release
	end

Route26_EventScript_RematchBeth::
	trainerbattle_rematch TRAINER_BETH_HNS, Route26_Text_BethRematchIntro, Route26_Text_BethRematchDefeat
	msgbox Route26_Text_BethPostRematch, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD_HNS, Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "Je me prépare pour la LIGUE\n"
    .string "Pokémon.$"

Route26_Text_CooltrainermJakeBeaten:
    .string "Noooon!$"

Route26_Text_CooltrainermJakeAfter:
    .string "Si je ne m’entraîne\n"
    .string "pas plus, gagner\p"
    .string "à la Ligue paraît\n"
    .string "peu probable.\p"
    .string "D’autant plus qu’on\n"
    .string "dit que les membres\p"
    .string "du Conseil 4 sont\n"
    .string "bien plus forts que\p"
    .string "les Champions.$"

Route26_Text_CooltrainermGavenSeen:
    .string "C’est en participant\n"
    .string "à des combats\p"
    .string "difficiles que\n"
    .string "l’on progresse.$"

Route26_Text_CooltrainermGavenBeaten:
    .string "Gaah! Tu progresses là?$"

Route26_Text_CooltrainermGavenAfter:
    .string "Pour aller à la LIGUE Pokémon,\n"
    .string "tu\p"
    .string "dois traverser la ROUTE\n"
    .string "VICTOIRE.\p"
    .string "Mais ça ne sera pas facile.\p"
    .string "Presque personne ne va là-bas!$"

Route26_Text_GavenRegister:
    .string "Pour aller à la LIGUE Pokémon,\n"
    .string "tu\p"
    .string "dois traverser la ROUTE\n"
    .string "VICTOIRE.\p"
    .string "Mais ça ne sera pas facile.\p"
    .string "Presque personne ne va là-bas!$"

Route26_Text_GavenRematchIntro:
    .string "C’est en participant\n"
    .string "à des combats\p"
    .string "difficiles que\n"
    .string "l’on progresse.$"

Route26_Text_GavenRematchDefeat:
    .string "Gaah! Tu progresses là?$"

Route26_Text_GavenPostRematch:
    .string "Pour aller à la LIGUE Pokémon,\n"
    .string "tu\p"
    .string "dois traverser la ROUTE\n"
    .string "VICTOIRE.\p"
    .string "Mais ça ne sera pas facile.\p"
    .string "Presque personne ne va là-bas!$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Si tu es là, c’est que tu dois\n"
    .string "être un adversaire de valeur.\p"
    .string "Alors... Je ne retiendrai pas\n"
    .string "mes coups!$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "Mais... c’est... Incroyable!$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "Je pensais pourtant qu’en ayant\n"
    .string "battu huit Champions d’Arène...\p"
    .string "Je dois persévérer.$"

Route26_Text_CooltrainerfBethSeen:
    .string "J'ai perdu face à un type du nom\n"
    .string "de {RIVAL}.\p"
    .string "Il était fort mais...\p"
    .string "On aurait dit qu' il combattait\n"
    .string "pour sa vie...\p"
    .string "Ca me faisait de la peine pour\n"
    .string "ses Pokémon.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "Les Pokémon ne sont pas nos\n"
    .string "esclaves.$"

Route26_Text_CooltrainerfBethAfter:
    .string "Les Pokémon sont des amis pour\n"
    .string "la vie.$"

Route26_Text_BethRegister:
    .string "Les Pokémon sont des amis pour\n"
    .string "la vie.$"

Route26_Text_BethRematchIntro:
    .string "J'ai perdu face à un Dresseur\n"
    .string "du nom de {RIVAL}.\p"
    .string "Mais contre toi, je gagnerai!$"

Route26_Text_BethRematchDefeat:
    .string "Les Pokémon ne sont pas nos\n"
    .string "esclaves.$"

Route26_Text_BethPostRematch:
    .string "Les Pokémon sont des amis pour\n"
    .string "la vie.$"

Route26_Text_PsychicRichardSeen:
    .string "Whoa! Regarde-moi tous ces\n"
    .string "Badges! J’suis bluffé.\p"
    .string "Mais ça ne te suffit pas de les\n"
    .string "collectionner, hein?$"

Route26_Text_PsychicRichardBeaten:
    .string "Beau combat!$"

Route26_Text_PsychicRichardAfter:
    .string "C’est en vivant\n"
    .string "des expériences\p"
    .string "nouvelles que l’on\n"
    .string "évolue, humains\p"
    .string "comme Pokémon.\p"
    .string "Il faut s’entraîner et voyager!$"

Route26_Text_Sign:
    .string "ROUTE 26\p"
    .string "LIGUE Pokémon PORTE D'ACCES$"
