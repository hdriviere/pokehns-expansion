Debug_MessageEnd:
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	goto Debug_MessageEnd

Debug_CheatStart::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	release
	end

Debug_CheatStartFrlg::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
	setflag FLAG_OPENED_START_MENU
	setflag FLAG_VISITED_OAKS_LAB
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
	givemon SPECIES_BULBASAUR, 20, ITEM_NONE
	givemon SPECIES_CHARMANDER, 20, ITEM_NONE
	givemon SPECIES_SQUIRTLE, 20, ITEM_NONE
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	setflag FLAG_HIDE_RIVAL_IN_LAB
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1 @ prevents Oak scene when trying to enter Route 1
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6 @ state after handing in parcel and getting pokedex
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
	setvar VAR_MAP_SCENE_ROUTE22, 1
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1 @ end
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_SYS_B_DASH
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_GOT_BIKE_VOUCHER
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	setflag FLAG_WORLD_MAP_PALLET_TOWN
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	setflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_CERULEAN_CITY
	setflag FLAG_WORLD_MAP_VERMILION_CITY
	setflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setflag FLAG_WORLD_MAP_CELADON_CITY
	setflag FLAG_WORLD_MAP_FUCHSIA_CITY
	setflag FLAG_WORLD_MAP_SAFFRON_CITY
	setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	setflag FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR
	setflag FLAG_WORLD_MAP_ONE_ISLAND
	setflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_WORLD_MAP_THREE_ISLAND
	setflag FLAG_WORLD_MAP_FOUR_ISLAND
	setflag FLAG_WORLD_MAP_FIVE_ISLAND
	setflag FLAG_WORLD_MAP_SIX_ISLAND
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND
	release
	end

Debug_FlagsNotSetOverworldConfigMessage::
	message Debug_FlagsNotSetOverworldConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetOverworldConfigMessage_Text:
	.string "Fonctionnalité indisponible!\n"
	.string "Définissez un flag utilisable\p"
	.string "dans:\n"
	.string "'include/config/overworld.h'!$"

Debug_FlagsNotSetBattleConfigMessage::
	message Debug_FlagsNotSetBattleConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetBattleConfigMessage_Text:
	.string "Fonctionnalité indisponible!\n"
	.string "Définissez un flag utilisable\p"
	.string "dans: 'include/config/battle.h'!$"

Debug_VarsNotSetBattleConfigMessage::
	message Debug_VarsNotSetBattleConfigMessage_Text
	goto Debug_MessageEnd

Debug_VarsNotSetBattleConfigMessage_Text:
	.string "Fonctionnalité indisponible!\n"
	.string "Définissez un flag utilisable\p"
	.string "dans: 'include/config/battle.h'!$"

Debug_BoxFilledMessage::
	message Debug_BoxFilledMessage_Text
	goto Debug_MessageEnd

Debug_BoxFilledMessage_Text:
	.string "Boîtes du PC remplies!$"

Debug_EventScript_CheckEVs::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckEVs_End
	callnative Script_GetChosenMonOffensiveEVs
	msgbox Debug_EventScript_Text_OffensiveEVs, MSGBOX_DEFAULT
	callnative Script_GetChosenMonDefensiveEVs
	msgbox Debug_EventScript_Text_DefensiveEVs, MSGBOX_DEFAULT
Debug_EventScript_CheckEVs_End::
	releaseall
	end

Debug_EventScript_Text_OffensiveEVs:
	.string "EVs ATK: {STR_VAR_1}, EVs SPATK:\n"
	.string "{STR_VAR_2}, EVs VIT.:\p"
	.string "{STR_VAR_3}$"

Debug_EventScript_Text_DefensiveEVs:
	.string "EVs PV: {STR_VAR_1}, EVs DEF:\n"
	.string "{STR_VAR_2}, EVs SPDEF:\p"
	.string "{STR_VAR_3}$"

Debug_EventScript_CheckIVs::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckIVs_End
	callnative Script_GetChosenMonOffensiveIVs
	msgbox Debug_EventScript_Text_OffensiveIVs, MSGBOX_DEFAULT
	callnative Script_GetChosenMonDefensiveIVs
	msgbox Debug_EventScript_Text_DefensiveIVs, MSGBOX_DEFAULT
Debug_EventScript_CheckIVs_End::
	releaseall
	end

Debug_EventScript_Text_OffensiveIVs:
	.string "IVs ATK: {STR_VAR_1}, IVs SPATK:\n"
	.string "{STR_VAR_2}, IVs VIT.:\p"
	.string "{STR_VAR_3}$"

Debug_EventScript_Text_DefensiveIVs:
	.string "IVs PV: {STR_VAR_1}, IVs DEF:\n"
	.string "{STR_VAR_2}, IVs SPDEF:\p"
	.string "{STR_VAR_3}$"

Debug_EventScript_Script_1::
	giveegg SPECIES_TOGEPI
	givemon SPECIES_NATU, 5
	givenamedmon 1
	release
	end

Debug_Text_1:
	.string "{STR_VAR_1}$"


Debug_EventScript_Script_2::
	finditem ITEM_POTION
	giveitem ITEM_SUPER_POTION
	release
	end

Debug_EventScript_Script_3::
	goto SinjohRuins_EventScript_StevenBattle
	release
	end

Debug_EventScript_Script_4::
	msgbox SinjohRuins_Lab_Text_StevenCall3Plates, MSGBOX_DEFAULT
	pokenavcall SinjohRuins_Lab_Text_StevenCall6Plates
	release
	end

Debug_EventScript_Script_5::
	special InitKantoRoamers
	release
	end

Debug_EventScript_Script_6::
	lockall
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	frontier_settrainers
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, FRONTIER_TRAINER_LEADER_BROCK_HNS
	special HealPlayerParty
	dofacilitytrainerbattle FACILITY_BATTLE_TOWER
	waitstate
	special HealPlayerParty
	releaseall
	end

Debug_EventScript_Script_7::
	release
	end

Debug_EventScript_Script_8::
	release
	end

Debug_EventScript_Lance_Multi::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, Debug_EventScript_DoLanceMultiBattle
	special LoadPlayerParty
	release
	end

Debug_EventScript_DoLanceMultiBattle::
	multi_2_vs_2 TRAINER_ARIANA_1_HNS, Debug_Text_ArianaDefeat, TRAINER_GRUNT_23_HNS, Debug_Text_Grunt23Defeat, PARTNER_LANCE_HNS
	switch VAR_RESULT
	case 1, Debug_EventScript_LanceMultiWin
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Debug_EventScript_LanceMultiWin::
	msgbox Debug_Text_LanceMultiVictory, MSGBOX_DEFAULT
	release
	end

Debug_Text_ArianaDefeat:
	.string "Tu n'as pas fini d'entendre\n"
	.string "parler de moi!$"

Debug_Text_Grunt23Defeat:
	.string "Je refuse de l'accepter!$"

Debug_Text_LanceMultiVictory:
	.string "Combat multiple avec LANCE\n"
	.string "terminé!$"

Debug_EventScript_Silver_Multi::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, Debug_EventScript_PickSilverPartner
	special LoadPlayerParty
	release
	end

Debug_EventScript_PickSilverPartner::
	switch VAR_STARTER_MON
	case 0, Debug_EventScript_DoSilverMulti_Typhlosion
	case 1, Debug_EventScript_DoSilverMulti_Feraligatr
	case 2, Debug_EventScript_DoSilverMulti_Meganium
	goto Debug_EventScript_DoSilverMulti_Typhlosion

Debug_EventScript_DoSilverMulti_Typhlosion::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, Debug_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, Debug_Text_Clair3Defeat, PARTNER_SILVER_TYPHLOSION_HNS
	goto Debug_EventScript_SilverMultiResult

Debug_EventScript_DoSilverMulti_Feraligatr::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, Debug_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, Debug_Text_Clair3Defeat, PARTNER_SILVER_FERALIGATR_HNS
	goto Debug_EventScript_SilverMultiResult

Debug_EventScript_DoSilverMulti_Meganium::
	multi_2_vs_2 TRAINER_LANCE_3_HNS, Debug_Text_Lance3Defeat, TRAINER_CLAIR_3_HNS, Debug_Text_Clair3Defeat, PARTNER_SILVER_MEGANIUM_HNS
	goto Debug_EventScript_SilverMultiResult

Debug_EventScript_SilverMultiResult::
	switch VAR_RESULT
	case 1, Debug_EventScript_SilverMultiWin
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Debug_EventScript_SilverMultiWin::
	msgbox Debug_Text_SilverMultiVictory, MSGBOX_DEFAULT
	release
	end

Debug_Text_SilverMultiVictory:
	.string "Combat multiple avec SILVER\n"
	.string "terminé!$"

Debug_Text_Lance3Defeat:
	.string "Tu n'as pas fini d'entendre\n"
	.string "parler de moi!$"

Debug_Text_Clair3Defeat:
	.string "Je refuse de l'accepter!$"

Debug_CheckSaveBlock::
	callnative CheckSaveBlock1Size
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock2Size
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock3Size
	msgbox Debug_SaveBlock3Size, MSGBOX_DEFAULT
	callnative CheckPokemonStorageSize
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
	release
	end

Debug_SaveBlock1Size::
	.string "Taille du SaveBlock1:\n"
	.string "{STR_VAR_1}b/{STR_VAR_2}b.\p"
	.string "Espace libre: {STR_VAR_3}b.$"

Debug_SaveBlock2Size::
	.string "Taille du SaveBlock2:\n"
	.string "{STR_VAR_1}b/{STR_VAR_2}b.\p"
	.string "Espace libre: {STR_VAR_3}b.$"

Debug_SaveBlock3Size::
	.string "Taille du SaveBlock3:\n"
	.string "{STR_VAR_1}b/{STR_VAR_2}b.\p"
	.string "Espace libre: {STR_VAR_3}b.$"

Debug_PokemonStorageSize::
	.string "Taille du Stockage {PKMN}:\n"
	.string "{STR_VAR_1}b/{STR_VAR_2}b.\p"
	.string "Espace libre: {STR_VAR_3}b.$"

Debug_CheckROMSpace::
	callnative CheckROMSize
	msgbox Debug_ROMSize, MSGBOX_DEFAULT
	release
	end

Debug_ROMSize::
	.string "Taille de la ROM:\n"
	.string "{STR_VAR_1}MB/32MB. Espace\p"
	.string "libre: {STR_VAR_2}MB.$"

Debug_HatchAnEgg::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_HatchAnEgg_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_ne VAR_RESULT, SPECIES_EGG, DebugScript_HatchAnEgg_CantForceHatch
	special EggHatch
	waitstate
Debug_HatchAnEgg_End::
	releaseall
	end

Debug_NoPokemon::
	msgbox DebugScript_Text_EmptyParty, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_HatchAnEgg_CantForceHatch::
	msgbox DebugScript_HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_Text_EmptyParty::
	.string "Votre équipe est vide.$"

DebugScript_HatchAnEgg_Text_NotAnEgg::
	.string "Ce n'est pas un Oeuf.$"

DebugScript_ZeroDaycareMons::
	msgbox DebugText_DaycareNoPokemon, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_OneDaycareMons::
	msgbox DebugText_DaycareOnePokemon, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_DaycareMonsNotCompatible::
	msgbox DebugText_DaycarePokemonNotCompatible, MSGBOX_DEFAULT
	releaseall
	end

DebugText_DaycareNoPokemon:
	.string "Vous n'avez pas de Pokémon à la\n"
	.string "Pension.$"

DebugText_DaycareOnePokemon:
	.string "Vous n'avez qu'un Pokémon à la\n"
	.string "Pension.$"

DebugText_DaycarePokemonNotCompatible:
	.string "Votre Pokémon à la Pension ne\n"
	.string "peut pas se reproduire!$"

Debug_ShowExpansionVersion::
	callnative BufferExpansionVersion
	msgbox Debug_ExpansionVersion, MSGBOX_DEFAULT
	release
	end

Debug_ExpansionVersion:
	.string "pokeemerald-expansion-fr\n"
	.string "{STR_VAR_1}$"

Debug_Follower_NPC_Not_Enabled::
	msgbox Debug_Enable_To_Use_Follower_NPCs, MSGBOX_DEFAULT
	release
	end

Debug_Enable_To_Use_Follower_NPCs:
	.string "Fonctionnalité indisponible!\n"
	.string "Mettez FNPC_ENABLE_NPC_FOLLOWERS\p"
	.string "à TRUE dans\n"
	.string "'include/config/follower_npc.h'.$"

Debug_Follower_NPC_Event_Script::
	lock
	facefollowernpc
	msgbox Debug_Follower_NPC_Test_Message, MSGBOX_DEFAULT
	releaseall
	end

Debug_Follower_NPC_Test_Message:
	.string "Ceci est un test Follower$"

Debug_EventScript_Steven_Multi::
	call MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	release
	end

Debug_EventScript_WallyTutorial::
	special SavePlayerParty
	special LoadWallyZigzagoon
	special StartWallyTutorialBattle
	waitstate
	special LoadPlayerParty
	release
	end

Debug_BerryPestsDisabled::
	msgbox DebugText_BerryPestsDisabled, MSGBOX_DEFAULT
	release
	end

DebugText_BerryPestsDisabled:
	.string "OW_BERRY_PESTS est désactivé.\n"
	.string "Impossible de forcer des\p"
	.string "parasites.$"

Debug_BerryWeedsDisabled::
	msgbox DebugText_BerryWeedsDisabled, MSGBOX_DEFAULT
	release
	end

DebugText_BerryWeedsDisabled:
	.string "OW_BERRY_WEEDS est désactivé.\n"
	.string "Impossible de forcer des\p"
	.string "mauvaises herbes.$"

Debug_EventScript_InflictStatus1::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Single
	case 1, Debug_EventScript_InflictStatus1_Party
	case 2, Debug_EventScript_InflictStatus1_Close
Debug_EventScript_InflictStatus1_Close:
	releaseall
	end

Debug_EventScript_InflictStatus1_Single:
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Single_Poison
	case 1, Debug_EventScript_InflictStatus1_Single_Paralysis
	case 2, Debug_EventScript_InflictStatus1_Single_Sleep
	case 3, Debug_EventScript_InflictStatus1_Single_Burn
	case 4, Debug_EventScript_InflictStatus1_Single_Freeze
	case 5, Debug_EventScript_InflictStatus1_Single_Frostbite
	case 6, Debug_EventScript_InflictStatus1_Close
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	releaseall
	end

Debug_EventScript_KoPokemon::
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	setko VAR_0x8004
	releaseall
	end

Debug_EventScript_SetHiddenNature::
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	dynmultipush Debug_EventScript_ChangeNature_Text_Hardy, 0
	dynmultipush Debug_EventScript_ChangeNature_Text_Lonely, 1
	dynmultipush Debug_EventScript_ChangeNature_Text_Brave, 2
	dynmultipush Debug_EventScript_ChangeNature_Text_Adamant, 3
	dynmultipush Debug_EventScript_ChangeNature_Text_Naughty, 4
	dynmultipush Debug_EventScript_ChangeNature_Text_Bold, 5
	dynmultipush Debug_EventScript_ChangeNature_Text_Docile, 6
	dynmultipush Debug_EventScript_ChangeNature_Text_Relaxed, 7
	dynmultipush Debug_EventScript_ChangeNature_Text_Impish, 8
	dynmultipush Debug_EventScript_ChangeNature_Text_Lax, 9
	dynmultipush Debug_EventScript_ChangeNature_Text_Timid, 10
	dynmultipush Debug_EventScript_ChangeNature_Text_Hasty, 11
	dynmultipush Debug_EventScript_ChangeNature_Text_Serious, 12
	dynmultipush Debug_EventScript_ChangeNature_Text_Jolly, 13
	dynmultipush Debug_EventScript_ChangeNature_Text_Naive, 14
	dynmultipush Debug_EventScript_ChangeNature_Text_Modest, 15
	dynmultipush Debug_EventScript_ChangeNature_Text_Mild, 16
	dynmultipush Debug_EventScript_ChangeNature_Text_Quiet, 17
	dynmultipush Debug_EventScript_ChangeNature_Text_Bashful, 18
	dynmultipush Debug_EventScript_ChangeNature_Text_Rash, 19
	dynmultipush Debug_EventScript_ChangeNature_Text_Calm, 20
	dynmultipush Debug_EventScript_ChangeNature_Text_Gentle, 21
	dynmultipush Debug_EventScript_ChangeNature_Text_Sassy, 22
	dynmultipush Debug_EventScript_ChangeNature_Text_Careful, 23
	dynmultipush Debug_EventScript_ChangeNature_Text_Quirky, 24
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	special SetHiddenNature
	releaseall
	end

Debug_EventScript_SetAbility::
	special ChoosePartyMon
	waitstate
	callnative DebugNative_GetAbilityNames
	dynmultipush gStringVar1, 0
	dynmultipush gStringVar2, 1
	dynmultipush gStringVar3, 2
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, Debug_EventScript_SetAbilityClose
	special SetAbility
Debug_EventScript_SetAbilityClose:
	releaseall
	end

Debug_EventScript_SetFriendship::
	special ChoosePartyMon
	waitstate
	callnative DebugNative_Party_SetFriendship
	releaseall
	end

Debug_EventScript_GivePokerus::
	special ChoosePartyMon
	waitstate
	callnative DebugNative_Party_SetPokerus
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Poison:
	setstatus1 STATUS1_POISON, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Paralysis:
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Sleep:
	setstatus1 STATUS1_SLEEP, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Burn:
	setstatus1 STATUS1_BURN, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Freeze:
	setstatus1 STATUS1_FREEZE, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Frostbite:
	setstatus1 STATUS1_FROSTBITE, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Party:
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Party_Poison
	case 1, Debug_EventScript_InflictStatus1_Party_Paralysis
	case 2, Debug_EventScript_InflictStatus1_Party_Sleep
	case 3, Debug_EventScript_InflictStatus1_Party_Burn
	case 4, Debug_EventScript_InflictStatus1_Party_Freeze
	case 5, Debug_EventScript_InflictStatus1_Party_Frostbite
	case 6, Debug_EventScript_InflictStatus1_Close
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Poison:
	setstatus1 STATUS1_POISON, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Paralysis:
	setstatus1 STATUS1_PARALYSIS, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Sleep:
	setstatus1 STATUS1_SLEEP, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Burn:
	setstatus1 STATUS1_BURN, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Freeze:
	setstatus1 STATUS1_FREEZE, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Frostbite:
	setstatus1 STATUS1_FROSTBITE, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Text_Single:
	.string "Solo$"

Debug_EventScript_InflictStatus1_Text_PartyWide:
	.string "Toute l'équipe$"

Debug_EventScript_InflictStatus1_Text_Close:
	.string "Fermer$"

Debug_EventScript_InflictStatus1_Text_Poison:
	.string "Poison$"

Debug_EventScript_InflictStatus1_Text_Paralysis:
	.string "Paralysie$"

Debug_EventScript_InflictStatus1_Text_Sleep:
	.string "Sommeil$"

Debug_EventScript_InflictStatus1_Text_Burn:
	.string "Brûlure$"

Debug_EventScript_InflictStatus1_Text_Freeze:
	.string "Gel$"

Debug_EventScript_InflictStatus1_Text_Frostbite:
	.string "Gelure$"

Debug_EventScript_InflictStatus1_Text_KO:
	.string "K.O.$"

Debug_EventScript_ChangeNature_Text_Hardy:
	.string "Hardi$"
Debug_EventScript_ChangeNature_Text_Lonely:
	.string "Solo$"
Debug_EventScript_ChangeNature_Text_Brave:
	.string "Brave$"
Debug_EventScript_ChangeNature_Text_Adamant:
	.string "Rigide$"
Debug_EventScript_ChangeNature_Text_Naughty:
	.string "Mauvais$"
Debug_EventScript_ChangeNature_Text_Bold:
	.string "Assuré$"
Debug_EventScript_ChangeNature_Text_Docile:
	.string "Docile$"
Debug_EventScript_ChangeNature_Text_Relaxed:
	.string "Relax$"
Debug_EventScript_ChangeNature_Text_Impish:
	.string "Malin$"
Debug_EventScript_ChangeNature_Text_Lax:
	.string "Lache$"
Debug_EventScript_ChangeNature_Text_Timid:
	.string "Timide$"
Debug_EventScript_ChangeNature_Text_Hasty:
	.string "Pressé$"
Debug_EventScript_ChangeNature_Text_Serious:
	.string "Sérieux$"
Debug_EventScript_ChangeNature_Text_Jolly:
	.string "Jovial$"
Debug_EventScript_ChangeNature_Text_Naive:
	.string "Naif$"
Debug_EventScript_ChangeNature_Text_Modest:
	.string "Modeste$"
Debug_EventScript_ChangeNature_Text_Mild:
	.string "Doux$"
Debug_EventScript_ChangeNature_Text_Quiet:
	.string "Discret$"
Debug_EventScript_ChangeNature_Text_Bashful:
	.string "Pudique$"
Debug_EventScript_ChangeNature_Text_Rash:
	.string "Foufou$"
Debug_EventScript_ChangeNature_Text_Calm:
	.string "Calme$"
Debug_EventScript_ChangeNature_Text_Gentle:
	.string "Gentil$"
Debug_EventScript_ChangeNature_Text_Sassy:
	.string "Malpoli$"
Debug_EventScript_ChangeNature_Text_Careful:
	.string "Prudent$"
Debug_EventScript_ChangeNature_Text_Quirky:
	.string "Bizarre$"

Debug_EventScript_EWRAMCounters::
	callnative CheckEWRAMCounters
	msgbox Debug_EventScript_EWRAMCounters_Text, MSGBOX_DEFAULT
	release
	end

Debug_EventScript_EWRAMCounters_Text::
	.string "Pas Follower: {STR_VAR_1}.\n"
	.string "Chaîne de Pêche: {STR_VAR_2}.$"

Debug_EventScript_FontTest_Text_1::
	.string "{FONT_SMALL_NARROWER}Angel Adept\n"
	.string "Blind Bodice Clique Coast Dunce\p"
	.string "Docile Enact Eosin Furlong Focal\n"
	.string "Gnome Gondola Human Hoist Inlet\p"
	.string "Iodine Justin Jocose Knoll Koala\n"
	.string "Linden Loads Milliner Modal\p"
	.string "Number Nodule Onset Oddball\n"
	.string "Pneumo Poncho Quanta Qophs Rhone\p"
	.string "Roman Snout Sodium Tundra Tocsin\n"
	.string "Uncle Udder Vulcan Vocal Whale\p"
	.string "Woman Xmas Xenon Yunnan Young\n"
	.string "Zloty Zodiac.$"

Debug_EventScript_FontTest_Text_2::
	.string "{FONT_SMALL_NARROWER}Ange,\n"
	.string "abricot, arène et azur. Benoît\p"
	.string "boit du cacao brûlant. Chloé\n"
	.string "cache cinq clés près du cœur.\p"
	.string "Didier décore une drôle de\n"
	.string "demeure.$"

Debug_EventScript_FontTest_Text_3::
	.string "{FONT_SMALL_NARROWER}Élise\n"
	.string "écrit: été, élève, être et Noël.\p"
	.string "François goûte un gâteau glacé.\n"
	.string "Hélène habite un hôtel haut\p"
	.string "perché.$"

Debug_EventScript_FontTest_Text_4::
	.string "{FONT_SMALL_NARROWER}Isidore\n"
	.string "imagine une île infinie. Jules\p"
	.string "joue avec un jouet jaune. Kilian\n"
	.string "garde un koala près du kiosque.\p"
	.string "Léon lit un long livre.$"

Debug_EventScript_FontTest_Text_5::
	.string "{FONT_SMALL_NARROWER}Mélanie\n"
	.string "mêle mûres et melon. Ninon note\p"
	.string "neuf nombres nouveaux. Oscar\n"
	.string "observe onze oiseaux. Paul\p"
	.string "prépare plusieurs poèmes.$"

Debug_EventScript_FontTest_Text_6::
	.string "{FONT_SMALL_NARROWER}Quentin\n"
	.string "quitte le quai à quinze heures.\p"
	.string "René rêve près de la rivière.\n"
	.string "Sophie sèche ses souliers. Théo\p"
	.string "trouve trois trésors.$"

Debug_EventScript_FontTest_Text_7::
	.string "{FONT_SMALL_NARROWER}Ulysse\n"
	.string "utilise une flûte usée. Victor\p"
	.string "voit vingt vélos verts. William\n"
	.string "voyage avec wagon et wapiti.\p"
	.string "Xavier examine deux xylophones.$"

Debug_EventScript_FontTest_Text_8::
	.string "{FONT_SMALL_NARROWER}Yann joue\n"
	.string "au yoyo dans l'Yonne. Zoé\p"
	.string "zigzague près du zoo. À Évry:\n"
	.string "âne, ça, Noël, où, sûr, île et\p"
	.string "forêt.$"


Debug_EventScript_FontTest_Text_9::                 @ Special thanks to Nintendo for this nice pangram to test other glyphs
	.string "{FONT_SMALL_NARROWER}42 × 138 =\n"
	.string "5796. M. Jock, docteur du quiz\p"
	.string "TV: 20% de lynx en moins au\n"
	.string "café; voilà, ils “valent” ♂1/♀1\p"
	.string "= ¥1.\p"
	.string "Cela fait 10 + 9 - 8 = 11. La\n"
	.string "Nintendo GBA peut se connecter à\p"
	.string "une console Nintendo GameCube!\n"
	.string "Il prétend l'avoir fait les yeux\p"
	.string "fermés…?$"

Debug_PrintFontTest::
	msgbox Debug_EventScript_FontTest_Text_1, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_2, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_3, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_4, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_5, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_6, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_7, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_8, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_9, MSGBOX_DEFAULT
	releaseall
	end

Debug_EventScript_FontTest::
	lockall
	goto Debug_PrintFontTest
@	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
@	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
@	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
@	switch VAR_RESULT
@	case 0, Debug_EventScript_InflictStatus1_Single
@	case 1, Debug_EventScript_InflictStatus1_Party
@	case 2, Debug_EventScript_InflictStatus1_Close
@Debug_EventScript_InflictStatus1_Close:
@	releaseall
@	end

Debug_EventScript_TellTheTime::
	callnative DebugMenu_CalculateTime
	msgbox Debug_EventScript_TellTheTime_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Debug_EventScript_PrintTimeOfDay::
	callnative DebugMenu_CalculateTimeOfDay
	msgbox DebugEventScript_PrintWeekday_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Debug_EventScript_FakeRTCNotEnabled::
	msgbox Debug_EventScript_FakeRTCNotEnabled_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	return

Debug_EventScript_FakeRTCNotEnabled_Text_0:
	.string "Vous n'avez pas le faux RTC\n"
	.string "activé. Activez le dans:\p"
	.string "include/ config/overworld.h$"


Debug_EventScript_TellTheTime_Text_0:
	.string "Date et heure: {STR_VAR_1},\n"
	.string "{STR_VAR_2}:{STR_VAR_3}$"

DebugEventScript_PrintWeekday_Text_0:
	.string "Heure du Jour: {STR_VAR_1}$"
