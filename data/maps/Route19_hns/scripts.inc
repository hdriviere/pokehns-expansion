Route19_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD_HNS, Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER_HNS, Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN_HNS, Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME_HNS, Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_EventScript_Item_Brine::
    finditem ITEM_TM_BRINE
    end

Route19_Text_SwimmermHaroldSeen:
	.string "As-tu déjà nagé au clair de\n"
	.string "lune?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Glub...$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "Un bain de minuit, c'est trop\n"
	.string "génial.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Pfff...pfff... PARMANIE..n'est..\p"
	.string "plus...très... loin...!$"

Route19_Text_SwimmermTuckerBeaten:
	.string "Je me noie!$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "J'ai demandé à ma copine de\n"
	.string "nager jusqu'à PARMANIE.$"

Route19_Text_SwimmerfDawnSeen:
	.string "Je DETESTE les gens désordonnés.$"

Route19_Text_SwimmerfDawnBeaten:
	.string "Pourtant, à la nage, je te\n"
	.string "bats...$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "Allez, fais-moi\n"
	.string "un aller-retour\p"
	.string "entre Parmanie et\n"
	.string "les Iles Ecume.\p"
	.string "Tu en es capable, non?$"

Route19_Text_SwimmermJeromeSeen:
	.string "Nager? Non merci. Je préfère\n"
	.string "faire trempette au bord.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "J’ai cru pouvoir gagner...$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "J’aime pas nager mais j’adore la\n"
	.string "mer!$"

Route19_Text_Fisher1:
	.string "Cette route est fermée pour\n"
	.string "cause de travaux.\p"
	.string "Pour aller à\n"
	.string "Cramois’Ile, il faut\p"
	.string "prendre par le sud\n"
	.string "de Bourg Palette.$"

Route19_Text_Kingler:
	.string "KRABBOSS: KEEEEEEEEEEEE$"

Route19_Text_Fisher1_RocksCleared:
	.string "Je dégouline de sueur... Allez!\n"
	.string "A l’eau!$"

Route19_Text_Fisher2:
	.string "Oh non, KRABBOSS bloque\n"
	.string "la plage.$"

Route19_Text_FisherBefore:
	.string "Tant que les KRABBOSS sont là,\n"
	.string "pas de pêche.$"

Route19_Text_Fisher2_RocksCleared:
	.string "Ces KRABBOSS sont enfin partis!\p"
	.string "Je peux retourner pêcher.$"

Route19_Text_Sign:
	.string "ROUTE 19\p"
	.string "PARMANIE ILES ECUME$"

Route19_Text_CarefulSwimmingSign:
	.string "Nagez prudemment si vous vous\n"
	.string "dirigez vers les ILES ECUME.\p"
	.string "POLICE de PARMANIE$"
