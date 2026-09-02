LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllRegionalMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	specialvar VAR_RESULT, HasAllMons
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm
	specialvar VAR_RESULT, HasAllRegionalMons
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveOvalCharm
	special Special_ShowDiploma
	waitstate

	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveOvalCharm::
	checkitem ITEM_OVAL_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm::
	giveitem ITEM_OVAL_CHARM
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm::
	checkitem ITEM_SHINY_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveShinyCharm
	checkitem ITEM_OVAL_CHARM
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOvalCharm
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveShinyCharm::
	giveitem ITEM_SHINY_CHARM
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Je suis le CONCEPTEUR DE JEU.\p"
	.string "Oh, est-ce que c’est vrai? Tu\n"
	.string "travailles sur un POKéDEX?\p"
	.string "C’est difficile de le compléter,\n"
	.string "mais n’abandonne pas.\p"
	.string "Si tu arrives à le compléter,\n"
	.string "reviens me voir.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Waouh! C’est impressionnant!\n"
	.string "Ouais, carrément impressionnant!\p"
	.string "Ce POKéDEX est totalement\n"
	.string "rempli! Tu dois vraiment aimer\p"
	.string "les POKéMON!\p"
	.string "Je suis si impressionné!\p"
	.string "Laisse-moi te donner quelque\n"
	.string "chose pour récompenser ton\p"
	.string "exploit!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Moi? C’est à moi que tu parles?\n"
	.string "Je suis le PROGRAMMEUR.\p"
	.string "Je me demande à quoi ressemblent\n"
	.string "les MACHINES A SOUS ici.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Je suis le GRAPHISTE! Les\n"
	.string "POKéMON de HOENN ne sont-ils pas\p"
	.string "intéressants?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Les filles FLOTTEURS sont à\n"
	.string "croquer, non? Pour affronter une\p"
	.string "de ces filles…\p"
	.string "Ouhhh, ça m’rend dingue!\p"
	.string "Et les JUMELLES! Mignonnes,\n"
	.string "hein? Un combat 2 contre 2 avec\p"
	.string "les JUMELLES…\p"
	.string "Ouhhh, c’est terrible!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brise marine emballe mon\n"
	.string "cœur. Quel bonheur d’être ici!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Tu ne peux pas savoir où et\n"
	.string "quand on va te défier.\p"
	.string "C’est pour cela que je ne sors\n"
	.string "jamais sans ma GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … … … … … … … Zzz…\p"
	.string "… … … … … Hein?!\p"
	.string "Oh, désolé, j’étais en train de\n"
	.string "dormir!\p"
	.string "Je suis venu voir ce qui se\n"
	.string "passe dans ces CONCOURS POKéMON.\p"
	.string "Je dois admettre que c’est\n"
	.string "plutôt divertissant, mais…\p"
	.string "En tant que puriste, je préfère\n"
	.string "les combats dangereux.\p"
	.string "Mais ce n’est que mon avis.\p"
	.string "{PLAYER}{KUN}, j’espère que tu\n"
	.string "vas profiter de tout: les\p"
	.string "ARENES, les CONCOURS, les TENTES\n"
	.string "DE COMBAT, tout!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Il faut beaucoup de\n"
	.string "stratégie pour remporter un\p"
	.string "CONCOURS.\p"
	.string "Parler des stratégies des\n"
	.string "CONCOURS est, à mon avis, une\p"
	.string "façon de devenir un bon\n"
	.string "DRESSEUR.$"

