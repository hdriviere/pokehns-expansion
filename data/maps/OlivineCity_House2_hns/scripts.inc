OlivineCity_House2_hns_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "Il y a 4 îles désertes en allant\n"
	.string "vers Irisia.\p"
	.string "On y abandonne les enfants qui\n"
	.string "n’ont pas été sages!$"

OlivineCity_Text_PunishmentBoy:
	.string "Chaque fois que je fais\n"
	.string "une bêtise,\l"
	.string "mon grand frère me fait peur.$"
