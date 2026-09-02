OneIsland_KindleRoad_EmberSpa_Frlg_MapScripts::
	.byte 0

OneIsland_KindleRoad_EmberSpa_EventScript_OldMan::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan1::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan2::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_OldWoman::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BlackBelt::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 3
	msgbox OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_RockSmashMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM06, OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa
	giveitem ITEM_HM06
	setflag FLAG_GOT_HM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_SpaHeal::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed
	setvar VAR_TEMP_1, 1
	releaseall
	end

OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore::
	.string "Hmmm… Haaa…\p"
	.string "C'est trop bon! Je suis\n"
	.string "complètement détendu…\p"
	.string "Saute dedans, tu verras comme ça\n"
	.string "fait du bien.\p"
	.string "Va au milieu, relaxe-toi et tu\n"
	.string "m'en diras des nouvelles.$"

OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder::
	.string "Le moment que je préfère vient\n"
	.string "juste après.\p"
	.string "Rien de mieux qu'un bol de soupe\n"
	.string "pour se réchauffer de\p"
	.string "l'intérieur!$"

OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed::
	.string "Cette eau est à la température\n"
	.string "idéale. C'est le bonheur…\p"
	.string "{PLAYER} et ses POKéMON\n"
	.string "retrouvent toute leur énergie.$"

OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic::
	.string "Rien de mieux pour le corps que\n"
	.string "de se relaxer dans l'eau chaude.$"

OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs::
	.string "Regarde-moi bien. Tu vois comme\n"
	.string "ma peau est belle et lisse?\p"
	.string "C'est grâce à l'eau de la source\n"
	.string "si j'ai l'air plus jeune que mon\p"
	.string "âge.$"

OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion::
	.string "Après une journée\n"
	.string "d'entraînement, il suffit de se\p"
	.string "plonger dans ce\p"
	.string "bassin pour retrouver la forme.\n"
	.string "D'ailleurs, ALDO vient souvent\p"
	.string "ici.\p"
	.string "Il vient pour soigner ses\n"
	.string "blessures et celles de ses\p"
	.string "POKéMON.$"

OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa::
	.string "Les sources thermales existent\n"
	.string "grâce aux volcans.\p"
	.string "J'ai créé la SOURCE BRAISE il y\n"
	.string "a bien longtemps.\p"
	.string "J'ai creusé le bassin en me\n"
	.string "débarrassant des rochers à\p"
	.string "la force de mes poignets.\p"
	.string "J'utilisais ça à l'époque, je\n"
	.string "pense que ça pourrait t'être\p"
	.string "utile.$"

OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06::
	.string "Avec ça, tu peux briser la roche\n"
	.string "comme si c'était du verre.$"

