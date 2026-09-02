SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Heu! Je suis le PRESIDENT du FAN\n"
	.string "CLUB POKéMON!\p"
	.string "En tant que PRESIDENT, je suis\n"
	.string "bien sûr la personne la plus\p"
	.string "importante!\p"
	.string "Personne ne sait mieux que moi\n"
	.string "comment dresser un POKéMON.\p"
	.string "Personne!\p"
	.string "Mais laisse-moi te parler des\n"
	.string "CONCOURS POKéMON.\p"
	.string "Il y a des évènements où l’on\n"
	.string "peut montrer ses POKéMON à tout\p"
	.string "le monde.\p"
	.string "Mais ils ont lieu loin d’ici,\n"
	.string "alors je ne peux pas y\p"
	.string "participer souvent.\p"
	.string "C’est pour cela que nous nous\n"
	.string "réunissons ici, pour montrer nos\p"
	.string "POKéMON aux autres.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "Le POKéMON d’un DRESSEUR ayant\n"
	.string "participé à un CONCOURS POKéMON,\p"
	.string "voilà ce que j’aimerais voir.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Hum, je vois que tu as participé\n"
	.string "à un CONCOURS POKéMON!\p"
	.string "S’il te plaît, laisse-moi voir\n"
	.string "comme tu as dressé tes POKéMON.\p"
	.string "J’adore voir comment les autres\n"
	.string "dressent leurs POKéMON.\p"
	.string "L’enthousiasme des POKéMON bien\n"
	.string "dressés…\p"
	.string "Les regards attentionnés et\n"
	.string "affectueux des DRESSEURS…\p"
	.string "Mon cœur déborde. C’est un\n"
	.string "bonheur intense!\p"
	.string "Oh, pardon! Ça fait déjà trop\n"
	.string "longtemps que je parle!\p"
	.string "Pourrais-je examiner tes POKéMON\n"
	.string "pour voir s’ils progressent\p"
	.string "bien?$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Ton POKéMON se développe-t-il\n"
	.string "bien? Laisse-moi l’examiner!$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hum, hum… Je vois…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hum… Ce n’est pas trop mal, mais\n"
	.string "cela dit, ce n’est pas excellent\p"
	.string "non plus…\p"
	.string "Toi, le DRESSEUR, tu dois\n"
	.string "t’efforcer de faire progresser\p"
	.string "tes POKéMON!\p"
	.string "Tu devrais, par exemple, leur\n"
	.string "donner plus de {POKEBLOCK}S.$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Oh, ça alors…\p"
	.string "Tes POKéMON progressent vite. Tu\n"
	.string "mérites une récompense.\p"
	.string "Mais tu n’as pas assez de place\n"
	.string "dans ton SAC pour la recevoir.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Ton {STR_VAR_1}, il progresse\n"
	.string "tellement vite! Quel spécimen!\p"
	.string "Mais si tu lui donnes ça, il\n"
	.string "grandira encore plus vite! C’est\p"
	.string "garanti!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Fais porter ce FOUL. ROUGE à un\n"
	.string "POKéMON.\p"
	.string "Tout le monde reconnaîtra son\n"
	.string "SANG-FROID!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Fais porter ce FOUL. BLEU à un\n"
	.string "POKéMON.\p"
	.string "Sa BEAUTE n’en sera\n"
	.string "qu’accentuée!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Fais porter ce FOUL. ROSE à un\n"
	.string "POKéMON.\p"
	.string "Ça fera un peu ressortir sa\n"
	.string "GRACE!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Fais porter ce FOUL. VERT à un\n"
	.string "POKéMON.\p"
	.string "Ça augmentera son INTELLIGENCE!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Fais porter ce FOUL. JAUNE à un\n"
	.string "POKéMON.\p"
	.string "Ça lui redonnera de la\n"
	.string "ROBUSTESSE!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Désolé, mais je n’ai rien\n"
	.string "d’autre à te donner! Rien du\p"
	.string "tout!\p"
	.string "Après tout, tu as aussi la\n"
	.string "possibilité de dresser tes\p"
	.string "POKéMON sans avoir  recours au\n"
	.string "moindre objet.$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "J’apprécie de voir des POKéMON\n"
	.string "qui aiment leur DRESSEUR.\p"
	.string "Les POKéMON sont très sensibles\n"
	.string "aux sentiments de leur DRESSEUR.\p"
	.string "Si tu donnes amour et attention\n"
	.string "à tes POKéMON, ils t’aimeront en\p"
	.string "retour.\p"
	.string "Quand l’amour de tes POKéMON\n"
	.string "aura grandi, passe me voir.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Ton POKéMON t’adore vraiment.\p"
	.string "Voilà un cadeau de la part du\n"
	.string "FAN CLUB pour toi, le DRESSEUR\p"
	.string "attentionné!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "Les POKéMON sont très sensibles\n"
	.string "aux sentiments de leur DRESSEUR.\p"
	.string "Si tu donnes amour et attention\n"
	.string "à tes POKéMON, ils t’aimeront en\p"
	.string "retour.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Si tu laisses un POKéMON se\n"
	.string "faire mettre K.O. au combat, il\p"
	.string "n’appréciera pas.\p"
	.string "Il aura alors moins confiance en\n"
	.string "son DRESSEUR.\p"
	.string "En d’autres termes, il ne\n"
	.string "t’aimera pas trop.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Les POKéMON aiment-ils recevoir\n"
	.string "des objets?\p"
	.string "Les miens sont ravis quand je\n"
	.string "leur donne des PROTEINES.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Skiiittyyy…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZATON: Zigzaaatooon…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Azuumaariill?$"

