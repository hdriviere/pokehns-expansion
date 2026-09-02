FourIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FourIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FOUR_ISLAND
	end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FourIsland_PokemonCenter_1F_EventScript_Man::
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Woman::
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
	end

@ The 5 texts below are supposed to be in FourIsland_House1
Text_BodySlamTeach::
	.string "Prêts? Go!\p"
	.string "On fait un concours de PLAQUAGE.\p"
	.string "Si tu veux essayer, tu vas te\n"
	.string "faire écraser comme un insecte!\p"
	.string "Et si j'apprenais plutôt cette\n"
	.string "capacité à un de tes POKéMON?$"

Text_BodySlamDeclined::
	.string "Allez! Go!$"

Text_BodySlamWhichMon::
	.string "A quel POKéMON vais-je enseigner\n"
	.string "PLAQUAGE?$"

Text_BodySlamTaught::
	.string "Whoua!$"

FourIsland_House1_Text_FatMan::
	.string "それ　ぼよーん！\n"
	.string "おまえ　おもいなあー！$"

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
	.string "Il y a un POKéMON GLACE très\n"
	.string "rare qui vit dans cette grotte.\p"
	.string "Y'a plein de monde qui vient ici\n"
	.string "en espérant le voir.$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
	.string "Oh? Un OEUF POKéMON? … Aucune\n"
	.string "idée.\p"
	.string "Oh, attends, il me semble que\n"
	.string "les gens de la PENSION en\p"
	.string "parlaient.\p"
	.string "Ils disaient en avoir déjà eu\n"
	.string "chez eux.$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
	.string "Quoi?\p"
	.string "Le nouveau JOURNAL POKéMON n'est\n"
	.string "pas encore arrivé sur l'île?$"

