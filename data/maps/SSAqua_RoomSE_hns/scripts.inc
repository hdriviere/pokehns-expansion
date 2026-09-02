SSAqua_RoomSE_hns_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN_HNS, SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG_HNS, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
    .string "Un combat contre moi?$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
    .string "T'es balèze!$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
    .string "Tu voyages? Et ta maman, elle\n"
    .string "s’inquiète pas?$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
    .string "Tu nous prends pour des bébés?\n"
    .string "Ça va pas la tête!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
    .string "Oh! Perdu!$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
    .string "On est des filles! Pas des\n"
    .string "bébés! Compris?$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
    .string "On n'est pas des bébés mais des\n"
    .string "belles dames!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
    .string "Oh! Perdu!$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
    .string "Les enfants sont souvent plus\n"
    .string "malins que les adultes!$"
