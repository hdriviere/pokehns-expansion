MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Bon, bon, bon… Qu’est-ce qu’on a\n"
	.string "là? Un client des plus\p"
	.string "énergiques!\p"
	.string "Moi? Tu peux m’appeler RODOLPHE.\n"
	.string "Je suis le propriétaire de ce\p"
	.string "magasin de vélos.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RODOLPHE: Tes CHAUSSURES DE\n"
	.string "SPORT… Elles sont dégoûtantes!\p"
	.string "Tu viens de loin?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RODOLPHE: C’est vrai?\p"
	.string "Alors je suppose que tu n’as pas\n"
	.string "besoin de mes VELOS.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RODOLPHE: Hum, hum… … … … … … …\n"
	.string "… … … … … …\p"
	.string "Tu veux dire que tu as fait\n"
	.string "toute la route depuis\p"
	.string "BOURG-EN-VOL?\p"
	.string "Mon dieu! C’est terriblement\n"
	.string "loin!\p"
	.string "Si tu avais un de mes VELOS, tu\n"
	.string "pourrais aller n’importe où sans\p"
	.string "problème, en sentant le vent te\n"
	.string "caresser le visage!\p"
	.string "Tu sais quoi? Je vais te donner\n"
	.string "un VELO!\p"
	.string "Oh, attends une seconde!\p"
	.string "J’ai oublié de te préciser qu’il\n"
	.string "y a deux sortes de VELOS.\p"
	.string "Il y a le VELO COURSE et le VELO\n"
	.string "CROSS.\p"
	.string "Le VELO COURSE est pour ceux qui\n"
	.string "veulent sentir le souffle du\p"
	.string "vent.\p"
	.string "Et le VELO CROSS est pour ceux\n"
	.string "qui préfèrent les performances\p"
	.string "techniques.\p"
	.string "Je suis un vrai passionné. Tu\n"
	.string "peux prendre celui que tu veux.\p"
	.string "Alors, tu choisis lequel?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} choisit le VELO COURSE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} choisit le VELO CROSS.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RODOLPHE: Si tu as besoin de\n"
	.string "changer de VELO, n’hésite pas à\p"
	.string "venir me voir!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RODOLPHE: Oh? Tu voudrais\n"
	.string "changer de VELO?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RODOLPHE: D’accord, pas de\n"
	.string "problème! Je t’échange ton VELO\p"
	.string "contre l’autre.$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} reçoit le VELO CROSS en\n"
	.string "échange du VELO COURSE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} reçoit le VELO COURSE\n"
	.string "en échange du VELO CROSS.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RODOLPHE: Très bien! Content\n"
	.string "qu’il te convienne!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? Qu’est-ce qui est arrivé au\n"
	.string "VELO que je t’avais donné?\p"
	.string "Ah, je vois! Tu l’as stocké sur\n"
	.string "ton PC.\p"
	.string "Bon, sors-le du PC et je te\n"
	.string "l’échangerai!\p"
	.string "Que les vents te soient\n"
	.string "favorables!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "J’apprends beaucoup de choses\n"
	.string "sur les VELOS depuis que je\p"
	.string "travaille ici.\p"
	.string "Si tu as besoin de conseils pour\n"
	.string "conduire ton vélo, il y a deux\p"
	.string "ou trois manuels derrière.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "C’est un guide sur le VELO\n"
	.string "COURSE.\p"
	.string "Lire quelle page?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Le VELO prend la direction\n"
	.string "indiquée sur la manette +.\p"
	.string "Il accélère dès qu’il commence à\n"
	.string "rouler.\p"
	.string "Quand la manette + n’est plus\n"
	.string "utilisée, le VELO ralentit et\p"
	.string "s’arrête.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Le VELO COURSE est rapide, mais\n"
	.string "il ne s’arrête pas\p"
	.string "immédiatement.\p"
	.string "C’est aussi un peu difficile de\n"
	.string "prendre les virages.\p"
	.string "Il faut relâcher la manette + et\n"
	.string "ralentir un peu avant le virage.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "De petites coulées de sable\n"
	.string "parsèment toute la région de\p"
	.string "HOENN.\p"
	.string "Ce sable fin empêche d’avancer\n"
	.string "normalement.\p"
	.string "Mais avec un VELO COURSE, il est\n"
	.string "possible de gravir un versant de\p"
	.string "sable.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "C’est un guide sur le VELO\n"
	.string "CROSS.\p"
	.string "Lire quelle page?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Si vous appuyez sur le bouton B\n"
	.string "en roulant, la roue avant se\p"
	.string "soulève.\p"
	.string "Vous pouvez rouler sur une roue\n"
	.string "en utilisant la manette +.\p"
	.string "Cette technique se nomme la roue\n"
	.string "arrière.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "En maintenant le bouton B\n"
	.string "enfoncé, vous pourrez sauter sur\p"
	.string "des rebords.\p"
	.string "Cette technique est appelée\n"
	.string "bunny hop.\p"
	.string "Vous pouvez aussi avancer en\n"
	.string "sautant.\p"
	.string "Lire une autre page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Appuyez simultanément sur le\n"
	.string "bouton B et sur la manette +\p"
	.string "pour faire un saut.\p"
	.string "Appuyez sur gauche ou droite sur\n"
	.string "la manette + pour faire un saut\p"
	.string "latéral.\p"
	.string "Appuyez sur haut sur la manette\n"
	.string "+ pour changer de direction en\p"
	.string "sautant.\p"
	.string "Voir une autre page?$"

