Aide_EventScript_HaventCaughtEnough::
	msgbox Aide_Text_HaventCaughtEnoughMonsForItem
	release
	end

Aide_EventScript_NoRoomForItem::
	msgbox Aide_Text_DontHaveAnyRoomForItem
	release
	end

Aide_EventScript_DeclineCheckMons::
	msgbox Aide_Text_GetEnoughMonsComeBackForItem
	release
	end

Aide_Text_HaventCaughtEnoughMonsForItem::
	.string "Voyons voir…\p"
	.string "Oh! Tu n'as attrapé que\n"
	.string "{STR_VAR_3} sortes de POKéMON!\p"
	.string "Il t'en faut {STR_VAR_1}\n"
	.string "différents pour mériter un\p"
	.string "{STR_VAR_2}.$"

Aide_Text_GetEnoughMonsComeBackForItem::
	.string "Dans ce cas…\p"
	.string "Reviens avec {STR_VAR_1} sortes\n"
	.string "de POKéMON pour obtenir\p"
	.string "{STR_VAR_2}.$"

Aide_Text_DontHaveAnyRoomForItem::
	.string "Oh! Tu n'as plus de place pour\n"
	.string "{STR_VAR_2}.$"
