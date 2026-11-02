UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "Tu vas à Ecorcia,\n"
	.string "n’est-ce pas?\p"
	.string "Voyons si tu peux\n"
	.string "te sortir de là...$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "Oh, oh, oh!$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "C’est décidé...\p"
	.string "Je ne partirai\n"
	.string "pas avant que mes\p"
	.string "Pokémon ne soient\n"
	.string "devenus très forts!$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "Je parcours la terre à la\n"
	.string "recherche de Pokémon.\p"
	.string "Quoi? Toi aussi tu les\n"
	.string "collectionnes?\p"
	.string "Bah alors... COMBAT!$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "Non!!! Mon pauvre Pokémon...$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "Parfois, on entend des cris\n"
	.string "de POKéMON venant du fond\l"
	.string "de la grotte.$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "Eh bien! Quelle\n"
	.string "surprise! Je ne\p"
	.string "pensais pas rencontrer\n"
	.string "quelqu’un ici!$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "Eh bien! Quelle\n"
	.string "surprise! Je ne\p"
	.string "pensais pas rencontrer\n"
	.string "quelqu’un de si fort!$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "On m'a persuadé d'acheter une\n"
	.string "QUEUE de RAMOLOSS.\p"
	.string "Mais j'ai des remords... Pauvre\n"
	.string "Pokémon.$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "L’ultrason de\n"
	.string "NOSFERAPTI n’arrête\p"
	.string "pas de rendre mes\n"
	.string "Pokémon confus.\p"
	.string "Et ça commence VRAIMENT à me\n"
	.string "gonfler.$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "Perdu, en lettres de feu!$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "Le week-end on peut entendre des\p"
	.string "cris de Pokémon venant de\n"
	.string "l'antre.$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "Une caverne éclairée, ça fait\n"
	.string "pas peur.\p"
	.string "Avec du courage, les méchants,\n"
	.string "ça fait pas peur.$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "FLASH!$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "Les flammes de mon Pokémon\n"
	.string "illuminent cette caverne!$"
