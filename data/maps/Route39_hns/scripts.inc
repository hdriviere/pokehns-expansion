Route39_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_DRAIN_PUNCH
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitfanfare
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "BAOBA: SAPRISTI! Cette ombre\n"
	.string "appartenait-elle à un Pokémon?\p"
	.string "As-tu réussi à bien la voir?\n"
	.string "Je n'ai pas vu sa couleur...$"

Route39_Text_BaobaIntro::
	.string "Baoba: Oooooooh! Ce truc dans ta\n"
	.string "main!\p"
	.string "C’est un Pokédex!\p"
	.string "Que de souvenirs!\p"
	.string "Je m’appelle Baoba!\p"
	.string "Il y a quelque temps,\n"
	.string "je m’occupais du Parc\p"
	.string "Safari de Parmanie,\n"
	.string "mais, tu sais,\p"
	.string "le monde change, de nouvelles\n"
	.string "modes\p"
	.string "naissent et meurent, et puis, un\n"
	.string "jour,\p"
	.string "on m’a dit que c’était passé de\n"
	.string "mode.\p"
	.string "Mon Safari! Tu te rends compte!\p"
	.string "Et alors, là! Ce\n"
	.string "que j’ai fait, c’est\p"
	.string "que je suis allé à\n"
	.string "l’étranger pour étudier,\p"
	.string "puis j’ai créé un nouveau Parc\n"
	.string "Safari\p"
	.string "à Irisia!\p"
	.string "Je suis sûr qu’on\n"
	.string "s’est rencontrés\p"
	.string "pour une raison\n"
	.string "aujourd’hui!\p"
	.string "Il faut qu’on\n"
	.string "s’échange nos numéros\p"
	.string "de téléphone avec\n"
	.string "nos Pokématos!\p"
	.string "Quand mon parc sera\n"
	.string "prêt, tu seras la\p"
	.string "première personne\n"
	.string "que j’appellerai!$"

Route39_Text_Registered:
	.string "{PLAYER} a enregistré Baoba dans\n"
	.string "son Pokématos!$"


Route39_Text_WillCall:
	.string "BAOBA: Je te préviendrai bientôt\n"
	.string "sur le POKéMATOS!$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "Cette ombre... C'était peut-être\n"
	.string "un ROUCOOL géant?$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "ÉCRÉMEUH: Meuh!$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE_HNS, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "Je reviens de OLIVILLE.\p"
	.string "Ca te dit un p'tit combat\n"
	.string "Pokémon?$"

Route39_Text_SailorEugeneBeaten:
	.string "Awaaargh!$"

Route39_Text_SailorEugeneAfter:
	.string "J'ai attrapé et entraîné mes\n"
	.string "Pokémon à l'étranger.\p"
	.string "Ils m'accompagnent pendant mes\n"
	.string "longs voyages.$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten, Route39_EventScript_RegisterDerek
	goto_if_set FLAG_DEREK_HAS_ITEM_HNS, Route39_EventScript_DerekGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route39_EventScript_RematchDerek
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RematchDerek::
	trainerbattle_rematch TRAINER_DEREK_HNS, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RegisterDerek::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route39_Text_DerekRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DEREK_HNS
	release
	end

Route39_EventScript_DerekGiveItem::
	msgbox Route39_Text_DerekHasItem, MSGBOX_DEFAULT
	giveitem VAR_DEREK_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route39_EventScript_DerekNoRoom
	clearflag FLAG_DEREK_HAS_ITEM_HNS
	msgbox Route39_Text_DerekGaveItem, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DerekNoRoom::
	msgbox Route39_Text_DerekNoRoom, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "Moi je crâne avec mon PIKACHU!$"

Route39_Text_PokefanMDerekBeaten:
	.string "J'ai pas pu crâner...$"

Route39_Text_PokefanMDerekAfter:
	.string "Je n'écouterai pas\n"
	.string "tes vantardises!\p"
	.string "Nous, les Pokéfans, avons\n"
	.string "pour règle de ne jamais écouter\l"
	.string "les vantards!$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH_HNS, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "J’adore les Pokémon! Allez! On\n"
	.string "se les montre en même temps, OK?$"

Route39_Text_PokefanFRuthBeaten:
	.string "J'm'en fiche si je perds.$"

Route39_Text_PokefanFRuthAfter:
	.string "Tu connais les bébés Pokémon?\p"
	.string "Ils sont siiii mignooons!$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_HNS, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Dis-moi, qu’est-ce qu’elle sait\n"
	.string "faire ton équipe de Pokémon?$"

Route39_Text_PsychicNormanBeaten:
	.string "Ooh, elle est forte ton équipe!$"

Route39_Text_PsychicNormanAfter:
	.string "Sais-tu combien de Pokémon ont\n"
	.string "plusieurs capacités?\p"
	.string "C'est normal! Les humains aussi\n"
	.string "ont plusieurs talents, non?$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE_HNS, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "Tu viens au bon moment.\p"
	.string "COMBAT.$"

Route39_Text_PokefanFJaimeBeaten:
	.string "Oh, quel dommage!$"

Route39_Text_PokefanFJaimeAfter:
	.string "J'ai vu MIAOUSS la nuit, ici sur\n"
	.string "la ROUTE 39.\p"
	.string "Je ne sais pas pourquoi mais il\p"
	.string "aime s'entraîner ici.\p"
	.string "Il devient plus amical de cette\n"
	.string "façon...$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "ROUTE 39\p"
	.string "OLIVILLE ROSALIA$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "Ranch Meumeu Si vous voulez du\n"
	.string "bon lait,\p"
	.string "ne cherchez pas plus loin!$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "Conseils aux Dresseurs!\p"
	.string "Les Pokémon qui\n"
	.string "tombent des arbres\p"
	.string "quand on leur donne\n"
	.string "un Coup d’Boule\p"
	.string "changent selon les arbres!\p"
	.string "Essayez donc Coup d’Boule sur\n"
	.string "des arbres différents!$"

Route39_Text_DerekRegister:
	.string "Je n'écouterai pas\n"
	.string "tes vantardises!\p"
	.string "Nous, les Pokéfans, avons\n"
	.string "pour règle de ne jamais écouter\l"
	.string "les vantards!$"

Route39_Text_DerekHasItem:
	.string "Hé! J'ai trouvé quelque chose\n"
	.string "en faisant admirer mon PIKACHU.\p"
	.string "Tiens, c'est pour toi!$"

Route39_Text_DerekGaveItem:
	.string "PIKACHU est cool! Tu ne trouves\n"
	.string "pas?$"

Route39_Text_DerekNoRoom:
	.string "Hmm, ton SAC est plein.\p"
	.string "Reviens quand tu auras\n"
	.string "de la place.$"
