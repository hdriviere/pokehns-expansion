SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKantoMidBattle
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_ExitKantoMidBattle::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#elif IS_HNS
	setvar VAR_SAFARI_ZONE_STATE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#elif IS_HNS
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE_HNS, 9, 3
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_HNS, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Voulez-vous quitter le PARC\n"
	.string "SAFARI tout de suite?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Le temps est écoulé!\n"
	.string "Votre partie de SAFARI est\p"
	.string "terminée.$"

SafariZone_Text_OutOfBalls:
	.string "Vous n’avez plus de SAFARI\n"
	.string "BALLS. Votre partie de SAFARI\p"
	.string "est terminée.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Voulez-vous placer un\n"
	.string "{POKEBLOCK} dans la MANGEOIRE\p"
	.string "{POKEBLOCK}?$"

SafariZone_Text_PokeblockStillHere:
	.string "Le {STR_VAR_1} que vous aviez\n"
	.string "placé là y est encore.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Le {STR_VAR_1} a été placé dans\n"
	.string "la MANGEOIRE {POKEBLOCK}.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Bienvenue au PARC SAFARI!\p"
	.string "Vous pourrez y observer de nombreuses\n"
	.string "espèces de POKéMON rarement vues\p"
	.string "dans cette région, à l'état sauvage,\n"
	.string "dans leur habitat naturel.\p"
	.string "Nous avons également ouvert nos\n"
	.string "portes aux DRESSEURS de POKéMON.\p"
	.string "N'hésitez pas à capturer des POKéMON\n"
	.string "pour les garder!\p"
	.string "Entrez et profitez du PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Bienvenue au PARC SAFARI! C’est\n"
	.string "la première fois que vous venez?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Entrez et amusez-vous au PARC\n"
	.string "SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Lorsque vous entrez dans le PARC\n"
	.string "SAFARI, vous recevez 30 SAFARI\p"
	.string "BALLS pour attraper des POKéMON.\p"
	.string "La partie de SAFARI se termine\n"
	.string "lorsque vous n’avez plus de\p"
	.string "SAFARI BALLS ou lorsque vous\n"
	.string "avez parcouru 500 pas.\p"
	.string "Entrez et amusez-vous au PARC\n"
	.string "SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Bienvenue au PARC SAFARI!\p"
	.string "Attrapez un max de POKéMON pour\n"
	.string "500¥! Voulez-vous faire un\p"
	.string "SAFARI?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "D’accord. Revenez nous voir une\n"
	.string "autre fois!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Vous n’avez pas assez d’argent.\n"
	.string "Désolé.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Cela fera 500¥, s’il vous plaît.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Voici vos SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} reçoit 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Nous vous préviendrons quand\n"
	.string "votre SAFARI sera terminé.\p"
	.string "En attendant, amusez-vous bien!\n"
	.string "Profitez de votre équipée\p"
	.string "sauvage!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Je regrette! La BOITE de votre\n"
	.string "PC est pleine.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Excusez-moi!\n"
	.string "Vous n'avez pas de BOITE {POKEBLOCK}S.\p"
	.string "Votre Safari sera bien plus fructueux\n"
	.string "si vous utilisez des {POKEBLOCK}S.\p"
	.string "Revenez avec une BOITE {POKEBLOCK}S.\p"
	.string "Vous pouvez en obtenir une auprès de\n"
#if IS_HNS
	.string "ce garçon, juste là-bas.$"
#else
	.string "la SALLE DE CONCOURS de NENUCRIQUE.$"
#endif

SafariZone_South_Text_StillHaveTimeExit:
	.string "Votre temps n’est pas encore\n"
	.string "écoulé. Voulez-vous quitter le\p"
	.string "PARC SAFARI?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Amusez-vous bien et profitez de\n"
	.string "votre équipée sauvage!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Bien.\p"
	.string "Je vais reprendre vos SAFARI\n"
	.string "BALLS restantes.\p"
	.string "Merci d’avoir joué. Nous\n"
	.string "espérons vous revoir bientôt.$"

SafariZone_South_Text_GoodLuck:
	.string "Bonne chance!\p"
	.string "Si vous avez besoin de quoi que\n"
	.string "ce soit, n’hésitez pas à venir\p"
	.string "me voir!$"

SafariZone_South_Text_Boy:
	.string "Le savais-tu?\p"
	.string "Si tu mets un {POKEBLOCK} dans\n"
	.string "cette boîte carrée, les POKéMON\p"
	.string "tourneront autour.$"

SafariZone_South_Text_Man:
	.string "J’aimerais bien continuer plus\n"
	.string "loin, mais j’ai oublié\p"
	.string "d’apporter un VELO.\p"
	.string "Quelque chose me dit que des\n"
	.string "POKéMON rares vivent dans les\p"
	.string "zones reculées.$"

SafariZone_Southwest_Text_Woman:
	.string "Parfois, j’envoie un {POKEBLOCK}\n"
	.string "à un POKéMON, mais il l’ignore.\p"
	.string "Est-ce que les POKéMON ont des\n"
	.string "préférences en matière de\p"
	.string "nourriture?$"

SafariZone_Northwest_Text_Man:
	.string "Pfou… Pfou… Je… J’ai réussi à\n"
	.string "venir jusqu’ici, mais…\p"
	.string "Je suis épuisé… Je n’ai plus la\n"
	.string "force d’attraper des POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "J’ai pour mission de trouver des\n"
	.string "POKéMON EAU introuvables à\p"
	.string "HOENN.\p"
	.string "Tu sais où se trouve le lac?$"

SafariZone_North_Text_Man:
	.string "Je vais attraper plein de\n"
	.string "POKéMON rares ici et je les\p"
	.string "échangerai avec mes amis!$"

SafariZone_South_Text_Youngster:
	.string "J'ai mis un {POKEBLOCK} dans la\n"
	.string "MANGEOIRE, mais il a disparu.\p"
	.string "Un POKéMON a dû le manger sans que\n"
	.string "je m'en aperçoive.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "PARC SAFARI - CONSEIL AUX\n"
	.string "DRESSEURS!\p"
	.string "Lancez des {POKEBLOCK}S aux\n"
	.string "POKéMON sauvages pour éviter\p"
	.string "qu’ils s’enfuient.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Reposez vos jambes fatiguées.”\n"
	.string "REFUGE$"

SafariZone_RestHouse_Text_Youngster:
	.string "Je n’ai pas de {POKEBLOCK}, mais\n"
	.string "j’ai quand même attrapé beaucoup\p"
	.string "de POKéMON.\p"
	.string "Tu peux augmenter tes chances\n"
	.string "d’attraper un POKéMON en\p"
	.string "t’approchant avant de jeter une\n"
	.string "SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Si tu leur donnes des\n"
	.string "{POKEBLOCK}S, les POKéMON\p"
	.string "s’enfuient moins vite.\p"
	.string "Ça ne sert pas à grand-chose de\n"
	.string "donner des {POKEBLOCK}S aux\p"
	.string "POKéMON qui ne sont pas\n"
	.string "farouches.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Si tu mets un {POKEBLOCK} dans\n"
	.string "la MANGEOIRE, ça attirera les\p"
	.string "POKéMON.\p"
	.string "Je crois que certains types de\n"
	.string "POKéMON sont attirés par\p"
	.string "certains {POKEBLOCK}S.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Cette zone est encore en\n"
	.string "construction. Vous ne pouvez pas\p"
	.string "entrer, désolé!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Les travaux d’agrandissement du\n"
	.string "PARC SAFARI sont terminés.\p"
	.string "Nous espérons que la nouvelle\n"
	.string "zone vous apportera entière\p"
	.string "satisfaction.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Cette zone est encore en\n"
	.string "construction. Vous ne pouvez pas\p"
	.string "entrer, désolé!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Waouh! Délire! C’est la première\n"
	.string "fois que je vois ce genre de\p"
	.string "POKéMON!$"

SafariZone_Southeast_Text_FatMan:
	.string "Je n’avais jamais vu aucun des\n"
	.string "POKéMON de cette zone.\p"
	.string "Et j’ai le droit d’attraper tous\n"
	.string "ces POKéMON rares? Trop cool!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Je ne pense pas que les POKéMON\n"
	.string "qui se trouvent ici soient de\p"
	.string "HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Il ne me reste que quelques\n"
	.string "SAFARI BALLS.\p"
	.string "J’ai du mal à décider ce que je\n"
	.string "dois attraper.$"

SafariZone_Northeast_Text_Woman:
	.string "On dit qu’il y a des PIKACHU\n"
	.string "ici. Je me demande bien où ils\p"
	.string "se cachent.$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, bouh! Je n’arrive à rien\n"
	.string "ici!\p"
	.string "J’ai payé l’entrée, il faut\n"
	.string "absolument que j’attrape quelque\p"
	.string "chose!$"
