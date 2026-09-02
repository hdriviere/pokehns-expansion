SaffronCity_CopycatsHouse_2F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, EventScript_MimicTutor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, FEMALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
	.string "{PLAYER}: Salut! Tu aimes les\n"
	.string "POKéMON?\p"
	.string "{PLAYER}: Heu, non Je demandais\n"
	.string "juste!\p"
	.string "{PLAYER}: Hein? T'es bizarre\n"
	.string "toi!\p"
	.string "COPIEUSE: Hmm? Arrêter de mimer?\p"
	.string "Mais je ne sais faire que ça!$"

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
	.string "{PLAYER}: Salut! Tu dois aimer\n"
	.string "les POKéMON, non?\p"
	.string "{PLAYER}: Heu, non Je demandais\n"
	.string "juste!\p"
	.string "{PLAYER}: Hein? T'es bizarre\n"
	.string "toi!\p"
	.string "COPIEUSE: Hmm? Arrêter de mimer?\p"
	.string "Mais je ne sais faire que ça!$"

Text_MimicTeach::
	.string "Whaaaaaa! Une POKéPOUPEE!\p"
	.string "C'est pour moi? Merci!\p"
	.string "Tiens, prends ça en échange!$"

Text_MimicDeclined::
	.string "T'aimes pas COPIE?$"

Text_MimicWhichMon::
	.string "Moi aussi j'adore! Alors, qui va\n"
	.string "l'apprendre?$"

Text_MimicTaughtMale::
	.string "{PLAYER}: Salut! Merci pour la\n"
	.string "CT31!\p"
	.string "{PLAYER}: Pardon?\p"
	.string "{PLAYER}: Heu… C'est aussi cool\n"
	.string "que ça de m'imiter?\p"
	.string "COPIEUSE: Ah non! C'est vraiment\n"
	.string "la galère, t'arrêtes pas\p"
	.string "d'bouger!$"

Text_MimicTaughtFemale::
	.string "{PLAYER}: Salut! Merci pour la\n"
	.string "CT31!\p"
	.string "{PLAYER}: Pardon?\p"
	.string "{PLAYER}: Heu… C'est aussi\n"
	.string "marrant que ça de m'imiter?\p"
	.string "COPIEUSE: Ah non! C'est vraiment\n"
	.string "la galère, t'arrêtes pas\p"
	.string "d'bouger!$"

SaffronCity_CopycatsHouse_2F_Text_Doduo::
	.string "DODUO: Doduuu!\p"
	.string "JOLI MIROIR, DIS-MOI QUI EST LA\n"
	.string "PLUS BELLE!$"

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
	.string "Ça, un POKéMON rare? Tu t'moques\n"
	.string "de moi! C'est rien qu'une\p"
	.string "poupée!$"

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
	.string "Un plombier? Mais… Ça a l'air\n"
	.string "sympa.$"

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
	.string "…\p"
	.string "Mes secrets!\p"
	.string "Mon boulot: je mime! Ma passion:\n"
	.string "les poupées! Mon POKéMON\p"
	.string "préféré: MELOFEE!$"

