SSAqua_RoomNE_hns_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND_HNS, SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_HNS, SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "Y’a personne avec toi? Alors...\n"
    .string "TAÏAUT!$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "C’est trop pour moi.$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "Tu crois qu'il y a de belles\n"
    .string "montagnes à KANTO?$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "Tu connais PETRA? C'est un super\n"
    .string "DJ de KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "Gyaaaah!$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "PETRA est cool mais LULA est\n"
    .string "top!\p"
    .string "J'veux connaître les stations de\n"
    .string "radio de JOHTO!$"
