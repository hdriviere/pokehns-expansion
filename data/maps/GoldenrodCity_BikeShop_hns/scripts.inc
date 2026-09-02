GoldenrodCity_BikeShop_hns_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_BICYCLE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "ENREGISTRE le VELO dans le SAC.\p"
	.string "Tu l'utiliseras avec un bouton.\p"
	.string "Pour aller plus vite, tu dois\n"
	.string "d'abord t'arrêter!\p"
	.string "Ce conseil paraît étrange, mais\n"
	.string "les vitesses ne se changent qu'à\p"
	.string "l'arrêt.\p"
	.string "Appuie sur R une fois arrêté.\p"
	.string "Au prochain coup de pédale, tu\n"
	.string "iras beaucoup plus vite!$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "...(soupir)... J'ai déménagé ici\p"
    .string "mais je n'arrive pas à vendre\n"
    .string "mes BICYCLETTES. Pourquoi?\p"
    .string "Pourrais-tu\n"
    .string "faire de la\p"
    .string "BICYCLETTE et me\n"
    .string "faire de la pub?$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "Vraiment? Génial!\p"
    .string "Donne-moi ton nom et ton numéro\n"
    .string "de\p"
    .string "téléphone et je te prêterai une\n"
    .string "BICYCLETTE.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER} emprunte une\n"
    .string "BICYCLETTE.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "Depuis notre départ de KANTO,\n"
	.string "les affaires sont difficiles.\p"
	.string "Merci pour ton aide!\p"
	.string "Montre bien notre changement de\n"
	.string "vitesse breveté!\p"
	.string "Appuie simplement sur R lorsque\n"
	.string "ton VELO est arrêté.\p"
	.string "Attention, tu iras très vite!$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "...(soupir)... Ah, que dire de\n"
    .string "plus...$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "Tout chô tout bô!\p"
    .string "BICYCLETTES de poche de premier\n"
    .string "choix!$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "C’est une Bicyclette toute\n"
    .string "neuve!$"
