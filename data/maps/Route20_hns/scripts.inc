Route20_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE_HNS, Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten, Route20_EventScript_RegisterNicole
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RematchNicole
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_RegisterNicole::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_NicoleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLE_HNS
	release
	end

Route20_EventScript_RematchNicole::
	trainerbattle_rematch TRAINER_NICOLE_HNS, Route20_Text_NicoleRematchIntro, Route20_Text_NicoleRematchDefeat
	msgbox Route20_Text_NicolePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_NICOLE_2_HNS, Route20_EventScript_RematchNicoleTryGiveItem
	end

Route20_EventScript_RematchNicoleTryGiveItem::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_HEART_SCALE
	closemessage
	end

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI_HNS, Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON_HNS, Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dennis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGIKARP, CRY_MODE_NORMAL
	msgbox Route20_Text_Dennis, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	lock
	faceplayer
	msgbox Route20_Text_Headlocker, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE20_HEADLOCKER, DIR_SOUTH
	release
	end

Route20_Text_Dennis:
	.string "DENNIS: SHAAAAAAAA!$"

Route20_Text_Headlocker:
	.string "Un Pokémon rare vit sur cette\n"
	.string "route.\p"
	.string "Parfois, il porte un objet rare\n"
	.string "d'évolution.\p"
	.string "C'est doublement rare!\p"
	.string "Je dois finir mon POKéDEX, alors\n"
	.string "je pêche ici depuis des heures!$"

Route20_Text_Seel:
	.string "OTARIA: Ota ota!$"

Route20_Text_Dewgong:
	.string "LAMANTINE: Maaaantine!$"

Route20_Text_SeafoamSign:
	.string "Iles Ecume$"

Route20_Text_NicoleRegister:
	.string "Ton Pokémon nage vite!\n"
	.string "Donne-moi ton numéro!$"

Route20_Text_NicoleRematchIntro:
	.string "Toute cette nage a renforcé mon\n"
	.string "Pokémon! Combattons!$"

Route20_Text_NicoleRematchDefeat:
	.string "Encore emportée...$"

Route20_Text_NicolePostRematch:
	.string "Victoire ou défaite, mon Pokémon\n"
	.string "et moi gagnons en forme!$"

Route20_Text_SwimmerfNicoleSeen:
	.string "On est léger dans l'eau...$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "Oh, non!$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "La nage fait travailler\n"
	.string "tous les muscles\p"
	.string "du corps! C’est\n"
	.string "super pour la santé!$"

Route20_Text_SwimmerfLoriSeen:
	.string "Tous les Badges que t’as...!\n"
	.string "Allez, un combat!$"

Route20_Text_SwimmerfLoriBeaten:
	.string "Non!$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "Surf n’est pas la seule capacité\n"
	.string "secrète utilisable dans l’eau!$"

Route20_Text_SwimmermCameronSeen:
	.string "Ça va pas être possible de nager\n"
	.string "comme ça jusqu’à Johto...$"

Route20_Text_SwimmermCameronBeaten:
	.string "Aiyah!$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "On peut nager dans la mer, les\n"
	.string "fleuves, les lacs...$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "Tiens! Une pancarte...\p"
	.string "CHAMPION d'ARENE de CRAMOIS'ILE:\n"
	.string "AUGUSTE$"
