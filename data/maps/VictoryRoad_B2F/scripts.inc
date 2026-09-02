VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "On s’entraîne tous ensemble,\n"
	.string "avec les membres de ma famille!\p"
	.string "Je ne perds contre personne!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Tu as un meilleur niveau que ma\n"
	.string "famille?! Est-ce possible?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "J’ai toujours été le meilleur de\n"
	.string "la famille. Je n’avais encore\p"
	.string "jamais perdu…\p"
	.string "J’ai perdu confiance en moi… Je\n"
	.string "vais peut-être rentrer chez moi…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "On m’avait dit qu’il y avait un\n"
	.string "môme très fort. C’est de toi\p"
	.string "qu’ils parlaient?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "La demi-portion est forte!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "D’après les rumeurs, le p’tit\n"
	.string "môme très fort viendrait de\p"
	.string "CLEMENTI-VILLE.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Tu dois commencer à fatiguer.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Aucun signe de fatigue du tout!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "La ROUTE VICTOIRE et la LIGUE\n"
	.string "POKéMON sont des défis épuisants\p"
	.string "et de longue haleine. Gare à la\n"
	.string "fatigue!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Avoir beaucoup de BADGES ne\n"
	.string "suffit pas.\p"
	.string "Il y aura toujours quelqu’un de\n"
	.string "plus fort que toi!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Tu as un meilleur niveau que\n"
	.string "moi!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Regarde bien tes BADGES et\n"
	.string "rappelle- toi quels DRESSEURS tu\p"
	.string "as affrontés.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Je suis arrivé jusqu’ici, mais\n"
	.string "le stress me donne des maux\p"
	.string "d’estomac…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Oooh… Ça fait mal…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Je ne peux pas m’empêcher de\n"
	.string "stresser en sachant que la LIGUE\p"
	.string "POKéMON est si proche.\p"
	.string "J’arrive à peine à me détendre.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "L’élite de l’élite se réunit\n"
	.string "dans cette grotte.\p"
	.string "T’en penses quoi?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Pas une seule fausse note!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "T’as du cran, continue comme ça!$"

