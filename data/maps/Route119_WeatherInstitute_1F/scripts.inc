Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "Le CHEF s’intéresse aux\n"
	.string "recherches qu’ils font ici.\p"
	.string "C’est pour ça qu’il nous envoie.\p"
	.string "Occupe-toi de tes oignons!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Quelle humiliation! Se faire\n"
	.string "battre par un gosse…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Notre CHEF sait tout.\p"
	.string "Mais je ne suis qu’un SBIRE. Je\n"
	.string "n’ai aucune idée de ce qu’il\p"
	.string "prépare!$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hein? Qu’est-ce que ce môme fait\n"
	.string "ici?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hein? J’ai perdu?!?$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, non… J’ai perdu contre un\n"
	.string "môme. Je vais me prendre un de\p"
	.string "ces savons…\p"
	.string "Je vais aller me reposer…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Tout le monde est monté à\n"
	.string "l’étage pendant que je dormais!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Ouah, tu es super balèze!\p"
	.string "J’aimerais devenir un DRESSEUR\n"
	.string "DE POKéMON comme toi!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Le PROFESSEUR adore la pluie.\n"
	.string "C’est indéniable.\p"
	.string "Mais s’il continue de pleuvoir,\n"
	.string "les gens auront des ennuis.\p"
	.string "Ça aussi, c’est indéniable.\p"
	.string "Le PROFESSEUR étudie donc la\n"
	.string "pluie pour savoir si elle peut\p"
	.string "être bénéfique.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Au premier étage du CENTRE, nous\n"
	.string "étudions les conditions météo\p"
	.string "dans la région de HOENN.\p"
	.string "Nous avons observé récemment des\n"
	.string "périodes de sécheresse brèves et\p"
	.string "isolées suivies de fortes\n"
	.string "pluies…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Bonjour! Tes actions nous ont\n"
	.string "sauvés!\p"
	.string "Mais je ne comprends pas ce que\n"
	.string "la TEAM AQUA vient faire\p"
	.string "là-dedans.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Il y a un lit… Je vais me\n"
	.string "reposer.$"

