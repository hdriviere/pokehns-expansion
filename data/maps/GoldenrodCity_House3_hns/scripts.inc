GoldenrodCity_House3_hns_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "Je perds toujours\n"
    .string "mes combats... Et\p"
    .string "mes Pokémon finissent\n"
    .string "toujours K.O.!\p"
    .string "C’est peut-être pour ça qu’ils\n"
    .string "ne m’aiment pas?$"

GoldenrodHappinessRater_Text_Twin:
    .string "Quand j’utilise\n"
    .string "certains objets sur\p"
    .string "mon Pokémon, ça le\n"
    .string "rend vraiment heureux!$"
