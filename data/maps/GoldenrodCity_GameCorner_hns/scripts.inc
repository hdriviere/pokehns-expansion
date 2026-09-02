GoldenrodCity_GameCorner_hns_MapScripts::
	.byte 0

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PrizeClerkMons::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChoosePrizeMon::
	@callnative DisableStaticRandomizer
	showcoinsbox 1, 1
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	multichoice 20, 0, MULTI_PRIZE_MONS, FALSE
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Abra
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Clefairy
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Munchlax
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Dratini
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_Porygon
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	case 127, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange::
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Abra::
	setvar VAR_TEMP_1, SPECIES_ABRA
	setvar VAR_TEMP_2, 120
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Clefairy::
	setvar VAR_TEMP_1, SPECIES_CLEFAIRY
	setvar VAR_TEMP_2, 500
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Munchlax::
	setvar VAR_TEMP_1, SPECIES_MUNCHLAX
	setvar VAR_TEMP_2, 2800
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Dratini::
	setvar VAR_TEMP_1, SPECIES_DRATINI
	setvar VAR_TEMP_2, 5500
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_Porygon::
	setvar VAR_TEMP_1, SPECIES_PORYGON
	setvar VAR_TEMP_2, 6500
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmPrizeMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_YouWantPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins
	switch VAR_TEMP_1
	updatecoinsbox 1, 1
	playse SE_SHOP
	case SPECIES_ABRA,     GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveAbra
	case SPECIES_CLEFAIRY, GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveClefairy
	case SPECIES_DRATINI,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveDratini
	case SPECIES_MUNCHLAX,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveMunchlax
	case SPECIES_PORYGON,  GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePorygon
	case SPECIES_PINSIR,   GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePinsir
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveAbra::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveClefairy::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveDratini::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GiveMunchlax::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePorygon::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_GivePinsir::
	givemon VAR_TEMP_1, 15
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_CheckReceivedMon::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC
	goto_if_eq VAR_RESULT, 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyFull
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyFull::
	msgbox Route119_WeatherInstitute_2F_Text_NoRoomForPokemon
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	closemessage
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon::
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty_Nickname_Nuzlocke::
	message GoldenrodGamecorner_Text_GiveNicknameToThisMon
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoins::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty::
	removecoins VAR_TEMP_2
	playse SE_SHOP
	updatecoinsbox 1, 1
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonParty_Nickname_Nuzlocke
	msgbox GoldenrodGamecorner_Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NicknamePartyMon
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReceivedMonPC::
	removecoins VAR_TEMP_2
	playse SE_SHOP
	updatecoinsbox 1, 1
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_TransferredToPC
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_EndPrizeExchange
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PartyMon::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	end
	
GoldenrodCity_GameCorner_PrizeRoom_EventScript_PcMon::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_EventScript_SendMon
	call Common_EventScript_NameReceivedBoxMon
	goto GoldenrodCity_GameCorner_EventScript_SendMon
	closemessage
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	release
	end

GoldenrodCity_GameCorner_EventScript_SendMon::
	call Common_EventScript_TransferredToPC
	closemessage
	hidecoinsbox 0, 0
	@callnative EnableStaticRandomizer
	release
	end

	.set TM_ICE_BEAM_COINS, 4000
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_REST_COINS, 2000
	.set TM_SWORDS_DANCE_COINS, 3000
	.set TM_SUBSTITUTE_COINS, 2000

GoldenrodCity_GameCorner_PrizeRoom_EventScript_PrizeClerkTMs::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NeedCoinCase
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorIntro, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrizeMessage
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrizeMessage::
	message GoldenrodCity_GameCorner_Text_PrizeVendorWhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize::
	message GoldenrodCity_GameCorner_Text_PrizeVendorWhichPrize
	waitmessage
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ChooseTMPrize::
	dynmultichoice 12, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_GameCorner_PrizeRoom_Text_TM44, GoldenrodCity_GameCorner_PrizeRoom_Text_TM90, GoldenrodCity_GameCorner_PrizeRoom_Text_TM75, GoldenrodCity_GameCorner_PrizeRoom_Text_TM13, GoldenrodCity_GameCorner_PrizeRoom_Text_TM24, GoldenrodCity_GameCorner_PrizeRoom_Text_TM35, GoldenrodCity_GameCorner_PrizeRoom_Text_Cancel
	switch VAR_RESULT
	case 0, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMRest
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSubstitute
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSwordsDance
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMIceBeam
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMThunderbolt
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMFlamethrower
	case 6, GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 6
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMRest::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_REST
	setvar VAR_0x8004, ITEM_TM_REST
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSwordsDance::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM75
	setvar VAR_0x8004, ITEM_TM75
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_TMSubstitute::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM90
	setvar VAR_0x8004, ITEM_TM90
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_SoYourChoiceIsTM, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect
	goto_if_unset FLAG_FINITE_TMS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite
	switch VAR_TEMP_1
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeam
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrower
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRest
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDance
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstitute
	case 6, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderbolt
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_ConfirmTMPrizeInfinite::
	switch VAR_TEMP_1
	case 1, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeamInfinite
	case 2, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrowerInfinite
	case 3, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRestInfinite
	case 4, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDanceInfinite
	case 5, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstituteInfinite
	case 6, GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderboltInfinite
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeamInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_ICE_BEAM, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrowerInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_FLAMETHROWER, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderboltInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_THUNDERBOLT, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRestInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_REST_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM_REST, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_REST_COINS
	additem ITEM_TM_REST
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDanceInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SWORDS_DANCE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM75, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_SWORDS_DANCE_COINS
	additem ITEM_TM75
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstituteInfinite::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SUBSTITUTE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitem ITEM_TM90, 1
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis
	removecoins TM_SUBSTITUTE_COINS
	additem ITEM_TM90
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_ICE_BEAM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMRest::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_REST_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_REST_COINS
	additem ITEM_TM_REST
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSwordsDance::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SWORDS_DANCE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM75
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_SWORDS_DANCE_COINS
	additem ITEM_TM75
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_BuyTMSubstitute::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_SUBSTITUTE_COINS, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM90
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM
	removecoins TM_SUBSTITUTE_COINS
	additem ITEM_TM90
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NotEnoughCoinsForTM::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_YouAlreadyHaveThis::
	msgbox GoldenrodCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_PrizeRoom_EventScript_ReturnToChooseTMPrize
	end

GoldenrodCity_GameCorner_PrizeRoom_EventScript_CancelTMSelect::
	msgbox GoldenrodCity_GameCorner_Text_PrizeVendorQuit, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_Text_TM44:
	.string "REPOS{CLEAR_TO 0x58}2 000 J.$"

GoldenrodCity_GameCorner_PrizeRoom_Text_TM90:
	.string "CLONAGE{CLEAR_TO 0x58}2 000 J.$"

GoldenrodCity_GameCorner_PrizeRoom_Text_TM75:
	.string "DANSE-LAMES{CLEAR_TO 0x58}3 000 J.$"

GoldenrodCity_GameCorner_PrizeRoom_Text_TM13:
	.string "LASER GLACE{CLEAR_TO 0x58}4 000 J.$"

GoldenrodCity_GameCorner_PrizeRoom_Text_TM24:
	.string "TONNERRE{CLEAR_TO 0x58}4 000 J.$"

GoldenrodCity_GameCorner_PrizeRoom_Text_TM35:
	.string "LANCE-FLAMMES{CLEAR_TO 0x58}4 000 J.$"

GoldenrodCity_GameCorner_PrizeRoom_Text_Cancel:
	.string "SORTIR$"

GoldenrodCity_GameCorner_PrizeRoom_Text_SoYourChoiceIsTM:
	.string "Tu choisis donc\n"
	.string "{STR_VAR_1} {STR_VAR_2}?$"

GoldenrodCity_GameCorner_PrizeRoom_Text_YouAlreadyHaveThis:
	.string "Tu possèdes déjà cet objet.$"

GoldenrodCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PokefanM1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Hiker::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_MoveTutorInside, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_PokefanM2::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_PokefanM2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_CooltrainerM::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_EventScript_Pharmacist::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_Pharmacist, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_GameCorner_PrizeRoom_Text_YouWantPrize:
	.string "Tu veux {STR_VAR_1}?$"

GoldenrodCity_GameCorner_Text_PlayerObtainedTheMon:
	.string "{PLAYER} obtient {STR_VAR_1} $!$"

GoldenrodGamecorner_Text_GiveNicknameToThisMon:
	.string "Donner un surnom à {STR_VAR_1}?$"

GoldenrodCity_GameCorner_Text_PrizeVendorIntro:
    .string "Bienvenue!\p"
    .string "On échange les jetons contre de\n"
    .string "fabuleux prix!$"

GoldenrodCity_GameCorner_Text_PrizeVendorWhichPrize:
    .string "Quel prix désirestu?$"

GoldenrodCity_GameCorner_Text_PrizeVendorHereYouGo:
    .string "Et voilà!$"

GoldenrodCity_GameCorner_Text_PrizeVendorNeedMoreCoins:
    .string "Désolé! Il faut plus de jetons.$"

GoldenrodCity_GameCorner_Text_PrizeVendorNoMoreRoom:
    .string "Oh, mais votre Sac est plein...$"

GoldenrodCity_GameCorner_Text_PrizeVendorQuit:
    .string "Ah bon? Revenez quand vous aurez\n"
    .string "économisé davantage de Jetons!$"

GoldenrodCity_GameCorner_Text_PrizeVendorNoCoinCase:
    .string "Oh? Tu n'as pas de BOITE JETON.$"

GoldenrodCity_GameCorner_Text_Pharmacist:
	.string "Je joue toujours sur cette\n"
	.string "machine.\p"
	.string "Je crois qu'elle rapporte plus\n"
	.string "les autres.$"

GoldenrodCity_GameCorner_Text_Woman:
	.string "Je n'arrête pas de gagner!$"

GoldenrodCity_GameCorner_Text_PokefanM1:
	.string "J'adore cette nouvelle machine.\p"
	.string "Elle est plus difficile que\n"
	.string "de CELADOPOLE.$"

GoldenrodCity_GameCorner_Text_CooltrainerM:
	.string "La vie est un pari.\p"
	.string "Je vais jouer\n"
	.string "jusqu'à l'épuisement!$"

GoldenrodCity_GameCorner_Text_PokefanF:
	.string "La roulette…\p"
	.string "Je la préfère aux machines:\n"
	.string "les probabilités sont faciles.\p"
	.string "Mais elle rapporte bien moins.$"

GoldenrodCity_GameCorner_Text_CooltrainerF:
    .string "Tant que je perds... Je reste!$"

GoldenrodCity_GameCorner_Text_Gentleman:
	.string "J'ai appris LASER GLACE à mon\n"
	.string "Pokémon.\p"
	.string "Obtenir assez de Jetons fut dur,\n"
	.string "mais ça en valait la peine.$"

GoldenrodCity_GameCorner_Text_PokefanM2:
	.string "Je perdais aux machines et j'ai\n"
	.string "tout gâché à la roulette.\p"
	.string "Furieux, j'ai jeté ma\n"
	.string "BOITE JETONS\p"
	.string "dans le SOUTERRAIN.$"

GoldenrodCity_GameCorner_Text_MoveTutorInside:
    .string "Wahahah! Encore des jetons!$"

GoldenrodCity_GameCorner_Text_LeftTheirDrink:
    .string "Quelqu'un a oublié sa boisson.$"

@ ========================================
@ VOLTORB FLIP GAME IMPLEMENTATION
@ ========================================

GoldenrodCity_GameCorner_EventScript_VoltorbFlip::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_GameCorner_EventScript_VF_NoCoinCase
	message GoldenrodCity_GameCorner_Text_VF_Welcome
	waitmessage
	playbgm MUS_RG_OAK, FALSE
	setvar VAR_TEMP_4, 0

GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap::
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, MAX_COINS, GoldenrodCity_GameCorner_EventScript_VF_ShowMenu
	msgbox GoldenrodCity_GameCorner_Text_VF_CoinCap, MSGBOX_DEFAULT
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_7, 0
	hidecoinsbox 0, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_VF_ShowMenu::
	showcoinsbox 1, 1
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	message GoldenrodCity_GameCorner_Text_VF_PlayLevel
	waitmessage
	dynmultichoice 19, 6, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_GameCorner_Text_VF_OptPlay, GoldenrodCity_GameCorner_Text_VF_OptGameInfo, GoldenrodCity_GameCorner_Text_VF_OptQuit
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_EventScript_VF_Play
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_EventScript_VF_GameInfo
	@ Quit or B-press
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_7, 0
	closemessage
	hidecoinsbox 0, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_VF_GameInfo::
	message GoldenrodCity_GameCorner_Text_VF_WhichInfo
	waitmessage
	dynmultichoice 19, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, GoldenrodCity_GameCorner_Text_VF_OptHowToPlay, GoldenrodCity_GameCorner_Text_VF_OptHint, GoldenrodCity_GameCorner_Text_VF_OptAboutNotes, GoldenrodCity_GameCorner_Text_VF_OptReturn
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_EventScript_VF_HowToPlay
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_EventScript_VF_Hint
	goto_if_eq VAR_RESULT, 2, GoldenrodCity_GameCorner_EventScript_VF_AboutNotes
	goto GoldenrodCity_GameCorner_EventScript_VF_ShowMenu

GoldenrodCity_GameCorner_EventScript_VF_HowToPlay::
	msgbox GoldenrodCity_GameCorner_Text_VF_HowToPlay, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_GameInfo

GoldenrodCity_GameCorner_EventScript_VF_Hint::
	msgbox GoldenrodCity_GameCorner_Text_VF_HintText, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_GameInfo

GoldenrodCity_GameCorner_EventScript_VF_AboutNotes::
	msgbox GoldenrodCity_GameCorner_Text_VF_AboutNotes, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_GameInfo

GoldenrodCity_GameCorner_EventScript_VF_Play::
	closemessage
	copyvar VAR_TEMP_6, VAR_TEMP_4
	setvar VAR_TEMP_5, 0
	hidecoinsbox 0, 5
	special Special_ViewVoltorbFlip
	waitstate
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_GameCorner_EventScript_VF_HandleLoss
	goto_if_eq VAR_RESULT, 1, GoldenrodCity_GameCorner_EventScript_VF_HandleWin
	goto GoldenrodCity_GameCorner_EventScript_VF_HandleQuit
	end

GoldenrodCity_GameCorner_EventScript_VF_HandleWin::
	msgbox GoldenrodCity_GameCorner_Text_VF_GameClear, MSGBOX_DEFAULT
	copyvar VAR_TEMP_1, VAR_TEMP_5
	showcoinsbox 1, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_1
	msgbox GoldenrodCity_GameCorner_Text_VF_ReceivedCoins, MSGBOX_DEFAULT
	addcoins VAR_TEMP_5
	setvar VAR_TEMP_5, 0
	updatecoinsbox 1, 1
	goto_if_le VAR_TEMP_4, VAR_TEMP_6, GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	msgbox GoldenrodCity_GameCorner_Text_VF_Advanced, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap

GoldenrodCity_GameCorner_EventScript_VF_HandleLoss::
	msgbox GoldenrodCity_GameCorner_Text_VF_OhNo, MSGBOX_DEFAULT
	goto_if_ge VAR_TEMP_4, VAR_TEMP_6, GoldenrodCity_GameCorner_EventScript_VF_ShowMenu
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	msgbox GoldenrodCity_GameCorner_Text_VF_Dropped, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_ShowMenu

GoldenrodCity_GameCorner_EventScript_VF_HandleQuit::
	goto_if_eq VAR_TEMP_5, 0, GoldenrodCity_GameCorner_EventScript_VF_QuitNoCoins
	copyvar VAR_TEMP_1, VAR_TEMP_5
	showcoinsbox 1, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_1
	msgbox GoldenrodCity_GameCorner_Text_VF_ReceivedCoins, MSGBOX_DEFAULT
	addcoins VAR_TEMP_5
	setvar VAR_TEMP_5, 0
	updatecoinsbox 1, 1

GoldenrodCity_GameCorner_EventScript_VF_QuitNoCoins::
	goto_if_ge VAR_TEMP_4, VAR_TEMP_6, GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap
	copyvar VAR_TEMP_A, VAR_TEMP_4
	addvar VAR_TEMP_A, 1
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	msgbox GoldenrodCity_GameCorner_Text_VF_Dropped, MSGBOX_DEFAULT
	goto GoldenrodCity_GameCorner_EventScript_VF_CheckCoinCap

GoldenrodCity_GameCorner_EventScript_VF_NoCoinCase::
	msgbox GoldenrodCity_GameCorner_Text_VF_NeedCoinCase, MSGBOX_DEFAULT
	releaseall
	end

GoldenrodCity_GameCorner_EventScript_VFAttendant1::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_VFAttendant1, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	waitmovement 0
	release
	end

GoldenrodCity_GameCorner_EventScript_VFAttendant2::
	lock
	faceplayer
	msgbox GoldenrodCity_GameCorner_Text_VFAttendant2, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	waitmovement 0
	release
	end

@ Voltorb Flip Menu Option Strings
GoldenrodCity_GameCorner_Text_VF_OptPlay:
	.string "JOUER$"

GoldenrodCity_GameCorner_Text_VF_OptGameInfo:
	.string "INFORMATIONS$"

GoldenrodCity_GameCorner_Text_VF_OptQuit:
	.string "QUITTER$"

GoldenrodCity_GameCorner_Text_VF_OptHowToPlay:
	.string "Règles$"

GoldenrodCity_GameCorner_Text_VF_OptHint:
	.string "INDICES$"

GoldenrodCity_GameCorner_Text_VF_OptAboutNotes:
	.string "LE MEMO$"

GoldenrodCity_GameCorner_Text_VF_OptReturn:
	.string "RETOUR$"

@ Voltorb Flip Dialogue Strings
GoldenrodCity_GameCorner_Text_VF_Welcome:
	.string "Bienvenue à la VOLTORBATAILLE!\p$"

GoldenrodCity_GameCorner_Text_VF_PlayLevel:
	.string "Jouer à Voltorbataille niveau\n"
	.string "{STR_VAR_1}?$"

GoldenrodCity_GameCorner_Text_VF_GameClear:
	.string "Partie gagnée!\p"
	.string "Tu as trouvé tous les panneaux\n"
	.string "x2 et x3 cachés!$"

GoldenrodCity_GameCorner_Text_VF_ReceivedCoins:
	.string "Tu reçois\n"
	.string "{STR_VAR_1} Jeton(s)!$"

GoldenrodCity_GameCorner_Text_VF_Advanced:
	.string "Le jeu est monté au niveau\n"
	.string "{STR_VAR_1}!$"

GoldenrodCity_GameCorner_Text_VF_OhNo:
	.string "Dommage! Vous avez 0 Jeton!$"

GoldenrodCity_GameCorner_Text_VF_Dropped:
	.string "Le jeu est descendu au niveau\n"
	.string "{STR_VAR_1}!$"

GoldenrodCity_GameCorner_Text_VF_CoinCap:
	.string "Tu as accumulé 9 999 JETONS.\p"
	.string "Tu ne peux plus en obtenir.$"

GoldenrodCity_GameCorner_Text_VF_WhichInfo:
	.string "Que souhaitez-vous savoir?$"

GoldenrodCity_GameCorner_Text_VF_HowToPlay:
	.string "Dans la VOLTORBATAILLE, retourne\n"
	.string "les panneaux pour trouver\p"
	.string "les chiffres cachés.\p"
	.string "Ils cachent les chiffres 1 à 3\n"
	.string "et des VOLTORBE.\p"
	.string "Le premier chiffre détermine ton\n"
	.string "gain initial en Jetons.\p"
	.string "Chaque nouveau chiffre multiplie\n"
	.string "le total: 2 par x2 et 3 par x3.\p"
	.string "Retourner un VOLTORBE termine la\n"
	.string "partie et fait perdre les Jetons\p"
	.string "gagnés pendant cette manche!\p"
	.string "Choisis QUITTER pour conserver\n"
	.string "les Jetons déjà trouvés.\p"
	.string "Trouve tous les panneaux x2 et\n"
	.string "x3\p"
	.string "pour gagner et passer au niveau\p"
	.string "suivant!$"

GoldenrodCity_GameCorner_Text_VF_HintText:
	.string "Les nombres au bord du plateau\n"
	.string "indiquent le total caché dans\p"
	.string "chaque ligne ou colonne.\p"
	.string "Plus ce nombre est élevé, plus\n"
	.string "les panneaux de grande valeur y\n"
	.string "sont nombreux.\p"
	.string "Le compteur indique combien de\n"
	.string "VOLTORBE s'y cachent.\p"
	.string "Croise les deux totaux pour\n"
	.string "trouver les panneaux sûrs!$"

GoldenrodCity_GameCorner_Text_VF_AboutNotes:
	.string "Utilise le mode mémo ({L_BUTTON} et {R_BUTTON})\n"
	.string "pour marquer les panneaux avec\p"
	.string "les chiffres 1 à 3 ou VOLTORBE.\p"
	.string "Marque un panneau que tu penses\n"
	.string "connaître.\p"
	.string "Retourne-le une fois sûr.\p"
	.string "Applique à nouveau une note pour\n"
	.string "l'effacer.$"

GoldenrodCity_GameCorner_Text_VF_NeedCoinCase:
	.string "Oh? Tu n'as pas de BOITE JETONS.$"

GoldenrodCity_GameCorner_Text_VFAttendant1:
	.string "Tu veux une VOLTORBATAILLE?\p"
	.string "Place-toi de l'autre côté de la\n"
	.string "table.$"

GoldenrodCity_GameCorner_Text_VFAttendant2:
	.string "Essaie l'autre côté de la table,\n"
	.string "l'ami.$"
