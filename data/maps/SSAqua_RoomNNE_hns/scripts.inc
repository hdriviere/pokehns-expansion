SSAqua_RoomNNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNNE_EventScript_Sean::
	trainerbattle_single TRAINER_SEAN_HNS, SSAqua_RoomNNE_Text_CooltrainermSeanSeen, SSAqua_RoomNNE_Text_CooltrainermSeanBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL_HNS, SSAqua_RoomNNE_Text_CooltrainerfCarolSeen, SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten
	msgbox SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNNE_Text_CooltrainermSeanSeen:
    .string "Je vais à KANTO pour\n"
    .string "m'entraîner.$"

SSAqua_RoomNNE_Text_CooltrainermSeanBeaten:
    .string "J'voulais gagner!$"

SSAqua_RoomNNE_Text_CooltrainermSeanAfterBattle:
    .string "Les Dresseurs de\n"
    .string "Johto peuvent eux\p"
    .string "aussi affronter\n"
    .string "les Champions\p"
    .string "de Kanto!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolSeen:
    .string "J'm'entraîne pour être la\n"
    .string "meilleure!$"

SSAqua_RoomNNE_Text_CooltrainerfCarolBeaten:
    .string "Mais où réside la différence\n"
    .string "entre toi et moi?$"

SSAqua_RoomNNE_Text_CooltrainerfCarolAfterBattle:
    .string "Je te battrai un jour! Oh oui!$"
