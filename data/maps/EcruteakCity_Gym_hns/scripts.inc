EcruteakCity_Gym_hns_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_HNS, SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING_HNS, SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA_HNS, MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE_HNS, MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1_HNS, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "Arène de Rosalia$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "ARENE Pokémon DE ROSALIA\p"
	.string "DRESSEURS CERTIFIÉS\n"
	.string "PAR MORTIMER:\l"
	.string "{PLAYER}$"

MortyIntroText:
	.string "Bienvenue.\p"
	.string "Ici, à ROSALIA, les Pokémon ont\n"
	.string "toujours été vénérés.\p"
	.string "On raconte qu'un Pokémon aux\n"
	.string "couleurs de l'arc-en-ciel\n"
	.string "apparaît\l"
	.string "devant les vrais Dresseurs.\p"
	.string "J'ai cru cette légende.\p"
	.string "Je me suis entraîné ici,\n"
	.string "en secret.\p"
	.string "Je peux désormais voir ce que\n"
	.string "les autres ne voient pas.\p"
	.string "Encore un peu...\p"
	.string "Avec un peu plus d'entraînement,\n"
	.string "je pourrai entrevoir un avenir\l"
	.string "où je rencontrerai ce Pokémon.\p"
	.string "Tu vas m'aider à atteindre\n"
	.string "ce niveau!$"

MortyWinLossText:
	.string "Je ne suis pas encore\n"
	.string "assez bon. Je ne\p"
	.string "vois rien. Il me\n"
	.string "faut des lunettes!!\p"
	.string "Bon allez, ce BADGE est à toi.$"

Text_ReceivedFogBadge:
	.string "{PLAYER} reçoit le BADGE BRUME.$"

MortyText_FogBadgeSpeech:
	.string "Avec le BADGE BRUME, les Pokémon\n"
	.string "jusqu'au niveau 50 t'obéiront.\p"
	.string "De plus, les Pokémon qui\n"
	.string "connaissent SURF pourront\l"
	.string "l'utiliser partout.\p"
	.string "Je veux aussi te donner ceci.$"

MortyText_ShadowBallSpeech:
	.string "C'est BALL'OMBRE.\n"
	.string "Elle inflige des dégâts et peut\l"
	.string "baisser la DÉF. SPÉ.\p"
	.string "Utilise-la si elle te convient.$"

MortyFightDoneText:
	.string "Je vois...\p"
	.string "Ton voyage t'a mené dans des\n"
	.string "contrées lointaines.\p"
	.string "Tu as vu bien plus de choses\n"
	.string "que moi.\p"
	.string "Je t'envie pour cela...$"

MortyRematchText:
	.string "Ah, le Maître de JOHTO!\n"
	.string "Merci d'être venu.\p"
	.string "Tu as fait preuve de force et\n"
	.string "de talent, mais as-tu progressé\l"
	.string "depuis notre dernier combat?\p"
	.string "Depuis, je me suis entraîné avec\n"
	.string "mes Pokémon de type SPECTRE.\p"
	.string "Voyons si tu peux encore vaincre\n"
	.string "les ombres.\p"
	.string "Veux-tu prendre ta revanche?$"

Morty_RematchDefeatText:
	.string "Je ne suis pas encore\n"
	.string "assez bon...\p"
	.string "Tu as vu bien plus de choses\n"
	.string "que moi.\p"
	.string "Je t'envie pour cela...$"

SageJeffreySeenText:
	.string "J'ai passé le printemps avec\n"
	.string "mes Pokémon.\p"
	.string "Puis l'été, l'automne\n"
	.string "et l'hiver...\p"
	.string "Le printemps est revenu.\n"
	.string "Nous sommes ensemble depuis\l"
	.string "bien longtemps.$"

SageJeffreyBeatenText:
	.string "J'ai connu la victoire\n"
	.string "comme la défaite.$"

SageJeffreyAfterBattleText:
	.string "D'où viennent les Pokémon?$"

SagePingSeenText:
	.string "Peux-tu infliger des dégâts à\n"
	.string "nos Pokémon?$"

SagePingBeatenText:
	.string "Ah! Bien joué!$"

SagePingAfterBattleText:
	.string "Nous utilisons des Pokémon de\n"
	.string "type SPECTRE.\p"
	.string "Les attaques de type NORMAL ne\n"
	.string "peuvent pas les toucher!$"

MediumMarthaSeenText:
	.string "Je vais gagner!$"

MediumMarthaBeatenText:
	.string "Et bah non, j'ai perdu!$"

MediumMarthaAfterBattleText:
	.string "C'est celui qui désire le plus\n"
	.string "gagner qui l'emportera!$"

MediumGraceSeenText:
	.string "Nos couloirs obscurs te posent\n"
	.string "problème?\p"
	.string "Bats-moi si tu veux un indice!$"

MediumGraceBeatenText:
	.string "Kk-kkoi?$"

MediumGraceAfterBattleText:
	.string "Très bien. Je vais te révéler\n"
	.string "le secret des ombres.\p"
	.string "Le chemin est juste devant\n"
	.string "tes yeux!$"

EcruteakCity_GymGuideText:
	.string "Hé, futur Maître! Tu as presque\n"
	.string "fait la moitié du chemin!\p"
	.string "Les Dresseurs utilisent des\n"
	.string "Pokémon de type SPECTRE\l"
	.string "et TÉNÈBRES.\p"
	.string "MORTIMER est expert du type\n"
	.string "SPECTRE.\p"
	.string "Mais méfie-toi de son\n"
	.string "cerf mystique.\p"
	.string "On raconte qu'il provoque\n"
	.string "d'étranges cauchemars...$"

EcruteakCity_GymGuideWinText:
	.string "Waouh, {PLAYER}! Bien joué!\p"
	.string "J’avais tellement peur que\n"
	.string "j’étais planqué dans un coin!$"

EcruteakCity_GymClosedText:
	.string "MORTIMER, le CHAMPION, est\n"
	.string "absent.\p"
	.string "Tu dois partir.\p"
	.string "Hohohoho.$"
