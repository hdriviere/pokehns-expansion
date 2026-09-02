Melemele_House_3_hns_MapScripts::
	.byte 0


Melemele_House3_Woman::
	lock
	faceplayer
	msgbox Melemele_House3_Woman_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Man::
	lock
	faceplayer
	msgbox Melemele_House3_Man_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House3_Woman_Text_0:
	.string "La vie insulaire est si paisible\n"
	.string "ici!\p"
	.string "Et j'aime pouvoir rejoindre\n"
	.string "rapidement mes petits-enfants à\p"
	.string "KANTO en bateau!$"

Melemele_House3_Man_Text_0:
	.string "Maudits touristes!\p"
	.string "Mon agent immobilier m'avait dit\n"
	.string "que cet endroit serait calme...\p"
	.string "Mais il faut dire que le voyage\n"
	.string "coûte moins cher que d'aller\p"
	.string "jusqu'à ALOLA.$"
