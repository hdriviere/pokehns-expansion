SSAqua_B1F_hns_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
	.string "Beurk!\n"
	.string "Je n'aurais pas dû regarder!$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Hé toi. Tu peux chercher mon\n"
	.string "pote pour moi?\p"
	.string "Il se balade dans le coin.\n"
	.string "Toujours à rien faire!\p"
	.string "J'aimerais le trouver mais moi\n"
	.string "j'ai du taf.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "Oh, ben...\p"
	.string "Le CAPITAINE va être furax...$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "Merci toi! J'lui ai passé un\p"
	.string "savon des familles et il va\n"
	.string "bosser maintenant.$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "Une fillette?\p"
	.string "Je crois l'avoir vue passer.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "La salle à manger est tout\n"
	.string "droit.\p"
	.string "Les escaliers au bout mènent à\n"
	.string "la cabine du CAPITAINE.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF_HNS, SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "Y'a rien de tel qu'un combat\n"
	.string "pendant la pause.$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "Finie la pause!$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "Je ne deviendrai\n"
	.string "jamais fort si je\p"
	.string "ne m’entraîne pas\n"
	.string "sérieusement...$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA_HNS, SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "Quel ennui... Allez, on se fait\n"
	.string "un petit combat?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "Mais non quoi!$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "Safrania... Céladopole...\p"
	.string "On dit qu’il y a plein de\n"
	.string "grandes villes\p"
	.string "à Kanto.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ_HNS, SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "Beuh... J’ai le mal de mer!$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "J'peux plus bouger...$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "La mer, c’est fini\n"
	.string "pour moi. Je prendrai\p"
	.string "le Train Magnétique\n"
	.string "la prochaine fois.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT_HNS, SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "Tu es ici sur le lieu de travail\n"
	.string "sacré des Marins!$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "Battu à domicile!$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "Quand on va de Carmin\n"
	.string "sur Mer à Oliville,\p"
	.string "les passagers ne\n"
	.string "sont pas les mêmes.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH_HNS, SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "On est en mer\n"
	.string "mais on peut pas\p"
	.string "pêcher! Quel ennui!\n"
	.string "Allez... combat!$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "T'es naze... J't'aime pas.$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "Je vais pêcher au port de\n"
	.string "CARMIN.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI_HNS, SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "Je me muscle les jambes avec le\n"
	.string "tangage du bateau!$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "Je me suis complètement planté!$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "Je n’ai pas trouvé le Roi du\n"
	.string "Karaté à Johto.\p"
	.string "On dit qu’il s’entraîne dans une\n"
	.string "caverne...$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH_HNS, SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "J'suis un marin!\p"
	.string "J'entraîne aussi des Pokémon\n"
	.string "pour devenir un boss!$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "Je ne peux pas cacher mon manque\n"
	.string "d’entraînement!$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "Tant de BADGES! Tu as alors\n"
	.string "battu\p"
	.string "les CHAMPIONS des ARENES...\p"
	.string "Normal que tu sois balèze!$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY_HNS, SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "On ne touche pas à mes élèves!$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "Aaack!$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "On va tous aux RUINES près de\n"
	.string "MAUVILLE.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE_HNS, SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "Dis... Tu connais les Ruines\n"
	.string "d’Alpha?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "Yaargh!$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "Les radios captent d'étranges\n"
	.string "signaux dans les RUINES.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_HNS, SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "Il y a d'étranges panneaux dans\n"
	.string "les RUINES d'ALPHA.$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "Yaaaaaah!$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "J’ai lu qu’il y avait quatre\n"
	.string "panneaux de pierre.$"
