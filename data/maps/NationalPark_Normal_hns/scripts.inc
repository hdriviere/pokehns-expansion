NationalPark_Normal_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "Hé! Regarde mon sac!\p"
	.string "J'ai imprimé mes copains du\n"
	.string "Pokédex\p"
	.string "et je les ai mis sur mon super\n"
	.string "sac!$"

NationalPark_Normal_Text_PokefanF:
	.string "C'est une LETTRE de ma fille.\n"
	.string "C'est cool, hein?$"

NationalPark_Normal_Text_Teacher1:
	.string "Allez, silence et en rang!\p"
	.string "... Heu, pardon. Les habitudes\n"
	.string "de maîtresse d’école,\p"
	.string "tu sais...\p"
	.string "Tu es Dresseur de Pokémon, non?\p"
	.string "Tu as l’air de prendre ça très\n"
	.string "au sérieux. Continue comme ça!\p"
	.string "Tiens, pour t’encourager!$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "Fais tenir la\n"
	.string "Vive Griffe à un\p"
	.string "Pokémon pour le\n"
	.string "faire frapper plus\p"
	.string "souvent en premier durant un\n"
	.string "combat.$"

NationalPark_Normal_Text_Youngster1:
	.string "Je m'amuse avec\n"
	.string "les autocollants\p"
	.string "que j'ai imprimés\n"
	.string "de mon Pokédex.$"

NationalPark_Normal_Text_Youngster2:
	.string "Je gagne les\n"
	.string "autocollants du\p"
	.string "Pokédex de l'adversaire\n"
	.string "si je le bats.$"

NationalPark_Normal_Text_Teacher2:
	.string "Je me promène dans le PARC,\n"
	.string "mais je ne vais jamais dans\l"
	.string "les hautes herbes.\p"
	.string "Les Dresseurs veulent toujours\n"
	.string "se battre...\p"
	.string "Tu as dû livrer bien des\n"
	.string "combats.\p"
	.string "Laisse-moi soigner tes Pokémon.$"

NationalPark_Normal_Text_Persian:
	.string "PERSIAN: Siaaaan!$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK_HNS, NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten, NationalPark_Normal_EventScript_RegisterJack
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchJack
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterJack::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_JackRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACK_HNS
	release
	end

NationalPark_Normal_EventScript_RematchJack::
	trainerbattle_rematch TRAINER_JACK_HNS, NationalPark_Normal_Text_JackRematchIntro, NationalPark_Normal_Text_JackRematchDefeat
	msgbox NationalPark_Normal_Text_JackPostRematch, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten, NationalPark_Normal_EventScript_RegisterBeverly
	goto_if_set FLAG_BEVERLY_HAS_ITEM_HNS, NationalPark_Normal_EventScript_BeverlyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, NationalPark_Normal_EventScript_RematchBeverly
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RematchBeverly::
	trainerbattle_rematch TRAINER_BEVERLY_HNS, NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_RegisterBeverly::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox NationalPark_Normal_Text_BeverlyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BEVERLY_HNS
	release
	end

NationalPark_Normal_EventScript_BeverlyGiveItem::
	msgbox NationalPark_Normal_Text_BeverlyHasItem, MSGBOX_DEFAULT
	giveitem VAR_BEVERLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, NationalPark_Normal_EventScript_BeverlyNoRoom
	clearflag FLAG_BEVERLY_HAS_ITEM_HNS
	msgbox NationalPark_Normal_Text_BeverlyGaveItem, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_BeverlyNoRoom::
	msgbox NationalPark_Normal_Text_BeverlyNoRoom, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM_HNS, NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE_HNS, NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "Grand est le monde des Pokémon.\p"
	.string "Tant de choses sont encore\n"
	.string "inconnues.\p"
	.string "Mais moi... J'en sais plus que\n"
	.string "toi!$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "Qu-qu-quoi?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple...\p"
	.string "Il y a 50 types de CT.\p"
	.string "Les Pokémon échangés grandissent\n"
	.string "plus vite.$"

NationalPark_Normal_Text_JackRegister:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple...\p"
	.string "Il y a 50 types de CT.\p"
	.string "Les Pokémon échangés grandissent\n"
	.string "plus vite.$"

NationalPark_Normal_Text_JackRematchIntro:
	.string "J'ai beaucoup appris depuis\n"
	.string "notre dernier combat! Allons-y!$"

NationalPark_Normal_Text_JackRematchDefeat:
	.string "Qu-qu-quoi?$"

NationalPark_Normal_Text_JackPostRematch:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple...\p"
	.string "Il y a 50 types de CT.\p"
	.string "Les Pokémon échangés grandissent\n"
	.string "plus vite.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "Mes Pokémon sont les mieux du\n"
	.string "mooooonde.\p"
	.string "Tu vas voir ça! Oh que oui!$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "Au moins, l’honneur est sauf...$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "Ton équipe de Pokémon est\n"
	.string "adorable!$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "On adore nos Pokémon, même si\n"
	.string "eux nous détestent.\p"
	.string "Et c'est ça un vrai FAN.$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "M-m-mon Pokémon!$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "Je perds le combat mais mes\n"
	.string "Pokémon\p"
	.string "sont de loin les plus beaux.$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "Bonjour? Pourquoi tu me\n"
	.string "regardes?\p"
	.string "Quoi? Tu veux te battre?!$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "... Hmmm...$"

NationalPark_Normal_Text_LassKrise_After:
	.string "J'pensais que tu me regardais\n"
	.string "pour me demander des sous!$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "AIRE DE REPOS du PARC NATUREL$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "C'est quoi cette affiche?\p"
	.string "Se battre uniquement dans\n"
	.string "l'herbe.\p"
	.string "LE GARDIEN DU PARC NATUREL$"

NationalPark_Normal_Text_TrainerTips:
	.string "ASTUCE\p"
	.string "Imprimer les LETTRES en les\n"
	.string "ouvrant et appuyer sur START.$"

NationalPark_Normal_Text_BeverlyRegister:
	.string "Ton équipe de Pokémon est\n"
	.string "adorable!$"

NationalPark_Normal_Text_BeverlyHasItem:
	.string "Oh, bonjour! J'ai quelque chose\n"
	.string "pour toi.\p"
	.string "Accepte-le en gage de ma\n"
	.string "reconnaissance!$"

NationalPark_Normal_Text_BeverlyGaveItem:
	.string "Mes adorables Pokémon et moi\n"
	.string "t'encouragerons!$"

NationalPark_Normal_Text_BeverlyNoRoom:
	.string "Hmm, ton SAC est plein.\p"
	.string "Reviens quand tu auras\n"
	.string "de la place.$"
