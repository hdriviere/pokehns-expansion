MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "PIERRE: Oh, waouh,\n"
	.string "{PLAYER}{KUN}. Je suis surpris\p"
	.string "que tu aies su où me trouver.\p"
	.string "Est-ce que… tu me considères\n"
	.string "juste comme un maniaque du type\p"
	.string "ROCHE?\p"
	.string "Non, je ne pense pas…\p"
	.string "Nous nous sommes battus côte à\n"
	.string "côte au CENTRE SPATIAL\p"
	.string "d’ALGATIA.\p"
	.string "Tu dois savoir mieux que\n"
	.string "quiconque de quelle façon je me\p"
	.string "bats.\p"
	.string "OK, {PLAYER}{KUN}, si tu\n"
	.string "cherches un vrai défi, je suis\p"
	.string "ton homme!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Toi… Je ne pensais pas que tu\n"
	.string "avais progressé à ce point…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "PIERRE: En y repensant, j’en\n"
	.string "avais eu la certitude lors de\p"
	.string "notre première\p"
	.string "rencontre à la GROTTE GRANITE du\n"
	.string "VILLAGE MYOKARA.\p"
	.string "Ma première impression est\n"
	.string "souvent la bonne.\p"
	.string "Et où veux-tu te rendre?\p"
	.string "… … … … … … … … … … … …\p"
	.string "Pfiuu, même moi, je n’aurais pas\n"
	.string "pu deviner ça.$"

