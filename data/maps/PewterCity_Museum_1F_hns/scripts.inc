PewterCity_Museum_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "Bienvenue!\p"
	.string "En ce moment, nos\n"
	.string "plus belles pièces\p"
	.string "ont été prêtées à\n"
	.string "un autre musée...\p"
	.string "Pour cette raison\n"
	.string "exceptionnelle,\p"
	.string "l’entrée de notre\n"
	.string "musée est gratuite!\p"
	.string "Je vous en prie, entrez!$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "Vous devez être un Dresseur\n"
	.string "aguerri.\p"
	.string "Nous n'avons guère besoin des\n"
	.string "fossiles posés sur ce comptoir.\p"
	.string "Un étrange homme aux cheveux\n"
	.string "argentés nous en a déposé\l"
	.string "tout un tas.\p"
	.string "Prenez-les si vous le souhaitez.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "Nous partageons souvent nos\n"
	.string "recherches avec les savants\l"
	.string "des RUINES D'ALPHA.\p"
	.string "Nous échangeons même avec eux\n"
	.string "des fossiles par PC!$"

PewterCity_Museum_1F_Text_Oldman:
	.string "Quelle joie! Quel honneur!\p"
	.string "Pouvoir ainsi adorer les\n"
	.string "ossements des divinités dragons!$"

PewterCity_Museum_1F_Text_Bones:
	.string "Ossements d'un ancien Pokémon\n"
	.string "dragon.$"
