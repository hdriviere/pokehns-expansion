Gate_NationalPark_hns_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveSportBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SPORT_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_DISABLE_EXP_GAIN
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "Bonjour, Dresseur!\p"
	.string "Le Concours de Capture d'insecte\n"
	.string "a lieu aujourd'hui.\p"
	.string "Les règles sont simples.\p"
	.string "Avec un Pokémon de ton équipe,\n"
	.string "attrape un Pokémon Insecte.\p"
	.string "Il sera ensuite évalué.\p"
	.string "Veux-tu tenter ta chance?$"

Route35NationalParkGate_Text_OfficerGiveSportBalls:
	.string "L'EXP gagnée par tes Pokémon\n"
	.string "pendant le concours sera annulée\l"
	.string "à ta sortie.\p"
	.string "Voici les PARC BALLS pour le\n"
	.string "concours.$"

Route35NationalParkGate_Text_ReceivedSportBalls:
	.string "{PLAYER} reçoit des PARC BALLS.$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "Le vainqueur sera celui qui aura\n"
	.string "le Pokémon Insecte\n"
	.string "le plus puissant.\p"
	.string "Si tu épuises tes PARC BALLS,\n"
	.string "le concours prend fin.\p"
	.string "Tu peux attraper jusqu'à\n"
	.string "5 Pokémon.\p"
	.string "Seul le dernier capturé sera\n"
	.string "gardé\l"
	.string "et présenté au concours.\p"
	.string "Va attraper le Pokémon Insecte\n"
	.string "le plus puissant possible!$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "Si tu as plusieurs Pokémon,\n"
	.string "tu devras utiliser le premier\l"
	.string "de ton équipe.\p"
	.string "Ça te convient?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "Parfait. Je vais\n"
	.string "garder les autres\p"
	.string "Pokémon pendant\n"
	.string "le concours.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "{PLAYER} confie ses Pokémon au\n"
	.string "RECEPTIONNISTE.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "Choisis le Pokémon à utiliser\n"
	.string "pendant\p"
	.string "le concours et viens me voir.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "Vraiment? A une prochaine fois\n"
	.string "dans ce cas.$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "Oh-oh... Le premier Pokémon\n"
	.string "de ton\l"
	.string "équipe ne peut pas combattre.\p"
	.string "Échange-le avec celui que tu\n"
	.string "veux utiliser, puis reviens\l"
	.string "me voir.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "Oh-oh... Ton équipe et ta BOITE\n"
	.string "PC sont pleines.\p"
	.string "Tu n'as pas de place pour le\n"
	.string "Pokémon insecte à attraper.\p"
	.string "Fais de la place dans l'équipe\n"
	.string "ou\p"
	.string "dans la BOITE PC et viens me\n"
	.string "voir.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "Oh-oh... Le premier Pokémon\n"
	.string "de ton\l"
	.string "équipe est un OEUF.\p"
	.string "Échange-le avec celui que tu\n"
	.string "veux utiliser, puis reviens\l"
	.string "me voir.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "Le concours d'aujourd'hui est\n"
	.string "terminé. Reviens une autre fois.$"

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "J'adore les Pokémon oiseaux!\p"
	.string "J'en ai vu un de type TÉNÈBRES\n"
	.string "dans le parc\l"
	.string "la nuit dernière!$"

Route35NationalParkGate_Text_BC2:
	.string "J'ai attrapé un énorme\n"
	.string "INSECATEUR!$"

Route35NationalParkGate_Text_Beauty:
	.string "Il gagne toujours ces concours!$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "Il y a des concours\n"
	.string "régulièrement\p"
	.string "au PARC.\n"
	.string "Inscris-toi!$"

Route35NationalParkGate_Text_YoungsterWonders:
	.string "C'est pour quand le prochain\n"
	.string "Concours de Capture?$"

Route35NationalParkGate_Text_ContestExplanation:
	.string "Le Concours de Capture d'insecte\n"
	.string "a lieu le mardi, jeudi\n"
	.string "et samedi.\p"
	.string "Participer suffit pour gagner\n"
	.string "un prix.\p"
	.string "Tu peux aussi garder le Pokémon\n"
	.string "Insecte choisi à la fin\l"
	.string "du concours.$"
