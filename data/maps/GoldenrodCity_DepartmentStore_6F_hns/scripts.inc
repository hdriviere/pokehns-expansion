GoldenrodCity_DepartmentStore_6F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "{PLAYER}! Quelle surprise!\p"
	.string "Je viens chercher quelque chose\n"
	.string "pour mon ECREMEUH.\p"
	.string "Pour un autre combat, viens au\n"
	.string "DOJO!$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MACHOP, GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon, GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "Je collectionne les Pokémon!\n"
	.string "Tu as un {STR_VAR_1}?\p"
	.string "Veux-tu l'échanger contre mon\n"
	.string "{STR_VAR_2}?$"

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "Youpi! J'ai obtenu {STR_VAR_1}!\p"
	.string "Prends soin de {STR_VAR_2}!$"

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "Euh, non, je ne crois pas.\n"
	.string "Ce n'est pas un {STR_VAR_1}.$"

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "Tu ne veux pas échanger? Oh…$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "Salut! Le MACHOC que je t’ai\n"
	.string "donné va bien?$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
	.string "Tu écoutes la CHAINE CHANCE?\p"
	.string "Pour gagner, il faudrait échanger\n"
	.string "des Pokémon avec de nombreuses\p"
	.string "personnes afin d'obtenir des\n"
	.string "numéros ID différents.\p"
	.string "Mais les échanges sont moins\n"
	.string "accessibles qu'autrefois.$"

GoldenrodDeptStore_Text_6FSuperNerd:
    .string "Si tu es naze, sers-toi du\n"
    .string "distributeur automatique.\p"
    .string "Ton Pokémon appréciera aussi.$"

GoldenrodDeptStore_Text_6FDirectory:
    .string "Une petite pause!\p"
    .string "5EME COIN      TRANQUILLE$"
