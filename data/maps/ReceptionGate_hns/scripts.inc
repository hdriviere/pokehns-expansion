ReceptionGate_hns_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
	.string "JEANNINE: Je vais chez mon père\n"
	.string "pour lui apporter son déjeuner.\p"
	.string "Le CONSEIL 4 n'a aucun répit,\n"
	.string "ni jour ni nuit. Quel travail\l"
	.string "épuisant, tu sais?\p"
	.string "Pour un autre combat, je serai\n"
	.string "au DOJO plus tard.$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 55
    waitmovement LOCALID_INDIGOJUNCTION_POLICEMAN
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "Seuls les dresseurs confirmés\n"
    .string "peuvent passer.$"

VictoryRoadGate_Text_Kimono:
	.string "Désolée, cette voie restera\n"
	.string "fermée tant que personne ne se\l"
	.string "sera occupé du Pokémon\l"
	.string "LÉGENDAIRE...$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "Tu n'as pas tous les BADGES\n"
    .string "d'ARENE de JOHTO.\p"
    .string "Je ne peux pas te laisser\n"
    .string "passer. Désolé.$"

VictoryRoadGate_Text_EightBadges:
    .string "Oh! Les huit BADGES de JOHTO!\p"
    .string "Après vous, votre altesse!$"

VictoryRoadGate_Text_LeftBlackBelt:
	.string "Cette voie mène au MONT ARGENT.\p"
	.string "Tu y verras des Pokémon d'une\n"
	.string "force terrifiante.$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "Tu vas à la LIGUE Pokémon, hein?\p"
    .string "Le CONSEIL des 4 est super hyper\p"
    .string "méga fort!!! Tu vas en baver!$"
