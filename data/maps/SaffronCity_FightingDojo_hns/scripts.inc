SaffronCity_FightingDojo_hns_MapScripts::
	.byte 0

SaffronCity_FightingDojo_EventScript_StatueLeft::
	msgbox SaffronCity_FightingDojo_Text_Sign1, MSGBOX_SIGN
	end
SaffronCity_FightingDojo_EventScript_StatueRight::
	msgbox SaffronCity_FightingDojo_Text_Sign2, MSGBOX_SIGN
	end

SaffronCity_FightingDojo_EventScript_BlackBelt::
	msgbox SaffronCity_FightingDojo_Text_BlackBelt, MSGBOX_NPC
	end

SaffronCity_FightingDojo_EventScript_Cooltrainer::
	msgbox SaffronCity_FightingDojo_Text_Cooltrainer, MSGBOX_NPC
	end

SaffronCity_FightingDojo_EventScript_Refused::
	closemessage
	release
	end

SaffronCity_FightingDojo_EventScript_Lickilicky_EV_HP::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LICKILICKY, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Lickilicky, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_1, SaffronCity_FightingDojo_EventScript_BattleLickilicky_EV_HP
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_LICKILICKY
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_HP
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleLickilicky_EV_HP::
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_LICKILICKY, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_1
	release
	end
	
SaffronCity_FightingDojo_Text_Lickilicky:
	.string "COUDLANGUE: Laaaangue!$"

SaffronCity_FightingDojo_EventScript_Machamp_EV_Attack::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Machamp, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_2, SaffronCity_FightingDojo_EventScript_BattleMachamp_EV_Attack
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_MACHAMP
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Attack
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleMachamp_EV_Attack::
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_MACHAMP, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_2
	release
	end

SaffronCity_FightingDojo_Text_Machamp:
	.string "MACKOGNEUR: Kogneur!$"

SaffronCity_FightingDojo_EventScript_Steelix_EV_Defense::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Steelix, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_3, SaffronCity_FightingDojo_EventScript_BattleSteelix_EV_Defense
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_STEELIX
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Defense
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleSteelix_EV_Defense::
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_STEELIX, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_3
	release
	end

SaffronCity_FightingDojo_Text_Steelix:
	.string "STEELIX: GRRRIND!$"

SaffronCity_FightingDojo_EventScript_Alakazam_EV_SpecialAttack::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ALAKAZAM, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Alakazam, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_4, SaffronCity_FightingDojo_EventScript_BattleAlakazam_EV_SpecialAttack
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_ALAKAZAM
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_SpecialAttack
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleAlakazam_EV_SpecialAttack::
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_ALAKAZAM, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_4
	release
	end

SaffronCity_FightingDojo_Text_Alakazam:
	.string "ALAKAZAM: ZAM!$"

SaffronCity_FightingDojo_EventScript_Slowking_EV_SpecialDefense::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWKING, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Slowking, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_5, SaffronCity_FightingDojo_EventScript_BattleSlowking_EV_SpecialDefense
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_SLOWKING
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_SpecialDefense
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattleSlowking_EV_SpecialDefense::
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_SLOWKING, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_5
	release
	end

SaffronCity_FightingDojo_Text_Slowking:
	.string "ROIGADA: Hmm...$"

SaffronCity_FightingDojo_EventScript_Pidgeot_EV_Speed::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojo_Text_Pidgeot, MSGBOX_DEFAULT
	delay 20
	closemessage
	goto_if_set FLAG_TEMP_6, SaffronCity_FightingDojo_EventScript_BattlePidgeot_EV_Speed
	delay 30
	bufferspeciesname STR_VAR_1, SPECIES_PIDGEOT
	bufferstring STR_VAR_2, SaffronCity_FightingDojo_Text_Speed
	msgbox SaffronCity_FightingDojo_Text_WouldYouLikeToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojo_EventScript_Refused
SaffronCity_FightingDojo_EventScript_BattlePidgeot_EV_Speed::
	setflag FLAG_NO_WILD_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_PIDGEOT, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_NO_WILD_CATCHING
	clearflag FLAG_NO_SHINY
	setflag FLAG_TEMP_6
	release
	end

SaffronCity_FightingDojo_Text_Pidgeot:
	.string "ROUCARNAGE: Roooou!$"

SaffronCity_FightingDojo_Text_HP:
	.string "PV$"
SaffronCity_FightingDojo_Text_Attack:
	.string "ATQ$"
SaffronCity_FightingDojo_Text_Defense:
	.string "DÉF$"
SaffronCity_FightingDojo_Text_SpecialAttack:
	.string "ATQ.SPÉ$"
SaffronCity_FightingDojo_Text_SpecialDefense:
	.string "DÉF.SPÉ$"
SaffronCity_FightingDojo_Text_Speed:
	.string "VIT$"

SaffronCity_FightingDojo_Text_WouldYouLikeToBattle:
	.string "Affronter {STR_VAR_1}\n"
	.string "pour gagner 3 EV en {STR_VAR_2}?$"

SaffronCity_FightingDojo_Text_BlackBelt:
	.string "Bienvenue au DOJO DE COMBAT!\p"
	.string "Ici, tu peux améliorer les stats\n"
	.string "de tes Pokémon en combattant!$"

SaffronCity_FightingDojo_Text_Sign1:
	.string "GAUCHE: PV, DÉFENSE,\n"
	.string "DÉF. SPÉCIALE$"

SaffronCity_FightingDojo_Text_Sign2:
	.string "DROITE: ATTAQUE, ATQ. SPÉCIALE,\n"
	.string "VITESSE$"

SaffronCity_FightingDojo_Text_Cooltrainer::
	.string "Seuls les Dresseurs ayant tous\n"
	.string "les Badges de KANTO peuvent\l"
	.string "entrer dans le salon VIP.$"

@Ability swapper

SaffronCity_FightingDojo_Ability_Man::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojo_Ability_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_FightingDojo_Ability_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_FightingDojo_Ability_No
	end

SaffronCity_FightingDojo_Ability_No:
	msgbox SaffronCity_FightingDojo_Ability_Text_No, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_SetZeroNoMoney::
	msgbox SaffronCity_FightingDojo_SetZeroTextNoMoney, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_Ability_CheckMoney:
	checkmoney 25000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq SaffronCity_FightingDojo_Ability_Continue
	compare VAR_RESULT, FALSE
	goto_if_eq SaffronCity_FightingDojo_SetZeroNoMoney
	end

SaffronCity_FightingDojo_Ability_Continue:
	closemessage
	special ChoosePartyMon
	waitstate
	@special SwitchMonAbility
	@compare VAR_RESULT, TRUE
	goto_if_eq SaffronCity_FightingDojo_Ability_Finish
	compare VAR_RESULT, FALSE
	goto_if_eq SaffronCity_FightingDojo_Ability_Cant
	end

SaffronCity_FightingDojo_Ability_Cant:
	msgbox SaffronCity_FightingDojo_Ability_Text_Cant, MSGBOX_DEFAULT
	waitmessage
	release
	end

SaffronCity_FightingDojo_Ability_Finish:
	fadescreen 0x1
	delay 100
	fadescreen 0x0
	faceplayer
	waitse
	playse SE_EXP_MAX
	msgbox SaffronCity_FightingDojo_Ability_Finish_Text, MSGBOX_DEFAULT
	removemoney 25000, 0
	closemessage
	release
	end

SaffronCity_FightingDojo_Ability_Finish_Text:
	.string "Et voilà! Tout le plaisir\n"
	.string "est pour moi!$"

SaffronCity_FightingDojo_Ability_Text1:
	.string "Bienvenue! Je suis l'EXPERT\n"
	.string "des TALENTS!\p"
	.string "Je peux changer le talent d'un\n"
	.string "Pokémon en un instant, pour\l"
	.string "seulement 25 000¥!\p"
	.string "Voulez-vous changer le talent\n"
	.string "d'un Pokémon?$"

SaffronCity_FightingDojo_Ability_Text_No:
	.string "Entendu. Je serai ici si vous\n"
	.string "avez besoin de moi.$"

SaffronCity_FightingDojo_Ability_Text_Cant:
	.string "C'est impossible. Ce Pokémon\n"
	.string "n'a pas de second talent!$"

SaffronCity_FightingDojo_Ability_Text_NoChampion:
	.string "Bienvenue! Je suis l'EXPERT\n"
	.string "des TALENTS!\p"
	.string "Je peux changer le talent d'un\n"
	.string "Pokémon en un instant.\p"
	.string "Malheureusement, j'ai mal au dos\n"
	.string "et je ne peux pas travailler\l"
	.string "aujourd'hui.\p"
	.string "Revenez plus tard!$"

SaffronCity_FightingDojo_SetZeroTextNoMoney:
	.string "Vous n'avez pas assez d'argent.\p"
	.string "Revenez quand vous en aurez.$"
