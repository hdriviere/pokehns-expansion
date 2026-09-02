MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woahou!\p"
	.string "Les gens m’appellent le TYPE\n"
	.string "ECLATE-ROC, mais je n’aime pas\p"
	.string "trop ça.\p"
	.string "Je crois que je mérite un surnom\n"
	.string "plus flatteur, comme le MEC\p"
	.string "ECLATE-ROC par exemple.\p"
	.string "Woahou!\p"
	.string "Quoi qu’il en soit, ton POKéMON\n"
	.string "semble plutôt fort.\p"
	.string "J’aime ça! Tiens, prends cette\n"
	.string "CS!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Cette CS contient ECLATE-ROC.\p"
	.string "Si tu te trouves face à de gros\n"
	.string "blocs de pierre bloquant le\p"
	.string "passage…\p"
	.string "Eh bien, utilise l’attaque de\n"
	.string "cette CS et pulvérise-les!\p"
	.string "Ouaip! Eclate-les carrément!\n"
	.string "Woahou!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah, oui! Si tu détruis une\n"
	.string "pierre, un POKéMON peut en\p"
	.string "surgir.\p"
	.string "Woahou!$"

