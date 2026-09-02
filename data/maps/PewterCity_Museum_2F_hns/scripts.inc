PewterCity_Museum_2F_hns_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "On raconte que des météorites se\n"
	.string "sont abattues sur l'ÎLE AURORE.\p"
	.string "Nous aimerions les exposer dans\n"
	.string "notre musée, mais...\p"
	.string "Elles émettraient une étrange\n"
	.string "énergie qui empêche de les\l"
	.string "emporter...$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
	.string "Je veux un PIKACHU!\n"
	.string "Il est si mignon!\p"
	.string "J'ai demandé à papa de m'en\n"
	.string "attraper un!$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
	.string "Oui, bientôt un PIKACHU, promis!$"

PewterCity_Museum_2F_Text_SpaceShuttle::
	.string "Navette spatiale$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
	.string "Une météorite tombée sur le\n"
	.string "MONT SÉLÉNITE. Ce serait une\l"
	.string "PIERRE LUNE.$"
