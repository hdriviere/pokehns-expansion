VioletCity_TrainerSchool_hns_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "Je n'ai pas grandi avec la GBA,\n"
	.string "mais j'adore les jeux Pokémon!\p"
	.string "Autrefois, il fallait combattre\n"
	.string "de nombreux Pokémon sauvages\p"
	.string "pour gagner assez d'EXP.\p"
	.string "Dans les jeux récents, le MULTI\n"
	.string "EXP accélère trop les niveaux.\p"
	.string "Ici, il est réglé pour garder\n"
	.string "tes Pokémon au bon niveau,\p"
	.string "ou un peu plus haut, selon tes\n"
	.string "combats.\p"
	.string "Pour jouer comme dans les\n"
	.string "générations 1 à 4, désactive-le.\p"
	.string "Pour une expérience moderne,\n"
	.string "active le MULTI EXP.\p"
	.string "À toi de choisir comment jouer!$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "THEOPHILE est mon nom!\p"
	.string "Sensationnels sont les Pokémon!\p"
	.string "Devenir meilleur Dresseur, je\n"
	.string "t'apprendrai!$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Certains Pokémon sont faibles au\n"
	.string "départ.\p"
	.string "Ils exigent bien plus d'EXP que\n"
	.string "d'autres pour devenir forts.\p"
	.string "EMBRYLEX est faible au départ,\n"
	.string "mais devient un grand TYRANOCIF\p"
	.string "grâce à beaucoup d'EXP.\p"
	.string "Seuls les Dresseurs très motivés\n"
	.string "devraient élever un tel Pokémon.$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "Très bien! Ton éducation je\n"
	.string "ferai!\p"
	.string "En combat, le premier Pokémon de\n"
	.string "ta liste sort le premier!\p"
	.string "Changer l'ordre de la liste peut\n"
	.string "t'aider à gagner ou perdre!\p"
	.string "Tu veux en savoir plus?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "Alors, on veut savoir comment\n"
	.string "bien élever ses p'tits Pokémon?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "Très bien. Ton éducation\n"
	.string "je ferai!\p"
	.string "Tout Pokémon qui participe au\n"
	.string "combat, même brièvement,\p"
	.string "gagne des points d'EXP.\p"
	.string "Mets d'abord un Pokémon faible,\n"
	.string "puis change-le vite!\p"
	.string "Ainsi, les Pokémon faibles\n"
	.string "deviendront forts!$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "Oh! Elève intelligent tu es!\n"
	.string "Plus rien à t'apprendre je n'ai!\p"
	.string "Pour en savoir plus, parle aux\n"
	.string "élèves!$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "Des Pokémon qui n'évoluaient que\n"
	.string "par échange peuvent maintenant\p"
	.string "évoluer en gagnant des niveaux.\p"
	.string "MACHOPEUR et GRAVALANCH évoluent\n"
	.string "au niveau 38, KADABRA et\p"
	.string "SPECTRUM au niveau 42.\p"
	.string "Certains objets, comme la PEAU\n"
	.string "METAL, font aussi évoluer.\p"
	.string "Le Pokémon doit les tenir lors\n"
	.string "d'un gain de niveau.$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "Les Pokémon rares d'une zone\n"
	.string "sont visibles dans le décor!\p"
	.string "Mais explore les routes de JOUR\n"
	.string "comme de NUIT!$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "Les BAIES de JOHTO soignent et\n"
	.string "servent à fabriquer des BALLS.\p"
	.string "Celles de KANTO peuvent réduire\n"
	.string "les statistiques d'un Pokémon.\p"
	.string "Le DOJO de KANTO permet aux\n"
	.string "Pokémon de parfaire leurs stats.$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Attention: tes adversaires ont\n"
	.string "désormais des équipes couvrant\p"
	.string "davantage de types.\p"
	.string "Ton voyage sera donc bien plus\n"
	.string "difficile.$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "Le tableau décrit les capacités\n"
	.string "CS des Pokémon.\p"
	.string "Débloquées, elles s'utilisent\n"
	.string "sans être enseignées.$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "C'est le cahier de ce gamin...\p"
	.string "Attrapez les Pokémon en lançant\n"
	.string "les Poké BALLS.\p"
	.string "Vous pouvez transporter six\n"
	.string "Pokémon avec vous.\p"
	.string "Continuer à lire?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Avant de lancer une Poké Ball,\n"
	.string "affaiblissez d'abord la cible.\p"
	.string "Un Pokémon empoisonné ou brûlé\n"
	.string "est plus facile à attraper.\p"
	.string "Continuer à lire?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Certaines capacités\n"
	.string "peuvent embrouiller\p"
	.string "l'esprit du\n"
	.string "Pokémon adverse.\p"
	.string "Une fois confus, le Pokémon peut\n"
	.string "s'attaquer luimême.\p"
	.string "Fuir le combat annule tout effet\n"
	.string "de confusion.\p"
	.string "Continuer à lire?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "Les personnes qui attrapent et\n"
	.string "utilisent les Pokémon pour les\p"
	.string "combats sont des dresseurs de\n"
	.string "Pokémon.\p"
	.string "Leur but est de défier et\n"
	.string "vaincre\p"
	.string "tous les dresseurs et CHAMPIONS\n"
	.string "d'ARENES.\p"
	.string "La page suivante est...blanche!\p"
	.string "Gamin: Maiiheuu...\p"
	.string "J'ai rien écrit d'autre...$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "Cette superbe machine imprime\n"
	.string "des données en autocollants!$"
