BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Bonjour! Si tu veux des infos\n"
	.string "sur la ZONE DE COMBAT, tu es au\p"
	.string "bon endroit.\p"
	.string "Je suis en quelque sorte le\n"
	.string "MORDU DE LA ZONE!\p"
	.string "Toi, tu es un DRESSEUR, n’est-ce\n"
	.string "pas?\p"
	.string "Je serais ravi de partager mes\n"
	.string "infos sur la ZONE DE COMBAT avec\p"
	.string "toi.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Bonjour! Je parierais que tu es\n"
	.string "là pour me faire parler un peu!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Alors? Alors? Alors?\p"
	.string "Mes informations vous ont été\n"
	.string "très utiles, pas vrai?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Voyons voir…\p"
	.string "L’endroit le plus en vue en ce\n"
	.string "moment… {STR_VAR_1}, sans\p"
	.string "hésitation.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Voyons voir…\p"
	.string "Le {STR_VAR_1} de la TOUR DE\n"
	.string "COMBAT est le meilleur du\p"
	.string "moment.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Je suis sûr que je vais\n"
	.string "t’apprendre quelque chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est\p"
	.string "ici.\p"
	.string "C’est un mystérieux DRESSEUR\n"
	.string "surnommé l’AS DU SALON.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "As-tu affronté l’AS DU SALON?\p"
	.string "Elle utilise ces POKéMON quand\n"
	.string "elle veut se mettre à la hauteur\p"
	.string "de l’adversaire:\p"
	.string "Un POKéMON de type PSY, un\n"
	.string "POKéMON VOLCAN de type FEU et un\p"
	.string "POKéMON PIONCEUR de type NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "As-tu affonté l’AS DU SALON\n"
	.string "quand elle est sérieuse?\p"
	.string "Quand elle se bat à fond, elle\n"
	.string "utilise les POKéMON suivants:\p"
	.string "Un POKéMON EON de type\n"
	.string "DRAGON/PSY, un POKéMON FOUDRE de\p"
	.string "type ELECTRIK et un POKéMON\n"
	.string "PIONCEUR de type NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Je vais t’apprendre quelque\n"
	.string "chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est\p"
	.string "ici.\p"
	.string "C’est l’extravagant DRESSEUR\n"
	.string "appelé la STAR DU DOME.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "As-tu affronté la STAR DU DOME?\p"
	.string "Quand il ne prend pas\n"
	.string "l’adversaire au sérieux, il\p"
	.string "utilise ces POKéMON:\p"
	.string "Un POKéMON DRAGON du type\n"
	.string "DRAGON/VOL, un POKéMON\p"
	.string "POISSONBOUE du type EAU/ SOL et\n"
	.string "un POKéMON FLAMME du type\p"
	.string "FEU/VOL.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "As-tu affronté la STAR DU DOME\n"
	.string "quand il se bat sérieusement?\p"
	.string "Quand il veut faire preuve de\n"
	.string "stratégie, il utilise ces trois\p"
	.string "POKéMON:\p"
	.string "Un POKéMON EON de type\n"
	.string "DRAGON/PSY, un POKéMON\p"
	.string "POISSONBOUE de type EAU/SOL et\n"
	.string "un POKéMON PATTEFER de type\p"
	.string "ACIER/PSY.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Je vais t’apprendre quelque\n"
	.string "chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est\p"
	.string "ici.\p"
	.string "C’est l’étrange DRESSEUR appelé\n"
	.string "le CHEF D’USINE.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "As-tu déjà affronté le CHEF\n"
	.string "D’USINE?\p"
	.string "Tu sais… Au combat, il doit\n"
	.string "utiliser trois POKéMON de\p"
	.string "location.\p"
	.string "Il se bat dans les mêmes\n"
	.string "conditions que les autres, en\p"
	.string "fait.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "As-tu déjà affronté le CHEF\n"
	.string "D’USINE quand il se bat\p"
	.string "sérieusement?\p"
	.string "Même quand il veut se battre à\n"
	.string "fond, il doit utiliser trois\p"
	.string "POKéMON de location.\p"
	.string "En fin de compte, il se bat dans\n"
	.string "les mêmes conditions que les\p"
	.string "autres.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Je vais t’apprendre quelque\n"
	.string "chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est\p"
	.string "ici.\p"
	.string "C’est le DRESSEUR effrayant\n"
	.string "appelé la REINE VENIN.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Tu as déjà affronté la REINE\n"
	.string "VENIN?\p"
	.string "Quand elle est de bonne humeur,\n"
	.string "elle utilise ces POKéMON:\p"
	.string "Un POKéMON SERPACROC de type\n"
	.string "POISON, un POKéMON POURRI de\p"
	.string "type INSECTE/ROCHE et un POKéMON\n"
	.string "TENDRE de type EAU.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Tu as déjà affronté la REINE\n"
	.string "VENIN quand elle est énervée?\p"
	.string "Quand elle est vraiment\n"
	.string "agressive, elle utilise ces\p"
	.string "trois POKéMON:\p"
	.string "Un POKéMON SERPACROC de type\n"
	.string "POISON, Un POKéMON SERPENFER de\p"
	.string "type ACIER/SOL et un POKéMON\n"
	.string "TERRIFIANT de type EAU/VOL.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Je vais t’apprendre quelque\n"
	.string "chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est\p"
	.string "ici.\p"
	.string "C’est le DRESSEUR pas mal appelé\n"
	.string "la PRO DU DOJO.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "As-tu déjà affronté la PRO DU\n"
	.string "DOJO?\p"
	.string "Quand elle veut laisser une\n"
	.string "chance à l’adversaire, elle\p"
	.string "utilise ces POKéMON:\p"
	.string "Un POKéMON UNICORNE de type\n"
	.string "INSECTE/ COMBAT, un POKéMON LUNE\p"
	.string "de type TENEBRES et un POKéMON\n"
	.string "EXUVIE de type INSECTE/SPECTRE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "As-tu déjà affronté la PRO DU\n"
	.string "DOJO?\p"
	.string "Si elle ne veut laisser aucune\n"
	.string "chance à l’adversaire, elle\p"
	.string "utilise ces POKéMON:\p"
	.string "Un POKéMON LUNE de type\n"
	.string "TENEBRES, un POKéMON OMBRE de\p"
	.string "type SPECTRE/POISON et un\n"
	.string "POKéMON CHAMPIGNON de type\p"
	.string "PLANTE/COMBAT.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Je vais t’apprendre quelque\n"
	.string "chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est\p"
	.string "ici.\p"
	.string "C’est ce DRESSEUR sinistre\n"
	.string "appelé le CAPT. PALACE.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Tu as déjà affronté le CAPT.\n"
	.string "PALACE?\p"
	.string "S’il veut tester l’adversaire,\n"
	.string "il utilise ces POKéMON:\p"
	.string "Un POKéMON CHOVSOURIS de type\n"
	.string "POISON/ VOL, un POKéMON FAINEANT\p"
	.string "de type NORMAL et un POKéMON\n"
	.string "TRANSPORT de type EAU/GLACE.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Tu as déjà combattu le CAPT.\n"
	.string "PALACE?\p"
	.string "Quand il se bat à fond, il\n"
	.string "utilise ces POKéMON:\p"
	.string "Un POKéMON LEGENDAIRE de type\n"
	.string "FEU, un POKéMON FAINEANT de type\p"
	.string "NORMAL et un POKéMON AURORE de\n"
	.string "type EAU.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Je vais t’apprendre quelque\n"
	.string "chose!\p"
	.string "Un des super DRESSEURS que SCOTT\n"
	.string "appelle les MENEURS DE ZONE est\p"
	.string "ici.\p"
	.string "C’est ce DRESSEUR intrépide\n"
	.string "appelé le ROI PYRAMIDE.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "As-tu déjà affronté le ROI\n"
	.string "PYRAMIDE?\p"
	.string "Quand il veut évaluer\n"
	.string "l’adversaire, il utilise ces\p"
	.string "POKéMON:\p"
	.string "Un POKéMON PIC ROCHEUX de type\n"
	.string "ROCHE, un POKéMON ICEBERG de\p"
	.string "type GLACE et un POKéMON FER de\n"
	.string "type ACIER.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "As-tu déjà affronté le ROI\n"
	.string "PYRAMIDE quand il se bat pour de\p"
	.string "bon?\p"
	.string "Quand il est gonflé à bloc, il\n"
	.string "utilise ces POKéMON:\p"
	.string "Un POKéMON GLACIAIRE de type\n"
	.string "GLACE/VOL, un POKéMON ELECTRIQUE\p"
	.string "de type ELECTRIK/VOL et un\n"
	.string "POKéMON FLAMME de type FEU/VOL.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Oui, il y a plein d’endroits où\n"
	.string "faire des COMBATS DUO.\p"
	.string "Mais il vaut mieux commencer par\n"
	.string "les SALLES DE COMBAT DUO de la\p"
	.string "TOUR DE COMBAT!\p"
	.string "C’est là que tu apprendras ce\n"
	.string "qu’est un COMBAT DUO dans la\p"
	.string "ZONE DE COMBAT.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Fais bien attention à toi.\p"
	.string "Il paraît que certains DRESSEURS\n"
	.string "développent des stratégies\p"
	.string "spéciales pour les COMBATS DUO.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Quand tu y maîtriseras les\n"
	.string "COMBATS DUO, tu pourrais essayer\p"
	.string "d’en faire ailleurs.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Toutes sortes de DRESSEURS se\n"
	.string "trouvent dans le SALON DE\p"
	.string "COMBAT.\p"
	.string "Il se peut que tu rencontres des\n"
	.string "amis ou encore des fans! Ouvre\p"
	.string "les yeux!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Si tu es avec un ami, dirige-toi\n"
	.string "vers la SALLE DE COMBAT MULTI\p"
	.string "LINK.\p"
	.string "Si ton ami est fort, les\n"
	.string "adversaires seront certainement\p"
	.string "de taille!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Quelle capacité de synthèse! Mon\n"
	.string "mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Quel talent d’observation! Mon\n"
	.string "mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Quelle force de persuasion! Mon\n"
	.string "mentor est le meilleur!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "C’est quoi, cet endroit? J’ai un\n"
	.string "peu peur…$"

