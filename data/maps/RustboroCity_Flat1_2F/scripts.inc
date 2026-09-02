RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, c’est chaque jour si\n"
	.string "difficile…\p"
	.string "Ce qui est difficile? Tu me le\n"
	.string "demandes?\p"
	.string "Tous les jours, je dois décider\n"
	.string "ce que je vais préparer pour le\p"
	.string "repas.\p"
	.string "C’est vraiment pas facile de\n"
	.string "trouver des idées différentes\p"
	.string "chaque jour.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, bonjour! Bienvenue chez les\n"
	.string "BOFOND.\p"
	.string "J’ai une question à te poser.\n"
	.string "As-tu déjà fait du baby-sitting?\p"
	.string "Tu vois, je viens d’être papa,\n"
	.string "alors élever un enfant est\p"
	.string "quelque chose de nouveau pour\n"
	.string "moi.\p"
	.string "Et j’ai un problème, ma fille\n"
	.string "BERCIA ne rit pas beaucoup.\p"
	.string "Je pense qu’elle rirait plus si\n"
	.string "je lui disais quelque chose\p"
	.string "d’amusant.\p"
	.string "Connaîtrais-tu un mot ou une\n"
	.string "phrase amusante que je pourrais\p"
	.string "lui dire?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Je lui ai déjà dit “{STR_VAR_1}”\n"
	.string "pour la faire rire.\p"
	.string "Connaîtrais-tu une autre phrase\n"
	.string "ou un autre mot qui pourrait la\p"
	.string "faire rire?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, formidable! Alors donne-moi\n"
	.string "ta suggestion.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, vraiment?\p"
	.string "N’hésite pas à me le dire si tu\n"
	.string "as une suggestion.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, je vois. Eh bien, nous\n"
	.string "n’avons plus qu’à essayer.\p"
	.string "D’accord?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "“{STR_VAR_1}” “{STR_VAR_1}”\p"
	.string "Oh oui! Elle rigole! Oh, je suis\n"
	.string "aussi heureux qu’elle!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, je vois. Eh bien, nous\n"
	.string "n’avons plus qu’à essayer.\p"
	.string "D’accord?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "“{STR_VAR_1}” “{STR_VAR_1}”\p"
	.string "Hmmm… Ça n’a pas l’air de\n"
	.string "fonctionner.\p"
	.string "Peut-être que BERCIA est juste\n"
	.string "un bébé trop sérieux…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Tu ne connais pas de bons mots\n"
	.string "alors…  Je vais continuer\p"
	.string "d’essayer.\p"
	.string "Hmm… Et “{STR_VAR_1}”? Voyons si\n"
	.string "ça marche.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "“{STR_VAR_1}” “{STR_VAR_1}”\p"
	.string "Hmmm… Ça n’a pas l’air de\n"
	.string "fonctionner.\p"
	.string "Peut-être que BERCIA est juste\n"
	.string "un bébé trop sérieux…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Tu ne connais pas de bons mots\n"
	.string "alors… Je vais essayer de\p"
	.string "l’amuser avec les mots que\n"
	.string "j’utilisais avant.\p"
	.string "Quoi qu’il en soit, n’hésite pas\n"
	.string "à me le dire si tu as une\p"
	.string "suggestion.$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Merci!\p"
	.string "Grâce à toi, ma petite BERCIA\n"
	.string "m’a montré son sourire!\p"
	.string "Au fait, je ne te l’ai pas dit\n"
	.string "mais je suis chercheur chez\p"
	.string "DEVON.\p"
	.string "Alors que pourrais-je faire en\n"
	.string "retour pour toi?\p"
	.string "Je sais, je vais ajouter de\n"
	.string "nouveaux fonds aux BOITES de\p"
	.string "Gestion de Stocks de POKéMON sur\n"
	.string "ton PC.\p"
	.string "Dans le menu des fonds,\n"
	.string "sélectionne “AMIS”.\p"
	.string "Tu auras alors accès à un\n"
	.string "nouveau fond  chaque fois que tu\p"
	.string "feras rire ma fille.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "C’est une POUPEE POKéMON!$"

