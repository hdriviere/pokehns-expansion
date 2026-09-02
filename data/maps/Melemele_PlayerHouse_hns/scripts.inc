Melemele_PlayerHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Melemele_PlayerHouse_hns_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALOLA_STATE, 1, Alola_Melemele_SamsonOakVillaIntro_Trigger
	.2byte 0


Alola_Melemele_SamsonOakVillaIntro_Trigger::
	lock
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2, MSGBOX_AUTOCLOSE
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3
	waitmovement 0
	setvar VAR_ALOLA_STATE, 2
	release
	end


Alola_Melemele_SamsonOakVilla_Dialogue::
	lock
	faceplayer
	goto_if_set FLAG_BATTLED_TAPU_KOKO, Alola_Melemele_SamsonOakVilla_Dialogue_4
Alola_Melemele_SamsonOakVilla_Dialogue_2:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_16
Alola_Melemele_SamsonOakVilla_Dialogue_14:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_10
	dynmultichoice 20, 4, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, Alola_Melemele_SamsonOakVilla_Dialogue_Text_11, Alola_Melemele_SamsonOakVilla_Dialogue_Text_12, Alola_Melemele_SamsonOakVilla_Dialogue_Text_13, Alola_Melemele_SamsonOakVilla_Dialogue_Text_14, Alola_Melemele_SamsonOakVilla_Dialogue_Text_15
	compare VAR_RESULT, 0
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_31
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_32
	compare VAR_RESULT, 2
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_33
	compare VAR_RESULT, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_53
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_34, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_1:
	compare VAR_ALOLA_STATE, 3
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_10
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_3:
	goto_if_set FLAG_BATTLED_TAPU_BULU, Alola_Melemele_SamsonOakVilla_Dialogue_7
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_4:
	goto_if_set FLAG_BATTLED_TAPU_LELE, Alola_Melemele_SamsonOakVilla_Dialogue_3
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_7:
	goto_if_set FLAG_BATTLED_TAPU_FINI, Alola_Melemele_SamsonOakVilla_Dialogue_1
	goto Alola_Melemele_SamsonOakVilla_Dialogue_2

Alola_Melemele_SamsonOakVilla_Dialogue_10:
	msgbox Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_0, MSGBOX_AUTOCLOSE
	giveitem ITEM_BEAST_BALL
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_1, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 4
	clearflag FLAG_HIDE_PHANT_OUTSIDE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_13:
	goto_if_set FLAG_DEFEATED_MELEMELE_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_25
Alola_Melemele_SamsonOakVilla_Dialogue_23:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_9, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_15:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_19
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_16:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_15
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_19:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_13
	goto Alola_Melemele_SamsonOakVilla_Dialogue_14

Alola_Melemele_SamsonOakVilla_Dialogue_22:
	goto_if_set FLAG_DEFEATED_SAMSON_OAK, Alola_Melemele_SamsonOakVilla_Dialogue_40
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_55
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_8, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_24:
	goto_if_set FLAG_DEFEATED_ULAULA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_28
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_25:
	goto_if_set FLAG_DEFEATED_AKALA_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_24
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_28:
	goto_if_set FLAG_DEFEATED_PONI_TOTEM, Alola_Melemele_SamsonOakVilla_Dialogue_22
	goto Alola_Melemele_SamsonOakVilla_Dialogue_23

Alola_Melemele_SamsonOakVilla_Dialogue_31:
	getcaughtmon SPECIES_MEOWTH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_44
Alola_Melemele_SamsonOakVilla_Dialogue_43:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_23, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_32:
	getcaughtmon SPECIES_MAROWAK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_47
Alola_Melemele_SamsonOakVilla_Dialogue_46:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_27, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_33:
	getcaughtmon SPECIES_VULPIX_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_50
Alola_Melemele_SamsonOakVilla_Dialogue_49:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_30, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_34:
	getcaughtmon SPECIES_RAICHU_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_68
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46
	end

Alola_Melemele_SamsonOakVilla_Dialogue_52:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_33, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_40:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_2, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_44:
	getcaughtmon SPECIES_PERSIAN_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_58
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_47:
	getcaughtmon SPECIES_DIGLETT_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_60
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_50:
	getcaughtmon SPECIES_NINETALES_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_62
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_53:
	getcaughtmon SPECIES_GEODUDE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_64
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_55:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_4
	trainerbattle_no_intro TRAINER_SAMSON_OAK_HNS, Alola_Melemele_SamsonOakVilla_Dialogue_Text_5
	special GivePartyMonMarineRibbon
	special HealPlayerParty
	setflag FLAG_DEFEATED_SAMSON_OAK
	setflag FLAG_FLYOVER_TAPU_KOKO
	setflag FLAG_FLYOVER_TAPU_LELE
	setflag FLAG_FLYOVER_TAPU_BULU
	setflag FLAG_FLYOVER_TAPU_FINI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_6, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_7, MSGBOX_AUTOCLOSE
	setvar VAR_ALOLA_STATE, 3
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_58:
	getcaughtmon SPECIES_RATTATA_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_66
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_60:
	getcaughtmon SPECIES_DUGTRIO_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_34
	goto Alola_Melemele_SamsonOakVilla_Dialogue_46

Alola_Melemele_SamsonOakVilla_Dialogue_62:
	getcaughtmon SPECIES_SANDSHREW_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_70
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_64:
	getcaughtmon SPECIES_GRAVELER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_72
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_66:
	getcaughtmon SPECIES_RATICATE_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_74
	goto Alola_Melemele_SamsonOakVilla_Dialogue_43

Alola_Melemele_SamsonOakVilla_Dialogue_68:
	goto_if_unset FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_76
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_26, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_70:
	getcaughtmon SPECIES_SANDSLASH_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_79
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_72:
	getcaughtmon SPECIES_GOLEM_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_81
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_74:
	goto_if_unset FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_83
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_22, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_76:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_86
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_86
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_79:
	getcaughtmon SPECIES_GRIMER_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_93
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_81:
	getcaughtmon SPECIES_EXEGGUTOR_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_95
	goto Alola_Melemele_SamsonOakVilla_Dialogue_52

Alola_Melemele_SamsonOakVilla_Dialogue_83:
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_97
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_97
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_86:
	setflag FLAG_CAUGHT_ALL_AKALA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_24
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_107
Alola_Melemele_SamsonOakVilla_Dialogue_105:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_93:
	getcaughtmon SPECIES_MUK_ALOLA
	compare VAR_RESULT, 1
	goto_if_eq Alola_Melemele_SamsonOakVilla_Dialogue_113
	goto Alola_Melemele_SamsonOakVilla_Dialogue_49

Alola_Melemele_SamsonOakVilla_Dialogue_95:
	goto_if_unset FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_115
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_32, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_97:
	setflag FLAG_CAUGHT_ALL_MELEMELE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_18
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_121
Alola_Melemele_SamsonOakVilla_Dialogue_119:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_104:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_106:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_110
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_107:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_106
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_110:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_104
	goto Alola_Melemele_SamsonOakVilla_Dialogue_105

Alola_Melemele_SamsonOakVilla_Dialogue_113:
	goto_if_unset FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_127
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_29, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_115:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_130
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_118:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_20, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_120:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_124
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_121:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_120
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_124:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_118
	goto Alola_Melemele_SamsonOakVilla_Dialogue_119

Alola_Melemele_SamsonOakVilla_Dialogue_127:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_137
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_137
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_130:
	setflag FLAG_CAUGHT_ALL_PONI
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_31
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_147
Alola_Melemele_SamsonOakVilla_Dialogue_145:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_137:
	setflag FLAG_CAUGHT_ALL_ULAULA
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_16, MSGBOX_AUTOCLOSE
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_17
	playfanfare MUS_HG_OBTAIN_EGG
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_28
	waitfanfare
	goto_if_set FLAG_CAUGHT_ALL_AKALA, Alola_Melemele_SamsonOakVilla_Dialogue_156
Alola_Melemele_SamsonOakVilla_Dialogue_154:
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_21, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_144:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_146:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_150
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_147:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_146
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_150:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_144
	goto Alola_Melemele_SamsonOakVilla_Dialogue_145

Alola_Melemele_SamsonOakVilla_Dialogue_153:
	playfanfare MUS_HG_BUG_CONTEST_1ST_PLACE
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_19, MSGBOX_AUTOCLOSE
	waitfanfare
	playse SE_PIN
	applymovement SamsonOakVilla, Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0
	waitmovement 0
	msgbox Alola_Melemele_SamsonOakVilla_Dialogue_Text_25, MSGBOX_AUTOCLOSE
	release
	end

Alola_Melemele_SamsonOakVilla_Dialogue_155:
	goto_if_set FLAG_CAUGHT_ALL_PONI, Alola_Melemele_SamsonOakVilla_Dialogue_159
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_156:
	goto_if_set FLAG_CAUGHT_ALL_ULAULA, Alola_Melemele_SamsonOakVilla_Dialogue_155
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154

Alola_Melemele_SamsonOakVilla_Dialogue_159:
	goto_if_set FLAG_CAUGHT_ALL_MELEMELE, Alola_Melemele_SamsonOakVilla_Dialogue_153
	goto Alola_Melemele_SamsonOakVilla_Dialogue_154


Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_0:
	emote_exclamation_mark
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_1:
	walk_down
	walk_left
	face_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_2:
	walk_in_place_down
	walk_in_place_down
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Movement_3:
	walk_right
	walk_up
	face_right
	step_end

Alola_Melemele_SamsonOakVilla_Dialogue_Movement_0:
	emote_exclamation_mark
	step_end

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_0:
	.string "Alola, {PLAYER}!$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_1:
	.string "Je suis ravi que tu sois là!\n"
	.string "Bienvenue dans ma villa!\p"
	.string "Je séjourne ici pour étudier les\n"
	.string "similitudes entre les ÎLES\p"
	.string "D'ALOLA et la région d'ALOLA.\p"
	.string "Je m'intéresse tout\n"
	.string "particulièrement au phénomène\p"
	.string "des formes régionales.$"

Alola_Melemele_SamsonOakVillaIntro_Trigger_Text_2:
	.string "Tu as l'air très compétent.\p"
	.string "Tu serais parfait pour m'aider à\n"
	.string "étudier les ÎLES D'ALOLA!\p"
	.string "Explore tout ce que les ÎLES ont\n"
	.string "à offrir. Si tu trouves des\p"
	.string "POKéMON familiers qui\n"
	.string "ressemblent à ceux de KANTO,\p"
	.string "reviens me montrer ton POKéDEX!\p"
	.string "J'attendrai patiemment de\n"
	.string "connaître tes progrès!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_0:
	.string "Waouh! Tu as vu les divinités\n"
	.string "gardiennes!\p"
	.string "Travail remarquable, {PLAYER}.\p"
	.string "J'ai trouvé ceci en me\n"
	.string "promenant.\p"
	.string "Je ne sais pas exactement à quoi\n"
	.string "cela sert, mais tu devrais le\p"
	.string "prendre.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_1:
	.string "Les ÎLES D'ALOLA doivent\n"
	.string "vraiment être particulières pour\p"
	.string "que les divinités en personne\n"
	.string "s'y soient rendues!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_2:
	.string "Merci de m'avoir aidé dans mes\n"
	.string "recherches, {PLAYER}!\p"
	.string "Grâce à toi, notre connaissance\n"
	.string "des ÎLES D'ALOLA a\p"
	.string "considérablement progressé!\p"
	.string "J'espère que tu continueras à\n"
	.string "explorer les ÎLES pour découvrir\p"
	.string "tous les secrets qu'elles\n"
	.string "recèlent!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_3:
	.string "Alola, {PLAYER}!\p"
	.string "Alors, tu as vaincu tous les\n"
	.string "POKéMON Dominants des ÎLES?\p"
	.string "Quel exploit remarquable!\p"
	.string "Cela fait assez longtemps...\p"
	.string "Je crois qu'il est temps que\n"
	.string "nous nous affrontions, pas toi?$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_4:
	.string "Parfait! Je ne te ferai aucun\n"
	.string "cadeau!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_5:
	.string "Incroyable, {PLAYER}!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_6:
	.string "Waouh, {PLAYER}! Tu es vraiment\n"
	.string "un Dresseur redoutable!\p"
	.string "Tu as prouvé que tu méritais de\n"
	.string "connaître un secret que je garde\p"
	.string "sur ces ÎLES...\p"
	.string "Je ne suis pas le seul à avoir\n"
	.string "remarqué leur ressemblance\p"
	.string "frappante avec la région\n"
	.string "d'ALOLA...\p"
	.string "Il semblerait que les divinités\n"
	.string "gardiennes elles-mêmes visitent\p"
	.string "les ÎLES.\p"
	.string "Si tu les vois survoler les\n"
	.string "ÎLES, rends-toi aux totems...\p"
	.string "Elles t'y attendent peut-être!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_7:
	.string "Qu'attends-tu, {PLAYER}? Pars\n"
	.string "explorer les environs!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_8:
	.string "Pas de souci, {PLAYER}!\p"
	.string "Prends le temps de te préparer\n"
	.string "au combat et reviens quand tu\p"
	.string "seras prêt!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_9:
	.string "Alola, {PLAYER}!\p"
	.string "Tu as donc trouvé toutes les\n"
	.string "formes d'Alola des ÎLES. Mais\p"
	.string "as-tu vaincu tous les POKéMON\n"
	.string "Dominants?\p"
	.string "Cherche un étrange pilier sur\n"
	.string "chaque île. Le POKéMON Dominant\p"
	.string "le gardera!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_10:
	.string "Te revoilà, {PLAYER}!\p"
	.string "Comment avancent tes recherches\n"
	.string "sur les ÎLES D'ALOLA?\p"
	.string "Veux-tu me faire part de tes\n"
	.string "progrès sur une île en\p"
	.string "particulier?$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_11:
	.string "ÎLE DE MELE-MELE$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_12:
	.string "ÎLE D'AKALA$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_13:
	.string "ÎLE D'ULA-ULA$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_14:
	.string "ÎLE DE PONI$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_15:
	.string "Pas maintenant.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_16:
	.string "Laisse-moi examiner ton\n"
	.string "POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_17:
	.string "Waouh, {PLAYER}!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_18:
	.string "Tu as trouvé toutes les formes\n"
	.string "d'Alola vivant sur l'ÎLE DE\p"
	.string "MELE-MELE!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_19:
	.string "Et on dirait que tu as aussi\n"
	.string "trouvé toutes les formes d'Alola\p"
	.string "des autres ÎLES!\p"
	.string "C'est incroyable, {PLAYER}! Tu\n"
	.string "peux être fier de toi!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_20:
	.string "Grâce à toi, j'ai pu confirmer\n"
	.string "que toutes les formes d'Alola\p"
	.string "sont présentes sur les ÎLES\n"
	.string "D'ALOLA!\p"
	.string "J'aimerais te demander une\n"
	.string "dernière chose...\p"
	.string "Pourrais-tu enquêter sur les\n"
	.string "POKéMON Dominants qui, à ce\p"
	.string "qu'on raconte, gardent les\n"
	.string "totems de chaque ÎLE?\p"
	.string "Mais sois prudent! Ils seraient\n"
	.string "bien plus puissants que leurs\p"
	.string "congénères ordinaires...\p"
	.string "On ne sait jamais qui pourrait\n"
	.string "t'observer pour juger si tu es\p"
	.string "un adversaire digne de ce nom!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_21:
	.string "Continue d'explorer les autres\n"
	.string "ÎLES et viens me faire part de\p"
	.string "tes progrès!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_22:
	.string "On dirait que tu as déjà trouvé\n"
	.string "toutes les formes d'Alola de\p"
	.string "l'ÎLE DE MELE-MELE!\p"
	.string "Bravo!\p"
	.string "Continue d'explorer les autres\n"
	.string "ÎLES et viens me faire part de\p"
	.string "tes progrès!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_23:
	.string "Laisse-moi examiner ton\n"
	.string "POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Il semble que tu n'aies pas\n"
	.string "encore trouvé toutes les formes\p"
	.string "d'Alola de l'ÎLE DE MELE-MELE.\p"
	.string "J'ai entendu dire qu'il y en\n"
	.string "avait\p"
	.string "{COLOR RED}4{COLOR DARK_GRAY} à\n"
	.string "trouver...\p"
	.string "{COLOR RED}RATTATA{COLOR DARK_GRAY},\n"
	.string "{COLOR RED}RATATAC{COLOR DARK_GRAY},\p"
	.string "{COLOR RED}MIAOUSS{COLOR DARK_GRAY}\n"
	.string "et\p"
	.string "{COLOR RED}PERSIAN{COLOR DARK_GRAY}.\p"
	.string "Poursuis tes recherches et\n"
	.string "reviens quand tu les auras tous\p"
	.string "attrapés!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_24:
	.string "Tu as trouvé toutes les formes\n"
	.string "d'Alola vivant sur l'ÎLE\p"
	.string "D'AKALA!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_25:
	.string "Maintenant que tu m'as aidé à\n"
	.string "confirmer la présence de toutes\p"
	.string "les formes d'Alola sur les ÎLES\n"
	.string "D'ALOLA, j'aimerais te demander\p"
	.string "une dernière chose...\p"
	.string "Pourrais-tu enquêter sur les\n"
	.string "POKéMON Dominants qui, à ce\p"
	.string "qu'on raconte, gardent les\n"
	.string "totems de chaque île?\p"
	.string "Mais sois prudent! Ils seraient\n"
	.string "bien plus puissants que leurs\p"
	.string "congénères ordinaires...\p"
	.string "On ne sait jamais qui pourrait\n"
	.string "t'observer pour juger si tu es\p"
	.string "un adversaire digne de ce nom!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_26:
	.string "On dirait que tu as déjà trouvé\n"
	.string "toutes les formes d'Alola de\p"
	.string "l'ÎLE D'AKALA!\p"
	.string "Bravo!\p"
	.string "Continue d'explorer les autres\n"
	.string "ÎLES et viens me faire part de\p"
	.string "tes progrès!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_27:
	.string "Laisse-moi examiner ton\n"
	.string "POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Il semble que tu n'aies pas\n"
	.string "encore trouvé toutes les formes\p"
	.string "d'Alola de l'ÎLE D'AKALA.\p"
	.string "J'ai entendu dire qu'il y en\n"
	.string "avait\p"
	.string "{COLOR RED}4{COLOR DARK_GRAY} à\n"
	.string "trouver...\p"
	.string "{COLOR RED}RAICHU{COLOR DARK_GRAY},\n"
	.string "{COLOR RED}OSSATUEUR{COLOR DARK_GRAY},\p"
	.string "{COLOR RED}TAUPIQUEUR{COLOR DARK_GRAY}\n"
	.string "et\p"
	.string "{COLOR RED}TRIOPIKEUR{COLOR DARK_GRAY}.\p"
	.string "Poursuis tes recherches et\n"
	.string "reviens quand tu les auras tous\p"
	.string "attrapés!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_28:
	.string "Tu as trouvé toutes les formes\n"
	.string "d'Alola vivant sur l'ÎLE\p"
	.string "D'ULA-ULA!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_29:
	.string "On dirait que tu as déjà trouvé\n"
	.string "toutes les formes d'Alola de\p"
	.string "l'ÎLE D'ULA-ULA!\p"
	.string "Bravo!\p"
	.string "Continue d'explorer les autres\n"
	.string "ÎLES et viens me faire part de\p"
	.string "tes progrès!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_30:
	.string "Laisse-moi examiner ton\n"
	.string "POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Il semble que tu n'aies pas\n"
	.string "encore trouvé toutes les formes\p"
	.string "d'Alola de l'ÎLE D'ULA-ULA.\p"
	.string "J'ai entendu dire qu'il y en\n"
	.string "avait\p"
	.string "{COLOR RED}6{COLOR DARK_GRAY} à\n"
	.string "trouver...\p"
	.string "{COLOR RED}GOUPIX{COLOR DARK_GRAY},\n"
	.string "{COLOR RED}FEUNARD{COLOR DARK_GRAY},\p"
	.string "{COLOR RED}SABELETTE{COLOR DARK_GRAY},\n"
	.string "{COLOR RED}SABLAIREAU{COLOR DARK_GRAY},\p"
	.string "{COLOR RED}TADMORV{COLOR DARK_GRAY}\n"
	.string "et\p"
	.string "{COLOR RED}GROTADMORV{COLOR DARK_GRAY}.\p"
	.string "Poursuis tes recherches et\n"
	.string "reviens quand tu les auras tous\p"
	.string "attrapés!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_31:
	.string "Tu as trouvé toutes les formes\n"
	.string "d'Alola vivant sur l'ÎLE DE\p"
	.string "PONI!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_32:
	.string "On dirait que tu as déjà trouvé\n"
	.string "toutes les formes d'Alola de\p"
	.string "l'ÎLE DE PONI!\p"
	.string "Bravo!\p"
	.string "Continue d'explorer les autres\n"
	.string "ÎLES et viens me faire part de\p"
	.string "tes progrès!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_33:
	.string "Laisse-moi examiner ton\n"
	.string "POKéDEX{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\p"
	.string "Il semble que tu n'aies pas\n"
	.string "encore trouvé toutes les formes\p"
	.string "d'Alola de l'ÎLE DE PONI.\p"
	.string "J'ai entendu dire qu'il y en\n"
	.string "avait\p"
	.string "{COLOR RED}4{COLOR DARK_GRAY} à\n"
	.string "trouver...\p"
	.string "{COLOR RED}RACAILLOU{COLOR DARK_GRAY},\n"
	.string "{COLOR RED}GRAVALANCH{COLOR DARK_GRAY},\p"
	.string "{COLOR RED}GROLEM{COLOR DARK_GRAY}\n"
	.string "et\p"
	.string "{COLOR RED}NOADKOKO{COLOR DARK_GRAY}.\p"
	.string "Poursuis tes recherches et\n"
	.string "reviens quand tu les auras tous\p"
	.string "attrapés!$"

Alola_Melemele_SamsonOakVilla_Dialogue_Text_34:
	.string "Pas de souci, {PLAYER}!\p"
	.string "Reviens quand tu voudras me\n"
	.string "faire part de tes découvertes\p"
	.string "sur les ÎLES D'ALOLA!$"
