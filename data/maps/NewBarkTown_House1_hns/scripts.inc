NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU est un Pokémon évolué.\p"
	.string "Les découvertes du PROF.ORME\n"
	.string "sont incroyables.\p"
	.string "Ses recherches sur l'évolution\n"
	.string "des Pokémon sont brillantes.\p"
	.string "(soupir)\p"
	.string "J'aimerais être comme lui...$"


NewBarkTown_House1_Text_Neighbor:
	.string "Ma fille tient absolument à\n"
	.string "devenir l'assistante du\p"
	.string "PROF.ORME.\p"
	.string "Elle adore vraiment les Pokémon!\p"
	.string "Mais moi aussi!$"
