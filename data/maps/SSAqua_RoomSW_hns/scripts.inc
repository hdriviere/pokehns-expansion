SSAqua_RoomSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE_HNS, SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE_HNS, SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "Les combats Pokémon me font\n"
    .string "oublier mes chagrins.\p"
    .string "Viens-donc par ici!$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "Mon cœur pleure.$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "Voyager fait oublier les peines\n"
    .string "de cœur, dit-on...\p"
    .string "Mais un Bateau\n"
    .string "Express va trop\p"
    .string "vite pour soulager\n"
    .string "les émotions!!!$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "Je vais auditionner à la STATION\p"
    .string "RADIO de DOUBLONVILLE.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "Quel bide!$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "J'allais me lancer dans le défi\n"
    .string "de la TOUR DE COMBAT...\p"
    .string "Je devrais retourner à CARMIN et\n"
    .string "m'entraîner...$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "Au fait... C'est quoi le BON\p"
    .string "NUMERO de cette semaine?$"
