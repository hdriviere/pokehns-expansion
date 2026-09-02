FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Ecoute, mon petit, est-ce que tu\n"
	.string "travailles sur un POKéDEX?\p"
	.string "Hum… Va au PARC SAFARI, sur la\n"
	.string "ROUTE 121! C’est mon conseil.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Tu as déjà fait quelque chose au\n"
	.string "CENTRE DE DONNEES?\p"
	.string "C’est ingénieux. Ça permet\n"
	.string "d’échanger des données entre\p"
	.string "DRESSEURS.\p"
	.string "Je sais pas trop comment ça\n"
	.string "marche, mais c’est cool. C’est\p"
	.string "même génial!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Hé, tu as un POKéNAV! C’est le\n"
	.string "même que le mien!\p"
	.string "Tu connais la fonction MATCH\n"
	.string "PHONE?\p"
	.string "Utilise-la pour tchater avec les\n"
	.string "DRESSEURS que tu auras\p"
	.string "enregistrés.\p"
	.string "Cette option t’indique aussi les\n"
	.string "DRESSEURS souhaitant une\p"
	.string "revanche.\p"
	.string "C’est pas génial? Y a pas mieux\n"
	.string "que DEVON!$"

