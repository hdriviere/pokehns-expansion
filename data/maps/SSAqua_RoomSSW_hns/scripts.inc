SSAqua_RoomSSW_hns_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE_HNS, SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN_HNS, SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "Je vais à Kanto pour donner un\n"
    .string "spectacle.$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "Pfff... Ma flamme est\n"
    .string "minuscule...$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "Le feu c'est nul sur l'eau, non?\p"
    .string "Ca change rien? Vraiment?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "Je vais voir ma grand-mère pour\n"
    .string "attraper des insectes!$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "Ooh! Fort de café!$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "Il y a plein de Pokémon dans les\n"
    .string "arbres de JOHTO!$"
