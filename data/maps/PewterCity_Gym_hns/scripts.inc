PewterCity_Gym_hns_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_HNS, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK_HNS, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_SLIDE
	msgbox PewterCity_Gym_Text_Brock_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers_hns
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	goto_if_unset FLAG_HIDE_DOJO_BROCK, PewterCity_Gym_EventScript_Brock_Trade
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "Pierre: C’est pas tous les jours\n"
	.string "que l’on reçoit de la visite de\p"
	.string "quelqu’un de Johto!\p"
	.string "Moi c’est Pierre! Je suis le\n"
	.string "Champion de l’Arène d’Argenta!\p"
	.string "Je suis un expert\n"
	.string "en Pokémon Roche.\p"
	.string "Ils endurent très\n"
	.string "bien les attaques\p"
	.string "les plus communes.\p"
	.string "C’est des chatouilles, pour eux!\n"
	.string "C’est parti!$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "PIERRE: Tes Pokémon ont pu\n"
	.string "passer ma défense de pierre...\p"
	.string "Tu es plus balèze que je ne le\n"
	.string "pensais...\p"
	.string "Tiens... Prends ce BADGE.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} reçoit le BADGE ROCHE.$"

PewterCity_Gym_Text_Brock_GiveTM:
	.string "Tiens, emporte cette CT.$"

PewterCity_Gym_Text_Brock_ExplainTM:
	.string "Elle contient ÉBOULEMENT.\p"
	.string "Elle fait tomber des rochers sur\n"
	.string "l'adversaire et peut l'apeurer.\p"
	.string "Elle stoppera net son élan.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "PIERRE: {PLAYER}, merci. J'ai\n"
	.string "aimé\p"
	.string "me battre contre toi, même si je\n"
	.string "l'ai mauvaise.\p"
	.string "Ce BADGE ROCHE renforcera tes\n"
	.string "Pokémon.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "PIERRE: Grand est le monde.\n"
	.string "Beaucoup\p"
	.string "de dresseurs tu rencontreras. Oh\n"
	.string "que oui.\p"
	.string "Tu verras... Je vais devenir\n"
	.string "super balèze.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "Les dresseurs\n"
	.string "de cette ARENE\p"
	.string "utilisent des Pokémon\n"
	.string "du type ROCHE.\p"
	.string "Cet élément a une grande\n"
	.string "DEFENSE.\p"
	.string "Les combats risquent de durer\n"
	.string "super longtemps.$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Je n’ai pas pu gagner...$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "Hé toi! Dresseur de JOHTO!\n"
	.string "PIERRE\p"
	.string "est super fort! Il va te punir\n"
	.string "la tête!$"

PewterCity_Gym_Text_Guide:
	.string "Hé! Graine de star! Tu\p"
	.string "affrontes les CHAMPIONS de\n"
	.string "KANTO, non?\p"
	.string "Ils sont tout aussi forts et\p"
	.string "déterminés que ceux de JOHTO.$"

PewterCity_Gym_Text_Guide_Win:
	.string "Hé! Graine de star! Cette\p"
	.string "ARENE ne t'a pas posé trop de\n"
	.string "problèmes...\p"
	.string "Tu m'as bluffé. Sérieusement.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
	.string "ARÈNE POKéMON D'ARGENTA\n"
	.string "CHAMPION: PIERRE\p"
	.string "DRESSEURS VAINQUEURS:\n"
	.string "BLUE, RED$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "ARÈNE POKéMON D'ARGENTA\n"
	.string "CHAMPION: PIERRE\p"
	.string "DRESSEURS VAINQUEURS:\n"
	.string "BLUE, RED, {PLAYER}$"

PewterCity_Gym_EventScript_Brock_Trade::
	goto_if_set FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED, PewterCity_Gym_EventScript_BrockTradeCompleted
	ingame_trade INGAME_TRADE_BONSLY, PewterCity_Gym_Text_BrockWantToTrade, PewterCity_Gym_EventScript_BrockDeclineTrade, PewterCity_Gym_EventScript_BrockNotRequestedMon, PewterCity_Gym_Text_BrockTakeCare
	setflag FLAG_PEWTER_GYM_NPC_TRADE_COMPLETED
	release
	end

PewterCity_Gym_EventScript_BrockDeclineTrade::
	msgbox PewterCity_Gym_Text_BrockDeclineTrade, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockNotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PewterCity_Gym_Text_BrockNotRequestedMon, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockTradeCompleted::
	msgbox PewterCity_Gym_Text_BrockTradeCompleted, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_BrockWantToTrade:
	.string "PIERRE: Hé, {PLAYER}!\n"
	.string "J'ai trouvé ce petit MANZAI en\l"
	.string "m'entraînant\l"
	.string "dans les montagnes.\p"
	.string "Il est mignon, mais je crois\n"
	.string "qu'il lui faut un Dresseur\l"
	.string "d'un autre genre.\p"
	.string "Veux-tu échanger un {STR_VAR_1}\n"
	.string "contre mon {STR_VAR_2}?$"

PewterCity_Gym_Text_BrockTakeCare:
	.string "PIERRE: Merci! Prends bien soin\n"
	.string "de WOODY pour moi!$"

PewterCity_Gym_Text_BrockDeclineTrade:
	.string "PIERRE: Non? Ce n'est pas grave.\n"
	.string "WOODY et moi continuerons à nous\l"
	.string "entraîner.$"

PewterCity_Gym_Text_BrockNotRequestedMon:
	.string "PIERRE: Ce Pokémon n'est pas\n"
	.string "un {STR_VAR_1}.\p"
	.string "Ce n'est pas ce que je cherche.$"

PewterCity_Gym_Text_BrockTradeCompleted:
	.string "PIERRE: Comment va WOODY?\n"
	.string "Les MANZAI sont plus robustes\l"
	.string "qu'ils en ont l'air!$"
