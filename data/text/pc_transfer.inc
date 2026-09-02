gText_PkmnTransferredSomeonesPC::
	.string "{STR_VAR_2} a été transféré sur\n"
	.string "le PC de ???.\p"
	.string "Il a été placé dans la BOITE\n"
	.string "appelée “{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPC::
	.string "{STR_VAR_2} a été transféré sur\n"
	.string "le PC de$"
#if IS_FRLG || IS_HNS
	.string " LEO.\p"
#else
	.string " ANNIE.\p"
#endif
	.string "Il a été placé dans la BOITE\n"
	.string "“{STR_VAR_1}”.$"

gText_PkmnTransferredSomeonesPCBoxFull::
	.string "La BOITE {STR_VAR_3} sur le PC\n"
	.string "de ??? est pleine.\p"
	.string "{STR_VAR_2} a été placé dans la\n"
	.string "BOITE appelée “{STR_VAR_1}”.$"

gText_PkmnTransferredLanettesPCBoxFull::
	.string "La BOITE {STR_VAR_3} du PC de$"
#if IS_FRLG || IS_HNS
	.string " LEO était pleine.\p"
#else
	.string " ANNIE était pleine.\p"
#endif
	.string "{STR_VAR_2} a été transféré dans\n"
	.string "la BOITE “{STR_VAR_1}”.$"

gText_PkmnSentToPCAfterCatch::
	.string "{STR_VAR_2} est envoyé au PC de\n"
	.string "{B_PC_CREATOR_NAME}.\p"
	.string "Il est placé dans la BOITE\n"
	.string "“{STR_VAR_1}”.$"

gText_PlayerObtainedTheMon::
	.string "{PLAYER} obtient le POKéMON\n"
	.string "{STR_VAR_1}!$"

gText_NoMoreRoomForPokemon::
	.string "Il n’y a plus de place pour les\n"
	.string "POKéMON.\p"
	.string "Les BOITES sont pleines et ne\n"
	.string "peuvent plus rien recevoir.$"

gText_NicknameThisPokemon::
	.string "Voulez-vous donner un surnom à\n"
	.string "{STR_VAR_1}?$"
