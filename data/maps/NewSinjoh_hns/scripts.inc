NewSinjoh_hns_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_On_Transition
	.byte 0

NewSinjoh_On_Transition:
    setflag FLAG_VISITED_NEW_SINJOH
	end

NewSinjoh_EventScript_TriggerNorthGate::
	lock
	msgbox NewSinjoh_Text_TriggerNorthGate, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

NewSinjoh_Text_TriggerNorthGate:
	.string "Mieux vaut ne pas faire attendre\n"
	.string "les danseuses en kimono.$"

NewSinjoh_EventScript_PetStantler::
    lock
	faceplayer
	playmoncry SPECIES_STANTLER, 0
	msgbox NewSinjoh_Text_Stantler_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Text_Stantler_Cry:
    .string "Lerrrrr!$"

NewSinjoh_EventScript_Steven::
	msgbox NewSinjoh_Text_Steven, MSGBOX_AUTOCLOSE
	end

NewSinjoh_Text_Steven:
	.string "PIERRE: Madame, puis-je vous\n"
	.string "accompagner jusqu'à la source?\p"
	.string "Il semble y avoir de la place.$"

NewSinjoh_MilkMan_EventScript_Seller::
	lock
	faceplayer
	checkitem ITEM_MOOMOO_MILK, 99
	goto_if_eq VAR_RESULT, 1, MilkMan_EventScript_Battle
	showmoneybox 0, 0
	msgbox NewSinjoh_MilkMan_text_BuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk
	msgbox NewSinjoh_MilkMan_NoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

NewSinjoh_EventScript_MilkMan_BuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_MilkMan_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox NewSinjoh_MilkMan_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, NewSinjoh_EventScript_MilkMan_BuyMilk

	msgbox NewSinjoh_MilkMan_GotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox NewSinjoh_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_BagFull::
	msgbox NewSinjoh_MilkMan_NoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

NewSinjoh_MilkMan_NotEnough::
	msgbox NewSinjoh_MilkMan_NoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSinjoh_MilkMan_text_BuyMilk:
	.string "Je suis le laitier.\p"
	.string "Mon lait est délicieux.\p"
	.string "Si tu en veux aujourd'hui, c'est\n"
	.string "¥500.$"

NewSinjoh_MilkMan_GotMilk:
	.string "Et voilà!\n"
	.string "Il contient ce dont le monde\l"
	.string "a besoin.$"

NewSinjoh_MilkMan_NoMoney:
	.string "Désolé.\n"
	.string "Reviens avec de l'argent et on\l"
	.string "fera affaire!$"

NewSinjoh_MilkMan_NoRoom:
	.string "On dirait que ton SAC est plein.$"

NewSinjoh_MilkMan_NoSale:
	.string "Tu n'en veux pas?\n"
	.string "Il a ce que le monde mérite.$"

NewSinjoh_MilkMan_Text_WouldYouLikeAnother:
	.string "Tu en veux un autre?$"

NewSinjoh_Text_GotMilk:
	.string "{PLAYER} obtient du LAIT MEUMEU.$"

MilkMan_EventScript_Battle:: 
    msgbox MilkMan_Battle_text
    Trainerbattle_no_intro TRAINER_MILKMAN_HNS, NewSinjoh_MilkMan_text_Lose
    release
    end

MilkMan_Battle_text:
	.string "Je suis le laitier,\p"
	.string "mon lait est délicieux.\p"
	.string "Livraison spéciale aujourd'hui!$"

NewSinjoh_MilkMan_text_Lose:
	.string "Ce monde est parfait,\n"
	.string "n'est-ce pas?$"

NewSinjoh_Script_TravelMart::
	lock
	faceplayer
	message NewSinjoh_Text_TravelShopGreeting
	waitmessage
	pokemart NewSinjoh_Pokemart_TravelShop
	msgbox NewSinjoh_Text_TravelShopEnd, MSGBOX_DEFAULT
	release
	end

	.align 2
NewSinjoh_Pokemart_TravelShop:
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ELIXER
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_MAX_LURE
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NONE
	release
	end

NewSinjoh_Text_TravelShopGreeting:
	.string "Bienvenue dans ma boutique.\n"
	.string "Que puis-je faire pour toi?$"

NewSinjoh_Text_TravelShopEnd:
	.string "Reviens nous voir.$"

Script_NewSinjoh_Traveler_Brother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_TravelBrother_Greeting
	release
	end

NewSinjoh_Text_TravelBrother_Greeting:
    .string "Tous nos produits sont faits\n"
	.string "maison et cultivés ici!\p"
	.string "Ma grande sœur a ouvert cette\n"
	.string "boutique.\p"
	.string "Aucun POKéMART ne s'installe\n"
	.string "aussi loin d'une grande ville.$"

NewSinjoh_EventScript_Josh::
	msgbox NewSinjoh_Text_Josh, MSGBOX_NPC
	end

NewSinjoh_Text_Josh:
	.string "Cet endroit est incroyable!\p"
	.string "Cacher ces sources chaudes au\n"
	.string "reste du monde est un scandale.\p"
	.string "Je vais prévenir tous mes amis!$"

NewSinjoh_EventScript_Janice::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_JaniceAfter
	msgbox NewSinjoh_Text_Janice, MSGBOX_NPC
	end
NewSinjoh_EventScript_JaniceAfter::
	msgbox NewSinjoh_Text_JaniceAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Janice:
	.string "Ces sources sont magiques,\n"
	.string "mais j'ai l'impression que les\l"
	.string "habitants nous regardent de\l"
	.string "travers.$"
NewSinjoh_Text_JaniceAfter:
	.string "Ces sources sont magiques,\n"
	.string "et les habitants sont si gentils\l"
	.string "quand on les connaît mieux!$"

NewSinjoh_EventScript_OldLady1::
	msgbox NewSinjoh_Text_OldLady1, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady1:
	.string "Rien de tel qu'une belle vue\n"
	.string "revigorer une vieille âme.$"

NewSinjoh_EventScript_OldLady2::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady2Steven
	msgbox NewSinjoh_Text_OldLady2, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady2Steven::
	msgbox NewSinjoh_Text_OldLady2Steven, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady2:
	.string "Formidable, maintenant ces\n"
	.string "touristes monopolisent nos\l"
	.string "sources chaudes!\p"
	.string "Ces derniers temps, les ennuis\n"
	.string "n'arrêtent pas!$"
NewSinjoh_Text_OldLady2Steven:
	.string "Quel beau jeune homme!\p"
	.string "Ces touristes ne sont peut-être\n"
	.string "pas si terribles, finalement.$"

NewSinjoh_EventScript_OldLady3::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady3After
	msgbox NewSinjoh_Text_OldLady3, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady3After::
	msgbox NewSinjoh_Text_OldLady3After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady3:
	.string "Comment cette femme peut-elle\n"
	.string "être si grossière avec nos\l"
	.string "invités?\p"
	.string "Elle devrait faire trempette\n"
	.string "dans les sources.\p"
	.string "Il y a bien assez de place\n"
	.string "pour tout le monde.$"
NewSinjoh_Text_OldLady3After:
	.string "On dirait que tout le monde\n"
	.string "s'habitue à vivre ensemble ici.\p"
	.string "Tant mieux!$"

NewSinjoh_EventScript_SpringsSage::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_SpringsSageAfter
	msgbox NewSinjoh_Text_SpringsSage, MSGBOX_NPC
	end
NewSinjoh_EventScript_SpringsSageAfter::
	msgbox NewSinjoh_Text_SpringsSageAfter, MSGBOX_NPC
	end

NewSinjoh_Text_SpringsSage:
	.string "Depuis l'arrivée des nouveaux\n"
	.string "venus, notre communauté connaît\l"
	.string "divisions et conflits.\p"
	.string "Quel que soit ton point de vue,\n"
	.string "il est clair que l'équilibre a\l"
	.string "été perturbé.\p"
	.string "Sois aimable avec les habitants\n"
	.string "comme avec les touristes.$"
NewSinjoh_Text_SpringsSageAfter:
	.string "Les choses vont mieux depuis que\n"
	.string "les Pokémon légendaires ont été\l"
	.string "apaisés.\p"
	.string "L'équilibre est revenu à SINJOH.$"

NewSinjoh_EventScript_Sage2::
	msgbox NewSinjoh_Text_Sage2, MSGBOX_NPC
	end

NewSinjoh_Text_Sage2:
	.string "Les temps changent, mais les\n"
	.string "CERFROUSSE se réunissent encore.\l"
	.string "Nous pouvons nous en réjouir.$"

NewSinjoh_EventScript_Daughter::
	msgbox NewSinjoh_Text_Daughter, MSGBOX_NPC
	end

NewSinjoh_Text_Daughter:
    .string "Youhouuuuu!!\p"
    .string "Regarde, Maman!\n"
    .string "Sans les mains!\p"
	.string "Comme les snowboardeurs!$"

NewSinjoh_EventScript_Mother::
	lock
	faceplayer
	msgbox NewSinjoh_Text_Mother, MSGBOX_AUTOCLOSE
	turnobject LOCALID_NEWSINJOH_MOTHER, DIR_EAST
	release
	end

NewSinjoh_Text_Mother:
    .string "Regarde ma petite chérie!\p"
    .string "Cette patinoire existe depuis\n"
	.string "des générations.\p"
	.string "Mais les enfants n'y jouaient pas\n"
	.string "pas avant l'arrivée des nouveaux\l"
	.string "venus.$"

NewSinjoh_EventScript_Welcome_Sign::
	msgbox NewSinjoh_Text_Welcome_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Welcome_Sign:
	.string "NOUVEAU SINJOH$"

NewSinjoh_EventScript_Resturant_Sign::
	msgbox NewSinjoh_Text_Resturant_Sign, MSGBOX_SIGN
	end

NewSinjoh_Text_Resturant_Sign:
	.string "CAFÉ FAMILIAL$"

NewSinjoh_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_HikerAfter
	msgbox NewSinjoh_Text_Hiker, MSGBOX_NPC
	end
NewSinjoh_EventScript_HikerAfter::
	msgbox NewSinjoh_Text_HikerAfter, MSGBOX_NPC
	end

NewSinjoh_Text_Hiker:
	.string "Les affaires sont florissantes!\p"
	.string "Depuis que les citadins aiment\n"
	.string "notre petite ville, les prix ont\l"
	.string "augmenté.$"
NewSinjoh_Text_HikerAfter:
	.string "Les affaires sont florissantes!\p"
	.string "Et grâce aux pourboires du type\n"
	.string "aux cheveux argentés, les prix\l"
	.string "ont baissé!$"

NewSinjoh_EventScript_OldLady4::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, NewSinjoh_EventScript_OldLady4After
	msgbox NewSinjoh_Text_OldLady4, MSGBOX_NPC
	end
NewSinjoh_EventScript_OldLady4After::
	msgbox NewSinjoh_Text_OldLady4After, MSGBOX_NPC
	end

NewSinjoh_Text_OldLady4:
	.string "Je ne vends qu'aux habitants!$"
NewSinjoh_Text_OldLady4After:
	.string "Je ne vends TOUJOURS qu'aux\n"
	.string "habitants!$"

NewSinjoh_EventScript_Item_DuskBall::
	finditem ITEM_DUSK_BALL
    end
