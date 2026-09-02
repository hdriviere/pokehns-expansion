ViridianCity_Gym_hns_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE_HNS, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	msgbox ViridianCity_Gym_Text_LeaderBlue_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_TRICK_ROOM
	msgbox ViridianCity_Gym_Text_LeaderBlue_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	setvar VAR_OAK_MT_SILVER_CALL, 1
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "BLUE: Tu en redemandes déjà?\p"
	.string "Pour me réaffronter, viens au\n"
	.string "DOJO DE COMBAT!$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "BLUE: Yo! Te voilà enfin!\p"
	.string "J'avais pas trop envie à\n"
	.string "CRAMOIS'\p"
	.string "ILE mais là je vais te battre.\p"
	.string "…\p"
	.string "Tu dis quoi? Tu as passé toutes\n"
	.string "les ARENES de JOHTO?\p"
	.string "Ils sont nuls à JOHTO alors...\p"
	.string "Mais t'en fais pas...\p"
	.string "Je vais tout de suite te dire si\p"
	.string "tu as du talent ou non.\p"
	.string "C'est parti, minable de JOHTO!$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "BLUE: Quoi?\p"
	.string "Comment c'est-y possible, ça?\p"
	.string "...\p"
	.string "Pfff... Tiens, prends ce BADGE\n"
	.string "TERRE.$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER} reçoit le BADGE TERRE.$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "Blue: ...\p"
	.string "J’avais tort. Tu es un Dresseur\n"
	.string "de talent!\p"
	.string "Je le reconnais!\p"
	.string "Mais bon... Je te battrai un\n"
	.string "jour. Ne t’inquiète pas.$"

ViridianCity_Gym_Text_LeaderBlue_GiveTM:
	.string "Emporte ceci.$"

ViridianCity_Gym_Text_LeaderBlue_ExplainTM:
	.string "C'est DISTORSION.\p"
	.string "Elle inverse l'ordre d'action\n"
	.string "de tous les Pokémon au combat.\p"
	.string "Les plus lents agissent d'abord,\n"
	.string "les plus rapides en dernier.\p"
	.string "Utilise-la pour bouleverser\n"
	.string "le combat.$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "BLUE: Ecoute voir.\p"
	.string "Reste cool jusqu'à notre\n"
	.string "prochain combat, d'accord?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "Salut, graine de star! Tout va\n"
	.string "bien?\p"
	.string "Le CHAMPION\n"
	.string "est celui qui a\p"
	.string "combattu le MAITRE\n"
	.string "il y a trois ans.\p"
	.string "C'est pas un tendre.\p"
	.string "Alors... Heu... Bonne chance!$"

ViridianCity_Gym_Text_Guide_Win:
	.string "Fiiou! Alors toi, t'es cool!\p"
	.string "Ca c'était du combat!\p"
	.string "J'en ai les larmes aux yeux.$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE JADIELLE\n"
    .string "CHAMPION: BLUE\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE JADIELLE\n"
    .string "CHAMPION: BLUE\p"
    .string "DRESSEURS VAINQUEURS: BLUE, RED,\n"
    .string "{PLAYER}$"
