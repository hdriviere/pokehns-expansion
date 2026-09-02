GoldenrodCity_DepartmentStore_5F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_Already
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "Bienvenue!\p"
    .string "Oh! Ton Pokémon...$"

GoldenrodDeptStore_Text_5FReceptionistWait:
	.string "Attends, tu as déjà cette CT!$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Hum…\n"
	.string "Ce n'est ni mauvais, ni bon.\p"
	.string "Comme Dresseur, tu dois faire\n"
	.string "encore quelques efforts.$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "Il est vraiment\n"
    .string "attaché à toi!\p"
    .string "Cette capacité\n"
    .string "convient parfaitement\p"
    .string "à votre équipe!$"

GoldenrodDeptStore_Text_5FLass:
	.string "Le jour, une dame vient examiner\n"
	.string "les Pokémon.\p"
	.string "Elle offre même des CT!$"

GoldenrodDeptStore_Text_5FPokefanM:
    .string "Tu ne peux pas\n"
    .string "renommer un Pokémon\p"
    .string "que tu as reçu\n"
    .string "dans un échange.\p"
    .string "Ce nom contient\n"
    .string "toujours les\p"
    .string "sentiments du\n"
    .string "Dresseur d’origine.$"

GoldenrodDeptStore_Text_Girl:
	.string "La dame m'a donné RETOUR!\p"
	.string "Mon Pokémon doit vraiment m'aimer!$"

GoldenrodDeptStore5_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5_Pokemart:
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_NATURAL_GIFT
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_SOLAR_BEAM
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_FOCUS_BLAST
	pokemartlistend


GoldenrodDeptStore_Text_5FDirectory:
    .string "Pour personnaliser son\n"
    .string "Pokémon...\p"
    .string "4EME Y'A BON LES      CT$"
