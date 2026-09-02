LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Oh, ça alors! Tu voyages en\n"
	.string "solitaire? Mais tu es si jeune!\p"
	.string "C’est bien pour toi!\p"
	.string "Je suis sûre que tu pourrais\n"
	.string "apprendre un truc ou deux à mes\p"
	.string "enfants!\p"
	.string "Moi? Je suis une spécialiste des\n"
	.string "{POKEBLOCK}S.\p"
	.string "Si je me concentre un peu, je\n"
	.string "peux concocter de fabuleux\p"
	.string "{POKEBLOCK}S.\p"
	.string "Tu veux apprendre des choses de\n"
	.string "la spécialiste des {POKEBLOCK}S?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Tu ne veux vraiment pas?\p"
	.string "Tu ne devrais pas toujours\n"
	.string "vouloir tout faire toi-même, mon\p"
	.string "p’tit!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Bien! Quelle âme avertie! C’est\n"
	.string "un peu long, alors écoute bien!\p"
	.string "C’est bon, je peux commencer?\p"
	.string "Si tu observes les {POKEBLOCK}S,\n"
	.string "tu verras qu’ils sont classés\p"
	.string "selon leur onctuosité.\p"
	.string "Plus le chiffre est bas, plus\n"
	.string "c’est onctueux et mieux c’est.\p"
	.string "N’oublie pas!\p"
	.string "Un bon {POKEBLOCK} est très\n"
	.string "onctueux et a un niveau élevé.\p"
	.string "Un POKéMON peut manger plus de\n"
	.string "bons {POKEBLOCK}S que de\p"
	.string "normaux.\p"
	.string "Et c’est important.\p"
	.string "Pour faire des {POKEBLOCK}S\n"
	.string "onctueux, il faut utiliser\p"
	.string "plusieurs sortes de BAIES.\p"
	.string "Ne sois pas avare! La variété\n"
	.string "des BAIES influe sur\p"
	.string "l’onctuosité des {POKEBLOCK}S.\p"
	.string "Et autre chose…\p"
	.string "Plus il y a de personnes qui\n"
	.string "mixent les BAIES, plus les\p"
	.string "{POKEBLOCK}S sont onctueux.\p"
	.string "C’est pourquoi tu dois parler\n"
	.string "aux autres et faire des\p"
	.string "{POKEBLOCK}S avec eux.\p"
	.string "Voilà à peu près tout ce que tu\n"
	.string "dois savoir pour faire de bons\p"
	.string "{POKEBLOCK}S.\p"
	.string "Si chacun avait des POKéMON\n"
	.string "qu’il aime, d’onctueux\p"
	.string "{POKEBLOCK}S et une famille\n"
	.string "aimante, le monde ne serait que\p"
	.string "bonheur.\p"
	.string "N’abandonne pas, mon p’tit.$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Quand ma femme a mis au monde\n"
	.string "des quadruplés, ça a été un\p"
	.string "choc!\p"
	.string "Mais maintenant, je suis heureux\n"
	.string "de les voir jouer ensemble.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "On va faire des COMBATS MULTI,\n"
	.string "mais je sais que je vais gagner.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "On aime bien échanger des\n"
	.string "données au CENTRE DE DONNEES.\p"
	.string "Mais qu’est-ce qu’on va échanger\n"
	.string "au juste?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "On va faire de super\n"
	.string "{POKEBLOCK}S avec un MIXEUR!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Je veux que tu voies à quel\n"
	.string "point mon POKéMON est fort.\p"
	.string "Alors on va tous les deux\n"
	.string "participer à un CONCOURS.$"

