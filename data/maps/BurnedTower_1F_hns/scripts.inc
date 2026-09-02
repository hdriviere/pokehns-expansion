BurnedTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_EUSINE
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "EUSINE: Mon nom est EUSINE.\p"
	.string "Je suis sur la piste d'un\n"
	.string "Pokémon appelé SUICUNE.\p"
	.string "Et toi, tu es...?\p"
	.string "{PLAYER}? Ravi de te connaître!\p"
	.string "J'ai entendu dire que SUICUNE\n"
	.string "se trouvait dans cette TOUR\l"
	.string "CENDREE.\p"
	.string "Je suis donc venu voir.\p"
	.string "Mais où peut-il bien être?$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "EUSINE: J'ai entendu dire que\n"
	.string "SUICUNE se trouvait dans cette\l"
	.string "TOUR CENDREE.\p"
	.string "Je suis donc venu voir.\p"
	.string "Mais où peut-il bien être?$"

BurnedTower_1FMortyText:
	.string "MORTIMER: Le CHAMPION de ROSALIA\p"
	.string "doit étudier les\n"
	.string "Pokémon légendaires:\p"
	.string "SUICUNE, ENTEI\n"
	.string "et RAIKOU.\p"
	.string "EUSINE est ici. J'ai décidé de\p"
	.string "fouiller la TOUR avec lui.$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_BURNED_TOWER_SILVER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F_HNS
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	waitstate
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3_HNS, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "..............................\p"
	.string "...Oh, c'est toi.\p"
	.string "Je suis venu chercher les\n"
	.string "Pokémon\l"
	.string "légendaires qui, paraît-il,\l"
	.string "nichent ici.\p"
	.string "Mais il n'y a rien!\p"
	.string "J'ai fait tout ce chemin jusqu'à\n"
	.string "ce trou pour ne rien trouver?\p"
	.string "Pas question!\p"
	.string "Tout est de ta faute!$"

BurnedTowerSilver_WinText:
	.string "...Pfff!\p"
	.string "J'ai perdu uniquement parce que\n"
	.string "mes Pokémon sont beaucoup\n"
	.string "trop faibles.\p"
	.string "C'est minable.$"

BurnedTowerSilver_AfterText1:
	.string "Pff...minable.\p"
	.string "T'auras jamais un Pokémon\n"
	.string "légendaire\p"
	.string "de toute façon. T'es zéro.$"

BurnedTowerSilver_LossText:
	.string "...Pfff!\p"
	.string "Voilà pourquoi je déteste\n"
	.string "affronter les nuls.\p"
	.string "C'est une perte de temps.$"

BurnedTowerSilver_AfterText2:
	.string "...Pfff!\p"
	.string "Tu tombes dans les trous?\p"
	.string "T'es pas trop bête, c'est bien.\p"
	.string "Minable!$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD_HNS, BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO_HNS, BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "Ne t’inquiète pas!\n"
	.string "Nous les Crache-Feu\p"
	.string "on connaît mieux\n"
	.string "que quiconque les\p"
	.string "dangers du feu!$"
BurnedTower_Text_NardBeaten:
	.string "Merci pour ce combat chaleureux!$"
BurnedTower_Text_NardAfter:
	.string "Cette tour a brûlé\n"
	.string "à cause d’un orage.\p"
	.string "Aucune chance\n"
	.string "que ça arrive\p"
	.string "avec mes petites flammes.$"

BurnedTower_Text_RichardoSeen:
	.string "Je m'entraîne à voler dans la\n"
	.string "TOUR CENDREE! N'essaie pas ça\l"
	.string "chez toi!$"
BurnedTower_Text_RichardoBeaten:
	.string "Pfffffffffffffff.$"
BurnedTower_Text_RichardoAfter:
	.string "La vie de criminel n'est\n"
	.string "peut-être pas faite pour moi...$"
