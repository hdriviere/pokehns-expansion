Route30_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 55
	waitmovement LOCALID_ROUTE_30_JOEY
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY_HNS, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten, Route30_EventScript_RegisterJoey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route30_EventScript_RematchJoey
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_RegisterJoey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route30_Text_JoeyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOEY_HNS
	release
	end

Route30_EventScript_RematchJoey::
	trainerbattle_rematch TRAINER_JOEY_HNS, Route30_Text_JoeyRematchIntro, Route30_Text_JoeyRematchDefeat
	msgbox Route30_Text_JoeyPostRematch, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY_HNS, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON_HNS, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	setspeaker Route30_Text_ElmName
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "CHEZ M.Pokémon$"

Route30_Text_UseTackle:
	.string "Allez, RATTATA!\p"
	.string "CHARGE!$"

Route30_Text_ThisIsABigBattle:
	.string "Tu veux quoi? On est en plein\n"
	.string "combat!\p"
	.string "Va voir ailleurs!$"

Route30_Text_YoungsterJoey1Seen:
	.string "Je viens de perdre...\n"
	.string "Dur à avaler, mais\p"
	.string "bon, je cherche de\n"
	.string "nouveaux Pokémon.\p"
	.string "Par contre, toi,\n"
	.string "t’as l’air plutôt\p"
	.string "faible... C’est\n"
	.string "décidé! Combat!$"

Route30_Text_YoungsterJoey1Beaten:
	.string "Encore perdu! Zut de flûte!$"

Route30_Text_YoungsterJoey1After:
	.string "Dois-je choper plus de Pokémon\p"
	.string "pour gagner des combats?\p"
	.string "Non! Je reste avec celui-ci!$"

Route30_Text_YoungsterMikeySeen:
	.string "T’es un Dresseur de Pokémon,\n"
	.string "non? Alors... COOOOMBAAAAT!$"

Route30_Text_YoungsterMikeyBeaten:
	.string "C'est bizarre. J'avais cru...$"

Route30_Text_YoungsterMikeyAfter:
	.string "Etre un bon Dresseur n’est pas\n"
	.string "donné à tout le monde.\p"
	.string "Je vais me battre... Encore et\n"
	.string "encore. Encore et encore!$"

Route30_Text_BugCatcherDonSeen:
	.string "Tiens! Je cherchais\n"
	.string "des Pokémon Insecte\p"
	.string "et je trouve\n"
	.string "un Dresseur!$"

Route30_Text_BugCatcherDonBeaten:
	.string "Ah! Quelle force!$"

Route30_Text_BugCatcherDonAfter:
	.string "J’ai utilisé ma\n"
	.string "dernière Poké\p"
	.string "Ball... J’aurais dû\n"
	.string "en acheter plus...$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "La maison de M.Pokémon? C'est un\n"
	.string "peu plus loin.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "Combattre c'est marrant! Tu\n"
	.string "devrais essayer!$"

Route30_Text_CooltrainerF:
	.string "Je ne suis pas Dresseur.\p"
	.string "Mais sache que\n"
	.string "si tu croises le\p"
	.string "regard d’un autre\n"
	.string "Dresseur, tu dois\p"
	.string "t’attendre à combattre!$"

Route30_Text_Sign:
	.string "ROUTE 30\p"
	.string "MAUVILLE VILLE GRIOTTE$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "Maison de M. Pokémon Tout droit!$"

Route30_Text_MrPokemonsHouseSign:
	.string "Maison de M. Pokémon$"

Route30_Text_TrainerTips:
	.string "Conseils aux Dresseurs!\p"
	.string "On ne vole pas les\n"
	.string "Pokémon des autres!\p"
	.string "Les Poké Balls\n"
	.string "sont faites pour\p"
	.string "attraper les Pokémon sauvages!$"

Route30_Text_JoeyRegister:
	.string "Tu es plutôt doué!\p"
	.string "Mon RATTATA déborde d'énergie,\n"
	.string "comme toujours.\p"
	.string "C'est mon seul Pokémon.\p"
	.string "Avec lui, je deviendrai un grand\n"
	.string "Dresseur!\p"
	.string "On se refera un combat!$"

Route30_Text_JoeyRematchIntro:
	.string "J'avais promis que ce serait\n"
	.string "différent! Au combat!$"

Route30_Text_JoeyRematchDefeat:
	.string "Encore perdu! Zut de flûte!$"

Route30_Text_JoeyPostRematch:
	.string "J'étudie les capacités de mon\n"
	.string "RATTATA pour élaborer des\p"
	.string "stratégies.\p"
	.string "Dès que ma stratégie sera prête,\n"
	.string "on se battra!$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "Encore perdu... T'y vas fort!\p"
	.string "Oh oui. Je dois te donner ça.\p"
	.string "Ca améliore quelque chose...\p"
	.string "Me demande pas quoi...$"

Route30_Text_ElmName:
	.string "PROF. ORME$"

Route30_Text_Elm_Disaster:
	.string "PROF.ORME: All… Allô, {PLAYER}?\p"
	.string "C'est… C'est terrible!\p"
	.string "C'est… AFFREUX!\p"
	.string "Que faire?\n"
	.string "Oh, non…\p"
	.string "Reviens vite!$"


Route30_Text_Poliwag:
	.string "PTITARD: Titaaard!$"
