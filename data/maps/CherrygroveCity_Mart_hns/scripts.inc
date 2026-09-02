CherrygroveCity_Mart_hns_MapScripts::
	.byte 0

Cherrygrove_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Clerk2
	pokemart Cherrygrove_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_Youngster::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Bugcatcher2
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Cherrygrove_Pokemart_EventScript_Bugcatcher2::
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Clerk2::
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 3
Cherrygrove_Pokemart_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_NONE
	release
	end

Cherrygrove_Pokemart_Text_CooltrainerM:
	.string "Ils n’ont plus de\n"
	.string "Poké Balls! Je me\p"
	.string "demande quand ils\n"
	.string "en recevront...$"

Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
	.string "Les Poké Balls sont\n"
	.string "arrivées! Je vais\p"
	.string "attraper tous les\n"
	.string "Pokémon en vue!$"

Cherrygrove_Pokemart_Text_Youngster:
	.string "Je marchais dans l'herbe et un\p"
	.string "Pokémon insecte a empoisonné mon\n"
	.string "Pokémon!\p"
	.string "J'ai continué mon chemin mais\n"
	.string "mon Pokémon s'est évanoui.\p"
	.string "Tu devrais garder un ANTIDOTE\n"
	.string "avec toi.$"
