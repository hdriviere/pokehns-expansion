BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3

	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST_HNS, 5
	waitstate
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_3RD_PLACE
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_2ND_PLACE
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	clearflag FLAG_DISABLE_EXP_GAIN
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSportBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK_HNS, 7, 2
	waitstate
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK_HNS, 35, 7
	waitstate
	releaseall
	end

BugContest_Text_Judging0::
	.string "Le concours est maintenant terminé.\n"
	.string "Choisis le POKéMON que tu souhaites\l"
	.string "garder et faire juger.$"

BugContest_Text_Judging1::
	.string "On va maintenant juger les POKéMON\n"
	.string "que tu as capturés.\p"
	.string "...................\n"
	.string "...................\p"
	.string "Nous avons choisi les vainqueurs!\n"
	.string "Tu es prêt?$"

BugContest_Text_WrongChoiceMon:
	.string "Choisis le POKéMON que tu souhaites\n"
	.string "garder et faire juger.$"

BugContest_Text_DidntCatch:
	.string "Oh non! Tu n'as capturé aucun POKéMON.\n"
	.string "Tu as déclaré forfait.\p"
	.string "Ton équipe va maintenant t'être rendue.$"

BugContest_Text_TimesUp:
	.string "Ding-dong! Le temps est écoulé!$"

BugContest_Text_WhiteOut:
	.string "{PLAYER} n'a plus de POKéMON en état\n"
	.string "de combattre et déclare forfait.$"

BugContest_Text_First1:
	.string "En troisième place: la TOPDRESSEUSE\n"
	.string "BELINDA, qui a capturé un PAPILUSION\l"
	.string "frétillant!$"
BugContest_Text_First2:
	.string "En deuxième place: le SCOUT SHAUN,\n"
	.string "qui a capturé un SCARABRUTE se\l"
	.string "tortillant!$"
BugContest_Text_First3:
	.string "Le gagnant du Concours de Capture\n"
	.string "d'insecte est…\p"
	.string "{PLAYER}, qui a capturé un énorme\n"
	.string "{STR_VAR_1}!$"

BugContest_Text_Second1:
	.string "En troisième place: la TOPDRESSEUSE\n"
	.string "BELINDA, qui a capturé un PAPILUSION\l"
	.string "frétillant!$"
BugContest_Text_Second2:
	.string "En deuxième place: {PLAYER}, qui a\n"
	.string "capturé un {STR_VAR_1} se tortillant!$"
BugContest_Text_Second3:
	.string "Le gagnant du Concours de Capture\n"
	.string "d'insecte est…\p"
	.string "Le SCOUT SHAUN, qui a capturé un\n"
	.string "énorme SCARABRUTE!$"

BugContest_Text_Third1:
	.string "En troisième place: {PLAYER}, qui a\n"
	.string "capturé un {STR_VAR_1} frétillant!$"
BugContest_Text_Third2:
	.string "En deuxième place: la TOPDRESSEUSE\n"
	.string "BELINDA, qui a capturé un PAPILUSION\l"
	.string "se tortillant!$"
BugContest_Text_Third3:
	.string "Le gagnant du Concours de Capture\n"
	.string "d'insecte est…\p"
	.string "Le SCOUT SHAUN, qui a capturé un\n"
	.string "énorme SCARABRUTE!$"

BugContest_Text_TakePartInFuture:
	.string "Merci d'avoir participé!\n"
	.string "Nous espérons te revoir lors d'un\l"
	.string "prochain concours.$"

BugContest_Text_TransferAndReturn:
	.string "Le POKéMON INSECTE choisi va être\n"
	.string "envoyé au PC et ton équipe va\l"
	.string "maintenant t'être rendue.$"
