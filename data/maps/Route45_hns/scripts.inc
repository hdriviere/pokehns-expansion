Route45_hns_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK_HNS, Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL_HNS, Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY_HNS, Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten, Route45_EventScript_RegisterParry
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchParry
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterParry::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_ParryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PARRY_HNS
	release
	end

Route45_EventScript_RematchParry::
	trainerbattle_rematch TRAINER_PARRY_HNS, Route45_Text_ParryRematchIntro, Route45_Text_ParryRematchDefeat
	msgbox Route45_Text_ParryPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_HNS, Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI_HNS, Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten, Route45_EventScript_RegisterKenji
	goto_if_set FLAG_KENJI_HAS_ITEM_HNS, Route45_EventScript_KenjiGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route45_EventScript_RematchKenji
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RegisterKenji::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route45_Text_KenjiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KENJI_HNS
	release
	end

Route45_EventScript_RematchKenji::
	trainerbattle_rematch TRAINER_KENJI_HNS, Route45_Text_KenjiRematchIntro, Route45_Text_KenjiRematchDefeat
	msgbox Route45_Text_KenjiPostRematch, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiGiveItem::
	msgbox Route45_Text_KenjiHasItem, MSGBOX_DEFAULT
	giveitem VAR_KENJI_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route45_EventScript_KenjiNoRoom
	clearflag FLAG_KENJI_HAS_ITEM_HNS
	msgbox Route45_Text_KenjiGaveItem, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KenjiNoRoom::
	msgbox Route45_Text_KenjiNoRoom, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN_HNS, Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY_HNS, Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN_HNS, Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "Rien à craindre\n"
    .string "quand on est préparé!\p"
    .string "Voyons, ton équipe\n"
    .string "est bien entraînée?$"

Route45_Text_HikerErikBeaten:
    .string "Oh! Perdu!$"

Route45_Text_HikerErikAfter:
    .string "Je retourne à la Route de Glace\n"
    .string "d’Ebènelle pour m’entraîner.$"

Route45_Text_HikerMichaelSeen:
    .string "Toi, tu crains! Tu le sais, ça?\p"
    .string "Alors il faut se battre. Parce\n"
    .string "que j't'aime pas!$"

Route45_Text_HikerMichaelBeaten:
    .string "Bien joué!$"

Route45_Text_HikerMichaelAfter:
    .string "Moi j’aime les PV Plus! Mmmh!\p"
    .string "C’est pour les Pokémon mais j’en\n"
    .string "bois quand même! C’est trop bon!$"

Route45_Text_HikerParrySeen:
    .string "J'ai super boosté mes Pokémon!$"

Route45_Text_HikerParryBeaten:
    .string "Wahahah! J’ai perdu!$"

Route45_Text_HikerParryAfter:
    .string "Réfléchir, c'est pas mon truc.\p"
    .string "Alors, je cogne.$"

Route45_Text_ParryRegister:
    .string "Réfléchir, c'est pas mon truc.\p"
    .string "Alors, je cogne.$"

Route45_Text_ParryRematchIntro:
    .string "J'ai super boosté mes Pokémon!$"

Route45_Text_ParryRematchDefeat:
    .string "Wahahah! J’ai perdu!$"

Route45_Text_ParryPostRematch:
    .string "Réfléchir, c'est pas mon truc.\p"
    .string "Alors, je cogne.$"

Route45_Text_HikerTimothySeen:
    .string "Pourquoi j'aime l'escalade?\p"
    .string "Parce que j'aime la montagne.\p"
    .string "Pourquoi j'aime les Pokémon?\p"
    .string "Parce que j'aime combattre!$"

Route45_Text_HikerTimothyBeaten:
    .string "Mais... J'aime pas perdre!$"

Route45_Text_HikerTimothyAfter:
    .string "Découvrir le monde merveilleux\n"
    .string "des\p"
    .string "Pokémon a été un grand bonheur.$"

Route45_Text_HikerParryGivesIron:
    .string "Je n'arrive pas à gagner!\p"
    .string "Courage!\p"
    .string "Oh, prends ça... C'est le truc\n"
    .string "que\p"
    .string "tu ne pouvais pas prendre la\n"
    .string "dernière fois.$"

Route45_Text_BlackbeltKenjiSeen:
    .string "Je m'entraîne en solitaire.\p"
    .string "Et voilà le résultat!$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "Waaaargh!$"

Route45_Text_BlackbeltKenjiAfter:
    .string "Tu m’obliges à m’entraîner en\n"
    .string "ermite!$"

Route45_Text_KenjiRegister:
    .string "Tu m’obliges à m’entraîner en\n"
    .string "ermite!$"

Route45_Text_KenjiRematchIntro:
    .string "Je m'entraîne en solitaire.\p"
    .string "Et voilà le résultat!$"

Route45_Text_KenjiRematchDefeat:
    .string "Waaaargh!$"

Route45_Text_KenjiPostRematch:
    .string "Tu m’obliges à m’entraîner en\n"
    .string "ermite!$"

Route45_Text_KenjiHasItem:
    .string "Hé! Je fais une pause dans mon\n"
    .string "entraînement.\p"
    .string "J'ai trouvé quelque chose de\n"
    .string "bien en chemin. Tiens, prends!$"

Route45_Text_KenjiGaveItem:
    .string "Fais-en bon usage!\p"
    .string "Je dois reprendre mon\n"
    .string "entraînement. Oooooaaarrrgh!$"

Route45_Text_KenjiNoRoom:
    .string "Hmm, ton SAC est plein.\p"
    .string "Reviens quand tu auras de la\n"
    .string "place.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "Je vais encore m'entraîner avant\n"
    .string "de bouffer.$"

Route45_Text_BlackbeltKenjiNight:
    .string "On a tous bouffé comme des\n"
    .string "malades!\p"
    .string "On a la super pêche!\p"
    .string "On va encore s'entraîner!$"

Route45_Text_CooltrainermRyanSeen:
    .string "Comment tu fais pour entraîner\n"
    .string "ton équipe?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "Respect. Bravo!$"

Route45_Text_CooltrainermRyanAfter:
    .string "Je vois que tu prends soin de\n"
    .string "ton équipe de Pokémon.\p"
    .string "Votre amitié vous sauvera.$"

Route45_Text_CooltrainerfKellySeen:
    .string "Quelle est ta stratégie?\p"
    .string "Utiliser des\n"
    .string "capacités puissantes\p"
    .string "au hasard ne\n"
    .string "sert à rien.$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "Bien. Perdu.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "Moi j'aime pas les attaques\n"
    .string "puissantes.\p"
    .string "Ca ne me fait pas plaisir de\n"
    .string "faire mal aux Pokémon.$"

Route45_Text_CamperQuentinSeen:
    .string "Trop de la balle!$"

Route45_Text_CamperQuentinBeaten:
    .string "J'étais fort au MONT DRESSEURS…$"

Route45_Text_CamperQuentinAfter:
    .string "Tu es allé au MONT DRESSEURS?\p"
    .string "Là-bas, je ne perds jamais,\n"
    .string "mais alors jamais…$"

Route45_Text_Sign:
    .string "ROUTE 45 CHEMIN de MONTAGNE Tout\n"
    .string "droit$"
