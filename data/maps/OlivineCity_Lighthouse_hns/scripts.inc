OlivineCity_Lighthouse_hns_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMSwagger::
    finditem ITEM_TM_SWAGGER
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "Les gens s'entraînent\n"
	.string "dans ce PHARE.\p"
	.string "L'ascension est difficile avec\n"
	.string "tous les Dresseurs présents.$"

OlivineLighthouse_Text_1FPokefanF:
	.string "Autrefois, des Pokémon\n"
	.string "éclairaient la mer autour\l"
	.string "d'OLIVILLE la nuit.\p"
	.string "Le PHARE fut construit\n"
	.string "en l'honneurl"
	.string "de ces nobles Pokémon.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY_HNS, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten, OlivineLighthouse_EventScript_RegisterHuey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OlivineLighthouse_EventScript_RematchHuey
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_RegisterHuey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox OlivineLighthouse_Text_HueyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_HUEY_HNS
	release
	end

OlivineLighthouse_EventScript_RematchHuey::
	trainerbattle_rematch TRAINER_HUEY_HNS, OlivineLighthouse_Text_HueyRematchIntro, OlivineLighthouse_Text_HueyRematchDefeat
	msgbox OlivineLighthouse_Text_HueyPostRematch, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED_HNS, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "Les Marins sont toujours\n"
	.string "partants pour chercher querelle!$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "Humpf! Perdu!$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "Tu m’plais bien! Ça te dirait de\n"
	.string "voyager ensemble?$"

OlivineLighthouse_Text_HueyRegister:
	.string "Tu m’plais bien! Ça te dirait de\n"
	.string "voyager ensemble?$"

OlivineLighthouse_Text_HueyRematchIntro:
	.string "Les Marins sont toujours\n"
	.string "partants pour chercher querelle!$"

OlivineLighthouse_Text_HueyRematchDefeat:
	.string "Humpf! Perdu!$"

OlivineLighthouse_Text_HueyPostRematch:
	.string "Tu m’plais bien! Ça te dirait de\n"
	.string "voyager ensemble?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "Hé! C'est interdit de jouer\n"
	.string "ici...$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "Ah! Tu rigoles pas, toi.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Au sommet vit le Pokémon qui\n"
	.string "maintient le PHARE allumé.\p"
	.string "Mais il paraît qu'il est malade\n"
	.string "et qu'un remède ordinaire\n"
	.string "ne suffit pas.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO_HNS, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL_HNS, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON_HNS, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "Pourquoi tu es là? Qu'est-ce que\n"
	.string "tu\p"
	.string "veux? Allez... Va-t'en!$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "Le Pokémon malade t'inquiète\n"
	.string "vraiment...$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "Comment tu fais pour monter?\p"
	.string "Je veux voir le Pokémon malade,\p"
	.string "mais j'arrive pas à monter...$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Les Marins allient la douceur et\n"
	.string "la force. Et toi?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "Toi aussi, tu as de la douceur\n"
	.string "et de la force quand tu te bats.$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Chaque fois que je reviens à\n"
	.string "OLIVILLE, je visite l'ARENE.\p"
	.string "Le type de Pokémon utilisé\n"
	.string "par la Championne a changé\l"
	.string "sans que je le remarque.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Je parcours la terre en quête\n"
	.string "d'entraînement. En garde!$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "Bon. Je vais errer autre part\n"
	.string "alors.$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "JASMINE utilisait autrefois des\n"
	.string "Pokémon de type ROCHE,\n"
	.string "comme ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT_HNS, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE_HNS, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "Jasmine doit\n"
	.string "s’inquiéter à propos\p"
	.string "de son Pokémon. Elle\n"
	.string "ne sourit même plus.$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "Moi non plus... J'souris plus...$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "Au fait, je crois qu'il y a une\n"
	.string "bonne PHARMACIE à IRISIA.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "JASMINE est la CHAMPIONNE de\n"
	.string "cette ville.\p"
	.string "Et moi j'suis plus forte\n"
	.string "qu'elle.\p"
	.string "Et ça... Tu vas le comprendre!$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "Aaah! Mes Pokémon!$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "Chaque dresseur est responsable\n"
	.string "de la santé de ses Pokémon.\p"
	.string "Je prie pour le Pokémon, ainsi\p"
	.string "JASMINE reviendra à l'ARENE.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST_HNS, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS_HNS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "Je voulais défier JASMINE mais\n"
	.string "ce\p"
	.string "n'est pas le moment. Et toi, ça\n"
	.string "te tente?$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "Fouiiii! T'es trop, toi!$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "Un CHAMPION n'est pas seulement\n"
	.string "fort\p"
	.string "mais il se doit d'être aussi\n"
	.string "compatissant.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "C’est haut ici! Mes Pokémon\n"
	.string "Oiseaux sont en super forme!$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Mayday! Mayday! C’est la super\n"
	.string "cata!$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "Mon Pokémon a appris VOL à\n"
	.string "IRISIA.\p"
	.string "Et puisque j'ai perdu, je vais\n"
	.string "VOLER autre part!$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "Jasmine: ...\n"
	.string "Ce Pokémon\p"
	.string "éclairait la mer\n"
	.string "en permanence...\p"
	.string "... Mais... Il est tombé malade\n"
	.string "tout d’un coup...\p"
	.string "Il a du mal à respirer...\p"
	.string "On dit qu’il y a\n"
	.string "une bonne pharmacie\p"
	.string "de l’autre côté de\n"
	.string "la mer, à Irisia...\p"
	.string "Mais je ne peux pas laisser\n"
	.string "Phary tout seul!\p"
	.string "Euh... Est-ce que\n"
	.string "je peux te demander\p"
	.string "d’aller y chercher\n"
	.string "un médicament\p"
	.string "à ma place? Je t’en prie!\p"
	.string "Je t’ouvre le passage ici...$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "Je... Je t’en prie! Va chercher\n"
	.string "le médicament\p"
	.string "à ma place! Par pitié!$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "Il y a une excellente PHARMACIE\n"
	.string "à IRISIA...\p"
	.string "Mais c'est de l'autre côté\n"
	.string "de la mer...\p"
	.string "Et je ne peux pas laisser\n"
	.string "PHARY seul...\p"
	.string "...Peux-tu aller me chercher\n"
	.string "un médicament? Je t'en prie.$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "JASMINE: ...Ce médicament\n"
	.string "va-t-il soigner PHARY?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playfanfare MUS_HEAL
	waitfanfare
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} donne la POTIONSECRET à\n"
	.string "JASMINE.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "JASMINE: Heu... Le prends pas\n"
	.string "mal mais...\p"
	.string "PHARY n'accepte que ce que JE\n"
	.string "lui donne...$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "JASMINE: ...\p"
	.string "PHARY, comment te sens-tu?$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "JASMINE: ...Oh,\n"
	.string "quel soulagement...\p"
	.string "C'est vraiment merveilleux...\p"
	.string "Merci infiniment.\p"
	.string "...Je retourne à l'ARENE...\p"
	.string "Je préfère aussi te prévenir:\n"
	.string "le type ACIER est puissant.$"

OlivineLighthouse_Text_JasmineISee:
	.string "JASMINE: ...Je vois...\n"
	.string "...PHARY, tiens bon!$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "PHARY: ... ...Pha! Phaaa...$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Il respire avec difficulté...$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "PHARY: Phapha! Phaaaaaa!$"
