CeladonCity_Gym_hns_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA_HNS, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_Erika_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	msgbox CeladonCity_Gym_Text_Erika_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA: Bonjour... Belle journée,\n"
	.string "non?\p"
	.string "C'est beau la vie.\p"
	.string "Moi je suis ERIKA, CHAMPIONNE de\n"
	.string "l'ARENE de CELADOPOLE.\p"
	.string "...Oh? Tu viens de JOHTO? C'est\n"
	.string "bien...\p"
	.string "...Quoi? Tu veux te battre? Mais\n"
	.string "il faut le dire!!!\p"
	.string "J'vais te casser ta face!!!$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA: Oh! J'ai perdu...\p"
	.string "Toi t'es un p'tit tigre...\p"
	.string "Voilà pour toi: le BADGE\n"
	.string "PRISME...$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} reçoit le BADGE PRISME.$"

CeladonCity_Gym_Text_Erika_GiveTM:
	.string "ERIKA: Ce combat fut délicieux.\p"
	.string "Il m'a inspirée. Je t'en prie,\n"
	.string "accepte cette CT.$"

CeladonCity_Gym_Text_Erika_ExplainTM:
	.string "Elle contient GIGA-SANGSUE.\p"
	.string "Cette belle capacité draine la\n"
	.string "moitié des dégâts et soigne\l"
	.string "soigner ton Pokémon.\p"
	.string "Utilise-la si elle te plaît…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "Erika: C’est toujours un peu\n"
	.string "triste de perdre un combat...\p"
	.string "Mais c’est aussi stimulant de\n"
	.string "rencontrer un adversaire\p"
	.string "vraiment puissant.$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA: Oh, bonjour.\p"
	.string "Quelle surprise, MAÎTRE de\n"
	.string "KANTO!\p"
	.string "Quel plaisir de te revoir.\p"
	.string "Ton voyage a dû être palpitant.\p"
	.string "Même les Maîtres aiment un défi.\p"
	.string "Veux-tu m'affronter de nouveau?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA: Perdre fait toujours un\n"
	.string "peu mal mais...\p"
	.string "Combattre un bon adversaire est\n"
	.string "stimulant...$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE_HNS, CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "Ça t’étonne, une Arène remplie\n"
	.string "de filles?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "Ouiiiiin!$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "Je ne faisais pas attention!$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA_HNS, CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "Un combat? Heu...non. ... Allez,\n"
	.string "d'accord!$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "C'est fini?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "T'en as plein des BADGES.\n"
	.string "Comment\p"
	.string "je pouvais gagner, moi?!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_HNS, CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "Tu regardes les fleurs ou c'est\n"
	.string "moi que tu mates?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "C'est pas bien!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "Comment devenir une belle fille\n"
	.string "comme ERIKA?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE_HNS, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "ERIKA nous a appris plein de\n"
	.string "trucs!$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Oh... On a perdu.$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "ERIKA! Venge-nous!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "On doit protéger la grande\n"
	.string "ERIKA!$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "Nooooonn....$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "ERIKA est bien plus forte!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CÉLADOPOLE\n"
    .string "CHAMPIONNE: ERIKA\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CÉLADOPOLE\n"
    .string "CHAMPIONNE: ERIKA\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED,\n"
    .string "{PLAYER}$"
