Melemele_House_6_hns_MapScripts::
	.byte 0


Melemele_House6_Hiker::
	lock
	faceplayer
	msgbox Melemele_House6_Hiker_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_GameboyKid::
	lock
	faceplayer
	msgbox Melemele_House6_GameboyKid_Text_0, MSGBOX_AUTOCLOSE
	release
	end


Melemele_House6_Hiker_Text_0:
	.string "J'ai acheté cette maison pour\n"
	.string "pouvoir explorer la nature avec\p"
	.string "mon fils...\p"
	.string "Mais tout ce qui l'intéresse,\n"
	.string "c'est de jouer à cette Game Boy\p"
	.string "Advance.$"

Melemele_House6_GameboyKid_Text_0:
	.string "J'ai un jeu sur Game Boy Advance\n"
	.string "qui permet d'explorer la région\p"
	.string "d'ALOLA!\p"
	.string "C'est comme si on y était.\p"
	.string "Il s'appelle ULTRA ECLIPSE et a\n"
	.string "été créé par PHANTONOMY!\p"
	.string "Haha, regarde! Je chevauche un\n"
	.string "BRUYVERNE de glace!$"
