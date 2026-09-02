VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Penser que je me rapproche de la\n"
	.string "LIGUE POKéMON…\p"
	.string "J’ai le trac…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Je n’ai rien pu faire…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "La LIGUE POKéMON s’éloigne à\n"
	.string "nouveau… Quelle déception…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Pour réussir à parcourir le\n"
	.string "chemin qui te mènera à la LIGUE\p"
	.string "POKéMON, il te faudra avoir la\n"
	.string "confiance de tes POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Votre relation est basée sur une\n"
	.string "solide confiance.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "Comme les POKéMON et les\n"
	.string "DRESSEURS sont toujours\p"
	.string "ensemble, leur confiance\n"
	.string "mutuelle grandit.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Ce n’est pas encore là. Ce n’est\n"
	.string "qu’une étape sur la route de la\p"
	.string "LIGUE POKéMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "C’est en ce sens qu’il faut\n"
	.string "aller!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Tu vas te débrouiller, c’est\n"
	.string "sûr! Tes POKéMON ont tous envie\p"
	.string "d’y aller!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Mes POKéMON me font penser aux\n"
	.string "étoiles!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Je n’avais encore jamais\n"
	.string "rencontré quelqu’un comme toi!$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Même quand tu ne te bats pas,\n"
	.string "j’arrive à sentir une grande\p"
	.string "force émanant de tes POKéMON et\n"
	.string "toi…$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "OK, pas besoin de t’énerver!\n"
	.string "Relax, ça va bien se passer!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Ouah! Formidable!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "C’est bien la ROUTE VICTOIRE.\p"
	.string "Mais ce n’est pas si différent\n"
	.string "de la route que tu as déjà\p"
	.string "empruntée.\p"
	.string "Essaie de profiter du reste du\n"
	.string "chemin à parcourir!$"

