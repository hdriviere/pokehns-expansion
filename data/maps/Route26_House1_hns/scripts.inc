Route26_House1_hns_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end


Route26_Text_HealHouseRest:
    .string "Tes Pokémon ont l'air fatigué.\p"
    .string "Tu devrais les soigner.$"

Route26_Text_HealHouseKeepAtIt:
    .string "Voilà! Ton équipe est en pleine\n"
    .string "forme!\p"
    .string "Allez, bonne chance!$"
