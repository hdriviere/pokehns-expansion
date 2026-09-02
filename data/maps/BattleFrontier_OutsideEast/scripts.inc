BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
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

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "TOUR DE COMBAT “Enchaînez les\n"
	.string "victoires!”$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "PALACE DE COMBAT “Gardez un œil\n"
	.string "sur vos POKéMON!”$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "DOJO DE COMBAT “Que les équipes\n"
	.string "se forment!”$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "PYRAMIDE DE COMBAT “Découvrez\n"
	.string "l’aventure du COMBAT QUETE!”$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "HALL DE CLASSEMENT “Jetez un œil\n"
	.string "aux records des meilleurs!”$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "SERVICE D’ECHANGE “Echangez vos\n"
	.string "POINTS DE COMBAT!”$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Waouh! C’est immense!\p"
	.string "La TOUR DE COMBAT est un endroit\n"
	.string "unique. Il ne ressemble à aucun\p"
	.string "autre.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Ma grande ambition est de\n"
	.string "conquérir la ZONE DE COMBAT et\p"
	.string "la LIGUE POKéMON.\p"
	.string "Si mon rêve se réalise…\p"
	.string "Je demanderai à MIMI si elle\n"
	.string "veut bien être mon amie!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La PYRAMIDE DE COMBAT est trop\n"
	.string "dure! Je n’arrive pas à\p"
	.string "atteindre le sommet!\p"
	.string "Je pense que je vais essayer de\n"
	.string "l’atteindre par l’extérieur…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Je m’épanouis dans l’obscurité…\n"
	.string "Oui… Ce qui compte à mes yeux?\p"
	.string "La PYRAMIDE DE COMBAT…\p"
	.string "J’aime me promener dans\n"
	.string "l’obscurité la plus totale, au\p"
	.string "bord du désespoir.$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Je n’ai pas dormi depuis une\n"
	.string "semaine, mais j’ai réuni une\p"
	.string "super équipe!\p"
	.string "Franchement, je ne peux pas\n"
	.string "perdre. A moi le DOJO DE COMBAT!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Tu es ici grâce à SCOTT? Il est\n"
	.string "bizarre, quand même, non?\p"
	.string "Il est très fort pour repérer\n"
	.string "les DRESSEURS qui ont du talent,\p"
	.string "oui…\p"
	.string "Mais je ne l’ai absolument\n"
	.string "jamais vu se battre.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG! Je crois en toi, mon bébé!\p"
	.string "Je te préparerai tout ce que tu\n"
	.string "voudras si tu gagnes, mon petit\p"
	.string "ZIGG!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZATON a l’air absent…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Les cuisiniers du PALACE disent\n"
	.string "que je suis un fouineur. C’est\p"
	.string "peut-être vrai…\p"
	.string "Ta toque est de travers! C’est\n"
	.string "tombé par terre, ramasse vite!\p"
	.string "Vite, c’est presque l’heure du\n"
	.string "dîner!\p"
	.string "Je ne peux pas m’empêcher de\n"
	.string "mettre mon grain de sel…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Je ne fais plus très peur, mais\n"
	.string "dans le temps, j’ai battu un\p"
	.string "CHAMPION D’ARENE.\p"
	.string "Qui sait, peut-être que je\n"
	.string "devrais m’y remettre!?!$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Sur mon VELO, je suis rapide.\n"
	.string "Aux combats aussi!\p"
	.string "Je gagne mes combats en un clin\n"
	.string "d’œil!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Je suis plus forte que mon père\n"
	.string "aux POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Allez, mon bébé! Va gagner pour\n"
	.string "papa!\p"
	.string "Tu ressembles à ta mère, tu vas\n"
	.string "les mener par le bout du nez!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Je viens de très loin, j’avais\n"
	.string "entendu dire qu’il y avait une\p"
	.string "jolie fille au DOJO DE COMBAT.\p"
	.string "Tu sais ce que j’ai trouvé à la\n"
	.string "place?\p"
	.string "Un ramassis de fanas d’arts\n"
	.string "martiaux!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Des fois, je vois un vieil homme\n"
	.string "à l’air très important qui entre\p"
	.string "ici.\p"
	.string "Il a des POKéMON magnifiques. Il\n"
	.string "a l’air très gentil.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
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

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Mince, alors! C’est la première\n"
	.string "fois que je perds!\p"
	.string "Je me suis fait écraser comme un\n"
	.string "moucheron!\p"
	.string "Et en plus, on vient me dire que\n"
	.string "je n’ai aucun talent! Mince…$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Cet homme a dû se battre contre\n"
	.string "un DRESSEUR horriblement fort à\p"
	.string "la TOUR DE COMBAT.\p"
	.string "Et maintenant, regarde-le…\p"
	.string "Si tu décides d’aller à la TOUR\n"
	.string "DE COMBAT, fais bien attention.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Chouette! J’ai enfin assez de\n"
	.string "POINTS DE COMBAT!\p"
	.string "Je pense que je vais les\n"
	.string "échanger contre une autre\p"
	.string "POUPEE!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Waouh… Alors comme ça, c’est le\n"
	.string "HALL DE CLASSEMENT!\p"
	.string "J’aimerais qu’on se souvienne de\n"
	.string "moi. J’aimerais que mon nom soit\p"
	.string "inscrit ici. Je veux passer à la\n"
	.string "postérité!$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Avec toi à mes côtés, rien ne\n"
	.string "peut m’arrêter.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
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

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "La ZONE DE COMBAT n’est pas\n"
	.string "réservée qu’aux bons DRESSEURS.\p"
	.string "Il paraît que des gens ayant\n"
	.string "d’autres aptitudes ont été\p"
	.string "invités aussi.\p"
	.string "Ce SCOTT…\p"
	.string "Peut-être qu’il avait une idée\n"
	.string "derrière la tête en construisant\p"
	.string "cet endroit…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Pardon, petit. As-tu une bonne\n"
	.string "vue?\p"
	.string "Il y a un arbre bizarre là-bas.\n"
	.string "J’ai l’impression qu’il bouge.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Pardon, petit. As-tu une bonne\n"
	.string "mémoire?\p"
	.string "Il me semble qu’il y avait un\n"
	.string "arbre bizarre là-bas, avant.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "… Je l’ai vu!\p"
	.string "J’ai vu un POKéMON du genre\n"
	.string "gluant avec une longue queue!\p"
	.string "Il se cachait derrière un rocher\n"
	.string "et n’arrêtait pas de me\p"
	.string "regarder!$"
