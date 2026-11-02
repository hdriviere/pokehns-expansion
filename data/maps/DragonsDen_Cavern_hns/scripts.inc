DragonsDen_Cavern_hns_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}… Te voilà.\p"
	.string "Si tu penses pouvoir me suivre,\n"
	.string "retrouve-moi au DOJO de\l"
	.string "SAFRANIA.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock
	setflag FLAG_TEMP_HIDE_FOLLOWER 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	call DragonsDen_Cavern_EventScript_Clair
	applymovement OBJ_EVENT_ID_PLAYER, DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY_HNS
	releaseall
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	playbgm MUS_HG_CLAIR, FALSE
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_DRAGONSDEN2_CLAIR
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_Clair_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_PULSE
	msgbox DragonsDen_Cavern_Text_Clair_ExplainTM, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeftPLAYER:
	walk_fast_down
	face_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_Clair_GiveTM:
    .string "SANDRA: ATTENDS!\p"
	.string "Je regrette ce qui s'est passé.\n"
    .string "Tiens, accepte ceci en guise\l"
	.string "d'excuses.$"

DragonsDen_Cavern_Text_Clair_ExplainTM:
    .string "DRACO-CHOC, c'est une sorte de…\n"
	.string "Enfin, peu importe!\p"
	.string "C'est une immense décharge\n"
	.string "d'énergie.\p"
	.string "Si tu n'en veux pas, rien ne\n"
	.string "t'oblige à la prendre.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "Qu'y a-t-il? Tu ne vas pas à\n"
    .string "la LIGUE POKéMON?\p"
    .string "Une fois MAÎTRE, tu pourras\n"
    .string "affronter de nouveau tous les\l"
    .string "CHAMPIONS d'ARÈNE de ton choix.\p"
    .string "Va donc à la LIGUE POKéMON.\p"
    .string "Tu sais comment t'y rendre?\p"
    .string "D'ici, va au BOURG GEON.\p"
    .string "Puis utilise SURF vers l'est,\n"
    .string "en direction de la LIGUE.\p"
    .string "La route est très difficile.\p"
    .string "Ne t'avise pas de perdre à la\n"
    .string "LIGUE POKéMON!\p"
    .string "Sinon, ma défaite contre toi\n"
    .string "me pèsera encore davantage!\p"
    .string "Donne tout ce que tu as.$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN_HNS, DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA_HNS, DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA_HNS, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "AUTEL DRAGON\p"
    .string "En l'honneur des\n"
    .string "Pokémon dragons\p"
    .string "ayant vécu dans\n"
    .string "l'ANTRE du DRAGON.$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "...... Quoi? {PLAYER}?\p"
    .string "...Non, je ne me battrai pas\n"
    .string "avec toi maintenant...\p"
    .string "Mes Pokémon ne sont pas prêts.\p"
    .string "Et je ne veux pas les pousser.\p"
    .string "Je dois être sage pour devenir\n"
    .string "un\p"
    .string "jour le plus grand des\n"
    .string "dresseurs...$"

DragonsDen_Cavern_Text_SilverTraining2:
    .string ".......\p"
    .string "Pffouiii...\p"
    .string "Ne croise plus jamais ma\n"
    .string "route...$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "Toi! Tu n’as pas le droit\n"
    .string "d’entrer ici!$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "Quelle puissance!$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "Le TEMPLE est la demeure de\n"
    .string "notre\p"
    .string "MAITRE, chef du clan des\n"
    .string "dragons.\p"
    .string "Tu n'as pas le droit d'entrer!$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "Tu n’as rien à faire ici!$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "Inconcevable!$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "Je vais bientôt avoir l'accord\n"
    .string "du\p"
    .string "MAITRE pour utiliser des\n"
    .string "dragons.\p"
    .string "Et alors, je pourrai rendre mon\p"
    .string "MAITRE fier en devenant un grand\p"
    .string "dresseur.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "C'est un étranger que l'on ne\n"
    .string "connaît pas.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "Ouille.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "J’ai eu l’impression de\n"
    .string "combattre Peter.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "Qui es-tu?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "Pas sympa.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "On va le dire! Le Maître ne sera\n"
    .string "pas content!$"
