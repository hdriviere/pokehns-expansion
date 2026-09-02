SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_PARTS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Oui? Si tu cherches POUPE, c’est\n"
	.string "bien moi.\p"
	.string "Ah! Ça doit être ce que j’avais\n"
	.string "commandé à M. ROCHARD de DEVON.\p"
	.string "Merci. Formidable! Nous allons\n"
	.string "désormais pouvoir préparer\p"
	.string "l’expédition!$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hé, hé, hé, pas si vite! On va\n"
	.string "prendre ces pièces!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPT. POUPE: Qu… quoi? Qui\n"
	.string "êtes-vous, jeunes gens?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "On est la TEAM AQUA!\p"
	.string "Notre CHEF veut ces pièces!\n"
	.string "Ferme-la et balance-les!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaaah! Se faire battre par un\n"
	.string "gosse!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, mon dieu, quel désastre… Le\n"
	.string "CHEF va être furieux…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Hum, espèce de mauviette!\n"
	.string "Laisse-moi régler ça!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Quoi?! Moi aussi, j’ai perdu!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Et maintenant? Si on ne récupère\n"
	.string "pas les pièces, on est faits!\p"
	.string "Ah, j’avais pas prévu d’être\n"
	.string "gêné par un mouflet qui se mêle\p"
	.string "de tout!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Je venais voir pourquoi vous\n"
	.string "mettiez tant de temps à\p"
	.string "récupérer les pièces et\p"
	.string "je constate que vous êtes\n"
	.string "retenus par un simple mioche!$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Nous sommes la TEAM AQUA, et\n"
	.string "nous adorons la mer!\p"
	.string "Moi, je suis ARTHUR, le leader\n"
	.string "de la TEAM AQUA.\p"
	.string "Dis-moi, pourquoi te mêles-tu de\n"
	.string "nos affaires?\p"
	.string "Attends un peu,\n"
	.string "appartiendrais-tu à la TEAM\p"
	.string "MAGMA?\p"
	.string "Non, ce n’est pas possible, tu\n"
	.string "ne portes pas leur uniforme.\p"
	.string "… … … … … … … … … … … …\p"
	.string "Les POKéMON, les gens, toute la\n"
	.string "vie dépend de la mer.\p"
	.string "C’est pourquoi le but premier de\n"
	.string "la TEAM AQUA est l’expansion de\p"
	.string "la mer.\p"
	.string "Nous défendons une noble cause.\n"
	.string "Tu ne crois pas?\p"
	.string "Ah, oui… Tu es trop jeune pour\n"
	.string "comprendre.\p"
	.string "Ça ne facilite pas les choses\n"
	.string "que tu ne comprennes pas nos\p"
	.string "idéaux.\p"
	.string "Mais je te préviens, ne t’avise\n"
	.string "pas de te mêler encore de nos\p"
	.string "histoires.\p"
	.string "Les conséquences seraient\n"
	.string "terribles.\p"
	.string "N’oublie pas ce conseil!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPT. POUPE: Tu es… Ah oui, tu\n"
	.string "es {PLAYER}{KUN}…\p"
	.string "En tout cas, que de tension!\n"
	.string "Merci de nous avoir sauvés!\p"
	.string "Ah oui, j’avais presque oublié\n"
	.string "que tu avais apporté les pièces\p"
	.string "de DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPT. POUPE: Zou! Il n’y a pas\n"
	.string "de temps à perdre!\p"
	.string "Il faut qu’on prépare cette\n"
	.string "expédition sous-marine au plus\p"
	.string "vite.\p"
	.string "Merci encore, mais il faut que\n"
	.string "j’y aille maintenant.\p"
	.string "Mais n’hésite pas à jeter un œil\n"
	.string "ici si tu en as envie.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "J’ai vu la maquette d’un bateau\n"
	.string "ici.\p"
	.string "Ça m’a fait penser à l’EPAVE,\n"
	.string "près du VILLAGE MYOKARA…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "N’essaie même pas de courir dans\n"
	.string "le MUSEE!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Waouh, quel sous-marin imposant!\n"
	.string "Je veux faire un tour!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "L’étiquette indique:\n"
	.string "“ECHANTILLON POUR TEST DE LA\p"
	.string "QUALITE DE L’EAU”.\p"
	.string "La mer forme un seul ensemble,\n"
	.string "mais l’eau est différente selon\p"
	.string "les régions.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "L’étiquette indique:\n"
	.string "“ECHANTILLON POUR TEST DE LA\p"
	.string "QUALITE DE L’EAU”.\p"
	.string "La salinité de l’eau diffère\n"
	.string "peut-être d’une région à\p"
	.string "l’autre…$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Une balle en caoutchouc\n"
	.string "s’allonge et rétrécit.\p"
	.string "“Dans la mer, le poids de l’eau\n"
	.string "exerce lui-même une pression.”\p"
	.string "“En eau peu profonde, la\n"
	.string "pression n’est pas très élevée.”\p"
	.string "“Par contre, en profondeur, la\n"
	.string "pression peut atteindre des\p"
	.string "dizaines de milliers de tonnes\n"
	.string "sur une petite surface.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "MAQUETTE DE LA REGION DE HOENN\p"
	.string "C’est un diorama de la région de\n"
	.string "HOENN.\p"
	.string "Où est représenté BOURG-EN-VOL?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "C’est la représentation du\n"
	.string "mouvement de l’eau de mer.\p"
	.string "“Au fond de la mer, les\n"
	.string "variations de certains facteurs\p"
	.string "tels que la température et la\n"
	.string "salinité provoquent le mouvement\p"
	.string "de l’eau.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "C’est la représentation du\n"
	.string "mouvement de l’eau de mer.\p"
	.string "“En surface, l’eau de mer\n"
	.string "circule comme des courants\p"
	.string "poussés par le vent.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "Le ferry LE MARINA\p"
	.string "Réplique à l’échelle du bateau\n"
	.string "en construction au CHANTIER\p"
	.string "NAVAL DE POUPE.$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "SOUS-MARIN D’EXPLORATION 1\p"
	.string "Réplique du performant\n"
	.string "sous-marin d’exploration des\p"
	.string "fonds marins.$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "CAPSULE SUBMERSIBLE\p"
	.string "Réplique d’une capsule compacte\n"
	.string "pour explorer les fonds marins.$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "L’OCEANE\p"
	.string "Réplique du luxueux paquebot qui\n"
	.string "fait le tour de la planète.$"
