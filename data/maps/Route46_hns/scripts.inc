Route46_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY_HNS, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED_HNS, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN_HNS, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten, Route46_EventScript_RegisterErin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route46_EventScript_RematchErin
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_RegisterErin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route46_Text_ErinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ERIN_HNS
	release
	end

Route46_EventScript_RematchErin::
	trainerbattle_rematch TRAINER_ERIN_HNS, Route46_Text_ErinRematchIntro, Route46_Text_ErinRematchDefeat
	msgbox Route46_Text_ErinPostRematch, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "Je vais t'montrer la force des\n"
	.string "Pokémon de montagne!$"

Route46_Text_HikerBaileyBeaten:
	.string "Mince! Tu m’as montré ta force!$"

Route46_Text_HikerBaileyAfterBattle:
	.string "Pas grave si c’est\n"
	.string "déjà terminé.\p"
	.string "C’est l’esprit des\n"
	.string "Montagnards, ça!$"

Route46_Text_CamperTedSeen:
	.string "Moi aussi j'ai des Pokémon!\p"
	.string "Ca te dit un bon combat?$"

Route46_Text_CamperTedBeaten:
	.string "Hein...?$"

Route46_Text_CamperTedAfterBattle:
	.string "J'ai fait de mon mieux...\p"
	.string "J'suis pas fort. Tant pis.$"

Route46_Text_PicnickerErinSeen:
	.string "J'ai des Pokémon moi z'aussi!\p"
	.string "On se fritte la tête?$"

Route46_Text_PicnickerErinBeaten:
	.string "Oh, ben mince!$"

Route46_Text_PicnickerErinAfterBattle:
	.string "Je connais toutes les ARENES\n"
	.string "mais ma\p"
	.string "préférée c'est celle de\n"
	.string "DOUBLONVILLE.\p"
	.string "Y'a tout plein de zolies fleurs!$"

Route46_Text_ErinRegister:
	.string "Je connais toutes les ARENES\n"
	.string "mais ma\p"
	.string "préférée c'est celle de\n"
	.string "DOUBLONVILLE.\p"
	.string "Y'a tout plein de zolies fleurs!$"

Route46_Text_ErinRematchIntro:
	.string "J'ai des Pokémon moi z'aussi!\p"
	.string "On se fritte la tête?$"

Route46_Text_ErinRematchDefeat:
	.string "Oh, ben mince!$"

Route46_Text_ErinPostRematch:
	.string "Je connais toutes les ARENES\n"
	.string "mais ma\p"
	.string "préférée c'est celle de\n"
	.string "DOUBLONVILLE.\p"
	.string "Y'a tout plein de zolies fleurs!$"

Route46_Text_PicnickerErin2Beaten:
	.string "Pfff... Je perds tout le temps!\p"
	.string "Y faut que je m'entraîne!\p"
	.string "Merci quand même. Voilà le\n"
	.string "cadeau de la dernière fois.$"

Route46_Text_Sign:
	.string "ROUTE 46 CHEMIN de MONTAGNE$"
