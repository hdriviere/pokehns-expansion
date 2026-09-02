MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Dans ma jeunesse, j'ai parcouru\n"
	.string "le monde comme DRESSEUR POKéMON.\p"
	.string "Maintenant que je suis un vieux\n"
	.string "croûton, mon seul plaisir est de\p"
	.string "regarder les jeunes DRESSEURS\n"
	.string "combattre.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "La porte semble être\n"
	.string "verrouillée.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un DRESSEUR nommé {STR_VAR_1}\n"
	.string "est chez moi.\p"
	.string "Voulez-vous affronter\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Vous ne voulez pas combattre?\n"
	.string "Quel dommage, j'aurais aimé vous\p"
	.string "voir à l'œuvre…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, parfait!\p"
	.string "Mais ma maison n'est pas très\n"
	.string "solide. Pourriez-vous vous\p"
	.string "limiter à un combat à trois\n"
	.string "contre trois?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Avant de combattre, vous devriez\n"
	.string "sauvegarder votre progression.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "J'espère assister à un beau\n"
	.string "combat!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Ainsi, le combat s'est soldé par\n"
	.string "une égalité.\p"
	.string "C'était un match brillant où\n"
	.string "personne n'a cédé un pouce de\p"
	.string "terrain!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "C'était remarquable!\p"
	.string "J'avais l'impression de me\n"
	.string "revoir dans ma jeunesse!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, quel dommage pour vous!\p"
	.string "Mais c'était un beau combat.\n"
	.string "J'espère que vous gagnerez la\p"
	.string "prochaine fois.$"
