CeruleanCity_House2_Frlg_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
	.string "Ces ROCKET, ils sont si\n"
	.string "méchants!\p"
	.string "Regarde ce qu'ils ont fait ici!\p"
	.string "Ils m'ont volé une CT pour\n"
	.string "apprendre à leurs POKéMON à\p"
	.string "creuser des TUNNELS!\p"
	.string "J'allais justement l'utiliser\n"
	.string "avec un de mes POKéMON.\p"
	.string "Elle m'avait coûté les yeux de\n"
	.string "la tête!$"

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
	.string "Contre mauvaise fortune bon\n"
	.string "cœur!\p"
	.string "Je vais apprendre à mon\n"
	.string "TAUPIQUEUR à creuser des TUNNELS\p"
	.string "sans CT!$"

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
	.string "La TEAM ROCKET doit maintenant\n"
	.string "creuser des TUNNELS partout!$"

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
	.string "La TEAM ROCKET a creusé une\n"
	.string "nouvelle sortie!$"

