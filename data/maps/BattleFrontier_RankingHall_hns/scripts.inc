BattleFrontier_RankingHall_hns_MapScripts::
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_DomeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PikeRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords_hns::
	lockall
	setvar VAR_0x8005, RANKING_HALL_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords_hns
	end

BattleFrontier_RankingHall_EventScript_ShowRecords_hns::
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant_hns::
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign_hns::
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn_hns::
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hns::
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy_hnsNameOnList_hns::
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy_hns::
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall_hns:
	.string "Voici le HALL DE CLASSEMENT.\p"
	.string "Ici, nous immortalisons les\n"
	.string "DRESSEURS qui ont obtenu les\p"
	.string "meilleurs résultats dans la ZONE\n"
	.string "DE COMBAT.$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords_hns:
	.string "Records du DOME DE COMBAT, du\n"
	.string "REPTILE DE COMBAT et de l’USINE\p"
	.string "DE COMBAT.$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords_hns:
	.string "Records du PALACE DE COMBAT, du\n"
	.string "DOJO DE COMBAT et de la PYRAMIDE\p"
	.string "DE COMBAT.$"

BattleFrontier_RankingHall_Text_IsYourNameOnThisList_hns:
	.string "Salut, ton nom est sur la liste?$"

BattleFrontier_RankingHall_Text_WowThatsSuper_hns:
	.string "La chance!!! Moi, il faut que je\n"
	.string "m’entraîne plus!$"

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName_hns:
	.string "Ah oui?\p"
	.string "Si tu voyais le nom de tes amis\n"
	.string "ici, tu ferais sûrement plus\p"
	.string "d’efforts!$"

BattleFrontier_RankingHall_Text_MyNamesNotUpThere_hns:
	.string "Hum… Y a pas mon nom…\p"
	.string "Faut dire que j’ai participé à\n"
	.string "aucun défi, donc c’est plutôt\p"
	.string "normal…$"

