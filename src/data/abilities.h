const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("Pas de capacité spéciale."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("PUANTEUR"),
        .description = COMPOUND_STRING(
            "Repousse POKéMON sauvage."
        ),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("CRACHIN"),
        .description = COMPOUND_STRING(
            "Le Pokémon invoque la pluie\n"
            "quand il entre au combat."
        ),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("TURBO"),
        .description = COMPOUND_STRING(
            "Améliore la VITESSE."
        ),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("ARMURBASTON"),
        .description = COMPOUND_STRING(
            "Bloque les coups critiques."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("FERMETÉ"),
        .description = COMPOUND_STRING(
            "Protège des capacités\n"
            "mettant K.O. en un coup."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("MOITEUR"),
        .description = COMPOUND_STRING(
            "Empêche auto-destruction."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("ÉCHAUFFEMENT"),
        .description = COMPOUND_STRING(
            "Empêche la paralysie."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("VOILE SABLE"),
        .description = COMPOUND_STRING(
            "Evasion si tempête sable."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("STATIK"),
        .description = COMPOUND_STRING(
            "Paralyse au toucher."
        ),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("ABSORBE-VOLT"),
        .description = COMPOUND_STRING(
            "Change l'électricité en PV."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("ABSORBE-EAU"),
        .description = COMPOUND_STRING(
            "Change l'eau en PV."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("BENÊT"),
        .description = COMPOUND_STRING(
            "Empêche l'attirance."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("CIEL GRIS"),
        .description = COMPOUND_STRING(
            "Ignore les effets du climat."
        ),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("ŒIL COMPOSÉ"),
        .description = COMPOUND_STRING(
            "Augmente la précision."
        ),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("INSOMNIA"),
        .description = COMPOUND_STRING(
            "Empêche de s'endormir."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("HOMOCHROMIE"),
        .description = COMPOUND_STRING(
            "Le Pokémon adopte le type\n"
            "de la capacité ennemie."
        ),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("VACCIN"),
        .description = COMPOUND_STRING(
            "Empêche l'empoisonnement."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("TORCHE"),
        .description = COMPOUND_STRING(
            "Puissance monte si brûlé."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("ÉCRAN POUDRE"),
        .description = COMPOUND_STRING(
            "Empêche le cumul d'effets."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("TEMPO PERSO"),
        .description = COMPOUND_STRING(
            "Empêche la confusion."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("VENTOUSE"),
        .description = COMPOUND_STRING(
            "Fixe solidement le corps."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("INTIMIDATION"),
        .description = COMPOUND_STRING(
            "Baisse l'ATTAQUE ennemie."
        ),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("MARQUE OMBRE"),
        .description = COMPOUND_STRING(
            "Empêche la fuite ennemie."
        ),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("PEAU DURE"),
        .description = COMPOUND_STRING(
            "Blesse quand touché."
        ),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("GARDE MYSTIK"),
        .description = COMPOUND_STRING(
            "Reçoit seul. “sup. eff.”."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("LÉVITATION"),
        .description = COMPOUND_STRING(
            "Ignore les attaques SOL."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("POSE SPORE"),
        .description = COMPOUND_STRING(
            "Laisse spores si touché."
        ),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("SYNCHRO"),
        .description = COMPOUND_STRING(
            "Transfère statuts."
        ),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("CORPS SAIN"),
        .description = COMPOUND_STRING(
            "Empêche réduction de cap."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("MÉDIC NATURE"),
        .description = COMPOUND_STRING(
            "Soigne POKéMON changeant."
        ),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("PARATONNERRE"),
        .description = COMPOUND_STRING(
            "Attire l'électricité et\n"
            "augmente l'Atq. Spé."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("SÉRÉNITÉ"),
        .description = COMPOUND_STRING(
            "Favorise le cumul d'effet."
        ),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("GLISSADE"),
        .description = COMPOUND_STRING(
            "Monte VITESSE s'il pleut."
        ),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("CHLOROPHYLLE"),
        .description = COMPOUND_STRING(
            "Augmente vitesse au soleil."
        ),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("LUMIATTIRANCE"),
        .description = COMPOUND_STRING(
            "Augmente les rencontres."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("CALQUE"),
        .description = COMPOUND_STRING(
            "Imite la capacité spéciale."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("COLOFORCE"),
        .description = COMPOUND_STRING(
            "Augmente ATTAQUE."
        ),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("POINT POISON"),
        .description = COMPOUND_STRING(
            "Empoisonne quand touché."
        ),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("ATTENTION"),
        .description = COMPOUND_STRING(
            "Empêche la peur."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("ARMUMAGMA"),
        .description = COMPOUND_STRING(
            "Empêche le gel."
        ),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("IGNIFU-VOILE"),
        .description = COMPOUND_STRING(
            "Empêche les brûlures."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("MAGNÉPIÈGE"),
        .description = COMPOUND_STRING(
            "Piège les POKéMON ACIER."
        ),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("ANTI-BRUIT"),
        .description = COMPOUND_STRING(
            "Évite les attaques sonores."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("CUVETTE"),
        .description = COMPOUND_STRING(
            "Gagne quelques PV si pluie."
        ),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("SABLE VOLANT"),
        .description = COMPOUND_STRING(
            "Lance une tempête de sable."
        ),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("PRESSION"),
        .description = COMPOUND_STRING(
            "Force l'ennemi à dépenser\n"
            "plus de PP."
        ),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("ISOGRAISSE"),
        .description = COMPOUND_STRING(
            "Contre chaleur et froid."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("MATINAL"),
        .description = COMPOUND_STRING(
            "Se réveille rapidement."
        ),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("CORPS ARDENT"),
        .description = COMPOUND_STRING(
            "Brûle l'ennemi quand touché."
        ),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("FUITE"),
        .description = COMPOUND_STRING(
            "Améliore chances de fuite."
        ),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("REGARD VIF"),
        .description = COMPOUND_STRING(
            "Empêche perte de précision."
        ),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("HYPER CUTTER"),
        .description = COMPOUND_STRING(
            "Empêche réduction ATTAQUE."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("RAMASSAGE"),
        .description = COMPOUND_STRING(
            "Permet parfois au Pokémon\n"
            "de ramasser des objets."
        ),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("ABSENTÉISME"),
        .description = COMPOUND_STRING(
            "Frappe tous les 2 tours."
        ),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("AGITATION"),
        .description = COMPOUND_STRING(
            "Substitue préc. par puiss."
        ),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("JOLI SOURIRE"),
        .description = COMPOUND_STRING(
            "Séduit quand touché."
        ),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("PLUS"),
        .description = COMPOUND_STRING(
            "Puissance + avec MINUS."
        ),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("MOINS"),
        .description = COMPOUND_STRING(
            "Puissance + avec PLUS."
        ),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("MÉTÉO"),
        .description = COMPOUND_STRING(
            "Change selon le climat."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("GLU"),
        .description = COMPOUND_STRING(
            "Empêche le vol d'objets."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("MUE"),
        .description = COMPOUND_STRING(
            "Mue pour se soigner."
        ),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("CRAN"),
        .description = COMPOUND_STRING(
            "Augmente ATT. quand blessé."
        ),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("ÉCAILLE SPÉCIALE"),
        .description = COMPOUND_STRING(
            "Augmente DEF. quand blessé."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("SUINTEMENT"),
        .description = COMPOUND_STRING(
            "Blesse quand drainé."
        ),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("ENGRAIS"),
        .description = COMPOUND_STRING(
            "Augmente attaques PLANTE."
        ),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("BRASIER"),
        .description = COMPOUND_STRING(
            "Augmente attaques feu."
        ),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("TORRENT"),
        .description = COMPOUND_STRING(
            "Augmente attaques EAU."
        ),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("ESSAIM"),
        .description = COMPOUND_STRING(
            "Augmente attaques INSECT."
        ),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("TÊTE DE ROC"),
        .description = COMPOUND_STRING(
            "Empêche dégâts du recul."
        ),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("SÉCHERESSE"),
        .description = COMPOUND_STRING(
            "Invoque le soleil."
        ),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("PIÈGE SABLE"),
        .description = COMPOUND_STRING(
            "Empêche la fuite."
        ),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("ESPRIT VITAL"),
        .description = COMPOUND_STRING(
            "Empêche le sommeil."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("ÉCRAN FUMÉE"),
        .description = COMPOUND_STRING(
            "Empêche réduction des cap."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("FORCE PURE"),
        .description = COMPOUND_STRING(
            "Augmente l'ATTAQUE."
        ),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("COQUE ARMURE"),
        .description = COMPOUND_STRING(
            "Bloque les coups critiques."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("AIR LOCK"),
        .description = COMPOUND_STRING(
            "Ignore les effets du climat."
        ),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("PIEDS CONFUS"),
        .description = COMPOUND_STRING(
            "Augmente l'esquive si le\n"
            "Pokémon est confus."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("MOTORISÉ"),
        .description = COMPOUND_STRING(
            "Augmente la Vit. si touché\n"
            "par une cap. Électrik."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("RIVALITÉ"),
        .description = COMPOUND_STRING(
            "Devient plus fort si\n"
            "l'ennemi est du même sexe."
        ),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("IMPASSIBLE"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse quand\n"
            "le Pokémon a peur."
        ),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("RIDEAU NEIGE"),
        .description = COMPOUND_STRING(
            "Augmente l'Esquive du\n"
            "Pokémon quand il neige."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("GLOUTONNERIE"),
        .description = COMPOUND_STRING(
            "Encourage l'utilisation\n"
            "d'une Baie tenue."
        ),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("COLÉRIQUE"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque au max\n"
            "après un coup critique."
        ),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("DÉLESTAGE"),
        .description = COMPOUND_STRING(
            "Augmente la Vit. si l'objet\n"
            "tenu est utilisé ou perdu."
        ),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("IGNIFUGÉ"),
        .description = COMPOUND_STRING(
            "Réduit la puissance des\n"
            "capacités de type Feu."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("SIMPLE"),
        .description = COMPOUND_STRING(
            "Le Pokémon est sujet à des\n"
            "variations de stats."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("PEAU SÈCHE"),
        .description = COMPOUND_STRING(
            "Perd des PV à la chaleur.\n"
            "L'eau les restaure."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("TÉLÉCHARGE"),
        .description = COMPOUND_STRING(
            "Ajuste la puissance selon\n"
            "l'ennemi."
        ),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("POING DE FER"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "capacités coups de poing."
        ),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("SOIN POISON"),
        .description = COMPOUND_STRING(
            "Restaure des PV si le\n"
            "Pokémon est empoisonné."
        ),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("ADAPTABILITÉ"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "capacités de même type."
        ),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("MULTI-COUPS"),
        .description = COMPOUND_STRING(
            "Augmente la fréquence des\n"
            "attaques multiples."
        ),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("HYDRATATION"),
        .description = COMPOUND_STRING(
            "Soigne les problèmes de\n"
            "statut s'il pleut."
        ),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("FORCE SOLEIL"),
        .description = COMPOUND_STRING(
            "Augmente l'Atq. Spé. mais\n"
            "baisse les PV au soleil."
        ),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("PIED VÉLOCE"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse en cas\n"
            "de problème de statut."
        ),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("NORMALISE"),
        .description = COMPOUND_STRING(
            "Toutes les capacités sont\n"
            "de type Normal."
        ),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("SNIPER"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "coups critiques."
        ),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("GARDE MAGIK"),
        .description = COMPOUND_STRING(
            "Seules les attaques\n"
            "peuvent blesser le Pokémon."
        ),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("ANNULE GARDE"),
        .description = COMPOUND_STRING(
            "Attaques du Pokémon et de\n"
            "l'ennemi réussissent."
        ),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("FREIN"),
        .description = COMPOUND_STRING(
            "Attaque toujours après\n"
            "l'ennemi, même plus lent."
        ),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("TECHNICIEN"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "capacités les plus faibles."
        ),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("FEUILLE GARDE"),
        .description = COMPOUND_STRING(
            "Empêche les problèmes de\n"
            "statut au soleil."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("MALADRESSE"),
        .description = COMPOUND_STRING(
            "Le Pokémon ne peut utiliser\n"
            "aucun objet tenu."
        ),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("BRISE MOULE"),
        .description = COMPOUND_STRING(
            "Cap. utilisables quelles que\n"
            "soient les cap. spé."
        ),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("CHANCEUX"),
        .description = COMPOUND_STRING(
            "Augmente la fréquence des\n"
            "coups critiques."
        ),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("BOOM FINAL"),
        .description = COMPOUND_STRING(
            "Blesse l'ennemi qui porte le\n"
            "coup de grâce."
        ),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("ANTICIPATION"),
        .description = COMPOUND_STRING(
            "Prévoit les capacités\n"
            "ennemies dangereuses."
        ),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("PRÉDICTION"),
        .description = COMPOUND_STRING(
            "Découvre la capacité\n"
            "ennemie la plus puissante."
        ),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("INCONSCIENT"),
        .description = COMPOUND_STRING(
            "Ignore les changements de\n"
            "stats de l'ennemi."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("LENTITEINTÉE"),
        .description = COMPOUND_STRING(
            "Améliore les capacités “pas\n"
            "très efficaces”."
        ),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("FILTRE"),
        .description = COMPOUND_STRING(
            "Affaiblit les capacités\n"
            "“super efficaces”."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("DÉBUT CALME"),
        .description = COMPOUND_STRING(
            "Divise temporairement\n"
            "Vitesse et Attaque par 2."
        ),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("QUERELLEUR"),
        .description = COMPOUND_STRING(
            "Les capacités touchent les\n"
            "Pokémon Spectre."
        ),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("LAVABO"),
        .description = COMPOUND_STRING(
            "Attire l'eau et augmente\n"
            "l'Atq. Spé."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("CORPS GEL"),
        .description = COMPOUND_STRING(
            "Récupère des PV lors des\n"
            "tempêtes de grêle."
        ),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("SOLIDE ROC"),
        .description = COMPOUND_STRING(
            "Affaiblit les capacités\n"
            "“super efficaces”."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("ALERTE NEIGE"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Invoque la neige en combat."),
    #else
        .description = COMPOUND_STRING("Invoque la grêle en combat."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("CHERCHE MIEL"),
        .description = COMPOUND_STRING(
            "Le Pokémon peut parfois\n"
            "trouver du Miel."
        ),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("FOUILLE"),
        .description = COMPOUND_STRING(
            "Permet de connaître l'objet\n"
            "tenu par l'ennemi."
        ),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("TÉMÉRAIRE"),
        .description = COMPOUND_STRING(
            "Booste les cap. ayant des\n"
            "dégâts de contrecoups."
        ),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("MULTI-TYPE"),
        .description = COMPOUND_STRING(
            "Modifie le type en fonction\n"
            "de la Plaque tenue."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("DON FLORAL"),
        .description = COMPOUND_STRING(
            "Pokémon de l'équipe plus\n"
            "puissants au soleil."
        ),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("MAUVAIS RÊVE"),
        .description = COMPOUND_STRING(
            "Réduit les PV d'un ennemi\n"
            "endormi."
        ),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("PICKPOCKET"),
        .description = COMPOUND_STRING(
            "Vole l'objet de l'ennemi si\n"
            "son attaque touche."
        ),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("SANS LIMITE"),
        .description = COMPOUND_STRING(
            "Frappe plus fort mais\n"
            "annule les effets cumulés."
        ),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("CONTESTATION"),
        .description = COMPOUND_STRING(
            "Inverse les variations de\n"
            "stats."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("TENSION"),
        .description = COMPOUND_STRING(
            "L'ennemi stresse et ne peut\n"
            "plus manger de Baies."
        ),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("ACHARNÉ"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque quand les\n"
            "stats baissent."
        ),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("DÉFAITISTE"),
        .description = COMPOUND_STRING(
            "Baisse les stats quand les\n"
            "PV tombent à la moitié."
        ),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("CORPS MAUDIT"),
        .description = COMPOUND_STRING(
            "Peut empêcher l'ennemi de\n"
            "réutiliser une attaque."
        ),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("CŒUR SOIN"),
        .description = COMPOUND_STRING(
            "Guérit parfois le statut\n"
            "des alliés alentour."
        ),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("GARDE-AMI"),
        .description = COMPOUND_STRING(
            "Diminue les dégâts subis\n"
            "par les alliés."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("ARMUROUILLÉE"),
        .description = COMPOUND_STRING(
            "Un coup physique baisse la\n"
            "Défense, monte la Vitesse."
        ),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("HEAVY METAL"),
        .description = COMPOUND_STRING(
            "Double le poids du Pokémon."
        ),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("LIGHT METAL"),
        .description = COMPOUND_STRING(
            "Divise par 2 le poids du\n"
            "Pokémon."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("MULTIÉCAILLE"),
        .description = COMPOUND_STRING(
            "Reçoit moins de dégâts si\n"
            "les PV sont au maximum."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("RAGE POISON"),
        .description = COMPOUND_STRING(
            "Booste les att. physiques\n"
            "si le statut est poison."
        ),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("RAGE BRÛLURE"),
        .description = COMPOUND_STRING(
            "Booste les att. spéciales si\n"
            "le statut est brûlure."
        ),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("RÉCOLTE"),
        .description = COMPOUND_STRING(
            "Les Baies utilisées peuvent\n"
            "repousser."
        ),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("TÉLÉPATHE"),
        .description = COMPOUND_STRING(
            "Anticipe et évite les\n"
            "attaques de ses alliés."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("LUNATIQUE"),
        .description = COMPOUND_STRING(
            "Monte une stat tout en en\n"
            "baissant une autre."
        ),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("ENVELOCAPE"),
        .description = COMPOUND_STRING(
            "Neutralise les dégâts dus à\n"
            "la météo."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("TOXITOUCHE"),
        .description = COMPOUND_STRING(
            "Peut empoisonner l'ennemi\n"
            "par simple contact."
        ),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("RÉGÉ-FORCE"),
        .description = COMPOUND_STRING(
            "Restaure un peu de PV si le\n"
            "Pokémon est retiré."
        ),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("CŒUR DE COQ"),
        .description = COMPOUND_STRING(
            "Protège des effets qui\n"
            "baissent la Défense."
        ),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("BAIGNE SABLE"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse lors\n"
            "des tempêtes de sable."
        ),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("PEAU MIRACLE"),
        .description = COMPOUND_STRING(
            "Résiste mieux aux attaques\n"
            "de statut."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("ANALYSTE"),
        .description = COMPOUND_STRING(
            "Booste les capacités s'il\n"
            "attaque en dernier."
        ),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("ILLUSION"),
        .description = COMPOUND_STRING(
            "Prend l'apparence du\n"
            "dernier Pokémon de l'équipe."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("IMPOSTEUR"),
        .description = COMPOUND_STRING(
            "Donne l'apparence du\n"
            "Pokémon adverse."
        ),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("INFILTRATION"),
        .description = COMPOUND_STRING(
            "Traverse les barrières de\n"
            "l'ennemi pour attaquer."
        ),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("MOMIE"),
        .description = COMPOUND_STRING(
            "Momifie le talent de\n"
            "l'ennemi qui le touche."
        ),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("IMPUDENCE"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque quand il\n"
            "met un ennemi K.O."
        ),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("CŒUR NOBLE"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque si une att.\n"
            "Ténèbres le touche."
        ),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("PHOBIQUE"),
        .description = COMPOUND_STRING(
            "Sa peur de certains types\n"
            "augmente sa Vitesse."
        ),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("MIROIR MAGIK"),
        .description = COMPOUND_STRING(
            "Renvoie les attaques de\n"
            "statut."
        ),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("HERBIVORE"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque après\n"
            "une attaque Plante."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("FARCEUR"),
        .description = COMPOUND_STRING(
            "Utilise les attaques de\n"
            "statut en premier."
        ),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("FORCE SABLE"),
        .description = COMPOUND_STRING(
            "Renforce des capacités en\n"
            "cas de tempête de sable."
        ),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("ÉPINE DE FER"),
        .description = COMPOUND_STRING(
            "Blesse l'ennemi au moindre\n"
            "contact."
        ),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("MODE TRANSE"),
        .description = COMPOUND_STRING(
            "Transforme le Pokémon dans\n"
            "les moments délicats."
        ),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("VICTORIEUX"),
        .description = COMPOUND_STRING(
            "Monte la Précision des\n"
            "Pokémon de l'équipe."
        ),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("TURBO BRASIER"),
        .description = COMPOUND_STRING(
            "Les cap. spé. adverses ne\n"
            "bloquent pas ses cap."
        ),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("TÉRA-VOLTAGE"),
        .description = COMPOUND_STRING(
            "Les cap. spé. adverses ne\n"
            "bloquent pas ses cap."
        ),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("AROMA-VOILE"),
        .description = COMPOUND_STRING(
            "Protège l'équipe des effets\n"
            "limitant le libre arbitre."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("FLORA-VOILE"),
        .description = COMPOUND_STRING(
            "Empêche les alliés de type Plante de\n"
            "subir des diminutions de stats."
        ),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("BAJOUES"),
        .description = COMPOUND_STRING(
            "Rend des PV lorsque le\n"
            "Pokémon consomme une Baie."
        ),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("PROTÉEN"),
        .description = COMPOUND_STRING(
            "Le Pokémon prend le type de\n"
            "la capacité qu'il utilise."
        ),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("TOISON ÉPAISSE"),
        .description = COMPOUND_STRING(
            "Divise les dégâts des attaques\n"
            "physiques par deux."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("MAGICIEN"),
        .description = COMPOUND_STRING(
            "Les capacités volent aussi\n"
            "l'objet tenu par la cible."
        ),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("PARE-BALLES"),
        .description = COMPOUND_STRING(
            "Protège de certaines capacités\n"
            "projetant des bombes, balles…"
        ),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("BATTANT"),
        .description = COMPOUND_STRING(
            "Monte l'Attaque quand les\n"
            "stats baissent."
        ),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("PROGNATHE"),
        .description = COMPOUND_STRING(
            "Grâce à une puissante mâchoire, les\n"
            "morsures sont plus fortes."
        ),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("PEAU GELÉE"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Glace."
        ),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("GLUCO-VOILE"),
        .description = COMPOUND_STRING(
            "Les Pokémon de l'équipe ne\n"
            "peuvent pas s'endormir."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("DÉCLIC TACTIQUE"),
        .description = COMPOUND_STRING(
            "Change de forme selon la façon dont le\n"
            "Pokémon se bat."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("AILES BOURRASQUE"),
        .description = COMPOUND_STRING(
            "Les attaques de type Vol\n"
            "sont prioritaires."
        ),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("MÉGA BLASTER"),
        .description = COMPOUND_STRING(
            "Augmente la puissance de certaines\n"
            "capacités de type aura."
        ),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("TOISON HERBUE"),
        .description = COMPOUND_STRING(
            "Augmente la Défense si\n"
            "Champ Herbu est actif."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("SYMBIOSE"),
        .description = COMPOUND_STRING(
            "Permet aux alliés d'utiliser l'objet porté\n"
            "par ce Pokémon."
        ),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("GRIFFE DURE"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "attaques directes."
        ),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("PEAU FÉÉRIQUE"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Fée."
        ),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("POISSEUX"),
        .description = COMPOUND_STRING(
            "Diminue la Vitesse de\n"
            "l'attaquant qui le touche."
        ),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("PEAU CÉLESTE"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Vol."
        ),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("AMOUR FILIAL"),
        .description = COMPOUND_STRING(
            "Attaque en famille."
        ),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("AURA TÉNÉBREUSE"),
        .description = COMPOUND_STRING(
            "Renforce les attaques de type Ténèbres\n"
            "de tous les Pokémon."
        ),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("AURA FÉÉRIQUE"),
        .description = COMPOUND_STRING(
            "Renforce les attaques de type Fée de\n"
            "tous les Pokémon."
        ),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("AURA INVERSÉE"),
        .description = COMPOUND_STRING(
            "L'effet des auras est\n"
            "inversé."
        ),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("MER PRIMAIRE"),
        .description = COMPOUND_STRING(
            "Altère les conditions météo et rend\n"
            "inefficaces les attaques Feu."
        ),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("TERRE FINALE"),
        .description = COMPOUND_STRING(
            "Altère les conditions météo et rend\n"
            "inefficaces les attaques Eau."
        ),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("SOUFFLE DELTA"),
        .description = COMPOUND_STRING(
            "Altère les conditions météo et annule les\n"
            "faiblesses du type Vol."
        ),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("ENDURANCE"),
        .description = COMPOUND_STRING(
            "Augmente la Défense du Pokémon lorsqu'il\n"
            "subit une attaque."
        ),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("ESCAMPETTE"),
        .description = COMPOUND_STRING(
            "Le Pokémon perd confiance quand ses PV\n"
            "tombent à la moitié et s'enfuit dans sa\n"
            "Poké Ball."
        ),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("REPLI TACTIQUE"),
        .description = COMPOUND_STRING(
            "Le Pokémon évite les situations\n"
            "inutilement dangereuses. Quand ses PV\n"
            "tombent à la moitié, il se réfugie dans sa\n"
            "Poké Ball."
        ),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("SABLE HUMIDE"),
        .description = COMPOUND_STRING(
            "Augmente beaucoup la Défense du\n"
            "Pokémon quand il subit une capacité de\n"
            "type Eau."
        ),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("CRUAUTÉ"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon attaque un\n"
            "adversaire empoisonné, le coup est\n"
            "forcément critique."
        ),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("BOUCLIER-CARCAN"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon perd la moitié de ses\n"
            "PV, son enveloppe se brise et il adopte\n"
            "une posture offensive."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("FILATURE"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon attaque une cible qui\n"
            "vient d'entrer sur le terrain en\n"
            "remplacement d'un autre Pokémon, les\n"
            "dégâts infligés sont doublés."
        ),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("AQUABULLE"),
        .description = COMPOUND_STRING(
            "Réduit les dégâts des capacités de type\n"
            "Feu subies par le Pokémon. Il est\n"
            "également immunisé contre les brûlures."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("EXPERT ACIER"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "attaques de type Acier."
        ),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("FOLLE FURIE"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque Spéciale du Pokémon\n"
            "lorsqu'il tombe à la moitié de ses PV à\n"
            "cause d'une attaque."
        ),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("CHASSE-NEIGE"),
        .description = COMPOUND_STRING(
            "Augmente la Vitesse du\n"
            "Pokémon quand il grêle."
        ),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("LONGUE PORTÉE"),
        .description = COMPOUND_STRING(
            "Le Pokémon est capable d'utiliser toutes\n"
            "ses capacités sans entrer en contact\n"
            "direct avec sa cible."
        ),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("HYDRATA-SON"),
        .description = COMPOUND_STRING(
            "Toutes les attaques sonores du Pokémon\n"
            "prennent le type Eau."
        ),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("PRIOGUÉRISON"),
        .description = COMPOUND_STRING(
            "Rend les capacités de soin\n"
            "prioritaires."
        ),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("PEAU ÉLECTRIQUE"),
        .description = COMPOUND_STRING(
            "Les capacités de type Normal deviennent\n"
            "de type Électrik. Leur puissance\n"
            "augmente légèrement."
        ),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("SURF CAUDAL"),
        .description = COMPOUND_STRING(
            "La Vitesse du Pokémon est doublée sur\n"
            "un Champ Électrifié."
        ),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("BANC"),
        .description = COMPOUND_STRING(
            "Le Pokémon se rassemble avec ses\n"
            "congénères quand ses PV sont élevés.\n"
            "Plus ses PV baissent, plus le banc\n"
            "s'amenuise."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("FANTÔMASQUE"),
        .description = COMPOUND_STRING(
            "Le déguisement qui recouvre le corps du\n"
            "Pokémon est capable de le protéger\n"
            "d'une attaque."
        ),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("SYNERGIE"),
        .description = COMPOUND_STRING(
            "En battant un ennemi, ce Pokémon\n"
            "renforce ses liens avec son Dresseur,\n"
            "ce qui augmente son Attaque, son\n"
            "Attaque Spéciale et sa Vitesse."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("RASSEMBLEMENT"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon perd la moitié de ses\n"
            "PV, ses Cellules se rassemblent pour\n"
            "l'encourager, ce qui lui permet de\n"
            "prendre sa Forme Parfaite."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("CORROSION"),
        .description = COMPOUND_STRING(
            "Permet d'empoisonner les Pokémon de\n"
            "type Acier ou Poison."
        ),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("HYPERSOMMEIL"),
        .description = COMPOUND_STRING(
            "Le Pokémon rêve en permanence et ne se\n"
            "réveille jamais. Il est capable d'attaquer\n"
            "normalement tout en dormant."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("PRESTANCE ROYALE"),
        .description = COMPOUND_STRING(
            "L'adversaire est impressionné par la\n"
            "majesté du Pokémon et ne peut pas le\n"
            "viser avec une attaque prioritaire."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("EXPULS’ORGANES"),
        .description = COMPOUND_STRING(
            "Le Pokémon inflige à l'adversaire l'ayant\n"
            "mis K.O. des dégâts égaux au nombre de\n"
            "PV qu'il lui restait avant le coup de\n"
            "grâce."
        ),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("DANSEUSE"),
        .description = COMPOUND_STRING(
            "Si n'importe quel Pokémon utilise une\n"
            "capacité dansante, ce Pokémon peut se\n"
            "mettre aussi à danser."
        ),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("BATTERIE"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités\n"
            "spéciales des alliés."
        ),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("BOULE DE POILS"),
        .description = COMPOUND_STRING(
            "Divise par deux les dégâts des attaques\n"
            "directes subies par le Pokémon, mais\n"
            "double les dégâts des capacités de type\n"
            "Feu."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("CORPS COLORÉ"),
        .description = COMPOUND_STRING(
            "L'adversaire est abasourdi par le\n"
            "Pokémon et ne peut pas le viser avec\n"
            "une capacité prioritaire."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("ANIMACŒUR"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque Spéciale du Pokémon\n"
            "lorsqu'un autre Pokémon est mis K.O."
        ),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("MÈCHE REBELLE"),
        .description = COMPOUND_STRING(
            "Baisse la Vitesse de l'attaquant lorsque\n"
            "le Pokémon subit une attaque directe."
        ),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("RECEVEUR"),
        .description = COMPOUND_STRING(
            "Le Pokémon reçoit le talent\n"
            "d'un allié mis K.O."
        ),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("OSMOSE"),
        .description = COMPOUND_STRING(
            "Le Pokémon acquiert le\n"
            "talent d'un allié mis K.O."
        ),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("BOOST CHIMÈRE"),
        .description = COMPOUND_STRING(
            "Augmente la stat la plus élevée du\n"
            "Pokémon quand il met K.O. un autre\n"
            "Pokémon."
        ),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("SYSTÈME ALPHA"),
        .description = COMPOUND_STRING(
            "Change le type du Pokémon en fonction\n"
            "de la ROM équipée."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("CRÉA-ÉLEC"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Électrifié au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("CRÉA-PSY"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Psychique au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("CRÉA-BRUME"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Brumeux au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("CRÉA-HERBE"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un Champ Herbu au\n"
            "moment où il entre au combat."
        ),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("MÉTALLO-GARDE"),
        .description = COMPOUND_STRING(
            "Empêche les stats du Pokémon de baisser\n"
            "à cause d'une capacité ou d'un talent."
        ),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("SPECTRO-BOUCLIER"),
        .description = COMPOUND_STRING(
            "Le Pokémon subit moins de dégâts quand\n"
            "ses PV sont au maximum."
        ),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("PRISME-ARMURE"),
        .description = COMPOUND_STRING(
            "Diminue la puissance des attaques super\n"
            "efficaces subies."
        ),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("CÉRÉBRO-FORCE"),
        .description = COMPOUND_STRING(
            "Augmente encore plus la puissance des\n"
            "attaques super efficaces."
        ),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("LAME INDOMPTABLE"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque du Pokémon quand il\n"
            "entre au combat."
        ),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("ÉGIDE INFLEXIBLE"),
        .description = COMPOUND_STRING(
            "Augmente la Défense du Pokémon quand il\n"
            "entre au combat."
        ),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("LIBÉRO"),
        .description = COMPOUND_STRING("Prend le type de la capacité."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("RAMASSE BALL"),
        .description = COMPOUND_STRING(
            "Si le Pokémon ne tient aucun objet, il\n"
            "ramassera la Poké Ball lors du premier\n"
            "lancer raté du combat."
        ),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("EFFILOCHAGE"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon est touché par une\n"
            "attaque, il dissémine des aigrettes qui\n"
            "diminuent la Vitesse de tout le monde,\n"
            "sauf la sienne."
        ),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("PROPULSEUR"),
        .description = COMPOUND_STRING(
            "Permet d'ignorer l'effet des capacités\n"
            "ou des talents qui attirent les\n"
            "capacités."
        ),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("ARMURE MIROIR"),
        .description = COMPOUND_STRING(
            "Le Pokémon renvoie les effets\n"
            "réducteurs de stats qu'il reçoit."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("DÉGOBAGE"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon utilise Surf ou Plongée,\n"
            "il revient avec une proie. Lorsqu'il subit\n"
            "des dégâts par la suite, il attaque en\n"
            "recrachant sa proie."
        ),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("NERFS D’ACIER"),
        .description = COMPOUND_STRING(
            "Permet d'ignorer l'effet des capacités\n"
            "ou des talents qui attirent les\n"
            "capacités."
        ),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("TURBINE"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est touché par des\n"
            "capacités de type Eau ou Feu, sa\n"
            "Vitesse augmente énormément."
        ),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("PUNK ROCK"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités\n"
            "basées sur le son. Le Pokémon ne subit\n"
            "que la moitié des dégâts quand il est\n"
            "touché par ce genre de capacités."
        ),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("EXPUL’SABLE"),
        .description = COMPOUND_STRING(
            "Le Pokémon déclenche une tempête de\n"
            "sable quand il subit une attaque."
        ),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("ÉCAILLES GLACÉES"),
        .description = COMPOUND_STRING(
            "Le Pokémon est protégé par des écailles\n"
            "de glace. Les dégâts qu'il subit par des\n"
            "capacités spéciales sont divisés par\n"
            "deux."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("MÛRISSEMENT"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait mûrir la Baie qu'il tient\n"
            "et double ainsi son effet."
        ),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("TÊTE DE GEL"),
        .description = COMPOUND_STRING(
            "Le glaçon sur sa tête encaisse les\n"
            "attaques physiques à la place du\n"
            "Pokémon. Le glaçon se reforme quand il\n"
            "grêle."
        ),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("CERCLE D’ÉNERGIE"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des capacités des\n"
            "Pokémon qui se trouvent à proximité."
        ),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("MIMÉTISME"),
        .description = COMPOUND_STRING(
            "Le Pokémon adopte le même type que le\n"
            "terrain lorsqu'un champ est actif."
        ),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("BRISE-BARRIÈRE"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon entre au combat, les\n"
            "effets de Mur Lumière, Protection et\n"
            "Voile Aurore disparaissent pour les\n"
            "alliés comme pour les ennemis."
        ),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("BOOST ACIER"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des attaques de\n"
            "type Acier du Pokémon et de ses alliés."
        ),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("CORPS CONDAMNÉ"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est directement\n"
            "touché par une attaque, l'assaillant et\n"
            "lui tomberont K.O. dans trois tours."
        ),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("ÂME VAGABONDE"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est directement\n"
            "touché par une attaque, il échange son\n"
            "talent avec celui de l'assaillant."
        ),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("ENTÊTEMENT"),
        .description = COMPOUND_STRING(
            "Augmente l'Attaque, mais empêche\n"
            "d'utiliser toute autre capacité que celle\n"
            "utilisée en premier par le Pokémon."
        ),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("GAZ INHIBITEUR"),
        .description = COMPOUND_STRING(
            "Si un Pokémon avec Gaz Inhibiteur est\n"
            "sur le terrain, les effets des talents\n"
            "de tous les autres Pokémon sont\n"
            "annulés."
        ),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("VOILE PASTEL"),
        .description = COMPOUND_STRING(
            "Protège le Pokémon et ses alliés contre\n"
            "toutes les altérations de statut liées à\n"
            "l'empoisonnement."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("DÉCLIC FRINGALE"),
        .description = COMPOUND_STRING(
            "À la fin de chaque tour, le Pokémon\n"
            "alterne entre ses formes Mode Rassasié\n"
            "et Mode Affamé."
        ),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("TIR VIF"),
        .description = COMPOUND_STRING(
            "Permet parfois au Pokémon\n"
            "d'agir en premier."
        ),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("POING INVISIBLE"),
        .description = COMPOUND_STRING(
            "Si le Pokémon utilise une attaque\n"
            "directe, celle-ci pourra passer outre\n"
            "les protections de la cible."
        ),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("BREUVAGE SUSPECT"),
        .description = COMPOUND_STRING(
            "Quand il entre au combat, le Pokémon\n"
            "répand une substance qui annule les\n"
            "changements de stats de ses alliés."
        ),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("TRANSISTOR"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "attaques de type Électrik."
        ),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("DENT DE DRAGON"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "attaques de type Dragon."
        ),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("BLANCHE RUADE"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon met un ennemi K.O., il\n"
            "émet un hennissement glaçant, ce qui\n"
            "augmente son Attaque."
        ),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("SOMBRE RUADE"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon met un ennemi K.O., il\n"
            "émet un hennissement terrifiant qui\n"
            "augmente son Attaque Spéciale."
        ),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("OSMOSE ÉQUINE"),
        .description = COMPOUND_STRING(
            "Le talent Tension de\n"
            "Sylveroy est cumulé."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("OSMOSE ÉQUINE"),
        .description = COMPOUND_STRING(
            "Le talent Sombre Ruade de\n"
            "Spectreval est cumulé."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("ODEUR TENACE"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon subit une attaque\n"
            "directe, le talent de l'attaquant est\n"
            "remplacé par Odeur Tenace."
        ),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("SEMENCIER"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un champ herbu quand il\n"
            "subit une attaque."
        ),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("THERMODYNAMIQUE"),
        .description = COMPOUND_STRING(
            "Lorsque le Pokémon est touché par une\n"
            "capacité de type Feu, son Attaque\n"
            "augmente. Il ne peut pas être brûlé."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("COURROUPACE"),
        .description = COMPOUND_STRING(
            "Le Pokémon enrage s'il a moins de la\n"
            "moitié de ses PV après avoir subi une\n"
            "attaque. Sa Déf., Déf. Spé. baissent, et\n"
            "son Atq., Atq. Spé., Vit. augmentent."
        ),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("SEL PURIFICATEUR"),
        .description = COMPOUND_STRING(
            "Le sel pur immunise le Pokémon contre\n"
            "les altérations de statut, et diminue de\n"
            "moitié les dégâts des capacités de type\n"
            "Spectre."
        ),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("BIEN CUIT"),
        .description = COMPOUND_STRING(
            "Si le Pokémon est touché par une\n"
            "capacité de type Feu, il ne subit aucun\n"
            "dégât et sa Défense augmente beaucoup."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("AÉROPORTÉ"),
        .description = COMPOUND_STRING(
            "L'Attaque du Pokémon augmente si un\n"
            "vent arrière souffle ou s'il est touché\n"
            "par une capacité faisant appel au vent."
        ),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("CHIEN DE GARDE"),
        .description = COMPOUND_STRING(
            "L'Attaque du Pokémon augmente s'il subit\n"
            "l'effet du talent Intimidation. Les\n"
            "capacités ou objets qui font changer de\n"
            "Pokémon n'ont aucun effet sur lui."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("PORTE-ROCHE"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "capacités de type Roche."
        ),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("TURBINE ÉOLIENNE"),
        .description = COMPOUND_STRING(
            "Si le Pokémon est touché par une\n"
            "capacité faisant appel au vent, il se\n"
            "charge en électricité."
        ),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("SUPERMUTATION"),
        .description = COMPOUND_STRING(
            "Le Pokémon prend sa Forme Super en\n"
            "quittant le combat."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("COMMANDANT"),
        .description = COMPOUND_STRING(
            "Si un Oyacata allié est sur le terrain\n"
            "quand ce Pokémon rejoint le combat, ce\n"
            "dernier entre dans sa bouche et devient\n"
            "son commandant."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("GRECHARGE"),
        .description = COMPOUND_STRING(
            "Si le Pokémon subit des dégâts, il se\n"
            "charge en électricité."
        ),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("PALÉOSYNTHÈSE"),
        .description = COMPOUND_STRING(
            "Quand le soleil brille ou que le Pokémon\n"
            "tient une capsule d'Énergie Booster, sa\n"
            "stat la plus élevée augmente."
        ),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("CHARGE QUANTIQUE"),
        .description = COMPOUND_STRING(
            "Quand un champ électrifié est actif ou\n"
            "que le Pokémon tient une capsule\n"
            "d'Énergie Booster, sa stat la plus élevée\n"
            "augmente."
        ),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("CORPS EN OR"),
        .description = COMPOUND_STRING(
            "Le corps en or pur et robuste du\n"
            "Pokémon l'immunise contre les capacités\n"
            "de statut des autres Pokémon."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("URNE DU FLÉAU"),
        .description = COMPOUND_STRING(
            "Le pouvoir de l'urne qui appelle le fléau\n"
            "affaiblit l'Attaque Spéciale de tous les\n"
            "autres Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("ÉPÉE DU FLÉAU"),
        .description = COMPOUND_STRING(
            "Le pouvoir de l'épée qui appelle le fléau\n"
            "affaiblit la Défense de tous les autres\n"
            "Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("BOIS DU FLÉAU"),
        .description = COMPOUND_STRING(
            "Le pouvoir du bois qui appelle le fléau\n"
            "affaiblit l'Attaque de tous les autres\n"
            "Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("PERLES DU FLÉAU"),
        .description = COMPOUND_STRING(
            "Le pouvoir des perles qui appellent le\n"
            "fléau affaiblit la Défense Spéciale de\n"
            "tous les autres Pokémon."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("POULS ORICHALQUE"),
        .description = COMPOUND_STRING(
            "Le Pokémon invoque le soleil quand il\n"
            "rejoint le combat. Quand le soleil brille,\n"
            "une pulsation primitive augmente son\n"
            "Attaque."
        ),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("MOTEUR À HADRONS"),
        .description = COMPOUND_STRING(
            "Le Pokémon crée un champ électrifié\n"
            "quand il rejoint le combat. Une machine\n"
            "du futur fait monter son Attaque\n"
            "Spéciale si un champ électrifié est actif."
        ),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("OPPORTUNISTE"),
        .description = COMPOUND_STRING(
            "Quand les stats de l'ennemi augmentent,\n"
            "le Pokémon en profite pour augmenter\n"
            "ses stats de la même manière."
        ),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("RUMINANT"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon mange une Baie, il la\n"
            "régurgite à la fin du tour suivant et la\n"
            "mange une nouvelle fois."
        ),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("INCISIF"),
        .description = COMPOUND_STRING(
            "Augmente la puissance des\n"
            "capacités tranchantes."
        ),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("GÉNÉRAL SUPRÊME"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon entre sur le terrain,\n"
            "son Attaque et son Attaque Spéciale\n"
            "augmentent légèrement pour chaque allié\n"
            "mis K.O. auparavant."
        ),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("COLLAB"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon entre sur le terrain, il\n"
            "copie les changements de stats de son\n"
            "allié."
        ),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("DÉPÔT TOXIQUE"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon est touché par une\n"
            "capacité physique, il répand des pics\n"
            "toxiques dans le camp adverse."
        ),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("ARMURE CAUDALE"),
        .description = COMPOUND_STRING(
            "Une étrange queue recouvre la tête du\n"
            "Pokémon, ce qui empêche ce dernier et\n"
            "ses alliés d'être visés par une capacité\n"
            "prioritaire."
        ),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("ABSORBE-TERRE"),
        .description = COMPOUND_STRING(
            "Si le Pokémon est touché par une\n"
            "capacité de type Sol, il regagne des PV\n"
            "au lieu de subir des dégâts."
        ),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("FORCE FONGIQUE"),
        .description = COMPOUND_STRING(
            "Le Pokémon agit toujours plus lentement\n"
            "quand il utilise une capacité de statut,\n"
            "mais il ignore les talents adverses."
        ),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("AUX PETITS SOINS"),
        .description = COMPOUND_STRING(
            "Quand il rejoint le combat, ce Pokémon\n"
            "est aux petits soins avec son allié et\n"
            "restaure quelques PV."
        ),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("ŒIL RÉVÉLATEUR"),
        .description = COMPOUND_STRING(
            "Le Pokémon ignore les changements\n"
            "d'Esquive des cibles et peut toucher les\n"
            "Pokémon Spectre avec des capacités\n"
            "Normal ou Combat."
        ),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("FORCE MÉMORIELLE"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("FORCE MÉMORIELLE"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("FORCE MÉMORIELLE"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("FORCE MÉMORIELLE"),
        .description = COMPOUND_STRING(
            "Le Pokémon fait briller le Masque en\n"
            "puisant dans ses souvenirs, ce qui\n"
            "augmente ses stats."
        ),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("CHAÎNE TOXIQUE"),
        .description = COMPOUND_STRING(
            "Grâce aux pouvoirs de sa chaîne\n"
            "imprégnée de toxines, le Pokémon peut\n"
            "empoisonner gravement sa cible en la\n"
            "touchant avec une capacité."
        ),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("NECTAR MIELLEUX"),
        .description = COMPOUND_STRING(
            "La première fois que le Pokémon entre\n"
            "au combat, une odeur de nectar sucré\n"
            "se répand sur le terrain, ce qui baisse\n"
            "l'Esquive de l'adversaire."
        ),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("TÉRAMORPHOSE"),
        .description = COMPOUND_STRING(
            "Quand le Pokémon rejoint le combat, il\n"
            "absorbe l'énergie alentour et prend sa\n"
            "Forme Téracristal."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("TÉRA-CARAPACE"),
        .description = COMPOUND_STRING(
            "Grâce à sa carapace, les capacités\n"
            "subies par ce Pokémon quand ses PV\n"
            "sont au maximum ne sont pas très\n"
            "efficaces."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("TÉRAFORMATION 0"),
        .description = COMPOUND_STRING(
            "Lorsque Terapagos prend sa Forme\n"
            "Stellaire, il utilise son pouvoir enfoui\n"
            "pour annuler les effets de la météo et\n"
            "des champs actifs."
        ),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("EMPRISE TOXIQUE"),
        .description = COMPOUND_STRING(
            "Lorsque Pêchaminus empoisonne un\n"
            "Pokémon grâce à l'une de ses capacités,\n"
            "ce dernier devient également confus."
        ),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
