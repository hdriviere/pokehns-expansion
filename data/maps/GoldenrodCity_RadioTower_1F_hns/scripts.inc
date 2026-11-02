GoldenrodCity_RadioTower_1F_hns_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2_HNS,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "Blanche: Ouuuuuuuiiii! C’est\n"
	.string "Blanche!\p"
	.string "J’ai entendu dire\n"
	.string "qu’ils organisaient\p"
	.string "un quiz et je suis\n"
	.string "venue tenter ma chance\p"
	.string "moi aussi!\p"
	.string "Mais la vache, il est trop dur\n"
	.string "leur quiz!$"

RadioTower1F_Text_Whitney2::
	.string "Blanche: Wah,\n"
	.string "tu déchires toi!\p"
	.string "J’étais allée\n"
	.string "jusqu’à la troisième\p"
	.string "question. J’pensais trop qu’on\p"
	.string "utilisait des Noigrom! Trop dur!\p"
	.string "J’vais m’rentrer à l’Arène...$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox RadioTower1F_Text_PokegearRadio, MSGBOX_AUTOCLOSE
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "Bienvenue!$"

RadioTower1F_Text_ReceptionistNoTours:
    .string "Bonjour. Il n'y a pas de visite\n"
    .string "prévue aujourd'hui.$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "Nous organisons un QUIZ spécial.\p"
    .string "Répondez juste à cinq questions\n"
    .string "pour gagner un COUPON RADIO.\p"
    .string "Vous écouterez de la musique\n"
    .string "partout avec vos Pokémon.\p"
    .string "Voulez-vous tenter le QUIZ?$"

RadioTower1F_Text_QuizQuestion1:
    .string "Question 1:\p"
    .string "Un Pokémon apparaît-il seulement\n"
    .string "le jour?$"

RadioTower1F_Text_QuizQuestion2:
    .string "C'est exact! Question 2:\p"
    .string "Cette proposition est-elle\n"
    .string "correcte?\p"
    .string "On ne peut pas acheter de BAIE à\n"
    .string "la BOUTIQUE.$"

RadioTower1F_Text_QuizQuestion3:
    .string "Dans le mille!\n"
    .string "Question 3:\p"
    .string "FARGAS fabrique-t-il ses BALLS\n"
	.string "avec des NOIGRUMES?$"

RadioTower1F_Text_QuizQuestion4:
    .string "Tout va bien! Question 4:\p"
    .string "ALBERT est-il le\n"
    .string "CHAMPION de MAUVILLE\p"
    .string "et un utilisateur\n"
    .string "de Pokémon oiseaux?$"

RadioTower1F_Text_QuizQuestion5:
    .string "Encore gagné! Voici la dernière\n"
    .string "question:\p"
    .string "SALAMECHE apparaît-il sur les\p"
    .string "machines à sous au CASINO de\n"
    .string "DOUBLONVILLE?$"

RadioTower1F_Text_QuizWin:
    .string "C’est un sans-faute!\n"
    .string "Félicitations!\p"
    .string "Voici votre Coupon Radio!$"

RadioTower1F_Text_PokegearRadio:
    .string "Le Pokématos de {PLAYER} peut\n"
    .string "maintenant servir de radio!$"

RadioTower1F_Text_TuneIn:
    .string "Ecoute bien nos émissions!!!$"

RadioTower1F_Text_WrongAnswer:
    .string "Oh non! Mauvaise réponse! Quel\n"
    .string "dommage!\p"
    .string "Tentez votre chance une nouvelle\n"
    .string "fois!$"

RadioTower1F_Text_DeclineQuiz:
    .string "Oh? Très bien! Revenez si vous\n"
    .string "changez d’avis!$"

RadioTower1F_Text_Lass:
    .string "BEN est un super DJ!!!\p"
    .string "Sa voix me fait super craquer!$"

RadioTower1F_Text_Youngster:
    .string "J'adore LULA de la CHRONIQUE\n"
    .string "Pokémon.\p"
    .string "En tout cas j'adore sa voix...\n"
    .string "C'est déjà ça.$"

RadioTower1F_Text_GruntM3Seen:
    .string "Nous avons enfin envahi la TOUR\n"
    .string "RADIO!\p"
    .string "Vous allez tous trembler devant\n"
    .string "la\p"
    .string "puissance de la TEAM ROCKET!\p"
    .string "Ya ha ha ah ah! On est méchant!$"

RadioTower1F_Text_GruntM3Beaten:
    .string "Trop fort! Désolé, boss…$"

RadioTower1F_Text_GruntM3After:
    .string "Trop balèze.\p"
    .string "Je dois prévenir les autres. Tu\n"
    .string "es un danger...$"

RadioTower1F_Text_Directory:
    .string "RC: Réception 1{SUPER_ER}:\n"
    .string "Produits dérivés\p"
    .string "2{SUPER_E}: Personnel\p"
    .string "3{SUPER_E}: Production\p"
    .string "4{SUPER_E}: Bureau du Directeur$"

RadioTower1F_Text_GotRadio:
	.string "{PLAYER} obtient le COUPON RADIO\n"
	.string "pour le Pokématos!$"

GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	special PickLotteryCornerTicket
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "Bienvenue à la LOTERIE Pokémon.\p"
	.string "Si le numéro du TICKET LOTO\n"
	.string "correspond à l'ID d'un de vos\p"
	.string "Pokémon, un beau cadeau à la clé.\p"
	.string "Tirer un TICKET LOTO?$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "Revenez demain, s'il vous plaît.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "Revenez nous voir.$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "Tirez un TICKET LOTO.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "Le numéro tiré est {STR_VAR_1}.\p"
	.string "Je dois vérifier s'il correspond\n"
	.string "à l'ID d'un de vos Pokémon.\p"
	.string "Veuillez patienter.$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "Félicitations!\p"
	.string "L'ID du {STR_VAR_1} de votre équipe\n"
	.string "correspond au TICKET LOTO!$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "Félicitations!\p"
	.string "L'ID du {STR_VAR_1} stocké sur PC\n"
	.string "correspond au TICKET LOTO!$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "Désolé.\n"
	.string "Aucun numéro ne correspond.$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "Deux chiffres correspondent.\p"
	.string "Vous gagnez le troisième prix!\p"
	.string "Vous remportez {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "Trois chiffres correspondent.\p"
	.string "Vous gagnez le deuxième prix!\p"
	.string "Vous remportez {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "Quatre chiffres correspondent.\p"
	.string "Vous gagnez le premier prix!\p"
	.string "Vous remportez {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "Incroyable, les cinq chiffres\n"
	.string "correspondent!\p"
	.string "Vous gagnez le gros lot!\n"
	.string "Vous remportez {STR_VAR_1}!$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "Oh?\n"
	.string "Vous n'avez pas de place.\p"
	.string "Libérez de la place dans le SAC\n"
	.string "et revenez me voir.$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{PLAYER}?\n"
	.string "Oui, je vous attendais.\p"
	.string "Voici le prix que nous gardions\n"
	.string "pour vous.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "Revenez nous voir.$"
