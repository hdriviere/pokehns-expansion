Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Qu’est-ce que c’est? Qu’est-ce\n"
	.string "que je fais?\p"
	.string "Je vais me créer ma propre pièce\n"
	.string "ici, en utilisant la capacité\p"
	.string "d’un POKéMON.\p"
	.string "Je sais! Je vais te donner cette\n"
	.string "CT. Tu vas l’utiliser pour avoir\p"
	.string "ta pièce?$"

Route111_Text_ExplainSecretPower:
	.string "Trouve un grand arbre qui\n"
	.string "pourrait avoir des lianes.\p"
	.string "Utilise FORCE CACHEE devant\n"
	.string "l’arbre. Des lianes peuvent en\p"
	.string "tomber et te permettre de\n"
	.string "monter.\p"
	.string "Tu trouveras toute la place\n"
	.string "qu’il te faut pour y mettre tes\p"
	.string "objets préférés.\p"
	.string "Ce sera ta pièce secrète… Ta\n"
	.string "BASE SECRETE!\p"
	.string "Tu devrais t’en créer une!\p"
	.string "Autre chose: une BASE SECRETE ne\n"
	.string "se construit pas toujours dans\p"
	.string "un arbre.\p"
	.string "Essaie d’utiliser FORCE CACHEE\n"
	.string "sur des façades rocheuses\p"
	.string "fissurées.\p"
	.string "Je vais aussi chercher d’autres\n"
	.string "lieux. Salut!$"

Route111_Text_DontWantThis:
	.string "Oh, tu n’en veux pas? Si tu\n"
	.string "changes d’avis, fais-moi signe,\p"
	.string "OK?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, tu n’as pas de place pour\n"
	.string "ça.\p"
	.string "Bon, je vais la garder et tu\n"
	.string "pourras la prendre une autre\p"
	.string "fois, d’accord?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
