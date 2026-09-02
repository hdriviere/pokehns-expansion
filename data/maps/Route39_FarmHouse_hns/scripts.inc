Route39_FarmHouse_hns_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "Ma chtite ECREMEUH m'donne plus\n"
	.string "eud' lait.\p"
	.string "Et pourtant qu'il était bien bon\n"
	.string "not'lait d'ici.\p"
	.string "Et tout eul'monde y veut à\n"
	.string "boire.\p"
	.string "Si j'en avais des BAIES à lui\n"
	.string "donner\p"
	.string "elle m'donnerait aussi du lait,\n"
	.string "par le fait.$"

Route39_Text_FarmerMBuyMilk:
	.string "Ca te dit du bon LAIT MEUMEU?\p"
	.string "C'est ma fierté et ma joie,\n"
	.string "poussin.\p"
	.string "Donnes-en à tes Pokémon pour en\n"
	.string "gagner des PV!\p"
	.string "Pour juste\n"
	.string "500¥\p"
	.string "je te l'offre.\n"
	.string "Pour sûr!$"

Route39_Text_FarmerMGotMilk:
	.string "A la tienne!$"

Route39_Text_FarmerMNoMoney:
	.string "Ayayaïe, t’as pas assez!$"

Route39_Text_FarmerMNoRoom:
	.string "T'as pas de place, mon poussin.$"

Route39_Text_FarmerMNoSale:
	.string "T’en veux pas? Bah, reviens plus\n"
	.string "tard!$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "Tu en veux une autre?$"

Route39_Text_GotMilk:
	.string "{PLAYER} obtient du LAIT MEUMEU.$"

Route39_Text_FarmerMMilking:
	.string "Bon, c’est l’heure de la\n"
	.string "traite...$"

Route39_Text_FarmerFInTrouble:
	.string "Notre lait est très à la mode à\n"
	.string "Kanto...\p"
	.string "Alors c’est\n"
	.string "un problème si\p"
	.string "l’ECREMEUH ne nous\n"
	.string "en donne plus...$"

Route39_Text_FarmerFHealedMiltank:
	.string "C’est grâce à toi\n"
	.string "que l’ECREMEUH\p"
	.string "a recommencé à\n"
	.string "donner du bon lait!\p"
	.string "Tiens, en remerciement!$"

Route39_Text_FarmerFSnatchSpeech:
	.string "Ça, c'est SAISIE.\p"
	.string "Cette capacité permet\n"
	.string "à un Pokémon de voler\l"
	.string "une capacité adversel"
	.string "juste avant son utilisation.\p"
	.string "Si plusieurs Pokémon utilisent\n"
	.string "SAISIE, seul le plus lent finira\l"
	.string "par voler la capacité.\p"
	.string "Utilise-la bien, mon chou.\n"
	.string "Tout est dans le timing.$"
