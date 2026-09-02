AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Les bateaux de ce genre sont\n"
	.string "rares, alors je vais y jeter un\p"
	.string "coup d’œil.\p"
	.string "Hum… On dirait qu’il y a\n"
	.string "d’autres cabines…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Qu’est-ce qui a bien pu te\n"
	.string "pousser à venir ici?\p"
	.string "Tu ne sais pas que la curiosité\n"
	.string "est un vilain défaut?$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Et plutôt tenace en plus de ça!$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "L’homme d’à côté…\p"
	.string "Il dit qu’il est juste là pour\n"
	.string "voir le paysage, mais j’ai du\p"
	.string "mal à le croire.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Tu es si jeune pour un DRESSEUR!\n"
	.string "Laisse-moi t’enregistrer!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Qu’est-ce qui a bien pu te\n"
	.string "pousser à revenir ici?\p"
	.string "Quelle curiosité, ma parole!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "C’est normal d’avoir tant de\n"
	.string "force dans un si petit corps?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Je suis sûre que cet homme\n"
	.string "cherche quelque chose. Il est\p"
	.string "vraiment étrange!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah! Tu m’as trouvé!$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, t’es pas ma maman toi!$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "J’ai peur de me faire gronder,\n"
	.string "alors je me cache…\p"
	.string "Tu diras rien, d’accord?$"

