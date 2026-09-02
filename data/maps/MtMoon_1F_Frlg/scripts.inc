MtMoon_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
	.string "YAHA! Tu m'as fait peur! Quoi?\n"
	.string "Mais t'es super jeune!$"

MtMoon_1F_Text_MarcosDefeat::
	.string "Whoa! Tu m'as encore fait\n"
	.string "peur!!!$"

MtMoon_1F_Text_MarcosPostBattle::
	.string "Cet endroit n'est pas pour les\n"
	.string "mioches comme toi!$"

MtMoon_1F_Text_JoshIntro::
	.string "Tu es aussi ici pour explorer?$"

MtMoon_1F_Text_JoshDefeat::
	.string "Hmm! Perdre, ça craint vraiment!$"

MtMoon_1F_Text_JoshPostBattle::
	.string "J'suis venu jusque-là pour\n"
	.string "impressionner les filles!$"

MtMoon_1F_Text_MiriamIntro::
	.string "Houlà! C'est plus balèze que\n"
	.string "j'croyais, ici!$"

MtMoon_1F_Text_MiriamDefeat::
	.string "RHAA! J'ai perdu!$"

MtMoon_1F_Text_MiriamPostBattle::
	.string "Comment on fait pour sortir\n"
	.string "d'ici?$"

MtMoon_1F_Text_JovanIntro::
	.string "Oh! Tu m'cherches ou quoi?$"

MtMoon_1F_Text_JovanDefeat::
	.string "Mes POKéMON sont nuls!$"

MtMoon_1F_Text_JovanPostBattle::
	.string "J'dois m'trouver des POKéMON\n"
	.string "plus costauds!$"

MtMoon_1F_Text_IrisIntro::
	.string "De quoi? J'attends mes potes\n"
	.string "ici.$"

MtMoon_1F_Text_IrisDefeat::
	.string "Nan! J'ai perdu?$"

MtMoon_1F_Text_IrisPostBattle::
	.string "Y paraît qu'il y a des fossiles\n"
	.string "très anciens dans le coin.$"

MtMoon_1F_Text_KentIntro::
	.string "Dans les grottes, on trouve de\n"
	.string "la racaille. T'es qui toi?$"

MtMoon_1F_Text_KentDefeat::
	.string "Tu m’as eu!$"

MtMoon_1F_Text_KentPostBattle::
	.string "Je les ai vus! C'était la TEAM\n"
	.string "ROCKET!$"

MtMoon_1F_Text_RobbyIntro::
	.string "Je traverse ces grottes pour\n"
	.string "aller à AZURIA!$"

MtMoon_1F_Text_RobbyDefeat::
	.string "J'ai… Perdu…$"

MtMoon_1F_Text_RobbyPostBattle::
	.string "Les NOSFERAPTI sont puissants!\n"
	.string "En attraper peut être utile!$"

MtMoon_1F_Text_ZubatIsABloodsucker::
	.string "Attention! Les NOSFERAPTI sont\n"
	.string "des suceurs de sang!$"

MtMoon_1F_Text_BrockHelpsExcavateFossils::
	.string "Salut! Je cherche des fossiles\n"
	.string "ici, sous le MONT SELENITE.\p"
	.string "PIERRE de l'ARENE d'ARGENTA\n"
	.string "vient souvent m'aider.$"
