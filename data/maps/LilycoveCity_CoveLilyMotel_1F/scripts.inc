LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hum… Ils ont doublé leur\n"
	.string "clientèle en faisant des POKéMON\p"
	.string "une attraction?\p"
	.string "Je devrais peut-être prendre un\n"
	.string "POKéMON gracieux comme mascotte\p"
	.string "pour notre auberge.\p"
	.string "Je me demande si ça attirera\n"
	.string "plus de monde chez nous.$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, pardon! Désolé! J’étais trop\n"
	.string "absorbé par la télé!\p"
	.string "Depuis que la TEAM AQUA a\n"
	.string "débarqué en ville, les touristes\p"
	.string "n’approchent plus.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hé, faut pas rester là! J’vois\n"
	.string "pas la télé!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Etonnant! Tu veux dire qu’un\n"
	.string "POKéMON a trouvé un objet perdu\p"
	.string "par quelqu’un?\p"
	.string "Ça par exemple! Si on avait un\n"
	.string "POKéMON aussi intelligent que\p"
	.string "ça…\p"
	.string "On pourrait retrouver tout ce\n"
	.string "que nos clients perdent…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, pardon! Désolé! J’étais\n"
	.string "absorbé par la télé!\p"
	.string "J’ai entendu dire que quelqu’un\n"
	.string "avait débusqué la PLANQUE AQUA.\p"
	.string "Grâce à ça, on vient juste de\n"
	.string "faire une réservation pour tout\p"
	.string "un groupe.\p"
	.string "C’était une entreprise nommée…\n"
	.string "hum… GAME quelque chose…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Etonnant! Un POKéMON de garde a\n"
	.string "attrapé un voleur?\p"
	.string "Ça alors! Si on avait un POKéMON\n"
	.string "aussi robuste pour monter la\p"
	.string "garde…\p"
	.string "On aimerait pouvoir garantir une\n"
	.string "totale sécurité à notre\p"
	.string "clientèle.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, pardon! Désolé! J’étais\n"
	.string "absorbé par la télé!\p"
	.string "Oh, oui. Un grand groupe de\n"
	.string "clients est arrivé il y a peu.\p"
	.string "Ils ont réservé sous le nom de\n"
	.string "GAME FREAK. Je suppose qu’ils\p"
	.string "font des jeux.\p"
	.string "Oh, je ferais mieux de m’occuper\n"
	.string "de leur dîner!$"

