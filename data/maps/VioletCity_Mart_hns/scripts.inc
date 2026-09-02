VioletCity_Mart_hns_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "Même un Pokémon\n"
	.string "faible que tu viens\p"
	.string "d’attraper deviendra\n"
	.string "fort si tu en\p"
	.string "prends soin.\p"
	.string "L’important, c’est ton amour\n"
	.string "pour ce Pokémon, à mon avis.$"

VioletCity_Mart_Text_CooltrainerM:
	.string "Les Pokémon peuvent\n"
	.string "porter des objets\p"
	.string "comme les POTIONS\n"
	.string "ou les ANTIDOTES.\p"
	.string "Mais ils semblent ne pas\n"
	.string "comprendre\p"
	.string "comment les utiliser tout seuls.\n"
	.string "Donne-leur un coup de main!$"
