SinjohRuins_House1_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SinjohRuins_Lab_OnFrame
	map_script 	MAP_SCRIPT_ON_TRANSITION, SinjohRuins_Lab_OnTransition
	.byte 0

SinjohRuins_Lab_OnTransition::
	call_if_eq VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_SetupFinalPlateScene
	end

SinjohRuins_Lab_OnFrame::
	map_script_2 VAR_SINJOH_STORYLINE, 7, SinjohRuins_Lab_FinalPlateScene
	.2byte 0

@==========================Intro Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_TriggerIntroTop::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkDown1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroMid::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntroBot::
	lock
	playse SE_PIN
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_PLAYER, Common_Movement_WalkUp1
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenMeetPlayer
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	goto SinjohRuins_Lab_EventScript_TriggerIntro

SinjohRuins_Lab_EventScript_TriggerIntro::
	turnobject LOCALID_PLAYER, DIR_EAST
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenSitsDown
	delay 10
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerGoesToTable
	delay 40
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkDown
	waitmovement 0
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	waitmovement LOCALID_NEWSINJOH_LAB_LINGUIST
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_NEWSINJOH_LAB_LINGUIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene4, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_NEWSINJOH_LAB_LINGUIST, SinjohRuins_Lab_Movement_LinguistWalkUp
	applymovement2 LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
SinjohRuins_Lab_EventScript_IntroChoice::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutsceneRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SinjohRuins_Lab_EventScript_IntroChoseYes
	goto SinjohRuins_Lab_EventScript_IntroChoice

SinjohRuins_Lab_EventScript_IntroChoseYes::
	msgbox SinjohRuins_Lab_Text_StevenIntroCutscene6, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SINJOH_STORYLINE, 6
	setvar VAR_NOBLE_SNEASLER, 1
	setvar VAR_NOBLE_OVERQWIL, 1
	setvar VAR_NOBLE_WYRDEER, 1
	setvar VAR_NOBLE_ARCANINE, 1
	setvar VAR_NOBLE_URSALUNA, 1
	setvar VAR_NOBLE_KLEAVOR, 1
	setvar VAR_NOBLE_ELECTRODE, 1
	setvar VAR_NOBLE_TYPHLOSION, 1
	release
	end

SinjohRuins_Lab_Movement_StevenMeetPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SinjohRuins_Lab_Movement_StevenSitsDown:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

SinjohRuins_Lab_Movement_PlayerGoesToTable:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

SinjohRuins_Lab_Movement_LinguistWalkDown:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

SinjohRuins_Lab_Movement_LinguistWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end


SinjohRuins_Lab_Text_StevenIntroCutscene1:
	.string "PIERRE: Hmm?$"

SinjohRuins_Lab_Text_StevenIntroCutscene2:
	.string "PIERRE: {PLAYER}!\p"
	.string "Je reconnaîtrais ce regard entre\n"
	.string "mille.\p"
	.string "Qu'est-ce qui t'amène si loin\n"
	.string "dans le nord?\p"
	.string ".............\p"
	.string "Je vois. Les danseuses en kimono\n"
	.string "du NOUVEAU SINJOH t'ont envoyé\l"
	.string "nous aider dans nos recherches.\p"
	.string "Alors, laisse-moi t'expliquer.$"

SinjohRuins_Lab_Text_StevenIntroCutscene3:
	.string "PIERRE: En apprenant l'existence\n"
	.string "de ces ruines, il fallait que je\l"
	.string "les voie de mes propres yeux.\p"
	.string "J'ai réuni une équipe de DEVON\n"
	.string "SARL et lancé une expédition.\p"
	.string "Qui sait ce qui est enfoui ici?\p"
	.string "Nous en avons déjà beaucoup\n"
	.string "appris.$"

SinjohRuins_Lab_Text_StevenIntroCutscene4:
	.string "LINGUISTE: Je n'ai pas encore\n"
	.string "traduit tous les glyphes trouvés\l"
	.string "autour des ruines, mais j'en ai\l"
	.string "compris certains aspects.\p"
	.string "Il existe 17 étranges PLAQUES.\p"
	.string "Elles sont liées à ces ruines,\n"
	.string "mais nous n'en avons trouvé\l"
	.string "qu'une pour l'instant.\p"
	.string "Les autres seraient gardées par\n"
	.string "des Pokémon et des Dresseurs\l"
	.string "d'une puissance redoutable.$"

SinjohRuins_Lab_Text_StevenIntroCutscene5:
	.string "PIERRE: Tu sais tout, {PLAYER}.\p"
	.string "Les POKéMON MONARQUES gardant\n"
	.string "les autres PLAQUES sont trop\l"
	.string "forts\l"
	.string "pour mon équipe, j'en ai peur.\p"
	.string "Et je dois rester ici pour\n"
	.string "superviser les recherches.\p"
	.string "Mais je t'en crois capable.\n"
	.string "Veux-tu nous aider?$"

SinjohRuins_Lab_Text_StevenIntroCutscene6:
	.string "Excellent.\p"
	.string "D'après les glyphes, les PLAQUES\n"
	.string "sont détenues par des POKéMON\l"
	.string "MONARQUES et de puissants\l"
	.string "Dresseurs partout dans SINJOH.\p"
	.string "Je t'appellerai sur le POKéMATOS\n"
	.string "si nous apprenons quelque chose.\p"
	.string "Merci, {PLAYER}.$"

SinjohRuins_Lab_Text_StevenIntroCutsceneRefused:
	.string "Tu es sûr?\p"
	.string "Qui sait ce que nous trouverons\n"
	.string "enfoui ici?\p"
	.string "Tu ne veux pas reconsidérer?$"

@==========================Final plate Cutscene SCRIPTS================================================================================

SinjohRuins_Lab_SetupFinalPlateScene::
	setobjectxyperm LOCALID_SINJOHRUINS_LAB_STEVEN, 4, 7
	setobjectmovementtype LOCALID_SINJOHRUINS_LAB_STEVEN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_NEWSINJOH_LAB_LINGUIST, 5, 7
	setobjectmovementtype LOCALID_NEWSINJOH_LAB_LINGUIST, MOVEMENT_TYPE_FACE_LEFT
	return

SinjohRuins_Lab_FinalPlateScene::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_SINJOHRUINS_LAB_STEVEN
	turnobject LOCALID_SINJOHRUINS_LAB_STEVEN, DIR_SOUTH
	delay 30
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, Common_Movement_WalkDown1
	turnobject LOCALID_NEWSINJOH_LAB_LINGUIST, DIR_SOUTH
	delay 30
	msgbox SinjohRuins_Lab_Text_FinalPlateScene1, MSGBOX_DEFAULT
	closemessage
	dofieldeffectsparkle 3, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 3
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 200
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 40  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox SinjohRuins_Lab_Text_FinalPlateScene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SinjohRuins_Lab_Movement_PlayerLeaveLab
	applymovement LOCALID_SINJOHRUINS_LAB_STEVEN, SinjohRuins_Lab_Movement_StevenLeaveLab
	waitmovement 0
	waitmovement 0
	setvar VAR_SINJOH_STORYLINE, 8
	warp MAP_SINJOH_RUINS_HNS, 0
	waitstate
	end

SinjohRuins_Lab_Text_FinalPlateScene1:
	.string "PIERRE: {PLAYER}!\p"
	.string "Je crois savoir ce qui va se\n"
	.string "passer en réunissant les 17\l"
	.string "PLAQUES.\p"
	.string "Je sens...\l"
	.string ".....................$"

SinjohRuins_Lab_Text_FinalPlateScene2:
	.string "PIERRE: Je dois voir cela de mes\n"
	.string "propres yeux!\p"
	.string "Dehors, {PLAYER}!$"

SinjohRuins_Lab_Movement_PlayerLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

SinjohRuins_Lab_Movement_StevenLeaveLab:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end

@==========================NPC SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_Steven::
	lock
	faceplayer
	buffernumberstring STR_VAR_1, VAR_PLATECOUNTER
	goto_if_ge VAR_PLATECOUNTER, 17, SinjohRuins_Lab_EventScript_StevenAfterAllPlates
	goto_if_ge VAR_PLATECOUNTER, 15, SinjohRuins_Lab_EventScript_StevenAfter15Plates
	goto_if_ge VAR_PLATECOUNTER, 12, SinjohRuins_Lab_EventScript_StevenAfter12Plates
	goto_if_ge VAR_PLATECOUNTER, 9, SinjohRuins_Lab_EventScript_StevenAfter9Plates
	goto_if_ge VAR_PLATECOUNTER, 6, SinjohRuins_Lab_EventScript_StevenAfter6Plates
	goto_if_ge VAR_PLATECOUNTER, 3, SinjohRuins_Lab_EventScript_StevenAfter3Plates
	msgbox SinjohRuins_Lab_Text_StevenFindPlates, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter3Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter6Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates3, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter9Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter12Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfter15Plates::
	msgbox SinjohRuins_Lab_Text_StevenFindPlates9, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_EventScript_StevenAfterAllPlates::
	msgbox SinjohRuins_Lab_Text_StevenAfterAll, MSGBOX_AUTOCLOSE
	release
	end

SinjohRuins_Lab_Text_StevenFindPlates:
	.string "PIERRE: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLAQUES pour l'instant.\n"
	.string "Pas mal du tout.\p"
	.string "Je l'avoue, je suis curieux\n"
	.string "de voir ce qui arrivera une fois\l"
	.string "qu'elles seront toutes réunies.\p"
	.string "Voyons donc ce que tu trouveras.$"

SinjohRuins_Lab_Text_StevenFindPlates3:
	.string "PIERRE: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLAQUES pour l'instant.\n"
	.string "Pas mal du tout.\p"
	.string "As-tu déjà examiné cette salle?\p"
	.string "Tout cela est bien mystérieux.$"

SinjohRuins_Lab_Text_StevenFindPlates9:
	.string "PIERRE: Ah, {PLAYER}.\p"
	.string "{STR_VAR_1} PLAQUES pour l'instant.\n"
	.string "Tu progresses très bien.\p"
	.string "Les salles qui se sont ouvertes\n"
	.string "ressemblent étonnamment à une\l"
	.string "série de salles de la région de\l"
	.string "HOENN.\p"
	.string "Chacune abritait également un\n"
	.string "Pokémon légendaire.\p"
	.string "Mais à HOENN, seules 3 ont été\n"
	.string "découvertes.\p"
	.string "Et ici, il y en a au moins 6.\p"
	.string "Qui sait ce que nous trouverons\n"
	.string "ensuite?$"

SinjohRuins_Lab_Text_StevenAfterAll:
	.string "PIERRE: {PLAYER}!\p"
	.string "Cette expédition aura été\n"
	.string "l'expérience de toute une vie.\p"
	.string "Dès que j'ai entendu parler de\n"
	.string "ces ruines, j'ai eu une idée.\p"
	.string "Je pensais que nous ferions une\n"
	.string "découverte extraordinaire.\p"
	.string "Et mes prédictions se réalisent\n"
	.string "généralement.\p"
	.string "Merci pour toute ton aide,\n"
	.string "Maître.\p"
	.string "Où iras-tu maintenant?\p"
	.string "J'espère que nous nous reverrons\n"
	.string "ailleurs.$"

SinjohRuins_Lab_EventScript_Geologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_GeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_GeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Geologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_GeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_GeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_GeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Geologist:
    .string "Le radar à pénétration de sol\n"
	.string "révèle 6 salles souterraines\l"
	.string "dans cette vallée.\p"
	.string "Cinq semblent proches de la\n"
	.string "surface. Une autre est enfouie\l"
	.string "encore plus profondément.$"
SinjohRuins_Lab_Text_GeologistDuring:
	.string "Tout ce temps, j'ai dirigé\n"
	.string "mon équipement vers le bas pour\l"
	.string "observer le sous-sol.\p"
	.string "Alors que j'aurais clairement dû\n"
	.string "le pointer vers le haut!$"
SinjohRuins_Lab_Text_GeologistAfter:
	.string "Ces PLAQUES étaient liées au\n"
	.string "plus puissant des Pokémon??\p"
	.string "J'aurais aimé les étudier plus\n"
	.string "longtemps.$"

SinjohRuins_Lab_EventScript_Linguist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_LinguistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_LinguistDuringEvent
	msgbox SinjohRuins_Lab_Text_Linguist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistDuringEvent::
	msgbox SinjohRuins_Lab_Text_LinguistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_LinguistAfterEvent::
	msgbox SinjohRuins_Lab_Text_LinguistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Linguist:
    .string "Pfff...\n"
	.string "Il y a tant de glyphes à\l"
	.string "traduire...\p"
	.string "Rien de tel n'existe dans la\n"
	.string "région de HOENN.$"
SinjohRuins_Lab_Text_LinguistDuring:
    .string "Imagine ma surprise quand j'ai\n"
	.string "traduit ce glyphe!\p"
	.string "J'ai vérifié trois, puis quatre\n"
	.string "fois avant d'en parler à PIERRE!\p"
	.string "Enfin, vraiment, le dieu des\n"
	.string "Pokémon?\p"
	.string "C'est incroyable.$"
SinjohRuins_Lab_Text_LinguistAfter:
    .string "Cette expédition fut un bonheur,\n"
	.string "{PLAYER}.\p"
	.string "Merci d'avoir assuré tout le\n"
	.string "travail sur le terrain.$"

SinjohRuins_Lab_EventScript_Archaeologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Archaeologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_ArchaeologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_ArchaeologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Archaeologist:
	.string "L'existence d'une civilisation\n"
    .string "ici bouleverse toute notre\l"
	.string "compréhension de l'Histoire.\p"
	.string "Beaucoup des artefacts trouvés\n"
	.string "ont plus de mille ans.\p"
	.string "La datation au carbone concorde\n"
	.string "à celle d'artefacts découverts à\l"
	.string "SINNOH.\p"
	.string "Mais cette flûte trouvée...\n"
	.string "Elle semble bien plus ancienne.$"
SinjohRuins_Lab_Text_ArchaeologistDuring:
	.string "Ces plaques...\n"
	.string "Le lien avec la région de\l"
	.string "SINNOH...\l"
	.string "Cette flûte...\l"
	.string "Tout commence à s'éclaircir.$"
SinjohRuins_Lab_Text_ArchaeologistAfter:
	.string "La valeur historique de ce que\n"
	.string "tu nous as aidés à déterrer ici\l"
	.string "est inestimable, {PLAYER}.\p"
	.string "Vraiment, merci.$"

SinjohRuins_Lab_EventScript_Growlithe_Hisui::
    lock
	faceplayer
	playmoncry SPECIES_GROWLITHE, 0
	msgbox SinjohRuins_Lab_Text_Growlithe_Cry, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

SinjohRuins_Lab_Text_Growlithe_Cry:
    .string "Graouh ouh!!$"

SinjohRuins_Lab_EventScript_GrowlithePokeball::
    msgbox SinjohRuins_Lab_Text_GrowlitheBall MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_GrowlitheBall:
	.string "Ce doit être la Ball\n"
	.string "de CANINOS...\p"
	.string "Mieux vaut ne pas y toucher.$"

SinjohRuins_Lab_EventScript_Biologist::
	goto_if_ge VAR_SINJOH_STORYLINE, 13, SinjohRuins_Lab_EventScript_BiologistAfterEvent
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_BiologistDuringEvent
	msgbox SinjohRuins_Lab_Text_Biologist MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistDuringEvent::
	msgbox SinjohRuins_Lab_Text_BiologistDuring, MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_BiologistAfterEvent::
	msgbox SinjohRuins_Lab_Text_BiologistAfter, MSGBOX_NPC
	end

SinjohRuins_Lab_Text_Biologist:
    .string "Regarde ce magnifique spécimen!\p"
	.string "Cette espèce de CANINOS ne\n"
	.string "ressemble à aucune autre dans le\l"
	.string "monde.\p"
	.string "L'analyse ADN révèle un ancêtre\n"
	.string "commun avec les CANINOS des\l"
	.string "autres régions.\p"
	.string "Pourtant, son tempérament et ses\n"
	.string "types diffèrent nettement.\p"
	.string "Les descriptions de CANINOS dans\n"
	.string "les anciennes archives de SINNOH\l"
	.string "semblent correspondre.\p"
	.string "Cette espèce occupait peut-être\n"
	.string "autrefois un territoire plus\l"
	.string "vaste, s'étendant au nord à\l"
	.string "travers l'ancien SINNOH.$"
SinjohRuins_Lab_Text_BiologistDuring:
	.string "Si la créature au sommet de ces\n"
	.string "marches est vraiment le dieu de\l"
	.string "tous les Pokémon, serait-elle\l"
	.string "leur premier ancêtre commun?$"
SinjohRuins_Lab_Text_BiologistAfter:
	.string "Cette expédition m'a permis de\n"
	.string "recueillir tant de données sur\l"
	.string "les formes régionales et\l"
	.string "l'évolution divergente.\p"
	.string "Merci, {PLAYER}.$"

SinjohRuins_Lab_EventScript_Hiker::
	goto_if_ge VAR_SINJOH_STORYLINE, 9, SinjohRuins_Lab_EventScript_HikerDuringAfter
	msgbox SinjohRuins_Lab_Text_Hiker MSGBOX_NPC
	end
SinjohRuins_Lab_EventScript_HikerDuringAfter::
	msgbox SinjohRuins_Lab_Text_HikerDuringAfter, MSGBOX_NPC
	end
SinjohRuins_Lab_Text_Hiker:
	.string "J'ai parcouru ces terres\n"
	.string "sauvages\l"
	.string "pendant dix ans.\p"
	.string "Non, plutôt vingt ans.\p"
	.string "Puis un jour, j'ai découvert ces\n"
	.string "grands piliers de pierre et ce\l"
	.string "temple inquiétant.\p"
	.string "Ce sont les RUINES SINJOH.\n"
	.string "Enfin, c'est ce qu'on m'a dit.\p"
	.string "À l'époque, j'ignorais que la\n"
	.string "ville existait.\p"
	.string "J'en ai juste parlé à quelques\n"
	.string "amis. Mais le bruit court vite.\p"
	.string "Je n'aurais jamais cru attirer\n"
	.string "tant d'attention sur la région.\p"
	.string "Ça me fait un drôle d'effet.\n"
	.string "Tu vois?$"
SinjohRuins_Lab_Text_HikerDuringAfter:
	.string "Ne le dis à personne, {PLAYER},\n"
	.string "mais j'ai vu ce temple au sommet\l"
	.string "de la montagne en découvrant cet\l"
	.string "endroit.\p"
	.string "Je l'ai gardé pour moi.\p"
	.string "J'en ai déjà bien assez dit sur\n"
	.string "ces ruines.\p"
	.string "Au moins, tout semble avoir bien\n"
	.string "fini.$"

@ENVIRONMENT
SinjohRuins_Lab_EventScript_Notes1::
	msgbox SinjohRuins_Lab_Text_Note1 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes2::
	msgbox SinjohRuins_Lab_Text_Note2 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes3::
	msgbox SinjohRuins_Lab_Text_Note3 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes4::
	msgbox SinjohRuins_Lab_Text_Note4 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes5::
	msgbox SinjohRuins_Lab_Text_Note5 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes6::
	msgbox SinjohRuins_Lab_Text_Note6 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes7::
	msgbox SinjohRuins_Lab_Text_Note7 MSGBOX_SIGN
	end
SinjohRuins_Lab_EventScript_Notes8::
	msgbox SinjohRuins_Lab_Text_Note8 MSGBOX_SIGN
	end

SinjohRuins_Lab_Text_Note1:
    .string "Journal de recherche nº1\n"
	.string "3 mai 1975\p"
	.string "Nous sommes arrivés sur le site\n"
	.string "des ruines.\p"
	.string "Le froid mordant du MONT ARGENT\n"
	.string "se fait sentir jusqu'ici...\p"
	.string "L'équipe principale d'excavation\n"
	.string "franchira bientôt la montagne...\p"
	.string "J'ai hâte de voir ce qui nous\n"
	.string "attend sous nos pieds!$"

SinjohRuins_Lab_Text_Note2:
    .string "Journal de recherche nº2\n"
	.string "10 mai 1975\p"
	.string "Une semaine de fouilles n'a\n"
	.string "absolument aucun résultat.\p"
	.string "La glace est incroyablement\n"
	.string "épaisse, et la roche brise tout\l"
	.string "notre matériel.\p"
	.string "Même MACKOGNEUR n'a pas réussi\n"
	.string "à l'entamer.\p"
	.string "Quel est cet endroit?\p"
	.string "Nous devons le découvrir.$"

SinjohRuins_Lab_Text_Note3:
    .string "Journal de recherche nº3\n"
	.string "14 mai 1975\p"
	.string "On n'avance pas dans la vie en\n"
	.string "restant là sans rien faire.\p"
	.string "Je ne suis qu'un ouvrier.\p"
	.string "Mais j'ai trouvé comment passer\n"
	.string "la glace.\p"
	.string "Ou plutôt, comment la fondre.\p"
	.string "Il nous faut beaucoup de Pokémon\n"
	.string "de type FEU.\p"
	.string "Mais comment les amener ici\n"
	.string "depuis SINNOH?$"

SinjohRuins_Lab_Text_Note4:
    .string "Journal de recherche nº4\n"
	.string "21 mai 1975\p"
	.string "Nous n'avons pas chômé.\p"
	.string "Mon idée nous a permis de passer\n"
	.string "la glace. Mais les Pokémon FEU\l"
	.string "ne venaient pas de chez nous.\p"
	.string "Le chef a exigé qu'on les trouve\n"
	.string "sur place.\p"
	.string "Nous avons découvert une source\n"
	.string "chaude près d'un village...\p"
	.string "Et pris ce qu'il nous fallait...\p"
	.string "Je n'en suis pas fier. Mais le\n"
	.string "progrès exige des sacrifices.\p"
	.string "La glace a donc disparu.\p"
	.string "Il y a 6 salles et, au centre,\n"
	.string "un temple scellé.\p"
	.string "L'architecture du bâtiment\n"
	.string "principal semble être celle de\l"
	.string "l'ancien peuple Célestica...\p"
	.string "Nos ancêtres, avant de migrer\n"
	.string "vers le nord.\p"
	.string "Le chef veut ouvrir ce temple au\n"
	.string "plus vite...$"

SinjohRuins_Lab_Text_Note5:
    .string "Journal de recherche nº5\n"
	.string "2 juin 1975\p"
	.string "Nous avons réussi à l'ouvrir...\p"
	.string "Je pensais être fou de joie...\p"
	.string "Mais nous avons perdu des hommes\n"
	.string "de valeur dans l'explosion\l"
	.string "d'énergie jaillie du temple.\p"
	.string "Sans parler des Pokémon qui nous\n"
	.string "ont aidés à l'ouvrir.\p"
	.string "Que Dieu ait leur âme...\p"
	.string "........................\p"
	.string "Quoi qu'il en soit.\p"
	.string "Le temple est ouvert, mais il ne\n"
	.string "laisse que des questions.\p"
	.string "Aucun Pokémon légendaire à\n"
	.string "l'intérieur. Aucun trésor.\p"
	.string "Nos provisions commencent à\n"
	.string "manquer, et nous n'avons rien\l"
	.string "à montrer de nos efforts...$"

SinjohRuins_Lab_Text_Note6:
	.string "Journal de recherche nº6\n"
	.string "10 juin 1975\p"
    .string "L'expédition est terminée.\n"
	.string "Les autres plient bagage.\p"
	.string "Mais moi, je ne peux pas.\p"
	.string "Je ne peux pas abandonner.\n"
	.string "Pas après tout ce que nous avons\l"
	.string "perdu.\p"
	.string "Je vais rester ici.$"

SinjohRuins_Lab_Text_Note7:
	.string "Journal de recherche nº7\n"
	.string "10 septembre 1975\p"
	.string "Cela fait des mois que nous\n"
	.string "sommes arrivés.\p"
	.string "Que je suis arrivé.\p"
	.string "Les autres hommes sont partis.\p"
	.string "Il ne reste que mes Pokémon et\n"
	.string "moi.\p"
	.string "Nous les avions capturés pour\n"
	.string "nous aider dans les travaux.\p"
	.string "Je les entraîne pour les rendre\n"
	.string "plus forts.\p"
	.string "Surtout mon TYPHLOSION.\p"
	.string "Nous devons découvrir ce qui se\n"
	.string "cache sous le temple.$"

SinjohRuins_Lab_Text_Note8:
	.string "Journal de recherche nº8\n"
	.string "15 septembre 1975\p"
	.string "Échec.\p"
	.string "......................\p"
	.string "Mes Pokémon...\p"
	.string "Ensemble, mes 6 Pokémon ont pu\n"
	.string "à abattre un faux mur du temple.\p"
	.string "Mais il nous attendait...\p"
	.string "Une sorte de titan géant...\p"
	.string "L'énergie qu'il a libérée était\n"
	.string "identique à la précédente.\p"
	.string "Ils ont tous péri...\p"
	.string "Et pire encore, cette bête a\n"
	.string "refermé le mur.\p"
	.string "Je ne peux pas rentrer.\n"
	.string "On ne me reconnaîtrait plus...\p"
	.string "Cet endroit m'a changé...\p"
	.string "Je vais parler aux villageois.\p"
	.string "Ils ignorent ce que j'ai fait.\p"
	.string "Les autres hommes étant partis\n"
	.string "depuis longtemps, on me prendra\l"
	.string "pour un randonneur égaré.\p"
	.string "Il ne me reste aucun autre lieu\n"
	.string "où aller.$"

SinjohRuins_EventScript_DisplayCase::
    lock
	msgbox SinjohRuins_DisplayCase_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_DisplayCase_Text:
	.string "Une vitrine bien remplie\n"
	.string "d'échantillons et d'artefacts!$"

SinjohRuins_EventScript_WallSign::
    lock
	msgbox SinjohRuins_WallSign_Text MSGBOX_DEFAULT
	release
	end

SinjohRuins_WallSign_Text:
   .string "Laboratoire de radiographie et\n"
   .string "d'impression.$"


SinjohRuins_EventScript_Artifact::
   lock
   msgbox SinjohRuins_Artifact_Text MSGBOX_DEFAULT
   release
   end

SinjohRuins_Artifact_Text:
   .string "Un artefact découvert à\n"
   .string "l'intérieur des ruines!$"


@==========================Unified other map SCRIPTS================================================================================

SinjohRuins_Lab_EventScript_NoOp::
	release
	end

SinjohRuins_Lab_Text_PlayFlute:
	.string "La FLÛTE AZUR réagit.\n"
	.string "Jouer de la flûte?$"

SinjohRuins_Lab_Text_DropedItem:
	.string "Le {STR_VAR_1} MONARQUE a laissé\n"
	.string "tomber un objet...$"

SinjohRuins_Lab_Text_StevenName:
	.string "Rochard$"

SinjohRuins_Lab_EventScript_3Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall3Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_6Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_9Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall9Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_12Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall12Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_15Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall15Plates
	waitmessage
	delay 30
	return
SinjohRuins_Lab_EventScript_16Plates::
	setspeaker SinjohRuins_Lab_Text_StevenName
	pokenavcall SinjohRuins_Lab_Text_StevenCall16Plates
	waitmessage
	delay 30
	setvar VAR_SINJOH_STORYLINE, 7
	return

SinjohRuins_Lab_Text_StevenCall3Plates:
	.string "PIERRE: {PLAYER}.\p"
	.string "Une secousse vient d'ébranler\n"
	.string "les ruines.\p"
	.string "Tout le monde va bien. Pas\n"
	.string "d'inquiétude.\p"
	.string "C'est fascinant: une des salles\n"
	.string "souterraines sous les ruines\l"
	.string "de s'ouvrir.\p"
	.string "Les marques à l'intérieur me\n"
	.string "rappellent celles de HOENN.\p"
	.string "Viens y jeter un œil quand tu le\n"
	.string "pourras.$"

SinjohRuins_Lab_Text_StevenCall6Plates:
	.string "PIERRE: {PLAYER}.\p"
	.string "Comment avancent les recherches?\p"
	.string "Une autre secousse a eu lieu.\n"
	.string "Cette fois, une deuxième salle\l"
	.string "s'est ouverte.\p"
	.string "J'ai demandé à notre géologue de\n"
	.string "tenir ses instruments prêts si\l"
	.string "cela recommence.\p"
	.string "Plus nous creusons... Plus les\n"
	.string "questions s'accumulent.$"

SinjohRuins_Lab_Text_StevenCall9Plates:
	.string "PIERRE: {PLAYER}.\p"
	.string "Encore une secousse aux ruines.\p"
	.string "Les données révèlent un fait\n"
	.string "fascinant.\p"
	.string "Ce n'était pas un séisme.\p"
	.string "Une énergie s'est accumulée sous\n"
	.string "terre et a fendu la roche de\l"
	.string "l'intérieur.\p"
	.string "Qu'est-ce qui a provoqué ça...\n"
	.string "Honnêtement, je l'ignore.$"

SinjohRuins_Lab_Text_StevenCall12Plates:
	.string "PIERRE: {PLAYER}.\p"
	.string "Encore une secousse. Encore une\n"
	.string "salle qui s'ouvre.\p"
	.string "Nous ne comprenons toujours pas\n"
	.string "ce qui détermine leur rythme.\p"
	.string "Dis, {PLAYER}... Tu ne serais\n"
	.string "pas à l'origine de tout cela,\l"
	.string "par hasard?\p"
	.string "Non, ça ne tient pas debout.$"

SinjohRuins_Lab_Text_StevenCall15Plates:
	.string "PIERRE: {PLAYER}.\p"
	.string "Tu viens de trouver une autre\n"
	.string "PLAQUE?\p"
	.string ".................\p"
	.string "Bien sûr.\p"
	.string "Les Pokémon légendaires tapis\n"
	.string "dans ces ruines... Ils semblent\l"
	.string "réagir à toi, n'est-ce pas?\p"
	.string "Comme s'ils voulaient qu'on les\n"
	.string "trouve.\p"
	.string "Mes prédictions se réalisent\n"
	.string "souvent. Je n'aurais pas dû\l"
	.string "douter de toi.$"

SinjohRuins_Lab_Text_StevenCall16Plates:
	.string "PIERRE: {PLAYER}.\p"
	.string "Nous y sommes presque. Je le\n"
	.string "sens.\p"
	.string "..................\p"
	.string "Tu devrais venir voir cela de\n"
	.string "propres yeux.$"
