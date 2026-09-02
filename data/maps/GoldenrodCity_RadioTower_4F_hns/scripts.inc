GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "Lance: Un instant!\p"
	.string "Mais... Tu ne serais pas le\n"
	.string "gêneur du Puits RAMOLOSS?\p"
	.string "Tu veux m’énerver, c’est ça?\n"
	.string "Très bien, tu vas être exaucé!\p"
	.string "Goûte à la fureur d’un\n"
	.string "Commandant de la Team Rocket!$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Ouf...$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "Lance: Tout ce que\n"
	.string "tu as gagné en fin\p"
	.string "de compte, c’est\n"
	.string "de mettre la Team\p"
	.string "Rocket hors d’elle!$"

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "J’écoutais la\n"
	.string "radio en visitant\p"
	.string "les ruines, quand\n"
	.string "soudain j’ai entendu\p"
	.string "une émission que je ne\n"
	.string "connaissais pas.$"

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "Lula: Mais!!! Pourquoi tant de\n"
	.string "haine?\p"
	.string "MIAOUSS, à l’aide!$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "Lula: C’est toi, le Dresseur qui\n"
	.string "m’a aidée? Alors tiens!\p"
	.string "C’est en remerciement!$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "MARIE: Il aide à esquiver les\n"
	.string "attaques ennemies.$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "LULA: Ecoute mon émission avec\n"
	.string "le\p"
	.string "PROF.CHEN: la CHRONIQUE Pokémon.$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MIAOUSS: Miaou...$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "Tu comptes sauver le DIRECTEUR?\p"
	.string "Je crois que ça va pas être\n"
	.string "possible. J'vais t'écraser!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "Incroyable!$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "Je... J'le crois pas!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "Stop! On m'appelle la forteresse\n"
	.string "de la TEAM ROCKET!\p"
	.string "Pas un pas de plus, poussin!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "Tout cassé ma forteresse!$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "Tu as mérité mon respect, alors\n"
	.string "voici un conseil.\p"
	.string "Laisse tomber ta quête pendant\n"
	.string "qu' il en est temps.$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "Quoi? Est-ce que les Pokémon\n"
	.string "sont mignons?\p"
	.string "Les miens seront mignons après\p"
	.string "t'avoir fichu une raclée, ouais!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "Oh, non! Ils sont nuls!$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "Je m'aime! Je m'aime!\p"
	.string "Les Pokémon ça sert à rien!$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "Parfait.\p"
	.string "Cette TOUR RADIO sera parfaite\n"
	.string "pour nos plans.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "Hmmm...\p"
	.string "Tout plan comprend certains\n"
	.string "accrocs.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "Penses-tu vraiment pouvoir\n"
	.string "stopper la TEAM ROCKET?$"

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "3{SUPER_E}: Production$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "3EME STUDIO 2$"
