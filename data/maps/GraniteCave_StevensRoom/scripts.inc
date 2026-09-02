GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "Je suis PIERRE.\p"
	.string "Je m’intéresse aux pierres\n"
	.string "rares, alors je vais ici et là.\p"
	.string "Oh? C’est une LETTRE pour moi?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "PIERRE: OK, merci.\p"
	.string "Tu as fait tout ça rien que pour\n"
	.string "me la  remettre? Il faut que je\p"
	.string "te remercie.\p"
	.string "Laisse-moi voir… Je vais te\n"
	.string "donner cette CT.\p"
	.string "Elle contient ma capacité\n"
	.string "préférée, AILE D’ACIER.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "PIERRE: Tes POKéMON semblent\n"
	.string "être tout à fait compétents.\p"
	.string "En continuant à t’entraîner, un\n"
	.string "jour,  tu pourrais même devenir\p"
	.string "le MAITRE de la LIGUE POKéMON.\n"
	.string "Je le pense vraiment.\p"
	.string "Je sais, puisqu’on se connaît\n"
	.string "maintenant, enregistrons nos\p"
	.string "numéros dans nos POKéNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Vous avez enregistré PIERRE dans\n"
	.string "le POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Maintenant, il faut que je me\n"
	.string "dépêche.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, ton SAC est plein… C’est\n"
	.string "dommage.$"

