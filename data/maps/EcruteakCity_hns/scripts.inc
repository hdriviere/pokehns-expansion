EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "BOUM!!$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL}: Pourquoi? Pourquoi?\n"
	.string "Pourquoi j’arrive pas à gagner?\p"
	.string "Ce sont que des femmes en kimono\n"
	.string "pourtant!$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL}: T’as vu, {PLAYER}?\p"
	.string "J’espère que ça t’a plu de me\n"
	.string "voir être ridiculisé!\p"
	.string "Battre cinq pauvres filles en\n"
	.string "kimono,\p"
	.string "ça paraissait si facile\n"
	.string "pourtant.\p"
	.string "Et elles m’ont retourné...\p"
	.string "...\p"
	.string "Tu es là pour les combattre, toi\n"
	.string "aussi?\p"
	.string "Te réjouis pas\n"
	.string "trop vite parce\p"
	.string "que t’as flanqué sa\n"
	.string "raclée à la Rocket.\p"
	.string "Ces 5 nanas, elles sont vraiment\n"
	.string "hyper\p"
	.string "fortes.\p"
	.string "Allez, vas-y!\p"
	.string "Essaye!\p"
	.string "Je ne retourne pas dedans. Je ne\n"
	.string "peux pas te voir gagner...$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "ÉVOLI: Voli!$"

EcruteakCity_Text_Vulpix:
	.string "GOUPIX: Gouuu Pix!$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "Oh non de non...\p"
	.string "Ma soeur n'est plus là.\p"
	.string "Noonn... Elle ne peut pas être\n"
	.string "partie à la TOUR CENDREE.\p"
	.string "Je lui avais dit de ne pas y\n"
	.string "aller.\p"
	.string "Les gens y disparaissent!\p"
	.string "Mais que dois-je faire...?$"

EcruteakCity_Text_Gramps1:
	.string "ROSALIA avait deux tours:\p"
	.string "une à l'Est, l'autre à l'Ouest.$"

EcruteakCity_Text_Gramps2:
	.string "Ah... As-tu appris à\p"
	.string "danser comme les KIMONO?\p"
	.string "Si tu vas dans leur SALLE de\p"
	.string "DANSE, un vieil homme bizarre te\n"
	.string "donnera un cadeau.$"

EcruteakCity_Text_Lass1:
	.string "Je vais m'entraîner à la SALLE\n"
	.string "de\p"
	.string "DANSE, tu viens avec moi?$"

EcruteakCity_Text_Lass2:
	.string "La tour qui se dressait ici...\p"
	.string "Ma grand-mère m'a dit qu'elle\n"
	.string "était autrefois bien plus haute.\p"
	.string "Il paraît que des fantômes\n"
	.string "la hantent maintenant.$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Trois gros Pokémon\n"
	.string "se sont enfuis\p"
	.string "dans des directions\n"
	.string "différentes.\p"
	.string "Qu’est-ce qui se trame?$"

EcruteakCity_Text_Fisher:
	.string "Il y a une rumeur qui court sur\n"
	.string "le PHARE D'OLIVILLE.\p"
	.string "Le Pokémon qui était au PHARE\p"
	.string "est tombé malade. Tout ça c'est\n"
	.string "pas bon signe.$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "Le Pokémon du PHARE D'OLIVILLE a\n"
	.string "été soigné.\p"
	.string "Les bateaux peuvent de nouveau\n"
	.string "naviguer de nuit sans soucis.$"

EcruteakCity_Text_Youngster:
	.string "On dit que les Pokémon sont\p"
	.string "déchaînés au LAC COLERE.\n"
	.string "J'aimerais bien voir ça.$"

EcruteakCity_Text_Gramps3:
	.string "Il y a bien longtemps...\p"
	.string "La tour prit feu. 3 Pokémon\n"
	.string "inconnus\p"
	.string "périrent alors dans les flammes.\p"
	.string "Un Pokémon aux couleurs\n"
	.string "de l'arcen-ciel\p"
	.string "descendit du ciel\n"
	.string "et les ressuscita...\p"
	.string "Cette légende est connue de tous\n"
	.string "les\p"
	.string "CHAMPIONS de ROSALIA.\p"
	.string "Moi?\p"
	.string "J'étais dresseur à l'époque.\n"
	.string "Hohoho!$"

EcruteakCity_Text_SageGym:
	.string "MORTIMER, le Champion d'Arène,\n"
	.string "n'est pas ici pour l'instant.\p"
	.string "Tu le trouveras peut-être à la\n"
	.string "TOUR CENDREE.$"

EcruteakCity_Text_Sign:
	.string "ROSALIA Une ville bien\p"
	.string "historique où le Passé et le\n"
	.string "Présent se rencontrent$"

EcruteakCity_Text_TinTowerSign:
	.string "TOUR FERRAILLE\p"
	.string "Un Pokémon légendaire y est\n"
	.string "soi-disant perché.$"

EcruteakCity_Text_OfficeSign:
	.string "POSTE DE CONTRÔLE DE LA\n"
	.string "TOUR FERRAILLE\p"
	.string "ACCÈS INTERDIT AUX INDIGNES$"

EcruteakCity_Text_GymSign:
	.string "Arène de Rosalia Champion:\n"
	.string "Mortimer\p"
	.string "L’apprenti aux dons de\n"
	.string "clairvoyance$"

EcruteakCity_Text_DanceTheaterSign:
	.string "Salle de Danse de Rosalia De son\n"
	.string "vrai nom, salle de spectacle$"

EcruteakCity_Text_BurnedTowerSign:
	.string "Tour Cendrée\p"
	.string "Détruite par un\n"
	.string "mystérieux incendie.\p"
	.string "Restez à l’écart\n"
	.string "pour votre propre\p"
	.string "sécurité.$"
