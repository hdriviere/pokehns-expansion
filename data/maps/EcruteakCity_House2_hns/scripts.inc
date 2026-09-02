EcruteakCity_House2_hns_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah! Tu fais les 400 coups avec\n"
	.string "tes Pokémon?\p"
	.string "Mais qu'est-ce qu'une aventure\n"
	.string "sans une chasse au trésor?\p"
	.string "J'ai bon ou j'ai bon?$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "Fantastique! Tu as tout compris\n"
	.string "au sens de la vie!\p"
	.string "J’aime! Prends ça avec toi!$"

Ecruteak_Text_ItemfinderExplanation:
	.string "De nombreux objets sont cachés\n"
	.string "un peu partout.\p"
	.string "Utilise le CHERCH'OBJET pour\n"
	.string "savoir si un objet se trouve\l"
	.string "près de toi.\p"
	.string "Il n'indique pas l'endroit\n"
	.string "exact.\p"
	.string "Tu devras chercher toi-même.\p"
	.string "Au fait, il paraît que\n"
	.string "des objetsl"
	.string "se trouvent dans la TOUR CENDREE\l"
	.string "de ROSALIA.$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh... Chacun sa voie, hein.$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	checkitem ITEM_DOWSING_MACHINE
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_AlreadyGotItemfinder
	msgbox Ecruteak_Text_ItemfinderAdventure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_GiveItemFinder
	msgbox Ecruteak_Text_ItemfinderToEachHisOwn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_GiveItemFinder::
	msgbox Ecruteak_Text_ItemfinderTrueSpirit, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
EcruteakCity_House2_EventScript_AlreadyGotItemfinder::
	msgbox Ecruteak_Text_ItemfinderExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "ROSALIA est une ville\n"
	.string "très ancienne.\p"
	.string "Des générations ont transmis son\l"
	.string "histoire dans ces livres.$"

Ecruteak_Text_HistoryBook:
	.string "HISTOIRE de ROSALIA\p"
	.string "Désirez-vous lire?$"

Ecruteak_Text_TwoTowers:
	.string "Il existait deux tours à\n"
	.string "ROSALIA.\p"
	.string "Chacune d'elle était le perchoir\n"
	.string "d'un puissant Pokémon volant.\p"
	.string "Mais l'une des tours a\n"
	.string "complètement brûlé.\p"
	.string "Les deux Pokémon n'ont jamais\n"
	.string "été revus depuis...\p"
	.string "Continuer à lire?$"

Ecruteak_Text_ThreeMon:
	.string "ROSALIA était aussi la demeure\p"
	.string "de trois Pokémon qui couraient\n"
	.string "autour de la ville.\p"
	.string "Ils étaient soidisant nés de\p"
	.string "l'eau, de la foudre et du feu.\p"
	.string "Mais ils ne pouvaient pas\n"
	.string "contenir toute leur puissance.\p"
	.string "C'est la raison pour laquelle\n"
	.string "ils\p"
	.string "couraient sans cesse.$"
