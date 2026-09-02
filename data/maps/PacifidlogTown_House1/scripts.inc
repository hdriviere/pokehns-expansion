PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "Dans la région de HOENN, il\n"
	.string "existe trois POKéMON qui\p"
	.string "symbolisent la puissance de la\n"
	.string "pierre, de la glace et de\p"
	.string "l’acier.\p"
	.string "On raconte qu’ils se cachent\n"
	.string "dans des grottes obscures.\p"
	.string "C’est une histoire que j’ai\n"
	.string "entendue quand j’étais petit.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "“Six points ouvrent trois\n"
	.string "portes.”\p"
	.string "Pépé disait souvent ça, mais je\n"
	.string "ne sais pas ce que ça veut dire.$"

