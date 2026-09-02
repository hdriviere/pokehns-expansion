RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Moi, à mes POKéMON, je leur\n"
	.string "donne des surnoms très\p"
	.string "appropriés!\p"
	.string "C’est l’expression de, euh… mon\n"
	.string "originalité, oui, c’est ça!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Mais surnommer PEKACHU un\n"
	.string "PIKACHU, ça ne rime à rien.\p"
	.string "C’est sûrement bien d’utiliser\n"
	.string "un nom facile à comprendre, mais\p"
	.string "de là à…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

