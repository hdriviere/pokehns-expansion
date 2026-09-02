Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "J’avais envie de vider mon sac,\n"
	.string "mais...\p"
	.string "Bon, va pour un combat!$"

Route47_Text_HikerBeaten::
	.string "Wahaha!$"

Route47_Text_HikerAfter::
	.string "On va se quitter sur un bel\n"
	.string "éclat de rire!$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "Je supporte mal la foule, alors\n"
	.string "je campe ici avec mes Pokémon!$"

Route47_Text_CamperBeaten::
	.string "Bon, on va songer à s’isoler\n"
	.string "plus.$"

Route47_Text_CamperAfter::
	.string "À plus!$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "SERGE: Un plus un font deux.\n"
	.string "Mais\l"
	.string "ensemble, nous sommes bien plus\l"
	.string "forts!\p"
	.string "DOM: Nous ne formons pas un\n"
	.string "couple banal!$"

Route47_Text_Couple1Beaten::
	.string "SERGE: Je ne m'y attendais pas.\l"
	.string "DOM: Toi aussi, tu sors du lot!$"

Route47_Text_Couple1After1::
	.string "Serge: Ta force est\n"
	.string "incalculable!$"

Route47_Text_Couple1After2::
	.string "Dom: Je pensais que tu étais un\n"
	.string "simple Dresseur...$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "LUDO: Veiller sur ma petite amie\n"
	.string "fait bondir mon cœur!\p"
	.string "DALIA: Mes sentiments pour mon\n"
	.string "petit ami sont aussi vastes et\l"
	.string "profonds que l'océan!$"

Route47_Text_Couple2Beaten::
	.string "LUDO: Je n'ai pas fait le poids!\l"
	.string "DALIA: Tu es impressionnant...$"

Route47_Text_Couple2After1::
	.string "Ludo: Merci pour ce passionnant\n"
	.string "combat! Bon voyage!$"

Route47_Text_Couple2After2::
	.string "Dalia: J’espère que\n"
	.string "tu trouveras toi\p"
	.string "aussi un formidable\n"
	.string "partenaire!$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "Hé, salut toi!\p"
	.string "On raconte que de\n"
	.string "l’autre côté de cette\p"
	.string "grotte s’élevait\n"
	.string "une tour géante\p"
	.string "qui allait jusqu’au ciel!\p"
	.string "Il paraît qu’elle avait une\n"
	.string "structure un peu bizarre...\p"
	.string "Pour moitié, elle avait été\n"
	.string "bâtie sur cette falaise, mais...\p"
	.string "En plus de s’élancer\n"
	.string "vers le ciel, elle\p"
	.string "s’enfonçait aussi\n"
	.string "loin dans le sol!\p"
	.string "Et même, jusqu’à l’océan!\p"
	.string "Ces ruines reliaient donc le\n"
	.string "ciel, la terre et la mer!\p"
	.string "Il n’en reste plus\n"
	.string "grand-chose de\p"
	.string "nos jours, à part\n"
	.string "l’entrée et un hall\p"
	.string "couvert de signes étranges...$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "LOUPIO: Lou!$"
