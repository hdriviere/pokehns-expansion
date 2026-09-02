MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "En tenant la CARTE MIRACLE, vous\n"
	.string "pouvez effectuer des\p"
	.string "sondages dans les BOUTIQUES\n"
	.string "POKéMON.\p"
	.string "Utilisez ces sondages pour\n"
	.string "inviter des DRESSEURS à\p"
	.string "ATALANOPOLIS.\p"
	.string "Laissez-moi vous donner un mot\n"
	.string "de passe secret:\p"
	.string "“DONNE-MOI UN COMBAT”\p"
	.string "Ecrivez ça sur un sondage et\n"
	.string "envoyez-le au SYSTEME DE\p"
	.string "COMMUNICATION SANS FIL.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Merci d’utiliser le système\n"
	.string "CADEAU MYST.\p"
	.string "Un DRESSEUR arrivé à\n"
	.string "ATALANOPOLIS vous cherche.\p"
	.string "On espère que vous apprecierez\n"
	.string "le combat contre ce DRESSEUR.\p"
	.string "Vous pouvez inviter des\n"
	.string "DRESSEURS en entrant le mot de\p"
	.string "passe.\p"
	.string "Essayez de trouver des mots de\n"
	.string "passe qui pourraient\p"
	.string "fonctionner.$"
