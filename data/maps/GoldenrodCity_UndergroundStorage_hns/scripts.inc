GoldenrodCity_UndergroundStorage_hns_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19_HNS, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12_HNS, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3_HNS, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
    .string "Comment t'as fait pour arriver\n"
    .string "ici?\p"
    .string "Bon... Tant pis: je dois me\n"
    .string "débarrasser de toi.$"

RadioTowerBasement_Text_GruntM24Beaten:
    .string "J'suis fichu...$"

RadioTowerBasement_Text_GruntM24After:
    .string "On continuera à\n"
    .string "faire vivre la Team\p"
    .string "Rocket jusqu’au\n"
    .string "retour de notre Boss,\p"
    .string "Giovanni.\p"
    .string "On est prêt à tout pour ça!$"

RadioTowerBasement_Text_GruntM14Seen:
    .string "Pas un pas de plus!\p"
    .string "Mes ennemis, j'en fais de la\n"
    .string "purée. A table!$"

RadioTowerBasement_Text_GruntM14Beaten:
    .string "VLAAAAM!$"

RadioTowerBasement_Text_GruntM14After:
    .string "Perdu... Pardon Boss!$"

RadioTowerBasement_Text_GruntM15Seen:
    .string "Ha-ha-ha! Regarde qui voilà!\p"
    .string "Prêt? Je suis vraiment fort!$"

RadioTowerBasement_Text_GruntM15Beaten:
    .string "Ha-ha-ha! Tu es vraiment doué!\p"
    .string "Ce n'est qu'un boulot pour moi,\n"
    .string "mais la TEAM ROCKET fait du mal.\p"
    .string "Ça suffit, je m'en vais.\p"
    .string "Merci. Désolé, GIOVANNI!$"

RadioTowerBasement_Text_GruntM15After:
    .string "Gnyaaaaaak! J'me souviendrai de\n"
    .string "toi!$"

RadioTowerBasement_Text_DirectorIntro:
    .string "Directeur: Qui... Qui es-tu? Tu\n"
    .string "es là pour me sauver?\p"
    .string "Merci!\p"
    .string "Mais... Et la Tour Radio? Que se\n"
    .string "passe-t-il là-bas?\p"
    .string "Quoi?! La Team Rocket l’a\n"
    .string "investie? Je vois. Tiens!\p"
    .string "Prends cette Carte Magnétique.$"

RadioTowerBasement_Text_DirectorCardKey:
    .string "Directeur: Elle te\n"
    .string "permettra d’ouvrir\p"
    .string "la cloison du\n"
    .string "2{SUPER_E} étage.$"

RadioTowerBasement_Text_DirectorAfter:
    .string "Je t’en supplie... Aide-nous.\p"
    .string "Nul ne sait ce qu’ils feront en\n"
    .string "contrôlant le transmetteur.\p"
    .string "Ils pourraient\n"
    .string "même manipuler les\p"
    .string "Pokémon grâce à\n"
    .string "un signal spécial!\p"
    .string "Tu es notre seul espoir.\p"
    .string "Sauve la Tour Radio!\n"
    .string "Le sort de tous\p"
    .string "les Pokémon est\n"
    .string "entre tes mains!$"
