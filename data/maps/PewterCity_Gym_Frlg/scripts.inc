PewterCity_Gym_Frlg_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Brock::
	famechecker FAMECHECKER_BROCK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrock, NO_MUSIC
	goto_if_unset FLAG_GOT_TM39_FROM_BROCK, PewterCity_Gym_EventScript_GiveTM39
	msgbox PewterCity_Gym_Text_BrockPostBattle
	release
	end

PewterCity_Gym_EventScript_DefeatedBrock::
	famechecker FAMECHECKER_BROCK, 1
	setflag FLAG_DEFEATED_BROCK
	setflag FLAG_BADGE01_GET
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	set_gym_trainers_frlg 1
	goto PewterCity_Gym_EventScript_GiveTM39
	end

PewterCity_Gym_EventScript_GiveTM39::
	msgbox PewterCity_Gym_Text_TakeThisWithYou
	checkitemspace ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM39
	giveitem_msg PewterCity_Gym_Text_ReceivedTM39FromBrock, ITEM_TM39
	setflag FLAG_GOT_TM39_FROM_BROCK
	msgbox PewterCity_Gym_Text_ExplainTM39
	release
	end

PewterCity_Gym_EventScript_NoRoomForTM39::
	msgbox PewterCity_Gym_Text_DontHaveRoomForThis
	release
	end

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BROCK, PewterCity_Gym_EventScript_GymGuyPostVictory
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial
	release
	end

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders
	release
	end

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_BrockIntro::
	.string "Je suis PIERRE! Je suis le\n"
	.string "CHAMPION d'ARGENTA!\p"
	.string "Je crois en la grande force de\n"
	.string "la pierre!\p"
	.string "C'est pourquoi mes POKéMON sont\n"
	.string "du type ROCHE!\p"
	.string "Tu veux toujours te battre avec\n"
	.string "moi? Même en sachant que tu vas\p"
	.string "perdre?\p"
	.string "Très bien. En\n"
	.string "garde!{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PewterCity_Gym_Text_BrockDefeat::
	.string "Hmm… Beau combat. J'étais trop\n"
	.string "sûr de moi, c'est pour ça que\p"
	.string "j'ai perdu.\p"
	.string "En reconnaissance de ta\n"
	.string "victoire, voici le BADGE ROCHE!\p"
	.string "{FONT_NORMAL}{PLAYER} reçoit le\n"
	.string "BADGE ROCHE!\p"
	.string "{PAUSE_MUSIC}{PLAY_BGM MUS_OBTAIN_BADGE}{PAUSE}\n"
	.string "{PAUSE 86}{RESUME_MUSIC}\p"
	.string "{FONT_MALE}C'est un BADGE\n"
	.string "officiel de la LIGUE POKéMON!\p"
	.string "Les POKéMON de son détenteur\n"
	.string "deviennent plus puissants!\p"
	.string "La technique FLASH peut être\n"
	.string "utilisée!{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}$"

PewterCity_Gym_Text_TakeThisWithYou::
	.string "Attends! Prends ça avec toi!$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
	.string "{PLAYER} reçoit la CT39!$"

PewterCity_Gym_Text_ExplainTM39::
	.string "Une CT (Capsule Tech.) contient\n"
	.string "une attaque à enseigner à un\p"
	.string "POKéMON!\p"
	.string "Une CT ne marche qu'une fois!\p"
	.string "Alors choisis bien le POKéMON à\n"
	.string "qui la donner!\p"
	.string "La CT39 contient TOMBEROCHE!\p"
	.string "Avec cette capacité, ton POKéMON\n"
	.string "lancera des rochers sur\p"
	.string "son ennemi pour baisser sa\n"
	.string "vitesse.$"

PewterCity_Gym_Text_BrockPostBattle::
	.string "Il y a plusieurs types de\n"
	.string "DRESSEURS dans le monde!\p"
	.string "Tu sembles être un DRESSEUR\n"
	.string "d'exception!\p"
	.string "Va à l'ARENE d'AZURIA pour\n"
	.string "tester tes capacités.$"

PewterCity_Gym_Text_DontHaveRoomForThis::
	.string "Ton inventaire est plein!$"

PewterCity_Gym_Text_LiamIntro::
	.string "Une minute!\p"
	.string "Tu es encore loin de pouvoir te\n"
	.string "battre contre PIERRE.\p"
	.string "Tu vas devoir m'affronter avant!$"

PewterCity_Gym_Text_LiamDefeat::
	.string "Zut!\p"
	.string "J'aurais dû te laisser passer!$"

PewterCity_Gym_Text_LiamPostBattle::
	.string "Tu sais te battre… Mais pas\n"
	.string "aussi bien que PIERRE!$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
	.string "Salut graine de CHAMPION!\p"
	.string "Je ne suis pas DRESSEUR mais mes\n"
	.string "conseils sont avisés!\p"
	.string "Laisse-moi te mener à la\n"
	.string "victoire!$"

PewterCity_Gym_Text_LetsGetHappening::
	.string "OK! C'est parti!$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
	.string "Le 1er POKéMON apparaissant dans\n"
	.string "un combat est celui à gauche\p"
	.string "dans la LISTE POKéMON!\p"
	.string "En changeant l'ordre des\n"
	.string "POKéMON, tu peux changer de\p"
	.string "stratégie!\p"
	.string "Essaye différents ordres pour\n"
	.string "t'adapter à ton adversaire.$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
	.string "C'est gratuit, profites-en!$"

PewterCity_Gym_Text_YoureChampMaterial::
	.string "Je le savais! Tu as l'âme d'un\n"
	.string "CHAMPION!$"

PewterCity_Gym_Text_GymStatue::
	.string "ARENE POKéMON d'ARGENTA\n"
	.string "CHAMPION: PIERRE\p"
	.string "VAINQUEURS: {RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "ARENE POKéMON d'ARGENTA\n"
	.string "CHAMPION: PIERRE\p"
	.string "VAINQUEURS: {RIVAL}, {PLAYER}$"

