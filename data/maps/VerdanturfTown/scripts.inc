VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Mon papa m’a tout raconté.\p"
	.string "Il dit que ce tunnel est rempli\n"
	.string "de POKéMON craintifs.\p"
	.string "Ils ont tous peur du bruit et\n"
	.string "font beaucoup de brouhaha.\p"
	.string "Alors ils ont été obligés\n"
	.string "d’arrêter le projet du tunnel.\p"
	.string "Mais il y a encore un homme. Il\n"
	.string "essaie de creuser le tunnel tout\p"
	.string "seul!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Il y a un type qui a creusé un\n"
	.string "tunnel pour la fille qu’il aime.\p"
	.string "Moi, je n’le ferais pas, mais\n"
	.string "bon, après tout…$"

VerdanturfTown_Text_AirCleanHere:
	.string "Le vent n’amène jamais les\n"
	.string "cendres volcaniques par là.\p"
	.string "L’air est sain et délicieux ici.\n"
	.string "Vivre ici est très bénéfique,\p"
	.string "surtout pour les personnes\n"
	.string "chétives et malades.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Mes POKéMON et moi venons de\n"
	.string "réussir une grande série de\p"
	.string "victoires consécutives.\p"
	.string "Alors j’ai décidé de nous\n"
	.string "essayer à la TENTE DE COMBAT de\p"
	.string "cette ville.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "As-tu vu la caverne près de la\n"
	.string "BOUTIQUE POKéMON?\p"
	.string "Il y a un type là-bas qui essaie\n"
	.string "de casser des rochers pour\p"
	.string "pouvoir passer et se rendre de\n"
	.string "ce côté.\p"
	.string "Ce serait super de pouvoir\n"
	.string "passer… Ça serait facile d’aller\p"
	.string "à MEROUVILLE.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Tu sais, cette caverne près de\n"
	.string "la BOUTIQUE POKéMON, elle relie\p"
	.string "désormais les deux côtés.\p"
	.string "C’est super! Plus de problème\n"
	.string "pour faire des courses chez\p"
	.string "DEVON à MEROUVILLE.$"

VerdanturfTown_Text_TownSign:
	.string "VERGAZON\p"
	.string "“Les montagnes où le vent\n"
	.string "souffle et où le doux parfum de\p"
	.string "l’herbe se dégage.”$"

VerdanturfTown_Text_WandasHouse:
	.string "MAISON DE SYLVIE$"

VerdanturfTown_Text_BattleTentSign:
	.string "TENTE DE COMBAT de VERGAZON\n"
	.string "“Venez admirer nos combats!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TUNNEL MERAZON “Passage entre\n"
	.string "MEROUVILLE et VERGAZON”.\p"
	.string "“Le projet de création du tunnel\n"
	.string "a été annulé.”$"

