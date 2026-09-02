BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Ça fait 70 ans que j’élève des\n"
	.string "POKéMON! On m’appelle l’ELEVEUR\p"
	.string "DE POKéMON légendaire!\p"
	.string "Quand tu auras pris autant de\n"
	.string "bouteille que moi, tu\p"
	.string "reconnaîtras les capacités d’un\n"
	.string "POKéMON au premier regard.\p"
	.string "Tu es un DRESSEUR. Tu veux\n"
	.string "connaître les capacités de tes\p"
	.string "POKéMON?\p"
	.string "Allez! Je vais jeter un œil à\n"
	.string "tes POKéMON!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "Hum…\p"
	.string "Celui-là, je dirais que ses\n"
	.string "capacités sont dans la moyenne.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "Hum…\p"
	.string "Celui-là, je dirais que ses\n"
	.string "capacités sont au-dessus de la\p"
	.string "moyenne.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "Hum…\p"
	.string "Celui-là, je dirais que ses\n"
	.string "capacités sont plutôt\p"
	.string "impressionnantes!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "Hum…\p"
	.string "Celui-là, je dirais que ses\n"
	.string "capacités sont vraiment\p"
	.string "excellentes!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Son point fort, ce sont ses PV…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "Son point fort, c’est son\n"
	.string "ATTAQUE…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "Son point fort, c’est sa\n"
	.string "DEFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Son point fort, c’est son\n"
	.string "ATTAQUE SPECIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Son point fort, c’est sa DEFENSE\n"
	.string "SPECIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "Son point fort, c’est sa\n"
	.string "VITESSE…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Cette stat est relativement\n"
	.string "bonne. Hum… Oui, oui.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Cette stat est assez\n"
	.string "impressionnante. Hum… Oui, oui.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Cette stat est excellente! Hum…\n"
	.string "Oui, oui.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "Cette stat est parfaite! Hum…\n"
	.string "Oui, oui.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Comment? Tu n’as pas le temps?\p"
	.string "Tu ne devrais jamais refuser\n"
	.string "l’aide de tes aînés!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Oui, qu'y a-t-il encore?\p"
	.string "J'ai des affaires à régler!\n"
	.string "Gardez ça pour la prochaine\p"
	.string "fois!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Dis, mon petit! Tu aimerais en\n"
	.string "savoir plus sur les capacités de\p"
	.string "tes POKéMON?\p"
	.string "Bien, bien! Jetons un œil à ces\n"
	.string "POKéMON!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Comment pourrais-je évaluer un\n"
	.string "POKéMON qui n’a pas encore\p"
	.string "éclos!\p"
	.string "Montre-moi un POKéMON! C’est un\n"
	.string "POKéMON que je veux voir!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Il a dit que mon POKéMON est\n"
	.string "excellent! Je m’en suis bien\p"
	.string "occupé!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Mon POKéMON est excellent, il a\n"
	.string "dit! Je n’ai rien fait de\p"
	.string "spécial, pourtant…$"

