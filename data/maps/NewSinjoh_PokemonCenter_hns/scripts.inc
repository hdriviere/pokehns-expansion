NewSinjoh_PokemonCenter_hns_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewSinjoh_PokemonCenter_OnTransition
    .byte 0

NewSinjoh_PokemonCenter_OnTransition: 
    setrespawn HEAL_LOCATION_NEW_SINJOH_HNS
    end

NewSinjoh_EventScript_Artist::
	lock
	faceplayer
	goto_if_set FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT, NewSinjoh_EventScript_ZoomLens_Gotten
	msgbox NewSinjoh_Text_Artist, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewSinjoh_EventScript_ZoomLens_No
	msgbox Text_ItemGiveaway, MSGBOX_DEFAULT
	giveitem ITEM_ZOOM_LENS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_NEWSINJOH_POKEMONCENTER_ARTIST_GIFT
	release
	end

NewSinjoh_PokemonCenter_EventScript_Skiier::
	lock
	faceplayer
	msgbox NewSinjoh_PokemonCenter_Text_Skiier, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_NEWSINJOH_POKEMONCENTER_SKIIER, DIR_NORTH
	release
	end

NewSinjoh_PokemonCenter_hns_Map::
	lockall
	setvar VAR_0x8000, 1 @ SCREENSHOT_SINJOH_MAP
	msgbox NewSinjoh_PokemonCenter_hns_Text_0, MSGBOX_DEFAULT
	closemessage
	callnative OpenScreenshotsFromScript
	waitstate
	releaseall
	end

NewSinjoh_PokemonCenter_Text_Skiier:
	.string "La neige complique les\n"
	.string "déplacements ici.\p"
	.string "Tout se ressemble.\p"
	.string "Cette carte est bien utile!\p"
	.string "Quelle belle région!$"

NewSinjoh_Text_Artist:
	.string "Cette ville cachée m'inspire\n"
	.string "énormément!\p"
	.string "Tu ne trouves pas ce paysage\n"
    .string "époustouflant?$"

Text_ItemGiveaway:
	.string "Je vois!\n"
	.string "Tu dois aussi être artiste!\p"
	.string "J'ai justement un objet en plus\n"
	.string "qui t'aidera à remarquer les\l"
    .string "petits détails de la vie!$"

NewSinjoh_Text_Artist_No:
    .string "Tu n'es pas anti-touristes,\n"
    .string "au moins?\p"
	.string "La beauté doit être partagée.$"

NewSinjoh_EventScript_ZoomLens_No::
	msgbox NewSinjoh_Text_Artist_No, MSGBOX_DEFAULT
	release
	end

NewSinjoh_EventScript_ZoomLens_Gotten::
	msgbox Text_WasGiven_ZoomLensAlready, MSGBOX_DEFAULT
	release
	end

Text_WasGiven_ZoomLensAlready:
	.string "J'espère que cette lentille te\n"
	.string "plaît!$"

NewSinjoh_EventScript_FemAce::
	msgbox NewSinjoh_Text_FemAce, MSGBOX_NPC
	end

NewSinjoh_Text_FemAce:
	.string "Nous n'avons guère de commodités\n"
	.string "modernes au NOUVEAU SINJOH.\p"
	.string "Mais au moins, nous avons ce\n"
	.string "CENTRE POKéMON.$"

NewSinjoh_PokemonCenter_hns_Text_0:
	.string "{PLAYER} regarde de plus près la\n"
	.string "carte de SINJOH.$"
