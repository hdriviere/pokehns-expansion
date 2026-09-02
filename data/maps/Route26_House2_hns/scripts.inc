Route26_House2_hns_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "Il y a quelque chose d'écrit.\p"
    .string "Lire?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "A mes frères et soeurs:\p"
    .string "Nous devons aider les dresseurs\n"
    .string "de Pokémon.\p"
    .string "Quand un dresseur vient vous\n"
    .string "parler, donnez-lui un objet.\p"
    .string "Bisous, LUCIE\p"
    .string "Continuer à lire?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "Lundi, LUCIE ROUTE 40\p"
    .string "Mardi, MARIE ROUTE 29\p"
    .string "Mercredi, HOMER LAC COLERE\p"
    .string "Jeudi, JEROME ROUTE 36\p"
    .string "Vendredi, VANESSA ROUTE 32\p"
    .string "Samedi, SAMUEL EBENELLE\p"
    .string "Dimanche, DIMITRI ROUTE 37$"
