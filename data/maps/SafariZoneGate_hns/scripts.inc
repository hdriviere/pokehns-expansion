SafariZoneGate_hns_MapScripts::
	.byte 0

SafariZoneGate_EventScript_Trigger::
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
	setvar VAR_SAFARI_ZONE_GATE_STATE, 3
	end

SafariZoneGate_EventScript_BackupTrigger::
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
	setvar VAR_TEMP_0, 1
	end

SafariZoneGate_EventScript_WorkerM::
	lock
	faceplayer
	msgbox SafariZone_Text_ForeignFeeling, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Silent::
	lock
	faceplayer
	msgbox SafariZone_Text_SilentNPC, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Kangaskhan::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	msgbox SafariZone_Text_Kangaskhan, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SafariZoneGate_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZone_Text_JigglypuffTrainer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Girl::
	lock
	faceplayer
	msgbox SafariZone_Text_FirstCatch, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_SlowpokeLady::
	lock
	faceplayer
	msgbox SafariZone_Text_SlowpokeFan, MSGBOX_DEFAULT
	closemessage
	release
	end


SafariZone_Text_ForeignFeeling:
	.string "Le Parc Safari...\p"
	.string "En venant ici, on a l’impression\n"
	.string "d’être transporté dans une fête\p"
	.string "exotique d’un pays lointain...\p"
	.string "C’est étrange, n’est-ce pas?$"

SafariZone_Text_SilentNPC:
	.string "... (J’aime pas parler).$"

SafariZone_Text_Kangaskhan:
	.string "KANGOUREX: ...$"

SafariZone_Text_JigglypuffTrainer:
	.string "Décidément, ce Parc Safari est\n"
	.string "bien amusant!\p"
	.string "Quand je suis là,\n"
	.string "je me mets à courir\p"
	.string "après les Pokémon\n"
	.string "comme un fou!\p"
	.string "Mais mon fidèle\n"
	.string "RONDOUDOU n’aime pas\p"
	.string "quand je suis comme\n"
	.string "ça, alors il boude.$"

SafariZone_Text_FirstCatch:
	.string "C’est décidé! Mon\n"
	.string "premier Pokémon,\p"
	.string "je l’attraperai\n"
	.string "au Parc Safari!$"

SafariZone_Text_SlowpokeFan:
	.string "Y’a plein de Pokémon, mais le\n"
	.string "meilleur, c’est RAMOLOSS!\p"
	.string "C’est lui le plus mignon!\p"
	.string "En plus, on me dit souvent que\n"
	.string "je ressemble à un RAMOLOSS...$"

SafariZone_Text_CustomSystem:
	.string "Je suis sûr que tu\n"
	.string "crois que ce Safari\p"
	.string "est customisable à\n"
	.string "volonté parce qu’il\p"
	.string "a été construit avec des\n"
	.string "technologies\p"
	.string "de pointe, pas vrai?\p"
	.string "Alors qu’en fait...$"

SafariZone_Text_Sign:
	.string "Parc Safari\p"
	.string "Goûtez au frisson de l’aventure!$"


SafariZoneGate_EventScript_IncenseClerk::
	goto_if_set FLAG_FINITE_TMS, SafariZoneGate_EventScript_IncenseClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_EventScript_IncenseClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SafariZoneGate_EventScript_VitaminGuru::
	lock
	faceplayer
	message SafariZoneGate_Text_VitaminGuruSellWhatYouNeed
	waitmessage
	pokemart SafariZoneGate_Pokemart_VitaminGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_VitaminGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_Text_VitaminGuruSellWhatYouNeed:
	.string "Je suis le MAITRE DE LA FORME!\n"
	.string "J’ai tout ce qu’il vous faut!$"

