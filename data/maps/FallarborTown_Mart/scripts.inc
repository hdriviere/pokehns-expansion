FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	pokemartlistend

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "J’ai du mal à me décider.\n"
	.string "Faut-il que je fasse évoluer mon\p"
	.string "SKITTY?\p"
	.string "Il me suffirait d’utiliser cette\n"
	.string "PIERRE LUNE, mais je n’arrive\p"
	.string "pas à me décider…\p"
	.string "Si je le fais évoluer, il sera\n"
	.string "bien plus puissant.\p"
	.string "Mais il changera aussi\n"
	.string "d’apparence.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY: Kiiiiity?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "J’ai trouvé une PEPITE, ici… Je\n"
	.string "suppose que je vais devoir la\p"
	.string "vendre, puisqu’elle ne sert à\n"
	.string "rien d’autre.$"

