SaffronCity_PokemonTrainerFanClub_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonTrainerFanClub_OnTransition
	.byte 0

SaffronCity_PokemonTrainerFanClub_OnFrame::
	map_script_2 VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_Delay48
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HuhYou
	closemessage
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow
	setvar VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2
	releaseall
	end

SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer::
	delay_16
	delay_8
	walk_down
	delay_16
	walk_down
	delay_8
	walk_left
	step_end

SaffronCity_PokemonTrainerFanClub_OnTransition::
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2, SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special Script_TryLoseFansFromPlayTime
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, 5, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, 7, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, 2, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, 3, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, MOVEMENT_TYPE_FACE_RIGHT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_ROCKER, 4, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_ROCKER, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_WOMAN, 10, 3
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_WOMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BEAUTY, 7, 5
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BEAUTY, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, 9, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting::
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Youngster::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Gentleman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Rocker::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBelt::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster
	release
	end

SaffronCity_PokemonTrainerFanClub_Text_HuhYou::
	.string "Hein? C'est toi?…$"

SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow::
	.string "Tu es peut-être… … …\p"
	.string "Tu es… C'est toi, {PLAYER}!\p"
	.string "On parlait justement de toi!\p"
	.string "On parlait de ce nouveau\n"
	.string "DRESSEUR super fort.\p"
	.string "Et cette personne c'est toi!\n"
	.string "C'est trop fort!\p"
	.string "Alors on va créer ton FAN CLUB!\p"
	.string "En continuant à te battre comme\n"
	.string "ça, je suis sûre que tu vas\p"
	.string "avoir de plus en plus de fans!$"

SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou::
	.string "Je te soutiendrai toujours!\p"
	.string "Go, {PLAYER}, go!$"

SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou::
	.string "Je croirai toujours en toi,\n"
	.string "{PLAYER}.\p"
	.string "Montre aux autres ce que c'est\n"
	.string "un super DRESSEUR!$"

SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore::
	.string "Désolée. J'étais une de tes fans\n"
	.string "avant.\p"
	.string "Mais on dirait que t'as plus\n"
	.string "l'énergie que t'avais avant.\p"
	.string "D'ailleurs, je trouve que\n"
	.string "{STR_VAR_1} est carrément plus\p"
	.string "cool!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe::
	.string "Oh! {PLAYER}!\p"
	.string "Tout le monde parle de toi en ce\n"
	.string "moment.\p"
	.string "Je vois très bien pourquoi!\n"
	.string "C'est vrai que t'es fortiche.\p"
	.string "Mais tu sais quoi?\p"
	.string "J'suis aussi fan de {STR_VAR_1}!$"

SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling::
	.string "Les DRESSEURS sont siiiii cool\n"
	.string "quand ils se battent!\p"
	.string "Tu crois pas?$"

SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts::
	.string "Oh! C'est {PLAYER}! Trop cool!\p"
	.string "Je peux avoir ton autographe?\n"
	.string "Allez, s'te plaît, sur mon\p"
	.string "short!$"

SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou::
	.string "Qu'il fasse super chaud…\p"
	.string "Ou qu'il fasse super froid…\p"
	.string "Une chose est sûre, je garderai\n"
	.string "mon short!\p"
	.string "Allez, continue de gagner, je\n"
	.string "crois en toi comme dans mes\p"
	.string "shorts!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero::
	.string "PIERRE est mon héros! C'est un\n"
	.string "vrai mec!\p"
	.string "Hehehe, t'as vu ça, ma mère m'a\n"
	.string "brodé le nom de PIERRE\p"
	.string "sur mon short. Trop classe!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd::
	.string "… …\p"
	.string "Je suis fan de PIERRE!\p"
	.string "Et je le resterai quoi qu'il\n"
	.string "arrive!\p"
	.string "J'le jure sur mon short!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool::
	.string "PIERRE, c'est le plus cool,\n"
	.string "point à la ligne!\p"
	.string "Si je lui ressemblais, j'aurais\n"
	.string "trop de succès avec les filles.$"

SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle::
	.string "{PLAYER}, j'ai eu le plaisir de\n"
	.string "te voir combattre.\p"
	.string "D'ailleurs, cela m'a rappelé les\n"
	.string "grands moments de ma jeunesse.\p"
	.string "En tout cas, sache que tu as\n"
	.string "tout mon soutien.$"

SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence::
	.string "J'ai voyagé par-delà les océans.\p"
	.string "Mais jamais, je n'avais vu un\n"
	.string "DRESSEUR comme toi.\p"
	.string "Prends conscience de ta force et\n"
	.string "ne perds pas espoir!\p"
	.string "Fais-moi cette promesse!$"

SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre::
	.string "Hmm… Et tu es?\p"
	.string "Tu comptais vraiment entrer au\n"
	.string "FAN CLUB?$"

SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo::
	.string "Ah, te voilà donc, {PLAYER},\n"
	.string "dont tout le monde parle.\p"
	.string "Tu as vraiment l'allure d'un\n"
	.string "vainqueur.\p"
	.string "Mais avant que je te reconnaisse\n"
	.string "comme une véritable légende\p"
	.string "POKéMON…\p"
	.string "… …\p"
	.string "Tu as encore du chemin à faire!$"

SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning::
	.string "Nous sommes tous des fans de\n"
	.string "DRESSEURS POKéMON.\p"
	.string "Rien de plus impressionnant\n"
	.string "qu'un DRESSEUR en plein combat.\p"
	.string "Qui sait, si tu continues comme\n"
	.string "ça, le jour viendra peut-être\p"
	.string "où l'on parlera aussi de toi.$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay::
	.string "C'est {PLAYER}! C'est {PLAYER}!\p"
	.string "Un jour, je serai comme\n"
	.string "{PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan::
	.string "Tout le monde a cessé d'être fan\n"
	.string "de {PLAYER}…\p"
	.string "Mais ça veut dire que je peux\n"
	.string "garder {PLAYER} pour moi toute\p"
	.string "seule!\p"
	.string "Youpi! Courage, mon unique\n"
	.string "{PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina::
	.string "T'sais quoi? J'adorerais être\n"
	.string "comme MORGANE!\p"
	.string "Mais je vais devoir développer\n"
	.string "mes pouvoirs PSY pour ça.$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan::
	.string "Même si je dois être la\n"
	.string "dernière, je serai toujours fan\p"
	.string "de MORGANE!\p"
	.string "Mon rêve, c'est d'être aussi\n"
	.string "belle et cool qu'elle!\p"
	.string "Mais je vais devoir développer\n"
	.string "mes pouvoirs PSY pour ça.$"

SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay::
	.string "Tu crois qu'un jour je pourrai\n"
	.string "être un DRESSEUR cool?$"

SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool::
	.string "Waouh, c'est trop coool! Trooop\n"
	.string "cool!\p"
	.string "Hein? Non… Pas toi…\p"
	.string "J'adore ta façon de combattre.$"

SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans::
	.string "Tiens, {PLAYER}!\p"
	.string "On dirait bien que je suis ton\n"
	.string "dernier fan.\p"
	.string "Mais ça me plaît assez d'être le\n"
	.string "seul, c'est moins stressant.\p"
	.string "Continue comme ça!$"

SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks::
	.string "{STR_VAR_1} est cool, hein?\n"
	.string "J'adore sa façon de parler.\p"
	.string "Si seulement je pouvais lui\n"
	.string "parler en personne.$"

SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan::
	.string "Hein, tu y crois? Tout le monde\n"
	.string "est devenu fan de toi.\p"
	.string "Après tout ce qu'on a vécu, je\n"
	.string "suis donc la seule fan de\p"
	.string "{STR_VAR_1}?\p"
	.string "Bah, être son unique fan, c'est\n"
	.string "bien mon style.$"

SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle::
	.string "Oh mon dieu, c'est toi? C'est\n"
	.string "bien toi, {PLAYER}?\p"
	.string "Je dois te dire, j'adore ta\n"
	.string "façon de combattre.\p"
	.string "Continue comme ça et ne nous\n"
	.string "déçois pas!$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan::
	.string "Oh là là! Mais c'est {PLAYER}!\p"
	.string "Quelle déception… Je viens de\n"
	.string "comprendre que je suis ta seule\p"
	.string "et plus grande fan!\p"
	.string "Tant pis! Laisse-moi au moins\n"
	.string "t'encourager!\p"
	.string "Hip hip hip, {PLAYER}!$"

SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire::
	.string "Ces derniers temps, rien ne peut\n"
	.string "arrêter {STR_VAR_1}.\p"
	.string "La façon dont il combat… C'est à\n"
	.string "couper le souffle!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou::
	.string "Bonjour {PLAYER}!\p"
	.string "Tout le monde parle de toi en ce\n"
	.string "moment.\p"
	.string "Je me sens un peu seule comme je\n"
	.string "suis fan de {STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing::
	.string "Incroyable! Tu es vraiment\n"
	.string "incroyable, {PLAYER}!\p"
	.string "Tu me donnes même envie de\n"
	.string "devenir DRESSEUR!$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan::
	.string "Je suis ta seule et unique fan…\n"
	.string "C'est frustrant…\p"
	.string "Tu veux pas te donner un peu de\n"
	.string "mal pour te faire remarquer?$"

SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity::
	.string "Pour moi, le plus grand c'est\n"
	.string "{STR_VAR_1}!\p"
	.string "Pourquoi est-ce que je suis la\n"
	.string "seule à penser ça?$"

SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart::
	.string "Je crois de tout mon cœur en\n"
	.string "Maître {STR_VAR_1}.\p"
	.string "Même si je suis la seule à\n"
	.string "croire en lui.\p"
	.string "Je ne me sentirai jamais seule\n"
	.string "tant que je penserai à Maître\p"
	.string "{STR_VAR_1}.$"

SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational::
	.string "Hiyah!\p"
	.string "Ta façon de combattre est\n"
	.string "géniale.\p"
	.string "Je suis sûr que tu iras super\n"
	.string "loin!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan::
	.string "Au lieu de juste regarder les\n"
	.string "autres se battre,\p"
	.string "il faut parfois aussi se jeter\n"
	.string "dans l'action.\p"
	.string "C'est le MAITRE de mon DOJO qui\n"
	.string "m'a appris ça.\p"
	.string "Mais ça ne m'empêchera pas de\n"
	.string "rester ton fan!$"

SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect::
	.string "Je n'admire qu'un seul DRESSEUR!\n"
	.string "Et c'est le MAITRE de mon DOJO.\p"
	.string "Toi aussi, tu devrais lui\n"
	.string "montrer du respect!\p"
	.string "Hiyaaah!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster::
	.string "Hiyaah!\p"
	.string "Je respecte le MAITRE de  mon\n"
	.string "DOJO comme personne.\p"
	.string "Je vais parcourir la région en\n"
	.string "parlant de lui pour que tout\p"
	.string "le monde reconnaisse sa valeur!$"

