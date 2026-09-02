Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "J'ai appris plein de trucs sur\n"
	.string "les\p"
	.string "Pokémon à la radio. Tu vas voir!$"

Route35_Text_CamperIvanBeaten:
	.string "Perdu!$"

Route35_Text_CamperIvanAfter:
	.string "La musique de la radio fait\n"
	.string "réagir les Pokémon sauvages.$"

Route35_Text_CamperElliotSeen:
	.string "J'vais montrer à ma copine que\n"
	.string "je suis un vrai dur!$"

Route35_Text_CamperElliotBeaten:
	.string "T'aurais pu perdre pour me faire\n"
	.string "plaisir...$"

Route35_Text_CamperElliotAfter:
	.string "Tu m'as fichu la honte devant ma\n"
	.string "copine...$"

Route35_Text_PicnickerBrookeSeen:
	.string "Mon copain est trop nul! J'ai la\n"
	.string "super honte!$"

Route35_Text_PicnickerBrookeBeaten:
	.string "Oh! Mazette!$"

Route35_Text_PicnickerBrookeAfter:
	.string "Je préfère mes Pokémon à mon\n"
	.string "copain.$"

Route35_Text_PicnickerKimSeen:
	.string "Tu vas à l'ARENE? Moi aussi!$"

Route35_Text_PicnickerKimBeaten:
	.string "J'ai aucune chance...$"

Route35_Text_PicnickerKimAfter:
	.string "Je collectionne les Badges\n"
	.string "d’Arène parce qu’ils sont jolis.$"

Route35_Text_BirdKeeperBryanSeen:
	.string "Quelles Poké BALLS utilises-tu?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "Whoa! J’suis pas assez rapide!$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Certains Pokémon s'enfuient\n"
	.string "aussitôt.\p"
	.string "Essaie de les attraper avec une\n"
	.string "RAPIDE BALL de FARGAS.\p"
	.string "Chaque fois que je trouve\n"
	.string "une BAIE WILLIA, je l'apporte\l"
	.string "à FARGAS.\p"
	.string "Il en fait une BALL spéciale.$"

Route35_Text_JugglerIrwinSeen:
	.string "Regarde comme je lance bien mes\n"
	.string "BALLS!$"

Route35_Text_JugglerIrwinBeaten:
	.string "J’ai une crampe...$"

Route35_Text_JugglerIrwinAfter:
	.string "J'allais t'éblouir avec mon\n"
	.string "nouveau Pokémon...\p"
	.string "Mais tu es trop rapide!$"

Route35_Text_BugCatcherArnieSeen:
	.string "Moi, mon truc, c’est les Pokémon\n"
	.string "Insecte.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "Hein? Je n'aurais pas dû\n"
	.string "perdre...$"

Route35_Text_BugCatcherArnieAfter:
	.string "J’ai gagné mon\n"
	.string "précieux MIMITOSS\p"
	.string "au Concours de\n"
	.string "Capture d’insecte au\p"
	.string "Parc Naturel.$"

Route35_Text_IrwinRegister:
	.string "J'allais t'éblouir avec mon\n"
	.string "nouveau Pokémon...\p"
	.string "Mais tu es trop rapide!$"

Route35_Text_ArnieRegister:
	.string "J’ai gagné mon\n"
	.string "précieux MIMITOSS\p"
	.string "au Concours de\n"
	.string "Capture d’insecte au\p"
	.string "Parc Naturel.$"

Route35_Text_ArnieRematchIntro:
	.string "Moi, mon truc, c’est les Pokémon\n"
	.string "Insecte.$"

Route35_Text_ArnieRematchDefeat:
	.string "Hein? Je n'aurais pas dû\n"
	.string "perdre...$"

Route35_Text_ArniePostRematch:
	.string "J’ai gagné mon\n"
	.string "précieux MIMITOSS\p"
	.string "au Concours de\n"
	.string "Capture d’insecte au\p"
	.string "Parc Naturel.$"

Route35_Text_BugCatcherArnieYanma:
	.string "Woah! Regarde ces YANMA!\p"
	.string "J'en suis baba!$"

Route35_Text_FirebreatherWaltSeen:
	.string "Je vais m’entraîner à cracher du\n"
	.string "feu!$"

Route35_Text_FirebreatherWaltBeaten:
	.string "Tu m'as cramé!$"

Route35_Text_FirebreatherWaltAfter:
	.string "La fanfare Pokémon à la radio\n"
	.string "attire les Pokémon sauvages.$"

Route35_Text_OfficerDirkSeen:
	.string "La nuit, le danger rôde!$"

Route35_Text_OfficerDirkBeaten:
	.string "Gnyaaaah!$"

Route35_Text_OfficerDirkAfter:
	.string "C'est marrant de se balader la\n"
	.string "nuit tombée.\p"
	.string "Mais ça fait un peu peur, non?$"

Route35_Text_OfficerDirkTough:
	.string "Ton Pokémon a l’air fort! Il te\n"
	.string "protégera où que tu ailles!$"

Route35_Text_Sign:
	.string "ROUTE 35$"

Route35_Text_Sign2:
	.string "ENTRÉE DU PARC NATUREL$"
