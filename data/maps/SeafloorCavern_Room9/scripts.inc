SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "ARTHUR: Ne bouge pas! Reste là!$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "ARTHUR: Hummm… Alors c’était toi\n"
	.string "en fait.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "ARTHUR: Regarde!\p"
	.string "Vois comme c’est beau, la\n"
	.string "silhouette endormie de l’ancien\p"
	.string "POKéMON KYOGRE!\p"
	.string "J’ai attendu ce jour si\n"
	.string "longtemps…$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "ARTHUR: Je suis surpris de voir\n"
	.string "que tu as réussi à me suivre\p"
	.string "jusqu’ici.\p"
	.string "Mais tout est fini désormais.\p"
	.string "Pour que je puisse réaliser mon\n"
	.string "rêve, il faut que tu\p"
	.string "disparaisses maintenant!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Quoi?!\p"
	.string "Tu m’as vraiment battu?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "ARTHUR: Hummm…\p"
	.string "Je te félicite. Je dois\n"
	.string "reconnaître que tu as vraiment\p"
	.string "du talent.\p"
	.string "Mais! J’ai ceci en ma\n"
	.string "possession!\p"
	.string "Avec cet ORBE ROUGE, KYOGRE\n"
	.string "peut…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "L’ORBE ROUGE commence soudain à\n"
	.string "briller!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "ARTHUR: Quoi?!\p"
	.string "Je n’ai rien fait du tout.\n"
	.string "Pourquoi l’ORBE ROUGE…\p"
	.string "Où est passé KYOGRE?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "ARTHUR: Hum? C’est un message\n"
	.string "envoyé par nos membres qui sont\p"
	.string "à l’extérieur…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "ARTHUR: Oui, qu’y a-t-il?\p"
	.string "Hum… Il pleut beaucoup?\p"
	.string "Bon… Ça devait arriver. C’est\n"
	.string "pour cela que nous avons\p"
	.string "réveillé KYOGRE, pour réaliser\n"
	.string "le désir de la TEAM AQUA\p"
	.string "d’étendre la mer.\p"
	.string "Quoi?!\p"
	.string "Il pleut bien plus que prévu?\n"
	.string "C’est dangereux?\p"
	.string "Ce n’est pas… C’est tout\n"
	.string "simplement impossible…\p"
	.string "Restez à vos postes et maîtrisez\n"
	.string "la situation!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "ARTHUR: Quelque chose est\n"
	.string "anormal…\p"
	.string "L’ORBE ROUGE est censé réveiller\n"
	.string "et contrôler KYOGRE…\p"
	.string "Mais… Pourquoi? Pourquoi KYOGRE\n"
	.string "a-t-il disparu?\p"
	.string "Pourquoi?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MAX: Qu’est-ce que t’as\n"
	.string "fabriqué?\p"
	.string "ARTHUR, tu as finalement\n"
	.string "réveillé KYOGRE, n’est-ce pas?\p"
	.string "Que va devenir le monde si cette\n"
	.string "forte pluie continue à tomber\p"
	.string "pour l’éternité?\p"
	.string "Toute la surface terrestre sera\n"
	.string "noyée dans les eaux profondes de\p"
	.string "la mer.$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "ARTHUR: Qu’est-ce que tu dis? Ne\n"
	.string "prends pas ce ton avec moi!\p"
	.string "N’est-ce pas vous, la TEAM\n"
	.string "MAGMA, qui avez rendu GROUDON\p"
	.string "furieux?\p"
	.string "L’ORBE ROUGE devrait me\n"
	.string "permettre de contrôler KYOGRE…\p"
	.string "Je devais pouvoir le contrôler…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MAX: On n’a pas le temps de\n"
	.string "discuter de ça ici!\p"
	.string "Va dehors et vois par toi-même!\p"
	.string "Vois si ce que tu as fait\n"
	.string "correspond au monde de tes\p"
	.string "rêves!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MAX: {PLAYER}, viens, il faut\n"
	.string "aussi que tu partes d’ici!$"
