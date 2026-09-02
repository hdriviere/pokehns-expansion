RuinsOfAlph_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_B1F_OnFrame
	.byte 0

RuinsOfAlph_B1F_OnFrame::
	map_script_2 VAR_RUINSOFALPH_STATE, 1, RuinsOfAlph_B1F_EventScript_Presence
	.2byte 0

RuinsOfAlph_B1F_EventScript_Presence::
	lock
	msgbox RuinsOfAlph_B1F_Text_Presence, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUINSOFALPH_STATE, 0
	release
	end


RuinsOfAlph_B1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Teacher, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Hiker::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Gramps::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Gramps, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HelixFossil::
	finditem ITEM_HELIX_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OldAmber::
	finditem ITEM_OLD_AMBER
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_GSBALL::
	finditem ITEM_GS_BALL
	end

RuinsOfAlph_B1F_Text_Presence:
	.string "Une présence étrange règne ici.$"

RuinsOfAlph_B1F_Text_Hiker:
	.string "C'est une grande salle, mais\n"
	.string "elle est vide.$"

RuinsOfAlph_B1F_Text_Teacher:
	.string "Cet endroit est mystique...\p"
	.string "Il semble être hors du monde.$"

RuinsOfAlph_B1F_Text_Gramps:
	.string "Les anciens monuments sont\n"
	.string "souvent des tombes royales.\p"
	.string "Un peu comme les pyramides...$"
