CeladonCity_Apartments_3F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "Mmmmoui?\p"
	.string "Je suis le DESIGNER du JEU!\p"
	.string "Continue à remplir ton Pokédex!$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "Whoa! Super! Tu as complété ton\n"
	.string "Pokédex!\p"
	.string "Formidable!$"

GameFreak_Text_GraphicArtist:
	.string "Je suis l'ARTISTE GRAPHIQUE.\p"
	.string "J'ai fait ton dessin!$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "Je suis l'ARTISTE GRAPHIQUE.\p"
	.string "Tu as complété ton Pokédex?\p"
	.string "Tu veux que j'imprime ton\n"
	.string "DIPLOME?$"

GameFreak_Text_GraphicArtistRefused:
	.string "Appelle-moi si tu veux que\n"
	.string "j'imprime ton DIPLOME.$"

GameFreak_Text_GraphicArtistError:
	.string "Ca ne marche pas. Je ne peux pas\n"
	.string "imprimer.$"

GameFreak_Text_Programmer:
	.string "Moi? Je suis le PROGRAMMEUR.\p"
	.string "Joue aux machines à sous!$"

GameFreak_Text_CharacterDesigner:
	.string "Les JUMELLES sont pas trop mimi?\p"
	.string "JASMINE est trop jolie, non?\p"
	.string "Je...les aime!$"

CeladonMansion3F_Text_DevRoomSign:
	.string "GAME FREAK Salle de\n"
	.string "Développement$"

CeladonMansion3F_Text_Drawing:
	.string "C'est le dessin d'une jolie\n"
	.string "fille.$"

CeladonMansion3F_Text_GameProgram:
	.string "C'est le programme du jeu. Si on\n"
	.string "y\p"
	.string "touche, il y aura des bogues!$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "C'est rempli de documents de\n"
	.string "référence. Il y a même une\l"
	.string "POKéPOUPÉE.$"
