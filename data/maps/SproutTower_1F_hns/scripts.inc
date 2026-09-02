SproutTower_1F_hns_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW_HNS, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "Nous montons la garde dans cette\n"
	.string "tour.\p"
	.string "Nous y exprimons notre gratitude\n"
	.string "envers tous les Pokémon.$"

SproutTower_Text_SageChow_Beaten:
	.string "Mer... Merci!$"

SproutTower_Text_SageChow_AfterBattle:
	.string "Toute vie est basée sur\n"
	.string "l’entraide.\p"
	.string "Nous ne devons pas oublier ce\n"
	.string "que nous devons aux autres!$"

SproutTower_Text_1F_Sage1:
	.string "Celui ou celle arrivant au\n"
	.string "sommet recevra une CS.$"

SproutTower_Text_1F_Sage2:
	.string "La Tour CHETIFLOR\n"
	.string "a été construite\p"
	.string "il y a longtemps\n"
	.string "pour s’entraîner\p"
	.string "avec les Pokémon.$"

SproutTower_Text_1F_Granny:
	.string "Un CHETIFLOR haut de 30\n"
	.string "mètres...\p"
	.string "On raconte que c'est en fait le\n"
	.string "pilier central.$"

SproutTower_Text_1F_Teacher:
	.string "Vois-tu le pilier osciller? Les\n"
	.string "moines s’entraînent dur là-haut.$"

SproutTower_Text_1F_Statue:
	.string "C’est le Pokémon\n"
	.string "vénéré ici...\p"
	.string "Cette seule pensée\n"
	.string "impose le respect.$"
