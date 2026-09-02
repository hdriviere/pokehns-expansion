MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "C’est ici que nous, adeptes des\n"
	.string "dragons, nous entraînons.\p"
	.string "Même le MAITRE nous a rendu\n"
	.string "visite. Tu vois comme c’est\p"
	.string "spécial ici?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Arrgh! Je n’imaginais pas ta\n"
	.string "force si grande!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "La route est encore longue et\n"
	.string "difficile.\p"
	.string "Quand deviendrons-nous les\n"
	.string "meilleurs, mes POKéMON et moi?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Je veux en savoir plus sur ta\n"
	.string "puissance. Laisse-moi\p"
	.string "t’enregistrer dans mon POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Depuis notre rencontre, on s’est\n"
	.string "entraînés dur pour devenir\p"
	.string "numéro un.\p"
	.string "Donne-nous la possibilité de\n"
	.string "voir à quel point notre\p"
	.string "puissance a augmenté!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Arrgh! Je n’imaginais pas ta\n"
	.string "force si grande!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Il est évident que tu as\n"
	.string "poursuivi l’entraînement de tes\p"
	.string "POKéMON.\p"
	.string "Aussi longtemps que tu seras\n"
	.string "solide, je pourrai, moi aussi,\p"
	.string "l’être davantage!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: On a toujours fait des\n"
	.string "combats de POKéMON ensemble.\p"
	.string "On a confiance l’un en l’autre.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: Oh, non! On a perdu, ma\n"
	.string "douce.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Et il faut que je livre un\n"
	.string "combat contre ma propre femme.\p"
	.string "Tu imagines?$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Eh bien, quel jeune\n"
	.string "DRESSEUR!\p"
	.string "Tu veux te battre avec nous? Si\n"
	.string "oui, il faudra revenir avec plus\p"
	.string "de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: Jeune DRESSEUR, nous\n"
	.string "affronteras-tu de nouveau si la\p"
	.string "chance se présente?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Le lien qui nous unit en tant\n"
	.string "que couple ne pourra jamais être\p"
	.string "rompu.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: Oh non! On a perdu, mon\n"
	.string "cher époux.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Cinquante ans de mariage…\p"
	.string "Quand on n’est pas d’accord, on\n"
	.string "règle toujours ça par un combat\p"
	.string "de POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Tu es un jeune DRESSEUR,\n"
	.string "hein?\p"
	.string "Pour te battre contre nous, il\n"
	.string "faut que tu reviennes avec plus\p"
	.string "de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: On a toujours fait des\n"
	.string "combats de POKéMON ensemble.\p"
	.string "On a confiance l’un en l’autre.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: Oh, non! On a perdu, ma\n"
	.string "douce.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Cinquante ans de mariage…\p"
	.string "A la réflexion, ma chère femme\n"
	.string "et moi, on s’est battus jour\p"
	.string "après jour…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Eh bien, quel jeune\n"
	.string "DRESSEUR!\p"
	.string "Tu veux te battre avec nous? Si\n"
	.string "oui, il faudra revenir avec plus\p"
	.string "de POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "On s’est toujours soutenus. Ça\n"
	.string "nous a rendus forts.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: Oh non! On a perdu, mon\n"
	.string "cher époux.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Cinquante ans de mariage…\n"
	.string "Tellement de choses se sont\p"
	.string "passées!\p"
	.string "J’espère que l’on va encore\n"
	.string "avoir de bons souvenirs\p"
	.string "ensemble.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Tu es un jeune DRESSEUR,\n"
	.string "hein?\p"
	.string "Pour te battre contre nous, il\n"
	.string "faut que tu reviennes avec plus\p"
	.string "de POKéMON.$"

