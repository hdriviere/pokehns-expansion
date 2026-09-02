BlackthornCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	setspeaker BlackthornCity_Text_ElmName
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_ElmName:
	.string "PROF. ORME$"

BlackthornCity_Text_BaobaCall:
	.string "DIRECTEUR BAOBA: {PLAYER}!\p"
	.string "C'est le directeur BAOBA.\p"
	.string "Je t'appelle pour t'annoncer\n"
	.string "que le PARC SAFARI\n"
	.string "s'est agrandi!\p"
	.string "Viens nous rendre visite!$"

BlackthornCity_Text_ElmCall:
	.string "PROF. ORME: Allô, {PLAYER}?\p"
	.string "J'ai quelque chose pour toi.\n"
	.string "Peux-tu passer au LABO?\p"
	.string "À bientôt!$"

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
	.string "SANDRA, notre Championne, suit\n"
	.string "ta progression.\p"
	.string "Mais elle n'affronte que les\n"
	.string "Dresseurs ayant déjà 7 BADGES.$"

BlackthornCity_Text_ClairIsIn:
	.string "Sandra, notre Champion, vous\n"
	.string "attend.\p"
	.string "Vous aurez du mal à la battre.$"

BlackthornCity_Text_ClairIsBeaten:
	.string "Vous avez battu Sandra?\n"
	.string "Incroyable!\p"
	.string "Seul Peter avait réussi cet\n"
	.string "exploit!$"

BlackthornGrampsRefusesEntryText:
	.string "Seuls les dresseurs confirmés\p"
	.string "peuvent s'entraîner ici. Partez.$"

BlackthornGrampsGrantsEntryText:
	.string "Si SANDRA le permet,\n"
	.string "son grandpère,\p"
	.string "le MAITRE, le\n"
	.string "permet aussi.\p"
	.string "Entrez.$"

BlackBeltText_VoicesInMyHead:
	.string "Aahhhh! Des voix dans ma tête!\p"
	.string "Hum? J'écoute ma radio!$"

BlackthornCooltrainerF1Text:
	.string "Tu vas faire réapprendre des\n"
	.string "capacités à tes Pokémon?$"

BlackthornYoungsterText:
	.string "Tous les experts en dragons\n"
	.string "viennent d'EBENELLE.$"

BlackthornCity_MeetSantosText:
	.string "SAMUEL: ...\p"
	.string "Je suis SAMUEL de la fratrie\n"
	.string "des jours de la semaine.\p"
	.string "Essaie de deviner.$"

BlackthornCity_SantosGivesGiftText:
	.string "Tiens...$"

BlackthornCity_SantosGaveGiftText:
	.string "SAMUEL: ...\p"
	.string "RUNE SORT...\p"
	.string "Les attaques de type SPECTRE\n"
	.string "sont plus fortes.\p"
	.string "Ca va t'effrayer, tu verras...$"

BlackthornCity_SantosSaturdayText:
	.string "SAMUEL: ...\p"
	.string "A la prochaine, un autre\n"
	.string "samedi...\p"
	.string "Je n'aurai plus de cadeaux...$"

BlackthornCity_SantosNopeText:
	.string "SAMUEL: Non.$"

BlackthornCooltrainerF2Text:
	.string "Wah! Tu as traversé la Route de\n"
	.string "Glace?\p"
	.string "Tu dois être un sacré Dresseur!$"

BlackthornCitySignText:
	.string "Ebènelle Un coin de montagne\n"
	.string "reculé$"

BlackthornGymSignText:
	.string "Arène d’Ebènelle\p"
	.string "Champion: Sandra La Dompteuse de\n"
	.string "Dragons$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "MAISON DES FRÈRES CAPACITÉS$"

BlackthornCity_Text_DragonDenSign:
	.string "ANTRE DU DRAGON TOUT DROIT$"
