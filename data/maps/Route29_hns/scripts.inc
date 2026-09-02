Route29_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Appuie sur A ou B pour arrêter.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "Les Pokémon se cachent dans\p"
	.string "l'herbe. Ils surgissent d'un\n"
	.string "coup. Pouf!$"

Route29_Text_OldMan2:
	.string "J'te connais toi. Combien de\n"
	.string "Pokémon as-tu attrapés?\p"
	.string "Veux-tu que je te montre comment\n"
	.string "attraper des Pokémon?$"

Route29_Text_OldManExplanation:
	.string "Affaiblis d'abord les Pokémon\n"
	.string "pour mieux les attraper.\p"
	.string "Puis lance-leur une Ball depuis\n"
	.string "ton Sac! N'importe laquelle.\p"
	.string "Pour en savoir plus, va à\n"
	.string "l'Académie Pokémon de MAUVILLE!\p"
	.string "Les élèves s'y connaissent bien\n"
	.string "en Pokémon.$"

Route29_Text_OldManDeclined:
	.string "Oh. Très bien.\p"
	.string "Explore les routes pour trouver\n"
	.string "différents types de Pokémon.\p"
	.string "Ton Pokédex indique aussi où les\n"
	.string "trouver!\p"
	.string "Pour en savoir plus, va à\n"
	.string "l'Académie Pokémon de MAUVILLE!\p"
	.string "Les élèves s'y connaissent bien\n"
	.string "en Pokémon.$"

Route29_Text_Youngster:
	.string "Salut. Comment vont tes Pokémon?\p"
	.string "S'ils sont fatigués ou\n"
	.string "incapables\p"
	.string "de combattre, évite l'herbe!$"

Route29_Text_Lass:
	.string "Tu vois ce mur? Sauter de là\n"
	.string "doit faire peur.\p"
	.string "Mais tu peux aller à BOURG GEON\n"
	.string "sans\p"
	.string "marcher dans les hautes herbes.$"

Route29_Text_Girl:
	.string "Si tu veux faire\n"
	.string "une pause, n’oublie\p"
	.string "pas de sauvegarder\n"
	.string "ta partie.$"

Route29_Text_Boy_WaitingForDay:
	.string "J'attends les Pokémon qui\n"
	.string "n'apparaissent qu'en journée.$"

Route29_Text_Boy_WaitingForNight:
	.string "J'attends les Pokémon qui\n"
	.string "n'apparaissent que la nuit.$"

Route29_Text_MeetTuscany:
	.string "MARIE: Il me semble que c'est\n"
	.string "notre première rencontre?\p"
	.string "Je suis MARIE, de la FAMILLE\n"
	.string "DE LA SEMAINE.\p"
	.string "Devine mon jour préféré et je te\n"
	.string "donnerai une récompense.$"

Route29_Text_TuscanyNope:
	.string "Pas tout à fait!$"

Route29_Text_TuscanyGivesGift:
	.string "Oui! Pour fêter notre rencontre,\n"
	.string "accepte ce MOUCHOIR SOIE.$"

Route29_Text_TuscanyGaveGift:
	.string "MARIE: C'est ravissant, tu ne\n"
	.string "trouves pas?\p"
	.string "Il améliore les capacités de\n"
	.string "type NORMAL.\p"
	.string "Je suis sûre qu'il te sera\n"
	.string "utile.$"

Route29_Text_TuscanyTuesday:
	.string "MARIE: As-tu rencontré LUCIE, ma\n"
	.string "grande soeur?\p"
	.string "Ou mon petit frère HOMER?\p"
	.string "Je suis la deuxième des sept\n"
	.string "enfants.$"

Route29_Text_Sign1:
	.string "ROUTE 29\p"
	.string "VILLE GRIOTTE BOURG GEON$"
