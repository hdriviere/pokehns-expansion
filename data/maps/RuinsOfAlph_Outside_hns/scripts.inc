RuinsOfAlph_Outside_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "MARAISTE: Mara Mara$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN_HNS, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN_HNS, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "Hm? C’est un Pokédex, n’est-ce\n"
	.string "pas? Puis-je le voir?\p"
	.string "Eh bien... Il y a tant de\n"
	.string "Pokémon...\p"
	.string "Quoi?!\p"
	.string "Mais quel est donc ce Pokémon?\p"
	.string "Il ressemble\n"
	.string "aux inscriptions\p"
	.string "étranges sur les\n"
	.string "murs des ruines...\p"
	.string "Si ces dessins sont\n"
	.string "des Pokémon, alors\p"
	.string "il doit y en avoir\n"
	.string "beaucoup d’autres...\p"
	.string "Je sais! Je vais améliorer ton\n"
	.string "Pokédex! Suis-moi!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "Que veux-tu? J'étudie, là... Me\n"
	.string "cherche pas!$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Pardon... Le manque de\p"
	.string "communication est un tort...$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "Les RUINES sont vieilles\n"
	.string "d'environ 1500 ans.\p"
	.string "Personne ne sait qui a pu les\n"
	.string "construire.\p"
	.string "On ne sait pas non plus si les\n"
	.string "statues de Pokémon ont un sens.\p"
	.string "Alors ça... C'est du mystère!$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "Hmmm... C'est bizarre ici.$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "...$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "J'aime réfléchir ici.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "PIERRE MYSTERE CHAMBRE du\n"
	.string "PANNEAU$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINES D'ALPHA Bienvenue$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "RUINES D'ALPHA CENTRE de\n"
	.string "RECHERCHE\p"
	.string "La référence des RUINES D'ALPHA$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "En explorant les RUINES, nous\n"
	.string "avons\p"
	.string "senti une drôle de présence.\p"
	.string "On a eu peur et on a filé.\p"
	.string "Fais gaffe. C'est un conseil.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "Il y a un secret dans les\n"
	.string "RUINES!\p"
	.string "Enfin je crois...$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "Il existe des ZARBI différents.\p"
	.string "Nous les utilisons pour nos\n"
	.string "codes secrets.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "D… R… O… I… T… Hmmm…\p"
	.string "Quoi?\p"
	.string "Je décode le message!$"
