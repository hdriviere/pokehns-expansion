BattleFrontier_Lounge3_hns_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler_hns::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5_hns
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10_hns
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15_hns
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet5_hns::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet10_hns::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_Bet15_hns::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet_hns::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet_hns
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount_hns
	end

BattleFrontier_Lounge3_EventScript_PlaceBet_hns::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet_hns
	end

BattleFrontier_Lounge3_EventScript_FinishBet_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols_hns::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount_hns::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols_hns::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler_hns::
	msgbox BattleFrontier_Lounge3_Text_Oh_hns, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults_hns
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults_hns::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge_hns
	goto BattleFrontier_Lounge3_EventScript_LostChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_WonChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10_hns
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15_hns
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15_hns::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted_hns::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns::
	msgbox BattleFrontier_Lounge3_Text_NotInterested_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet_hns::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge_hns
	end

BattleFrontier_Lounge3_EventScript_Man_hns::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_PokefanF_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FatMan_hns::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection_hns::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere_hns::
	.string "… Qu’est-ce que tu veux?\p"
	.string "Nous sommes occupés. Tu ne peux\n"
	.string "pas revenir plus tard?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling_hns::
	.string "… Tu as l’air d’être un bon\n"
	.string "DRESSEUR.\p"
	.string "Hé, hé… J’ai quelque chose à te\n"
	.string "proposer.\p"
	.string "On est un petit groupe et on\n"
	.string "joue à un petit jeu ici. On mise\p"
	.string "sur ce qui se passe à la ZONE DE\n"
	.string "COMBAT.\p"
	.string "Les règles sont simples.\p"
	.string "D’abord, on choisit un des\n"
	.string "bâtiments de la ZONE DE COMBAT.\p"
	.string "Ensuite, on choisit chacun un\n"
	.string "DRESSEUR qui relève le défi de\p"
	.string "ce bâtiment et on mise des\n"
	.string "POINTS DE COMBAT dessus.\p"
	.string "Celui qui a misé sur le DRESSEUR\n"
	.string "qui fait le meilleur score\p"
	.string "récolte tous les POINTS DE\n"
	.string "COMBAT mis en jeu.\p"
	.string "Plutôt simple, non? De toute\n"
	.string "façon…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE\p"
	.string "COMBAT SOLO de la TOUR DE\n"
	.string "COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE\p"
	.string "COMBAT DUO de la TOUR DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE\p"
	.string "COMBAT MULTI de la TOUR DE\n"
	.string "COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI DE COMBAT\p"
	.string "SOLO du DOME DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI DE COMBAT\p"
	.string "DUO du DOME DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\p"
	.string "ECHANGE SOLO de l’USINE DE\n"
	.string "COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI COMBAT\p"
	.string "ECHANGE DUO de l’USINE DE\n"
	.string "COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi des HALLS DE\p"
	.string "COMBAT SOLO du PALACE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi des HALLS DE\p"
	.string "COMBAT DUO du PALACE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "participer au TOURNOI K.O. du\p"
	.string "DOJO DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi du COMBAT HASARD\p"
	.string "au REPTILE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid_hns::
	.string "Je cherche un DRESSEUR qui va\n"
	.string "relever le défi du COMBAT QUETE\p"
	.string "dans la PYRAMIDE DE COMBAT.\p"
	.string "Mais je n’ai pas vu un seul\n"
	.string "DRESSEUR à la hauteur.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe_hns::
	.string "Bien sûr, tu ne feras pas ça\n"
	.string "pour rien. Qu’est-ce que tu en\p"
	.string "dis? Tu veux bien être ce\n"
	.string "DRESSEUR?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints_hns::
	.string "Très bien. Parfait. Heu… Tu veux\n"
	.string "bien me prêter quelques POINTS\p"
	.string "DE COMBAT?\p"
	.string "Fais-moi confiance, je te\n"
	.string "remercierai comme il se doit.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot_hns::
	.string "Super! Combien tu peux me\n"
	.string "prêter?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints_hns::
	.string "Non mais! Tu n’as pas assez de\n"
	.string "POINTS DE COMBAT!\p"
	.string "Ça t’amuse de faire perdre leur\n"
	.string "temps aux honnêtes gens?$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo_hns::
	.string "Hé, hé! Merci bien! C’est parti!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle_hns::
	.string "Vite, les SALLES DE COMBAT SOLO\n"
	.string "de la TOUR DE COMBAT\p"
	.string "t’attendent!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble_hns::
	.string "Vite, les SALLES DE COMBAT DUO\n"
	.string "de la TOUR DE COMBAT\p"
	.string "t’attendent!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti_hns::
	.string "Vite, les SALLES DE COMBAT MULTI\n"
	.string "de la TOUR DE COMBAT\p"
	.string "t’attendent!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle_hns::
	.string "Vite, le TOURNOI DE COMBAT SOLO\n"
	.string "du DOME DE COMBAT t’attend!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble_hns::
	.string "Vite, le TOURNOI DE COMBAT DUO\n"
	.string "du DOME DE COMBAT t’attend!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle_hns::
	.string "Vite, le TOURNOI COMBAT ECHANGE\n"
	.string "SOLO de l’USINE DE COMBAT\p"
	.string "t’attend!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble_hns::
	.string "Vite, le TOURNOI COMBAT ECHANGE\n"
	.string "DUO de l’USINE DE COMBAT\p"
	.string "t’attend!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle_hns::
	.string "Vite, les HALLS DE COMBAT SOLO\n"
	.string "du PALACE DE COMBAT t’attendent!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble_hns::
	.string "Vite, les HALLS DE COMBAT DUO du\n"
	.string "PALACE DE COMBAT t’attendent!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattleArena_hns::
	.string "Vite, le TOURNOI K.O. du DOJO DE\n"
	.string "COMBAT t’attend!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePike_hns::
	.string "Vite, le défi du COMBAT HASARD\n"
	.string "t’attend au REPTILE DE COMBAT!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid_hns::
	.string "Vite, le défi du COMBAT QUETE\n"
	.string "t’attend dans la PYRAMIDE DE\p"
	.string "COMBAT!\p"
	.string "Tu dois gagner! Je compte sur\n"
	.string "toi! Notre avenir à tous les\p"
	.string "deux en dépend!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints_hns::
	.string "Oh, c’est toi… C’était bien\n"
	.string "tenté…\p"
	.string "Malheureusement, je ne peux pas\n"
	.string "te rendre ce que tu m’as prêté…\p"
	.string "Ça nous apprendra à faire plus\n"
	.string "attention la prochaine fois!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints_hns::
	.string "Bravo! Tu as été formidable!\p"
	.string "Je le savais! Je te faisais\n"
	.string "confiance! On est les meilleurs!\p"
	.string "Je te rends ce que tu m’as prêté\n"
	.string "avec un petit extra!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints_hns::
	.string "{PLAYER} reçoit {STR_VAR_1}\n"
	.string "POINTS DE COMBAT.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge_hns::
	.string "Si tu as envie de relever un\n"
	.string "autre défi, pense à moi!$"

BattleFrontier_Lounge3_Text_NotInterested_hns::
	.string "Ça ne t’intéresse pas? Penses-y,\n"
	.string "au moins!$"

BattleFrontier_Lounge3_Text_Oh_hns::
	.string "Oh...$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer_hns::
	.string "J’ai encore misé sur le mauvais\n"
	.string "DRESSEUR!\p"
	.string "Je crois que je devrais arrêter\n"
	.string "ces bêtises…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled_hns::
	.string "Ce DRESSEUR…\p"
	.string "Il est bon, mais il n’a pas les\n"
	.string "nerfs assez solides pour le DOME\p"
	.string "DE COMBAT…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne_hns::
	.string "Hi, hi, hi! Je sais reconnaître\n"
	.string "un gagnant!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges_hns::
	.string "Ces DRESSEURS… Mais que\n"
	.string "font-ils? Ils devraient aller se\p"
	.string "battre.$"
