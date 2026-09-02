RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Bonjour et bienvenue à la DEVON\n"
	.string "SARL.\p"
	.string "Nous produisons avec fierté des\n"
	.string "objets et médicaments qui\p"
	.string "simplifient la vie.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Une de nos équipes de chercheurs\n"
	.string "s’est fait voler un important\p"
	.string "paquet.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hé, ces CHAUSSURES DE SPORT!\n"
	.string "Elles sortent de nos ateliers!\p"
	.string "J’aime constater que ce que nous\n"
	.string "avons produit sert à quelqu’un.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Ce paquet qui a été volé…\p"
	.string "Bien sûr, c’est important, mais\n"
	.string "ce n’est pas utile à tout le\p"
	.string "monde.\p"
	.string "Et d’après mes calculs, le\n"
	.string "voleur ne doit pas être très\p"
	.string "intelligent.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Ils ont l’air d’avoir retrouvé\n"
	.string "le PACK DEVON qui avait été\p"
	.string "volé.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Désolé, mais seules les\n"
	.string "personnes autorisées peuvent\p"
	.string "entrer ici.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "C’est trop bête! Comment a-t-on\n"
	.string "pu se faire voler?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Bonjour! C’est toujours avec\n"
	.string "grand plaisir que nous vous\p"
	.string "accueillons ici!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Des échantillons de pierres et\n"
	.string "de métaux sont placés dans une\p"
	.string "vitrine.\p"
	.string "Il y a un panneau avec quelque\n"
	.string "chose d’écrit…\p"
	.string "“DEVON était à l’origine une\n"
	.string "compagnie d’exploitation\p"
	.string "minière.\p"
	.string "La compagnie a également produit\n"
	.string "de l’acier en exploitant la\p"
	.string "limaille se trouvant dans le\n"
	.string "sable.\p"
	.string "DEVON s’est sans cesse développé\n"
	.string "depuis ses humbles débuts.\p"
	.string "DEVON fabrique maintenant une\n"
	.string "grande variété de produits\p"
	.string "industriels.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "La vitrine est pleine de\n"
	.string "prototypes et d’échantillons.\p"
	.string "Il y a un panneau avec une\n"
	.string "inscription…\p"
	.string "“En plus de ses produits\n"
	.string "industriels, DEVON souhaite se\p"
	.string "développer sur le\p"
	.string "marché pharmaceutique pour\n"
	.string "améliorer notre qualité de vie.\p"
	.string "Récemment, DEVON a commercialisé\n"
	.string "des outils pour les DRESSEURS,\p"
	.string "comme les\p"
	.string "POKé BALLS et les systèmes\n"
	.string "POKéNAV.”$"

