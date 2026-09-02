Route9_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN_HNS, Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI_HNS, Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA_HNS, Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID_HNS, Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM_HNS, Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY_HNS, Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_EventScript_Item_Flash_Cannon::
    finditem ITEM_TM_FLASH_CANNON
    end

Route9_Text_CamperDeanSeen:
	.string "Je viens pour explorer la\n"
	.string "GROTTE.$"

Route9_Text_CamperDeanBeaten:
	.string "Whoa! Danger!$"

Route9_Text_CamperDeanAfter:
	.string "Mes Pokémon ont été blessés\n"
	.string "avant\p"
	.string "d'entrer dans la GROTTE.\p"
	.string "Je devrais les amener à un\n"
	.string "CENTRE Pokémon...$"

Route9_Text_PicnickerHeidiSeen:
	.string "Tu aimes les pique-niques? C'est\n"
	.string "trop cool!$"

Route9_Text_PicnickerHeidiBeaten:
	.string "Ohhhh!$"

Route9_Text_PicnickerHeidiAfter:
	.string "On mange comme des truies et on\p"
	.string "fait des miettes. C'est mortel!$"

Route9_Text_CamperSidSeen:
	.string "Toi, là! C’est interdit de jeter\n"
	.string "des déchets ici!$"

Route9_Text_CamperSidBeaten:
	.string "Je pensais bien faire...$"

Route9_Text_CamperSidAfter:
	.string "Je me suis trompé, je m’excuse.$"

Route9_Text_PicnickerEdnaSeen:
	.string "Pour protéger\n"
	.string "l’environnement,\p"
	.string "il faut ramener ses\n"
	.string "déchets à la maison.$"

Route9_Text_PicnickerEdnaBeaten:
	.string "Ohh...pas glop.$"

Route9_Text_PicnickerEdnaAfter:
	.string "Il faut économiser l’énergie. Et\n"
	.string "protéger l’environnement!$"

Route9_Text_HikerTimSeen:
	.string "Elle descend du MONT ARGENT à\n"
	.string "cheval... La la la la la...\p"
	.string "Le MONT ARGENT est à JOHTO, non?$"

Route9_Text_HikerTimBeaten:
	.string "C'est trop bien de chanter.$"

Route9_Text_HikerTimAfter:
	.string "La concentration est pourtant la\n"
	.string "clé!$"

Route9_Text_HikerSidneySeen:
	.string "J'ai un secret pour toi.\p"
	.string "Mais d'abord... Combat!$"

Route9_Text_HikerSidneyBeaten:
	.string "Zut de flûte! Perdu!$"

Route9_Text_HikerSidneyAfter:
	.string "La CENTRALE est de l'autre côté\n"
	.string "d'une rivière.$"

Route9_Text_Sign:
	.string "ROUTE 9\p"
	.string "AZURIA GROTTE$"
