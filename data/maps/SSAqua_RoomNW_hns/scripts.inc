SSAqua_RoomNW_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY_HNS, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD_HNS, SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY_HNS, SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "Ouaip. Moi j'suis un marin.\p"
	.string "Un vrai de vrai. Pur boeuf!\p"
	.string "J'suis grand. J'suis beau. Je\n"
	.string "sens le sable chaud.\p"
	.string "Oh! Tu m'écoutes? ...COMBAT!$"

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "Heu... Comment? De quoi?$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "Dans la mariiine,\n"
	.string "on n'est pas des\p"
	.string "p'tites filles!\n"
	.string "Dans la mariiine!$"

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "Hmm... Quel ennui... J’ai perdu\n"
	.string "une chose très précieuse...$"

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "J'le...trouve... ...pas!!!$"

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "Tant pis, j’abandonne. Ne perds\n"
	.string "pas ton temps, mon enfant!\p"
	.string "Ce n’est pas la peine de\n"
	.string "chercher.\p"
	.string "Oublie!$"

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "Ouaiiis! Le bol!$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "Ooooh! Pas d'bol!$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "J’ai trouvé une belle pièce dans\n"
	.string "ma chambre.\p"
	.string "Quelqu’un a dû la perdre...$"
