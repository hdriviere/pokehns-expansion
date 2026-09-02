AzaleaTown_Mart_hns_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "Tu peux acheter des SUPER BALLS?\p"
	.string "Moi, je ne peux acheter que des\n"
	.string "Poké Balls.\p"
	.string "Il paraît que de nouveaux objets\n"
	.string "sont vendus avec plus de Badges!\p"
	.string "Je voudrais des BALLS de FARGAS.$"

AzaleaMart_Text_BugCatcher:
	.string "Une SUPER BALL est\n"
	.string "plus efficace qu'une\p"
	.string "Poké BALL pour\n"
	.string "attraper les Pokémon.\p"
	.string "Mais celles de FARGAS sont plus\n"
	.string "efficaces quelquefois.$"
