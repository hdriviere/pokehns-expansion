MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Professeur… Regardez les progrès\n"
	.string "que j’ai faits!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Professeur… Pardonnez-moi!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Mon prof, qui repose ici, ne\n"
	.string "trouvera la paix que lorsque\p"
	.string "j’aurai progressé…$"

