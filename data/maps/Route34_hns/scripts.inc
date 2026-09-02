Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end
	
Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
	.string "Hé! Je cherche des FEROSINGE!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Battu par toi???$"

Route34_Text_YoungsterSamuel_After:
	.string "Je vais encore m'entraîner.\p"
	.string "Je veux devenir CHAMPION, après\n"
	.string "tout.$"

Route34_Text_YoungsterIan_Seen:
	.string "Le meilleur de la classe en\n"
	.string "Pokémon, c’est moi!$"

Route34_Text_YoungsterIan_Beaten:
	.string "Il existe de meilleurs\n"
	.string "dresseurs...$"

Route34_Text_YoungsterIan_After:
	.string "Je fais de mon mieux pour être\n"
	.string "la star de ma classe.$"

Route34_Text_CamperTodd_Seen:
	.string "J’ai un vrai talent pour élever\n"
	.string "les Pokémon. Tu veux voir?$"

Route34_Text_CamperTodd_Beaten:
	.string "J'ai raté mon entraînement?$"

Route34_Text_CamperTodd_After:
	.string "Je devrais en mettre\n"
	.string "un en PENSION. Ou\p"
	.string "peutêtre utiliser\n"
	.string "des objets...$"

Route34_Text_ToddRegister:
	.string "Je devrais en mettre\n"
	.string "un en PENSION. Ou\p"
	.string "peutêtre utiliser\n"
	.string "des objets...$"

Route34_Text_ToddRematchIntro:
	.string "J’ai un vrai talent pour élever\n"
	.string "les Pokémon. Tu veux voir?$"

Route34_Text_ToddRematchDefeat:
	.string "J'ai raté mon entraînement?$"

Route34_Text_ToddPostRematch:
	.string "Je devrais en mettre\n"
	.string "un en PENSION. Ou\p"
	.string "peutêtre utiliser\n"
	.string "des objets...$"

Route34_Text_GinaRegister:
	.string "Ton niveau est\n"
	.string "trop élevé pour\p"
	.string "qu’on puisse\n"
	.string "s’entraîner ensemble.$"

Route34_Text_PicnickerGina_Seen:
	.string "T’es un Dresseur, non? On s’fait\n"
	.string "un duel d’entraînement?$"

Route34_Text_PicnickerGina_Beaten:
	.string "Ne gagnerai-je donc jamais?$"

Route34_Text_PicnickerGina_After:
	.string "Ton niveau est\n"
	.string "trop élevé pour\p"
	.string "qu’on puisse\n"
	.string "s’entraîner ensemble.$"

Route34_Text_OfficerKeith_Seen:
	.string "Qui va là? Pour quelle raison?$"

Route34_Text_OfficerKeith_Win:
	.string "T'es coriace toi!$"

Route34_Text_OfficerKeith_After:
	.string "Rien à signaler aujourd'hui.\p"
	.string "Sois sage et évite les ennuis.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Je fais la ronde pour vérifier\n"
	.string "que personne de louche ne rôde.$"

Route34_Text_PokefanBrandon_Seen:
	.string "Mon Pokémon vient de rentrer de\n"
	.string "la PENSION.\p"
	.string "Voyons s'il est plus fort!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "Pourquoi?$"

Route34_Text_PokefanBrandon_After:
	.string "Mon Pokémon est revenu avec de\n"
	.string "nouvelles capacités.\p"
	.string "Ça m'a complètement déconcerté!$"

Route34_Text_Sign_IlexForest:
	.string "BOIS AUX CHENES Après la porte$"

Route34_Text_Sign_Route34:
	.string "ROUTE 34\p"
	.string "DOUBLONVILLE ECORCIA\p"
	.string "BOIS AUX CHENES Sur la route$"

Route34_Text_TrainerTips:
	.string "ASTUCE DRESSEUR\p"
	.string "Les arbres à BAIES produisent\n"
	.string "plusieurs fois par jour.\p"
	.string "Note les BAIES de chaque arbre.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "Amy: Hé! Un instant! Qui es-tu,\n"
	.string "toi?$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "IRENE: Ohhh! Tu es trop fort!$"

Route34_Text_CooltrainerIrene_After1:
	.string "Amy: Ma sœur Irène te fera payer\n"
	.string "ça!$"

Route34_Text_CooltrainerIrene_After2:
	.string "AMY: Elle est pas excellente\n"
	.string "cette plage?\p"
	.string "C'est notre cachette secrète!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "Maria: Hé! Un instant! Qu’est-ce\n"
	.string "que tu fais ici?$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "JENN: Désolée, IRENE! Ma sœur!$"

Route34_Text_CooltrainerJenn_After1:
	.string "Maria: Ne crâne pas trop! Ma\n"
	.string "sœur Irène est très forte!$"

Route34_Text_CooltrainerJenn_After2:
	.string "MARIA: Le soleil rend le corps\n"
	.string "plus fort.$"

Route34_Text_CooltrainerKate_Seen:
	.string "Irène: Tu as su\n"
	.string "comment te charger\p"
	.string "de mes petites\n"
	.string "sœurs, j’ai vu!$"

Route34_Text_CooltrainerKate_Beaten:
	.string "Irène: Non! J’ai perdu!\n"
	.string "Incroyable!$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "Irène: Quelle force! Je n’avais\n"
	.string "aucune chance.\p"
	.string "Tiens, tu mérites bien ceci.$"

Route34_Text_CooltrainerKate_After:
	.string "Irène: Désolée de\n"
	.string "t’avoir sauté dessus.\p"
	.string "On ne pensait pas\n"
	.string "que quelqu’un nous\p"
	.string "trouverait ici.\p"
	.string "On a été un peu surprises, c’est\n"
	.string "tout!$"


Route34_Text_Sign_DayCare:
	.string "PENSION\p"
	.string "On élève votre Pokémon pour\n"
	.string "vous!$"
