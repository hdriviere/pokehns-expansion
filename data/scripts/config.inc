Debug_FlagsAndVarNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsAndVarNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsAndVarNotSetBattleConfigMessage_Text:
	.string "Fonctionnalité inutilisable!\n"
	.string "Définissez un flag valide et une\p"
	.string "variable valide dans:\n"
	.string "'include/config/battle.h'!$"
