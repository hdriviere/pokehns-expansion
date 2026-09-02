LavenderTown_RadioStation_hns_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "Bienvenue! Tu peux visiter\p"
	.string "cet étage tant que tu le veux.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Seul le rez-de-chaussée est\n"
	.string "visitable.\p"
	.string "Depuis l’attaque\n"
	.string "de la Tour Radio de\p"
	.string "Johto par un gang\n"
	.string "criminel, les mesures\p"
	.string "de sécurité ont été renforcées.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Les gens travaillent dur ici, à\n"
	.string "la TOUR RADIO.\p"
	.string "Ils se donnent à fond pour faire\n"
	.string "de bonnes émissions.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "Oh, non, non, non!\p"
	.string "Maintenant que la\n"
	.string "Centrale a cessé de\p"
	.string "fonctionner, nous\n"
	.string "ne pouvons plus rien\p"
	.string "diffuser!\p"
	.string "Juste quand on commençait à\n"
	.string "émettre! Je suis ruiné!$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah! C'est toi {PLAYER} qui a\p"
	.string "réparé la CENTRALE?\p"
	.string "Grâce à toi, j'ai pu garder mon\n"
	.string "job. Tu es trop cool!\p"
	.string "Prends ça!$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} obtient l'EXTENSION\n"
	.string "RADIO!$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "Avec ceci, tu peux écouter la\n"
	.string "radio depuis KANTO.\p"
	.string "Gahahahaha!$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Salut!\p"
	.string "Je suis le DIRECTEUR MUSICAL!\p"
	.string "Hein? Ta RADIO ne capte pas mes\n" @POKéGEAR
	.string "émissions. Quel dommage!\p"
	.string "Avec une EXTENSION RADIO, tu\n"
	.string "pourras les écouter. Tu ferais\l"
	.string "bien d'en obtenir une!$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "Salut, bonjour, hello! Je suis\n"
	.string "le super directeur musical!\p"
	.string "On diffuse de super mélodies à\n"
	.string "l’antenne! Ecoute-nous!$"

LavenderTown_RadioStation_Text_Directory:
	.string "RC: Réception 1{SUPER_ER}:\n"
	.string "Produits dérivés\p"
	.string "2{SUPER_E}: Personnel\p"
	.string "3{SUPER_E}: Production\p"
	.string "4{SUPER_E}: Bureau du Directeur$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Réveillez vos Pokémon au doux\n"
	.string "son de la FLÛTE POKé sur\l"
	.string "le CANAL 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Whoa! Plein de cassettes et de\n"
	.string "CD Pokémon!\p"
	.string "Ca doit être une librairie\n"
	.string "officielle.$"
