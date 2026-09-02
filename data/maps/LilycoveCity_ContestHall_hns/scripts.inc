@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_hns_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1_hns::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2_hns::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl_hns::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor_hns::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1_hns::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1_hns::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear_hns, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3_hns::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign_hns::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage_hns, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest_hns:
	.string "Ce POKéMON a déjà gagné le\n"
	.string "CONCOURS DE BEAUTE ici.\p"
	.string "Et tu sais quoi? Je lui ai fait\n"
	.string "gagner le CONCOURS\p"
	.string "D’INTELLIGENCE, aujourd’hui!\p"
	.string "Je m’effraie moi-même…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests_hns:
	.string "J’ai fait pas mal de CONCOURS,\n"
	.string "donc je sais comment ça se\p"
	.string "passe.\p"
	.string "Dans un CONCOURS DE SANG-FROID,\n"
	.string "les capacités SANG-FROID ont du\p"
	.string "succès.\p"
	.string "Mais les capacités INTELLIGENCE\n"
	.string "et GRACE, par exemple, n’ont pas\p"
	.string "trop d’effet.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks_hns:
	.string "Le jeune garçon qui vient de\n"
	.string "gagner avait plein de\p"
	.string "{POKEBLOCK}S différents.\p"
	.string "Tu gagnerais, toi, si t’en avais\n"
	.string "autant?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous_hns:
	.string "Waouh, cet endroit est super!\p"
	.string "On peut sentir la tension dans\n"
	.string "l’air… Ça, c’est un vrai lieu de\p"
	.string "CONCOURS.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal_hns:
	.string "ANIMATRICE: POKéMON INTELLIGENTS\n"
	.string "et leurs DRESSEURS, vous êtes\p"
	.string "prêts?!\p"
	.string "Montrez-vous sous votre meilleur\n"
	.string "jour! C’est parti!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest_hns:
	.string "JUGE: Vous aimez ce genre de\n"
	.string "CONCOURS?\p"
	.string "Revenez avec trois amis et vous\n"
	.string "pourrez tous participer à un\p"
	.string "CONCOURS!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest_hns:
	.string "Aïe, aïe, aïe… Je me suis trompé\n"
	.string "de CONCOURS.\p"
	.string "J’ai inscrit ce POKéMON ROBUSTE\n"
	.string "à un CONCOURS D’INTELLIGENCE…\p"
	.string "Allez, montre-leur ton\n"
	.string "ECLATE-ROC.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart_hns:
	.string "Cela m’a pris des années et\n"
	.string "beaucoup de sagesse, pour que ce\p"
	.string "POKéMON devienne aussi\n"
	.string "intelligent.\p"
	.string "Il ne se laisse pas battre par\n"
	.string "n’importe quel POKéMON\p"
	.string "inexpérimenté.$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext_hns:
	.string "Voilà!\p"
	.string "Une capacité INTELLIGENCE\n"
	.string "maintenant, et l’enthousiasme du\p"
	.string "public augmentera!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife_hns:
	.string "Oh, non!\p"
	.string "J’utilise tout le temps le\n"
	.string "VAMPIRISME de mon NOSFERAPTI, il\p"
	.string "est si gracieux!\p"
	.string "Mais ces gens sont méchants et\n"
	.string "n’apprécient pas du tout!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa_hns:
	.string "Ouais! T’es super, pépé!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves_hns:
	.string "Même quand les DRESSEURS\n"
	.string "inscrivent le même genre de\p"
	.string "POKéMON, ils semblent utiliser\n"
	.string "des capacités différentes.\p"
	.string "C’est comme pour les combats,\n"
	.string "chacun a son propre style.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers_hns:
	.string "Je trouve que les POKéMON ont\n"
	.string "l’air bien plus intelligents que\p"
	.string "leurs DRESSEURS.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests_hns:
	.string "Par-dessus tout, j’adore les\n"
	.string "CONCOURS D’INTELLIGENCE.\p"
	.string "Cette couleur verte si\n"
	.string "intellectuelle… C’est… super\p"
	.string "cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest_hns:
	.string "ANIMATRICE: Tu vas aussi\n"
	.string "participer au CONCOURS DE\p"
	.string "BEAUTE? Bonne chance!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty_hns:
	.string "JUGE: Ah, les POKéMON ici\n"
	.string "présents sont des spécimens\p"
	.string "d’une rare beauté!\p"
	.string "Oh, j’en ai presque oublié de\n"
	.string "les noter!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty_hns:
	.string "Un POKéMON de cette\n"
	.string "magnificence… Il n’y en a pas\p"
	.string "deux comme ça.\p"
	.string "Tout le monde sera subjugué par\n"
	.string "tant de beauté.$"

LilycoveCity_ContestHall_Text_OverdidGrooming_hns:
	.string "Ahhhhh!\p"
	.string "J’ai brossé et coiffé mon\n"
	.string "POKéMON avec soin pour ce\p"
	.string "CONCOURS…\p"
	.string "Mais j’ai exagéré… Maintenant,\n"
	.string "il a le poil tout ébouriffé…\p"
	.string "Qu’est-ce que je peux faire?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam_hns:
	.string "Cette ONDE BOREALE est si\n"
	.string "éblouissante que le JUGE ne\p"
	.string "pourra pas la voir.\p"
	.string "Euh, attends… Mais ça sert à\n"
	.string "rien, alors!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe_hns:
	.string "Ce joli POKéMON, c’est\n"
	.string "exactement moi quand j’étais\p"
	.string "plus jeune.\p"
	.string "Juste au moment où je l’ai dit,\n"
	.string "mon mari s’est étouffé avec son\p"
	.string "café.\p"
	.string "J’ai dit quelque chose\n"
	.string "d’amusant?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy_hns:
	.string "Tu sais, en tant que femme, je\n"
	.string "serais plus qu’heureuse de\p"
	.string "gagner un CONCOURS DE BEAUTE.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon_hns:
	.string "Waouhhhh!\p"
	.string "Tu devrais jeter un coup d’œil à\n"
	.string "ces jolis POKéMON.\p"
	.string "Quelle splendeur! J’adore!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone_hns:
	.string "Tu ne peux pas toujours compter\n"
	.string "sur la beauté uniquement.\p"
	.string "Tu dois aussi coiffer ton\n"
	.string "POKéMON, pour qu’il soit aussi\p"
	.string "brillant que le mien.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest_hns:
	.string "ANIMATRICE: Hum! Ohé! On est en\n"
	.string "plein CONCOURS!\p"
	.string "Veuillez vous inscrire au\n"
	.string "guichet et revenez ensuite, vous\p"
	.string "voulez bien?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals_hns:
	.string "JUGE: Oh, quelles démonstrations\n"
	.string "ravissantes et gracieuses!\p"
	.string "Juste ciel! Quelle parfaite et\n"
	.string "adorable démonstration de\p"
	.string "TOURNIQUET!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted_hns:
	.string "Oh, non… Mon doux AZURILL s’est\n"
	.string "laissé distraire par un autre\p"
	.string "POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest_hns:
	.string "Mon POKéMON ne gagne jamais de\n"
	.string "combat, mais en CONCOURS, c’est\p"
	.string "le meilleur!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel_hns:
	.string "La DANSE-FLEUR de mon POKéMON\n"
	.string "est une merveille d’élégance.\p"
	.string "Je ne laisserai personne\n"
	.string "perturber sa prestation.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter_hns:
	.string "Tous les POKéMON sont gracieux.\p"
	.string "Mais si mon POKéMON faisait une\n"
	.string "démonstration de grâce…\p"
	.string "Je suis sûre qu’il serait\n"
	.string "beaucoup plus gracieux que les\p"
	.string "autres.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest_hns:
	.string "Mon enfant participe au\n"
	.string "CONCOURS.$"

LilycoveCity_ContestHall_Text_ComeOnDear_hns:
	.string "Vas-y, courage! Ton POKéMON est\n"
	.string "le meilleur!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest_hns:
	.string "Je trouve que cette fille est\n"
	.string "vraiment la plus gracieuse.\p"
	.string "Comment? Ils jugent les POKéMON\n"
	.string "sur leur apparence?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn_hns:
	.string "Oh, regarder tous ces gracieux\n"
	.string "POKéMON me donne envie d’en\p"
	.string "avoir un!\p"
	.string "Je vais aller en attraper\n"
	.string "quelques-uns!$"

LilycoveCity_ContestHall_Text_BeautyContestStage_hns:
	.string "EPREUVE DE BEAUTE POKéMON D’UNE\n"
	.string "BEAUTE EPOUSTOUFLANTE!$"

LilycoveCity_ContestHall_Text_CuteContestStage_hns:
	.string "EPREUVE DE GRACE POKéMON D’UNE\n"
	.string "GRACE EXTREME!$"

LilycoveCity_ContestHall_Text_SmartContestStage_hns:
	.string "EPREUVE D’INTELLIGENCE POKéMON\n"
	.string "D’UNE INTELLIGENCE INOUIE!$"

