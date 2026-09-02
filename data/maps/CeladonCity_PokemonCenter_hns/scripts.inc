CeladonCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY_HNS
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ERIKA est la maîtresse des\n"
	.string "Pokémon des plantes.\p"
	.string "Fais attention ou tu le\n"
	.string "regretteras.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "La planque de la TEAM ROCKET est\n"
	.string "au\p"
	.string "sous-sol du CASINO.\p"
	.string "Attends... C'était il y a 3 ans,\n"
	.string "ça.$"

Celadon_Text_Eusine1:
	.string "EUSINE: Bonjour!\p"
	.string "Je suis de retour dans ma ville\n"
	.string "natale.\p"
	.string "Ca faisait bien longtemps.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, es-tu au courant?\p"
	.string "On raconte qu'un\n"
	.string "Pokémon aux couleurs de\p"
	.string "l'arcen-ciel est apparu\n"
	.string "à la TOUR FERRAILLE.\p"
	.string "Je viens de soigner mon équipe.\p"
	.string "Je retourne à ROSALIA.\p"
	.string "A très bientôt, {PLAYER}!$"

Celadon_Text_NoBeasts:
	.string "Au fait, {PLAYER}.\p"
	.string "As-tu attrapé les Pokémon\n"
	.string "légendaires RAIKOU et ENTEI?\p"
	.string "<……><……><……>\p"
	.string "D'accord...\p"
	.string "Si tu en attrapes un,\n"
	.string "préviens-moi.\p"
	.string "Je compte sur toi, {PLAYER}!$"
