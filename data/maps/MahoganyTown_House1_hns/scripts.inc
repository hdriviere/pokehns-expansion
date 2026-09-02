MahoganyTown_House1_hns_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 10, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "J'ai entendu dire qu'un LEVIATOR\n"
    .string "rouge est apparu au LAC.\p"
    .string "C'est bizarre... Même un\n"
    .string "LEVIATOR\p"
    .string "ordinaire est très rare dans ce\n"
    .string "LAC!$"

MahoganyRedGyaradosHouse_Text_Teacher:
    .string "Mon émission de radio préférée?\n"
    .string "La Poké Musique!$"

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "J’entends de drôles de rires à\n"
    .string "la radio ces derniers temps...\p"
    .string "Ça donne la chair de poule!$"
