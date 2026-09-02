CeladonCity_GameCorner_hns_MapScripts::
	.byte 0

CeladonGameCorner_EventScript_PokefanM::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanM, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Teacher::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Teacher, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_FishingGuru::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_FishingGuru, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_Fisher1::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher1, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Fisher2::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Fisher2, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_GymGuide::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_GymGuide, MSGBOX_NPC
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Gramps::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Gramps, MSGBOX_NPC
	closemessage
	release
	end

CeladonGameCorner_EventScript_PokefanF::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
	waitmovement 0
	release
	end

CeladonGameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox CeladonGameCorner_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonGameCorner_Text_PokefanM:
	.string "Les machines à sous, c'est trop\n"
	.string "fort.$"

CeladonGameCorner_Text_Teacher:
	.string "C'est cette machine que je veux.\p"
	.string "Elle m'a plumé hier, alors elle\n"
	.string "devrait payer aujourd'hui.$"

CeladonGameCorner_Text_FishingGuru:
	.string "Je pense que cette machine\n"
	.string "à sous\l"
	.string "va payer…\p"
	.string "Les chances varient selon les\n"
	.string "machines.$"

CeladonGameCorner_Text_Fisher1:
	.string "Gahahaha!\p"
	.string "Les jetons tombent sans arrêt!\p"
	.string "Hmm? Quoi, gamin? Tu veux jouer?\p"
	.string "Je vais partager ma chance!$"

CeladonGameCorner_Text_Fisher2:
	.string "Gahahaha!\p"
	.string "Aider son prochain c'est trop\n"
	.string "cool!$"

CeladonGameCorner_Text_GymGuide:
	.string "Hé! Graine de star!\p"
	.string "Tu joues aux machines à sous?\p"
	.string "Je veux des jetons pour\n"
	.string "m'acheter un Pokémon.\p"
	.string "Mais c'est pas facile...$"

CeladonGameCorner_Text_PokefanF:
	.string "Roulette…\p"
	.string "Je préfère ça aux machines à\n"
	.string "sous, car les chances sont plus\l"
	.string "faciles à calculer.\p"
	.string "Mais les gains sont moindres.$"

CeladonGameCorner_Text_Gramps:
	.string "Hmm… Les chances sont sûrement\n"
	.string "meilleures en misant tout sur le\l"
	.string "bleu, mais… que faire?$"

CeladonGameCorner_Text_Woman:
	.string "Je n'arrête pas de gagner!$"
