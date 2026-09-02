GoldenrodCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodCity_PokemonCenter_hns_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoldenrodCity_PokemonCenter_hns_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY_HNS
	end

GoldenrodCity_PokemonCenter_hns_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_OnWarp_Nop
	.2byte 0

GoldenrodCity_PokemonCenter_hns_OnWarp_Nop::
	end

GoldenrodCity_PokemonCenter_hns_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, GoldenrodCity_PokemonCenter_hns_ExitLinkRoom
	.2byte 0

GoldenrodCity_PokemonCenter_hns_ExitLinkRoom::
	lockall
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	erasebox 0, 0, 29, 19
	releaseall
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc::
	lock
	faceplayer
	copyvar VAR_0x8007, VAR_LAST_TALKED
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_LINK_SERVICES_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_ChooseTrade
	case 1, GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseTrade::
	helpwindow HELP_TRADE_WINDOW
	delay 30
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryTradeLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

GoldenrodCity_PokemonCenter_EventScript_EnterTradeRoom::
	setvar VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_TRADE_CENTER_HNS, 5, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_ChooseBattle::
	helpwindow HELP_TRADE_WINDOW
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_BATTLE_MODE_HNS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_PokemonCenter_EventScript_SingleBattle
	case 1, GoldenrodCity_PokemonCenter_EventScript_DoubleBattle
	case 2, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	case MULTI_B_PRESSED, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline
	end

GoldenrodCity_PokemonCenter_EventScript_SingleBattle::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_DoubleBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum
	end

GoldenrodCity_PokemonCenter_EventScript_NeedTwoMons::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
	goto GoldenrodCity_PokemonCenter_EventScript_ChooseBattle
	end

GoldenrodCity_PokemonCenter_EventScript_TryEnterColosseum::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End
	message gText_PleaseWaitForLink
	waitmessage
	special TryBattleLinkup
	waitstate
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, GoldenrodCity_PokemonCenter_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

GoldenrodCity_PokemonCenter_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	closemessage
	release
	setdynamicwarp MAP_GOLDENROD_CITY_POKEMON_CENTER_HNS, 255, 14, 6
	setwarp MAP_BATTLE_COLOSSEUM_2P_HNS, 6, 8
	special DoCableClubWarp
	waitstate
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_Decline::
	msgbox GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_EventScript_LinkNpc_End::
	release
	end

GoldenrodCity_PokemonCenter_LinkNpc_Text_Intro:
	.string "COIN CONNEXION\p"
	.string "CHOISIS LE TYPE DE CONNEXION.$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_BattleMode:
	.string "CHOISIS LE TYPE DE COMBAT.$"

GoldenrodCity_PokemonCenter_LinkNpc_Text_Goodbye:
	.string "AU REVOIR.$"

GoldenrodCity_PokemonCenter_EventScript_LinkExplainerNpc::
	msgbox GoldenrodCity_PokemonCenter_Text_LinkExplainer, MSGBOX_NPC
	end

GoldenrodCity_PokemonCenter_Text_LinkExplainer:
	.string "Cette machine sert aux échanges\n"
	.string "et aux combats avec des joueurs\p"
	.string "proches. Vive la technologie!$"

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
	.string "J'adore la vie en grande ville!\p"
	.string "J'ai emménagé ici quand j'étais\n"
	.string "une jeune Dresseuse, comme toi!$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
	.string "Ce Centre Pokémon est spécial.\n"
	.string "Son toit est en or!$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
	.string "J'ai dit à mon frère que le toit\n"
	.string "était en or massif.\p"
	.string "Il croit vraiment tout!$"

GoldenrodCity_PokemonCenter_LassText:
    .string "Le type du Pokémon\n"
    .string "est au moins\p"
    .string "aussi important\n"
    .string "que son niveau...\p"
    .string "Un Pokémon qui est\n"
    .string "fort contre n’importe\p"
    .string "quel ennemi, ça\n"
    .string "n’existe pas!$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "{PLAYER}?\p"
    .string "Félicitations!\p"
    .string "En cadeau spécial, une GS BALL\n"
    .string "vous a été envoyée!\p"
    .string "C'est pour vous!$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "A très bientôt!$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "Ton SAC a l'air siiiii lourd!\p"
    .string "Oh! As-tu un truc du nom de LETR\n"
    .string "EVOLI?\p"
    .string "Ma fille en veut une.\p"
    .string "Tu peux m'en donner une?$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "Donner LETR EVOLI?$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "Oh, formidable! Merci merci!\n"
    .string "Voilà pour toi!$"

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "Ma fille sera ravie!$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "Oh? Tu n'en as pas? Dommage.$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "Oh... Une autre fois, alors.$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{PLAYER} donne la LETR EVOLI.$"
