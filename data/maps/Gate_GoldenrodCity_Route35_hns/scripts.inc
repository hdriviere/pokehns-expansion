Gate_GoldenrodCity_Route35_hns_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "Minute papillon! Tu peux me\n"
	.string "rendre service?\p"
	.string "Tu peux apporter ce Pokémon et\n"
	.string "sa LETTRE à mon pote?\p"
	.string "Il est sur la ROUTE 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "Tu veux bien? Merci!\p"
	.string "Mon pote est gras et il pionce\n"
	.string "tout le temps.\p"
	.string "Tu vas le reconnaître, c'est\n"
	.string "sûr!$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER} reçoit un Pokémon avec\n"
	.string "une LETTRE.$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "Place-le en tête de ton équipe\n"
	.string "quand tu trouveras mon ami!\p"
	.string "Sur la ROUTE 31!\p"
	.string "Ah oui. Un arbre étrange\n"
	.string "bloquait le chemin.\p"
	.string "Je me demande s'il a été dégagé.$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "Tu ne peux plus porter de\n"
	.string "Pokémon!$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "Bon. Laisse tomber alors...$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "Merci bien! Tu as bien fait la\n"
	.string "livraison!\p"
	.string "Voilà pour toi!$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "Mon pote pionce comme un fou,\n"
	.string "non? Quelle classe!$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "Un arbre bizarre\n"
	.string "bloque le chemin.\p"
	.string "Il gigote si on\n"
	.string "s’en approche.\p"
	.string "Il paraît qu’il\n"
	.string "devient dingue si\p"
	.string "on l’asperge avec\n"
	.string "un CARAPUCE à O.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "J'aime la berceuse Pokémon qui\n"
	.string "passe à la radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "Combien d'espèces de Pokémon\n"
	.string "existent dans le monde?\p"
	.string "Il y a trois ans, le PROF.CHEN\n"
	.string "comptait 150 espèces.\p"
	.string "Mais récemment, j'ai entendu\n"
	.string "y en avait plus de 400!$"
