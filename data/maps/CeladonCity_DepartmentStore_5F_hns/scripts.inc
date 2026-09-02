CeladonCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FRUSTRATION, CeladonDeptStore5_EventScript_Receptionist_Already
	msgbox CeladonDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, FRIENDSHIP_50_TO_99, CeladonDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	msgbox CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore5_EventScript_Receptionist_Already::
	msgbox CeladonDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonDeptStore_Text_5FReceptionistOhYourMon:
    .string "Bienvenue!\p"
    .string "Oh! Ton Pokémon...$"

CeladonDeptStore_Text_5FReceptionistWait:
    .string "Attends, je t'ai déjà donné la\n"
    .string "CT!$"

CeladonDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "Ce n'est ni mauvais ni bon.\p"
	.string "Comme Dresseur, tu dois faire\n"
	.string "encore quelques efforts.$"

CeladonDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "Il a l'air un peu méchant. Que\n"
    .string "penses-tu de cette CT pour lui?$"

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "ALBERT: {PLAYER}. Je ne pensais\n"
	.string "pas te voir ici.\p"
	.string "J'achète du matériel pour mes\n"
	.string "Pokémon oiseaux.\p"
	.string "Si tu veux me réaffronter, je\n"
	.string "serai au DOJO de SAFRANIA.$"

CeladonDeptStore5F_Text_Gentleman:
	.string "Je voulais acheter\n"
	.string "de quoi augmenter\p"
	.string "les statistiques de\n"
	.string "mes Pokémon, mais\p"
	.string "je n’ai pas assez d’argent!$"

CeladonDeptStore5F_Text_Sailor:
	.string "Je veux PP PLUS pour augmenter\n"
	.string "les\p"
	.string "PP des capacités. Mais on ne\n"
	.string "peut pas en acheter...$"

CeladonDeptStore5F_Text_Teacher:
	.string "Utiliser certains\n"
	.string "objets sur les Pokémon\p"
	.string "les rend heureux.\n"
	.string "Mais il y en a\p"
	.string "d’autres qu’ils n’aiment pas.$"

CeladonDeptStore5F_Text_Directory:
	.string "4EME: POTIONS, etc$"
