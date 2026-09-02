Route37_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE_HNS, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG_HNS, Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "TEA: LEA et moi sommes\n"
	.string "inséparables!$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "TEA&LEA: ... Pas possible.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "TEA: Je pense comme ma soeur et\p"
	.string "comme mes Pokémon.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "LEA: TEA et moi sommes\n"
	.string "inséparables!$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "TEA&LEA: ... Pas possible.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "LEA: Nous ressentons les mêmes\n"
	.string "choses que nos Pokémon.$"

Route37_Text_PsychicGreg_Seen:
	.string "Les Pokémon endormis ne peuvent\n"
	.string "plus rien faire.\p"
	.string "Tu vas voir quel effet ça fait!$"

Route37_Text_PsychicGreg_Beaten:
	.string "Perdu. C'est pas cool, ça...$"

Route37_Text_PsychicGreg_After:
	.string "Endormir ou\n"
	.string "paralyser les\p"
	.string "Pokémon est super\n"
	.string "utile en combat.$"

Route37_Text_Sunny_Meet:
	.string "DIMITRI: Salut!\p"
	.string "Moi, c'est DIMITRI de la fratrie\n"
	.string "des jours de la semaine!\p"
	.string "Devine mon jour préféré et je te\n"
	.string "donnerai une récompense.$"

Route37_Text_Sunny_GiveGift1:
	.string "On m'a dit de te donner ça!$"

Route37_Text_Sunny_GiveGift2:
	.string "On m'a dit de te donner ça!$"

Route37_Text_Sunny_GaveGift:
	.string "DIMITRI: Ca...\p"
	.string "Heu...\p"
	.string "...C'est...\p"
	.string "...\p"
	.string "Oh! Je me  souviens!\p"
	.string "C'est pour un Pokémon à\n"
	.string "capacités électriques.\p"
	.string "Ma soeur LUCIE dit que ça les\n"
	.string "améliore!$"

Route37_Text_Sunny_Sunday:
	.string "DIMITRI: Mes frères\n"
	.string "et soeurs sont LUCIE,\p"
	.string "MARIE, HOMER, JEROME,\n"
	.string "VANESSA et SAMUEL.\p"
	.string "Ils sont tous plus vieux que\n"
	.string "moi!$"

Route37_Text_Sunny_NotSunday:
	.string "DIMITRI: On est pas dimanche?\n"
	.string "Heu! Je sais plus!$"

Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ROSALIA DROIT DEVANT$"
