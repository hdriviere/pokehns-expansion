OlivineCity_Cafe_hns_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "Oh... Bonjour, {PLAYER}.\p"
	.string "Tous ces plats devant moi ne\n"
	.string "sont pas à moi...\p"
	.string "Euh...\p"
	.string "En fait, la personne assise ici\n"
	.string "avant moi a beaucoup mangé...\p"
	.string "Si tu veux m'affronter\n"
	.string "à nouveau,\l"
	.string "retrouve-moi au DOJO\l"
	.string "de SAFRANIA.$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "Ha! Tes Pokémon ont l'air de\n"
	.string "mauviettes!\p"
	.string "Ils ne peuvent pas déplacer les\n"
	.string "rochers, je parie.\p"
	.string "Tiens! Apprendsleur FORCE!$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "En mer, tu ne peux compter que\n"
	.string "sur toi-même!\p"
	.string "Je suis fier de mes muscles!\n"
	.string "Entraîne-toi comme moi!$"

OlivineCity_Text_CafeFishingGuru:
	.string "Le menu du CAFE D'OLIVILLE\n"
	.string "regorge\l"
	.string "de plats nourrissants pour les\l"
	.string "MARINS costauds comme moi!$"

OlivineCity_Text_CafeSailor:
	.string "A chaque passage dans cette\n"
	.string "ville,\p"
	.string "je vais au CAFE d'OLIVILLE.\p"
	.string "La bouffe y est trooooooooooooop\n"
	.string "bonne!$"
