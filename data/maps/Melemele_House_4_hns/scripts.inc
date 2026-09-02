Melemele_House_4_hns_MapScripts::
	.byte 0


Melemele_House4_Man::
	lock
	faceplayer
	msgbox Melemele_House4_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Woman::
	lock
	faceplayer
	msgbox Melemele_House4_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House4_Man_Text_0:
	.string "Nous passons nos vacances sur\n"
	.string "les ÎLES D'ALOLA!\p"
	.string "C'est comme la région d'ALOLA,\n"
	.string "mais plus près de KANTO!\p"
	.string "J'ai économisé une fortune sur\n"
	.string "le voyage!$"

Melemele_House4_Woman_Text_0:
	.string "Mon petit ami m'avait dit que\n"
	.string "nous allions à ALOLA...\p"
	.string "Je pensais qu'il parlait de la\n"
	.string "région d'ALOLA, pas de ces\p"
	.string "petites îles au large de KANTO.$"
