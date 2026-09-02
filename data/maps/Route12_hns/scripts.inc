Route12_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN_HNS, Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN_HNS, Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_HNS, Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE_HNS, Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten, Route12_EventScript_RegisterKyle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_RematchKyle
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RegisterKyle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_KyleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLE_HNS
	release
	end

Route12_EventScript_RematchKyle::
	trainerbattle_rematch TRAINER_KYLE_HNS, Route12_Text_KyleRematchIntro, Route12_Text_KyleRematchDefeat
	msgbox Route12_Text_KylePostRematch, MSGBOX_AUTOCLOSE
	goto_if_defeated TRAINER_KYLE_2_HNS, Route12_EventScript_RematchKyleTryGiveItem
	end

Route12_EventScript_RematchKyleTryGiveItem::
	checkitem ITEM_BLUE_SHARD
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NoOp
	giveitem ITEM_BLUE_SHARD
	closemessage
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_NewFisher:
	.string "Attention, une bête féroce vit\n"
	.string "dans ces eaux.$"

Route12_Text_FisherMartinSeen:
	.string "Il faut de la patience\n"
	.string "pour pêcher. Il\p"
	.string "faut de la patience\n"
	.string "pour les Pokémon.$"

Route12_Text_FisherMartinBeaten:
	.string "Gwaaah!$"

Route12_Text_FisherMartinAfterBattle:
	.string "Finalement, la\n"
	.string "pêche, c’est pas\p"
	.string "pour moi! Je manque\n"
	.string "de patience...$"

Route12_Text_FisherStephenSeen:
	.string "C’est génial de pêcher en\n"
	.string "écoutant la radio.$"

Route12_Text_FisherStephenBeaten:
	.string "Ma radio m'a fait perdre!$"

Route12_Text_FisherStephenAfterBattle:
	.string "Quand on écoute\n"
	.string "la radio de Johto\p"
	.string "depuis Kanto,\n"
	.string "il y a plein de\p"
	.string "programmes locaux.\p"
	.string "Ils sont plein d’attentions pour\n"
	.string "leurs auditeurs!$"

Route12_Text_FisherBarneySeen:
	.string "Quelle est la\n"
	.string "chose la plus\p"
	.string "importante dans nos\n"
	.string "vies quotidiennes?$"

Route12_Text_FisherBarneyBeaten:
	.string "La réponse va suivre!$"

Route12_Text_FisherBarneyAfterBattle:
	.string "Je crois que l'électricité est\p"
	.string "la chose la plus importante.\p"
	.string "Et c'est pour ça qu'on a fait\n"
	.string "tant\p"
	.string "d'histoires à propos de la panne\n"
	.string "de la CENTRALE.$"

Route12_Text_KyleRegister:
	.string "Je m'en souviendrai.\n"
	.string "Donne-moi ton numéro!$"

Route12_Text_KyleRematchIntro:
	.string "Tu as oublié?\n"
	.string "Voyons ça!$"

Route12_Text_KyleRematchDefeat:
	.string "Tu t'en es souvenu.$"

Route12_Text_KylePostRematch:
	.string "Combattre procure presque autant\n"
	.string "de frissons qu'une grosse prise!$"

Route12_Text_FisherKyleSeen:
	.string "Tu t'en souviens?$"

Route12_Text_FisherKyleBeaten:
	.string "Tu t'en souviens?$"

Route12_Text_FisherKyleAfterBattle:
	.string "La p'tite secousse que l'on sent\p"
	.string "quand on ferre un Pokémon...\p"
	.string "C'est la plus belle des\n"
	.string "sensations!!!$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "ROUTE 12 NORD: LAVANVILLE$"

Route12_Text_FishingSpotSign:
	.string "COIN PECHE$"
