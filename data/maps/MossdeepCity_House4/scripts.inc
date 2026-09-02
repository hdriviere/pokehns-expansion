MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "Mon petit frère dit qu’il aime\n"
	.string "bien chercher les BASES SECRETES\p"
	.string "des autres.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "Mon petit frère dit qu’il aime\n"
	.string "bien voir les BASES SECRETES des\p"
	.string "autres et mener des combats de\n"
	.string "POKéMON.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "C’est toi qui as aménagé une\n"
	.string "BASE SECRETE {STR_VAR_1}?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "Tu devrais t’aménager une BASE\n"
	.string "SECRETE quelque part. J’irai la\p"
	.string "chercher!$"

MossdeepCity_House4_Text_Skitty:
	.string "DELCATTY: Delcaaah?$"

