PewterCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "As-tu vu l'ARENE d'ARGENTA?\p"
	.string "Le CHAMPION a des Pokémon de\n"
	.string "roche.$"

PewterCity_Text_BugCatcher:
	.string "La nuit, les MELOFEE sortent\n"
	.string "pour jouer au MONT SELENITE.\p"
	.string "Mais pas toutes les nuits.$"

PewterCity_Text_Gramps:
	.string "Oh! Tu viens de Johto?\p"
	.string "Ah, ça me rappelle\n"
	.string "des souvenirs! Moi\p"
	.string "aussi je me suis\n"
	.string "entraîné là-bas\p"
	.string "dans ma jeunesse!\p"
	.string "Tiens! Pour fêter\n"
	.string "cette rencontre,\p"
	.string "voilà un objet que\n"
	.string "j’ai trouvé à Johto.$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "Découvrir de nouveaux visages,\n"
	.string "de nouveaux lieux...\p"
	.string "C'est beau de voyager.$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "ARGENTA Grise comme le roc$"

PewterCity_Text_GymSign:
	.string "CHAMPION d'ARENE d'ARGENTA:\n"
	.string "PIERRE\p"
	.string "Le dresseur dur comme la roche$"

PewterCity_Text_MuseumSign:
	.string "Il y a une affiche ici...\p"
	.string "Le MUSEE DES SCIENCES\n"
	.string "d'ARGENTA est\p"
	.string "fermé pour cause\n"
	.string "de rénovations...$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "Il y a une affiche ici...\p"
	.string "La BOUTIQUE de SOUVENIRS du MONT\n"
	.string "SELENITE est ouverte!$"

PewterCity_Text_WelcomeSign:
	.string "Bienvenue à ARGENTA!$"

