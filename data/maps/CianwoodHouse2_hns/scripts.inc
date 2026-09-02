CianwoodHouse2_hns_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "Tu viens d'OLIVILLE?\p"
	.string "Tu te rappelles des quatre îles\n"
	.string "sur la route?\p"
	.string "J'ai entendu dire\n"
	.string "qu'une créature\p"
	.string "marine mythique\n"
	.string "s'y cache.$"

CianwoodCity_Text_LugiaHouseLass:
	.string "On raconte qu’on\n"
	.string "peut le rencontrer\p"
	.string "si l’on possède\n"
	.string "une Argent’Aile.\p"
	.string "Peut-être qu’il reconnaît sa\n"
	.string "propre odeur?$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "Les tourbillons\n"
	.string "autour des îles\p"
	.string "sont créés par le\n"
	.string "dieu de la mer.\p"
	.string "Il y a une légende à ce sujet.\p"
	.string "Je ne crois pas\n"
	.string "qu’on puisse les\p"
	.string "traverser sans une\n"
	.string "capacité spécifique.$"
