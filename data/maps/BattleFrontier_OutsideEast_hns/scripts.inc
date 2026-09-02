BattleFrontier_OutsideEast_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition_hns
	.byte 0

BattleFrontier_OutsideEast_OnResume_hns:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker_hns::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac_hns::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1_hns::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin_hns::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM_hns::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo_hns::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo_hns::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1_hns::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl_hns::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM_hns::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2_hns::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2_hns::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hns::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper_hns::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign_hns:
	.string "TOUR DE COMBAT “Enchaînez les\n"
	.string "victoires!”$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns:
	.string "PALACE DE COMBAT “Gardez un œil\n"
	.string "sur vos POKéMON!”$"

BattleFrontier_OutsideEast_Text_BattleArenaSign_hns:
	.string "DOJO DE COMBAT “Que les équipes\n"
	.string "se forment!”$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns:
	.string "PYRAMIDE DE COMBAT “Découvrez\n"
	.string "l’aventure du COMBAT QUETE!”$"

BattleFrontier_OutsideEast_Text_RankingHallSign_hns:
	.string "HALL DE CLASSEMENT “Jetez un œil\n"
	.string "aux records des meilleurs!”$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns:
	.string "SERVICE D’ECHANGE “Echangez vos\n"
	.string "POINTS DE COMBAT!”$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns:
	.string "Waouh! C’est immense!\p"
	.string "La TOUR DE COMBAT est un endroit\n"
	.string "unique. Il ne ressemble à aucun\p"
	.string "autre.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns:
	.string "Ma grande ambition est de\n"
	.string "conquérir la ZONE DE COMBAT et\p"
	.string "la LIGUE POKéMON.\p"
	.string "Si mon rêve se réalise…\p"
	.string "Je demanderai à MIMI si elle\n"
	.string "veut bien être mon amie!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns:
	.string "La PYRAMIDE DE COMBAT est trop\n"
	.string "dure! Je n’arrive pas à\p"
	.string "atteindre le sommet!\p"
	.string "Je pense que je vais essayer de\n"
	.string "l’atteindre par l’extérieur…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns:
	.string "Je m’épanouis dans l’obscurité…\n"
	.string "Oui… Ce qui compte à mes yeux?\p"
	.string "La PYRAMIDE DE COMBAT…\p"
	.string "J’aime me promener dans\n"
	.string "l’obscurité la plus totale, au\p"
	.string "bord du désespoir.$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns:
	.string "Je n’ai pas dormi depuis une\n"
	.string "semaine, mais j’ai réuni une\p"
	.string "super équipe!\p"
	.string "Franchement, je ne peux pas\n"
	.string "perdre. A moi le DOJO DE COMBAT!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns:
	.string "Tu es ici grâce à SCOTT? Il est\n"
	.string "bizarre, quand même, non?\p"
	.string "Il est très fort pour repérer\n"
	.string "les DRESSEURS qui ont du talent,\p"
	.string "oui…\p"
	.string "Mais je ne l’ai absolument\n"
	.string "jamais vu se battre.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns:
	.string "ZIGG! Je crois en toi, mon bébé!\p"
	.string "Je te préparerai tout ce que tu\n"
	.string "voudras si tu gagnes, mon petit\p"
	.string "ZIGG!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns:
	.string "ZIGZATON a l’air absent…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns:
	.string "Les cuisiniers du PALACE disent\n"
	.string "que je suis un fouineur. C’est\p"
	.string "peut-être vrai…\p"
	.string "Ta toque est de travers! C’est\n"
	.string "tombé par terre, ramasse vite!\p"
	.string "Vite, c’est presque l’heure du\n"
	.string "dîner!\p"
	.string "Je ne peux pas m’empêcher de\n"
	.string "mettre mon grain de sel…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns:
	.string "Je ne fais plus très peur, mais\n"
	.string "dans le temps, j’ai battu un\p"
	.string "CHAMPION D’ARENE.\p"
	.string "Qui sait, peut-être que je\n"
	.string "devrais m’y remettre!?!$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns:
	.string "Sur mon VELO, je suis rapide.\n"
	.string "Aux combats aussi!\p"
	.string "Je gagne mes combats en un clin\n"
	.string "d’œil!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns:
	.string "Je suis plus forte que mon père\n"
	.string "aux POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns:
	.string "Allez, mon bébé! Va gagner pour\n"
	.string "papa!\p"
	.string "Tu ressembles à ta mère, tu vas\n"
	.string "les mener par le bout du nez!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns:
	.string "Je viens de très loin, j’avais\n"
	.string "entendu dire qu’il y avait une\p"
	.string "jolie fille au DOJO DE COMBAT.\p"
	.string "Tu sais ce que j’ai trouvé à la\n"
	.string "place?\p"
	.string "Un ramassis de fanas d’arts\n"
	.string "martiaux!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns:
	.string "Des fois, je vois un vieil homme\n"
	.string "à l’air très important qui entre\p"
	.string "ici.\p"
	.string "Il a des POKéMON magnifiques. Il\n"
	.string "a l’air très gentil.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns:
	.string "Tu la connais, la légende de la\n"
	.string "PYRAMIDE DE COMBAT?\p"
	.string "Quand un DRESSEUR sûr de lui\n"
	.string "atteindra le sommet doré, un\p"
	.string "homme apparaîtra parmi les\n"
	.string "hommes.\p"
	.string "Tu ne connais pas cette légende?\n"
	.string "Pas étonnant, je viens de\p"
	.string "l’inventer!\p"
	.string "Il y a un sens caché, tu sais.\n"
	.string "Désolé, motus et bouche cousue!$"

BattleFrontier_OutsideEast_Text_GotWipedOut_hns:
	.string "Mince, alors! C’est la première\n"
	.string "fois que je perds!\p"
	.string "Je me suis fait écraser comme un\n"
	.string "moucheron!\p"
	.string "Et en plus, on vient me dire que\n"
	.string "je n’ai aucun talent! Mince…$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns:
	.string "Cet homme a dû se battre contre\n"
	.string "un DRESSEUR horriblement fort à\p"
	.string "la TOUR DE COMBAT.\p"
	.string "Et maintenant, regarde-le…\p"
	.string "Si tu décides d’aller à la TOUR\n"
	.string "DE COMBAT, fais bien attention.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns:
	.string "Chouette! J’ai enfin assez de\n"
	.string "POINTS DE COMBAT!\p"
	.string "Je pense que je vais les\n"
	.string "échanger contre une autre\p"
	.string "POUPEE!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns:
	.string "Waouh… Alors comme ça, c’est le\n"
	.string "HALL DE CLASSEMENT!\p"
	.string "J’aimerais qu’on se souvienne de\n"
	.string "moi. J’aimerais que mon nom soit\p"
	.string "inscrit ici. Je veux passer à la\n"
	.string "postérité!$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns:
	.string "Avec toi à mes côtés, rien ne\n"
	.string "peut m’arrêter.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns:
	.string "Oh, mon chéri! Tu es formidable!\p"
	.string "Je ne veux plus attendre!\p"
	.string "Allons vite dans une SALLE DE\n"
	.string "COMBAT MULTI!\p"
	.string "Si nous allons dans le SALON DE\n"
	.string "COMBAT ensemble, ils vont tous\p"
	.string "trembler devant la force de\n"
	.string "notre amour.\p"
	.string "Ils vont tous s’effondrer comme\n"
	.string "des dominos devant nous!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns:
	.string "La ZONE DE COMBAT n’est pas\n"
	.string "réservée qu’aux bons DRESSEURS.\p"
	.string "Il paraît que des gens ayant\n"
	.string "d’autres aptitudes ont été\p"
	.string "invités aussi.\p"
	.string "Ce SCOTT…\p"
	.string "Peut-être qu’il avait une idée\n"
	.string "derrière la tête en construisant\p"
	.string "cet endroit…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns:
	.string "Pardon, petit. As-tu une bonne\n"
	.string "vue?\p"
	.string "Il y a un arbre bizarre là-bas.\n"
	.string "J’ai l’impression qu’il bouge.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns:
	.string "Pardon, petit. As-tu une bonne\n"
	.string "mémoire?\p"
	.string "Il me semble qu’il y avait un\n"
	.string "arbre bizarre là-bas, avant.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns:
	.string "… Je l’ai vu!\p"
	.string "J’ai vu un POKéMON du genre\n"
	.string "gluant avec une longue queue!\p"
	.string "Il se cachait derrière un rocher\n"
	.string "et n’arrêtait pas de me\p"
	.string "regarder!$"
