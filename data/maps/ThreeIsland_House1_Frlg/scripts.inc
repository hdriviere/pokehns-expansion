ThreeIsland_House1_Frlg_MapScripts::
	.byte 0

ThreeIsland_House1_EventScript_Lostelle::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_House1_Text_YoureAlwaysSoCool
	release
	end

ThreeIsland_House1_EventScript_DisplayCase::
	msgbox ThreeIsland_House1_Text_RareRocksGemsDisplayed, MSGBOX_SIGN
	end

ThreeIsland_House1_Text_YoureAlwaysSoCool::
	.string "LOSTELLE: Bonjour, {PLAYER}! Tu\n"
	.string "es toujours aussi cool!\p"
	.string "Un jour, je te préparerai aussi\n"
	.string "le déjeuner, {PLAYER}.$"

ThreeIsland_House1_Text_RareRocksGemsDisplayed::
	.string "Des pierres rares sont mises en\n"
	.string "évidence.$"

