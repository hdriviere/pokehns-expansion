SeafoamIslands_Gym_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_Blaine_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	msgbox SeafoamIslands_Gym_Text_Blaine_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CRAMOIS'ÎLE\n"
    .string "CHAMPION: AUGUSTE\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CRAMOIS'ÎLE\n"
    .string "CHAMPION: AUGUSTE\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED,\n"
    .string "{PLAYER}$"

SeafoamIslands_Gym_Text_Blaine_GiveTM:
	.string "Prends aussi ceci!$"

SeafoamIslands_Gym_Text_Blaine_ExplainTM:
	.string "Cette CT contient la redoutable\n"
	.string "SURCHAUFFE!\p"
	.string "Elle brûle la cible, mais réduit\n"
	.string "ensuite ta puissance.\p"
	.string "Ton prochain adversaire aura\n"
	.string "intérêt à avoir un ANTI-BRÛLE!\l"
	.string "Waaah!$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "AUGUSTE: Waaah!\p"
	.string "Mon ARENE de CRAMOIS'ILE a\n"
	.string "brûlé.\p"
	.string "Moi et mes Pokémon de feu\n"
	.string "n'avons\p"
	.string "plus de maison à cause du\n"
	.string "volcan.\p"
	.string "Waaah!\p"
	.string "Mais je suis toujours un\n"
	.string "CHAMPION!\p"
	.string "Et je fais la loi dans cette\n"
	.string "grotte.\p"
	.string "Bats-moi et je te donnerai un\n"
	.string "BADGE. Promis!\p"
	.string "J'espère que tu as de\n"
	.string "l'ANTI-BRULE!$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "AUGUSTE: Bien. J'ai perdu.\p"
	.string "Tu as mérité le BADGE VOLCAN!$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} reçoit le BADGE VOLCAN.$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "AUGUSTE: Je perds cette fois\n"
	.string "mais la\p"
	.string "prochaine, je serai vainqueur.\p"
	.string "Je vais reconstruire mon ARENE à\p"
	.string "CRAMOIS'ILE et nous combattrons\n"
	.string "à nouveau.$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "AUGUSTE: Mes Pokémon de feu\p"
	.string "seront invincibles tu verras!$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "AUGUSTE: Waouh!\p"
	.string "Je vois que tu es devenu le\n"
	.string "MAÎTRE de KANTO!\p"
	.string "C'est incandescent!\p"
	.string "Ton talent est de premier ordre.\p"
	.string "Je suis toujours partant pour\n"
	.string "un combat.\p"
	.string "Veux-tu me réaffronter?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "AUGUSTE: Ton talent est vraiment\n"
	.string "ardent!\p"
	.string "Tu as réduit mes défenses\n"
	.string "en cendres.$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "Yo!\p"
	.string "Hein? C'est déjà fini?\p"
	.string "Désolé!\p"
	.string "L'ARENE de CRAMOIS'ILE était\n"
	.string "fermée\p"
	.string "alors je savais pas où te\n"
	.string "trouver.\p"
	.string "Enfin t'es super balèze même\n"
	.string "sans\p"
	.string "mes conseils. Je suis très fier!$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "Une ARENE Pokémon\n"
	.string "peut être n'importe\p"
	.string "où tant que le\n"
	.string "CHAMPION est là.\p"
	.string "Pas besoin d'un toit.$"
