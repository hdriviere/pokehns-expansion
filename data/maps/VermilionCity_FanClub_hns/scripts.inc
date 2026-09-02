VermilionCity_FanClub_hns_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "Je suis le PRESIDENT du FAN CLUB\n"
	.string "Pokémon.\p"
	.string "J'ai élevé plus de 150 Pokémon.\p"
	.string "Je suis très difficile quand il\n"
	.string "s'agit de Pokémon.\p"
	.string "Tu es ici pour en apprendre plus\n"
	.string "sur mes Pokémon?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "Bien! Alors, écoute!\p"
	.string "Mon préféré... GALOPA...\p"
	.string "Il est mignon...\n"
	.string "beau...rapide... élégant...en\p"
	.string "feu. Il fait pataclop,\n"
	.string "pataclop...quand il\p"
	.string "court...c'est super non? Je\n"
	.string "l'aime...!\p"
	.string "Je lui fais...des\n"
	.string "câlins...des...\p"
	.string "poutoux...des... gnangnans...des\n"
	.string "zigouzigoux... ...Oups!\p"
	.string "Regarde l'heure! Je crois\n"
	.string "qu'il est temps d'y aller!$"

PokemonFanClub_Text_Chairman_Gift:
	.string "Merci de m'avoir écouté... Voilà\n"
	.string "pour toi!$"

PokemonFanClub_Text_Chairman_Candy:
	.string "Un Super Bonbon, ça rend les\n"
	.string "Pokémon plus forts!\p"
	.string "Moi je préfère les\n"
	.string "renforcer en faisant\p"
	.string "des combats, alors\n"
	.string "il est pour toi.$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "Salut salut, {PLAYER}!\p"
	.string "Tu es ici pour\n"
	.string "profiter encore\p"
	.string "de mon immense\n"
	.string "expérience en Pokémon?\p"
	.string "Hein? Non? Oh... Pfff... C’est\n"
	.string "nul.$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "Dommage...\p"
	.string "Reviens me voir vite.$"

PokemonFanClub_Text_Receptionist:
	.string "Notre Président ne s’arrête\n"
	.string "jamais de parler de Pokémon...$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "J'aime quand MELOFEE gigote son\p"
	.string "doigt quand il utilise son\p"
	.string "METRONOME. C'est adorable!$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "J’adore MELOFEE,\n"
	.string "mais je n’ai\p"
	.string "toujours pas réussi\n"
	.string "à en attraper un.\p"
	.string "Tant pis! Je m’amuse avec cette\n"
	.string "Poképoupée\p"
	.string "que j’ai trouvée...$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "Oh, je vois. La fille qui a\n"
	.string "perdu\p"
	.string "sa Poké POUPEE est triste...\p"
	.string "OK. Peux-tu porter cette Poké\n"
	.string "POUPEE\p"
	.string "à la pauvre petite fille triste?\p"
	.string "Je trouverai un vrai MELOFEE...$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "J’attraperai un MELOFEE et il\n"
	.string "sera mon ami pour la vie!$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "Regarde donc mon MACRONIUM!\p"
	.string "La feuille sur sa tête est\n"
	.string "mignonne!$"

PokemonFanClub_Text_ClefairyDoll:
	.string "C'est un MELOFEE! Hein?\p"
	.string "Ah, d'accord. C'est une Poké Poupée\n"
	.string "d'un MELOFEE.$"

PokemonFanClub_Text_Bayleef:
	.string "MACRONIUM: Niuuum!$"

PokemonFanClub_Text_Listen:
	.string "Si un Dresseur se vante devant\n"
	.string "vous, écoutez-le patiemment!$"

PokemonFanClub_Text_Bragging:
	.string "Si un Dresseur se vante devant\n"
	.string "vous, vantez-vous dix fois plus!$"
