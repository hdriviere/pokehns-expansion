DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Qu’est-ce qui est à la mode?\n"
	.string "Heu, sans doute “{STR_VAR_1}”!\p"
	.string "Je n’imagine pas la vie sans\n"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Qu’est-ce qui est à la mode?\n"
	.string "Heu, sans doute “{STR_VAR_1}”!\p"
	.string "Mais ça commence à me lasser.\p"
	.string "Je vais trouver un nouveau truc\n"
	.string "à la mode.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "J’essaie d’apprendre\n"
	.string "“{STR_VAR_1}” à mon POKéMON,\p"
	.string "mais ça ne marche pas bien.\p"
	.string "Ça doit être un peu trop\n"
	.string "compliqué.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "En ce moment, j’étudie cette\n"
	.string "mode du “{STR_VAR_1}”.\p"
	.string "C’est vrai qu’il y a un lien\n"
	.string "solide entre “{STR_VAR_1}” et\p"
	.string "“{STR_VAR_2}”?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh! J’ai eu une bonne intuition,\n"
	.string "alors!\p"
	.string "Je dois être encore branché,\n"
	.string "yéhé!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Quoi?!? Vraiment?!?\p"
	.string "Oh, ce n’est pas facile de\n"
	.string "suivre les modes sans se\p"
	.string "tromper!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Tout le monde parle de\n"
	.string "“{STR_VAR_1}”… N’y aurait-il pas\p"
	.string "une émission de télé là-dessus?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "De l’autre côté de l’océan?\p"
	.string "Tu crois que “{STR_VAR_1}” est\n"
	.string "encore plus célèbre de l’autre\p"
	.string "côté de l’océan?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Je collectionne les objets\n"
	.string "dérivés de “{STR_VAR_1}”.\p"
	.string "J’ai les poupées officielles de\n"
	.string "“{STR_VAR_1}”…\p"
	.string "La marque de vêtements\n"
	.string "officielle de “{STR_VAR_1}”…\p"
	.string "Et les albums photos officiels\n"
	.string "de “{STR_VAR_1}”.\p"
	.string "Hé hé, tout ça, c’est à moi! Et\n"
	.string "je ne partagerai rien avec toi!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "RECONNAITRE LES BONS\n"
	.string "“{STR_VAR_1}” ET LES MAUVAIS\p"
	.string "“{STR_VAR_1}”…\p"
	.string "LE LIEN ENTRE  “{STR_VAR_1}” ET\n"
	.string "LES POKéMON…\p"
	.string "L’UTILITE DE “{STR_VAR_1}”…\p"
	.string "C’est vraiment plein de livres\n"
	.string "sur “{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "Le titre est: “LE CRI DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "Le titre est: “LE SOURIRE DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Le titre est: “LE DERNIER\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Le titre est: “LA NAISSANCE DE\n"
	.string "{STR_VAR_1}”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "J’ai vu “{STR_VAR_1}”! Cool,\n"
	.string "hein?\p"
	.string "C’est le truc le plus génial de\n"
	.string "la journée!\p"
	.string "C’était d’enfer! Carrément\n"
	.string "ahurissant!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, non, non, non.\p"
	.string "Ce “{STR_VAR_1}” que tu prétends\n"
	.string "avoir vu. Ça ne peut pas être\p"
	.string "ça.\p"
	.string "Le véritable article est\n"
	.string "beaucoup plus… Comment dire?\p"
	.string "Précis et plus mélodieux!\p"
	.string "Ah, pas de doute. C’est\n"
	.string "étonnant!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Hé, écoute, j’ai composé une\n"
	.string "chanson sur “{STR_VAR_1}”.\p"
	.string "“{STR_VAR_1}” est très célèbre,\n"
	.string "maintenant.\p"
	.string "Bon, écoute! … …\p"
	.string "Oh! {STR_VAR_1}!\p"
	.string "Super {STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Si je peux me permettre, mon\n"
	.string "cher ami, tu devrais apprendre à\p"
	.string "chanter avant d’essayer de nous\n"
	.string "divertir avec “{STR_VAR_1}”.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "De toute façon, je crois que\n"
	.string "nous devrions organiser une\p"
	.string "grande fête sur l’île en\n"
	.string "l’honneur de “{STR_VAR_1}”.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, quelle excellente idée!\p"
	.string "On pourra enfin déterminer qui\n"
	.string "en connaît le plus sur\p"
	.string "“{STR_VAR_1}”. C’est une idée de\n"
	.string "génie, vraiment!\p"
	.string "Dès maintenant, nos vies seront\n"
	.string "axées sur “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Mais je me disais…\p"
	.string "Vous ne croyez pas que\n"
	.string "“{STR_VAR_1}”, qui n’était\p"
	.string "qu’une mode, est maintenant\n"
	.string "quelque chose de tout à fait\p"
	.string "courant?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Ah, pardon? Autant que ça?\p"
	.string "Cependant, il est vrai que\n"
	.string "“{STR_VAR_1}” est très présent\p"
	.string "dans nos esprits, même lorsqu’on\n"
	.string "dort.\p"
	.string "Absolument, tu es le PROF de\n"
	.string "“{STR_VAR_1}”, mon vieux!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Si nous formons une équipe, nous\n"
	.string "serons invincibles, dès qu’il\p"
	.string "s’agira de “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Bien vu, camarade!\p"
	.string "Nous serons le DUO\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Quelle image respectable,\n"
	.string "n’est-ce pas? Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Pour moi, la BOMB-BEURK, c’est\n"
	.string "le nec plus ultra. Pas de doute\p"
	.string "possible.\p"
	.string "Hein? Tu ne sais pas ce que\n"
	.string "c’est qu’une BOMB-BEURK?\p"
	.string "C’est carrément dommage. Je t’en\n"
	.string "donnerai une.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "J’adore la BOMB-BEURK.\p"
	.string "Mais c’est vrai que l’expression\n"
	.string "“{STR_VAR_1}” est pas mal non\p"
	.string "plus.$"

