ThreeIsland_BerryForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
	.byte 0

ThreeIsland_BerryForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 12, 6
	end

ThreeIsland_BerryForest_EventScript_Lostelle::
	lock
	faceplayer
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
	waitse
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HYPNO, 30
	dowildbattle
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_IAPAPA_BERRY
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
	waitstate
	release
	end

ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
	return

ThreeIsland_BerryForest_Movement_LostelleLookAround::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	step_end

ThreeIsland_BerryForest_EventScript_WelcomeSign::
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_BewareSign::
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_Text_HelpScaryPokemon::
	.string "LOSTELLE: Sniff… Aidez-moiiii…\p"
	.string "Un méchant POKéMON arrête pas de\n"
	.string "m'embêteeer.\p"
	.string "Il me fait peur. Sniff… Je peux\n"
	.string "plus partir.\p"
	.string "Je veux rentrer chez moiiii…$"

ThreeIsland_BerryForest_Text_HereItComesAgain::
	.string "Ohh! Il revient encore! Non,\n"
	.string "va-t-en! J'ai peuuur!\p"
	.string "Aaaaah!! Je veux mon papa!$"

ThreeIsland_BerryForest_Text_ThankYouHaveThis::
	.string "Oh! J'ai eu trop peur! Merci\n"
	.string "beaucoup!\p"
	.string "Je voulais ramasser des BAIES.\n"
	.string "Tiens, c'est pour toi!$"

ThreeIsland_BerryForest_Text_LetsGoHome::
	.string "Tu t'appelles comment?\p"
	.string "J'ai peur, tu veux bien venir\n"
	.string "avec moi jusque chez mon papa?\p"
	.string "Ouiii! On y va! Je rentre à ma\n"
	.string "maison.$"

ThreeIsland_BerryForest_Text_BerryPouchIsFull::
	.string "Ta POCHE A BAIES est pleine. Tu\n"
	.string "ne peux pas prendre ça.$"

ThreeIsland_BerryForest_Text_WelcomeToBerryForest::
	.string "Bienvenue aux BOIS BAIES\p"
	.string "Echangez vos BAIES pour régaler\n"
	.string "vos amis et vos POKéMON.$"

ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons::
	.string "Attention aux POKéMON sauvages\n"
	.string "attirés par les BAIES.$"

