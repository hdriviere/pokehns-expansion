Route28_House_hns_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_STEEL_WING, Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "Oh ben mince. Tu m'as trouvée.\p"
	.string "Ne parle de moi à personne.\p"
	.string "En échange je te donne ceci. Ca\n"
	.string "marche?$"

Route28House_Text_Celebrity2:
	.string "C'est dur d'être célèbre.\p"
	.string "On me poursuit. On me regarde.\p"
	.string "J'te jure... C'est dur!$"

Route28House_Text_Fearow:
	.string "RAPASDEPIC: Piiic!$"

