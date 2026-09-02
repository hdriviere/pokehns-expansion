CliffEdgeGate_hns_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "Tu savais? Une ZONE SAFARI est\n"
	.string "juste au coin.\p"
	.string "C'est vraiment amusant!\n"
	.string "Tu y verras plein d'espèces de\l"
	.string "Pokémon, et tu peux toutes\l"
	.string "les attraper!\p"
	.string "Aucune raison de ne pas y aller,\n"
	.string "pas vrai? C'est juste au coin.$"

CliffEdgeGate_Text_Expectations:
	.string "C’est très bien, que les gens\n"
	.string "attendent notre parc...\p"
	.string "Mais la vieille\n"
	.string "au comptoir est un\p"
	.string "peu trop excitée\n"
	.string "à mon goût...\p"
	.string "Bref, oui pour\n"
	.string "être excité par\p"
	.string "notre parc, mais\n"
	.string "avec modération,\p"
	.string "s’il te plaît!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "La vie sauvage à\n"
	.string "portée de main!\p"
	.string "Plus de Pokémon\n"
	.string "que vous ne pourrez\p"
	.string "en porter!\p"
	.string "Le Parc Safari de monsieur\n"
	.string "Baoba! Essayé et approuvé!$"
