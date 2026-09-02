DarkCave_NorthSide_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_NorthSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "Woah! Tu m’as fait peur!\p"
    .string "J’avais mes Lunettes\n"
    .string "Noires, alors\p"
    .string "je n’ai pas vu\n"
    .string "que tu étais là.\p"
    .string "Tu te demandes ce que je fais\n"
    .string "là?\p"
    .string "Et pourquoi je serais pas là?!\p"
    .string "Tiens, prends cette\n"
    .string "paire de Lunettes\p"
    .string "Noires, et oublie\n"
    .string "que tu m’as vu.$"

DarkCave2_Text_Nerd2:
	.string "Les LUNETTES NOIRES renforcent\n"
	.string "les capacités de type TÉNÈBRES.$"
