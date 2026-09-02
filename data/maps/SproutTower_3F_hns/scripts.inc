SproutTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN_HNS, SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL_HNS, SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY_HNS, SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_SPROUT_TOWER_SILVER
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI_HNS, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "ANCIEN: Tu es sans conteste un\n"
	.string "bon dresseur.\p"
	.string "Comme promis, voici ta CS.\p"
	.string "Un conseil toutefois: traite tes\p"
	.string "Pokémon avec plus de\n"
	.string "gentillesse.\p"
	.string "Tu es bien trop âpre au combat.\p"
	.string "Les Pokémon ne sont pas des\n"
	.string "engins de guerre.$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "... ...Pfeuh!\p"
	.string "On l'appelle l'ANCIEN mais il\n"
	.string "est super nul!\p"
	.string "Et il raconte n'importe quoi...\p"
	.string "Je ne me ferai jamais battre par\p"
	.string "un crétin qui conseille d'être\p"
	.string "gentil avec les Pokémon.\p"
	.string "Seuls les Pokémon puissants sont\n"
	.string "importants.\p"
	.string "Je me contrefiche des Pokémon\n"
	.string "mignons et faibles.$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{RIVAL} utilise Corde Sortie!$"

SproutTower_Text_SageLi_Seen:
	.string "Bienvenue à toi, mon poussin!\p"
	.string "La TOUR CHETIFLOR est un lieu\n"
	.string "d'entraînement.\p"
	.string "Humains et Pokémon y renforcent\n"
	.string "leurs\p"
	.string "liens pour des lendemains qui\n"
	.string "chantent.\p"
	.string "Je serai ton adversaire final.\p"
	.string "Permets-moi de mettre à\n"
	.string "l'épreuve\p"
	.string "ton amitié envers tes Pokémon!$"

SproutTower_Text_SageLi_Beaten:
	.string "Ah, admirable!$"

SproutTower_Text_SageLi_TakeFlash:
	.string "Toi et tes Pokémon méritez bien\n"
	.string "cette nouvelle capacité.\p"
	.string "Prends donc cette CS FLASH.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "Le FLASH illumine les endroits\n"
	.string "les plus sombres.\p"
	.string "Pour l'utiliser en dehors des\n"
	.string "combats\p"
	.string "il te faudra cependant le BADGE\n"
	.string "de l'ARENE de MAUVILLE.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "Je souhaite\n"
	.string "que ton voyage\p"
	.string "t’enrichisse de\n"
	.string "mille découvertes.$"

SproutTower_Text_SageJin_Seen:
	.string "Je m'entraîne pour trouver la\n"
	.string "voie du Pokémon!$"

SproutTower_Text_SageJin_Beaten:
	.string "Mon entraînement est\n"
	.string "insuffisant.$"

SproutTower_Text_SageJin_AfterBattle:
	.string "Quand un Pokémon\n"
	.string "gagne en puissance,\p"
	.string "son Dresseur\n"
	.string "devient plus fort.\p"
	.string "Non, attends...\n"
	.string "C’est le contraire\p"
	.string "je crois...\n"
	.string "Je sais plus.$"

SproutTower_Text_SageTroy_Seen:
	.string "Montre-moi à quel\n"
	.string "point tu fais\p"
	.string "confiance à ton\n"
	.string "équipe de Pokémon.$"

SproutTower_Text_SageTroy_Beaten:
	.string "Ta confiance est totale! Bien!$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "L'ANCIEN n'est plus très loin.$"

SproutTower_Text_SageNeal_Seen:
	.string "La CS de l'ANCIEN éclaire même\n"
	.string "les sombres cavernes.$"

SproutTower_Text_SageNeal_Beaten:
	.string "Je suis illuminé, ébloui par tes\n"
	.string "capacités!$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "Que tes pas te guident vers la\n"
	.string "lumière!$"

SproutTower_Text_3F_Painting:
	.string "Un CHETIFLOR a\n"
	.string "été peint par un\p"
	.string "artiste extrêmement\n"
	.string "talentueux...$"
