Route10_PowerPlantEntrance_hns_MapScripts::
	.byte 0

Route10_PowerPlantEntrance_EventScript_Cop::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantEntrance_EventScript_CopDuringRocket
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantEntrance_EventScript_CopAfterDone
	msgbox Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopDuringRocket::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_CopAfterDone::
	lock
	faceplayer
	msgbox Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity, MSGBOX_DEFAULT
	closemessage
	end

Route10_PowerPlantEntrance_EventScript_Engineer1::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer1Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer1Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer2Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer2Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Cop2::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Cop2Done
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious, MSGBOX_NPC
	end
Route10_PowerPlantEntrance_EventScript_Cop2Done::
	msgbox Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3::
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantEntrance_EventScript_Engineer3Done
	msgbox Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_EventScript_Engineer3Done::
	msgbox Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning, MSGBOX_NPC
	end

Route10_PowerPlantEntrance_Trigger_Cop::
	lock
	playse SE_POKENAV_CALL
	applymovement2 LOCALID_POWERPLANT_COP, Common_Movement_ExclamationMark
	waitse
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkToPlayer
	waitmovement 0
	turnobject LOCALID_POWERPLANT_ENGINEER, DIR_SOUTH
	msgbox Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_POWERPLANT_COP, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 30
	msgbox Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_POWERPLANT_COP, Route10_PowerPlantEntrance_Movement_WalkBack
	waitmovement 0
	setvar VAR_KANTO_ROCKET_STORY_STATE, 2
	clearflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	release
	end

Route10_PowerPlantEntrance_Movement_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route10_PowerPlantEntrance_Movement_WalkBack:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Route10_PowerPlantEntrance_Text_Officer1AThiefBrokeIn:
	.string "Un voleur s’est introduit dans\n"
	.string "la Centrale...\p"
	.string "C’est du jamais vu...$"

Route10_PowerPlantEntrance_Text_Officer1CeruleanShadyCharacter:
	.string "On a reçu un message d’Azuria!\n"
	.string "Un type bizarre rôderait\p"
	.string "dans les rues...$"

Route10_PowerPlantEntrance_Text_Officer1CouldIAskForYourCooperation:
	.string "Tu veux bien m'aider?$"

Route10_PowerPlantEntrance_Text_Officer1HaveToBeefUpSecurity:
	.string "Il faut renforcer la sécurité.$"

Route10_PowerPlantEntrance_Text_Engineer1SomeoneStoleAPart:
	.string "Quelqu'un a volé une partie\n"
	.string "essentielle du générateur.\p"
	.string "Sans elle, rien ne marche!$"

Route10_PowerPlantEntrance_Text_Engineer1GeneratorUpAndRunning:
	.string "Le générateur est\n"
	.string "en marche. Il crée\p"
	.string "de l’électricité\n"
	.string "continuellement.$"

Route10_PowerPlantEntrance_Text_Engineer2PowerPlantUpAndRunning:
	.string "Cette Centrale a été abandonnée\n"
	.string "il y a longtemps.\p"
	.string "On l’a rénovée pour fournir de\n"
	.string "l’énergie au Train Magnétique.$"

Route10_PowerPlantEntrance_Text_Engineer2GeneratorIsRunningAgain:
	.string "Le générateur est en marche!$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenSadAndFurious:
	.string "Le PATRON de la CENTRALE est\n"
	.string "dans l'arrière-salle, avec\l"
	.string "le générateur.\p"
	.string "Mais depuis que quelqu'un l'a\n"
	.string "saccagé, il est à la fois triste\l"
	.string "et furieux...$"

Route10_PowerPlantEntrance_Text_Officer2ManagerHasBeenCheerful:
	.string "Depuis que tout a été réparé, le\n"
	.string "Patron est au comble du bonheur!$"

Route10_PowerPlantEntrance_Text_Engineer4MagnetTrainConsumesElectricity:
	.string "Le Train Magnétique consomme\n"
	.string "beaucoup d’électricité.\p"
	.string "Il ne peut plus\n"
	.string "fonctionner si le\p"
	.string "nouveau générateur\n"
	.string "est en panne...$"

Route10_PowerPlantEntrance_EventScript_Lorenzo::
	lock
	faceplayer
	goto_if_set FLAG_POWERPLANT_NPC_TRADE_COMPLETED, Route10_PowerPlantEntrance_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MAGNETON, Route10_PowerPlantEntrance_Text_WantToTrade, Route10_PowerPlantEntrance_EventScript_DeclineTrade, Route10_PowerPlantEntrance_EventScript_NotRequestedMon, Route10_PowerPlantEntrance_Text_TakeCare
	setflag FLAG_POWERPLANT_NPC_TRADE_COMPLETED
	release
	end

Route10_PowerPlantEntrance_EventScript_DeclineTrade::
	msgbox Route10_PowerPlantEntrance_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route10_PowerPlantEntrance_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_EventScript_TradeCompleted::
	msgbox Route10_PowerPlantEntrance_Text_TradeCompleted, MSGBOX_DEFAULT
	release
	end

Route10_PowerPlantEntrance_Text_WantToTrade:
	.string "Je travaille ici, à la CENTRALE.\n"
	.string "Mon MAGNÉTON est mon partenaire\l"
	.string "depuis des années.\p"
	.string "Mais j'ai toujours voulu\n"
	.string "un {STR_VAR_1}.\p"
	.string "Veux-tu en échanger un contre\n"
	.string "mon {STR_VAR_2}?$"

Route10_PowerPlantEntrance_Text_TakeCare:
	.string "Merci! Prends bien soin de\n"
	.string "MAGGIE pour moi!$"

Route10_PowerPlantEntrance_Text_DeclineTrade:
	.string "Non? C'est dommage.\n"
	.string "Mon MAGNÉTON travaille dur.$"

Route10_PowerPlantEntrance_Text_NotRequestedMon:
	.string "Hmm, ce Pokémon n'est pas\n"
	.string "un {STR_VAR_1}.\p"
	.string "Ce n'est pas ce que je voulais.$"

Route10_PowerPlantEntrance_Text_TradeCompleted:
	.string "Comment va MAGGIE?\n"
	.string "Elle adore les champs\l"
	.string "magnétiques!$"

Route10_PowerPlantEntrance_Text_Engineer4WeCanGetMagnetTrainRunning:
	.string "Le Train Magnétique peut à\n"
	.string "nouveau fonctionner!$"
