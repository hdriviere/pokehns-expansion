LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad:
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame:
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
	lockall
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
#ifdef UBFIX
	setvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
#else
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE
#endif
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
	.string "Notre salle d’œuvres\n"
	.string "contemporaines!$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
	.string "Comme il est facile de le\n"
	.string "constater, il n’y a pas un seul\p"
	.string "tableau exposé.\p"
	.string "Je ne souhaite pas exposer\n"
	.string "d’œuvres dites “classiques” ici.\p"
	.string "Les œuvres de ce type ont déjà\n"
	.string "leur place au rez-de-chaussée.\p"
	.string "Mon désir est d’exposer des\n"
	.string "œuvres qui se distinguent de\p"
	.string "l’art classique.\p"
	.string "L’art, après tout, ne se limite\n"
	.string "pas aux anciennes œuvres\p"
	.string "célèbres!\p"
	.string "Cette salle, je désire l’emplir…\p"
	.string "d’œuvres modernes et pleines de\n"
	.string "vie représentant des POKéMON\p"
	.string "prêts à s’élancer dans une vie\n"
	.string "heureuse!$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
	.string "Je m’excuse. Je n’avais pas\n"
	.string "l’intention de monopoliser la\p"
	.string "conversation.\p"
	.string "Tu es jeune et as déjà beaucoup\n"
	.string "voyagé…\p"
	.string "Tu as dû voir des POKéMON pleins\n"
	.string "de vie et des œuvres les\p"
	.string "dépeignant.\p"
	.string "Si tu découvrais une telle\n"
	.string "œuvre, nous te serions\p"
	.string "reconnaissants de bien vouloir\n"
	.string "obtenir la permission de\p"
	.string "l’artiste pour l’exposer ici.$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
	.string "J’aimerais emplir cette salle de\n"
	.string "tableaux modernes et pleins de\p"
	.string "vie représentant des POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
	.string "Merci. Grâce à toi, nous avons\n"
	.string "ajouté un nouveau tableau à\p"
	.string "notre collection!\p"
	.string "Il paraît qu’il représente ton\n"
	.string "POKéMON. Vraiment magnifique!\p"
	.string "Merci beaucoup!$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
	.string "Ah, c’est toi! {PLAYER}!$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
	.string "N’est-ce pas fabuleux? Cette\n"
	.string "collection de tableaux!\p"
	.string "Tous parfaits! Il n’y en a pas\n"
	.string "un meilleur que les autres!\p"
	.string "Ces tableaux ont fait augmenter\n"
	.string "le nombre de visiteurs dans\p"
	.string "notre MUSEE.\p"
	.string "Merci vraiment, {PLAYER}. Mon\n"
	.string "rêve est devenu réalité!$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
	.string "Voici un gage de ma\n"
	.string "reconnaissance.$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
	.string "Je vais le garder pour toi\n"
	.string "jusqu’à notre prochaine\p"
	.string "rencontre.$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
	.string "Ah, ça fait plaisir de te voir,\n"
	.string "{PLAYER}!\p"
	.string "Quel honneur que tu trouves le\n"
	.string "temps de nous rendre visite\p"
	.string "entre tes voyages!\p"
	.string "Détends-toi et apprécie ta venue\n"
	.string "à nos côtés.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
	.string "C’est un cadre à ornements\n"
	.string "roses.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
	.string "C’est un cadre à ornements\n"
	.string "jaunes.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
	.string "C’est un cadre à ornements\n"
	.string "bleus.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
	.string "C’est un cadre à ornements\n"
	.string "rouges.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
	.string "C’est un cadre à ornements\n"
	.string "verts.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
	.string "C’est un tableau de POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
	.string "J’ai été absente longtemps.\n"
	.string "Alors les tableaux à l’étage me\p"
	.string "surprennent.\p"
	.string "J’aimerais bien que quelqu’un\n"
	.string "peigne mes POKéMON comme ça.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
	.string "Alors voilà où sont exposés les\n"
	.string "tableaux à thèmes de POKéMON.\p"
	.string "Je vois, ces nouveaux tableaux\n"
	.string "sont effectivement très\p"
	.string "amusants.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
	.string "Waouh, c’est vrai? Ces tableaux\n"
	.string "représentent tes POKéMON.\p"
	.string "N’est-ce pas la joie ultime pour\n"
	.string "un DRESSEUR?$"

