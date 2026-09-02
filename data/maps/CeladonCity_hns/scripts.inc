CeladonCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
	.string "ERIKA: Oh, {PLAYER}.\n"
	.string "La fontaine est ravissante, non?\p"
	.string "Si tu souhaites un autre combat,\n"
	.string "je serai au DOJO de COMBAT.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_EventScript_Item_Recycle::
    finditem ITEM_TM_RECYCLE
    end

CeladonCity_Text_Fisher:
	.string "Ce TARTARD est mon partenaire.\p"
	.string "Peut-il évoluer en un Pokémon\n"
	.string "grenouille?$"

CeladonCity_Text_Poliwrath:
	.string "TARTARD: Tarr!$"

CeladonCity_Text_Teacher1:
	.string "J'ai encore perdu aux machines à\n"
	.string "sous…\p"
	.string "Les filles aussi, on y joue.\p"
	.string "Tu devrais essayer.$"

CeladonCity_Text_Gramps1:
	.string "Des TADMORV sont apparus dans\n"
	.string "les environs.\p"
	.string "Tu vois la mare devant la\n"
	.string "maison?\p"
	.string "Un TADMORV y vit maintenant.\p"
	.string "D'où est-ce qu'ils viennent\n"
	.string "tous? C'est un gros problème...$"

CeladonCity_Text_Gramps2:
	.string "Hihi! Cette ARENE est géniale!\n"
	.string "C'est\p"
	.string "réservé aux filles! Youpi!$"

CeladonCity_Text_Youngster1:
	.string "Tu veux connaître un secret?\p"
	.string "Le MANOIR CELADON a une porte\n"
	.string "cachée à l'arrière.$"

CeladonCity_Text_Youngster2:
	.string "Il y a un concours de bouffe au\n"
	.string "restaurant.\p"
	.string "Rien que de les regarder me\n"
	.string "donne mal au coeur...$"

CeladonCity_Text_Teacher2:
	.string "Le CENTRE COMMERCIAL de\n"
	.string "CELADOPOLE vend de tout.\p"
	.string "Si tu n'y trouves pas ce que tu\n"
	.string "veux\p"
	.string "c'est que tu n'as pas de chance.\p"
	.string "...On dirait un slogan.$"

CeladonCity_Text_Lass:
	.string "J'ai mal au crâne.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "CELADOPOLE\p"
	.string "La ville aux rêves arc-en-ciel$"

CeladonGym_Text_Sign:
	.string "CHAMPION d'ARENE de CELADOPOLE:\n"
	.string "ERIKA\p"
	.string "La princesse de la nature$"

CeladonCity_Text_DeptStoreSign:
	.string "Y'a de tout au CENTRE COMMERCIAL\n"
	.string "de CELADOPOLE!$"

CeladonCity_Text_MansionSign:
	.string "MANOIR CELADON$"

CeladonCity_Text_GameCornerSign:
	.string "Le terrain de jeu de tous--\n"
	.string "CASINO DE CÉLADOPOLE$"

CeladonCity_Text_TrainerTips:
	.string "ASTUCE DRESSEUR\p"
	.string "GARDE SPEC. protège les Pokémon\n"
	.string "des attaques SPÉCIALES comme\l"
	.string "LANCE-FLAMMES et SURF.\p"
	.string "Achète tes objets au CENTRE\n"
	.string "COMMERCIAL de CÉLADOPOLE!$"
