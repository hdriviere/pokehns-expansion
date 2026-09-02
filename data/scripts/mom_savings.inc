EventScript_MomGiftCall_Item::
	lockall
	pokenavcall Mom_Text_GiftCall_Item
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Berry::
	lockall
	pokenavcall Mom_Text_GiftCall_Berry
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

EventScript_MomGiftCall_Decoration::
	lockall
	pokenavcall Mom_Text_GiftCall_Decoration
	waitmessage
	delay 30
	clearflag FLAG_MOM_HAS_GIFT
	releaseall
	end

Mom_Text_GiftCall_Item:
	.string "MAMAN: Bonjour, mon chéri!\p"
	.string "Je t'ai acheté quelque chose de\n"
	.string "bien avec tes économies!\p"
	.string "Je l'ai envoyé sur ton PC.\n"
	.string "Prends soin de toi!$"

Mom_Text_GiftCall_Berry:
	.string "MAMAN: Bonjour, mon chéri!\p"
	.string "J'ai trouvé de belles BAIES\n"
	.string "à la boutique pour toi!\p"
	.string "Je les ai envoyées sur ton PC.\n"
	.string "Prends soin de toi!$"

Mom_Text_GiftCall_Decoration:
	.string "MAMAN: Bonjour, mon chéri!\p"
	.string "J'ai acheté une adorable POUPEE\n"
	.string "POKéMON pour ta chambre!\p"
	.string "Regarde tes DECORATIONS quand tu\n"
	.string "rentreras. Prends soin de toi!$"
