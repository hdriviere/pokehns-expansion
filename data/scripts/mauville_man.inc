MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Salut, je suis le BROCANTEUR. Tu\n"
	.string "veux échanger des décorations\p"
	.string "avec moi?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh… Je me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Mais, nous avons déjà échangé\n"
	.string "des décorations, toi et moi.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Si tu veux un objet décoratif\n"
	.string "que j’ai, n’hésite pas à me le\p"
	.string "demander.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Tu ne veux rien? Bouh, je\n"
	.string "n’intéresse personne…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "A l’époque, cette décoration\n"
	.string "appartenait à {STR_VAR_1}.\p"
	.string "Tu la veux?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Hé… Une minute! Tu ne possèdes\n"
	.string "aucune décoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Très bien, choisis la décoration\n"
	.string "que tu veux échanger avec moi.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Tu ne veux rien échanger avec\n"
	.string "moi? Bouh, je me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Tu as déjà stocké le maximum de\n"
	.string "{STR_VAR_2}S. Tu n'as plus de place.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Alors, on échange {STR_VAR_3}\n"
	.string "contre {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Tu utilises déjà cette\n"
	.string "décoration. Tu ne peux pas\p"
	.string "l’échanger.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Dans ce cas, faisons l’échange!\n"
	.string "J’enverrai ma décoration dans\p"
	.string "ton PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ah non, pas cet objet!\p"
	.string "C’est une décoration vraiment\n"
	.string "rare. Je ne peux pas te\p"
	.string "l’échanger!\p"
	.string "Il n’y a rien d’autre qui\n"
	.string "t’intéresse?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Je suis le CONTEUR. Je peux te\n"
	.string "raconter l’histoire de DRESSEURS\p"
	.string "légendaires.\p"
	.string "Alors, tu veux écouter mon\n"
	.string "histoire?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh… Je me sens frustré…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "J’en connais, des légendes.\n"
	.string "Quelle histoire veux-tu que je\p"
	.string "raconte?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Mais je ne connais aucun\n"
	.string "DRESSEUR légendaire. Donc, pas\p"
	.string "d’histoire.\p"
	.string "Où peut-on trouver un DRESSEUR\n"
	.string "digne d’entrer dans la légende?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "De quoi?!? Toi… Tu as…\p"
	.string "{STR_VAR_2} {STR_VAR_1} fois?!?\p"
	.string "Mais c’est formidable! C’est la\n"
	.string "naissance d’une nouvelle\p"
	.string "légende!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Mais j’y pense, il y a peut-être\n"
	.string "encore d’autres DRESSEURS à\p"
	.string "découvrir, avec des légendes\n"
	.string "plus impressionnantes?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Et toi, tu es DRESSEUR?\p"
	.string "Alors dis-moi, as-tu des\n"
	.string "histoires à me raconter, même\p"
	.string "vaguement légendaires?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "À propos… Veux-tu entendre\n"
	.string "une autre histoire légendaire?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hum… Je suis un peu déçu…\p"
	.string "J’aurais aimé que tu me racontes\n"
	.string "une histoire digne d’être\p"
	.string "appelée légende.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "J’aimerais bien que plus de gens\n"
	.string "s’intéressent à mes épiques\p"
	.string "sagas de DRESSEURS légendaires.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "Le DRESSEUR à la sauvegarde\n"
	.string "facile$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "sauvegardé la partie$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauvegardé sa\n"
	.string "partie {STR_VAR_1} fois!\p"
	.string "Impossible de trouver un\n"
	.string "DRESSEUR plus prudent que\p"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "Le DRESSEUR qui lançait des\n"
	.string "modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "lancé des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a lancé de nouvelles\n"
	.string "modes {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} lance des modes dans\n"
	.string "toute la région de HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "Le DRESSEUR qui plantait des\n"
	.string "BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "planté des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a planté {STR_VAR_1}\n"
	.string "BAIES!\p"
	.string "{STR_VAR_3} est connu pour être\n"
	.string "un grand amateur de BAIES!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "Le DRESSEUR fan de VELOS$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "changé de VELO$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a changé de VELO\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit aimer les VELOS\n"
	.string "à la folie!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "Le DRESSEUR interviewé$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "répondu à une interview$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a été interviewé\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est vraiment un\n"
	.string "DRESSEUR très médiatisé!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "Le DRESSEUR combattant$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "combattu$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a combattu\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "ne rate pas une occasion de se\p"
	.string "battre!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "Le DRESSEUR chasseur de POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "attrapé des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} est un chasseur de\n"
	.string "POKéMON sauvages légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "Le DRESSEUR pêcheur$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "attrapé des POKéMON avec une\n"
	.string "CANNE$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON en les\p"
	.string "pêchant!\p"
	.string "{STR_VAR_3} est un pêcheur\n"
	.string "légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "Le DRESSEUR qui couvait des\n"
	.string "OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "fait éclore des OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait éclore\n"
	.string "{STR_VAR_1} OEUF(S) de POKéMON!\p"
	.string "{STR_VAR_3} s’occupe\n"
	.string "formidablement bien des OEUFS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "Le DRESSEUR aux POKéMON évolués$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "fait évoluer des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait évoluer\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} est un pro de\n"
	.string "l’évolution des POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "Le DRESSEUR fan de CENTRES\n"
	.string "POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "utilisé des CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné des POKéMON\n"
	.string "{STR_VAR_1} fois dans des\p"
	.string "CENTRES POKéMON!\p"
	.string "Il n’existe pas de plus grand\n"
	.string "fan de CENTRES POKéMON que\p"
	.string "{STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "Le DRESSEUR casanier$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "soigné des POKéMON à la maison$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné ses POKéMON\n"
	.string "à la maison {STR_VAR_1} fois!\p"
	.string "Il n’existe pas de DRESSEUR plus\n"
	.string "casanier que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "Le DRESSEUR fan de SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "pénétré dans le PARC SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR est entré dans le\n"
	.string "PARC SAFARI {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "exprime son côté sauvage au PARC\p"
	.string "SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "Le DRESSEUR à la COUPE facile$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "utilisé COUPE$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé COUPE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "adore utiliser COUPE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "Le DRESSEUR ECLATE-ROC$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "éclaté des rochers$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé ECLATE-ROC\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "ne peut pas laisser un rocher\p"
	.string "entier!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "Le DRESSEUR qui aime déménager$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "déplacé ta BASE SECRETE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a déplacé sa BASE\n"
	.string "SECRETE {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "adore déménager!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "Le DRESSEUR fou de TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "utilisé TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé TREMPETTE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "adore faire TREMPETTE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "Le DRESSEUR tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "fini par utiliser LUTTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a dû utiliser LUTTE\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR\n"
	.string "tenace qui n’abandonne jamais\p"
	.string "face à l’adversité!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Le champion des MACHINES A SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "eu le jackpot aux MACHINES A\n"
	.string "SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné le jackpot\n"
	.string "aux MACHINES A SOUS {STR_VAR_1}\p"
	.string "fois.\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "a eu de la chance aux MACHINES A\p"
	.string "SOUS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Le champion de la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "gagné consécutivement à la\n"
	.string "ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la\n"
	.string "ROULETTE {STR_VAR_1} fois de\p"
	.string "suite.\p"
	.string "{STR_VAR_3} a eu beaucoup de\n"
	.string "chance à la ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Le candidat à la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "relevé les défis de la TOUR DE\n"
	.string "COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a relevé les défis\n"
	.string "de la TOUR DE COMBAT {STR_VAR_1}\p"
	.string "fois!\p"
	.string "{STR_VAR_3} est un DRESSEUR\n"
	.string "cherchant à être premier dans la\p"
	.string "TOUR DE COMBAT!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "Le DRESSEUR qui aime mixer$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "fait des {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait des\n"
	.string "{POKEBLOCK}S {STR_VAR_1} fois!\p"
	.string "Personne n’utilise un MIXEUR\n"
	.string "mieux que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "Le DRESSEUR fan de CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "participé à des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a participé à des\n"
	.string "CONCOURS {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} adore exhiber ses\n"
	.string "POKéMON devant un public!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Le maître des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "gagné des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné des CONCOURS\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être\n"
	.string "incroyablement doué pour les\p"
	.string "CONCOURS!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Le joyeux consommateur$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "acheté des objets$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a acheté des objets\n"
	.string "dans un magasin {STR_VAR_1}\p"
	.string "fois!\p"
	.string "{STR_VAR_3} doit être l’un de\n"
	.string "ces DRESSEURS nés pour faire des\p"
	.string "achats.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "Le DRESSEUR chercheur d’objets$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "utilisé un CHERCH’OBJET$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé un\n"
	.string "CHERCH’OBJET {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit aimer sonder le\n"
	.string "sol pour trouver des objets\p"
	.string "cachés!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "Le DRESSEUR trempé jusqu’aux os$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "pris une averse$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a été trempé\n"
	.string "jusqu’aux os par la pluie\p"
	.string "{STR_VAR_1} fois!\p"
	.string "Le charisme de {STR_VAR_3} doit\n"
	.string "même attirer la pluie!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Le lecteur de POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "vérifié ton POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a vérifié son\n"
	.string "POKéDEX {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit adorer en\n"
	.string "apprendre plus sur les POKéMON\p"
	.string "dans son POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Le collectionneur de RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "reçu des RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a reçu des RUBANS\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un\n"
	.string "DRESSEUR qui adore collectionner\p"
	.string "les RUBANS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "Le DRESSEUR qui saute des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "sauté des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauté des talus\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} ne peut pas\n"
	.string "s’empêcher de sauter d’un talus!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Le téléspectateur légendaire$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "regardé la télé$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a regardé la télé\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit adorer regarder\n"
	.string "la télé!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "Le DRESSEUR conscient du temps$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "regardé l’heure$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a regardé l’heure\n"
	.string "{STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un\n"
	.string "DRESSEUR ponctuel, toujours\p"
	.string "conscient du temps.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Le magicien de la LOTERIE\n"
	.string "POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "gagné à la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la LOTERIE\n"
	.string "POKéMON {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit avoir de\n"
	.string "nombreux amis avec qui échanger\p"
	.string "des POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "Le DRESSEUR client de la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "laissé des POKéMON à la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a laissé des POKéMON\n"
	.string "à la PENSION {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un vrai\n"
	.string "battant qui élève ses POKéMON\p"
	.string "avec énergie!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "Le DRESSEUR fan du TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "fait le trajet en TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a pris le\n"
	.string "TELEPHERIQUE {STR_VAR_1} fois!\p"
	.string "{STR_VAR_3} doit être un\n"
	.string "DRESSEUR surmené qui passe son\p"
	.string "temps à voyager!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "Le DRESSEUR fan de sources\n"
	.string "chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "pris un bain dans les sources\n"
	.string "chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Il était une fois un DRESSEUR du\n"
	.string "nom de {STR_VAR_3}.\p"
	.string "Ce DRESSEUR s’est baigné dans\n"
	.string "les sources chaudes {STR_VAR_1}\p"
	.string "fois!\p"
	.string "{STR_VAR_3} doit être un\n"
	.string "DRESSEUR avec une peau de bébé!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Je m’appelle PAPOTEUR! J’ai une\n"
	.string "super histoire à te raconter!\p"
	.string "Tu veux l’écouter?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh… Tu m’as déprimé…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Et puis aussi, je me disais…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Eh bien, c’est tout, je pense…\p"
	.string "On discutera plus tard! Ciao!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Bonjour, je suis CAPELO. Tu veux\n"
	.string "entendre ma chanson?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh… Tu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, quelle chanson émouvante… Je\n"
	.string "voudrais pouvoir la chanter aux\p"
	.string "autres.$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Alors? Qu’est-ce que tu penses\n"
	.string "de ma chanson?\p"
	.string "Mais je ne suis pas très content\n"
	.string "des paroles.\p"
	.string "Ça te plairait d’écrire de\n"
	.string "nouvelles paroles pour moi?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh… Tu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Merci beaucoup! Je vais la\n"
	.string "chanter pour toi.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Tu la voulais bien comme ça, ta\n"
	.string "chanson?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Super! La chanson est finie,\n"
	.string "alors. Je vais la chanter\p"
	.string "pendant longtemps.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Yo, toi! On m’appelle MINET. Je\n"
	.string "vais te montrer ce qui est à la\p"
	.string "mode.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Hé, mais je t’ai déjà montré ce\n"
	.string "qui est à la mode en ce moment.\p"
	.string "Maintenant, j’aimerais prêcher\n"
	.string "la bonne parole aux autres.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Mais, tu sais déjà ce qui est à\n"
	.string "la mode en ce moment.\p"
	.string "Je n’ai rien de nouveau à\n"
	.string "t’apprendre!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hé, t'as entendu parler de\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Qu'est-ce que ça veut dire? Heu…\n"
	.string "T'as qu'à demander à ta maman,\p"
	.string "OK?$"
