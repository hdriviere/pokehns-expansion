SaffronCity_FightingDojoVIP_hns_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Nurse::
	lock
	faceplayer
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSAquaRooms_EventScript_Bed_PokecenterChallenge
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse1, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox SaffronCity_FightingDojoVIP_Text_Nurse2, MSGBOX_NPC
	waitmessage
	release
	end

SaffronCity_FightingDojoVIP_Text_Nurse1:
	.string "Bonjour! Bienvenue au DOJO\n"
	.string "D'ENTRAÎNEMENT!\p"
	.string "Je vais soigner vos Pokémon.$"

SaffronCity_FightingDojoVIP_Text_Nurse2:
	.string "Au plaisir de vous revoir!$"


SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_FALKNER_2_HNS, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BUGSY_2_HNS, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_WHITNEY_2_HNS, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MORTY_2_HNS, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CHUCK_2_HNS, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JASMINE_2_HNS, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_PRYCE_2_HNS, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CLAIR_2_HNS, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BROCK_HNS, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MISTY_HNS, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_LTSURGE_HNS, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_ERIKA_HNS, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JANINE_HNS, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLAINE_HNS, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLUE_HNS, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
	.string "CIZAYOX: Cizaaayox!$"

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
	.string "ÉCRÉMEUH: Meuuuh!$"

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
	.string "TÊTARTE: Têta-tarte!$"

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
	.string "LAMANTINE: Maaaantine!$"

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
	.string "STEELIX: GraaAAANk!$"

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
	.string "HYPOROI: Hyprooo...$"

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
	.string "ONIX: Oooonix!$"

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
	.string "STAROSS: Hyaaa!$"

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
	.string "EMPIFLOR: Empiii!$"

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
	.string "GROTADMORV: Grooo...$"

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
	.string "KADABRA: Kadabra!$"

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
	.string "MAGMAR: Magmaaaar!$"

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
	.string "RAICHU: Rai-CHU!$"

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Machamp:
	.string "MACKOGNEUR: Maa-kogneur!$"

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
	.string "Au secours!$"

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
	.string "SALON VIP DU DOJO DE COMBAT$"

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
	.string "Félicitations pour ta victoire\n"
	.string "sur le CONSEIL 4!\p"
	.string "J'ai entraîné plus durement mes\n"
	.string "Pokémon de type VOL.\p"
	.string "Peux-tu affronter à nouveau\n"
	.string "la puissance des cieux?$"

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
	.string "Waouh... Tu m'as encore battu.\p"
	.string "Je vais redoubler d'efforts pour\n"
	.string "devenir le meilleur Maître\l"
	.string "des Pokémon oiseaux!$"

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
	.string "Waouh, tu es devenu le MAÎTRE\n"
	.string "de JOHTO!\p"
	.string "Ton talent est impressionnant!\p"
	.string "J'ai beaucoup travaillé sur mes\n"
	.string "recherches.\p"
	.string "Je suis prêt à te montrer mes\n"
	.string "nouvelles découvertes.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
	.string "Waouh, tu dois être un Dresseur\n"
	.string "expert.\p"
	.string "Mes recherches sont sans doute\n"
	.string "incomplètes...$"

SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
	.string "Salut! C'est toi!\p"
	.string "Waouh, tu es MAÎTRE de JOHTO?\p"
	.string "Tu es vraiment incroyable!\p"
	.string "Je veux mesurer ta force.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
	.string "Waouaouah!\p"
	.string "Waaaaah!\p"
	.string "Sniff et re-sniff ...T'es pas\n"
	.string "cool!$"

SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
	.string "Ah, le MAÎTRE de JOHTO! Merci\n"
	.string "d'être venu.\p"
	.string "Tu as montré ta force et ton\n"
	.string "talent, mais as-tu progressé\l"
	.string "depuis notre dernier combat?\p"
	.string "Je me suis entraîné avec mes\n"
	.string "Pokémon de type SPECTRE.\p"
	.string "Voyons si tu peux de nouveau\n"
	.string "triompher des ombres.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
	.string "Je dois encore progresser...\p"
	.string "Tu as été témoin de bien plus de\n"
	.string "choses que moi.\p"
	.string "Je t'envie pour cela...$"

SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
	.string "WAHAHAH! MAÎTRE de JOHTO!\p"
	.string "Tu en redemandes!\p"
	.string "Je vois que tu as progressé!\p"
	.string "Prêt à découvrir le plus fort?$"

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
	.string "Quoi? Hein? J'ai encore perdu?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
	.string "...Félicitations, MAÎTRE\n"
	.string "de JOHTO.\p"
	.string "Tu es devenu si fort...\p"
	.string "Je me demande si j'ai progressé.\p"
	.string "Voudrais-tu le vérifier?\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
	.string "...Tu es meilleur Dresseur que\n"
	.string "moi, par ton talent comme par\l"
	.string "ta bonté.$"

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
	.string "Ah, MAÎTRE de JOHTO!\p"
	.string "Ton talent est remarquable.\p"
	.string "Je suis impressionné.\p"
	.string "Mais même maintenant, nous avons\n"
	.string "encore beaucoup à apprendre\l"
	.string "l'un de l'autre.\p"
	.string "Moi, FREDO, Dresseur hivernal,\n"
	.string "j'ai encore quelques atouts.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
	.string "Ah, ta prouesse m'impressionne\n"
	.string "une fois de plus.\p"
	.string "Avec ta volonté de fer, je sais\n"
	.string "que tu surmonteras tous les\l"
	.string "obstacles de la vie.$"

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
	.string "Tu as réussi, hein?\p"
	.string "Tu es le MAÎTRE de JOHTO.\p"
	.string "Tu as prouvé ta force.\n"
	.string "Mais peux-tu encore m'affronter?\p"
	.string "En tant que Maître des dragons,\n"
	.string "je ne me retiendrai pas.\p"
	.string "Pas cette fois.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
	.string "J'ai perdu?\p"
	.string "Encore?\p"
	.string "Je n'y crois pas. Il y a\n"
	.string "sûrement une erreur...$"

SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
	.string "PIERRE: Salut, {PLAYER}!\p"
	.string "J'ai entendu dire que tu es\n"
	.string "maintenant le MAÎTRE de KANTO.\p"
	.string "C'est incroyable!\p"
	.string "Tu dois être encore plus fort.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
	.string "PIERRE: Tes Pokémon ont encore\n"
	.string "surmonté ma défense de roc...$"

SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
	.string "ONDINE: Waouh, tu es maintenant\n"
	.string "MAÎTRE de KANTO!\p"
	.string "C'est incroyable! Tu as fait du\n"
	.string "chemin, {PLAYER}.\p"
	.string "Mais je ne reculerai pas.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
	.string "ONDINE: Tu es vraiment fort...$"

SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
	.string "BOB: Alors, tu es maintenant\n"
	.string "MAÎTRE de KANTO!\p"
	.string "Beau travail, petit! Mais je\n"
	.string "n'ai pas fini!\p"
	.string "Que dirais-tu d'une revanche?$"

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
	.string "BOB: Arrrgh! Tu es toujours\n"
	.string "aussi fort!$"

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
	.string "ERIKA: Oh, bonjour.\p"
	.string "Quelle surprise, MAÎTRE!\p"
	.string "Quel plaisir de te revoir.\p"
	.string "Ton voyage a dû être exaltant.\p"
	.string "Même un Maître aime les défis.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
	.string "Erika: C’est toujours un peu\n"
	.string "triste de perdre un combat...\p"
	.string "Mais c’est aussi stimulant de\n"
	.string "rencontrer un adversaire\p"
	.string "vraiment puissant.$"

SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
	.string "MORGANE: Ah, le MAÎTRE.\p"
	.string "J'ai senti ton retour.\p"
	.string "Ta puissance s'est accrue.\p"
	.string "Je sens encore ton aura.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
	.string "MORGANE: Ton amour pour tes\n"
	.string "Pokémon a encore submergé mes\l"
	.string "pouvoirs psychiques...$"

SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
	.string "Fufufufu...\p"
	.string "Waouh, tu as réussi!\p"
	.string "Tu es le MAÎTRE maintenant!\p"
	.string "Je suis si fière de toi! Mais ne\n"
	.string "crois pas que je serai tendre.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
	.string "JEANNINE: Tu es toujours aussi\n"
	.string "coriace!\p"
	.string "Tu as vraiment gagné...$"

SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
	.string "AUGUSTE: Waouh!\p"
	.string "Je vois que tu es devenu le\n"
	.string "MAÎTRE de KANTO!\p"
	.string "C'est incandescent!\p"
	.string "Ton talent est de premier ordre.\p"
	.string "Je suis toujours partant pour\n"
	.string "un combat.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
	.string "AUGUSTE: Ton talent est vraiment\n"
	.string "ardent!\p"
	.string "Tu as réduit mes défenses\n"
	.string "en cendres.$"

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
	.string "BLUE: Tiens, tiens. Le MAÎTRE!\p"
	.string "Tu sembles avoir fait du chemin.\p"
	.string "Moi aussi, j'ai porté ce titre,\n"
	.string "tu sais. Mais je ne te ménagerai\l"
	.string "pas.\p"
	.string "Voyons si tu tiens le rythme.\p"
	.string "Veux-tu me réaffronter?$"

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
	.string "BLUE: Quoi?\p"
	.string "Comment ai-je encore pu perdre?$"
