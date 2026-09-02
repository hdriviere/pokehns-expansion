VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "{PLAYER}! Ca faisait\n"
	.string "longtemps. Le PROF.\p"
	.string "ORME m'a demandé\n"
	.string "de te trouver.\p"
	.string "Il a encore un service à te\n"
	.string "demander.\p"
	.string "Peux-tu prendre l'OEUF Pokémon?$"

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "{PLAYER}! Ça faisait longtemps.\p"
	.string "Le PROF.ORME m'a demandé de te\n"
	.string "trouver.\p"
	.string "Il a encore un service à te\n"
	.string "demander.\p"
	.string "Peux-tu prendre l'OEUF Pokémon?\p"
	.string "Oh, attends… Fais d'abord de la\n"
	.string "place dans ton équipe.$"

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "Nous avons découvert qu'un\n"
	.string "Pokémon doit grandir dans l'OEUF\p"
	.string "de pouvoir éclore.\p"
	.string "Il doit aussi rester avec\n"
	.string "d'autres Pokémon actifs\p"
	.string "pour éclore.\p"
	.string "{PLAYER}, nous comptons sur toi.$"

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "Ceci pourra aider à l'éclosion.$"

VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "Oh, flûte. Tu ne peux plus avoir\n"
	.string "de Pokémon sur toi.\p"
	.string "Je t'attends ici pendant que tu\n"
	.string "fais de la place pour l'OEUF.$"

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
	.string "Oh, tu ne peux plus porter de\n"
	.string "Pokémon avec toi.\p"
	.string "Pas d'inquiétude: j'ai envoyé\n"
	.string "l'OEUF sur le PC de LEO.$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "M-Mais... Le PROF.ORME te\n"
	.string "cherchait...$"

VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "Je lis volontiers un bon livre\n"
	.string "pendant leur récupération.$"

VioletCity_PokeCenter_Text_MobileAdapter:
	.string "Je viens de combattre par câble\n"
	.string "un ami d'IRISIA.\p"
	.string "Un ADAPTATEUR MOBILE permet de\n"
	.string "te connecter à un ami très loin.$"

VioletCity_PokeCenter_Text_GameboyKid:
	.string "Un type du nom de LEO a créé le\n"
	.string "système de stockage de Pokémon.$"

VioletCity_PokeCenter_Text_Gentleman:
	.string "Ca fait plus ou moins trois ans.\p"
	.string "La TEAM ROCKET était la pire\n"
	.string "ennemie des Pokémon.\p"
	.string "Mais y'a une justice! Un jeune\n"
	.string "gamin les a depuis détrônés.$"

VioletCity_PokeCenter_Text_Youngster:
	.string "Les Pokémon sont intelligents.\p"
	.string "Ils n'obéissent\n"
	.string "pas aux dresseurs\p"
	.string "qui ne les\n"
	.string "respectent pas.\p"
	.string "Sans les BADGES appropriés, ils\p"
	.string "n'en feront qu'à leur tête.$"
