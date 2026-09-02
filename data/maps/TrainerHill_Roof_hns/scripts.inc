TrainerHill_Roof_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Roof_hns_OnLoad
	.byte 0

TrainerHill_Roof_hns_OnLoad::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

TrainerHill_Roof_hns_EventScript_Owner::
	trainerhill_settrainerflags
	lock
	faceplayer
	trainerhill_getownerstate
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_Arrived
	case 1, TrainerHill_Roof_hns_EventScript_GivePrize
	case 2, TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize
TrainerHill_Roof_hns_EventScript_Arrived::
	msgbox TrainerHill_Roof_hns_Text_YouFinallyCameBravo, MSGBOX_DEFAULT
TrainerHill_Roof_hns_EventScript_GivePrize::
	trainerhill_giveprize
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_ReceivePrize
	case 1, TrainerHill_Roof_hns_EventScript_NoRoomForPrize
	case 2, TrainerHill_Roof_hns_EventScript_CheckFinalTime
TrainerHill_Roof_hns_EventScript_ReceivePrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_NoRoomForPrize::
	msgbox TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift, MSGBOX_DEFAULT
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	msgbox TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_CheckFinalTime

TrainerHill_Roof_hns_EventScript_CheckFinalTime::
	trainerhill_finaltime
	switch VAR_RESULT
	case 0, TrainerHill_Roof_hns_EventScript_NewRecord
	case 1, TrainerHill_Roof_hns_EventScript_NoNewRecord
	case 2, TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
TrainerHill_Roof_hns_EventScript_NewRecord::
	msgbox TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_NoNewRecord::
	msgbox TrainerHill_Roof_hns_Text_YouWerentVeryQuick, MSGBOX_DEFAULT
	goto TrainerHill_Roof_hns_EventScript_EndSpeakToOwner
	end

TrainerHill_Roof_hns_EventScript_EndSpeakToOwner::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_EventScript_AlreadyReceivedPrize::
	msgbox TrainerHill_Roof_hns_Text_ArriveZippierNextTime, MSGBOX_DEFAULT
	release
	end

TrainerHill_Roof_hns_Text_YouFinallyCameBravo:
	.string "Hum! Hum!\p"
	.string "Te voilà enfin! Oui, te voilà!\p"
	.string "Non, ne dis rien! Je sais\n"
	.string "pourquoi tu as fait tout ce\p"
	.string "chemin!\p"
	.string "Tu voulais me voir, moi le\n"
	.string "propriétaire du MONT DRESSEURS…\p"
	.string "Tu veux faire équipe avec moi!\n"
	.string "Youhou!\p"
	.string "Hein? Ah non?\p"
	.string "En tout cas, tu as fait de très\n"
	.string "beaux combats pour arriver ici!\p"
	.string "Bravo!$"

TrainerHill_Roof_hns_Text_HaveTheMostMarvelousGift:
	.string "Pour une personne aussi\n"
	.string "merveilleuse que vous, j'ai un\p"
	.string "cadeau tout aussi merveilleux,\n"
	.string "plus de l'argent pour vos\p"
	.string "efforts!$"

TrainerHill_Roof_hns_Text_FullUpBeBackLaterForThis:
	.string "Oh? Ton SAC est carrément plein.\n"
	.string "J’attendrai que tu reviennes!$"

TrainerHill_Roof_hns_Text_GotHereMarvelouslyQuickly:
	.string "Oh… Avec quelle rapidité tu as\n"
	.string "grimpé jusqu’ici!\p"
	.string "C’est formidable! Tu avais\n"
	.string "vraiment hâte de me voir!\p"
	.string "Ça me fait très plaisir. Ton\n"
	.string "temps va être reporté sur le\p"
	.string "Panneau des Temps!$"

TrainerHill_Roof_hns_Text_YouWerentVeryQuick:
	.string "Mais, quel dommage… Tu n’as pas\n"
	.string "été assez rapide.$"

TrainerHill_Roof_hns_Text_ArriveZippierNextTime:
	.string "Je pense que ça me ferait encore\n"
	.string "plus plaisir si tu étais encore\p"
	.string "plus rapide.\p"
	.string "Ensuite, je serais ravi de\n"
	.string "devenir ton partenaire!\p"
	.string "Nous nous reverrons!$"
