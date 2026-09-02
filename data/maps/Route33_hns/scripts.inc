Route33_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY_HNS, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten, Route33_EventScript_RegisterAnthony
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route33_EventScript_RematchAnthony
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_RegisterAnthony::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route33_Text_AnthonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANTHONY_HNS
	release
	end

Route33_EventScript_RematchAnthony::
	trainerbattle_rematch TRAINER_ANTHONY_HNS, Route33_Text_AnthonyRematchIntro, Route33_Text_AnthonyRematchDefeat
	msgbox Route33_Text_AnthonyPostRematch, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "J'ai traversé le tunnel, mais il\n"
	.string "me\p"
	.string "reste encore pas mal d'énergie.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Ah! Il te restait plus d’énergie\n"
	.string "qu’à moi!$"

Route33_Text_HikerAnthony2After:
	.string "Nous, les\n"
	.string "Montagnards, on\p"
	.string "est plein d’énergie\n"
	.string "dans la montagne!$"

Route33_Text_AnthonyRegister:
	.string "Nous, les\n"
	.string "Montagnards, on\p"
	.string "est plein d’énergie\n"
	.string "dans la montagne!$"

Route33_Text_AnthonyRematchIntro:
	.string "J'ai traversé le tunnel, mais il\n"
	.string "me\p"
	.string "reste encore pas mal d'énergie.$"

Route33_Text_AnthonyRematchDefeat:
	.string "Ah! Il te restait plus d’énergie\n"
	.string "qu’à moi!$"

Route33_Text_AnthonyPostRematch:
	.string "Nous, les\n"
	.string "Montagnards, on\p"
	.string "est plein d’énergie\n"
	.string "dans la montagne!$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hé! As-tu chopé un INSOLOURDO?\p"
	.string "Moi ouais.\p"
	.string "Regarde-le bien! Il a une bonne\n"
	.string "bouille, hein?$"

Route33_Text_Lass:
	.string "Pouf, pouf…\p"
	.string "Cette grotte était plus grande\n"
	.string "que prévu.\p"
	.string "J'étais épuisée de chercher\n"
	.string "MARILL, alors je suis sortie.$"
