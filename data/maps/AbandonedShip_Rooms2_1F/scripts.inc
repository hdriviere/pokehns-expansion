AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "JOE: En cherchant des trésors,\n"
	.string "on a découvert un DRESSEUR!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "JOE: On n’a pas réussi à gagner,\n"
	.string "même en se mettant ensemble…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "JOE: On n’a pas trouvé de\n"
	.string "trésors… Quelqu’un les aurait-il\p"
	.string "déjà pris?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "JOE: Tu n’as même pas deux\n"
	.string "POKéMON. N’espère pas nous\p"
	.string "battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "RITA: Oh?! On cherchait des\n"
	.string "trésors, mais on n’a trouvé\p"
	.string "qu’un DRESSEUR.$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "RITA: Oh, waouh, quelle force!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "RITA: Je me demande où les\n"
	.string "trésors peuvent bien être\p"
	.string "cachés.\p"
	.string "Je sais déjà ce que je vais\n"
	.string "m’acheter quand on les aura\p"
	.string "trouvés!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "RITA: Tu n’as pas deux POKéMON?\n"
	.string "On se battra une autre fois\p"
	.string "alors!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "RITA: Tu m’as mise en colère! Je\n"
	.string "vais t’enregistrer pour la\p"
	.string "peine!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "JOE: On a passé tout ce temps à\n"
	.string "chercher des trésors.\p"
	.string "Nos POKéMON sont devenus plus\n"
	.string "forts. On t’fait voir, OK?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "JOE: Toujours autant de force!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "JOE: On n’a pas trouvé de\n"
	.string "trésors, on a perdu notre combat\p"
	.string "de POKéMON…\p"
	.string "Je veux rentrer à la maison…\n"
	.string "Mais si je dis ça, elle va m’en\p"
	.string "vouloir…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "JOE: Tu n’as même pas deux\n"
	.string "POKéMON. N’espère pas nous\p"
	.string "battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "RITA: Oh, salut! Comme on\n"
	.string "s’retrouve!\p"
	.string "Tout comme nous, t’as pas arrêté\n"
	.string "de chercher des trésors!\p"
	.string "Si on se battait? Et le perdant\n"
	.string "arrête de chercher!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "RITA: Oh, on a encore perdu…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "RITA: On va élever le niveau de\n"
	.string "nos POKéMON.\p"
	.string "Et on ne rentrera pas à la\n"
	.string "maison avant d’avoir trouvé des\p"
	.string "trésors!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "RITA: Tu n’as pas deux POKéMON?\n"
	.string "On se battra une autre fois\p"
	.string "alors!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Je ne sais pas bien nager, mais\n"
	.string "quand il s’agit de se battre…$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oups, ça n’a pas vraiment bien\n"
	.string "marché.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Ça ne se fait pas vraiment de\n"
	.string "marcher pieds nus sur un bateau.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Force et compassion… Ce sont les\n"
	.string "trésors d’un DRESSEUR!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Quelque chose brille en toi, ça\n"
	.string "se voit tout de suite.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "J’ai vu quelque chose briller\n"
	.string "dans une des cabines du bateau.$"
