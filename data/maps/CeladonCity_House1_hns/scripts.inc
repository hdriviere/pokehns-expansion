CeladonCity_House1_hns_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "Bienvenue!\p"
	.string "... Du moins,\n"
	.string "j’aimerais bien\p"
	.string "vous dire ça, mais\n"
	.string "on est en plein\p"
	.string "concours de gloutonnerie...\p"
	.string "Si ça vous\n"
	.string "intéresse, vous\p"
	.string "pouvez regarder les\n"
	.string "concurrents manger.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "...(tousse)... ...(crache)...$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "Me parle pas!\p"
	.string "J'vais perdre ma concentration!$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "...(tousse)... ...(mâche)...$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "Bouffer! Bouuuuuffer!\p"
	.string "J'vais m'faire exploser\n"
	.string "l'ventre!$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "Miam...(bouffe)...$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "Ici la nourriture est\n"
	.string "bonne mais celle de\p"
	.string "DOUBLONVILLE est la\n"
	.string "meilleure de toutes.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "(mâche), (croque).$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "Personne ne te donnera de BOITE\p"
	.string "JETON, ici. Va voir à JOHTO.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "MIOM MIOM MIOM!\p"
	.string "Je peux encore manger!\p"
	.string "Chef! Une autre!$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "Concours de Bouffe! Pas de\p"
	.string "temps limite! Une\n"
	.string "joie sans fin!\p"
	.string "Et c'est gratuit\n"
	.string "pour le vainqueur!$"

