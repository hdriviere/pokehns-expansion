PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Humm… Rien du tout…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Salut! T’aurais pas vu un\n"
	.string "POKéMON appelé BALIGNON dans le\p"
	.string "coin?\p"
	.string "J’aime beaucoup ce POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Je voulais te piéger, mais ça\n"
	.string "fait une éternité que tu traînes\p"
	.string "dans le BOIS CLEMENTI!\p"
	.string "Ras l’bol d’attendre! Alors me\n"
	.string "voilà!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Toi! Le CHERCHEUR DE DEVON!\p"
	.string "Donne-moi ces papiers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Oh, hé!\p"
	.string "Tu es un DRESSEUR de POKéMON,\n"
	.string "non? Il faut que tu m’aides.\p"
	.string "S’il te plaît!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hum? Tu penses faire quoi?\n"
	.string "Comment! Tu vas le défendre?\p"
	.string "La TEAM AQUA n’a jamais de pitié\n"
	.string "pour ses ennemis. Pas même pour\p"
	.string "un enfant!\p"
	.string "Viens te battre!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Tu m’as bluffé! Quelle force!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Tu as eu le culot de\n"
	.string "t’opposer à la TEAM AQUA!\p"
	.string "Viens et affronte-moi de\n"
	.string "nouveau!\p"
	.string "C’est ce que j’aurais aimé te\n"
	.string "dire, mais je suis à court de\p"
	.string "POKéMON…\p"
	.string "Et en plus, nous, la TEAM AQUA,\n"
	.string "on a quelque chose à faire à\p"
	.string "MEROUVILLE.\p"
	.string "Ça va pour aujourd’hui. J’te\n"
	.string "laisse filer!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ouf… Il s’en est fallu de peu!\p"
	.string "Grâce à toi, il ne m’a pas volé\n"
	.string "ces importants papiers.\p"
	.string "Je sais! Pour te remercier, je\n"
	.string "vais te donner cette SUPER BALL.$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Cette brute de la TEAM AQUA\n"
	.string "n’a-t-elle pas dit qu’ils\p"
	.string "avaient quelque chose à faire à\n"
	.string "MEROUVILLE?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh là là! C’est une catastrophe!\n"
	.string "Je n’ai pas de temps à perdre!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Tu croules sous les objets. Je\n"
	.string "ne peux pas te donner cette\p"
	.string "SUPER BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "J’ai attrapé tout un tas de\n"
	.string "POKéMON!\p"
	.string "Allez, allez, allez! Mon équipe\n"
	.string "de POKéMON INSECTE!$"

PetalburgWoods_Text_ICouldntWin:
	.string "J’avais tous ces POKéMON et je\n"
	.string "n’ai même pas gagné…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "J’ai attrapé tout un tas de\n"
	.string "POKéMON. Maintenant, je n’ai\p"
	.string "plus de POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Si t’emmènes des POKéMON INSECTE\n"
	.string "à l’école, t’es tout de suite\p"
	.string "populaire!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Je n’peux pas être populaire si\n"
	.string "je perds.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Quand tu as un gros POKéMON\n"
	.string "INSECTE, les gens te respectent.$"

PetalburgWoods_Text_IWantRematch1:
	.string "J’aurai ma revanche dès que mes\n"
	.string "POKéMON INSECTE auront grandi!\p"
	.string "Je vais t’enregistrer dans mon\n"
	.string "POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "J’aurai ma revanche dès que mes\n"
	.string "POKéMON INSECTE auront grandi!\p"
	.string "Je vais t’enregistrer dans mon\n"
	.string "POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mon POKéMON INSECTE a grandi. Je\n"
	.string "vais redevenir populaire.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Je n’peux pas être populaire si\n"
	.string "je perds.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "On devient populaire quand on a\n"
	.string "des POKéMON puissants, pas vrai?\p"
	.string "Alors je m’entraîne dur.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, là! Ça baigne pour tes\n"
	.string "POKéMON?\p"
	.string "Si tes POKéMON sont faibles et\n"
	.string "que tu ne veux pas te battre, il\p"
	.string "vaut mieux ne pas t’attarder\n"
	.string "dans les hautes herbes.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Parfois, il y a des choses par\n"
	.string "terre qu’on ne peut même pas\p"
	.string "voir.\p"
	.string "C’est pour ça que je fais\n"
	.string "toujours attention où je marche.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, génial! C’est le BADGE de\n"
	.string "l’ARENE de MEROUVILLE!\p"
	.string "Tu dois être DRESSEUR. Tu\n"
	.string "devrais essayer d’utiliser cet\p"
	.string "objet.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "C’est un GRAIN MIRACL. Lorsqu’un\n"
	.string "POKéMON tient cet objet, ses\p"
	.string "attaques PLANTE sont plus\n"
	.string "puissantes.\p"
	.string "Mais il existe d’autres objets\n"
	.string "tout aussi pratiques, que les\p"
	.string "POKéMON peuvent porter.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Tout POKéMON apparaissant au\n"
	.string "combat, même une fois, reçoit\p"
	.string "des points EXP.\p"
	.string "Pour augmenter le niveau d’un\n"
	.string "POKéMON, il faut le placer en\p"
	.string "tête de liste.\p"
	.string "Dès le début du combat,\n"
	.string "échangez-le. Il recevra ainsi\p"
	.string "des points EXP sans  prendre le\n"
	.string "moindre risque.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "En plus des POINTS DE VIE (PV),\n"
	.string "les POKéMON ont des POINTS DE\p"
	.string "POUVOIR (PP) pour utiliser les\n"
	.string "capacités au combat.\p"
	.string "Si un POKéMON n’a plus de PP, il\n"
	.string "faut l’emmener dans un CENTRE\p"
	.string "POKéMON.$"

