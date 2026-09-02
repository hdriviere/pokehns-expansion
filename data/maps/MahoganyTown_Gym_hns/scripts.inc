MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "Arène d’Acajou$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON D'ACAJOU\p"
	.string "CHAMPION: FREDO\p"
	.string "DRESSEURS VAINQUEURS: {PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
    .string "Les Pokémon ont\n"
    .string "beaucoup d'aventures\p"
    .string "au cours de leur\n"
    .string "vie, comme nous.\p"
    .string "Moi aussi, j'ai beaucoup\n"
    .string "souffert dans ma vie.\p"
    .string "Comme je suis plus vieux que\n"
    .string "toi, laisse-moi t'expliquer...\p"
    .string "Je suis avec les Pokémon depuis\p"
    .string "bien avant ta naissance.\p"
    .string "Je ne perds pas facilement.\p"
    .string "Moi, FREDO, le dresseur du\n"
    .string "froid,\p"
    .string "je vais te montrer ma puissance!$"

MahoganyTown_Gym_Text_PryceImpressed:
    .string "Ah, je suis très impressionné\n"
    .string "par ta prouesse.\p"
    .string "Avec un tempérament comme le\p"
    .string "tien, tu surmonteras tous les\n"
    .string "obstacles de la vie.\p"
    .string "Tu mérites ce BADGE!$"

MahoganyTown_Gym_Text_ReceivedBadge:
    .string "{PLAYER} reçoit le BADGEGLACIER.$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
    .string "Ce BADGE permet à tes Pokémon de\n"
    .string "développer leur SPECIAL.\p"
    .string "Il permet aussi à tes\n"
    .string "Pokémon d'utiliser\p"
    .string "SIPHON pour passer\n"
    .string "les tourbillons.\p"
    .string "Et ça... C'est un cadeau de ma\n"
    .string "part!$"

MahoganyTown_Gym_Text_HailSpeech:
	.string "Cette CT contient GRÊLE.\p"
	.string "Elle inflige des dégâts à chaque\n"
	.string "tour pendant 5 tours.\p"
	.string "Elle démontre la rigueur\n"
	.string "de l'hiver.$"

MahoganyTown_Gym_Text_CherishPokemon:
    .string "Lorsque la glace et la neige\n"
    .string "fondent, le printemps arrive.\p"
    .string "Toi et tes Pokémon serez\n"
    .string "ensemble pendant des années.\p"
    .string "Profitez bien de ces instants!$"

MahoganyTown_Gym_Text_PryceRematch:
	.string "Ah, Maître de JOHTO!\p"
	.string "Tes talents sont remarquables.\n"
	.string "Je suis impressionné.\p"
	.string "Mais nous avons encore beaucoup\n"
	.string "à apprendre l'un de l'autre.\p"
	.string "Moi, FREDO, Dresseur de l'hiver,\n"
	.string "j'ai encore quelques tours\l"
	.string "en réserve.\p"
	.string "Veux-tu prendre ta revanche?$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
	.string "Ah, une fois encore, ta maîtrise\n"
	.string "m'impressionne.\p"
	.string "Avec ta volonté, tu surmonteras\n"
	.string "tous les obstacles de la vie.$"

MahoganyTown_Gym_Text_Guide:
	.string "FREDO est un vétéran.\p"
	.string "Il entraîne des Pokémon depuis\n"
	.string "près de 50 ans.\p"
	.string "Son équipe solide peut répondre\n"
	.string "à tout ce que tu lui opposeras.\p"
	.string "Le type FEU est un bon début,\n"
	.string "mais attention à la pluie!$"

MahoganyTown_Gym_Text_GuideWin:
    .string "FREDO, c'est quelqu'un, mais toi\n"
    .string "t'es pas naze non plus!\p"
    .string "C'était un combat chaud qui a\n"
    .string "soudé\p"
    .string "l'écart entre deux générations!$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
    .string "Je vais geler tes Pokémon et tu\n"
    .string "ne pourras plus rien faire!$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
    .string "Saperlipopette! Je n'ai rien pu\n"
    .string "faire.$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
    .string "Je crois qu'il existe\n"
    .string "une capacité que les\p"
    .string "Pokémon peuvent utiliser\n"
    .string "même en étant gelés.$"

MahoganyTown_Gym_Text_BoarderBradSeen:
    .string "Cette Arène a le sol glissant.\n"
    .string "C’est délire, pas vrai?\p"
    .string "Mais... Fini de jouer!$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
    .string "Tu vois à quel point on est\n"
    .string "sérieux ici?$"

MahoganyTown_Gym_Text_BoarderBradAfter:
    .string "Cette ARENE est superbe. J'adore\n"
    .string "surfer avec mes Pokémon!$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
    .string "Je connais le secret de la\n"
    .string "puissance de Frédo.$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
    .string "OK. Je vais te le dire.$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
    .string "Le secret de la force de\n"
    .string "FREDO...\p"
    .string "Il médite derrière une\p"
    .string "cascade tous les jours\n"
    .string "pour accroître sa\p"
    .string "force et développer\n"
    .string "son esprit.$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
    .string "Pour atteindre\n"
    .string "Frédo, notre Champion\p"
    .string "d’Arène, tu dois\n"
    .string "réfléchir avant\p"
    .string "de te laisser glisser!$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
    .string "Enfin, moi j'te bats en ski!$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
    .string "Si tu ne patines pas\n"
    .string "avec précision, tu\p"
    .string "n’iras pas bien loin\n"
    .string "dans cette Arène.\p"
    .string "Mais c’est aussi ce qui fait son\n"
    .string "charme.$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
    .string "Sors de mon slalom!$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
    .string "Non! Tu m'as fait déraper!$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
    .string "Je n’aurais pas dû frimer...$"
