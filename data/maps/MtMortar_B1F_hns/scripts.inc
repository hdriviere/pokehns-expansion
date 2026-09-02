MtMortar_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO_HNS, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "Hé!\p"
	.string "Je suis le ROI du KARATE!\p"
	.string "Je m'entraîne seul dans le noir!\p"
	.string "Toi! Moi! Combat!\p"
	.string "Yaaaaaah!$"

MountMortar4_Text_KiyoWin:
	.string "Waaaarggh! Perdu!$"

MountMortar4_Text_KiyoTyrogueReward:
	.string "J'suis...mauvais.\p"
	.string "Mon entraînement n'est pas\n"
	.string "encore suffisant.\p"
	.string "Mais j'admets ma défaite.\p"
	.string "En gage de récompense, je vais\n"
	.string "te\p"
	.string "donner un Pokémon de combat\n"
	.string "rare.$"

MountMortar4_Text_ReceiveTyrogue:
	.string "{PLAYER} reçoit DEBUGANT.$"

MountMortar4_Text_KiyoGotTyrogue:
	.string "DEBUGANT est du type COMBAT.\p"
	.string "Il évolue en un puissant\n"
	.string "Pokémon.\p"
	.string "Alors fais comme moi...\n"
	.string "Entraîne-toi!\p"
	.string "Adieu!$"

MountMortar4_Text_KiyoFullParty:
	.string "Ghh... Ton équipe est au\n"
	.string "complet!$"
