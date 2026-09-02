LakeOfRage_House1_hns_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
    .string "... Tu as bien voyagé... Moi,\n"
    .string "j’ai médité...\p"
    .string "Au fond de moi une nouvelle\n"
    .string "force s’est réveillée.\p"
    .string "Laisse-moi partager mon pouvoir\n"
    .string "avec tes Pokémon.\p"
    .string "Reçois ceci...$"

HiddenPowerGuy_Text_Explanation:
    .string "Tu vois? C’est Puissance Cachée!\p"
    .string "Elle développe la puissance de\n"
    .string "tes Pokémon.\p"
    .string "Mais attention! Cela\n"
    .string "dépend du type et\p"
    .string "de la puissance du\n"
    .string "Pokémon utilisé.$"

HiddenPowerGuy_Text_Meditating:
    .string "Je médite...$"
