Route27_House_hns_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "Où tu vas toi avec tes Pokémon?\p"
    .string "La LIGUE Pokémon?\p"
    .string "Tes Pokémon sont assez confiants\n"
    .string "pour y aller?\p"
    .string "On va voir...$"

SandstormHouse_Text_LoyalMon:
    .string "Oh! Ton Pokémon te fait vraiment\n"
    .string "confiance!\p"
    .string "C’est agréable\n"
    .string "de voir un bon\p"
    .string "Dresseur. Tiens!\n"
    .string "Un cadeau pour toi!$"

SandstormHouse_Text_TM37Description:
    .string "CT37 apprend TEMPETESABLE.\p"
    .string "Elle inflige des dégâts aux deux\n"
    .string "combattants.\p"
    .string "Seuls les experts savent bien\n"
    .string "s'en servir.\p"
    .string "A toi de peaufiner une\n"
    .string "technique!$"

SandstormHouse_Text_DisloyalMon:
    .string "Ton Pokémon doit\n"
    .string "avoir davantage\p"
    .string "confiance en toi,\n"
    .string "ou tu auras du mal\p"
    .string "à remporter la victoire.\p"
    .string "C’est la confiance qui unit\n"
    .string "Dresseurs et Pokémon.$"


