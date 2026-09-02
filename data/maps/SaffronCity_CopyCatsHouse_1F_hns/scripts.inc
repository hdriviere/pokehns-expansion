SaffronCity_CopyCatsHouse_1F_hns_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "... Pour notre malheur, notre\n"
	.string "fille aime imiter les gens.\p"
	.string "Elle aime faire des\n"
	.string "blagues, alors le\p"
	.string "voisinage l’appelle\n"
	.string "la Copieuse.$"

CopycatsHouse1F_Text_PokefanF:
	.string "Ma fille est très\n"
	.string "égocentrique...\p"
	.string "Elle n'a pas beaucoup d'amis.$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "Elle a perdu la\n"
	.string "Poképoupée qu’un\p"
	.string "garçon lui a donnée\n"
	.string "il y a 3 ans.\p"
	.string "Et depuis, elle\n"
	.string "passe encore\p"
	.string "plus de temps à\n"
	.string "imiter qu’avant...$"

CopycatsHouse1F_Text_Blissey:
	.string "LEUPHORIE: Rriii!$"
