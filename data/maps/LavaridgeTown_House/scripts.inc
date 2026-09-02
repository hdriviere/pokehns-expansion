LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "Ma femme tente de faire éclore\n"
	.string "un OEUF dans les sources\p"
	.string "chaudes. Elle vient de me le\n"
	.string "dire.\p"
	.string "Elle a laissé deux POKéMON à la\n"
	.string "PENSION. Et ils ont découvert\p"
	.string "cet OEUF!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZATON: Zigzaaa!$"

