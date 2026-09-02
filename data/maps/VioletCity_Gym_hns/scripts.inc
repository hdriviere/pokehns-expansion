VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "Je suis ALBERT, le CHAMPION\n"
	.string "d'ARENE de MAUVILLE!\p"
	.string "On dit qu'avec une bonne\n"
	.string "décharge\p"
	.string "électrique, les Pokémon volants\n"
	.string "grillent...\p"
	.string "Je n'autorise personne à\n"
	.string "insulter les Pokémon!\p"
	.string "Tu vas subir les terribles\n"
	.string "attaques\p"
	.string "de mes Pokémon volants!$"

VioletGym_Text_Falkner_WinLoss:
	.string "...Zut de flûte! Les Pokémon\n"
	.string "adorés de mon papa...\p"
	.string "Très bien. Prends ceci.\p"
	.string "C'est le BADGE ZEPHYR officiel\n"
	.string "de la LIGUE Pokémon.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} reçoit le BADGE ZEPHYR.$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "Le BADGE ZEPHYR augmente\n"
	.string "l'ATTAQUE des Pokémon.\p"
	.string "Il permet aussi aux Pokémon\p"
	.string "d'utiliser FLASH en dehors des\n"
	.string "combats.\p"
	.string "Prends ça aussi.$"

VioletGym_Text_Falkner_TMExplain:
	.string "Avec une CT, un Pokémon apprend\n"
	.string "aussitôt une nouvelle capacité.\p"
	.string "Cette CT contient ATTERRISSAGE.\p"
	.string "Elle restaure jusqu'à la moitié\n"
	.string "des PV maximum du Pokémon.\p"
	.string "Autrement dit, elle le soigne.$"

VioletGym_Text_Falkner_AfterFight:
	.string "Il y a des ARENES Pokémon dans\n"
	.string "les alentours.\p"
	.string "Tu devrais tester ton habileté\n"
	.string "dans ces ARENES.\p"
	.string "Je vais m'entraîner plus dur\n"
	.string "pour\p"
	.string "devenir le plus grand!$"

VioletGym_Text_Falkner_Rematch:
	.string "Félicitations pour ta victoire\n"
	.string "sur le CONSEIL 4!\p"
	.string "J'ai davantage entraîné mes\n"
	.string "Pokémon de type VOL.\p"
	.string "Peux-tu affronter à nouveau la\n"
	.string "puissance des cieux?$"

VioletGym_Text_Falkner_RematchLoss:
	.string "Waouh… Tu m'as encore battu.\p"
	.string "Je vais m'entraîner davantage\n"
	.string "pour devenir le meilleur maître\p"
	.string "des oiseaux!$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "Le mot clé est... Le cran!\p"
	.string "Ceux d'ici s'entraînent nuit et\p"
	.string "jour pour devenir maître des\n"
	.string "Pokémon volants.\p"
	.string "Allez!$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "Yaaah!$"

VioletGym_Text_BirdKeeperRod_After:
	.string "L'habileté d'ALBERT est bien\n"
	.string "réelle!\p"
	.string "Si tu as les chevilles qui\n"
	.string "enflent, change de baskets!$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "Montre-moi si tu as les épaules\n"
	.string "pour battre ALBERT!$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "Vraiment?!$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "C'est pathétique de perdre\n"
	.string "contre toi...$"

VioletGym_Text_GymGuide_Intro:
	.string "Hé toi! Je ne suis pas Dresseur,\n"
	.string "mais je peux te conseiller!\p"
	.string "Crois-moi! Avec de la volonté,\n"
	.string "ton rêve peut devenir réalité.\p"
	.string "Tu y crois? Alors écoute.\p"
	.string "Le meilleur Pokémon d'ALBERT est\n"
	.string "un hibou robuste.\p"
	.string "Il adore manger des BAIES.\p"
	.string "Il n'est pas le plus puissant,\n"
	.string "mais il résiste à de nombreux\n"
	.string "coups.\p"
	.string "ELECTRIK et ROC lui font mal,\n"
	.string "mais gare à COUD'BOUE!\p"
	.string "Pour plus d'aide, va à\n"
	.string "l'Académie Pokémon.\p"
	.string "Les élèves sont de vrais pros!$"

VioletGym_Text_GymGuide_Win:
	.string "Joli combat! Continue comme ça,\n"
	.string "et tu finiras\p"
	.string "Maître Pokémon!$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "Arène de Mauville$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "ARENE Pokémon de MAUVILLE\p"
	.string "DRESSEURS CERTIFIES D'ALBERT:\n"
	.string "{PLAYER}$"
