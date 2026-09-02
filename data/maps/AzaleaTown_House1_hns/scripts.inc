AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "Tous les RAMOLOSS ont disparu\n"
	.string "d’ici...\p"
	.string "La divinité de la forêt\n"
	.string "serait-elle en colère?\p"
	.string "En tous cas, c’est\n"
	.string "un mauvais présage.\p"
	.string "Mieux vaut se\n"
	.string "tenir tranquille...$"

CharcoalKiln_Text_Boss2:
	.string "Les RAMOLOSS sont revenus…$"

CharcoalKiln_Text_Boss3:
	.string "Les RAMOLOSS sont de retour...\p"
	.string "Mais mon APPRENTI n'est pas\n"
	.string "revenu du BOIS AUX CHENES.\p"
	.string "Où est donc ce dresseur de\n"
	.string "troisième zone?$"

CharcoalKiln_Text_Boss4:
	.string "Eh bien! Tu as chassé\n"
	.string "la Team Rocket et\p"
	.string "tu as pénétré dans\n"
	.string "le Bois aux Chênes\p"
	.string "sans la moindre crainte! Tu me\n"
	.string "plais!\p"
	.string "Ça te dirait de t’entraîner avec\n"
	.string "nous?$"

CharcoalKiln_Text_Apprentice1:
	.string "Où sont passés les RAMOLOSS? Ils\n"
	.string "sont partis s’amuser ailleurs?$"

CharcoalKiln_Text_Apprentice2:
	.string "Les RAMOLOSS sont de retour!$"

CharcoalKiln_Text_Apprentice3:
	.string "Pardonne-moi, j'ai oublié de te\n"
	.string "remercier.\p"
	.string "J'ai produit ce CHARBON.\p"
	.string "Les Pokémon de feu seront\n"
	.string "contents d'en tenir un.$"

CharcoalKiln_Text_Apprentice4:
	.string "Les RAMOLOSS sont\n"
	.string "de retour, et tu\p"
	.string "as même retrouvé\n"
	.string "mes CANARTICHO.\p"
	.string "Tu dépotes, toi!$"

CharcoalKiln_Text_Farfetchd:
	.string "CANARTICHO: Ticho!$"
