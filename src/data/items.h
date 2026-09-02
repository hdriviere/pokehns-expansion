#if I_USE_EVO_HELD_ITEMS_FROM_BAG == TRUE
    #define EVO_HELD_ITEM_TYPE ITEM_USE_PARTY_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_EvolutionStone
#else
    #define EVO_HELD_ITEM_TYPE ITEM_USE_BAG_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_CannotUse
#endif

#define GEM_BOOST_PARAM ((I_GEM_BOOST_POWER >= GEN_6) ? 30 : 50)
#define TYPE_BOOST_PARAM ((I_TYPE_BOOST_POWER >= GEN_4) ? 20 : 10) // For non Pokémon-specific type-boosting held items.
#define POWER_ITEM_BOOST ((I_POWER_ITEM_BOOST >= GEN_7) ? 8 : 4)

#define X_ITEM_STAGES ((B_X_ITEMS_BUFF >= GEN_7) ? 2 : 1)

#define TREASURE_FACTOR ((I_SELL_VALUE_FRACTION >= GEN_9) ? 2 : 1)

#define ITEM_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_LENGTH)
#define ITEM_PLURAL_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_PLURAL_LENGTH)

// Shared Item Description entries

static const u8 sFullHealDesc[]       = _("Soigne tous les\n"
                                          "problèmes de statut\n"
                                          "d'un POKéMON.");

static const u8 sPokeDollDesc[]       = _("Permet de fuir tout\n"
                                          "combat contre un\n"
                                          "POKéMON sauvage.");

static const u8 sMaxReviveDesc[]      = _("Réanime un POKéMON\n"
                                          "K.O. et restaure\n"
                                          "tous ses PV.");

static const u8 sHealthFeatherDesc[]  = _("Augmente les PV\n"
                                          "de base d'un\n"
                                          "POKéMON.");

static const u8 sMuscleFeatherDesc[]  = _("Augmente l'Attaque\n"
                                          "de base d'un\n"
                                          "POKéMON.");

static const u8 sResistFeatherDesc[]  = _("Augmente la Défense\n"
                                          "de base d'un\n"
                                          "POKéMON.");

static const u8 sGeniusFeatherDesc[]  = _("Augmente l'Atq. Spé.\n"
                                          "de base d'un\n"
                                          "POKéMON.");

static const u8 sCleverFeatherDesc[]  = _("Augmente la Déf. Spé.\n"
                                          "de base d'un\n"
                                          "POKéMON.");

static const u8 sSwiftFeatherDesc[]   = _("Augmente la Vitesse\n"
                                          "de base d'un\n"
                                          "POKéMON.");

static const u8 sBigMushroomDesc[]    = _(
    "Un champignon rare.\n"
    "Peut être vendu\n"
    "à bon prix.");

static const u8 sShardsDesc[]         = _(
    "Fragment d’objet\n"
    "antique. Peut être\n"
    "vendu à bas prix.");

static const u8 sRootFossilDesc[]     = _("Le fossile d'un\n"
                                          "ancien POKéMON des\n"
                                          "fonds marins.");

static const u8 sFossilizedFishDesc[] = _("Le fossile d'un\n"
                                          "ancien POKéMON\n"
                                          "marin.");

static const u8 sBeadMailDesc[]       = _("Une LETTRE ornée\n"
                                          "d'un dessin du\n"
                                          "POKéMON porteur.");

static const u8 sEvolutionStoneDesc[] = _("Fait évoluer certaines\n"
                                          "espèces de\n"
                                          "POKéMON.");

static const u8 sNectarDesc[]         = _("Un nectar floral qui\n"
                                          "change la forme de\n"
                                          "certains POKéMON.");

static const u8 sCharizarditeDesc[]   = _("Permet à Dracaufeu\n"
                                          "de méga-évoluer\n"
                                          "en combat.");

static const u8 sMewtwoniteDesc[]     = _("Permet à Mewtwo\n"
                                          "de méga-évoluer\n"
                                          "en combat.");

static const u8 sRaichuniteDesc[]     = _("Permet à Raichu\n"
                                          "de méga-évoluer\n"
                                          "en combat.");

static const u8 sAbsoliteDesc[]       = _("Permet à Absol\n"
                                          "de méga-évoluer\n"
                                          "en combat.");

static const u8 sGarchompiteDesc[]    = _("Permet à Carchacrok\n"
                                          "de méga-évoluer\n"
                                          "en combat.");

static const u8 sLucarioniteDesc[]    = _("Permet à Lucario\n"
                                          "de méga-évoluer\n"
                                          "en combat.");

static const u8 sSeaIncenseDesc[]     = _("Objet à tenir qui\n"
                                          "renforce un peu les\n"
                                          "capacités EAU.");

static const u8 sOddIncenseDesc[]     = _("Objet à tenir qui\n"
                                          "renforce les\n"
                                          "capacités PSY.");

static const u8 sRockIncenseDesc[]    = _("Objet à tenir qui\n"
                                          "renforce les\n"
                                          "capacités ROCHE.");

static const u8 sFullIncenseDesc[]    = _("Objet à tenir qui\n"
                                          "ralentit son\n"
                                          "porteur.");

static const u8 sRoseIncenseDesc[]    = _("Objet à tenir qui\n"
                                          "renforce les\n"
                                          "capacités PLANTE.");

static const u8 sLuckIncenseDesc[]    = _(
    "Double l’argent ga-\n"
    "gné si le porteur\n"
    "se bat aussi.");

static const u8 sPureIncenseDesc[]    = _("Objet à tenir qui\n"
                                          "repousse les POKéMON\n"
                                          "sauvages.");

static const u8 sKingsRockDesc[]      = _(
    "Objet tenu pouvant\n"
    "apeurer l’ennemi\n"
    "s’il est touché.");

static const u8 sFigyBerryDesc[]      = _(
    "Objet tenu qui res-\n"
    "taure les PV. Peut\n"
    "rendre confus.");

const u8 gQuestionMarksItemName[] = _("????????");

static const u8 sQuestionMarksDesc[]  = _("?????");

static const u8 sKeyToRoomDesc[]      = _("Une clé ouvrant une\n"
                                          "porte de l'ÉPAVE.");

static const u8 sTeraShardDesc[]      = _("Ces éclats apparaissent\n"
                                          "parfois lorsqu'un POKéMON\n"
                                          "téracristallisé tombe K.O.");

static const u8 sGenericMulchDesc[]   = _("Un engrais inadapté\n"
                                          "au sol local.");

const struct ItemInfo gItemsInfo[] =
{
    [ITEM_NONE] =
    {
        .name = gQuestionMarksItemName,
        .price = 0,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_UNCATEGORIZED,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

// Poké Balls

    [ITEM_STRANGE_BALL] =
    {
        .name = ITEM_NAME("ÉTRANGE BALL"),
        .price = 0,
        .description = COMPOUND_STRING("Une Ball inhabituelle\nayant traversé\nl'espace et le temps."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_STRANGE,
        .iconPic = gItemIcon_StrangeBall,
        .iconPalette = gItemIconPalette_StrangeBall,
    },

    [ITEM_POKE_BALL] =
    {
        .name = ITEM_NAME("POKÉ BALL"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Cette capsule\n"
            "capture les\n"
            "Pokémon sauvages\n"
            "quand on la lance\n"
            "comme une balle."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_POKE,
        .iconPic = gItemIcon_PokeBall,
        .iconPalette = gItemIconPalette_PokeBall,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = ITEM_NAME("SUPER BALL"),
        .price = 400,
        .description = COMPOUND_STRING(
            "Une Ball très performante\n"
            "dont le taux de réussite\n"
            "est supérieur à celui de la\n"
            "Poké Ball."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_GREAT,
        .iconPic = gItemIcon_GreatBall,
        .iconPalette = gItemIconPalette_GreatBall,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = ITEM_NAME("HYPER BALL"),
        //.price = (I_PRICE >= GEN_7) ? 800 : 1200,
        .price = 800,
        .description = COMPOUND_STRING(
            "Une Ball ultraperformante\n"
            "dont le taux de réussite\n"
            "est supérieur à celui de la\n"
            "Super Ball."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_ULTRA,
        .iconPic = gItemIcon_UltraBall,
        .iconPalette = gItemIconPalette_UltraBall,
    },

    [ITEM_MASTER_BALL] =
    {
        .name = ITEM_NAME("MASTER BALL"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Assurément la Ball la plus\n"
            "performante. Elle permet de\n"
            "capturer à coup sûr un\n"
            "Pokémon sauvage."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MASTER,
        .iconPic = gItemIcon_MasterBall,
        .iconPalette = gItemIconPalette_MasterBall,
    },

    [ITEM_PREMIER_BALL] =
    {
        .name = ITEM_NAME("HONOR BALL"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "Une Poké Ball assez\n"
            "rare qui fut créée\n"
            "pour un événement\n"
            "particulier."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PREMIER,
        .iconPic = gItemIcon_PremierBall,
        .iconPalette = gItemIconPalette_PremierBall,
    },

    [ITEM_HEAL_BALL] =
    {
        .name = ITEM_NAME("SOIN BALL"),
        .price = 300,
        .description = COMPOUND_STRING(
            "Une Poké Ball de soin qui\n"
            "rend tous les PV du Pokémon\n"
            "attrapé et qui soigne tous\n"
            "les changements de statut."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAL,
        .iconPic = gItemIcon_HealBall,
        .iconPalette = gItemIconPalette_HealBall,
    },

    [ITEM_NET_BALL] =
    {
        .name = ITEM_NAME("FILET BALL"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball un peu\n"
            "spéciale qui fonctionne\n"
            "particulièrement bien sur\n"
            "les Pokémon Eau ou Insecte."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NET,
        .iconPic = gItemIcon_NetBall,
        .iconPalette = gItemIconPalette_NetBall,
    },

    [ITEM_NEST_BALL] =
    {
        .name = ITEM_NAME("FAIBLO BALL"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball un peu\n"
            "spéciale qui fonctionne\n"
            "particulièrement bien sur\n"
            "les Pokémon les plus faibles."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NEST,
        .iconPic = gItemIcon_NestBall,
        .iconPalette = gItemIconPalette_NestBall,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = ITEM_NAME("SCUBA BALL"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball un peu\n"
            "spéciale qui fonctionne\n"
            "particulièrement bien sur\n"
            "les Pokémon sous-marins."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DIVE,
        .iconPic = gItemIcon_DiveBall,
        .iconPalette = gItemIconPalette_DiveBall,
    },

    [ITEM_DUSK_BALL] =
    {
        .name = ITEM_NAME("SOMBRE BALL"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball\n"
            "efficace de nuit ou\n"
            "dans les endroits\n"
            "sombres, tels que\n"
            "les grottes."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DUSK,
        .iconPic = gItemIcon_DuskBall,
        .iconPalette = gItemIconPalette_DuskBall,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = ITEM_NAME("CHRONO BALL"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball un peu\n"
            "spéciale qui fonctionne de\n"
            "mieux en mieux à mesure que\n"
            "le combat s'éternise."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_TIMER,
        .iconPic = gItemIcon_TimerBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_QUICK_BALL] =
    {
        .name = ITEM_NAME("RAPIDE BALL"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball qui permet\n"
            "d'attraper un Pokémon\n"
            "sauvage plus facilement si\n"
            "on l'utilise au début du\n"
            "combat."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_QUICK,
        .iconPic = gItemIcon_QuickBall,
        .iconPalette = gItemIconPalette_QuickBall,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = ITEM_NAME("BIS BALL"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball un peu\n"
            "spéciale qui fonctionne\n"
            "particulièrement bien sur\n"
            "les espèces de Pokémon déjà\n"
            "capturées."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_REPEAT,
        .iconPic = gItemIcon_RepeatBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = ITEM_NAME("LUXE BALL"),
        .price = (I_PRICE >= GEN_8) ? 3000 : 1000,
        .description = COMPOUND_STRING(
            "Une Poké Ball pratique qui\n"
            "permet de gagner\n"
            "rapidement l'amitié d'un\n"
            "Pokémon sauvage attrapé."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LUXURY,
        .iconPic = gItemIcon_LuxuryBall,
        .iconPalette = gItemIconPalette_LuxuryBall,
    },

    [ITEM_LEVEL_BALL] =
    {
        .name = ITEM_NAME("NIVEAU BALL"),
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING("Pour les POKéMON\nNORMAL, VOL, GLACE\nou de faible niveau."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LEVEL,
        .iconPic = gItemIcon_LevelBall,
        .iconPalette = gItemIconPalette_LevelBall,
    },

    [ITEM_LURE_BALL] =
    {
        .name = ITEM_NAME("APPÂT BALL"),
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING("Pour les POKéMON\nEAU, DRAGON ou\npêchés à la ligne."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LURE,
        .iconPic = gItemIcon_LureBall,
        .iconPalette = gItemIconPalette_LureBall,
    },

    [ITEM_MOON_BALL] =
    {
        .name = ITEM_NAME("LUNE BALL"),
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING("Pour les POKéMON\nTÉNÈBRES, SPECTRE,\nPOISON ou Pierre Lune."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MOON,
        .iconPic = gItemIcon_MoonBall,
        .iconPalette = gItemIconPalette_MoonBall,
    },

    [ITEM_FRIEND_BALL] =
    {
        .name = ITEM_NAME("COPAIN BALL"),
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING("Pour les POKéMON\nINSECTE, PLANTE et\nles rendre amicaux."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FRIEND,
        .iconPic = gItemIcon_FriendBall,
        .iconPalette = gItemIconPalette_FriendBall,
    },

    [ITEM_LOVE_BALL] =
    {
        .name = ITEM_NAME("LOVE BALL"),
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING("Pour les POKéMON\nPSY, FÉE et de sexe\nopposé."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LOVE,
        .iconPic = gItemIcon_LoveBall,
        .iconPalette = gItemIconPalette_LoveBall,
    },

    [ITEM_FAST_BALL] =
    {
        .name = ITEM_NAME("SPEED BALL"),
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING("Pour les POKéMON\nrapides, FEU,\nÉLECTRIK ou COMBAT."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FAST,
        .iconPic = gItemIcon_FastBall,
        .iconPalette = gItemIconPalette_FastBall,
    },

    [ITEM_HEAVY_BALL] =
    {
        .name = ITEM_NAME("MASSE BALL"),
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING("Pour les POKéMON\nROCHE, SOL, ACIER\nou très lourds."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAVY,
        .iconPic = gItemIcon_HeavyBall,
        .iconPalette = gItemIconPalette_HeavyBall,
    },

    [ITEM_DREAM_BALL] =
    {
        .name = ITEM_NAME("RÊVE BALL"),
        .price = 0,
        .description = COMPOUND_STRING(
        #if B_DREAM_BALL_MODIFIER >= GEN_8
            "Une Ball efficace\n"
            "sur les POKéMON\n"
            "endormis."),
        #else
            "Une POKé BALL utilisée\n"
            "dans la Forêt d'Entree."),
        #endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DREAM,
        .iconPic = gItemIcon_DreamBall,
        .iconPalette = gItemIconPalette_DreamBall,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = ITEM_NAME("SAFARI BALL"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une Poké Ball spéciale\n"
            "anciennement utilisée au\n"
            "Parc Safari de Kanto et au\n"
            "Grand Marais de Sinnoh."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SAFARI,
        .iconPic = gItemIcon_SafariBall,
        .iconPalette = gItemIconPalette_SafariBall,
    },

    [ITEM_SPORT_BALL] =
    {
        .name = ITEM_NAME("COMPÉT’BALL"),
        .price = (I_PRICE <= GEN_3 || I_PRICE >= GEN_9) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Une Poké Ball\n"
            "spéciale utilisée\n"
            "au Concours de\n"
            "Capture d'insecte."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SPORT,
        .iconPic = gItemIcon_SportBall,
        .iconPalette = gItemIconPalette_SportBall,
    },

    [ITEM_PARK_BALL] =
    {
        .name = ITEM_NAME("PARC BALL"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une Poké Ball\n"
            "spéciale utilisée\n"
            "au Parc des Amis."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PARK,
        .iconPic = gItemIcon_ParkBall,
        .iconPalette = gItemIconPalette_ParkBall,
    },

    [ITEM_BEAST_BALL] =
    {
        .name = ITEM_NAME("ULTRA BALL"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une Poké Ball un peu\n"
            "spéciale avec laquelle il est\n"
            "assez difficile de capturer\n"
            "des Pokémon."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_BEAST,
        .iconPic = gItemIcon_BeastBall,
        .iconPalette = gItemIconPalette_BeastBall,
    },

    [ITEM_CHERISH_BALL] =
    {
        .name = ITEM_NAME("MÉMOIRE BALL"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une Poké Ball\n"
            "plutôt rare qui fut\n"
            "créée pour une\n"
            "occasion spéciale."
        ),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_CHERISH,
        .iconPic = gItemIcon_CherishBall,
        .iconPalette = gItemIconPalette_CherishBall,
    },

// Medicine

    [ITEM_POTION] =
    {
        .name = ITEM_NAME("POTION"),
        .price = (I_PRICE >= GEN_7) ? 200 : 300,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Un spray qui soigne\n"
            "les blessures.\n"
            "Restaure 20 PV à un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_Potion,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = ITEM_NAME("SUPER POTION"),
        .price = 700,
        .holdEffectParam = 60,
        .description = COMPOUND_STRING(
            "Restaure les PV d'un\n"
            "POKéMON de\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "60 points."),
        #else
            "50 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_SuperPotion,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = ITEM_NAME("HYPER POTION"),
        .price = (I_PRICE >= GEN_2 && I_PRICE <= GEN_6) ? 1200 : 1500,
        .holdEffectParam = 120,
        .description = COMPOUND_STRING(
            "Restaure les PV d'un\n"
            "POKéMON de\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "120 points."),
        #else
            "200 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_HyperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_HyperPotion,
    },

    [ITEM_MAX_POTION] =
    {
        .name = ITEM_NAME("POTION MAX"),
        .price = 2500,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Un spray qui soigne les\n"
            "blessures. Restaure tous\n"
            "les PV d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MaxPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_MaxPotion,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = ITEM_NAME("GUÉRISON"),
        .price = 3000,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Un médicament qui restaure\n"
            "tous les PV d'un Pokémon et\n"
            "soigne tous ses problèmes\n"
            "de statut."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_HEAL_AND_CURE_STATUS,
        .effect = gItemEffect_FullRestore,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_FullRestore,
    },

    [ITEM_REVIVE] =
    {
        .name = ITEM_NAME("RAPPEL"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 1500,
        .description = COMPOUND_STRING(
            "Un médicament qui\n"
            "ranime un Pokémon\n"
            "K.O. et restaure la\n"
            "moitié de ses PV\n"
            "max."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_Revive,
        .flingPower = 30,
        .iconPic = gItemIcon_Revive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = ITEM_NAME("RAPPEL MAX"),
        .price = 4000,
        .description = COMPOUND_STRING(
            "Un médicament qui\n"
            "ranime un Pokémon\n"
            "K.O. et restaure\n"
            "tous ses PV."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxRevive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = ITEM_NAME("EAU FRAÎCHE"),
        .price = 200,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "Une eau minérale\n"
            "qui restaure\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 30 points."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FreshWater,
        .flingPower = 30,
        .iconPic = gItemIcon_FreshWater,
        .iconPalette = gItemIconPalette_FreshWater,
    },

    [ITEM_SODA_POP] =
    {
        .name = ITEM_NAME("SODA COOL"),
        .price = 300,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Un soda pétillant\n"
            "qui restaure\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 50 points."),
        #else
            "by 60 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SodaPop,
        .flingPower = 30,
        .iconPic = gItemIcon_SodaPop,
        .iconPalette = gItemIconPalette_SodaPop,
    },

    [ITEM_LEMONADE] =
    {
        .name = ITEM_NAME("LIMONADE"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 70,
        .description = COMPOUND_STRING(
            "Une boisson sucrée\n"
            "qui restaure\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 70 points."),
        #else
            "by 80 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Lemonade,
        .flingPower = 30,
        .iconPic = gItemIcon_Lemonade,
        .iconPalette = gItemIconPalette_Lemonade,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = ITEM_NAME("LAIT MEUMEU"),
        .price = (I_PRICE >= GEN_7) ? 600 : 500,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Un lait très nourrissant.\n"
            "Restaure 100 PV à un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MoomooMilk,
        .flingPower = 30,
        .iconPic = gItemIcon_MoomooMilk,
        .iconPalette = gItemIconPalette_MoomooMilk,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = ITEM_NAME("POUDRÉNERGIE"),
        .price = 500,
        .description = COMPOUND_STRING(
            "Une poudre amère\n"
            "qui restaure\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 60 points."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_EnergyPowder,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = ITEM_NAME("RACINÉNERGIE"),
        .price = (I_PRICE >= GEN_7) ? 1200 : 800,
        .description = COMPOUND_STRING(
            "Une racine amère\n"
            "qui restaure\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 120 points."),
        #else
            "by 200 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyRoot,
        .flingPower = 30,
        .iconPic = gItemIcon_EnergyRoot,
        .iconPalette = gItemIconPalette_EnergyRoot,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = ITEM_NAME("POUDRE SOIN"),
        .price = (I_PRICE >= GEN_7) ? 300 : 450,
        .description = COMPOUND_STRING(
            "Une poudre médicinale très\n"
            "amère. Soigne tous les\n"
            "problèmes de statut d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_HealPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_HealPowder,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = ITEM_NAME("HERBE RAPPEL"),
        .price = 2800,
        .description = COMPOUND_STRING(
            "Une herbe médicinale très\n"
            "amère. Ranime un Pokémon\n"
            "K.O. et restaure tous ses\n"
            "PV."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_RevivalHerb,
        .flingPower = 30,
        .iconPic = gItemIcon_RevivalHerb,
        .iconPalette = gItemIconPalette_RevivalHerb,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = ITEM_NAME("ANTIDOTE"),
        .price = (I_PRICE >= GEN_7) ? 200 : 100,
        .description = COMPOUND_STRING(
            "Un médicament sous\n"
            "forme de spray.\n"
            "Guérit un Pokémon\n"
            "empoisonné."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Antidote,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = ITEM_NAME("ANTI-PARA"),
        .price = (I_PRICE == GEN_7) ? 300 : 200,
        .description = COMPOUND_STRING(
            "Un médicament sous\n"
            "forme de spray.\n"
            "Soigne un Pokémon\n"
            "de la paralysie."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_ParalyzeHeal,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = ITEM_NAME("ANTI-BRÛLE"),
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "Un médicament sous\n"
            "forme de spray.\n"
            "Soigne les brûlures\n"
            "d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_BurnHeal,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = ITEM_NAME("ANTIGEL"),
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "Un médicament sous\n"
            "forme de spray.\n"
            "Réchauffe un\n"
            "Pokémon gelé."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_IceHeal,
    },

    [ITEM_AWAKENING] =
    {
        .name = ITEM_NAME("RÉVEIL"),
    #if (I_PRICE >= GEN_8 || I_PRICE == GEN_1)
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "Un médicament sous\n"
            "forme de spray.\n"
            "Réveille un Pokémon\n"
            "endormi."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Awakening,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = ITEM_NAME("TOTAL SOIN"),
        .price = (I_PRICE >= GEN_7) ? 400 : 600,
        .description = COMPOUND_STRING(
            "Un médicament sous forme de\n"
            "spray. Soigne tous les\n"
            "problèmes de statut d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_FullHeal,
        .iconPalette = gItemIconPalette_FullHeal,
    },

    [ITEM_ETHER] =
    {
        .name = ITEM_NAME("HUILE"),
        .price = (I_PRICE >= GEN_2) ? 1200 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Restaure 10 PP\n"
            "d'une capacité\n"
            "sélectionnée."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Ether,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Ether,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = ITEM_NAME("HUILE MAX"),
        .price = (I_PRICE >= GEN_2) ? 2000 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Restaure tous les\n"
            "PP d'une capacité\n"
            "sélectionnée."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxEther,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxEther,
    },

    [ITEM_ELIXIR] =
    {
        .name = ITEM_NAME("ÉLIXIR"),
        .price = (I_PRICE >= GEN_2) ? 3000 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Restaure 10 PP de\n"
            "toutes les\n"
            "capacités d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Elixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Elixir,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = ITEM_NAME("ÉLIXIR MAX"),
        .price = (I_PRICE >= GEN_2) ? 4500 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Restaure tous les\n"
            "PP de toutes les\n"
            "capacités d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxElixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxElixir,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = ITEM_NAME("JUS DE BAIE"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Une boisson 100%\n"
            "pur jus de Baies.\n"
            "Restaure 20 PV à un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_BerryJuice,
        .iconPalette = gItemIconPalette_BerryJuice,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = ITEM_NAME("CENDRE SACRÉE"),
        .pluralName = ITEM_PLURAL_NAME("CENDRES SACRÉES"),
        .price = (I_PRICE >= GEN_7) ? 50000 : 200,
        .description = COMPOUND_STRING(
            "Ranime tous les\n"
            "Pokémon K.O. et\n"
            "restaure tous\n"
            "leurs PV."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
        .effect = gItemEffect_SacredAsh,
        .flingPower = 30,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_SacredAsh,
    },

    [ITEM_SWEET_HEART] =
    {
        .name = ITEM_NAME("CHOCOCŒUR"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 100,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Un chocolat\n"
            "extrêmement sucré.\n"
            "Restaure 20 PV à un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetHeart,
        .iconPalette = gItemIconPalette_SweetHeart,
    },

    [ITEM_MAX_HONEY] =
    {
        .name = ITEM_NAME("MAXI MIEL"),
        .pluralName = ITEM_PLURAL_NAME("MAXI MIELS"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "Un miel crémeux produit par\n"
            "un Apireine Dynamax qui\n"
            "permet d'adoucir le goût de\n"
            "la Maxi Soupe. Il a également\n"
            "le même effet qu'un Rappel\n"
            "Max."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxHoney,
        .iconPalette = gItemIconPalette_MaxHoney,
    },

// Regional Specialties

    [ITEM_PEWTER_CRUNCHIES] =
    {
        .name = ITEM_NAME("CROK’ARGENTA"),
        .pluralName = ITEM_PLURAL_NAME("CROK'ARGENTA"),
        .price = 250,
        .description = COMPOUND_STRING(
            "Une spécialité d'Argenta.\n"
            "Soigne toutes les\n"
            "altérations de statut d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_PewterCrunchies,
        .iconPalette = gItemIconPalette_PewterCrunchies,
    },

    [ITEM_RAGE_CANDY_BAR] =
    {
        .name = ITEM_NAME("BONBON RAGE"),
        .price = (I_PRICE >= GEN_7) ? 350 : 300,
        .description = COMPOUND_STRING(
            "Un bonbon, spécialité\n"
            "d'Acajou. Il constitue un\n"
            "cadeau très réputé."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_RageCandyBar,
        .iconPalette = gItemIconPalette_RageCandyBar,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = ITEM_NAME("LAVA COOKIE"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
            "Une spécialité de Vermilava.\n"
            "Soigne toutes les\n"
            "altérations de statut d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LavaCookie,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_OLD_GATEAU] =
    {
        .name = ITEM_NAME("VIEUX GÂTEAU"),
        .pluralName = ITEM_PLURAL_NAME("VIEUX GÂTEAUX"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
            "Spécialité du Vieux\n"
            "Château. Il soigne\n"
            "tous les problèmes\n"
            "de statut d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_OldGateau,
        .iconPalette = gItemIconPalette_OldGateau,
    },

    [ITEM_CASTELIACONE] =
    {
        .name = ITEM_NAME("GLACE VOLUTE"),
        .price = (I_PRICE >= GEN_7) ? 350 : 100,
        .description = COMPOUND_STRING(
            "Spécialité de Volucité. Elle\n"
            "soigne tous les problèmes de\n"
            "statut d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_Casteliacone,
        .iconPalette = gItemIconPalette_Casteliacone,
    },

    [ITEM_LUMIOSE_GALETTE] =
    {
        .name = ITEM_NAME("GALETTE ILLUMIS"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
            "La spécialité d'Illumis. Elle\n"
            "soigne tous les problèmes de\n"
            "statut d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LumioseGalette,
        .iconPalette = gItemIconPalette_LumioseGalette,
    },

    [ITEM_SHALOUR_SABLE] =
    {
        .name = ITEM_NAME("SABLÉ YANTREIZH"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
            "Une spécialité de Kalos.\n"
            "Soigne toutes les\n"
            "altérations de statut d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_ShalourSable,
        .iconPalette = gItemIconPalette_ShalourSable,
    },

    [ITEM_BIG_MALASADA] =
    {
        .name = ITEM_NAME("MALASADA MAXI"),
        .price = 350,
        .description = COMPOUND_STRING(
            "Une spécialité d'Alola. Soigne\n"
            "toutes les altérations de\n"
            "statut d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMalasada,
        .iconPalette = gItemIconPalette_BigMalasada,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = ITEM_NAME("PV PLUS"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Une boisson très\n"
            "nutritive qui monte\n"
            "les PV de base d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_HPUp,
        .iconPalette = gItemIconPalette_HPUp,
    },

    [ITEM_PROTEIN] =
    {
        .name = ITEM_NAME("PROTÉINE"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Une boisson très\n"
            "nutritive qui monte\n"
            "l'Attaque de base\n"
            "d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Protein,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Protein,
    },

    [ITEM_IRON] =
    {
        .name = ITEM_NAME("FER"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Une boisson très\n"
            "nutritive qui monte\n"
            "la Défense de base\n"
            "d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Iron,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Iron,
    },

    [ITEM_CALCIUM] =
    {
        .name = ITEM_NAME("CALCIUM"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Une boisson très\n"
            "nutritive qui monte\n"
            "l'Attaque Spéciale\n"
            "de base d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Calcium,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Calcium,
    },

    [ITEM_ZINC] =
    {
        .name = ITEM_NAME("ZINC"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Une boisson très\n"
            "nutritive qui monte\n"
            "la Défense Spéciale\n"
            "d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Zinc,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Zinc,
    },

    [ITEM_CARBOS] =
    {
        .name = ITEM_NAME("CARBONE"),
        .pluralName = ITEM_PLURAL_NAME("CARBONES"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Une boisson très\n"
            "nutritive qui monte\n"
            "la Vitesse de base\n"
            "d'un Pokémon."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Carbos,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Carbos,
    },

    [ITEM_PP_UP] =
    {
        .name = ITEM_NAME("PP PLUS"),
    #if I_PRICE >= GEN_7
        .price = 10000,
    #elif I_PRICE >= GEN_2
        .price = 9800,
    #else
        .price = 1,
    #endif
        .description = COMPOUND_STRING(
            "Monte un peu les PP\n"
            "max d'une capacité\n"
            "sélectionnée."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_PPUp,
        .iconPalette = gItemIconPalette_PPUp,
    },

    [ITEM_PP_MAX] =
    {
        .name = ITEM_NAME("PP MAX"),
        .pluralName = ITEM_PLURAL_NAME("PP MAX"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Monte sensiblement\n"
            "les PP max d'une\n"
            "capacité\n"
            "sélectionnée."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPMax,
        .flingPower = 30,
        .iconPic = gItemIcon_PPMax,
        .iconPalette = gItemIconPalette_PPMax,
    },

// EV Feathers

    [ITEM_HEALTH_FEATHER] =
    {
        .name = ITEM_NAME("PLUME SANTÉ"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = COMPOUND_STRING(
            "Objet à utiliser sur\n"
            "un Pokémon pour un\n"
            "peu augmenter ses\n"
            "PV de base."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_HealthFeather,
    },

    [ITEM_MUSCLE_FEATHER] =
    {
        .name = ITEM_NAME("PLUME FORCE"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = COMPOUND_STRING(
            "Objet à utiliser sur\n"
            "un Pokémon pour un\n"
            "peu augmenter son\n"
            "Attaque de base."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_MuscleFeather,
    },

    [ITEM_RESIST_FEATHER] =
    {
        .name = ITEM_NAME("PLUME ARMURE"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = COMPOUND_STRING(
            "Objet à utiliser sur\n"
            "un Pokémon pour un\n"
            "peu augmenter sa\n"
            "Défense de base."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_ResistFeather,
    },

    [ITEM_GENIUS_FEATHER] =
    {
        .name = ITEM_NAME("PLUME ESPRIT"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = COMPOUND_STRING(
            "Objet à utiliser sur\n"
            "un Pokémon pour un\n"
            "peu augmenter son\n"
            "Attaque Spéciale\n"
            "de base."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_GeniusFeather,
    },

    [ITEM_CLEVER_FEATHER] =
    {
        .name = ITEM_NAME("PLUME MENTAL"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = COMPOUND_STRING(
            "Objet à utiliser sur\n"
            "un Pokémon pour un\n"
            "peu augmenter sa\n"
            "Défense Spéciale\n"
            "de base."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_CleverFeather,
    },

    [ITEM_SWIFT_FEATHER] =
    {
        .name = ITEM_NAME("PLUME SPRINT"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = COMPOUND_STRING(
            "Objet à utiliser sur\n"
            "un Pokémon pour un\n"
            "peu augmenter sa\n"
            "Vitesse de base."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_SwiftFeather,
    },

// Ability Modifiers

    [ITEM_ABILITY_CAPSULE] =
    {
        .name = ITEM_NAME("PILULE TALENT"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 1000,
    #endif
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une capsule permettant à un\n"
            "Pokémon pouvant avoir deux\n"
            "talents de passer de l'un à\n"
            "l'autre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,
        .iconPic = gItemIcon_AbilityCapsule,
        .iconPalette = gItemIconPalette_AbilityCapsule,
    },

    [ITEM_ABILITY_PATCH] =
    {
        .name = ITEM_NAME("PATCH TALENT"),
        .pluralName = ITEM_PLURAL_NAME("PATCHS TALENT"),
        .price = (I_PRICE >= GEN_9) ? 250000 : 20,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Un objet qui permet\n"
            "de remplacer le\n"
            "talent ordinaire\n"
            "d'un Pokémon par un\n"
            "talent rare."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityPatch,
        .iconPic = gItemIcon_AbilityPatch,
        .iconPalette = gItemIconPalette_AbilityPatch,
    },

// Mints

    [ITEM_LONELY_MINT] =
    {
        .name = ITEM_NAME("AROMATE SOLO"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "montera plus facilement,\n"
            "mais sa Défense se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LONELY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_ADAMANT_MINT] =
    {
        .name = ITEM_NAME("AROMATE RIGIDE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "montera plus facilement,\n"
            "mais son Attaque Spéciale se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_ADAMANT,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_NAUGHTY_MINT] =
    {
        .name = ITEM_NAME("AROMATE MAUVAIS"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "montera plus facilement,\n"
            "mais sa Défense Spéciale se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAUGHTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BRAVE_MINT] =
    {
        .name = ITEM_NAME("AROMATE BRAVE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "montera plus facilement,\n"
            "mais sa Vitesse se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BRAVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BOLD_MINT] =
    {
        .name = ITEM_NAME("AROMATE ASSURÉ"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "montera plus facilement,\n"
            "mais son Attaque se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BOLD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_IMPISH_MINT] =
    {
        .name = ITEM_NAME("AROMATE MALIN"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "montera plus facilement,\n"
            "mais son Attaque Spéciale se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_IMPISH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_LAX_MINT] =
    {
        .name = ITEM_NAME("AROMATE LÂCHE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "montera plus facilement,\n"
            "mais sa Défense Spéciale se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LAX,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_RELAXED_MINT] =
    {
        .name = ITEM_NAME("AROMATE RELAX"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "montera plus facilement,\n"
            "mais sa Vitesse se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RELAXED,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_MODEST_MINT] =
    {
        .name = ITEM_NAME("AROMATE MODESTE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "Spéciale montera plus\n"
            "facilement, mais son Attaque\n"
            "se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MODEST,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_MILD_MINT] =
    {
        .name = ITEM_NAME("AROMATE DOUX"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "Spéciale montera plus\n"
            "facilement, mais sa Défense\n"
            "se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MILD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_RASH_MINT] =
    {
        .name = ITEM_NAME("AROMATE FOUFOU"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "Spéciale montera plus\n"
            "facilement, mais sa Défense\n"
            "Spéciale se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RASH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_QUIET_MINT] =
    {
        .name = ITEM_NAME("AROMATE DISCRET"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque\n"
            "Spéciale montera plus\n"
            "facilement, mais sa Vitesse\n"
            "se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_QUIET,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_CALM_MINT] =
    {
        .name = ITEM_NAME("AROMATE CALME"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "Spéciale montera plus\n"
            "facilement, mais son Attaque\n"
            "se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CALM,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_GENTLE_MINT] =
    {
        .name = ITEM_NAME("AROMATE GENTIL"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "Spéciale montera plus\n"
            "facilement, mais sa Défense\n"
            "se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_GENTLE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_CAREFUL_MINT] =
    {
        .name = ITEM_NAME("AROMATE PRUDENT"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "Spéciale montera plus\n"
            "facilement, mais son Attaque\n"
            "Spéciale se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CAREFUL,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_SASSY_MINT] =
    {
        .name = ITEM_NAME("AROMATE MALPOLI"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Défense\n"
            "Spéciale montera plus\n"
            "facilement, mais sa Vitesse\n"
            "se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SASSY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_TIMID_MINT] =
    {
        .name = ITEM_NAME("AROMATE TIMIDE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Vitesse montera\n"
            "plus facilement, mais son\n"
            "Attaque se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_TIMID,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_HASTY_MINT] =
    {
        .name = ITEM_NAME("AROMATE PRESSÉ"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Vitesse montera\n"
            "plus facilement, mais sa\n"
            "Défense se développera plus\n"
            "lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_HASTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_JOLLY_MINT] =
    {
        .name = ITEM_NAME("AROMATE JOVIAL"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Vitesse montera\n"
            "plus facilement, mais son\n"
            "Attaque Spéciale se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_JOLLY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_NAIVE_MINT] =
    {
        .name = ITEM_NAME("AROMATE NAÏF"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, sa Vitesse montera\n"
            "plus facilement, mais sa\n"
            "Défense Spéciale se\n"
            "développera plus lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAIVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_SERIOUS_MINT] =
    {
        .name = ITEM_NAME("AROMATE SÉRIEUX"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Si un Pokémon hume cet\n"
            "aromate, son Attaque, sa\n"
            "Défense, sa Vitesse, son\n"
            "Attaque Spéciale et sa\n"
            "Défense Spéciale se\n"
            "développeront uniformément."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SERIOUS,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_YellowMint,
    },

// Candy

    [ITEM_RARE_CANDY] =
    {
        .name = ITEM_NAME("SUPER BONBON"),
        .pluralName = ITEM_PLURAL_NAME("SUPER BONBONS"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 4800,
        .description = COMPOUND_STRING(
            "Un bonbon plein\n"
            "d'énergie. Il permet\n"
            "à un Pokémon de\n"
            "monter d'un niveau."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_RareCandy,
        .iconPalette = gItemIconPalette_RareCandy,
    },

    [ITEM_EXP_CANDY_XS] =
    {
        .name = ITEM_NAME("BONBON EXP. XS"),
        .pluralName = ITEM_PLURAL_NAME("BONBONS EXP. XS"),
        .price = 20,
        .holdEffectParam = EXP_100,
        .description = COMPOUND_STRING(
            "Un bonbon plein d'énergie. Il\n"
            "permet à un Pokémon de\n"
            "gagner un petit peu de\n"
            "Points d'Expérience."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_S] =
    {
        .name = ITEM_NAME("BONBON EXP. S"),
        .pluralName = ITEM_PLURAL_NAME("BONBONS EXP. S"),
        .price = 240,
        .holdEffectParam = EXP_800,
        .description = COMPOUND_STRING(
            "Un bonbon plein d'énergie. Il\n"
            "permet à un Pokémon de\n"
            "gagner un peu de Points\n"
            "d'Expérience."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_M] =
    {
        .name = ITEM_NAME("BONBON EXP. M"),
        .pluralName = ITEM_PLURAL_NAME("BONBONS EXP. M"),
        .price = 1000,
        .holdEffectParam = EXP_3000,
        .description = COMPOUND_STRING(
            "Un bonbon plein d'énergie. Il\n"
            "permet à un Pokémon de\n"
            "gagner quelques Points\n"
            "d'Expérience."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyM,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_L] =
    {
        .name = ITEM_NAME("BONBON EXP. L"),
        .pluralName = ITEM_PLURAL_NAME("BONBONS EXP. L"),
        .price = 3000,
        .holdEffectParam = EXP_10000,
        .description = COMPOUND_STRING(
            "Un bonbon plein d'énergie. Il\n"
            "permet à un Pokémon de\n"
            "gagner une bonne quantité\n"
            "de Points d'Expérience."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_XL] =
    {
        .name = ITEM_NAME("BONBON EXP. XL"),
        .pluralName = ITEM_PLURAL_NAME("BONBONS EXP. XL"),
        .price = 10000,
        .holdEffectParam = EXP_30000,
        .description = COMPOUND_STRING(
            "Un bonbon plein d'énergie. Il\n"
            "permet à un Pokémon de\n"
            "gagner beaucoup de Points\n"
            "d'Expérience."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_DYNAMAX_CANDY] =
    {
        .name = ITEM_NAME("BONBON DYNAMAX"),
        .pluralName = ITEM_PLURAL_NAME("BONBONS DYNAMAX"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un bonbon plein d'énergie qui\n"
            "fait monter le niveau\n"
            "Dynamax d'un Pokémon d'un\n"
            "point. Plus ce dernier est\n"
            "élevé, plus les PV sous\n"
            "forme Dynamax augmentent."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_DynamaxCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_DynamaxCandy,
        .iconPalette = gItemIconPalette_DynamaxCandy,
    },

// Medicinal Flutes

    [ITEM_BLUE_FLUTE] =
    {
        .name = ITEM_NAME("FLÛTE BLEUE"),
        .price = (I_PRICE >= GEN_7) ? 20 : 100,
        .description = COMPOUND_STRING(
            "Un jouet en forme\n"
            "de flûte en verre\n"
            "bleu."
        ),
        .notConsumed = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlueFlute,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = ITEM_NAME("FLÛTE JAUNE"),
        .price = (I_PRICE >= GEN_7) ? 20 : 300,
        .description = COMPOUND_STRING(
            "Un jouet en forme\n"
            "de flûte en verre\n"
            "jaune."
        ),
        .notConsumed = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_YellowFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_YellowFlute,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = ITEM_NAME("FLÛTE ROUGE"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "Un jouet en forme\n"
            "de flûte en verre\n"
            "rouge."
        ),
        .notConsumed = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_RedFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_RedFlute,
    },

// Encounter-modifying Flutes

    [ITEM_BLACK_FLUTE] =
    {
        .name = ITEM_NAME("FLÛTE NOIRE"),
        .price = (I_PRICE >= GEN_7) ? 20 : 400,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Un jouet en forme\n"
            "de flûte en verre\n"
            "noir."
        ),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlackFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = ITEM_NAME("FLÛTE BLANCHE"),
        .price = (I_PRICE >= GEN_7) ? 20 : 500,
        .holdEffectParam = 150,
        .description = COMPOUND_STRING(
            "Un jouet en forme\n"
            "de flûte en verre\n"
            "blanc."
        ),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_WhiteFlute,
    },

// Encounter Modifiers

    [ITEM_REPEL] =
    {
        .name = ITEM_NAME("REPOUSSE"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Repousse les\n"
            "Pokémon sauvages\n"
            "faibles pendant\n"
            "100 pas."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_Repel,
    },

    [ITEM_SUPER_REPEL] =
    {
        .name = ITEM_NAME("SUPER REPOUSSE"),
        .price = (I_PRICE >= GEN_7) ? 700 : 500,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "Repousse les\n"
            "Pokémon sauvages\n"
            "faibles pendant\n"
            "200 pas."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_SuperRepel,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = ITEM_NAME("REPOUSSE MAX"),
        .price = (I_PRICE >= GEN_7) ? 900 : 700,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "Repousse les\n"
            "Pokémon sauvages\n"
            "faibles pendant\n"
            "250 pas."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_MaxRepel,
    },

    [ITEM_LURE] =
    {
        .name = ITEM_NAME("PARFUM"),
        .price = 400,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Une substance qui\n"
            "fait apparaître les\n"
            "Pokémon rares plus\n"
            "facilement pendant\n"
            "un court moment."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_Lure,
    },

    [ITEM_SUPER_LURE] =
    {
        .name = ITEM_NAME("SUPER PARFUM"),
        .price = 700,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "Une substance qui fait\n"
            "apparaître les Pokémon\n"
            "rares plus facilement\n"
            "pendant une durée plus\n"
            "longue que le Parfum."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_SuperLure,
    },

    [ITEM_MAX_LURE] =
    {
        .name = ITEM_NAME("PARFUM MAX"),
        .price = 900,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "Une substance qui fait\n"
            "apparaître les Pokémon\n"
            "rares plus facilement\n"
            "pendant une durée plus\n"
            "longue que le Super Parfum."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_MaxLure,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = ITEM_NAME("CORDE SORTIE"),
        .description = COMPOUND_STRING("Permet de fuir\nimmédiatement une\ngrotte ou un donjon."),
    #if I_KEY_ESCAPE_ROPE >= GEN_8
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #else
        //.price = (I_PRICE >= GEN_7) ? 1000 : 550,
        .price = 100,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
    #endif
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
        .flingPower = 30,
        .iconPic = gItemIcon_EscapeRope,
        .iconPalette = gItemIconPalette_EscapeRope,
    },

// X Items

    [ITEM_X_ATTACK] =
    {
        .name = ITEM_NAME("ATTAQUE +"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup\n"
            "l'Attaque durant\n"
            "un combat."),
        #else
            "Monte l'Attaque\n"
            "durant un combat."),
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAttack,
    },

    [ITEM_X_DEFENSE] =
    {
        .name = ITEM_NAME("DÉFENSE +"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 550,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup\n"
            "la Défense durant\n"
            "un combat."),
        #else
            "Monte la stat\n"
            "Defense during one\n"
            "battle."),
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XDefend,
    },

    [ITEM_X_SP_ATK] =
    {
        .name = ITEM_NAME("ATQ. SPÉ. +"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup\n"
            "l'Atq. Spé. durant\n"
            "un combat."),
        #else
            "Monte la stat\n"
            "Sp. Atk during one\n"
            "battle."),
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecial,
    },

    [ITEM_X_SP_DEF] =
    {
        .name = ITEM_NAME("DÉF. SPÉ. +"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup\n"
            "la Déf. Spé. durant\n"
            "un combat."),
        #else
            "Monte la stat\n"
            "Sp. Def during one\n"
            "battle."),
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecialDefense,
    },

    [ITEM_X_SPEED] =
    {
        .name = ITEM_NAME("VITESSE +"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup\n"
            "la Vitesse durant\n"
            "un combat."),
        #else
            "Monte la stat\n"
            "Speed during one\n"
            "battle."),
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpeed,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpeed,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = ITEM_NAME("PRÉCISION +"),
        .pluralName = ITEM_PLURAL_NAME("PRÉCISIONS +"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 950,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup la\n"
            "Précision durant\n"
            "un combat."),
        #else
            "Monte la Précision\n"
            "of attack moves\n"
            "during un combat."),
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAccuracy,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAccuracy,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = ITEM_NAME("MUSCLE +"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 650,
        .description = COMPOUND_STRING(
            "Monte fortement le taux de\n"
            "critiques. Utilisable une\n"
            "seule fois. L'effet\n"
            "disparaît si le Pokémon se\n"
            "retire."
        ),
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_FOCUS_ENERGY,
        .effect = gItemEffect_DireHit,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_DireHit,
    },

    [ITEM_GUARD_SPEC] =
    {
        .name = ITEM_NAME("GARDE-STATS"),
        .pluralName = ITEM_PLURAL_NAME("GARDES-STATS."),
        .price = (I_PRICE >= GEN_7) ? 1500 : 700,
        .description = COMPOUND_STRING(
            "Empêche la\n"
            "réduction des\n"
            "stats de tous les\n"
            "Pokémon de l'équipe\n"
            "pendant 5 tours."
        ),
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_MIST,
        .effect = gItemEffect_GuardSpec,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_GuardSpec,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = ITEM_NAME("POKÉ POUPÉE"),
    #if I_PRICE >= GEN_8
        .price = 300,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 1000,
    #endif
        .description = COMPOUND_STRING(
            "Une poupée qui attire les\n"
            "Pokémon. Permet de s'enfuir\n"
            "d'un combat contre un\n"
            "Pokémon sauvage."
        ),
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeDoll,
        .iconPalette = gItemIconPalette_PokeDoll,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = ITEM_NAME("QUEUE SKITTY"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = COMPOUND_STRING(
            "Objet qui attire\n"
            "les Pokémon. Permet\n"
            "de s'enfuir d'un\n"
            "combat contre un\n"
            "Pokémon sauvage."
        ),
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_FluffyTail,
        .iconPalette = gItemIconPalette_FluffyTail,
    },

    [ITEM_POKE_TOY] =
    {
        .name = ITEM_NAME("POKÉ PLUMET"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = COMPOUND_STRING(
            "Objet qui attire\n"
            "les Pokémon. Permet\n"
            "de s'enfuir d'un\n"
            "combat contre un\n"
            "Pokémon sauvage."
        ),
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeToy,
        .iconPalette = gItemIconPalette_PokeToy,
    },

    [ITEM_MAX_MUSHROOMS] =
    {
        .name = ITEM_NAME("MAXI CHAMPI"),
        .pluralName = ITEM_PLURAL_NAME("MAXI CHAMPIS"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "Un champignon pouvant\n"
            "modifier l'apparence des\n"
            "Pokémon Dynamax. Utilisé en\n"
            "combat, il augmente toutes\n"
            "les stats d'un Pokémon."
        ),
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_ALL_STATS,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxMushrooms,
        .iconPalette = gItemIconPalette_MaxMushrooms,
    },

// Treasures

    [ITEM_BOTTLE_CAP] =
    {
        .name = ITEM_NAME("CAPSULE D’ARGENT"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 5000,
        .description = COMPOUND_STRING(
            "Une jolie capsule\n"
            "en argent.\n"
            "Certaines\n"
            "personnes adorent\n"
            "en recevoir."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_BottleCap,
    },

    [ITEM_GOLD_BOTTLE_CAP] =
    {
        .name = ITEM_NAME("CAPSULE D’OR"),
        .price = (I_PRICE >= GEN_9) ? 60000 : 10000,
        .description = COMPOUND_STRING(
            "Une jolie capsule en or,\n"
            "encore plus rare que la\n"
            "Capsule d'Argent. Certaines\n"
            "personnes adorent en\n"
            "recevoir."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_GoldBottleCap,
    },

    [ITEM_NUGGET] =
    {
        .name = ITEM_NAME("PÉPITE"),
        .price = 10000 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Pépite d'or pur qui brille\n"
            "magnifiquement. Peut être\n"
            "vendue à bon prix aux\n"
            "magasins."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Nugget,
        .iconPalette = gItemIconPalette_Nugget,
    },

    [ITEM_BIG_NUGGET] =
    {
        .name = ITEM_NAME("MAXI PÉPITE"),
    #if I_PRICE >= GEN_7
        .price = 40000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 20000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "Grosse pépite d'or pur qui\n"
            "brille magnifiquement. Les\n"
            "amateurs en donnent un bon\n"
            "prix."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = B_UPDATED_MOVE_DATA >= GEN_8 ? 130 : 80,
        .iconPic = gItemIcon_BigNugget,
        .iconPalette = gItemIconPalette_BigNugget,
    },

    [ITEM_TINY_MUSHROOM] =
    {
        .name = ITEM_NAME("PETIT CHAMPI"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un petit champignon assez\n"
            "rare. Il est plutôt populaire\n"
            "parmi certains fans\n"
            "dévoués."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = ITEM_NAME("GROS CHAMPI"),
        .price = 5000 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un grand champignon assez\n"
            "rare. Il est très populaire\n"
            "parmi certains fans\n"
            "dévoués."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BALM_MUSHROOM] =
    {
        .name = ITEM_NAME("CHAMPI SUAVE"),
    #if I_PRICE >= GEN_7
        .price = 15000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 12500,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "Champignon rare qui répand\n"
            "un agréable parfum autour\n"
            "de lui. Les amateurs en\n"
            "donnent un bon prix."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BalmMushroom,
        .iconPalette = gItemIconPalette_BalmMushroom,
    },

    [ITEM_PEARL] =
    {
        .name = ITEM_NAME("PERLE"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR: 1400,
        .description = COMPOUND_STRING(
            "Une petite perle qui brille\n"
            "d'une jolie couleur argent.\n"
            "Peut être vendue à bas prix\n"
            "en magasin."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Pearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = ITEM_NAME("GRANDE PERLE"),
        .price = (I_PRICE >= GEN_7) ? 8000 * TREASURE_FACTOR: 7500,
        .description = COMPOUND_STRING(
            "Une grosse perle qui brille\n"
            "d'une jolie couleur argent.\n"
            "Peut être vendue à bon prix\n"
            "en magasin."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigPearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_PEARL_STRING] =
    {
        .name = ITEM_NAME("PERLE TRIPLE"),
    #if I_PRICE >= GEN_8
        .price = 20000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 30000,
    #elif I_PRICE == GEN_6
        .price = 15000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "Une très grosse perle qui\n"
            "brille d'une jolie couleur\n"
            "argent. Les amateurs en\n"
            "donnent un bon prix."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PearlString,
        .iconPalette = gItemIconPalette_PearlString,
    },

    [ITEM_STARDUST] =
    {
        .name = ITEM_NAME("POUSSIÈRE ÉTOILE"),
        .price = (I_PRICE >= GEN_7) ? 3000 * TREASURE_FACTOR: 2000,
        .description = COMPOUND_STRING(
            "Sable rouge ravissant, aux\n"
            "grains très fins. Peut être\n"
            "vendu à bon prix aux\n"
            "magasins."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = ITEM_NAME("MORCEAU D’ÉTOILE"),
        .price = (I_PRICE >= GEN_7) ? 12000 * TREASURE_FACTOR: 9800,
        .description = COMPOUND_STRING(
            "Fragment de gemme\n"
            "qui brille d'un\n"
            "éclat rouge. Peut\n"
            "se vendre à bon\n"
            "prix aux magasins."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_COMET_SHARD] =
    {
        .name = ITEM_NAME("MORCEAU COMÈTE"),
    #if I_PRICE >= GEN_8
        .price = 25000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 60000,
    #elif I_PRICE == GEN_6
        .price = 30000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "Un fragment de comète,\n"
            "tombé au sol quand elle\n"
            "traversait l'atmosphère. Les\n"
            "amateurs en donnent un bon\n"
            "prix."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_CometShard,
    },

    [ITEM_SHOAL_SALT] =
    {
        .name = ITEM_NAME("SEL TRÉFONDS"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Du sel provenant de\n"
            "la Grotte Tréfonds."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_ShoalSalt,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = ITEM_NAME("COQUILLETRÉFONDS"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Un coquillage\n"
            "provenant de la\n"
            "Grotte Tréfonds."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShoalShell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_RED_SHARD] =
    {
        .name = ITEM_NAME("TESSON ROUGE"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = COMPOUND_STRING(
            "Petit tesson rouge.\n"
            "Il semble provenir\n"
            "d'un outil très\n"
            "ancien."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_RedShard,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = ITEM_NAME("TESSON BLEU"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = COMPOUND_STRING(
            "Petit tesson bleu.\n"
            "Il semble provenir\n"
            "d'un outil très\n"
            "ancien."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_BlueShard,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = ITEM_NAME("TESSON JAUNE"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = COMPOUND_STRING(
            "Petit tesson jaune.\n"
            "Il semble provenir\n"
            "d'un outil très\n"
            "ancien."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_YellowShard,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = ITEM_NAME("TESSON VERT"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = COMPOUND_STRING(
            "Petit tesson vert.\n"
            "Il semble provenir\n"
            "d'un outil très\n"
            "ancien."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_GreenShard,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = ITEM_NAME("ÉCAILLE CŒUR"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Une très rare et jolie\n"
            "écaille en forme de cœur.\n"
            "Elle brille légèrement d'un\n"
            "éclat arc-en-ciel."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_HeartScale,
        .iconPalette = gItemIconPalette_HeartScale,
    },

    [ITEM_HONEY] =
    {
        .name = ITEM_NAME("MIEL"),
        .pluralName = ITEM_PLURAL_NAME("MIELS"),
    #if I_PRICE >= GEN_8
        .price = 900,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 100,
    #endif
        .description = COMPOUND_STRING(
            "Du miel au parfum\n"
            "riche rassemblé par\n"
            "des Pokémon. Peut\n"
            "être vendu à bas\n"
            "prix en magasin."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Honey,
        .flingPower = 30,
        .iconPic = gItemIcon_Honey,
        .iconPalette = gItemIconPalette_Honey,
    },

    [ITEM_RARE_BONE] =
    {
        .name = ITEM_NAME("OS RARE"),
        .price = (I_PRICE >= GEN_7) ? 5000 * TREASURE_FACTOR: 10000,
        .description = COMPOUND_STRING(
            "Un os d'une grande valeur\n"
            "pour l'archéologie Pokémon.\n"
            "Peut être vendu à bon prix\n"
            "en magasin."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_ODD_KEYSTONE] =
    {
        .name = ITEM_NAME("CLÉ DE VOÛTE"),
        .price = 2100,
        .description = COMPOUND_STRING(
            "Un objet très important qui\n"
            "empêche une tour en pierre\n"
            "de s'écrouler. Des voix en\n"
            "sortent parfois."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_OddKeystone,
        .iconPalette = gItemIconPalette_OddKeystone,
    },

    [ITEM_PRETTY_FEATHER] =
    {
        .name = ITEM_NAME("JOLIE PLUME"),
        .price = (I_PRICE >= GEN_7) ? 1000 * TREASURE_FACTOR: 200,
        .description = COMPOUND_STRING(
            "Une plume très\n"
            "jolie, mais\n"
            "ordinaire et sans\n"
            "effet particulier."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 20,
        .iconPic = gItemIcon_PrettyFeather,
        .iconPalette = gItemIconPalette_PrettyFeather,
    },

    [ITEM_RELIC_COPPER] =
    {
        .name = ITEM_NAME("VIEUX SOU"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une pièce de cuivre\n"
            "d'une civilisation\n"
            "vieille de plus de 3\n"
            "000 ans."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicCopper,
    },

    [ITEM_RELIC_SILVER] =
    {
        .name = ITEM_NAME("VIEIL ÉCU"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une pièce d'argent\n"
            "d'une civilisation\n"
            "vieille de plus de 3\n"
            "000 ans."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicSilver,
    },

    [ITEM_RELIC_GOLD] =
    {
        .name = ITEM_NAME("VIEUX DUCAT"),
        .price = (I_PRICE >= GEN_6) ? 60000 : 0,
        .description = COMPOUND_STRING(
            "Une pièce d'or d'une\n"
            "civilisation vieille\n"
            "de plus de 3 000\n"
            "ans."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicGold,
    },

    [ITEM_RELIC_VASE] =
    {
        .name = ITEM_NAME("VIEUX VASE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un vase d'une\n"
            "civilisation vieille\n"
            "de plus de 3 000\n"
            "ans."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicVase,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_BAND] =
    {
        .name = ITEM_NAME("VIEUX BIJOU"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un bijou d'une\n"
            "civilisation vieille\n"
            "de plus de 3 000\n"
            "ans."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicBand,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_STATUE] =
    {
        .name = ITEM_NAME("VIEUX SANTON"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une statuette\n"
            "d'une civilisation\n"
            "vieille de plus de 3\n"
            "000 ans."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicStatue,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_CROWN] =
    {
        .name = ITEM_NAME("VIEUX TORTIL"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une couronne d'une\n"
            "civilisation vieille\n"
            "de plus de 3 000\n"
            "ans."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCrown,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_STRANGE_SOUVENIR] =
    {
        .name = ITEM_NAME("BIBELOT BIZARRE"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 10,
        .description = COMPOUND_STRING("Un ornement\nreprésentant un\nPOKéMON d'ALOLA."),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

// Fossils

    [ITEM_HELIX_FOSSIL] =
    {
        .name = ITEM_NAME("NAUTILE"),
        .description = COMPOUND_STRING(
            "Un morceau de coquille\n"
            "d'un ancien POKéMON\n"
            "marin."),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_HelixFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE DÔME"),
        .description = COMPOUND_STRING(
            "Un morceau de carapace\n"
            "d'un ancien POKéMON\n"
            "marin."),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_DomeFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = ITEM_NAME("VIEIL AMBRE"),
        .description = COMPOUND_STRING("Une pierre contenant\nles gènes d'un\nancien POKéMON."),
    #if I_KEY_FOSSILS >= GEN_4
        .price = 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_OldAmber,
        .iconPalette = gItemIconPalette_OldAmber,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE RACINE"),
        .description = sRootFossilDesc,
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RootFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE GRIFFE"),
        .description = sRootFossilDesc,
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ClawFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_ARMOR_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE ARMURE"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Fossile d'un Pokémon\n"
            "préhistorique terrestre. On\n"
            "dirait une partie d'un\n"
            "collier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ArmorFossil,
        .iconPalette = gItemIconPalette_ArmorFossil,
    },

    [ITEM_SKULL_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE CRÂNE"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Fossile d'un Pokémon\n"
            "préhistorique terrestre. On\n"
            "dirait une partie d'un crâne."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SkullFossil,
        .iconPalette = gItemIconPalette_SkullFossil,
    },

    [ITEM_COVER_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE PLAQUE"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Fossile d'un ancien\n"
            "Pokémon aquatique.\n"
            "Il semble que ce\n"
            "soit une partie de\n"
            "son dos."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_CoverFossil,
        .iconPalette = gItemIconPalette_CoverFossil,
    },

    [ITEM_PLUME_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE PLUME"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Fossile d'un ancien\n"
            "Pokémon volant. Il\n"
            "semble que ce soit\n"
            "un morceau d'aile."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_PlumeFossil,
        .iconPalette = gItemIconPalette_PlumeFossil,
    },

    [ITEM_JAW_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE MÂCHOIRE"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Le fossile d'un Pokémon\n"
            "préhistorique terrestre. On\n"
            "dirait un morceau de\n"
            "mâchoire."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_JawFossil,
        .iconPalette = gItemIconPalette_JawFossil,
    },

    [ITEM_SAIL_FOSSIL] =
    {
        .name = ITEM_NAME("FOSSILE NAGEOIRE"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Le fossile d'un Pokémon\n"
            "préhistorique terrestre. On\n"
            "dirait un morceau de\n"
            "nageoire."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SailFossil,
        .iconPalette = gItemIconPalette_SailFossil,
    },

    [ITEM_FOSSILIZED_BIRD] =
    {
        .name = ITEM_NAME("FOSSILE OISEAU"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "Un morceau du\n"
            "fossile d'un ancien\n"
            "Pokémon volant. Nul\n"
            "ne sait à quoi il\n"
            "ressemblait."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedBird,
        .iconPalette = gItemIconPalette_FossilizedBird,
    },

    [ITEM_FOSSILIZED_FISH] =
    {
        .name = ITEM_NAME("FOSSILE POISSON"),
        .pluralName = ITEM_PLURAL_NAME("FOSSILES POISSON"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "Un morceau du\n"
            "fossile d'un ancien\n"
            "Pokémon aquatique.\n"
            "Nul ne sait à quoi il\n"
            "ressemblait."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedFish,
        .iconPalette = gItemIconPalette_FossilizedFish,
    },

    [ITEM_FOSSILIZED_DRAKE] =
    {
        .name = ITEM_NAME("FOSSILE DRAGON"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "Un morceau du\n"
            "fossile d'un ancien\n"
            "Pokémon terrestre.\n"
            "Nul ne sait à quoi il\n"
            "ressemblait."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDrake,
        .iconPalette = gItemIconPalette_FossilizedDrake,
    },

    [ITEM_FOSSILIZED_DINO] =
    {
        .name = ITEM_NAME("FOSSILE AILERON"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "Un morceau du\n"
            "fossile d'un ancien\n"
            "Pokémon aquatique.\n"
            "Nul ne sait à quoi il\n"
            "ressemblait."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDino,
        .iconPalette = gItemIconPalette_FossilizedDino,
    },

// Mulch

    [ITEM_GROWTH_MULCH] =
    {
        .name = ITEM_NAME("FERTIPOUSSE"),
        .pluralName = ITEM_PLURAL_NAME("FERTIPOUSSES"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais qui\naccélère la pousse\ndes Baies."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GROWTH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GrowthMulch,
    },

    [ITEM_DAMP_MULCH] =
    {
        .name = ITEM_NAME("FERTIHUMIDE"),
        .pluralName = ITEM_PLURAL_NAME("FERTIHUMIDES"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais qui\nralentit la pousse\ndes Baies."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_DAMP_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_DampMulch,
    },

    [ITEM_STABLE_MULCH] =
    {
        .name = ITEM_NAME("FERTISTABLE"),
        .pluralName = ITEM_PLURAL_NAME("FERTISTABLES"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais qui\nprolonge la vie\ndes plants de Baies."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_STABLE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_StableMulch,
        .iconPalette = gItemIconPalette_StableMulch,
    },

    [ITEM_GOOEY_MULCH] =
    {
        .name = ITEM_NAME("FERTIGLU"),
        .pluralName = ITEM_PLURAL_NAME("FERTIGLUS"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais faisant\nrepousser plus de\nBaies après leur chute."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GOOEY_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GooeyMulch,
    },

    [ITEM_RICH_MULCH] =
    {
        .name = ITEM_NAME("FERTIBONDANCE"),
        .pluralName = ITEM_PLURAL_NAME("FERTIBONDANCES"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais qui\naugmente le nombre\nde Baies récoltées."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_RICH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_RichMulch,
    },

    [ITEM_SURPRISE_MULCH] =
    {
        .name = ITEM_NAME("FERTISTANTANÉ"),
        .pluralName = ITEM_PLURAL_NAME("FERTISTANTANÉS"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais qui\nfavorise les\nmutations des Baies."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_SURPRISE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_SurpriseMulch,
    },

    [ITEM_BOOST_MULCH] =
    {
        .name = ITEM_NAME("FERTIBÉRANCE"),
        .pluralName = ITEM_PLURAL_NAME("FERTIBÉRANCES"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais qui\naccélère le séchage\ndu sol meuble."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_BOOST_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_BoostMulch,
    },

    [ITEM_AMAZE_MULCH] =
    {
        .name = ITEM_NAME("FERTIPRODIGE"),
        .pluralName = ITEM_PLURAL_NAME("FERTIPRODIGES"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING("Un engrais à la fois\nFertile, Surprise\net Prodige."),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_AMAZE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_AmazeMulch,
    },

// Apricorns
    #if (I_PRICE >= GEN_8 || I_PRICE <= GEN_2)
        #define APRICORN_PRICE 200
    #elif I_PRICE >= GEN_5
        #define APRICORN_PRICE 20
    #else
        #define APRICORN_PRICE 0
    #endif

    [ITEM_RED_APRICORN] =
    {
        .name = ITEM_NAME("NOIGRUME ROUGE"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "Un Noigrume de\n"
            "couleur rouge. Il\n"
            "dégage un puissant\n"
            "arôme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_RedApricorn,
    },

    [ITEM_BLUE_APRICORN] =
    {
        .name = ITEM_NAME("NOIGRUME BLEU"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "Un Noigrume de\n"
            "couleur bleue. Il\n"
            "dégage un arôme un\n"
            "peu aigre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlueApricorn,
    },

    [ITEM_YELLOW_APRICORN] =
    {
        .name = ITEM_NAME("NOIGRUME JAUNE"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "Un Noigrume de\n"
            "couleur jaune. Il\n"
            "dégage un arôme\n"
            "délicat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_YellowApricorn,
    },

    [ITEM_GREEN_APRICORN] =
    {
        .name = ITEM_NAME("NOIGRUME VERT"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "Un Noigrume de\n"
            "couleur verte. Il\n"
            "dégage un arôme\n"
            "étonnamment riche."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_GreenApricorn,
    },

    [ITEM_PINK_APRICORN] =
    {
        .name = ITEM_NAME("NOIGRUME ROSE"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "Un Noigrume de\n"
            "couleur rose. Il\n"
            "dégage un arôme\n"
            "sucré."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_PinkApricorn,
    },

    [ITEM_WHITE_APRICORN] =
    {
        .name = ITEM_NAME("NOIGRUME BLANC"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "Un Noigrume de\n"
            "couleur blanche. Il\n"
            "ne dégage aucun\n"
            "arôme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_WhiteApricorn,
    },

    [ITEM_BLACK_APRICORN] =
    {
        .name = ITEM_NAME("NOIGRUME NOIR"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "Un Noigrume de\n"
            "couleur noire. Il\n"
            "dégage un arôme\n"
            "indéfinissable."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlackApricorn,
    },

    [ITEM_WISHING_PIECE] =
    {
        .name = ITEM_NAME("MORCEAU VŒU"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Un objet à lancer dans\n"
            "l'antre d'un Pokémon pour y\n"
            "faire apparaître un\n"
            "Pokémon Dynamax."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .flingPower = 50,
        .iconPic = gItemIcon_WishingPiece,
        .iconPalette = gItemIconPalette_WishingPiece,
    },

    [ITEM_GALARICA_TWIG] =
    {
        .name = ITEM_NAME("BRANCHE GALANOA"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Une branche de Galanoa, un\n"
            "arbre qui pousse dans\n"
            "certains endroits de Galar.\n"
            "Elle sert à fabriquer des\n"
            "accessoires pour un\n"
            "Pokémon en particulier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaTwig,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_ARMORITE_ORE] =
    {
        .name = ITEM_NAME("ARMURIUM"),
        .pluralName = ITEM_PLURAL_NAME("ARMURIUM"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Un minerai rare que l'on\n"
            "trouve à Isolarmure. Vous\n"
            "pourriez avoir une bonne\n"
            "surprise en le donnant à un\n"
            "collectionneur de l'île."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ArmoriteOre,
        .iconPalette = gItemIconPalette_ArmoriteOre,
    },

    [ITEM_DYNITE_ORE] =
    {
        .name = ITEM_NAME("DYNAMAXIUM"),
        .pluralName = ITEM_PLURAL_NAME("DYNAMAXIUM"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Un minerai\n"
            "mystérieux que l'on\n"
            "trouve dans le\n"
            "Grand Antre\n"
            "Dynamax."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_DyniteOre,
        .iconPalette = gItemIconPalette_DyniteOre,
    },

// Mail

    [ITEM_ORANGE_MAIL] =
    {
        .name = ITEM_NAME("LETTRE ORANJ"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES ORANJ"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Zigzaton\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
        .iconPic = gItemIcon_OrangeMail,
        .iconPalette = gItemIconPalette_OrangeMail,
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = ITEM_NAME("LETTRE PORT"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES PORT"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Goelise\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
        .iconPic = gItemIcon_HarborMail,
        .iconPalette = gItemIconPalette_HarborMail,
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = ITEM_NAME("LETTRE BRILL"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES BRILL"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Pikachu\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
        .iconPic = gItemIcon_GlitterMail,
        .iconPalette = gItemIconPalette_GlitterMail,
    },

    [ITEM_MECH_MAIL] =
    {
        .name = ITEM_NAME("LETTRE MÉCA"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES MÉCA"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Magneti\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
        .iconPic = gItemIcon_MechMail,
        .iconPalette = gItemIconPalette_MechMail,
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = ITEM_NAME("LETTRE BOIS"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES BOIS"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Parecool\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
        .iconPic = gItemIcon_WoodMail,
        .iconPalette = gItemIconPalette_WoodMail,
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = ITEM_NAME("LETTRE VAGUE"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES VAGUE"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Wailmer\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
        .iconPic = gItemIcon_WaveMail,
        .iconPalette = gItemIconPalette_WaveMail,
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = ITEM_NAME("LETTRE BULLE"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES BULLE"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Du papier avec un\n"
            "dessin du Pokémon\n"
            "qui le tient."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
        .iconPic = gItemIcon_BeadMail,
        .iconPalette = gItemIconPalette_BeadMail,
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = ITEM_NAME("LETTRE OMBRE"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES OMBRE"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Skelenox\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
        .iconPic = gItemIcon_ShadowMail,
        .iconPalette = gItemIconPalette_ShadowMail,
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = ITEM_NAME("LETTRE TROPI"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES TROPI"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier Joliflor\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
        .iconPic = gItemIcon_TropicMail,
        .iconPalette = gItemIconPalette_TropicMail,
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = ITEM_NAME("LETTRE SONGE"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES SONGE"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Du papier avec un\n"
            "dessin du Pokémon\n"
            "qui le tient."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
        .iconPic = gItemIcon_DreamMail,
        .iconPalette = gItemIconPalette_DreamMail,
    },

    [ITEM_FAB_MAIL] =
    {
        .name = ITEM_NAME("LETTRE COOL"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES COOL"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Papier magnifique\n"
            "pouvant être tenu\n"
            "par un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
        .iconPic = gItemIcon_FabMail,
        .iconPalette = gItemIconPalette_FabMail,
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = ITEM_NAME("LETTRE RETRO"),
        .pluralName = ITEM_PLURAL_NAME("LETTRES RETRO"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Du papier avec les\n"
            "dessins de trois\n"
            "Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
        .iconPic = gItemIcon_RetroMail,
        .iconPalette = gItemIconPalette_RetroMail,
    },

// Evolution Items

    [ITEM_FIRE_STONE] =
    {
        .name = ITEM_NAME("PIERRE FEU"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Une pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Elle est jaune\n"
            "et orange."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_FireStone,
        .iconPalette = gItemIconPalette_FireStone,
    },

    [ITEM_WATER_STONE] =
    {
        .name = ITEM_NAME("PIERRE EAU"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Une pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Elle est de\n"
            "couleur bleue."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_WaterStone,
        .iconPalette = gItemIconPalette_WaterStone,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = ITEM_NAME("PIERRE FOUDRE"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Une pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Un éclair est\n"
            "dessiné dessus."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ThunderStone,
        .iconPalette = gItemIconPalette_ThunderStone,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = ITEM_NAME("PIERRE PLANTE"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Une pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Une feuille est\n"
            "dessinée dessus."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LeafStone,
        .iconPalette = gItemIconPalette_LeafStone,
    },

    [ITEM_ICE_STONE] =
    {
        .name = ITEM_NAME("PIERRE GLACE"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Une pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Un flocon de\n"
            "neige semble dessiné dessus."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_IceStone,
        .iconPalette = gItemIconPalette_IceStone,
    },

    [ITEM_SUN_STONE] =
    {
        .name = ITEM_NAME("PIERRE SOLEIL"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Une pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Elle est rouge\n"
            "comme le soleil."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SunStone,
        .iconPalette = gItemIconPalette_SunStone,
    },

    [ITEM_MOON_STONE] =
    {
        .name = ITEM_NAME("PIERRE LUNE"),
    #if I_PRICE >= GEN_7
        .price = 3000,
    #elif I_PRICE >= GEN_4
        .price = 2100,
    #elif I_PRICE == GEN_3
        .price = 0,
    #else
        .price = 10000,
    #endif
        .description = COMPOUND_STRING(
            "Une pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Elle est noire\n"
            "comme la nuit."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MoonStone,
        .iconPalette = gItemIconPalette_MoonStone,
    },

    [ITEM_SHINY_STONE] =
    {
        .name = ITEM_NAME("PIERRE ÉCLAT"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Elle brille d'une\n"
            "lumière aveuglante."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ShinyStone,
        .iconPalette = gItemIconPalette_ShinyStone,
    },

    [ITEM_DUSK_STONE] =
    {
        .name = ITEM_NAME("PIERRE NUIT"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Pierre étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Elle est sombre\n"
            "comme une nuit sans lune."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DuskStone,
        .iconPalette = gItemIconPalette_DuskStone,
    },

    [ITEM_DAWN_STONE] =
    {
        .name = ITEM_NAME("PIERRE AUBE"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Pierre étrange qui\n"
            "fait évoluer\n"
            "certaines espèces\n"
            "de Pokémon. Elle\n"
            "brille comme un œil."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DawnStone,
        .iconPalette = gItemIconPalette_DawnStone,
    },

    [ITEM_SWEET_APPLE] =
    {
        .name = ITEM_NAME("POMME SUCRÉE"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "Une pomme\n"
            "mystérieuse très\n"
            "sucrée qui permet\n"
            "de faire évoluer un\n"
            "certain Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetApple,
        .iconPalette = gItemIconPalette_SweetApple,
    },

    [ITEM_TART_APPLE] =
    {
        .name = ITEM_NAME("POMME ACIDULÉE"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "Une pomme\n"
            "mystérieuse très\n"
            "acide qui permet de\n"
            "faire évoluer un\n"
            "certain Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_TartApple,
        .iconPalette = gItemIconPalette_TartApple,
    },

    [ITEM_CRACKED_POT] =
    {
        .name = ITEM_NAME("THÉIÈRE FÊLÉE"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "Un récipient mystérieux\n"
            "pouvant faire évoluer un\n"
            "certain Pokémon. Il est\n"
            "abîmé, mais on y fait du bon\n"
            "thé."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_CrackedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_CHIPPED_POT] =
    {
        .name = ITEM_NAME("THÉIÈRE ÉBRÉCHÉE"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "Un récipient mystérieux\n"
            "pouvant faire évoluer un\n"
            "certain Pokémon. Il est\n"
            "ébréché, mais on y fait du\n"
            "bon thé."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_ChippedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_GALARICA_CUFF] =
    {
        .name = ITEM_NAME("BRACELET GALANOA"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Un bracelet confectionné à\n"
            "partir de Branches Galanoa.\n"
            "Les Ramoloss de Galar\n"
            "adorent en porter."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaCuff,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_GALARICA_WREATH] =
    {
        .name = ITEM_NAME("COURONNE GALANOA"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Une couronne confectionnée\n"
            "à partir de Branches\n"
            "Galanoa. Les Ramoloss de\n"
            "Galar adorent en porter."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaWreath,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = ITEM_NAME("ÉCAILLE DRACO"),
        .price = 20000,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Une écaille épaisse et dure\n"
            "tenue parfois par les\n"
            "Pokémon de type Dragon\n"
            "quand ils sont attrapés."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DragonScale,
        .iconPalette = gItemIconPalette_DragonScale,
    },

    [ITEM_UPGRADE] =
    {
        .name = ITEM_NAME("AMÉLIORATOR"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Un dispositif transparent\n"
            "rempli de données diverses\n"
            "et variées. Fabriqué par la\n"
            "Sylphe SARL."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_Upgrade,
        .iconPalette = gItemIconPalette_Upgrade,
    },

    [ITEM_PROTECTOR] =
    {
        .name = ITEM_NAME("PROTECTEUR"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Objet protecteur\n"
            "très dur et très\n"
            "lourd, apprécié d'un\n"
            "certain Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Protector,
        .iconPalette = gItemIconPalette_Protector,
    },

    [ITEM_ELECTIRIZER] =
    {
        .name = ITEM_NAME("ÉLECTRISEUR"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Une boîte remplie d'une\n"
            "énorme quantité d'énergie\n"
            "électrique. Appréciée d'un\n"
            "certain Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Electirizer,
        .iconPalette = gItemIconPalette_Electirizer,
    },

    [ITEM_MAGMARIZER] =
    {
        .name = ITEM_NAME("MAGMARISEUR"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Une boîte remplie d'une\n"
            "énorme quantité d'énergie\n"
            "magmatique. Appréciée d'un\n"
            "certain Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Magmarizer,
        .iconPalette = gItemIconPalette_Magmarizer,
    },

    [ITEM_DUBIOUS_DISC] =
    {
        .name = ITEM_NAME("CD DOUTEUX"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Appareil transparent rempli\n"
            "de données douteuses. Son\n"
            "fabricant n'est pas connu."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 50,
        .iconPic = gItemIcon_DubiousDisc,
        .iconPalette = gItemIconPalette_DubiousDisc,
    },

    [ITEM_REAPER_CLOTH] =
    {
        .name = ITEM_NAME("TISSU FAUCHE"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Un tissu imprégné d'une\n"
            "énergie spirituelle\n"
            "horriblement puissante.\n"
            "Apprécié d'un certain\n"
            "Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 10,
        .iconPic = gItemIcon_ReaperCloth,
        .iconPalette = gItemIconPalette_ReaperCloth,
    },

    [ITEM_PRISM_SCALE] =
    {
        .name = ITEM_NAME("BEL’ÉCAILLE"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 2000,
    #else
        .price = 20000,
    #endif
        .description = COMPOUND_STRING(
            "Une écaille étrange qui fait\n"
            "évoluer certaines espèces\n"
            "de Pokémon. Elle a une\n"
            "couleur arc-en-ciel."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PrismScale,
        .iconPalette = gItemIconPalette_PrismScale,
    },

    [ITEM_WHIPPED_DREAM] =
    {
        .name = ITEM_NAME("CHANTIBONBON"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Une crème sucrée qui fond\n"
            "dans la bouche, légère comme\n"
            "un nuage. Elle est appréciée\n"
            "d'un certain Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_WhippedDream,
        .iconPalette = gItemIconPalette_WhippedDream,
    },

    [ITEM_SACHET] =
    {
        .name = ITEM_NAME("SACHET SENTEUR"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Un sachet d'herbes et\n"
            "d'épices, au parfum trop\n"
            "marqué pour beaucoup, mais\n"
            "néanmoins apprécié d'un\n"
            "certain Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Sachet,
        .iconPalette = gItemIconPalette_Sachet,
    },

    [ITEM_OVAL_STONE] =
    {
        .name = ITEM_NAME("PIERRE OVALE"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Pierre étrange qui\n"
            "fait évoluer\n"
            "certaines espèces\n"
            "de Pokémon. Elle a\n"
            "la forme d'un œuf."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_OvalStone,
        .iconPalette = gItemIconPalette_OvalStone,
    },

    [ITEM_STRAWBERRY_SWEET] =
    {
        .name = ITEM_NAME("FRAISE EN SUCRE"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un bonbon en forme\n"
            "de fraise. Quand on\n"
            "le donne à un Crèmy,\n"
            "il danse de\n"
            "bonheur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StrawberrySweet,
        .iconPalette = gItemIconPalette_StrawberrySweet,
    },

    [ITEM_LOVE_SWEET] =
    {
        .name = ITEM_NAME("CŒUR EN SUCRE"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un bonbon en forme\n"
            "de cœur. Quand on\n"
            "le donne à un Crèmy,\n"
            "il danse de\n"
            "bonheur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LoveSweet,
        .iconPalette = gItemIconPalette_LoveSweet,
    },

    [ITEM_BERRY_SWEET] =
    {
        .name = ITEM_NAME("BAIE EN SUCRE"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un bonbon en forme\n"
            "de Baie. Quand on le\n"
            "donne à un Crèmy, il\n"
            "danse de bonheur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerrySweet,
        .iconPalette = gItemIconPalette_BerrySweet,
    },

    [ITEM_CLOVER_SWEET] =
    {
        .name = ITEM_NAME("TRÈFLE EN SUCRE"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un bonbon en forme\n"
            "de trèfle. Quand on\n"
            "le donne à un Crèmy,\n"
            "il danse de\n"
            "bonheur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CloverSweet,
        .iconPalette = gItemIconPalette_CloverSweet,
    },

    [ITEM_FLOWER_SWEET] =
    {
        .name = ITEM_NAME("FLEUR EN SUCRE"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un bonbon en forme\n"
            "de fleur. Quand on\n"
            "le donne à un Crèmy,\n"
            "il danse de\n"
            "bonheur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FlowerSweet,
        .iconPalette = gItemIconPalette_FlowerSweet,
    },

    [ITEM_STAR_SWEET] =
    {
        .name = ITEM_NAME("ÉTOILE EN SUCRE"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un bonbon en forme\n"
            "d'étoile. Quand on\n"
            "le donne à un Crèmy,\n"
            "il danse de\n"
            "bonheur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarSweet,
        .iconPalette = gItemIconPalette_StarSweet,
    },

    [ITEM_RIBBON_SWEET] =
    {
        .name = ITEM_NAME("RUBAN EN SUCRE"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Un bonbon en forme\n"
            "de ruban. Quand on\n"
            "le donne à un Crèmy,\n"
            "il danse de\n"
            "bonheur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RibbonSweet,
        .iconPalette = gItemIconPalette_RibbonSweet,
    },

    [ITEM_EVERSTONE] =
    {
        .name = ITEM_NAME("PIERRE STASE"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Pierre merveilleuse\n"
            "empêchant\n"
            "l'évolution."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Everstone,
        .iconPalette = gItemIconPalette_Everstone,
    },

// Nectars

    [ITEM_RED_NECTAR] =
    {
        .name = ITEM_NAME("NECTAR ROUGE"),
        .price = 300,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Un nectar obtenu\n"
            "au Jardin d'Ula-Ula.\n"
            "Permet à un certain\n"
            "Pokémon de changer\n"
            "d'apparence."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_RedNectar,
    },

    [ITEM_YELLOW_NECTAR] =
    {
        .name = ITEM_NAME("NECTAR JAUNE"),
        .price = 300,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Un nectar obtenu au Jardin\n"
            "de Mele-Mele. Permet à un\n"
            "certain Pokémon de changer\n"
            "d'apparence."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_YellowNectar,
    },

    [ITEM_PINK_NECTAR] =
    {
        .name = ITEM_NAME("NECTAR ROSE"),
        .price = 300,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Un nectar obtenu à partir\n"
            "des fleurs de la Rue du Dôme\n"
            "Royal. Permet à un certain\n"
            "Pokémon de changer\n"
            "d'apparence."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PinkNectar,
    },

    [ITEM_PURPLE_NECTAR] =
    {
        .name = ITEM_NAME("NECTAR MAUVE"),
        .price = 300,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Un nectar obtenu\n"
            "au Jardin de Poni.\n"
            "Permet à un certain\n"
            "Pokémon de changer\n"
            "d'apparence."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PurpleNectar,
    },

// Plates

    [ITEM_FLAME_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE FLAMME"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Feu."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FlamePlate,
    },

    [ITEM_SPLASH_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE HYDRO"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SplashPlate,
    },

    [ITEM_ZAP_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE VOLT"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Électrik."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ZapPlate,
    },

    [ITEM_MEADOW_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE HERBE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Plante."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MeadowPlate,
    },

    [ITEM_ICICLE_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE GLACE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Glace."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IciclePlate,
    },

    [ITEM_FIST_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE POING"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FistPlate,
    },

    [ITEM_TOXIC_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE TOXICITÉ"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Poison."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ToxicPlate,
    },

    [ITEM_EARTH_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE TERRE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Sol."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_EarthPlate,
    },

    [ITEM_SKY_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE CIEL"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Vol."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SkyPlate,
    },

    [ITEM_MIND_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE ESPRIT"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Psy."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MindPlate,
    },

    [ITEM_INSECT_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE INSECTE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Insecte."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_InsectPlate,
    },

    [ITEM_STONE_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE ROC"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Roche."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_StonePlate,
    },

    [ITEM_SPOOKY_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE FANTÔME"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Spectre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SpookyPlate,
    },

    [ITEM_DRACO_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE DRACO"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Dragon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DracoPlate,
    },

    [ITEM_DREAD_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE OMBRE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Ténèbres."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DreadPlate,
    },

    [ITEM_IRON_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE FER"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Tablette en\n"
            "pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Acier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IronPlate,
    },

    [ITEM_PIXIE_PLATE] =
    {
        .name = ITEM_NAME("PLAQUE PIXIE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Une tablette\n"
            "en pierre augmentant la\n"
            "puissance des capacités de\n"
            "type Fée."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_PixiePlate,
    },

// Drives

    [ITEM_DOUSE_DRIVE] =
    {
        .name = ITEM_NAME("MODULE AQUA"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Tenu par Genesect, ce\n"
            "module change la capacité\n"
            "TechnoBuster en une\n"
            "capacité de type Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_DouseDrive,
    },

    [ITEM_SHOCK_DRIVE] =
    {
        .name = ITEM_NAME("MODULE CHOC"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Tenu par Genesect, ce\n"
            "module change la capacité\n"
            "TechnoBuster en une\n"
            "capacité de type Électrik."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ShockDrive,
    },

    [ITEM_BURN_DRIVE] =
    {
        .name = ITEM_NAME("MODULE PYRO"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Tenu par Genesect, ce\n"
            "module change la capacité\n"
            "TechnoBuster en une\n"
            "capacité de type Feu."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_BurnDrive,
    },

    [ITEM_CHILL_DRIVE] =
    {
        .name = ITEM_NAME("MODULE CRYO"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Tenu par Genesect, ce\n"
            "module change la capacité\n"
            "TechnoBuster en une\n"
            "capacité de type Glace."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ChillDrive,
    },

// Memories

    [ITEM_FIRE_MEMORY] =
    {
        .name = ITEM_NAME("ROM FEU"),
        .pluralName = ITEM_PLURAL_NAME("ROM FEU"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Feu. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 50,
        .iconPic = gItemIcon_FireMemory,
        .iconPalette = gItemIconPalette_FireMemory,
    },

    [ITEM_WATER_MEMORY] =
    {
        .name = ITEM_NAME("ROM EAU"),
        .pluralName = ITEM_PLURAL_NAME("ROM EAU"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Eau. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 50,
        .iconPic = gItemIcon_WaterMemory,
        .iconPalette = gItemIconPalette_WaterMemory,
    },

    [ITEM_ELECTRIC_MEMORY] =
    {
        .name = ITEM_NAME("ROM ÉLECTRIK"),
        .pluralName = ITEM_PLURAL_NAME("ROM ÉLECTRIK"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Électrik. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 50,
        .iconPic = gItemIcon_ElectricMemory,
        .iconPalette = gItemIconPalette_ElectricMemory,
    },

    [ITEM_GRASS_MEMORY] =
    {
        .name = ITEM_NAME("ROM PLANTE"),
        .pluralName = ITEM_PLURAL_NAME("ROM PLANTE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Plante. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 50,
        .iconPic = gItemIcon_GrassMemory,
        .iconPalette = gItemIconPalette_GrassMemory,
    },

    [ITEM_ICE_MEMORY] =
    {
        .name = ITEM_NAME("ROM GLACE"),
        .pluralName = ITEM_PLURAL_NAME("ROM GLACE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Glace. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 50,
        .iconPic = gItemIcon_IceMemory,
        .iconPalette = gItemIconPalette_IceMemory,
    },

    [ITEM_FIGHTING_MEMORY] =
    {
        .name = ITEM_NAME("ROM COMBAT"),
        .pluralName = ITEM_PLURAL_NAME("ROM COMBAT"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Combat. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 50,
        .iconPic = gItemIcon_FightingMemory,
        .iconPalette = gItemIconPalette_FightingMemory,
    },

    [ITEM_POISON_MEMORY] =
    {
        .name = ITEM_NAME("ROM POISON"),
        .pluralName = ITEM_PLURAL_NAME("ROM POISON"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Poison. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 50,
        .iconPic = gItemIcon_PoisonMemory,
        .iconPalette = gItemIconPalette_PoisonMemory,
    },

    [ITEM_GROUND_MEMORY] =
    {
        .name = ITEM_NAME("ROM SOL"),
        .pluralName = ITEM_PLURAL_NAME("ROM SOL"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Sol. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 50,
        .iconPic = gItemIcon_GroundMemory,
        .iconPalette = gItemIconPalette_GroundMemory,
    },

    [ITEM_FLYING_MEMORY] =
    {
        .name = ITEM_NAME("ROM VOL"),
        .pluralName = ITEM_PLURAL_NAME("ROM VOL"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Vol. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_FlyingMemory,
        .iconPalette = gItemIconPalette_FlyingMemory,
    },

    [ITEM_PSYCHIC_MEMORY] =
    {
        .name = ITEM_NAME("ROM PSY"),
        .pluralName = ITEM_PLURAL_NAME("ROM PSY"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Psy. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 50,
        .iconPic = gItemIcon_PsychicMemory,
        .iconPalette = gItemIconPalette_PsychicMemory,
    },

    [ITEM_BUG_MEMORY] =
    {
        .name = ITEM_NAME("ROM INSECTE"),
        .pluralName = ITEM_PLURAL_NAME("ROM INSECTE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Insecte. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 50,
        .iconPic = gItemIcon_BugMemory,
        .iconPalette = gItemIconPalette_BugMemory,
    },

    [ITEM_ROCK_MEMORY] =
    {
        .name = ITEM_NAME("ROM ROCHE"),
        .pluralName = ITEM_PLURAL_NAME("ROM ROCHE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Roche. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 50,
        .iconPic = gItemIcon_RockMemory,
        .iconPalette = gItemIconPalette_RockMemory,
    },

    [ITEM_GHOST_MEMORY] =
    {
        .name = ITEM_NAME("ROM SPECTRE"),
        .pluralName = ITEM_PLURAL_NAME("ROM SPECTRE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Spectre. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 50,
        .iconPic = gItemIcon_GhostMemory,
        .iconPalette = gItemIconPalette_GhostMemory,
    },

    [ITEM_DRAGON_MEMORY] =
    {
        .name = ITEM_NAME("ROM DRAGON"),
        .pluralName = ITEM_PLURAL_NAME("ROM DRAGON"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Dragon. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 50,
        .iconPic = gItemIcon_DragonMemory,
        .iconPalette = gItemIconPalette_DragonMemory,
    },

    [ITEM_DARK_MEMORY] =
    {
        .name = ITEM_NAME("ROM TÉNÈBRES"),
        .pluralName = ITEM_PLURAL_NAME("ROM TÉNÈBRES"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Ténèbres. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 50,
        .iconPic = gItemIcon_DarkMemory,
        .iconPalette = gItemIconPalette_DarkMemory,
    },

    [ITEM_STEEL_MEMORY] =
    {
        .name = ITEM_NAME("ROM ACIER"),
        .pluralName = ITEM_PLURAL_NAME("ROM ACIER"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Acier. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 50,
        .iconPic = gItemIcon_SteelMemory,
        .iconPalette = gItemIconPalette_SteelMemory,
    },

    [ITEM_FAIRY_MEMORY] =
    {
        .name = ITEM_NAME("ROM FÉE"),
        .pluralName = ITEM_PLURAL_NAME("ROM FÉE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Une carte mémoire\n"
            "contenant des données sur\n"
            "le type Fée. Un certain\n"
            "Pokémon peut changer de\n"
            "type en l'équipant."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 50,
        .iconPic = gItemIcon_FairyMemory,
        .iconPalette = gItemIconPalette_FairyMemory,
    },

    [ITEM_RUSTED_SWORD] =
    {
        .name = ITEM_NAME("ÉPÉE ROUILLÉE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "On raconte que cette épée\n"
            "fut jadis utilisée par un\n"
            "héros pour vaincre une\n"
            "calamité. À présent, elle est\n"
            "toute usée et rouillée."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedSword,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

    [ITEM_RUSTED_SHIELD] =
    {
        .name = ITEM_NAME("BOUCLIER ROUILLÉ"),
        .price = 0,
        .description = COMPOUND_STRING(
            "On raconte que ce bouclier\n"
            "fut jadis utilisé par un\n"
            "héros pour vaincre une\n"
            "calamité. À présent, il est\n"
            "tout usé et rouillé."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedShield,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

// Colored Orbs

    [ITEM_RED_ORB] =
    {
        .name = ITEM_NAME("GEMME ROUGE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "Un orbe incarnat\n"
            "dont on dit qu'il a\n"
            "un lien très étroit\n"
            "avec les légendes\n"
            "de Hoenn."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RedOrb,
        .iconPalette = gItemIconPalette_RedOrb,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = ITEM_NAME("GEMME BLEUE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "Un orbe céruléen\n"
            "dont on dit qu'il a\n"
            "un lien très étroit\n"
            "avec les légendes\n"
            "de Hoenn."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BlueOrb,
        .iconPalette = gItemIconPalette_BlueOrb,
    },

// Mega Stones

    [ITEM_VENUSAURITE] =
    {
        .name = ITEM_NAME("FLORIZARRITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Florizarre\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Venusaurite,
        .iconPalette = gItemIconPalette_Venusaurite,
    },

    [ITEM_CHARIZARDITE_X] =
    {
        .name = ITEM_NAME("DRACAUFITE X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Dracaufeu\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeX,
        .iconPalette = gItemIconPalette_CharizarditeX,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
        .name = ITEM_NAME("DRACAUFITE Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Dracaufeu\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeY,
        .iconPalette = gItemIconPalette_CharizarditeY,
    },

    [ITEM_BLASTOISINITE] =
    {
        .name = ITEM_NAME("TORTANKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Tortank de\n"
            "méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blastoisinite,
        .iconPalette = gItemIconPalette_Blastoisinite,
    },

    [ITEM_BEEDRILLITE] =
    {
        .name = ITEM_NAME("DARDARGNITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Dardargnan\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Beedrillite,
        .iconPalette = gItemIconPalette_Beedrillite,
    },

    [ITEM_PIDGEOTITE] =
    {
        .name = ITEM_NAME("ROUCARNAGITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Roucarnage\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pidgeotite,
        .iconPalette = gItemIconPalette_Pidgeotite,
    },

    [ITEM_ALAKAZITE] =
    {
        .name = ITEM_NAME("ALAKAZAMITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Alakazam de\n"
            "méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Alakazite,
        .iconPalette = gItemIconPalette_Alakazite,
    },

    [ITEM_SLOWBRONITE] =
    {
        .name = ITEM_NAME("FLAGADOSSITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Flagadoss\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Slowbronite,
        .iconPalette = gItemIconPalette_Slowbronite,
    },

    [ITEM_GENGARITE] =
    {
        .name = ITEM_NAME("ECTOPLASMITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Ectoplasma\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gengarite,
        .iconPalette = gItemIconPalette_Gengarite,
    },

    [ITEM_KANGASKHANITE] =
    {
        .name = ITEM_NAME("KANGOUREXITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Kangourex\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Kangaskhanite,
        .iconPalette = gItemIconPalette_Kangaskhanite,
    },

    [ITEM_PINSIRITE] =
    {
        .name = ITEM_NAME("SCARABRUITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Scarabrute\n"
            "de méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pinsirite,
        .iconPalette = gItemIconPalette_Pinsirite,
    },

    [ITEM_GYARADOSITE] =
    {
        .name = ITEM_NAME("LÉVIATORITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Elle permet à un Léviator de\n"
            "méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gyaradosite,
        .iconPalette = gItemIconPalette_Gyaradosite,
    },

    [ITEM_AERODACTYLITE] =
    {
        .name = ITEM_NAME("PTÉRAÏTE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de\n"
            "Méga-Gemme. Elle\n"
            "permet à un Ptéra\n"
            "de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aerodactylite,
        .iconPalette = gItemIconPalette_Aerodactylite,
    },

    [ITEM_MEWTWONITE_X] =
    {
        .name = ITEM_NAME("MEWTWOÏTE X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de\n"
            "Méga-Gemme. Elle\n"
            "permet à un Mewtwo\n"
            "de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteX,
        .iconPalette = gItemIconPalette_MewtwoniteX,
    },

    [ITEM_MEWTWONITE_Y] =
    {
        .name = ITEM_NAME("MEWTWOÏTE Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de\n"
            "Méga-Gemme. Elle\n"
            "permet à un Mewtwo\n"
            "de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteY,
        .iconPalette = gItemIconPalette_MewtwoniteY,
    },

    [ITEM_AMPHAROSITE] =
    {
        .name = ITEM_NAME("PHARAMPITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Pharamp, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Ampharosite,
        .iconPalette = gItemIconPalette_Ampharosite,
    },

    [ITEM_STEELIXITE] =
    {
        .name = ITEM_NAME("STEELIXITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Steelix, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Steelixite,
        .iconPalette = gItemIconPalette_Steelixite,
    },

    [ITEM_SCIZORITE] =
    {
        .name = ITEM_NAME("CIZAYOXITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Cizayox, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scizorite,
        .iconPalette = gItemIconPalette_Scizorite,
    },

    [ITEM_HERACRONITE] =
    {
        .name = ITEM_NAME("SCARHINOÏTE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Scarhino, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heracronite,
        .iconPalette = gItemIconPalette_Heracronite,
    },

    [ITEM_HOUNDOOMINITE] =
    {
        .name = ITEM_NAME("DÉMOLOSSITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Démolosse, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Houndoominite,
        .iconPalette = gItemIconPalette_Houndoominite,
    },

    [ITEM_TYRANITARITE] =
    {
        .name = ITEM_NAME("TYRANOCIVITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Tyranocif, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tyranitarite,
        .iconPalette = gItemIconPalette_Tyranitarite,
    },

    [ITEM_SCEPTILITE] =
    {
        .name = ITEM_NAME("JUNGKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Jungko, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sceptilite,
        .iconPalette = gItemIconPalette_Sceptilite,
    },

    [ITEM_BLAZIKENITE] =
    {
        .name = ITEM_NAME("BRASÉGALITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Braségali, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blazikenite,
        .iconPalette = gItemIconPalette_Blazikenite,
    },

    [ITEM_SWAMPERTITE] =
    {
        .name = ITEM_NAME("LAGGRONITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Laggron, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Swampertite,
        .iconPalette = gItemIconPalette_Swampertite,
    },

    [ITEM_GARDEVOIRITE] =
    {
        .name = ITEM_NAME("GARDEVOIRITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Gardevoir, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gardevoirite,
        .iconPalette = gItemIconPalette_Gardevoirite,
    },

    [ITEM_SABLENITE] =
    {
        .name = ITEM_NAME("TÉNÉFIXITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Ténéfix, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sablenite,
        .iconPalette = gItemIconPalette_Sablenite,
    },

    [ITEM_MAWILITE] =
    {
        .name = ITEM_NAME("MYSDIBULITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Mysdibule, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Mawilite,
        .iconPalette = gItemIconPalette_Mawilite,
    },

    [ITEM_AGGRONITE] =
    {
        .name = ITEM_NAME("GALEKINGITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Galeking, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aggronite,
        .iconPalette = gItemIconPalette_Aggronite,
    },

    [ITEM_MEDICHAMITE] =
    {
        .name = ITEM_NAME("CHARMINITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Charmina, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Medichamite,
        .iconPalette = gItemIconPalette_Medichamite,
    },

    [ITEM_MANECTITE] =
    {
        .name = ITEM_NAME("ÉLECSPRINTITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Élecsprint, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Manectite,
        .iconPalette = gItemIconPalette_Manectite,
    },

    [ITEM_SHARPEDONITE] =
    {
        .name = ITEM_NAME("SHARPEDITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Sharpedo, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sharpedonite,
        .iconPalette = gItemIconPalette_Sharpedonite,
    },

    [ITEM_CAMERUPTITE] =
    {
        .name = ITEM_NAME("CAMÉRUPTITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Camérupt, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Cameruptite,
        .iconPalette = gItemIconPalette_Cameruptite,
    },

    [ITEM_ALTARIANITE] =
    {
        .name = ITEM_NAME("ALTARITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Altaria, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Altarianite,
        .iconPalette = gItemIconPalette_Altarianite,
    },

    [ITEM_BANETTITE] =
    {
        .name = ITEM_NAME("BRANETTITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Branette, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Banettite,
        .iconPalette = gItemIconPalette_Banettite,
    },

    [ITEM_ABSOLITE] =
    {
        .name = ITEM_NAME("ABSOLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Absol, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Absolite,
        .iconPalette = gItemIconPalette_Absolite,
    },

    [ITEM_GLALITITE] =
    {
        .name = ITEM_NAME("ONIGLALITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Oniglali, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glalitite,
        .iconPalette = gItemIconPalette_Glalitite,
    },

    [ITEM_SALAMENCITE] =
    {
        .name = ITEM_NAME("DRATTAKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Drattak, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Salamencite,
        .iconPalette = gItemIconPalette_Salamencite,
    },

    [ITEM_METAGROSSITE] =
    {
        .name = ITEM_NAME("MÉTALOSSITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Métalosse, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Metagrossite,
        .iconPalette = gItemIconPalette_Metagrossite,
    },

    [ITEM_LATIASITE] =
    {
        .name = ITEM_NAME("LATIASITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par Latias, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiasite,
        .iconPalette = gItemIconPalette_Latiasite,
    },

    [ITEM_LATIOSITE] =
    {
        .name = ITEM_NAME("LATIOSITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par Latios, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiosite,
        .iconPalette = gItemIconPalette_Latiosite,
    },

    [ITEM_LOPUNNITE] =
    {
        .name = ITEM_NAME("LOCKPINITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Lockpin, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lopunnite,
        .iconPalette = gItemIconPalette_Lopunnite,
    },

    [ITEM_GARCHOMPITE] =
    {
        .name = ITEM_NAME("CARCHACROKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Carchacrok,\n"
            "elle lui permet de\n"
            "méga-évoluer durant un\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Garchompite,
        .iconPalette = gItemIconPalette_Garchompite,
    },

    [ITEM_LUCARIONITE] =
    {
        .name = ITEM_NAME("LUCARITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Lucario, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lucarionite,
        .iconPalette = gItemIconPalette_Lucarionite,
    },

    [ITEM_ABOMASITE] =
    {
        .name = ITEM_NAME("BLIZZARITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Blizzaroi, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Abomasite,
        .iconPalette = gItemIconPalette_Abomasite,
    },

    [ITEM_GALLADITE] =
    {
        .name = ITEM_NAME("GALLAMITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Gallame, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Galladite,
        .iconPalette = gItemIconPalette_Galladite,
    },

    [ITEM_AUDINITE] =
    {
        .name = ITEM_NAME("NANMÉOUÏTE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Nanméouïe, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Audinite,
        .iconPalette = gItemIconPalette_Audinite,
    },

    [ITEM_DIANCITE] =
    {
        .name = ITEM_NAME("DIANCITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Diancie, elle lui\n"
            "permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Diancite,
        .iconPalette = gItemIconPalette_Diancite,
    },

    [ITEM_CLEFABLITE] =
    {
        .name = ITEM_NAME("MÉLODELFITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Clefablite,
        .iconPalette = gItemIconPalette_Clefablite,
    },

    [ITEM_VICTREEBELITE] =
    {
        .name = ITEM_NAME("EMPIFLORITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Victreebelite,
        .iconPalette = gItemIconPalette_Victreebelite,
    },

    [ITEM_STARMINITE] =
    {
        .name = ITEM_NAME("STAROSSITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Starminite,
        .iconPalette = gItemIconPalette_Starminite,
    },

    [ITEM_DRAGONINITE] =
    {
        .name = ITEM_NAME("DRACOLOSSITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragoninite,
        .iconPalette = gItemIconPalette_Dragoninite,
    },

    [ITEM_MEGANIUMITE] =
    {
        .name = ITEM_NAME("MÉGANIUMITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un mochi contenant\n"
            "des Baies qui\n"
            "réinitialise tous\n"
            "les points de base\n"
            "d'un Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meganiumite,
        .iconPalette = gItemIconPalette_Meganiumite,
    },

    [ITEM_FERALIGITE] =
    {
        .name = ITEM_NAME("ALIGATUEURITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une perche compatible avec\n"
            "les Motismart. Elle permet de\n"
            "se photographier d'un peu\n"
            "plus loin lorsqu'on prend des\n"
            "selfies."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Feraligite,
        .iconPalette = gItemIconPalette_Feraligite,
    },

    [ITEM_SKARMORITE] =
    {
        .name = ITEM_NAME("AIRMURITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un mystérieux charme\n"
            "éclatant qui permet\n"
            "d'obtenir davantage de\n"
            "Téra-Éclats lors des raids\n"
            "Téracristal."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Skarmorite,
        .iconPalette = gItemIconPalette_Skarmorite,
    },

    [ITEM_FROSLASSITE] =
    {
        .name = ITEM_NAME("MOMARTIKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un morceau de métal étrange\n"
            "qui permet de faire évoluer\n"
            "une certaine espèce de\n"
            "Pokémon. Il est composé de\n"
            "plusieurs couches."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Froslassite,
        .iconPalette = gItemIconPalette_Froslassite,
    },

    [ITEM_EMBOARITE] =
    {
        .name = ITEM_NAME("ROITIFLAMITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Emboarite,
        .iconPalette = gItemIconPalette_Emboarite,
    },

    [ITEM_EXCADRITE] =
    {
        .name = ITEM_NAME("MINOTAUPITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Excadrite,
        .iconPalette = gItemIconPalette_Excadrite,
    },

    [ITEM_SCOLIPITE] =
    {
        .name = ITEM_NAME("BRUTAPODITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scolipite,
        .iconPalette = gItemIconPalette_Scolipite,
    },

    [ITEM_SCRAFTINITE] =
    {
        .name = ITEM_NAME("BAGGAÏDITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scraftinite,
        .iconPalette = gItemIconPalette_Scraftinite,
    },

    [ITEM_EELEKTROSSITE] =
    {
        .name = ITEM_NAME("OHMASSACRITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Eelektrossite,
        .iconPalette = gItemIconPalette_Eelektrossite,
    },

    [ITEM_CHANDELURITE] =
    {
        .name = ITEM_NAME("LUGULABRITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chandelurite,
        .iconPalette = gItemIconPalette_Chandelurite,
    },

    [ITEM_CHESNAUGHTITE] =
    {
        .name = ITEM_NAME("BLINDÉPIQUITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chesnaughtite,
        .iconPalette = gItemIconPalette_Chesnaughtite,
    },

    [ITEM_DELPHOXITE] =
    {
        .name = ITEM_NAME("GOUPELINITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Delphoxite,
        .iconPalette = gItemIconPalette_Delphoxite,
    },

    [ITEM_GRENINJITE] =
    {
        .name = ITEM_NAME("AMPHINOLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Greninjite,
        .iconPalette = gItemIconPalette_Greninjite,
    },

    [ITEM_PYROARITE] =
    {
        .name = ITEM_NAME("NÉMÉLIOSITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pyroarite,
        .iconPalette = gItemIconPalette_Pyroarite,
    },

    [ITEM_FLOETTITE] =
    {
        .name = ITEM_NAME("FLOETTITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Floettite,
        .iconPalette = gItemIconPalette_Floettite,
    },

    [ITEM_MALAMARITE] =
    {
        .name = ITEM_NAME("SEPIATROCITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Malamarite,
        .iconPalette = gItemIconPalette_Malamarite,
    },

    [ITEM_BARBARACITE] =
    {
        .name = ITEM_NAME("GOLGOPATHITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Barbaracite,
        .iconPalette = gItemIconPalette_Barbaracite,
    },

    [ITEM_DRAGALGITE] =
    {
        .name = ITEM_NAME("KRAVAREKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragalgite,
        .iconPalette = gItemIconPalette_Dragalgite,
    },

    [ITEM_HAWLUCHANITE] =
    {
        .name = ITEM_NAME("BRUTALIBRITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Hawluchanite,
        .iconPalette = gItemIconPalette_Hawluchanite,
    },

    [ITEM_ZYGARDITE] =
    {
        .name = ITEM_NAME("ZYGARDITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zygardite,
        .iconPalette = gItemIconPalette_Zygardite,
    },

    [ITEM_DRAMPANITE] =
    {
        .name = ITEM_NAME("DRAÏEULITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Drampanite,
        .iconPalette = gItemIconPalette_Drampanite,
    },

    [ITEM_FALINKSITE] =
    {
        .name = ITEM_NAME("HEXADRONITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Falinksite,
        .iconPalette = gItemIconPalette_Falinksite,
    },

    [ITEM_HEATRANITE] =
    {
        .name = ITEM_NAME("HEATRANITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de\n"
            "Méga-Gemme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heatranite,
        .iconPalette = gItemIconPalette_Heatranite,
    },

    [ITEM_DARKRANITE] =
    {
        .name = ITEM_NAME("DARKRAÏTE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Darkranite,
        .iconPalette = gItemIconPalette_Darkranite,
    },

    [ITEM_ZERAORITE] =
    {
        .name = ITEM_NAME("ZERAORITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zeraorite,
        .iconPalette = gItemIconPalette_Zeraorite,
    },

    [ITEM_RAICHUNITE_X] =
    {
        .name = ITEM_NAME("RAICHUÏTE X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une friandise préparée avec\n"
            "les ingrédients favoris du\n"
            "Pokémon légendaire Blizzeval."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteX,
        .iconPalette = gItemIconPalette_RaichuniteX,
    },

    [ITEM_RAICHUNITE_Y] =
    {
        .name = ITEM_NAME("RAICHUÏTE Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une friandise préparée avec\n"
            "les ingrédients favoris du\n"
            "Pokémon légendaire\n"
            "Spectreval."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteY,
        .iconPalette = gItemIconPalette_RaichuniteY,
    },

    [ITEM_CHIMECHITE] =
    {
        .name = ITEM_NAME("ÉOKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un disque mystérieux aux\n"
            "beaux reflets indigo que la\n"
            "Maîtresse en Chef vous a\n"
            "confié. Il semble avoir un\n"
            "lien avec la Zone Zéro."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chimechite,
        .iconPalette = gItemIconPalette_Chimechite,
    },

    [ITEM_ABSOLITE_Z] =
    {
        .name = ITEM_NAME("ABSOLITE Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une pique ornée d'un\n"
            "Maganon. Plantée dans un\n"
            "Sandwich, elle le rend tout\n"
            "chaud comme s'il venait\n"
            "d'être préparé."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AbsoliteZ,
        .iconPalette = gItemIconPalette_AbsoliteZ,
    },

    [ITEM_STARAPTITE] =
    {
        .name = ITEM_NAME("ÉTOURAPTORITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un fragment cristallisé qui\n"
            "se forme rarement lors de\n"
            "l'éclatement d'un Joyau\n"
            "Téracristal après qu'un\n"
            "Pokémon Téracristal a été\n"
            "mis K.O."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Staraptite,
        .iconPalette = gItemIconPalette_Staraptite,
    },

    [ITEM_GARCHOMPITE_Z] =
    {
        .name = ITEM_NAME("CARCHACROKITE Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Une variété de Méga-Gemme."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_GarchompiteZ,
        .iconPalette = gItemIconPalette_GarchompiteZ,
    },

    [ITEM_LUCARIONITE_Z] =
    {
        .name = ITEM_NAME("LUCARITE Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING("Une variété de Méga-Gemme."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_LucarioniteZ,
        .iconPalette = gItemIconPalette_LucarioniteZ,
    },

    [ITEM_GOLURKITE] =
    {
        .name = ITEM_NAME("GOLEMASTOKITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Des sièges parfaits pour les\n"
            "pique-niques. Leur design\n"
            "est inspiré de la Nappe\n"
            "Myrtille."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golurkite,
        .iconPalette = gItemIconPalette_Golurkite,
    },

    [ITEM_MEOWSTICITE] =
    {
        .name = ITEM_NAME("MISTIGRIXITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de\n"
            "Méga-Gemme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meowsticite,
        .iconPalette = gItemIconPalette_Meowsticite,
    },

    [ITEM_CRABOMINITE] =
    {
        .name = ITEM_NAME("CRABOMINABLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une pierre venue de\n"
            "l'espace, qui permet à un\n"
            "certain Pokémon de changer\n"
            "d'apparence. Elle est\n"
            "légèrement tiède au\n"
            "toucher."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Crabominite,
        .iconPalette = gItemIconPalette_Crabominite,
    },

    [ITEM_GOLISOPITE] =
    {
        .name = ITEM_NAME("SARMURAÏTE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un récit d'exploration du\n"
            "Cratère de Paldea que la\n"
            "Professeure Olim vous a\n"
            "donné. Son nom y est inscrit\n"
            "d'une écriture maladroite."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golisopite,
        .iconPalette = gItemIconPalette_Golisopite,
    },

    [ITEM_MAGEARNITE] =
    {
        .name = ITEM_NAME("MAGEARNITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Un récit d'exploration du\n"
            "Cratère de Paldea que le\n"
            "Professeur Turum vous a\n"
            "donné. Son nom y est inscrit\n"
            "d'une écriture maladroite."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Magearnite,
        .iconPalette = gItemIconPalette_Magearnite,
    },

    [ITEM_SCOVILLAINITE] =
    {
        .name = ITEM_NAME("SCOVILAINITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de\n"
            "Méga-Gemme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scovillainite,
        .iconPalette = gItemIconPalette_Scovillainite,
    },

    [ITEM_BAXCALIBRITE] =
    {
        .name = ITEM_NAME("GLAIVODITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Donnez cette étrange\n"
            "graine à une certaine\n"
            "personne pour changer les\n"
            "capacités de vos Pokémon en\n"
            "capacités Plus."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Baxcalibrite,
        .iconPalette = gItemIconPalette_Baxcalibrite,
    },

    [ITEM_TATSUGIRINITE] =
    {
        .name = ITEM_NAME("NIGIRIGONITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Mélodelfe, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tatsugirinite,
        .iconPalette = gItemIconPalette_Tatsugirinite,
    },

    [ITEM_GLIMMORANITE] =
    {
        .name = ITEM_NAME("FLORÉCLATITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Une variété de Méga-Gemme.\n"
            "Tenue par un Empiflor, elle\n"
            "lui permet de méga-évoluer\n"
            "durant un combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glimmoranite,
        .iconPalette = gItemIconPalette_Glimmoranite,
    },

// GB Player
    [ITEM_GB_PLAYER] =
    {
        .name = ITEM_NAME("LECTEUR GB"),
        .price = 0,
        .description = COMPOUND_STRING("Un appareil jouant\nles musiques des\nanciens jeux POKéMON."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_GBPlayer,
        .importance = 1,
        .iconPic = gItemIcon_GBPlayer,
        .iconPalette = gItemIconPalette_GBPlayer,
    },

// Gems
    #if I_PRICE >= GEN_9
        #define GEM_PRICE 15000
    #elif I_PRICE >= GEN_7
        #define GEM_PRICE 4000
    #else
        #define GEM_PRICE 200
    #endif

    [ITEM_NORMAL_GEM] =
    {
        .name = ITEM_NAME("JOYAU NORMAL"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Normal."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_NormalGem,
    },

    [ITEM_FIRE_GEM] =
    {
        .name = ITEM_NAME("JOYAU FEU"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Feu."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FireGem,
    },

    [ITEM_WATER_GEM] =
    {
        .name = ITEM_NAME("JOYAU EAU"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_WaterGem,
    },

    [ITEM_ELECTRIC_GEM] =
    {
        .name = ITEM_NAME("JOYAU ÉLECTRIK"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Électrik."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_ElectricGem,
    },

    [ITEM_GRASS_GEM] =
    {
        .name = ITEM_NAME("JOYAU PLANTE"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Plante."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GrassGem,
    },

    [ITEM_ICE_GEM] =
    {
        .name = ITEM_NAME("JOYAU GLACE"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Glace."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_IceGem,
    },

    [ITEM_FIGHTING_GEM] =
    {
        .name = ITEM_NAME("JOYAU COMBAT"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FightingGem,
    },

    [ITEM_POISON_GEM] =
    {
        .name = ITEM_NAME("JOYAU POISON"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Poison."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PoisonGem,
    },

    [ITEM_GROUND_GEM] =
    {
        .name = ITEM_NAME("JOYAU SOL"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Sol."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GroundGem,
    },

    [ITEM_FLYING_GEM] =
    {
        .name = ITEM_NAME("JOYAU VOL"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Vol."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FlyingGem,
    },

    [ITEM_PSYCHIC_GEM] =
    {
        .name = ITEM_NAME("JOYAU PSY"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Psy."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PsychicGem,
    },

    [ITEM_BUG_GEM] =
    {
        .name = ITEM_NAME("JOYAU INSECTE"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Insecte."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_BugGem,
    },

    [ITEM_ROCK_GEM] =
    {
        .name = ITEM_NAME("JOYAU ROCHE"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Roche."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_RockGem,
    },

    [ITEM_GHOST_GEM] =
    {
        .name = ITEM_NAME("JOYAU SPECTRE"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Spectre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GhostGem,
    },

    [ITEM_DRAGON_GEM] =
    {
        .name = ITEM_NAME("JOYAU DRAGON"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Dragon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DragonGem,
    },

    [ITEM_DARK_GEM] =
    {
        .name = ITEM_NAME("JOYAU TÉNÈBRES"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Ténèbres."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DarkGem,
    },

    [ITEM_STEEL_GEM] =
    {
        .name = ITEM_NAME("JOYAU ACIER"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Acier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_SteelGem,
    },

    [ITEM_FAIRY_GEM] =
    {
        .name = ITEM_NAME("JOYAU FÉE"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Un joyau\n"
            "augmentant une fois la\n"
            "puissance des capacités de\n"
            "type Fée."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FairyGem,
    },

// Z-Crystals

    [ITEM_NORMALIUM_Z] =
    {
        .name = ITEM_NAME("NORMAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Normal en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_NormaliumZ,
        .iconPalette = gItemIconPalette_NormaliumZ,
    },

    [ITEM_FIRIUM_Z] =
    {
        .name = ITEM_NAME("PYROZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Feu en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_FiriumZ,
        .iconPalette = gItemIconPalette_FiriumZ,
    },

    [ITEM_WATERIUM_Z] =
    {
        .name = ITEM_NAME("AQUAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Eau en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_WateriumZ,
        .iconPalette = gItemIconPalette_WateriumZ,
    },

    [ITEM_ELECTRIUM_Z] =
    {
        .name = ITEM_NAME("VOLTAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Électrik en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_ElectriumZ,
        .iconPalette = gItemIconPalette_ElectriumZ,
    },

    [ITEM_GRASSIUM_Z] =
    {
        .name = ITEM_NAME("FLORAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Plante en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_GrassiumZ,
        .iconPalette = gItemIconPalette_GrassiumZ,
    },

    [ITEM_ICIUM_Z] =
    {
        .name = ITEM_NAME("CRYOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Glace en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_IciumZ,
        .iconPalette = gItemIconPalette_IciumZ,
    },

    [ITEM_FIGHTINIUM_Z] =
    {
        .name = ITEM_NAME("COMBAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Combat en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_FightiniumZ,
        .iconPalette = gItemIconPalette_FightiniumZ,
    },

    [ITEM_POISONIUM_Z] =
    {
        .name = ITEM_NAME("TOXIZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Poison en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_PoisoniumZ,
        .iconPalette = gItemIconPalette_PoisoniumZ,
    },

    [ITEM_GROUNDIUM_Z] =
    {
        .name = ITEM_NAME("TERRAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Sol en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_GroundiumZ,
        .iconPalette = gItemIconPalette_GroundiumZ,
    },

    [ITEM_FLYINIUM_Z] =
    {
        .name = ITEM_NAME("AÉROZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Vol en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_FlyiniumZ,
        .iconPalette = gItemIconPalette_FlyiniumZ,
    },

    [ITEM_PSYCHIUM_Z] =
    {
        .name = ITEM_NAME("PSYCHÉZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Psy en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_PsychiumZ,
        .iconPalette = gItemIconPalette_PsychiumZ,
    },

    [ITEM_BUGINIUM_Z] =
    {
        .name = ITEM_NAME("INSECTOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Insecte en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_BuginiumZ,
        .iconPalette = gItemIconPalette_BuginiumZ,
    },

    [ITEM_ROCKIUM_Z] =
    {
        .name = ITEM_NAME("ROCAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Roche en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_RockiumZ,
        .iconPalette = gItemIconPalette_RockiumZ,
    },

    [ITEM_GHOSTIUM_Z] =
    {
        .name = ITEM_NAME("SPECTROZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Spectre en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_GhostiumZ,
        .iconPalette = gItemIconPalette_GhostiumZ,
    },

    [ITEM_DRAGONIUM_Z] =
    {
        .name = ITEM_NAME("DRACOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Dragon en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_DragoniumZ,
        .iconPalette = gItemIconPalette_DragoniumZ,
    },

    [ITEM_DARKINIUM_Z] =
    {
        .name = ITEM_NAME("TÉNÉBROZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Ténèbres en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_DarkiniumZ,
        .iconPalette = gItemIconPalette_DarkiniumZ,
    },

    [ITEM_STEELIUM_Z] =
    {
        .name = ITEM_NAME("MÉTALLOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Acier en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_SteeliumZ,
        .iconPalette = gItemIconPalette_SteeliumZ,
    },

    [ITEM_FAIRIUM_Z] =
    {
        .name = ITEM_NAME("NYMPHÉZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer les capacités\n"
            "de type Fée en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_FairiumZ,
        .iconPalette = gItemIconPalette_FairiumZ,
    },

    [ITEM_PIKANIUM_Z] =
    {
        .name = ITEM_NAME("PIKAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer l'Électacle d'un\n"
            "Pikachu en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikaniumZ,
        .iconPalette = gItemIconPalette_PikaniumZ,
    },

    [ITEM_EEVIUM_Z] =
    {
        .name = ITEM_NAME("ÉVOLIZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Dernier\n"
            "Recours d'un Évoli en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_EeviumZ,
        .iconPalette = gItemIconPalette_EeviumZ,
    },

    [ITEM_SNORLIUM_Z] =
    {
        .name = ITEM_NAME("RONFLÉZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Giga Impact\n"
            "d'un Ronflex en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SnorliumZ,
        .iconPalette = gItemIconPalette_SnorliumZ,
    },

    [ITEM_MEWNIUM_Z] =
    {
        .name = ITEM_NAME("MEWZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Psyko de Mew\n"
            "en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MewniumZ,
        .iconPalette = gItemIconPalette_MewniumZ,
    },

    [ITEM_DECIDIUM_Z] =
    {
        .name = ITEM_NAME("ARCHÉZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Tisse Ombre\n"
            "d'un Archéduc en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_DecidiumZ,
        .iconPalette = gItemIconPalette_DecidiumZ,
    },

    [ITEM_INCINIUM_Z] =
    {
        .name = ITEM_NAME("FÉLINOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Dark Lariat\n"
            "d'un Félinferno en capacité\n"
            "Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_InciniumZ,
        .iconPalette = gItemIconPalette_InciniumZ,
    },

    [ITEM_PRIMARIUM_Z] =
    {
        .name = ITEM_NAME("ORATOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer l'Aria de\n"
            "l'Écume d'un Oratoria en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PrimariumZ,
        .iconPalette = gItemIconPalette_PrimariumZ,
    },

    [ITEM_LYCANIUM_Z] =
    {
        .name = ITEM_NAME("LOUGAROZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer la capacité\n"
            "Lame de Roc d'un Lougaroc\n"
            "en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LycaniumZ,
        .iconPalette = gItemIconPalette_LycaniumZ,
    },

    [ITEM_MIMIKIUM_Z] =
    {
        .name = ITEM_NAME("MIMIQUIZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer la capacité\n"
            "Câlinerie d'un Mimiqui en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MimikiumZ,
        .iconPalette = gItemIconPalette_MimikiumZ,
    },

    [ITEM_KOMMONIUM_Z] =
    {
        .name = ITEM_NAME("ÉKAÏZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer la capacité\n"
            "Vibrécaille d'un Ékaïser en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_KommoniumZ,
        .iconPalette = gItemIconPalette_KommoniumZ,
    },

    [ITEM_TAPUNIUM_Z] =
    {
        .name = ITEM_NAME("TOKOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer l'Ire de la\n"
            "Nature d'un Toko en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  //signature z move
        .iconPic = gItemIcon_TapuniumZ,
        .iconPalette = gItemIconPalette_TapuniumZ,
    },

    [ITEM_SOLGANIUM_Z] =
    {
        .name = ITEM_NAME("SOLGAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Choc\n"
            "Météore de Solgaleo en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SolganiumZ,
        .iconPalette = gItemIconPalette_SolganiumZ,
    },

    [ITEM_LUNALIUM_Z] =
    {
        .name = ITEM_NAME("LUNAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Rayon\n"
            "Spectral de Lunala en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LunaliumZ,
        .iconPalette = gItemIconPalette_LunaliumZ,
    },

    [ITEM_MARSHADIUM_Z] =
    {
        .name = ITEM_NAME("MARSHADOZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Clepto-Mânes\n"
            "de Marshadow en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MarshadiumZ,
        .iconPalette = gItemIconPalette_MarshadiumZ,
    },

    [ITEM_ALORAICHIUM_Z] =
    {
        .name = ITEM_NAME("ALORAÏZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Tonnerre\n"
            "d'un Raichu de la région\n"
            "d'Alola en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_AloraichiumZ,
        .iconPalette = gItemIconPalette_AloraichiumZ,
    },

    [ITEM_PIKASHUNIUM_Z] =
    {
        .name = ITEM_NAME("PIKACHAZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le Tonnerre du\n"
            "Pikachu à casquette en\n"
            "capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikashuniumZ,
        .iconPalette = gItemIconPalette_PikashuniumZ,
    },

    [ITEM_ULTRANECROZIUM_Z] =
    {
        .name = ITEM_NAME("ULTRANÉCROZÉLITE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Une cristallisation de la\n"
            "Force Z, permettant de\n"
            "transformer le\n"
            "Photo-Geyser de Necrozma\n"
            "en capacité Z."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255, //signature z move
        .iconPic = gItemIcon_UltranecroziumZ,
        .iconPalette = gItemIconPalette_UltranecroziumZ,
    },

// Species-specific Held Items

    [ITEM_LIGHT_BALL] =
    {
        .name = ITEM_NAME("BALLE LUMIÈRE"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = COMPOUND_STRING(
            "Objet à faire tenir par\n"
            "Pikachu. Orbe énigmatique\n"
            "qui monte son Attaque et\n"
            "son Attaque Spéciale."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightBall,
        .iconPalette = gItemIconPalette_LightBall,
    },

    [ITEM_LEEK] =
    {
        .name = ITEM_NAME("POIREAU"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .holdEffect = HOLD_EFFECT_LEEK,
        .description = COMPOUND_STRING(
            "Objet à faire tenir à\n"
            "Canarticho. Un poireau très\n"
            "long et solide qui augmente\n"
            "son taux de critiques."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_Leek,
        .iconPalette = gItemIconPalette_Leek,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = ITEM_NAME("MASSE OS"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = COMPOUND_STRING(
            "Objet à faire tenir\n"
            "à Osselait ou\n"
            "Ossatueur. Os dur\n"
            "qui monte leur\n"
            "Attaque."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = ITEM_NAME("POING CHANCE"),
        .pluralName = ITEM_PLURAL_NAME("POINGS CHANCE"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = COMPOUND_STRING(
            "Objet à faire tenir\n"
            "à Leveinard. Paire\n"
            "de gants montant\n"
            "son taux de\n"
            "critiques."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_LuckyPunch,
        .iconPalette = gItemIconPalette_LuckyPunch,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = ITEM_NAME("POUDRE MÉTAL"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = COMPOUND_STRING(
            "Objet à faire tenir à\n"
            "Métamorph. Cette poudre\n"
            "étrange, très fine mais\n"
            "résistante, booste sa\n"
            "Défense."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_MetalPowder,
    },

    [ITEM_QUICK_POWDER] =
    {
        .name = ITEM_NAME("POUDRE VITE"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = COMPOUND_STRING(
            "Objet à faire tenir à\n"
            "Métamorph. Cette poudre\n"
            "étrange, très fine mais\n"
            "résistante, augmente sa\n"
            "Vitesse."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_QuickPowder,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = ITEM_NAME("ÉCAILLE OCÉAN"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = COMPOUND_STRING(
            "Objet à faire tenir\n"
            "à Coquiperl. Écaille\n"
            "de couleur rose\n"
            "montant sa Défense\n"
            "Spéciale."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DeepSeaScale,
        .iconPalette = gItemIconPalette_DeepSeaScale,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = ITEM_NAME("DENT OCÉAN"),
        .pluralName = ITEM_PLURAL_NAME("DENTS OCÉAN"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = COMPOUND_STRING(
            "Objet à faire tenir\n"
            "à Coquiperl. Dent\n"
            "de couleur argent\n"
            "montant son\n"
            "Attaque Spéciale."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 90,
        .iconPic = gItemIcon_DeepSeaTooth,
        .iconPalette = gItemIconPalette_DeepSeaTooth,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = ITEM_NAME("ROSÉE ÂME"),
        .price = (I_PRICE >= GEN_7) ? 0 : 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .holdEffectParam = B_SOUL_DEW_BOOST >= GEN_7 ? 20 : 50,
        .description = COMPOUND_STRING(
        #if B_SOUL_DEW_BOOST >= GEN_7
            "Renforce les capacités\n"
            "PSY et DRAGON de\n"
            "Latios et Latias."),
        #else
            "Objet tenu: monte\n"
            "l'Atq. Spé. et la Déf. Spé.\n"
            "de Latios et Latias."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SoulDew,
        .iconPalette = gItemIconPalette_SoulDew,
    },

    [ITEM_ADAMANT_ORB] =
    {
        .name = ITEM_NAME("ORBE ADAMANT"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Orbe très brillant destiné à\n"
            "Dialga. Augmente la\n"
            "puissance des capacités de\n"
            "type Dragon et Acier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantOrb,
        .iconPalette = gItemIconPalette_AdamantOrb,
    },

    [ITEM_LUSTROUS_ORB] =
    {
        .name = ITEM_NAME("ORBE PERLÉ"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Bel orbe luisant destiné à\n"
            "Palkia. Augmente la\n"
            "puissance des capacités de\n"
            "type Dragon et Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousOrb,
        .iconPalette = gItemIconPalette_LustrousOrb,
    },

    [ITEM_GRISEOUS_ORB] =
    {
        .name = ITEM_NAME("ORBE PLATINÉ"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Mystérieux objet\n"
            "destiné à Giratina.\n"
            "Améliore les\n"
            "capacités de type\n"
            "Dragon et Spectre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousOrb,
        .iconPalette = gItemIconPalette_GriseousOrb,
    },

// Incenses

    [ITEM_SEA_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS MER"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = I_TYPE_BOOST_POWER >= GEN_4 ? 20 : 5,
        .description = COMPOUND_STRING(
            "Objet à tenir. Encens au\n"
            "parfum curieux qui augmente\n"
            "la puissance des capacités\n"
            "de type Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_SeaIncense,
        .iconPalette = gItemIconPalette_SeaIncense,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS DOUX"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
    #if I_LAX_INCENSE_BOOST >= GEN_4
        .holdEffectParam = 10,
        .description = COMPOUND_STRING("Objet à tenir qui\nbaisse la Précision\nde l'ennemi."),
    #else
        .holdEffectParam = 5,
        .description = COMPOUND_STRING("Objet à tenir qui\nbaisse un peu la\nPrécision ennemie."),
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaxIncense,
        .iconPalette = gItemIconPalette_LaxIncense,
    },

    [ITEM_ODD_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS BIZARRE"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Encens au\n"
            "parfum exotique augmentant\n"
            "la puissance des capacités\n"
            "de type Psy."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 10,
        .iconPic = gItemIcon_OddIncense,
        .iconPalette = gItemIconPalette_OddIncense,
    },

    [ITEM_ROCK_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS ROC"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Encens au\n"
            "parfum exotique augmentant\n"
            "la puissance des capacités\n"
            "de type Roche."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 10,
        .iconPic = gItemIcon_RockIncense,
        .iconPalette = gItemIconPalette_RockIncense,
    },

    [ITEM_FULL_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS PLEIN"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .holdEffectParam = 5,
        .description = COMPOUND_STRING(
            "Objet à tenir. Encens au\n"
            "parfum exotique gonflant\n"
            "son porteur et le faisant\n"
            "se déplacer lentement."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FullIncense,
        .iconPalette = gItemIconPalette_FullIncense,
    },

    [ITEM_WAVE_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS VAGUE"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Encens au\n"
            "parfum exotique augmentant\n"
            "la puissance des capacités\n"
            "de type Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_WaveIncense,
        .iconPalette = gItemIconPalette_WaveIncense,
    },

    [ITEM_ROSE_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS FLEUR"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Encens au\n"
            "parfum exotique augmentant\n"
            "la puissance des capacités\n"
            "de type Plante."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseIncense,
        .iconPalette = gItemIconPalette_RoseIncense,
    },

    [ITEM_LUCK_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS VEINE"),
        .price = (I_PRICE >= GEN_7) ? 11000 : 9600,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Double l'argent\n"
            "gagné si le porteur\n"
            "se joint au combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LuckIncense,
        .iconPalette = gItemIconPalette_LuckIncense,
    },

    [ITEM_PURE_INCENSE] =
    {
        .name = ITEM_NAME("ENCENS PUR"),
        .price = (I_PRICE >= GEN_7) ? 6000 : 9600,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = COMPOUND_STRING(
            "Objet à tenir. Aide à\n"
            "repousser les Pokémon\n"
            "sauvages si le porteur est\n"
            "le premier Pokémon de\n"
            "l'équipe."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PureIncense,
        .iconPalette = gItemIconPalette_PureIncense,
    },

// Contest Scarves

    [ITEM_RED_SCARF] =
    {
        .name = ITEM_NAME("FOULARD ROUGE"),
        .pluralName = ITEM_PLURAL_NAME("FOULARDS ROUGES"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Augmente le\n"
            "Sang-froid d'un\n"
            "Pokémon dans les\n"
            "Concours."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_RedScarf,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = ITEM_NAME("FOULARD BLEU"),
        .pluralName = ITEM_PLURAL_NAME("FOULARDS BLEUS"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Augmente la Beauté\n"
            "d'un Pokémon dans\n"
            "les Concours."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_BlueScarf,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = ITEM_NAME("FOULARD ROSE"),
        .pluralName = ITEM_PLURAL_NAME("FOULARDS ROSES"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Augmente la Grâce\n"
            "d'un Pokémon dans\n"
            "les Concours."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_PinkScarf,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = ITEM_NAME("FOULARD VERT"),
        .pluralName = ITEM_PLURAL_NAME("FOULARDS VERTS"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Augmente\n"
            "l'Intelligence d'un\n"
            "Pokémon dans les\n"
            "Concours."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_GreenScarf,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = ITEM_NAME("FOULARD JAUNE"),
        .pluralName = ITEM_PLURAL_NAME("FOULARDS JAUNES"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Augmente la\n"
            "Robustesse d'un\n"
            "Pokémon dans les\n"
            "Concours."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_YellowScarf,
    },

// EV Gain Modifiers

    [ITEM_MACHO_BRACE] =
    {
        .name = ITEM_NAME("BRACELET MACHO"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = COMPOUND_STRING(
            "Objet à tenir. Un bracelet\n"
            "dur et lourd qui rend le\n"
            "porteur plus fort, mais\n"
            "baisse sa Vitesse."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_MachoBrace,
        .iconPalette = gItemIconPalette_MachoBrace,
    },

    [ITEM_POWER_WEIGHT] =
    {
        .name = ITEM_NAME("POIDS POUVOIR"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Objet à tenir. Permet aux PV\n"
            "max de progresser plus vite,\n"
            "mais réduit la Vitesse\n"
            "pendant le combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_HP,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerWeight,
        .iconPalette = gItemIconPalette_PowerWeight,
    },

    [ITEM_POWER_BRACER] =
    {
        .name = ITEM_NAME("POIGNET POUVOIR"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Objet à tenir. Permet à\n"
            "l'Attaque de progresser\n"
            "plus vite, mais réduit la\n"
            "Vitesse pendant le combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_ATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBracer,
        .iconPalette = gItemIconPalette_PowerBracer,
    },

    [ITEM_POWER_BELT] =
    {
        .name = ITEM_NAME("CEINTURE POUVOIR"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Objet à tenir. Permet à la\n"
            "Défense de progresser plus\n"
            "vite, mais réduit la Vitesse\n"
            "pendant le combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_DEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBelt,
        .iconPalette = gItemIconPalette_PowerBelt,
    },

    [ITEM_POWER_LENS] =
    {
        .name = ITEM_NAME("LENTILLE POUVOIR"),
        .pluralName = ITEM_PLURAL_NAME("LENTILLES POUVOIR"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Objet à tenir. Permet à\n"
            "l'Attaque Spéciale de\n"
            "progresser plus vite, mais\n"
            "réduit la Vitesse pendant le\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerLens,
        .iconPalette = gItemIconPalette_PowerLens,
    },

    [ITEM_POWER_BAND] =
    {
        .name = ITEM_NAME("BANDEAU POUVOIR"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Objet à tenir. Permet à la\n"
            "Défense Spéciale de\n"
            "progresser plus vite, mais\n"
            "réduit la Vitesse pendant le\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPDEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBand,
        .iconPalette = gItemIconPalette_PowerBand,
    },

    [ITEM_POWER_ANKLET] =
    {
        .name = ITEM_NAME("CHAÎNE POUVOIR"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Permet à la Vitesse\n"
            "de progresser plus\n"
            "vite, mais la réduit\n"
            "pendant le combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPEED,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerAnklet,
        .iconPalette = gItemIconPalette_PowerAnklet,
    },

// Type-boosting Held Items
    #if I_PRICE >= GEN_9
        #define TYPE_BOOSTING_PRICE 3000
    #elif I_PRICE >= GEN_7
        #define TYPE_BOOSTING_PRICE 1000
    #else
        #define TYPE_BOOSTING_PRICE 100
    #endif

    [ITEM_SILK_SCARF] =
    {
        .name = ITEM_NAME("MOUCHOIR SOIE"),
        .pluralName = ITEM_PLURAL_NAME("MOUCHOIRS SOIE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Mouchoir\n"
            "somptueux montant la\n"
            "puissance des capacités de\n"
            "type Normal."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .flingPower = 10,
        .iconPic = gItemIcon_SilkScarf,
        .iconPalette = gItemIconPalette_SilkScarf,
    },

    [ITEM_CHARCOAL] =
    {
        .name = ITEM_NAME("CHARBON"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 1000,
    #else
        .price = 9800,
    #endif
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Combustible\n"
            "montant la puissance des\n"
            "capacités de type Feu."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 30,
        .iconPic = gItemIcon_Charcoal,
        .iconPalette = gItemIconPalette_Charcoal,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = ITEM_NAME("EAU MYSTIQUE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Gemme en\n"
            "forme de goutte d'eau\n"
            "montant la puissance des\n"
            "capacités de type Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 30,
        .iconPic = gItemIcon_MysticWater,
        .iconPalette = gItemIconPalette_MysticWater,
    },

    [ITEM_MAGNET] =
    {
        .name = ITEM_NAME("AIMANT"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Aimant\n"
            "puissant montant la\n"
            "puissance des capacités de\n"
            "type Électrik."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 30,
        .iconPic = gItemIcon_Magnet,
        .iconPalette = gItemIconPalette_Magnet,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = ITEM_NAME("GRAINE MIRACLE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Graine remplie\n"
            "de vie qui monte la\n"
            "puissance des capacités de\n"
            "type Plante."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 30,
        .iconPic = gItemIcon_MiracleSeed,
        .iconPalette = gItemIconPalette_MiracleSeed,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = ITEM_NAME("GLACE ÉTERNELLE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Morceau de\n"
            "glace qui réfléchit la\n"
            "chaleur et monte la\n"
            "puissance des capacités de\n"
            "type Glace."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 30,
        .iconPic = gItemIcon_NeverMeltIce,
        .iconPalette = gItemIconPalette_NeverMeltIce,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = ITEM_NAME("CEINTURE NOIRE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Une ceinture\n"
            "d'art martial qui augmente la\n"
            "puissance des capacités de\n"
            "type Combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackBelt,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_POISON_BARB] =
    {
        .name = ITEM_NAME("PIC VENIN"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Petit pic\n"
            "empoisonné montant la\n"
            "puissance des capacités de\n"
            "type Poison."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 70,
        .iconPic = gItemIcon_PoisonBarb,
        .iconPalette = gItemIconPalette_PoisonBarb,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = ITEM_NAME("SABLE DOUX"),
        .pluralName = ITEM_PLURAL_NAME("SABLES DOUX"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Sable fin et\n"
            "soyeux montant la puissance\n"
            "des capacités de type Sol."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 10,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_SoftSand,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = ITEM_NAME("BEC POINTU"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Bec long et\n"
            "pointu montant la puissance\n"
            "des capacités de type Vol."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_SharpBeak,
        .iconPalette = gItemIconPalette_SharpBeak,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = ITEM_NAME("CUILLÈRE TORDUE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Cuillère\n"
            "contenant un pouvoir\n"
            "télékinésique montant la\n"
            "puissance des capacités de\n"
            "type Psy."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 30,
        .iconPic = gItemIcon_TwistedSpoon,
        .iconPalette = gItemIconPalette_TwistedSpoon,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = ITEM_NAME("POUDRE ARGENTÉE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Poudre\n"
            "d'argent brillante qui monte\n"
            "la puissance des capacités\n"
            "de type Insecte."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 10,
        .iconPic = gItemIcon_SilverPowder,
        .iconPalette = gItemIconPalette_SilverPowder,
    },

    [ITEM_HARD_STONE] =
    {
        .name = ITEM_NAME("PIERRE DURE"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Pierre\n"
            "incassable qui monte la\n"
            "puissance des capacités de\n"
            "type Roche."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 100,
        .iconPic = gItemIcon_HardStone,
        .iconPalette = gItemIconPalette_HardStone,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = ITEM_NAME("RUNE SORT"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Plaque\n"
            "sinistre et étrange montant\n"
            "la puissance des capacités\n"
            "de type Spectre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 30,
        .iconPic = gItemIcon_SpellTag,
        .iconPalette = gItemIconPalette_SpellTag,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = ITEM_NAME("CROC DRAGON"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Croc dur et\n"
            "pointu montant la puissance\n"
            "des capacités de type\n"
            "Dragon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 70,
        .iconPic = gItemIcon_DragonFang,
        .iconPalette = gItemIconPalette_DragonFang,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = ITEM_NAME("LUNETTES NOIRES"),
        .pluralName = ITEM_PLURAL_NAME("LUNETTES NOIRES"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Paire de\n"
            "lunettes à l'aspect louche\n"
            "qui monte la puissance des\n"
            "capacités de type Ténèbres."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackGlasses,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_METAL_COAT] =
    {
        .name = ITEM_NAME("PEAU MÉTAL"),
        //#if I_PRICE >= GEN_9
        //    .price = 3000,
        //#elif I_PRICE >= GEN_7
        //    .price = 2000,
        //#else
        //    .price = 100,
        //#endif
        .price = 20000,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Objet à tenir. Pellicule\n"
            "métallique spéciale qui monte\n"
            "la puissance des capacités\n"
            "de type Acier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .secondaryId = TYPE_STEEL,
        .flingPower = 30,
        .iconPic = gItemIcon_MetalCoat,
        .iconPalette = gItemIconPalette_MetalCoat,
    },

// Choice Items

    [ITEM_CHOICE_BAND] =
    {
        .name = ITEM_NAME("BANDEAU CHOIX"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = COMPOUND_STRING(
            "Objet à tenir. Ce bandeau\n"
            "augmente l'Attaque, mais ne\n"
            "permet d'utiliser qu'une\n"
            "seule capacité."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceBand,
        .iconPalette = gItemIconPalette_ChoiceBand,
    },

    [ITEM_CHOICE_SPECS] =
    {
        .name = ITEM_NAME("LUNETTES CHOIX"),
        .pluralName = ITEM_PLURAL_NAME("LUNETTES CHOIX"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente\n"
            "l'Attaque Spéciale, mais ne\n"
            "permet d'utiliser qu'une\n"
            "seule capacité."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceSpecs,
        .iconPalette = gItemIconPalette_ChoiceSpecs,
    },

    [ITEM_CHOICE_SCARF] =
    {
        .name = ITEM_NAME("MOUCHOIR CHOIX"),
        .pluralName = ITEM_PLURAL_NAME("MOUCHOIRS CHOIX"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "Vitesse, mais ne permet\n"
            "d'utiliser qu'une seule\n"
            "capacité."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceScarf,
        .iconPalette = gItemIconPalette_ChoiceScarf,
    },

// Status Orbs

    [ITEM_FLAME_ORB] =
    {
        .name = ITEM_NAME("ORBE FLAMME"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = COMPOUND_STRING(
            "Objet à tenir. Orbe\n"
            "bizarre brûlant son\n"
            "porteur durant le\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FlameOrb,
        .iconPalette = gItemIconPalette_FlameOrb,
    },

    [ITEM_TOXIC_ORB] =
    {
        .name = ITEM_NAME("ORBE TOXIQUE"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = COMPOUND_STRING(
            "Objet à tenir. Orbe bizarre\n"
            "empoisonnant gravement son\n"
            "porteur durant le combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ToxicOrb,
        .iconPalette = gItemIconPalette_ToxicOrb,
    },

// Weather Rocks

    [ITEM_DAMP_ROCK] =
    {
        .name = ITEM_NAME("ROCHE HUMIDE"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "durée de la capacité Danse\n"
            "Pluie utilisée par le porteur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_DampRock,
        .iconPalette = gItemIconPalette_DampRock,
    },

    [ITEM_HEAT_ROCK] =
    {
        .name = ITEM_NAME("ROCHE CHAUDE"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Augmente la durée\n"
            "de la capacité\n"
            "Zénith utilisée par\n"
            "le porteur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_HeatRock,
        .iconPalette = gItemIconPalette_HeatRock,
    },

    [ITEM_SMOOTH_ROCK] =
    {
        .name = ITEM_NAME("ROCHE LISSE"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = COMPOUND_STRING(
            "Objet à tenir augmentant la\n"
            "durée de la capacité\n"
            "Tempêtesable utilisée par le\n"
            "porteur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SmoothRock,
        .iconPalette = gItemIconPalette_SmoothRock,
    },

    [ITEM_ICY_ROCK] =
    {
        .name = ITEM_NAME("ROCHE GLACE"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
    #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        .description = COMPOUND_STRING("Prolonge la Grêle\ndéclenchée par le\nporteur."),
    #elif B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING("Prolonge la Neige\ndéclenchée par le\nporteur."),
    #else
        .description = COMPOUND_STRING("Prolonge les climats\nfroids déclenchés\npar le porteur."),
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_IcyRock,
        .iconPalette = gItemIconPalette_IcyRock,
    },

// Terrain Seeds

    [ITEM_ELECTRIC_SEED] =
    {
        .name = ITEM_NAME("GRAINE ÉLECTRIK"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "Défense lorsque le terrain\n"
            "est couvert d'un Champ\n"
            "Électrifié."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_ElectricSeed,
    },

    [ITEM_PSYCHIC_SEED] =
    {
        .name = ITEM_NAME("GRAINE PSYCHIQUE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "Défense Spéciale lorsque le\n"
            "terrain est couvert d'un\n"
            "Champ Psychique."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_PsychicSeed,
    },

    [ITEM_MISTY_SEED] =
    {
        .name = ITEM_NAME("GRAINE BRUME"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_MISTY_TERRAIN,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "Défense lorsque le terrain\n"
            "est couvert d'un Champ\n"
            "Brumeux."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_MistySeed,
    },

    [ITEM_GRASSY_SEED] =
    {
        .name = ITEM_NAME("GRAINE HERBE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_GRASSY_TERRAIN,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "Défense lorsque le terrain\n"
            "est couvert d'un Champ\n"
            "Herbu."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_GrassySeed,
    },

// Type-activated Stat Modifiers

    [ITEM_ABSORB_BULB] =
    {
        .name = ITEM_NAME("BULBE"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ABSORB_BULB,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Bulbe jetable. Tenu, il\n"
            "augmente la Défense\n"
            "Spéciale lorsque le Pokémon\n"
            "subit une attaque de type\n"
            "Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbsorbBulb,
        .iconPalette = gItemIconPalette_AbsorbBulb,
    },

    [ITEM_CELL_BATTERY] =
    {
        .name = ITEM_NAME("PILE"),
        .pluralName = ITEM_PLURAL_NAME("PILES"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CELL_BATTERY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Pile jetable. Tenue, elle\n"
            "augmente l'Attaque lorsque\n"
            "le Pokémon subit une\n"
            "attaque de type Électrik."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CellBattery,
        .iconPalette = gItemIconPalette_CellBattery,
    },

    [ITEM_LUMINOUS_MOSS] =
    {
        .name = ITEM_NAME("LICHEN LUMINEUX"),
        .pluralName = ITEM_PLURAL_NAME("LICHEN LUMINEUX"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Du lichen à usage unique.\n"
            "Tenu, il augmente la Défense\n"
            "Spéciale lorsque le Pokémon\n"
            "subit une attaque de type\n"
            "Eau."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuminousMoss,
        .iconPalette = gItemIconPalette_LuminousMoss,
    },

    [ITEM_SNOWBALL] =
    {
        .name = ITEM_NAME("BOULE DE NEIGE"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SNOWBALL,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Objet à usage unique. Tenue,\n"
            "elle augmente l'Attaque du\n"
            "Pokémon lorsqu'il est touché\n"
            "par une capacité de type\n"
            "Glace."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Snowball,
        .iconPalette = gItemIconPalette_Snowball,
    },

// Misc. Held Items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = ITEM_NAME("POUDRE CLAIRE"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 10,
    #endif
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Intimide l'ennemi\n"
            "et baisse sa\n"
            "Précision."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BrightPowder,
        .iconPalette = gItemIconPalette_BrightPowder,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = ITEM_NAME("HERBE BLANCHE"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_WHITE_HERB,
        .description = COMPOUND_STRING(
            "Objet à tenir qui\n"
            "restaure les stats\n"
            "baissées. Ne peut\n"
            "être utilisé qu'une\n"
            "fois."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_WhiteHerb,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = ITEM_NAME("MULTI EXP"),
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
    #if I_EXP_SHARE_ITEM >= GEN_6
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Objet à tenir. Le\n"
            "porteur reçoit une\n"
            "partie des points\n"
            "Exp. du combat sans\n"
            "avoir à combattre."
        ),
        .pocket = POCKET_KEY_ITEMS,
    #else
        .price = (I_PRICE == GEN_1) ? 1 : 3000,
        .description = COMPOUND_STRING(
            "L'expérience gagnée va\n"
            "vers le porteur."),
        .pocket = POCKET_ITEMS,
    #endif
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_ExpShare,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpShare,
        .iconPalette = gItemIconPalette_ExpShare,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = ITEM_NAME("VIVE GRIFFE"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Griffe légère\n"
            "mais tranchante qui permet\n"
            "parfois de frapper le\n"
            "premier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_QuickClaw,
        .iconPalette = gItemIconPalette_QuickClaw,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = ITEM_NAME("GRELOT ZEN"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Grelot dont le\n"
            "carillon calme le\n"
            "porteur et\n"
            "favorise l'amitié."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SootheBell,
        .iconPalette = gItemIconPalette_SootheBell,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = ITEM_NAME("HERBE MENTAL"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_MENTAL_HERB,
        .description = COMPOUND_STRING(
        #if B_MENTAL_HERB >= GEN_5
            "Libère un POKéMON\n"
            "des effets entravant\n"
            "ses capacités."),
        #else
            "Objet à tenir qui\n"
            "libère un POKéMON\n"
            "de l'amour."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_MentalHerb,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = ITEM_NAME("ROCHE ROYALE"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir. Peut apeurer\n"
            "l'ennemi lorsque le porteur\n"
            "lui inflige des dégâts."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_KingsRock,
        .iconPalette = gItemIconPalette_KingsRock,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = ITEM_NAME("PIÈCE RUNE"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Double l'argent\n"
            "gagné si le porteur\n"
            "se joint au combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AmuletCoin,
        .iconPalette = gItemIconPalette_AmuletCoin,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = ITEM_NAME("RUNE PURIFIANTE"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = COMPOUND_STRING(
            "Objet à tenir. Aide à\n"
            "repousser les Pokémon\n"
            "sauvages si le porteur est\n"
            "le premier Pokémon de\n"
            "l'équipe."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CleanseTag,
        .iconPalette = gItemIconPalette_CleanseTag,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = ITEM_NAME("BOULE FUMÉE"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Permet au porteur\n"
            "de s'enfuir à coup\n"
            "sûr face à un\n"
            "Pokémon sauvage."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SmokeBall,
        .iconPalette = gItemIconPalette_SmokeBall,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = ITEM_NAME("BANDEAU"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir\n"
            "pouvant parfois\n"
            "empêcher d'être mis\n"
            "K.O., ne laissant\n"
            "qu'un PV."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusBand,
        .iconPalette = gItemIconPalette_FocusBand,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = ITEM_NAME("ŒUF CHANCE"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = COMPOUND_STRING(
            "Objet à tenir. Œuf\n"
            "rempli de joie qui\n"
            "augmente le nombre\n"
            "de points Exp.\n"
            "gagnés au combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuckyEgg,
        .iconPalette = gItemIconPalette_LuckyEgg,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = ITEM_NAME("LENTILSCOPE"),
        .pluralName = ITEM_PLURAL_NAME("LENTILSCOPES"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Lentille qui\n"
            "augmente le taux\n"
            "de critiques du\n"
            "porteur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ScopeLens,
        .iconPalette = gItemIconPalette_ScopeLens,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = ITEM_NAME("RESTES"),
        .pluralName = ITEM_PLURAL_NAME("RESTES"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir. Permet de\n"
            "restaurer graduellement les\n"
            "PV du porteur durant le\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Leftovers,
        .iconPalette = gItemIconPalette_Leftovers,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = ITEM_NAME("GRELOT COQUE"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Restaure un peu les\n"
            "PV du porteur\n"
            "chaque fois qu'il\n"
            "inflige des dégâts."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShellBell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_WIDE_LENS] =
    {
        .name = ITEM_NAME("LOUPE"),
        .pluralName = ITEM_PLURAL_NAME("LOUPES"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir. Une\n"
            "loupe qui augmente\n"
            "légèrement la\n"
            "Précision des\n"
            "capacités."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WideLens,
        .iconPalette = gItemIconPalette_WideLens,
    },

    [ITEM_MUSCLE_BAND] =
    {
        .name = ITEM_NAME("BANDEAU MUSCLE"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir. Bandeau\n"
            "augmentant légèrement la\n"
            "puissance des attaques\n"
            "physiques."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MuscleBand,
        .iconPalette = gItemIconPalette_MuscleBand,
    },

    [ITEM_WISE_GLASSES] =
    {
        .name = ITEM_NAME("LUNETTES SAGES"),
        .pluralName = ITEM_PLURAL_NAME("LUNETTES SAGES"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir. Paire de\n"
            "lunettes épaisses\n"
            "augmentant un peu la\n"
            "puissance des attaques\n"
            "spéciales."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WiseGlasses,
        .iconPalette = gItemIconPalette_WiseGlasses,
    },

    [ITEM_EXPERT_BELT] =
    {
        .name = ITEM_NAME("CEINTURE PRO"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Ceinture usée\n"
            "augmentant légèrement la\n"
            "puissance des capacités\n"
            "super efficaces."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ExpertBelt,
        .iconPalette = gItemIconPalette_ExpertBelt,
    },

    [ITEM_LIGHT_CLAY] =
    {
        .name = ITEM_NAME("LUMARGILE"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = COMPOUND_STRING(
            "Objet à tenir augmentant la\n"
            "durée de capacités\n"
            "barrières telles que Mur\n"
            "Lumière et Protection."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightClay,
        .iconPalette = gItemIconPalette_LightClay,
    },

    [ITEM_LIFE_ORB] =
    {
        .name = ITEM_NAME("ORBE VIE"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "puissance des capacités,\n"
            "mais dépense des PV à\n"
            "chaque coup."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LifeOrb,
        .iconPalette = gItemIconPalette_LifeOrb,
    },

    [ITEM_POWER_HERB] =
    {
        .name = ITEM_NAME("HERBE POUVOIR"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = COMPOUND_STRING(
            "Objet à tenir et à usage\n"
            "unique. Permet d'utiliser\n"
            "immédiatement une capacité\n"
            "qui devrait se charger au\n"
            "premier tour."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PowerHerb,
        .iconPalette = gItemIconPalette_PowerHerb,
    },

    [ITEM_FOCUS_SASH] =
    {
        .name = ITEM_NAME("CEINTURE FORCE"),
        .pluralName = ITEM_PLURAL_NAME("CEINTURES FORCE"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = COMPOUND_STRING(
            "Objet à tenir permettant au\n"
            "porteur, s'il a ses PV pleins,\n"
            "d'éviter un potentiel K.O. en\n"
            "conservant un PV."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusSash,
        .iconPalette = gItemIconPalette_FocusSash,
    },

    [ITEM_ZOOM_LENS] =
    {
        .name = ITEM_NAME("LENTILLE ZOOM"),
        .pluralName = ITEM_PLURAL_NAME("LENTILLES ZOOM"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "Précision du porteur s'il\n"
            "attaque après l'ennemi."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ZoomLens,
        .iconPalette = gItemIconPalette_ZoomLens,
    },

    [ITEM_METRONOME] =
    {
        .name = ITEM_NAME("MÉTRONOME"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Objet à tenir. Booste une\n"
            "capacité utilisée à\n"
            "répétition. L'effet s'annule\n"
            "si une autre capacité est\n"
            "utilisée."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Metronome,
        .iconPalette = gItemIconPalette_Metronome,
    },

    [ITEM_IRON_BALL] =
    {
        .name = ITEM_NAME("BALLE FER"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = COMPOUND_STRING(
            "Objet à tenir réduisant la\n"
            "Vitesse. Rend les porteurs\n"
            "de type Vol et lévitant\n"
            "sensibles aux capacités de\n"
            "type Sol."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 130,
        .iconPic = gItemIcon_IronBall,
        .iconPalette = gItemIconPalette_IronBall,
    },

    [ITEM_LAGGING_TAIL] =
    {
        .name = ITEM_NAME("RALENTIQUEUE"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = COMPOUND_STRING(
            "Objet à tenir\n"
            "extrêmement lourd\n"
            "qui ralentit le\n"
            "porteur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaggingTail,
        .iconPalette = gItemIconPalette_LaggingTail,
    },

    [ITEM_DESTINY_KNOT] =
    {
        .name = ITEM_NAME("NŒUD DESTIN"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = COMPOUND_STRING(
            "Un long fil rouge vif à faire\n"
            "tenir à un Pokémon. Si le\n"
            "porteur tombe amoureux,\n"
            "l'ennemi aussi."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DestinyKnot,
        .iconPalette = gItemIconPalette_DestinyKnot,
    },

    [ITEM_BLACK_SLUDGE] =
    {
        .name = ITEM_NAME("BOUE NOIRE"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = COMPOUND_STRING(
            "Objet à tenir. Restaure peu\n"
            "à peu les PV des Pokémon de\n"
            "type Poison. Inflige des\n"
            "dégâts à tous les autres\n"
            "types."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackSludge,
        .iconPalette = gItemIconPalette_BlackSludge,
    },

    [ITEM_GRIP_CLAW] =
    {
        .name = ITEM_NAME("ACCRO GRIFFE"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "durée des attaques à tours\n"
            "multiples telles que Ligotage\n"
            "et Étreinte."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_GripClaw,
        .iconPalette = gItemIconPalette_GripClaw,
    },

    [ITEM_STICKY_BARB] =
    {
        .name = ITEM_NAME("PIQUANTS"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = COMPOUND_STRING(
            "Objet à tenir. Blesse le\n"
            "porteur à chaque tour. Peut\n"
            "s'accrocher aux ennemis qui\n"
            "attaquent le porteur."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_StickyBarb,
        .iconPalette = gItemIconPalette_StickyBarb,
    },

    [ITEM_SHED_SHELL] =
    {
        .name = ITEM_NAME("CARAPACE MUE"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = COMPOUND_STRING(
            "Objet à tenir. Carapace\n"
            "dure qui permet au porteur\n"
            "de se retirer même s'il est\n"
            "affecté par une attaque\n"
            "immobilisante."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShedShell,
        .iconPalette = gItemIconPalette_ShedShell,
    },

    [ITEM_BIG_ROOT] =
    {
        .name = ITEM_NAME("GROSSE RACINE"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Augmente la\n"
            "puissance des\n"
            "attaques volant\n"
            "des PV."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BigRoot,
        .iconPalette = gItemIconPalette_BigRoot,
    },

    [ITEM_RAZOR_CLAW] =
    {
        .name = ITEM_NAME("GRIFFE RASOIR"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Griffe crochue et\n"
            "pointue\n"
            "augmentant le taux\n"
            "de critiques."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_RazorClaw,
        .iconPalette = gItemIconPalette_RazorClaw,
    },

    [ITEM_RAZOR_FANG] =
    {
        .name = ITEM_NAME("CROC RASOIR"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Objet à tenir. Peut\n"
            "apeurer l'ennemi\n"
            "quand le porteur\n"
            "lui inflige des\n"
            "dégâts."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_RazorFang,
        .iconPalette = gItemIconPalette_RazorFang,
    },

    [ITEM_EVIOLITE] =
    {
        .name = ITEM_NAME("ÉVOLUROC"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Un étrange concentré\n"
            "d'évolution qui augmente la\n"
            "Défense et la Déf. Spé. d'un\n"
            "Pokémon pouvant évoluer."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_Eviolite,
        .iconPalette = gItemIconPalette_Eviolite,
    },

    [ITEM_FLOAT_STONE] =
    {
        .name = ITEM_NAME("PIERRALLÉGÉE"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = COMPOUND_STRING(
            "Une pierre très\n"
            "légère. Elle réduit\n"
            "le poids du Pokémon\n"
            "qui la tient."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FloatStone,
        .iconPalette = gItemIconPalette_FloatStone,
    },

    [ITEM_ROCKY_HELMET] =
    {
        .name = ITEM_NAME("CASQUE BRUT"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Tenu, cet objet inflige des\n"
            "dégâts à l'attaquant si ce\n"
            "dernier utilise une attaque\n"
            "physique qui atteint son\n"
            "but."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_RockyHelmet,
        .iconPalette = gItemIconPalette_RockyHelmet,
    },

    [ITEM_AIR_BALLOON] =
    {
        .name = ITEM_NAME("BALLON"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_AIR_BALLOON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING("Fait flotter son\nporteur, mais éclate\ns'il subit une attaque."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AirBalloon,
        .iconPalette = gItemIconPalette_AirBalloon,
    },

    [ITEM_RED_CARD] =
    {
        .name = ITEM_NAME("CARTON ROUGE"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RED_CARD,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Carte au pouvoir\n"
            "mystérieux. Tenue, elle\n"
            "force un Pokémon touchant\n"
            "le porteur à se retirer du\n"
            "combat."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RedCard,
        .iconPalette = gItemIconPalette_RedCard,
    },

    [ITEM_RING_TARGET] =
    {
        .name = ITEM_NAME("POINT DE MIRE"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RING_TARGET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Un Pokémon tenant cet\n"
            "objet devient sensible aux\n"
            "capacités autrement\n"
            "inefficaces en raison de son\n"
            "type."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RingTarget,
        .iconPalette = gItemIconPalette_RingTarget,
    },

    [ITEM_BINDING_BAND] =
    {
        .name = ITEM_NAME("BANDE ÉTREINTE"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "puissance des attaques\n"
            "immobilisantes telles que\n"
            "Ligotage ou Étreinte."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BindingBand,
        .iconPalette = gItemIconPalette_BindingBand,
    },

    [ITEM_EJECT_BUTTON] =
    {
        .name = ITEM_NAME("BOUTON FUITE"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Objet à tenir. Permet au\n"
            "porteur de quitter le\n"
            "combat après avoir été\n"
            "touché par une attaque."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_EjectButton,
        .iconPalette = gItemIconPalette_EjectButton,
    },

    [ITEM_WEAKNESS_POLICY] =
    {
        .name = ITEM_NAME("VULNÉ-ASSURANCE"),
        .pluralName = ITEM_PLURAL_NAME("VULNÉ-ASSURANCES"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente\n"
            "beaucoup l'Attaque et\n"
            "l'Attaque Spéciale du\n"
            "Pokémon lorsqu'il reçoit un\n"
            "coup d'un type auquel il est\n"
            "vulnérable."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_WeaknessPolicy,
        .iconPalette = gItemIconPalette_WeaknessPolicy,
    },

    [ITEM_ASSAULT_VEST] =
    {
        .name = ITEM_NAME("VESTE DE COMBAT"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Objet à tenir. Une veste\n"
            "augmentant la Défense\n"
            "Spéciale, mais empêchant\n"
            "d'utiliser des attaques de\n"
            "statut."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AssaultVest,
        .iconPalette = gItemIconPalette_AssaultVest,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
        .name = ITEM_NAME("LUNETTES FILTRE"),
        .pluralName = ITEM_PLURAL_NAME("LUNETTES FILTRE"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_SAFETY_GOGGLES,
        .description = COMPOUND_STRING(
            "Objet à tenir. Protège le\n"
            "Pokémon contre les dégâts\n"
            "dus à la météo et la plupart\n"
            "des capacités utilisant de la\n"
            "poudre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_SafetyGoggles,
        .iconPalette = gItemIconPalette_SafetyGoggles,
    },

    [ITEM_ADRENALINE_ORB] =
    {
        .name = ITEM_NAME("ORBE FROUSSE"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE == GEN_8
        .price = 4000,
    #else
        .price = 300,
    #endif
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = COMPOUND_STRING(
            "Objet à tenir. Si le\n"
            "porteur subit une\n"
            "Intimidation, sa\n"
            "Vitesse augmente."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AdrenalineOrb,
        .iconPalette = gItemIconPalette_AdrenalineOrb,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
        .name = ITEM_NAME("CHAMP’DUIT"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = COMPOUND_STRING(
            "Objet à tenir. Augmente la\n"
            "durée des champs que le\n"
            "Pokémon peut créer sur le\n"
            "terrain avec une capacité\n"
            "ou un talent."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_TerrainExtender,
        .iconPalette = gItemIconPalette_TerrainExtender,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
        .name = ITEM_NAME("PARE-EFFET"),
        .pluralName = ITEM_PLURAL_NAME("PARE-EFFETS"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = COMPOUND_STRING(
            "Annule les effets subis par\n"
            "le porteur quand il utilise\n"
            "une attaque directe sur un\n"
            "autre Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ProtectivePads,
        .iconPalette = gItemIconPalette_ProtectivePads,
    },

    [ITEM_THROAT_SPRAY] =
    {
        .name = ITEM_NAME("SPRAY GORGE"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_THROAT_SPRAY,
        .description = COMPOUND_STRING(
            "Augmente l'Attaque\n"
            "Spéciale du porteur\n"
            "lorsqu'il utilise\n"
            "une capacité basée\n"
            "sur le son."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ThroatSpray,
        .iconPalette = gItemIconPalette_ThroatSpray,
    },

    [ITEM_EJECT_PACK] =
    {
        .name = ITEM_NAME("SAC FUITE"),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_EJECT_PACK,
        .description = COMPOUND_STRING(
            "Objet à tenir. Si le porteur\n"
            "subit une baisse de stats, il\n"
            "revient vers son Dresseur\n"
            "et change de place avec un\n"
            "coéquipier."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
        .iconPic = gItemIcon_EjectPack,
        .iconPalette = gItemIconPalette_EjectPack,
    },

    [ITEM_HEAVY_DUTY_BOOTS] =
    {
        .name = ITEM_NAME("GROSSES BOTTES"),
        .pluralName = ITEM_PLURAL_NAME("GROSSES BOTTES"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_HEAVY_DUTY_BOOTS,
        .description = COMPOUND_STRING(
            "Le porteur ne subit\n"
            "plus les effets des\n"
            "pièges ou autres\n"
            "entraves posés sur\n"
            "le terrain."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_HeavyDutyBoots,
        .iconPalette = gItemIconPalette_HeavyDutyBoots,
    },

    [ITEM_BLUNDER_POLICY] =
    {
        .name = ITEM_NAME("ASSURANCE ÉCHEC"),
        .pluralName = ITEM_PLURAL_NAME("ASSURANCES ÉCHEC"),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_BLUNDER_POLICY,
        .description = COMPOUND_STRING(
            "Si un Pokémon manque sa\n"
            "cible parce qu'une capacité\n"
            "a peu de Précision, sa\n"
            "Vitesse augmente beaucoup."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_BlunderPolicy,
        .iconPalette = gItemIconPalette_BlunderPolicy,
    },

    [ITEM_ROOM_SERVICE] =
    {
        .name = ITEM_NAME("CHARIOT DISTORDU"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_ROOM_SERVICE,
        .description = COMPOUND_STRING(
            "Objet à tenir. Baisse la\n"
            "Vitesse du porteur lorsque\n"
            "la capacité Distorsion est\n"
            "active."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RoomService,
        .iconPalette = gItemIconPalette_RoomService,
    },

    [ITEM_UTILITY_UMBRELLA] =
    {
        .name = ITEM_NAME("PARAPLUIE SOLIDE"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_UTILITY_UMBRELLA,
        .description = COMPOUND_STRING(
            "Objet à tenir.\n"
            "Protège le porteur\n"
            "des effets de la\n"
            "pluie et des rayons\n"
            "du soleil."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_UtilityUmbrella,
        .iconPalette = gItemIconPalette_UtilityUmbrella,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = ITEM_NAME("BAIE CERIZ"),
        .pluralName = ITEM_PLURAL_NAME("BAIES CERIZ"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = COMPOUND_STRING(
            "Baie qui soigne la\n"
            "paralysie\n"
            "lorsqu'elle est\n"
            "tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_CheriBerry,
        .iconPalette = gItemIconPalette_CheriBerry,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = ITEM_NAME("BAIE MARON"),
        .pluralName = ITEM_PLURAL_NAME("BAIES MARON"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = COMPOUND_STRING(
            "Baie qui soigne le\n"
            "sommeil lorsqu'elle\n"
            "est tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 10,
        .iconPic = gItemIcon_ChestoBerry,
        .iconPalette = gItemIconPalette_ChestoBerry,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = ITEM_NAME("BAIE PÊCHA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES PÊCHA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = COMPOUND_STRING(
            "Baie qui soigne\n"
            "l'empoisonnement\n"
            "lorsqu'elle est\n"
            "tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 10,
        .iconPic = gItemIcon_PechaBerry,
        .iconPalette = gItemIconPalette_PechaBerry,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = ITEM_NAME("BAIE FRAIVE"),
        .pluralName = ITEM_PLURAL_NAME("BAIES FRAIVE"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = COMPOUND_STRING(
            "Baie qui soigne les\n"
            "brûlures\n"
            "lorsqu'elle est\n"
            "tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_RawstBerry,
        .iconPalette = gItemIconPalette_RawstBerry,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = ITEM_NAME("BAIE WILLIA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES WILLIA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = COMPOUND_STRING(
            "Baie qui soigne le\n"
            "gel lorsqu'elle est\n"
            "tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_AspearBerry,
        .iconPalette = gItemIconPalette_AspearBerry,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = ITEM_NAME("BAIE MEPO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES MEPO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Baie qui restaure\n"
            "10 PP lorsqu'elle\n"
            "est tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_LeppaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_LeppaBerry,
        .iconPalette = gItemIconPalette_LeppaBerry,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = ITEM_NAME("BAIE ORAN"),
        .pluralName = ITEM_PLURAL_NAME("BAIES ORAN"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Baie qui restaure\n"
            "10 PV lorsqu'elle\n"
            "est tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_OranBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_OranBerry,
        .iconPalette = gItemIconPalette_OranBerry,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = ITEM_NAME("BAIE KIKA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES KIKA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = COMPOUND_STRING(
            "Baie qui soigne la\n"
            "confusion\n"
            "lorsqu'elle est\n"
            "tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_PersimBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PersimBerry,
        .iconPalette = gItemIconPalette_PersimBerry,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = ITEM_NAME("BAIE PRINE"),
        .pluralName = ITEM_PLURAL_NAME("BAIES PRINE"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = COMPOUND_STRING(
            "Baie qui soigne tous les\n"
            "problèmes de statut\n"
            "lorsqu'elle est tenue par un\n"
            "Pokémon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_LumBerry,
        .iconPalette = gItemIconPalette_LumBerry,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = ITEM_NAME("BAIE SITRUS"),
        .pluralName = ITEM_PLURAL_NAME("BAIES SITRUS"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
    #if I_SITRUS_BERRY_HEAL >= GEN_4
        .holdEffect = HOLD_EFFECT_RESTORE_PCT_HP,
        .holdEffectParam = 25,
        .description = COMPOUND_STRING("Objet à tenir qui\nrestaure un peu les\nPV de son porteur."),
    #else
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING("Objet à tenir qui\nrestaure 30 PV\nen combat."),
    #endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SitrusBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_SitrusBerry,
        .iconPalette = gItemIconPalette_SitrusBerry,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = ITEM_NAME("BAIE FIGUY"),
        .pluralName = ITEM_PLURAL_NAME("BAIES FIGUY"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie restaure\n"
            "des PV en cas de besoin,\n"
            "mais rend confus si le\n"
            "Pokémon n'aime pas son goût."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FigyBerry,
        .iconPalette = gItemIconPalette_FigyBerry,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = ITEM_NAME("BAIE WIKI"),
        .pluralName = ITEM_PLURAL_NAME("BAIES WIKI"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie restaure\n"
            "des PV en cas de besoin,\n"
            "mais rend confus si le\n"
            "Pokémon n'aime pas son goût."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WikiBerry,
        .iconPalette = gItemIconPalette_WikiBerry,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = ITEM_NAME("BAIE MAGO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES MAGO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie restaure\n"
            "des PV en cas de besoin,\n"
            "mais rend confus si le\n"
            "Pokémon n'aime pas son goût."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagoBerry,
        .iconPalette = gItemIconPalette_MagoBerry,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = ITEM_NAME("BAIE GOWAV"),
        .pluralName = ITEM_PLURAL_NAME("BAIES GOWAV"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie restaure\n"
            "des PV en cas de besoin,\n"
            "mais rend confus si le\n"
            "Pokémon n'aime pas son goût."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AguavBerry,
        .iconPalette = gItemIconPalette_AguavBerry,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = ITEM_NAME("BAIE PAPAYA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES PAPAYA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie restaure\n"
            "des PV en cas de besoin,\n"
            "mais rend confus si le\n"
            "Pokémon n'aime pas son goût."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_IapapaBerry,
        .iconPalette = gItemIconPalette_IapapaBerry,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = ITEM_NAME("BAIE FRAMBY"),
        .pluralName = ITEM_PLURAL_NAME("BAIES FRAMBY"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RazzBerry,
        .iconPalette = gItemIconPalette_RazzBerry,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = ITEM_NAME("BAIE REMU"),
        .pluralName = ITEM_PLURAL_NAME("BAIES REMU"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BlukBerry,
        .iconPalette = gItemIconPalette_BlukBerry,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = ITEM_NAME("BAIE NANAB"),
        .pluralName = ITEM_PLURAL_NAME("BAIES NANAB"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NanabBerry,
        .iconPalette = gItemIconPalette_NanabBerry,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = ITEM_NAME("BAIE REPOI"),
        .pluralName = ITEM_PLURAL_NAME("BAIES REPOI"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WepearBerry,
        .iconPalette = gItemIconPalette_WepearBerry,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = ITEM_NAME("BAIE NANANA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES NANANA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PinapBerry,
        .iconPalette = gItemIconPalette_PinapBerry,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = ITEM_NAME("BAIE GRENA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES GRENA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Rend les Pokémon\n"
            "plus amicaux, mais\n"
            "baisse leurs PV de\n"
            "base."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_PomegBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PomegBerry,
        .iconPalette = gItemIconPalette_PomegBerry,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = ITEM_NAME("BAIE ALGA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES ALGA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Rend les Pokémon\n"
            "plus amicaux, mais\n"
            "baisse leur stat\n"
            "Attaque de base."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_KelpsyBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_KelpsyBerry,
        .iconPalette = gItemIconPalette_KelpsyBerry,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = ITEM_NAME("BAIE QUALOT"),
        .pluralName = ITEM_PLURAL_NAME("BAIES QUALOT"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Rend les Pokémon\n"
            "plus amicaux, mais\n"
            "baisse leur stat\n"
            "Défense de base."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_QualotBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_QualotBerry,
        .iconPalette = gItemIconPalette_QualotBerry,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = ITEM_NAME("BAIE LONME"),
        .pluralName = ITEM_PLURAL_NAME("BAIES LONME"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Rend les Pokémon\n"
            "plus amicaux, mais\n"
            "baisse leur stat\n"
            "Attaque Spéciale\n"
            "de base."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_HondewBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_HondewBerry,
        .iconPalette = gItemIconPalette_HondewBerry,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = ITEM_NAME("BAIE RÉSIN"),
        .pluralName = ITEM_PLURAL_NAME("BAIES RÉSIN"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Rend les Pokémon\n"
            "plus amicaux, mais\n"
            "baisse leur stat\n"
            "Défense Spéciale\n"
            "de base."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_GrepaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_GrepaBerry,
        .iconPalette = gItemIconPalette_GrepaBerry,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = ITEM_NAME("BAIE TAMATO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES TAMATO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Rend les Pokémon\n"
            "plus amicaux, mais\n"
            "baisse leur stat\n"
            "Vitesse de base."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_TamatoBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_TamatoBerry,
        .iconPalette = gItemIconPalette_TamatoBerry,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = ITEM_NAME("BAIE SIAM"),
        .pluralName = ITEM_PLURAL_NAME("BAIES SIAM"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CornnBerry,
        .iconPalette = gItemIconPalette_CornnBerry,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = ITEM_NAME("BAIE MANGOU"),
        .pluralName = ITEM_PLURAL_NAME("BAIES MANGOU"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagostBerry,
        .iconPalette = gItemIconPalette_MagostBerry,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = ITEM_NAME("BAIE RABUTA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES RABUTA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RabutaBerry,
        .iconPalette = gItemIconPalette_RabutaBerry,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = ITEM_NAME("BAIE TRONCI"),
        .pluralName = ITEM_PLURAL_NAME("BAIES TRONCI"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NomelBerry,
        .iconPalette = gItemIconPalette_NomelBerry,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = ITEM_NAME("BAIE KIWAN"),
        .pluralName = ITEM_PLURAL_NAME("BAIES KIWAN"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SpelonBerry,
        .iconPalette = gItemIconPalette_SpelonBerry,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = ITEM_NAME("BAIE PALMA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES PALMA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PamtreBerry,
        .iconPalette = gItemIconPalette_PamtreBerry,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = ITEM_NAME("BAIE STEKPA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES STEKPA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WatmelBerry,
        .iconPalette = gItemIconPalette_WatmelBerry,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = ITEM_NAME("BAIE DURIN"),
        .pluralName = ITEM_PLURAL_NAME("BAIES DURIN"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DurinBerry,
        .iconPalette = gItemIconPalette_DurinBerry,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = ITEM_NAME("BAIE MYRTE"),
        .pluralName = ITEM_PLURAL_NAME("BAIES MYRTE"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Une Baie très rare\n"
            "à Unys."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BelueBerry,
        .iconPalette = gItemIconPalette_BelueBerry,
    },

    [ITEM_CHILAN_BERRY] =
    {
        .name = ITEM_NAME("BAIE ZALIS"),
        .pluralName = ITEM_PLURAL_NAME("BAIES ZALIS"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_NORMAL,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie de\n"
            "type Normal."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChilanBerry,
        .iconPalette = gItemIconPalette_ChilanBerry,
    },

    [ITEM_OCCA_BERRY] =
    {
        .name = ITEM_NAME("BAIE CHOCCO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES CHOCCO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIRE,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Feu."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_OccaBerry,
        .iconPalette = gItemIconPalette_OccaBerry,
    },

    [ITEM_PASSHO_BERRY] =
    {
        .name = ITEM_NAME("BAIE POCPOC"),
        .pluralName = ITEM_PLURAL_NAME("BAIES POCPOC"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_WATER,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Eau."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PasshoBerry,
        .iconPalette = gItemIconPalette_PasshoBerry,
    },

    [ITEM_WACAN_BERRY] =
    {
        .name = ITEM_NAME("BAIE PARMA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES PARMA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ELECTRIC,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Électrik."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WacanBerry,
        .iconPalette = gItemIconPalette_WacanBerry,
    },

    [ITEM_RINDO_BERRY] =
    {
        .name = ITEM_NAME("BAIE RATAM"),
        .pluralName = ITEM_PLURAL_NAME("BAIES RATAM"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GRASS,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Plante."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RindoBerry,
        .iconPalette = gItemIconPalette_RindoBerry,
    },

    [ITEM_YACHE_BERRY] =
    {
        .name = ITEM_NAME("BAIE NANONE"),
        .pluralName = ITEM_PLURAL_NAME("BAIES NANONE"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ICE,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Glace."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_YacheBerry,
        .iconPalette = gItemIconPalette_YacheBerry,
    },

    [ITEM_CHOPLE_BERRY] =
    {
        .name = ITEM_NAME("BAIE POMROZ"),
        .pluralName = ITEM_PLURAL_NAME("BAIES POMROZ"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Combat."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChopleBerry,
        .iconPalette = gItemIconPalette_ChopleBerry,
    },

    [ITEM_KEBIA_BERRY] =
    {
        .name = ITEM_NAME("BAIE KÉBIA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES KÉBIA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_POISON,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Poison."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KebiaBerry,
        .iconPalette = gItemIconPalette_KebiaBerry,
    },

    [ITEM_SHUCA_BERRY] =
    {
        .name = ITEM_NAME("BAIE JOUCA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES JOUCA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GROUND,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Sol."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShucaBerry,
        .iconPalette = gItemIconPalette_ShucaBerry,
    },

    [ITEM_COBA_BERRY] =
    {
        .name = ITEM_NAME("BAIE COBABA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES COBABA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FLYING,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Vol."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CobaBerry,
        .iconPalette = gItemIconPalette_CobaBerry,
    },

    [ITEM_PAYAPA_BERRY] =
    {
        .name = ITEM_NAME("BAIE YAPAP"),
        .pluralName = ITEM_PLURAL_NAME("BAIES YAPAP"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_PSYCHIC,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Psy."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PayapaBerry,
        .iconPalette = gItemIconPalette_PayapaBerry,
    },

    [ITEM_TANGA_BERRY] =
    {
        .name = ITEM_NAME("BAIE PANGA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES PANGA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_BUG,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Insecte."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TangaBerry,
        .iconPalette = gItemIconPalette_TangaBerry,
    },

    [ITEM_CHARTI_BERRY] =
    {
        .name = ITEM_NAME("BAIE CHARTI"),
        .pluralName = ITEM_PLURAL_NAME("BAIES CHARTI"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ROCK,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Roche."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChartiBerry,
        .iconPalette = gItemIconPalette_ChartiBerry,
    },

    [ITEM_KASIB_BERRY] =
    {
        .name = ITEM_NAME("BAIE SÉDRA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES SÉDRA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GHOST,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Spectre."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KasibBerry,
        .iconPalette = gItemIconPalette_KasibBerry,
    },

    [ITEM_HABAN_BERRY] =
    {
        .name = ITEM_NAME("BAIE FRAIGO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES FRAIGO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DRAGON,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Dragon."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_HabanBerry,
        .iconPalette = gItemIconPalette_HabanBerry,
    },

    [ITEM_COLBUR_BERRY] =
    {
        .name = ITEM_NAME("BAIE LAMPOU"),
        .pluralName = ITEM_PLURAL_NAME("BAIES LAMPOU"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DARK,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Ténèbres."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ColburBerry,
        .iconPalette = gItemIconPalette_ColburBerry,
    },

    [ITEM_BABIRI_BERRY] =
    {
        .name = ITEM_NAME("BAIE BABIRI"),
        .pluralName = ITEM_PLURAL_NAME("BAIES BABIRI"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_STEEL,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Acier."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BabiriBerry,
        .iconPalette = gItemIconPalette_BabiriBerry,
    },

    [ITEM_ROSELI_BERRY] =
    {
        .name = ITEM_NAME("BAIE SELRO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES SELRO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FAIRY,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "affaiblit une\n"
            "attaque ennemie\n"
            "super efficace de\n"
            "type Fée."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseliBerry,
        .iconPalette = gItemIconPalette_RoseliBerry,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = ITEM_NAME("BAIE LICHII"),
        .pluralName = ITEM_PLURAL_NAME("BAIES LICHII"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "monte l'Attaque en\n"
            "cas de besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LiechiBerry,
        .iconPalette = gItemIconPalette_LiechiBerry,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = ITEM_NAME("BAIE LINGAN"),
        .pluralName = ITEM_PLURAL_NAME("BAIES LINGAN"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "monte la Défense\n"
            "en cas de besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_GanlonBerry,
        .iconPalette = gItemIconPalette_GanlonBerry,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = ITEM_NAME("BAIE SAILAK"),
        .pluralName = ITEM_PLURAL_NAME("BAIES SAILAK"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "monte la Vitesse en\n"
            "cas de besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SalacBerry,
        .iconPalette = gItemIconPalette_SalacBerry,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = ITEM_NAME("BAIE PITAYE"),
        .pluralName = ITEM_PLURAL_NAME("BAIES PITAYE"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "monte l'Atq. Spé. en\n"
            "cas de besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PetayaBerry,
        .iconPalette = gItemIconPalette_PetayaBerry,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = ITEM_NAME("BAIE ABRIKO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES ABRIKO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "monte la Déf. Spé.\n"
            "en cas de besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ApicotBerry,
        .iconPalette = gItemIconPalette_ApicotBerry,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = ITEM_NAME("BAIE LANSAT"),
        .pluralName = ITEM_PLURAL_NAME("BAIES LANSAT"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "monte le taux de\n"
            "critiques en cas de\n"
            "besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LansatBerry,
        .iconPalette = gItemIconPalette_LansatBerry,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = ITEM_NAME("BAIE FRISTA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES FRISTA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "monte beaucoup une\n"
            "des stats en cas de\n"
            "besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarfBerry,
        .iconPalette = gItemIconPalette_StarfBerry,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = ITEM_NAME("BAIE ENIGMA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES ENIGMA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ENIGMA_BERRY,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "restaure les PV du\n"
            "Pokémon s'il subit\n"
            "une attaque super\n"
            "efficace."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

    [ITEM_MICLE_BERRY] =
    {
        .name = ITEM_NAME("BAIE MICLE"),
        .pluralName = ITEM_PLURAL_NAME("BAIES MICLE"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MICLE_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "augmente une fois\n"
            "la Précision d'une\n"
            "capacité en cas de\n"
            "besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MicleBerry,
        .iconPalette = gItemIconPalette_MicleBerry,
    },

    [ITEM_CUSTAP_BERRY] =
    {
        .name = ITEM_NAME("BAIE CHÉRIM"),
        .pluralName = ITEM_PLURAL_NAME("BAIES CHÉRIM"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CUSTAP_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "permet d'attaquer\n"
            "en premier une fois\n"
            "en cas de besoin."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CustapBerry,
        .iconPalette = gItemIconPalette_CustapBerry,
    },

    [ITEM_JABOCA_BERRY] =
    {
        .name = ITEM_NAME("BAIE JABOCA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES JABOCA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_JABOCA_BERRY,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie inflige des\n"
            "dégâts à l'ennemi s'il utilise\n"
            "une attaque physique qui\n"
            "atteint son but."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_JabocaBerry,
        .iconPalette = gItemIconPalette_JabocaBerry,
    },

    [ITEM_ROWAP_BERRY] =
    {
        .name = ITEM_NAME("BAIE POMMO"),
        .pluralName = ITEM_PLURAL_NAME("BAIES POMMO"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ROWAP_BERRY,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie inflige des\n"
            "dégâts à l'ennemi s'il utilise\n"
            "une attaque spéciale qui\n"
            "atteint son but."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RowapBerry,
        .iconPalette = gItemIconPalette_RowapBerry,
    },

    [ITEM_KEE_BERRY] =
    {
        .name = ITEM_NAME("BAIE ÉKA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES ÉKA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_KEE_BERRY,
        .description = COMPOUND_STRING(
            "Baie à tenir augmentant la\n"
            "Défense du Pokémon lorsqu'il\n"
            "est touché par une attaque\n"
            "physique."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KeeBerry,
        .iconPalette = gItemIconPalette_KeeBerry,
    },

    [ITEM_MARANGA_BERRY] =
    {
        .name = ITEM_NAME("BAIE RANGMA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES RANGMA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MARANGA_BERRY,
        .description = COMPOUND_STRING(
            "Baie à tenir augmentant la\n"
            "Défense Spéciale du Pokémon\n"
            "lorsqu'il est touché par une\n"
            "attaque spéciale."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MarangaBerry,
        .iconPalette = gItemIconPalette_MarangaBerry,
    },

    [ITEM_ENIGMA_BERRY_E_READER] =
    {
        .name = ITEM_NAME("BAIE ENIGMA"),
        .pluralName = ITEM_PLURAL_NAME("BAIES ENIGMA"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Tenue, cette Baie\n"
            "restaure les PV du\n"
            "Pokémon s'il subit\n"
            "une attaque super\n"
            "efficace."
        ),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = EFFECT_ITEM_ENIGMA_BERRY_EREADER,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

// TMs/HMs. They don't have a set flingPower, as that's handled by GetFlingPowerFromItemId.

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = ITEM_NAME("CT01"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Puissant, mais peut\n"
            "apeurer le lanceur\n"
            "s'il est touché."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = ITEM_NAME("CT02"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attrape l'ennemi et\n"
            "le lacère d'un\n"
            "féroce coup de\n"
            "griffe."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = ITEM_NAME("CT03"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Génère des\n"
            "ultra-sons qui\n"
            "rendent confus."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = ITEM_NAME("CT04"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Concentration pour\n"
            "monter l'Atq. Spe.\n"
            "et la Def. Spe."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROAR] =
    {
        .name = ITEM_NAME("CT05"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Un horrible\n"
            "hurlement. Fait\n"
            "fuir pour terminer\n"
            "le combat."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = ITEM_NAME("CT06"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Empoisonne l'ennemi\n"
            "avec une toxine de\n"
            "plus en plus forte."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HAIL] =
    {
        .name = ITEM_NAME("CT07"),
        .price = 3000,
    #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING("Monte la Défense des\n{PKMN} de type GLACE\npendant 5 tours."),
    #else
        .description = COMPOUND_STRING("Déclenche une grêle\nqui blesse tous les\ntypes sauf GLACE."),
    #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = ITEM_NAME("CT08"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Se gonfle pour\n"
            "monter l'Attaque et\n"
            "la Défense."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = ITEM_NAME("CT09"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Mitraille l'ennemi\n"
            "avec 2 à 5 graines\n"
            "de suite."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = ITEM_NAME("CT10"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "La puissance de\n"
            "l'attaque dépend\n"
            "du Pokémon lanceur."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = ITEM_NAME("CT11"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Améliore les\n"
            "attaques Feu\n"
            "pendant 5 tours."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = ITEM_NAME("CT12"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Provoque l'ennemi.\n"
            "L'oblige à utiliser\n"
            "des attaques."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = ITEM_NAME("CT13"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Un rayon glacial\n"
            "qui peut\n"
        #if B_USE_FROSTBITE == TRUE
            "infliger une gelure."),
        #else
            "geler l'ennemi."),
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = ITEM_NAME("CT14"),
        .price = 10000,
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
            "Une attaque de neige\n"
            "et de vent pouvant\n"
            "infliger une gelure."),
        #else
            "Une violente attaque\n"
            "de neige et de vent\n"
            "pouvant geler l'ennemi."),
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = ITEM_NAME("CT15"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Puissant. Oblige le lanceur à\n"
            "recharger le tour suivant."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = ITEM_NAME("CT16"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Crée un mur\n"
            "lumineux. Baisse\n"
            "les dégâts d'Atq.\n"
            "Spe."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = ITEM_NAME("CT17"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Ignore les dégâts,\n"
            "mais peut échouer\n"
            "si réutilisée."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = ITEM_NAME("CT18"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Améliore les\n"
            "attaques Eau\n"
            "pendant 5 tours."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = ITEM_NAME("CT19"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Une attaque qui\n"
            "aspire la moitié des\n"
            "dégâts infligés."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = ITEM_NAME("CT20"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Force mystique\n"
            "empêchant tout\n"
            "changement de\n"
            "statut."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = ITEM_NAME("CT21"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Attaque plus\n"
            "puissante si le\n"
            "lanceur vous\n"
            "déteste."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = ITEM_NAME("CT22"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Absorbe la lumière\n"
            "et attaque le tour\n"
            "suivant."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = ITEM_NAME("CT23"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Frappe l'ennemi\n"
            "avec sa queue. Peut\n"
            "baisser la Défense."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = ITEM_NAME("CT24"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Forte attaque\n"
            "électrique pouvant\n"
            "paralyser l'ennemi."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = ITEM_NAME("CT25"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Une attaque\n"
            "foudroyante\n"
            "pouvant paralyser\n"
            "l'ennemi."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = ITEM_NAME("CT26"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Séisme sans effet\n"
            "sur les adversaires\n"
            "volants."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RETURN] =
    {
        .name = ITEM_NAME("CT27"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Attaque dont la\n"
            "puissance dépend\n"
            "de l'amitié."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DIG] =
    {
        .name = ITEM_NAME("CT28"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Creuse sous terre au 1{SUPER_ER}\n"
            "tour et frappe au 2{SUPER_E}."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = ITEM_NAME("CT29"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Puissante attaque\n"
            "Psy pouvant\n"
            "baisser la Def. Spe."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = ITEM_NAME("CT30"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Projette une\n"
            "grande tache qui\n"
            "peut baisser la\n"
            "Def. Spe."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = ITEM_NAME("CT31"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Détruit les\n"
            "barrières comme Mur\n"
            "Lumiere et blesse."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = ITEM_NAME("CT32"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Crée de fausses\n"
            "copies pour\n"
            "augmenter\n"
            "l'esquive."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = ITEM_NAME("CT33"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Crée un mur\n"
            "lumineux. Affaiblit\n"
            "les att. physiques."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = ITEM_NAME("CT34"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Envoie un choc\n"
            "électrique\n"
            "impossible à\n"
            "esquiver."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = ITEM_NAME("CT35"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Envoie un torrent\n"
            "de flammes pouvant\n"
            "brûler l'ennemi."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = ITEM_NAME("CT36"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Envoie des\n"
            "détritus pour\n"
            "blesser. Peut\n"
            "empoisonner."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = ITEM_NAME("CT37"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Une tempête de\n"
            "sable qui dure\n"
            "plusieurs tours."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = ITEM_NAME("CT38"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Puissante attaque\n"
            "enflammée pouvant\n"
            "brûler l'ennemi."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = ITEM_NAME("CT39"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Bloque l'ennemi\n"
            "avec des rocs. Peut\n"
            "baisser la Vitesse."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = ITEM_NAME("CT40"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Une attaque\n"
            "extrêmement rapide\n"
            "et inévitable."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = ITEM_NAME("CT41"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Empêche la\n"
            "réutilisation d'une\n"
            "attaque."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FACADE] =
    {
        .name = ITEM_NAME("CT42"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Améliore l'Attaque\n"
            "si brûlé, paralysé\n"
            "ou empoisonné."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = ITEM_NAME("CT43"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Les effets de\n"
            "l'attaque\n"
            "dépendent du lieu."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REST] =
    {
        .name = ITEM_NAME("CT44"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Le lanceur dort 2\n"
            "tours et regagne\n"
            "PV et statut."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = ITEM_NAME("CT45"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Le genre opposé a\n"
            "moins de chances\n"
            "d'attaquer."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THIEF] =
    {
        .name = ITEM_NAME("CT46"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Peut voler l'objet\n"
            "tenu par l'ennemi\n"
            "pendant l'attaque."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = ITEM_NAME("CT47"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Frappe l'ennemi en\n"
            "déployant ses ailes\n"
            "d'acier."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = ITEM_NAME("CT48"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Le lanceur et la\n"
            "cible échangent\n"
            "leurs capacités."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = ITEM_NAME("CT49"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Vole les effets de\n"
            "la prochaine\n"
            "attaque ennemie."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = ITEM_NAME("CT50"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attaque à pleine\n"
            "puissance, mais\n"
            "baisse Atq. Spe."
        ),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM51] = // Roost
    {
        .name = ITEM_NAME("TM51"),
        .price = 3000,
        .description = COMPOUND_STRING("Restaure la moitié\ndes PV max du\nlanceur."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM52] = // Focus Blast
    {
        .name = ITEM_NAME("TM52"),
        .price = 10000,
        .description = COMPOUND_STRING("Frappe à pleine\npuissance. Peut baisser\nla Déf. Spé. ennemie."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM53] = // Energy Ball
    {
        .name = ITEM_NAME("TM53"),
        .price = 3000,
        .description = COMPOUND_STRING("Puise dans la nature.\nPeut baisser la\nDéf. Spé. ennemie."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM54] = // False Swipe
    {
        .name = ITEM_NAME("TM54"),
        .price = 3000,
        .description = COMPOUND_STRING("Laisse toujours\nau moins 1 PV\nà l'ennemi."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM55] = // Brine
    {
        .name = ITEM_NAME("TM55"),
        .price = 3000,
        .description = COMPOUND_STRING("Double les dégâts si\nl'ennemi a la moitié\nde ses PV ou moins."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM56] = // Fling
    {
        .name = ITEM_NAME("TM56"),
        .price = 3000,
        .description = COMPOUND_STRING("Son type et sa force\ndépendent de l'objet\ntenu par le lanceur."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM57] = // Charge Beam
    {
        .name = ITEM_NAME("TM57"),
        .price = 3000,
        .description = COMPOUND_STRING("Un rayon électrique\npouvant monter\nl'Atq. Spé."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM58] = // Endure
    {
        .name = ITEM_NAME("TM58"),
        .price = 3000,
        .description = COMPOUND_STRING("Endure les attaques\ndurant 1 tour avec\nau moins 1 PV."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM59] = // Dragon Pulse
    {
        .name = ITEM_NAME("TM59"),
        .price = 3000,
        .description = COMPOUND_STRING("Produit une onde de\nchoc qui blesse\nl'ennemi."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM60] = // Drain Punch
    {
        .name = ITEM_NAME("TM60"),
        .price = 3000,
        .description = COMPOUND_STRING("Rend au lanceur la\nmoitié des dégâts\ninfligés."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM61] = // Will-O-Wisp
    {
        .name = ITEM_NAME("TM61"),
        .price = 3000,
        .description = COMPOUND_STRING("Inflige une brûlure\nà l'ennemi avec un\nfeu intense."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM62] = // Silver Wind
    {
        .name = ITEM_NAME("TM62"),
        .price = 3000,
        .description = COMPOUND_STRING("Une attaque poudreuse\npouvant monter\ntoutes les stats."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM63] = // Embargo
    {
        .name = ITEM_NAME("TM63"),
        .price = 3000,
        .description = COMPOUND_STRING("Empêche l'ennemi\nd'utiliser le moindre\nobjet."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM64] = // Explosion
    {
        .name = ITEM_NAME("TM64"),
        .price = 3000,
        .description = COMPOUND_STRING("Inflige d'énormes\ndégâts mais met le\nlanceur K.O."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM65] = // Shadow Claw
    {
        .name = ITEM_NAME("TM65"),
        .price = 3000,
        .description = COMPOUND_STRING("Frappe d'une griffe\nd'ombre. Taux de\ncritique élevé."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM66] = // Payback
    {
        .name = ITEM_NAME("TM66"),
        .price = 3000,
        .description = COMPOUND_STRING("Gagne en puissance\nsi le lanceur agit\nen dernier."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM67] = // Recycle
    {
        .name = ITEM_NAME("TM67"),
        .price = 3000,
        .description = COMPOUND_STRING("Recycle un objet\nconsommé afin de le\nréutiliser."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM68] = // Giga Impact
    {
        .name = ITEM_NAME("TM68"),
        .price = 3000,
        .description = COMPOUND_STRING("Très puissante, mais\nimmobilise le lanceur\nau tour suivant."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM69] = // Rock Polish
    {
        .name = ITEM_NAME("TM69"),
        .price = 3000,
        .description = COMPOUND_STRING("Polit son corps pour\nbeaucoup monter\nla Vitesse."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

#if IS_HNS
    [ITEM_TM70] = // Rock Climb
    {
        .name = ITEM_NAME("TM70"),
        .price = 3000,
        .description = COMPOUND_STRING("Une charge brutale\npouvant rendre\nl'ennemi confus."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#else
    [ITEM_TM70] = // Flash
    {
        .name = ITEM_NAME("TM70"),
        .price = 3000,
        .description = COMPOUND_STRING("Libère une vive\nlumière qui baisse\nla Précision."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#endif

    [ITEM_TM71] = // Stone Edge
    {
        .name = ITEM_NAME("TM71"),
        .price = 3000,
        .description = COMPOUND_STRING("Transperce de pierres.\nTaux de critique\nélevé."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM72] = // Avalanche
    {
        .name = ITEM_NAME("TM72"),
        .price = 3000,
        .description = COMPOUND_STRING("Agit en dernier et\ngagne en puissance\nsi le lanceur est touché."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM73] = // Thunder Wave
    {
        .name = ITEM_NAME("TM73"),
        .price = 3000,
        .description = COMPOUND_STRING("Une faible décharge\nqui paralyse\nl'ennemi."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM74] = // Gyro Ball
    {
        .name = ITEM_NAME("TM74"),
        .price = 3000,
        .description = COMPOUND_STRING("Une rotation rapide,\nplus forte sur les\nennemis rapides."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM75] = // Swords Dance
    {
        .name = ITEM_NAME("TM75"),
        .price = 3000,
        .description = COMPOUND_STRING("Une danse guerrière\nqui monte beaucoup\nl'Attaque."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM76] = // Stealth Rock
    {
        .name = ITEM_NAME("TM76"),
        .price = 3000,
        .description = COMPOUND_STRING("Des pierres flottantes\nblessent les ennemis\nentrant au combat."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM77] = // Psych Up
    {
        .name = ITEM_NAME("TM77"),
        .price = 3000,
        .description = COMPOUND_STRING("Copie les changements\nde stats de l'ennemi\nsur le lanceur."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM78] = // Captivate
    {
        .name = ITEM_NAME("TM78"),
        .price = 3000,
        .description = COMPOUND_STRING("Baisse beaucoup\nl'Atq. Spé. d'un ennemi\nde sexe opposé."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM79] = // Dark Pulse
    {
        .name = ITEM_NAME("TM79"),
        .price = 3000,
        .description = COMPOUND_STRING("Attaque avec une aura\naffreuse pouvant\neffrayer l'ennemi."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM80] = // Rock Slide
    {
        .name = ITEM_NAME("TM80"),
        .price = 3000,
        .description = COMPOUND_STRING("Lance de gros rochers\npouvant effrayer\nl'ennemi."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM81] = // X-Scissor
    {
        .name = ITEM_NAME("TM81"),
        .price = 3000,
        .description = COMPOUND_STRING("Lacère l'ennemi avec\ndes faux ou griffes\ncroisées."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM82] = // Sleep Talk
    {
        .name = ITEM_NAME("TM82"),
        .price = 3000,
        .description = COMPOUND_STRING("Utilise au hasard une\ncapacité disponible\npendant le sommeil."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM83] = // Natural Gift
    {
        .name = ITEM_NAME("TM83"),
        .price = 10000,
        .description = COMPOUND_STRING("Son type et sa force\ndépendent de la Baie\ntenue par le lanceur."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM84] = // Poison Jab
    {
        .name = ITEM_NAME("TM84"),
        .price = 3000,
        .description = COMPOUND_STRING("Une attaque perforante\npouvant empoisonner\nl'ennemi."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM85] = // Dream Eater
    {
        .name = ITEM_NAME("TM85"),
        .price = 3000,
        .description = COMPOUND_STRING("Récupère la moitié\ndes dégâts infligés\nà l'ennemi endormi."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM86] = // Grass Knot
    {
        .name = ITEM_NAME("TM86"),
        .price = 3000,
        .description = COMPOUND_STRING("Une attaque qui blesse\ndavantage les ennemis\nles plus lourds."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM87] = // Swagger
    {
        .name = ITEM_NAME("TM87"),
        .price = 3000,
        .description = COMPOUND_STRING("Rend l'ennemi confus,\nmais monte beaucoup\nson Attaque."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM88] = // Pluck
    {
        .name = ITEM_NAME("TM88"),
        .price = 3000,
        .description = COMPOUND_STRING("Mange la Baie tenue\npar l'ennemi et\nprofite de son effet."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM89] = // U-turn
    {
        .name = ITEM_NAME("TM89"),
        .price = 3000,
        .description = COMPOUND_STRING("Inflige des dégâts\npuis remplace le\nlanceur."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM90] = // Substitute
    {
        .name = ITEM_NAME("TM90"),
        .price = 3000,
        .description = COMPOUND_STRING("Crée un clone avec\nun quart des PV max\ndu lanceur."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM91] = // Flash Cannon
    {
        .name = ITEM_NAME("TM91"),
        .price = 3000,
        .description = COMPOUND_STRING("Libère une lumière\npouvant baisser\nla Déf. Spé."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM92] = // Trick Room
    {
        .name = ITEM_NAME("TM92"),
        .price = 3000,
        .description = COMPOUND_STRING("Les POKéMON lents\nagissent d'abord\npendant 5 tours."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM93] =
    {
        .name = ITEM_NAME("CT93"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Une charge électrique\n"
            "violente qui blesse aussi\n"
            "légèrement le lanceur."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM94] =
    {
        .name = ITEM_NAME("CT94"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Le lanceur retient ses\n"
            "coups pour que l'ennemi\n"
            "garde au moins 1 PV et ne\n"
            "tombe pas K.O."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM95] =
    {
        .name = ITEM_NAME("CT95"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Le lanceur hurle sur\n"
            "l'ennemi. Baisse l'Atq. Spé. de\n"
            "l'ennemi."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM96] =
    {
        .name = ITEM_NAME("CT96"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Une attaque qui tire sa\n"
            "force de la nature. Son\n"
            "type varie selon le terrain."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM97] =
    {
        .name = ITEM_NAME("CT97"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Le lanceur pivote pour\n"
            "prendre de l'élan et infliger\n"
            "des dégâts."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM98] =
    {
        .name = ITEM_NAME("CT98"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Le lanceur charge l'ennemi à\n"
            "une vitesse remarquable, ce\n"
            "qui peut l'apeurer."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM99] =
    {
        .name = ITEM_NAME("CT99"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Libère une puissante\n"
            "décharge lumineuse qui\n"
            "inflige des dégâts à l'ennemi."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM100] =
    {
        .name = ITEM_NAME("CT100"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Dévoile des secrets à\n"
            "l'ennemi qui perd sa\n"
            "concentration et voit son\n"
            "Attaque Spéciale diminuer."
        ), // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_CUT] =
    {
        .name = ITEM_NAME("CS01"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Coupe l'ennemi avec des\n"
            "lames, des griffes, etc."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLY] =
    {
        .name = ITEM_NAME("CS02"),
        .price = 0,
        .description = COMPOUND_STRING(
            "S'envole au premier\n"
            "tour et frappe au\n"
            "second."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_SURF] =
    {
        .name = ITEM_NAME("CS03"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Crée une énorme\n"
            "vague qui s'écrase\n"
            "sur l'ennemi."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_STRENGTH] =
    {
        .name = ITEM_NAME("CS04"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Accumule de la\n"
            "puissance, puis\n"
            "frappe l'ennemi."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLASH] =
    {
        .name = ITEM_NAME("CS05"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Explosion\n"
            "lumineuse baissant\n"
            "la précision."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .name = ITEM_NAME("CS06"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une attaque\n"
            "puissante qui peut\n"
            "baisser la Défense."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_WATERFALL] =
    {
        .name = ITEM_NAME("CS07"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Attaque rapide qui\n"
            "permet de franchir\n"
            "des cascades."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

#if IS_HNS
    [ITEM_HM_WHIRLPOOL] =
    {
        .name = ITEM_NAME("CS08"),
        .price = 0,
        .description = COMPOUND_STRING("Piège l'ennemi dans\nun violent\ntourbillon d'eau."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#else
    [ITEM_HM_DIVE] =
    {
        .name = ITEM_NAME("CS08"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Plonge en apnée au\n"
            "premier tour et\n"
            "frappe au second."
        ),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#endif


// Charms

    [ITEM_OVAL_CHARM] =
    {
        .name = ITEM_NAME("CHARME OVALE"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un mystérieux charme rond\n"
            "qui permet de trouver plus\n"
            "facilement des Œufs à la\n"
            "Pension Pokémon."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OvalCharm,
        .iconPalette = gItemIconPalette_OvalCharm,
    },

    [ITEM_SHINY_CHARM] =
    {
        .name = ITEM_NAME("CHARME CHROMA"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un mystérieux charme\n"
            "scintillant qui facilite la\n"
            "rencontre avec les Pokémon\n"
            "chromatiques."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ShinyCharm,
        .iconPalette = gItemIconPalette_ShinyCharm,
    },

    [ITEM_CATCHING_CHARM] =
    {
        .name = ITEM_NAME("CHARME STABILITÉ"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ce porte-bonheur permet de\n"
            "stabiliser les Poké Balls et\n"
            "augmente les chances de\n"
            "réaliser une capture\n"
            "critique."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CatchingCharm,
        .iconPalette = gItemIconPalette_CatchingCharm,
    },

    [ITEM_EXP_CHARM] =
    {
        .name = ITEM_NAME("CHARME EXP"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un charme permettant aux\n"
            "Pokémon de gagner\n"
            "davantage de Points\n"
            "d'Expérience. Il renferme\n"
            "une espèce de mécanisme."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ExpCharm,
        .iconPalette = gItemIconPalette_ExpCharm,
    },

// Form-changing Key Items

    [ITEM_ROTOM_CATALOG] =
    {
        .name = ITEM_NAME("MOTI-CATALOGUE"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un catalogue présentant\n"
            "divers appareils ménagers\n"
            "que Motisma apprécie. À\n"
            "utiliser pour faire entrer\n"
            "Motisma dans ces appareils\n"
            "ou l'en faire sortir."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RotomCatalog,
        .iconPic = gItemIcon_RotomCatalog,
        .iconPalette = gItemIconPalette_RotomCatalog,
    },

    [ITEM_GRACIDEA] =
    {
        .name = ITEM_NAME("GRACIDÉE"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Fleur que l'on offre en gage\n"
            "de reconnaissance,\n"
            "notamment à l'occasion d'un\n"
            "anniversaire."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Gracidea,
        .iconPalette = gItemIconPalette_Gracidea,
    },

    [ITEM_REVEAL_GLASS] =
    {
        .name = ITEM_NAME("MIROIR SACRÉ"),
        .pluralName = ITEM_PLURAL_NAME("MIROIRS SACRÉS"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un mystérieux miroir qui, en\n"
            "reflétant la vérité, permet\n"
            "de redonner à un Pokémon\n"
            "sa forme originelle."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_RevealGlass,
        .iconPalette = gItemIconPalette_RevealGlass,
    },

    [ITEM_DNA_SPLICERS] =
    {
        .name = ITEM_NAME("POINTEAU ADN"),
        .pluralName = ITEM_PLURAL_NAME("POINTEURS ADN"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un outil qui permet la\n"
            "fusiorption de Kyurem et\n"
            "d'un autre Pokémon avec\n"
            "lequel il ne faisait qu'un à\n"
            "l'origine."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_DNASplicers,
        .iconPalette = gItemIconPalette_DNASplicers,
    },

    [ITEM_ZYGARDE_CUBE] =
    {
        .name = ITEM_NAME("BOÎTE ZYGARDE"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un artefact dans lequel les\n"
            "Cellules et Cœurs de\n"
            "Zygarde ont été rassemblés.\n"
            "Il permet à Zygarde de\n"
            "changer de forme."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ZygardeCube,
        .iconPic = gItemIcon_ZygardeCube,
        .iconPalette = gItemIconPalette_ZygardeCube,
    },

    [ITEM_PRISON_BOTTLE] =
    {
        .name = ITEM_NAME("VASE SCELLÉ"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Récipient utilisé il\n"
            "y a fort longtemps\n"
            "pour sceller le\n"
            "pouvoir d'un\n"
            "certain Pokémon."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_PrisonBottle,
        .iconPalette = gItemIconPalette_PrisonBottle,
    },

    [ITEM_N_SOLARIZER] =
    {
        .name = ITEM_NAME("NECROSOL"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un appareil permettant à un\n"
            "Necrozma assoiffé de\n"
            "lumière de fusionner avec\n"
            "Solgaleo."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NSolarizer,
    },

    [ITEM_N_LUNARIZER] =
    {
        .name = ITEM_NAME("NECROLUNA"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un appareil permettant à un\n"
            "Necrozma assoiffé de\n"
            "lumière de fusionner avec\n"
            "Lunala."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NLunarizer,
    },

    [ITEM_REINS_OF_UNITY] =
    {
        .name = ITEM_NAME("RÊNES DE L’UNITÉ"),
        .pluralName = ITEM_PLURAL_NAME("RÊNES DE L'UNITÉ"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Une courroie faite d'un\n"
            "tissu qui scintille à la\n"
            "lumière. Les humains en\n"
            "offraient autrefois au\n"
            "Seigneur des récoltes en\n"
            "gage de leur gratitude."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_ReinsOfUnity,
        .iconPalette = gItemIconPalette_ReinsOfUnity,
    },

// Battle Mechanic Key Items

    [ITEM_MEGA_RING] =
    {
        .name = ITEM_NAME("MÉGA-ANNEAU"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un anneau aux pouvoirs\n"
            "mystérieux permettant à un\n"
            "Pokémon de méga-évoluer au\n"
            "combat s'il tient la bonne\n"
            "Méga-Gemme."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MegaRing,
        .iconPalette = gItemIconPalette_MegaRing,
    },

    [ITEM_Z_POWER_RING] =
    {
        .name = ITEM_NAME("SUPER BRACELET Z"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Un bracelet mystérieux\n"
            "utilisant la force vitale du\n"
            "Dresseur pour permettre à\n"
            "ses Pokémon d'utiliser la\n"
            "Force Z."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ZPowerRing,
        .iconPalette = gItemIconPalette_ZPowerRing,
    },

    [ITEM_DYNAMAX_BAND] =
    {
        .name = ITEM_NAME("POIGNET DYNAMAX"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Quand elle se trouve près\n"
            "d'une Source d'Énergie,\n"
            "l'Étoile Vœu sertie dans ce\n"
            "poignet brille, ce qui permet\n"
            "de donner à un Pokémon sa\n"
            "forme Dynamax."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DynamaxBand,
        .iconPalette = gItemIconPalette_DynamaxBand,
    },

// Misc. Key Items

    [ITEM_BICYCLE] =
    {
        .name = ITEM_NAME("BICYCLETTE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une bicyclette pliante.\n"
            "À l'arrêt, appuyez sur R\n"
            "pour changer de vitesse."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = IS_HNS ? ACRO_BIKE : STANDARD_BIKE,
        .iconPic = gItemIcon_Bicycle,
        .iconPalette = gItemIconPalette_Bicycle,
    },

    [ITEM_MACH_BIKE] =
    {
        .name = ITEM_NAME("VÉLO DE COURSE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un vélo pliable qui roule\n"
            "jusqu'à deux fois plus vite\n"
            "qu'une bicyclette ordinaire."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
        .iconPic = gItemIcon_MachBike,
        .iconPalette = gItemIconPalette_MachBike,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = ITEM_NAME("VÉLO CROSS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un vélo pliable qui\n"
            "permet de bondir et\n"
            "de rouler sur la\n"
            "roue arrière."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
        .iconPic = gItemIcon_AcroBike,
        .iconPalette = gItemIconPalette_AcroBike,
    },

    [ITEM_OLD_ROD] =
    {
        .name = ITEM_NAME("CANNE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une vieille canne usée.\n"
            "Utilisez-la pour pêcher des\n"
            "Pokémon sauvages dans les\n"
            "points d'eau."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
        .iconPic = gItemIcon_OldRod,
        .iconPalette = gItemIconPalette_OldRod,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = ITEM_NAME("SUPER CANNE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une canne neuve et de\n"
            "bonne qualité. Utilisez-la\n"
            "pour pêcher des Pokémon\n"
            "sauvages dans les points\n"
            "d'eau."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
        .iconPic = gItemIcon_GoodRod,
        .iconPalette = gItemIconPalette_GoodRod,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = ITEM_NAME("MÉGA CANNE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une canne à pêche\n"
            "ultramoderne. Utilisez-la\n"
            "pour pêcher des Pokémon\n"
            "sauvages dans les points\n"
            "d'eau."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
        .iconPic = gItemIcon_SuperRod,
        .iconPalette = gItemIconPalette_SuperRod,
    },

    [ITEM_DOWSING_MACHINE] =
    {
        .name = ITEM_NAME("CHERCH’OBJET"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un appareil high-tech qui\n"
            "indique l'emplacement des\n"
            "objets invisibles. Il se\n"
            "porte sur la tête."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
        .iconPic = gItemIcon_DowsingMachine,
        .iconPalette = gItemIconPalette_DowsingMachine,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = ITEM_NAME("CARTE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une carte très pratique\n"
            "pouvant être consultée\n"
            "n'importe quand. Elle indique\n"
            "la position actuelle."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TownMap,
        .iconPic = gItemIcon_TownMap,
        .iconPalette = gItemIconPalette_TownMap,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = ITEM_NAME("CHERCH’COMBAT"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un appareil indiquant les\n"
            "Dresseurs prêts à se\n"
            "battre. La batterie se\n"
            "recharge quand l'on marche."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
    #if I_VS_SEEKER_CHARGING != 0
        .fieldUseFunc = FieldUseFunc_VsSeeker,
    #else
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    #endif
        .iconPic = gItemIcon_VsSeeker,
        .iconPalette = gItemIconPalette_VsSeeker,
    },

    [ITEM_TM_CASE] =
    {
        .name = ITEM_NAME("BOÎTE CT"),
        .price = 0,
        .description = COMPOUND_STRING("Une boîte pratique\nqui contient les\nCT et les CS."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TMCase,
        .iconPalette = gItemIconPalette_TMCase,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = ITEM_NAME("SAC À BAIES"),
        .pluralName = ITEM_PLURAL_NAME("SACS À BAIES"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un petit sac pour\n"
            "transporter les\n"
            "Baies."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BerryPouch,
        .iconPalette = gItemIconPalette_BerryPouch,
    },

    [ITEM_POKEMON_BOX_LINK] =
    {
        .name = ITEM_NAME("BOÎTE POKÉMON"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Permet d'accéder aux\n"
            "Boîtes PC du Centre\n"
            "Pokémon à tout moment pour\n"
            "y déposer ou en retirer des\n"
            "Pokémon."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_PokemonBoxLink,
        .iconPic = gItemIcon_PokemonBoxLink,
        .iconPalette = gItemIconPalette_PokemonBoxLink,
    },

    [ITEM_COIN_CASE] =
    {
        .name = ITEM_NAME("BOÎTE JETONS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une boîte pour conserver\n"
            "les Jetons obtenus au\n"
            "Casino. Peut contenir\n"
            "jusqu'à 50 000 Jetons."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
        .iconPic = gItemIcon_CoinCase,
        .iconPalette = gItemIconPalette_CoinCase,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = ITEM_NAME("POT POUDRE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un pot pour\n"
            "conserver la\n"
            "Poudre Baie."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
        .iconPic = gItemIcon_PowderJar,
        .iconPalette = gItemIconPalette_PowderJar,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = ITEM_NAME("WAILMERROSOIR"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Sert à arroser les\n"
            "Baies plantées\n"
            "dans le sol."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
        .iconPic = gItemIcon_WailmerPail,
        .iconPalette = gItemIconPalette_WailmerPail,
    },

    [ITEM_POKE_RADAR] =
    {
        .name = ITEM_NAME("POKÉ RADAR"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Objet permettant de\n"
            "trouver les Pokémon qui se\n"
            "cachent dans l'herbe. Se\n"
            "recharge quand vous\n"
            "marchez."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .iconPic = gItemIcon_PokeRadar,
        .iconPalette = gItemIconPalette_PokeRadar,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = ITEM_NAME("BOÎTE POKÉBLOCS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Boîte pour ranger les\n"
            "{POKEBLOCK}S créés avec le\n"
            "Mixeur."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
        .iconPic = gItemIcon_PokeblockCase,
        .iconPalette = gItemIconPalette_PokeblockCase,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = ITEM_NAME("SAC À SUIE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un sac utilisé pour\n"
            "ramasser les\n"
            "cendres\n"
            "volcaniques\n"
            "accumulées au sol."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SootSack,
        .iconPalette = gItemIconPalette_SootSack,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = ITEM_NAME("POKÉ FLÛTE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une flûte au son si\n"
            "particulier qu'elle permet de\n"
            "réveiller les Pokémon les\n"
            "plus profondément endormis."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeFlute,
        .battleUsage = EFFECT_ITEM_USE_POKE_FLUTE,
        .iconPic = gItemIcon_PokeFlute,
        .iconPalette = gItemIconPalette_PokeFlute,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = ITEM_NAME("MEMORYDEX"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Stocke les infos\n"
            "sur les gens\n"
            "importants."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_FameChecker,
        .iconPalette = gItemIconPalette_FameChecker,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = ITEM_NAME("TV ABC"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un programme qui\n"
            "donne des conseils\n"
            "aux Dresseurs."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeachyTV,
        .iconPalette = gItemIconPalette_TeachyTV,
    },

// Story Key Items

    [ITEM_SS_TICKET] =
    {
        .name = ITEM_NAME("PASSE BATEAU"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un ticket nécessaire pour\n"
            "embarquer sur le ferry\n"
            "L'Aquaria. Un bateau est\n"
            "dessiné dessus."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SSTicket,
        .iconPalette = gItemIconPalette_SSTicket,
    },

    [ITEM_EON_TICKET] =
    {
        .name = ITEM_NAME("PASSE ÉON"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un billet de ferry pour l'Île\n"
            "du Sud. Norman, le Champion\n"
            "de l'Arène de Clémenti-Ville,\n"
            "semble savoir quelque chose\n"
            "à son sujet."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
        .iconPic = gItemIcon_EonTicket,
        .iconPalette = gItemIconPalette_EonTicket,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = ITEM_NAME("TICKETMYSTIK"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Le ticket requis\n"
            "pour aller au Roc\n"
            "Nombri."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MysticTicket,
        .iconPalette = gItemIconPalette_MysticTicket,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = ITEM_NAME("TICKETAURORA"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Le ticket requis\n"
            "pour aller sur l'Ile\n"
            "Aurore."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_AuroraTicket,
        .iconPalette = gItemIconPalette_AuroraTicket,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = ITEM_NAME("VIEILLECARTE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une vieille carte\n"
            "montrant la route\n"
            "vers une île."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OldSeaMap,
        .iconPalette = gItemIconPalette_OldSeaMap,
    },

    [ITEM_LETTER] =
    {
        .name = ITEM_NAME("LETTRE À PIERRE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une lettre confiée\n"
            "par le directeur de\n"
            "Devon."
        ),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Letter,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_DEVON_PARTS] =
    {
        .name = ITEM_NAME("PACK DEVON"),
        .pluralName = ITEM_PLURAL_NAME("PACKS DEVON"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une valise qui\n"
            "contient des\n"
            "pièces mécaniques\n"
            "fabriquées par la\n"
            "société Devon."
        ),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonParts,
        .iconPalette = gItemIconPalette_DevonParts,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = ITEM_NAME("LUNETTES SABLE"),
        .pluralName = ITEM_PLURAL_NAME("LUNETTES SABLE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une paire de lunettes bien\n"
            "pratique qui protège les\n"
            "yeux en cas de tempête de\n"
            "sable dans le désert."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoGoggles,
        .iconPalette = gItemIconPalette_GoGoggles,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = ITEM_NAME("DEVON SCOPE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ce produit en série limitée\n"
            "de Devon émet un signal\n"
            "sonore pour signaler la\n"
            "présence de Pokémon\n"
            "invisibles."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonScope,
        .iconPalette = gItemIconPalette_DevonScope,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = ITEM_NAME("CLÉ SOUS-SOL"),
        .price = 0,
#if IS_HNS
        .description = COMPOUND_STRING("La clé du SOUTERRAIN\nde DOUBLONVILLE."),
#else
        .description = COMPOUND_STRING("La clé de NEW\nLAVANDIA, sous\nLAVANDIA."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BasementKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_SCANNER] =
    {
        .name = ITEM_NAME("SCANNER"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un objet trouvé à\n"
            "Lavandia Sea."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Scanner,
        .iconPalette = gItemIconPalette_Scanner,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = ITEM_NAME("CLÉ STOCKAGE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "La clé de\n"
            "l'entrepôt de la\n"
            "Team Galaxie situé\n"
            "à la périphérie de\n"
            "Voilaroc."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StorageKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_KEY_TO_ROOM_1] =
    {
        .name = ITEM_NAME("CLÉ SALLE 1"),
        .pluralName = ITEM_PLURAL_NAME("CLÉS SALLE 1"),
        .price = 0,
        .description = COMPOUND_STRING(
            "La clé d'une salle\n"
            "de Lavandia Sea."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom1,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_2] =
    {
        .name = ITEM_NAME("CLÉ SALLE 2"),
        .pluralName = ITEM_PLURAL_NAME("CLÉS SALLE 2"),
        .price = 0,
        .description = COMPOUND_STRING(
            "La clé d'une salle\n"
            "de Lavandia Sea."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom2,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_4] =
    {
        .name = ITEM_NAME("CLÉ SALLE 4"),
        .pluralName = ITEM_PLURAL_NAME("CLÉS SALLE 4"),
        .price = 0,
        .description = COMPOUND_STRING(
            "La clé d'une salle\n"
            "de Lavandia Sea."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom4,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_6] =
    {
        .name = ITEM_NAME("CLÉ SALLE 6"),
        .pluralName = ITEM_PLURAL_NAME("CLÉS SALLE 6"),
        .price = 0,
        .description = COMPOUND_STRING(
            "La clé d'une salle\n"
            "de Lavandia Sea."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom6,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_METEORITE] =
    {
        .name = ITEM_NAME("MÉTÉORITE"),
        .price = 0,
#if IS_HNS
        .description = COMPOUND_STRING(
            "Une météorite trouvée\n"
            "sur l'ÎLE AURORE."),
#else
        .description = COMPOUND_STRING(
            "Une météorite trouvée\n"
            "au SITE MÉTÉORE."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Meteorite,
        .iconPalette = gItemIconPalette_Meteorite,
    },

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = ITEM_NAME("SCEAU MAGMA"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un objet portant le sceau\n"
            "de la Team Magma."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MagmaEmblem,
        .iconPalette = gItemIconPalette_MagmaEmblem,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = ITEM_NAME("PASSE CONCOURS"),
        .pluralName = ITEM_PLURAL_NAME("PASSES CONCOURS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "La carte requise\n"
            "pour participer aux\n"
            "Concours Pokémon.\n"
            "Il y a un ruban\n"
            "dessiné dessus."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ContestPass,
        .iconPalette = gItemIconPalette_ContestPass,
    },

    [ITEM_PARCEL] =
    {
        .name = ITEM_NAME("COLIS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Paquet qu'on vous a\n"
            "confié. Vous devez\n"
            "le remettre à votre\n"
            "ami d'enfance qui a\n"
            "quitté Bonaugure."
        ),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Parcel,
        .iconPalette = gItemIconPalette_Parcel,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = ITEM_NAME("CLÉ SECRÈTE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Clé destinée à une serrure\n"
            "très complexe. Ouvre une\n"
            "porte en transmettant un\n"
            "signal électrique."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SecretKey,
        .iconPalette = gItemIconPalette_SecretKey,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = ITEM_NAME("BON COMMANDE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Bon à échanger\n"
            "contre un vélo aux\n"
            "Cycles A Gogo."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BikeVoucher,
        .iconPalette = gItemIconPalette_BikeVoucher,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = ITEM_NAME("DENTIER EN OR"),
        .pluralName = ITEM_PLURAL_NAME("DENTIERS EN OR"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un dentier en or perdu par\n"
            "le directeur du Parc Safari.\n"
            "Il lui donne un sourire\n"
            "étincelant."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoldTeeth,
        .iconPalette = gItemIconPalette_GoldTeeth,
    },

    [ITEM_CARD_KEY] =
    {
        .name = ITEM_NAME("CARTE MAGNÉTIQUE"),
        .price = 0,
#if IS_HNS
        .description = COMPOUND_STRING("Une carte-clé ouvrant\nles portes de la\nTOUR RADIO."),
#else
        .description = COMPOUND_STRING("Une carte-clé ouvrant\nles bureaux de la\nSYLPHE SARL."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CardKey,
        .iconPalette = gItemIconPalette_CardKey,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = ITEM_NAME("CLÉ ASCENSEUR"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une clé activant l'ascenseur\n"
            "du Repaire de la Team\n"
            "Rocket. Elle porte la marque\n"
            "de l'organisation."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LiftKey,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = ITEM_NAME("SCOPE SYLPHE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un appareil permettant de\n"
            "voir les Pokémon invisibles.\n"
            "Il est fabriqué par la\n"
            "Sylphe SARL."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SilphScope,
        .iconPalette = gItemIconPalette_SilphScope,
    },

    [ITEM_TRI_PASS] =
    {
        .name = ITEM_NAME("TRI-PASSE"),
        .pluralName = ITEM_PLURAL_NAME("TRI-PASSES"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un passe pour\n"
            "accéder aux Iles 1,\n"
            "2 et 3."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TriPass,
        .iconPalette = gItemIconPalette_TriPass,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = ITEM_NAME("PASSE PRISME"),
        .pluralName = ITEM_PLURAL_NAME("PASSES PRISME"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Passe pour le ferry\n"
            "de Carmin Sur Mer\n"
            "aux Iles Sevii."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RainbowPass,
        .iconPalette = gItemIconPalette_RainbowPass,
    },

    [ITEM_TEA] =
    {
        .name = ITEM_NAME("THÉ"),
        .pluralName = ITEM_PLURAL_NAME("THÉS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un thé aromatique\n"
            "légèrement amer. Il\n"
            "a des vertus\n"
            "désaltérantes."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Tea,
        .iconPalette = gItemIconPalette_Tea,
    },

    [ITEM_RUBY] =
    {
        .name = ITEM_NAME("RUBIS"),
        .pluralName = ITEM_PLURAL_NAME("RUBIS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une pierre rouge\n"
            "qui symbolise la\n"
            "passion."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Ruby,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = ITEM_NAME("SAPHIR"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une pierre bleue\n"
            "qui symbolise\n"
            "l'honnêteté."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Sapphire,
    },

    [ITEM_ABILITY_SHIELD] =
    {
        .name = ITEM_NAME("GARDE-TALENT"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_ABILITY_SHIELD,
        .description = COMPOUND_STRING("Empêche le talent du\nporteur d'être\nmodifié."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbilityShield,
        .iconPalette = gItemIconPalette_AbilityShield,
    },

// GEN 9 ITEMS

    [ITEM_CLEAR_AMULET] =
    {
        .name = ITEM_NAME("TALISMAN SAIN"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_CLEAR_AMULET,
        .description = COMPOUND_STRING(
            "Un rouleau mystérieux\n"
            "pouvant faire évoluer un\n"
            "certain Pokémon. Tous les\n"
            "secrets de la voie des\n"
            "Ténèbres y sont inscrits."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ClearAmulet,
        .iconPalette = gItemIconPalette_ClearAmulet,
    },

    [ITEM_PUNCHING_GLOVE] =
    {
        .name = ITEM_NAME("GANT DE BOXE"),
        .price = 15000,
        .holdEffect = HOLD_EFFECT_PUNCHING_GLOVE,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PunchingGlove,
        .iconPalette = gItemIconPalette_PunchingGlove,
    },

    [ITEM_COVERT_CLOAK] =
    {
        .name = ITEM_NAME("CAPE OBSCURE"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_COVERT_CLOAK,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CovertCloak,
        .iconPalette = gItemIconPalette_CovertCloak,
    },

    [ITEM_LOADED_DICE] =
    {
        .name = ITEM_NAME("DÉ PIPÉ"),
        .pluralName = ITEM_PLURAL_NAME("DÉS PIPÉS"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_LOADED_DICE,
        .description = COMPOUND_STRING(
            "Une armure mystérieuse\n"
            "pouvant faire évoluer un\n"
            "certain Pokémon. Une grande\n"
            "rancune y est enfermée."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LoadedDice,
        .iconPalette = gItemIconPalette_LoadedDice,
    },

    [ITEM_AUSPICIOUS_ARMOR] =
    {
        .name = ITEM_NAME("ARMURE FORTUNE"),
        .price = 3000,
        .description = COMPOUND_STRING("Une armure animée de\nvœux propices. Provoque\nune évolution."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_AuspiciousArmor,
        .iconPalette = gItemIconPalette_AuspiciousArmor,
    },

    [ITEM_BOOSTER_ENERGY] =
    {
        .name = ITEM_NAME("ÉNERGIE BOOSTER"),
        .pluralName = ITEM_PLURAL_NAME("ÉNERGIE BOOSTERS"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_BOOSTER_ENERGY,
        .description = COMPOUND_STRING("Une énergie condensée\nrenforçant certains\nPOKéMON Paradoxes."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BoosterEnergy,
        .iconPalette = gItemIconPalette_BoosterEnergy,
    },

    [ITEM_BIG_BAMBOO_SHOOT] =
    {
        .name = ITEM_NAME("GROS BAMBOU"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Un orbe qui renferme le\n"
            "pouvoir de la cristallisation.\n"
            "Quand il est chargé\n"
            "d'énergie, il permet à un\n"
            "Pokémon de se\n"
            "téracristalliser."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigBambooShoot,
        .iconPalette = gItemIconPalette_BigBambooShoot,
    },

    [ITEM_GIMMIGHOUL_COIN] =
    {
        .name = ITEM_NAME("PIÈCE DE MORDUDOR"),
        .price = 400,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GimmighoulCoin,
        .iconPalette = gItemIconPalette_GimmighoulCoin,
    },

    [ITEM_LEADERS_CREST] =
    {
        .name = ITEM_NAME("EMBLÈME DU GÉNÉRAL"),
        .price = 3000,
        .description = COMPOUND_STRING("Un fragment d'une\nancienne lame, porté\npar certains Scalproie."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LeadersCrest,
        .iconPalette = gItemIconPalette_LeadersCrest,
    },

    [ITEM_MALICIOUS_ARMOR] =
    {
        .name = ITEM_NAME("ARMURE RANCUNE"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Un portefeuille oublié par\n"
            "Kombu, le Champion de l'Arène\n"
            "de Jarramanca. Vous devez\n"
            "vous rendre au marché de\n"
            "Porto Marinada pour le lui\n"
            "rendre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MaliciousArmor,
        .iconPalette = gItemIconPalette_MaliciousArmor,
    },

    [ITEM_MIRROR_HERB] =
    {
        .name = ITEM_NAME("FEUILLE COPIEUSE"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_MIRROR_HERB,
        .description = COMPOUND_STRING(
            "Un rouleau mystérieux\n"
            "pouvant faire évoluer un\n"
            "certain Pokémon. Tous les\n"
            "secrets de la voie de l'Eau y\n"
            "sont inscrits."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_MirrorHerb,
        .iconPalette = gItemIconPalette_MirrorHerb,
    },

    [ITEM_SCROLL_OF_DARKNESS] =
    {
        .name = ITEM_NAME("ROULEAU TÉNÈBRES"),
        .pluralName = ITEM_PLURAL_NAME("ROULEAUX TÉNÈBRES"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un récit d'exploration du\n"
            "Cratère de Paldea signé par\n"
            "un certain Bruyer. Quelqu'un\n"
            "y a inscrit le nom “ Olim ”\n"
            "d'une écriture maladroite."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfDarkness,
        .iconPalette = gItemIconPalette_ScrollOfDarkness,
    },

    [ITEM_SCROLL_OF_WATERS] =
    {
        .name = ITEM_NAME("ROULEAU DE L'EAU"),
        .pluralName = ITEM_PLURAL_NAME("ROULEAUX DE L'EAU"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un récit d'exploration du\n"
            "Cratère de Paldea signé par\n"
            "un certain Bruyer. Quelqu'un\n"
            "y a inscrit le nom “ Turum ”\n"
            "d'une écriture maladroite."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfWaters,
        .iconPalette = gItemIconPalette_ScrollOfWaters,
    },

    [ITEM_TERA_ORB] =
    {
        .name = ITEM_NAME("ORBE TÉRACRISTAL"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Lorsqu'elle est utilisée sur\n"
            "un certain Pokémon, celui-ci\n"
            "obtient les pouvoirs de\n"
            "n'importe quel type."
        ),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraOrb,
        .iconPalette = gItemIconPalette_TeraOrb,
    },

    [ITEM_TINY_BAMBOO_SHOOT] =
    {
        .name = ITEM_NAME("PETIT BAMBOU"),
        .price = 750,
        .description = COMPOUND_STRING(
            "Une Poké Ball qui peut\n"
            "contenir le mystérieux\n"
            "Pokémon Miraidon. Elle vous a\n"
            "été confiée par un garçon\n"
            "du nom de Pepper."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyBambooShoot,
        .iconPalette = gItemIconPalette_TinyBambooShoot,
    },

    [ITEM_BUG_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT INSECT"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_BugTeraShard,
    },

    [ITEM_DARK_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT TÉNÈB."),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DarkTeraShard,
    },

    [ITEM_DRAGON_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT DRAGON"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DragonTeraShard,
    },

    [ITEM_ELECTRIC_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT ÉLEK."),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_ElectricTeraShard,
    },

    [ITEM_FAIRY_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT FÉE"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FairyTeraShard,
    },

    [ITEM_FIGHTING_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT COMBAT"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une grosse pousse\n"
            "de bambou assez\n"
            "rare. Elle est très\n"
            "populaire auprès de\n"
            "certains gourmets."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FightingTeraShard,
    },

    [ITEM_FIRE_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT FEU"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FireTeraShard,
    },

    [ITEM_FLYING_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT VOL"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FlyingTeraShard,
    },

    [ITEM_GHOST_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT SPECT."),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GhostTeraShard,
    },

    [ITEM_GRASS_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT PLANTE"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GrassTeraShard,
    },

    [ITEM_GROUND_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT SOL"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GroundTeraShard,
    },

    [ITEM_ICE_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT GLACE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une petite pousse de bambou\n"
            "assez rare. Elle est plutôt\n"
            "populaire auprès de\n"
            "certains gourmets."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_IceTeraShard,
    },

    [ITEM_NORMAL_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT NORMAL"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_NormalTeraShard,
    },

    [ITEM_POISON_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT POISON"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PoisonTeraShard,
    },

    [ITEM_PSYCHIC_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT PSY"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PsychicTeraShard,
    },

    [ITEM_ROCK_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT ROCHE"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_RockTeraShard,
    },

    [ITEM_STEEL_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT ACIER"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_SteelTeraShard,
    },

    [ITEM_WATER_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT EAU"),
        .price = 0,
        .description = COMPOUND_STRING("N/A"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_WaterTeraShard,
    },

    [ITEM_ADAMANT_CRYSTAL] =
    {
        .name = ITEM_NAME("GLOBE ADAMANT"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ce grand cristal\n"
            "brillant débordant\n"
            "de puissance\n"
            "permet à Dialga de\n"
            "changer de forme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantCrystal,
        .iconPalette = gItemIconPalette_AdamantCrystal,
    },

    [ITEM_GRISEOUS_CORE] =
    {
        .name = ITEM_NAME("GLOBE PLATINÉ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ce grand cristal brillant\n"
            "débordant de puissance\n"
            "permet à Giratina de\n"
            "changer de forme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousCore,
        .iconPalette = gItemIconPalette_GriseousCore,
    },

    [ITEM_LUSTROUS_GLOBE] =
    {
        .name = ITEM_NAME("GLOBE PERLÉ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Cette grande sphère\n"
            "brillante débordant de\n"
            "puissance permet à Palkia de\n"
            "changer de forme."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousGlobe,
        .iconPalette = gItemIconPalette_LustrousGlobe,
    },

    [ITEM_BLACK_AUGURITE] =
    {
        .name = ITEM_NAME("OBSIDIENNE"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Lorsqu'on brise cette\n"
            "pierre noire semblable à du\n"
            "verre, on obtient des éclats\n"
            "très coupants. Elle est\n"
            "appréciée d'un certain\n"
            "Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackAugurite,
        .iconPalette = gItemIconPalette_BlackAugurite,
    },

    [ITEM_LINKING_CORD] =
    {
        .name = ITEM_NAME("FIL DE LIAISON"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "Un fil qui semble abriter une\n"
            "étrange énergie capable de\n"
            "nouer des liens entre les\n"
            "êtres. Il est apprécié de\n"
            "certains Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LinkingCord,
        .iconPalette = gItemIconPalette_LinkingCord,
    },

    [ITEM_PEAT_BLOCK] =
    {
        .name = ITEM_NAME("BLOC DE TOURBE"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "Un Bloc de Tourbe similaire à\n"
            "de la boue qu'on peut\n"
            "utiliser comme combustible\n"
            "une fois séché. Il est\n"
            "apprécié d'un certain\n"
            "Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PeatBlock,
        .iconPalette = gItemIconPalette_PeatBlock,
    },

    [ITEM_BERSERK_GENE] =
    {
        .name = ITEM_NAME("ADN BERZERK"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_BERSERK_GENE,
        .description = COMPOUND_STRING(
            "Booste l'attaque\n"
            "mais rend confus."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerserkGene,
        .iconPalette = gItemIconPalette_BerserkGene,
    },

    [ITEM_FAIRY_FEATHER] =
    {
        .name = ITEM_NAME("PLUME ENCHANTÉE"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Une gourde à losanges avec\n"
            "une petite tasse assortie.\n"
            "Petite et légère, elle est\n"
            "facile à emporter avec soi\n"
            "en balade grâce à sa lanière\n"
            "détachable."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 10,
        .iconPic = gItemIcon_FairyFeather,
        .iconPalette = gItemIconPalette_FairyFeather,
    },

    [ITEM_SYRUPY_APPLE] =
    {
        .name = ITEM_NAME("POMME NECTAR"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "Le soin apporté à ses\n"
            "rebords la rend populaire\n"
            "parmi les élèves, mais aussi\n"
            "en dehors de l'école."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SyrupyApple,
        .iconPalette = gItemIconPalette_SyrupyApple,
    },

    [ITEM_UNREMARKABLE_TEACUP] =
    {
        .name = ITEM_NAME("BOL MÉDIOCRE"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "Le soin apporté à ses\n"
            "rebords la rend populaire\n"
            "parmi les élèves, mais aussi\n"
            "en dehors de l'école."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_UnremarkableTeacup,
        .iconPalette = gItemIconPalette_UnremarkableTeacup,
    },

    [ITEM_MASTERPIECE_TEACUP] =
    {
        .name = ITEM_NAME("BOL EXCEPTIONNEL"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "Une tasse à pique-nique\n"
            "très légère et solide,\n"
            "destinée aux enfants. On\n"
            "peut les empiler facilement,\n"
            "ce qui les rend faciles à\n"
            "transporter."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_MasterpieceTeacup,
        .iconPalette = gItemIconPalette_MasterpieceTeacup,
    },

    [ITEM_CORNERSTONE_MASK] =
    {
        .name = ITEM_NAME("MASQUE DE PIERRE"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Permet à Ogerpon de\nprendre le type ROC\nen combat."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CornerstoneMask,
        .iconPalette = gItemIconPalette_CornerstoneMask,
    },

    [ITEM_WELLSPRING_MASK] =
    {
        .name = ITEM_NAME("MASQUE DU PUITS"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Permet à Ogerpon de\nprendre le type EAU\nen combat."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_WellspringMask,
        .iconPalette = gItemIconPalette_WellspringMask,
    },

    [ITEM_HEARTHFLAME_MASK] =
    {
        .name = ITEM_NAME("MASQUE DU FOURNEAU"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING("Permet à Ogerpon de\nprendre le type FEU\nen combat."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HearthflameMask,
        .iconPalette = gItemIconPalette_HearthflameMask,
    },

    [ITEM_HEALTH_MOCHI] =
    {
        .name = ITEM_NAME("MOCHI SANTÉ"),
        .pluralName = ITEM_PLURAL_NAME("HEALTH MOCHI"),
        .price = 500,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_HealthMochi,
    },

    [ITEM_MUSCLE_MOCHI] =
    {
        .name = ITEM_NAME("MOCHI FORCE"),
        .pluralName = ITEM_PLURAL_NAME("MUSCLE MOCHI"),
        .price = 500,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_MuscleMochi,
    },

    [ITEM_RESIST_MOCHI] =
    {
        .name = ITEM_NAME("MOCHI ARMURE"),
        .pluralName = ITEM_PLURAL_NAME("RESIST MOCHI"),
        .price = 500,
        .description = COMPOUND_STRING(
            "Un ballon distribué par\n"
            "l'académie, de taille moyenne.\n"
            "Beaucoup d'élèves pensent\n"
            "qu'il faut le taper juste sur\n"
            "le blason de l'académie pour\n"
            "le faire voler droit."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_ResistMochi,
    },

    [ITEM_GENIUS_MOCHI] =
    {
        .name = ITEM_NAME("MOCHI ESPRIT"),
        .pluralName = ITEM_PLURAL_NAME("GENIUS MOCHI"),
        .price = 500,
        .description = COMPOUND_STRING(
            "Un ballon distribué par\n"
            "l'académie, de taille moyenne.\n"
            "Beaucoup d'élèves pensent\n"
            "qu'il faut le taper juste sur\n"
            "le blason de l'académie pour\n"
            "le faire voler droit."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_GeniusMochi,
    },

    [ITEM_CLEVER_MOCHI] =
    {
        .name = ITEM_NAME("MOCHI MENTAL"),
        .pluralName = ITEM_PLURAL_NAME("CLEVER MOCHI"),
        .price = 500,
        .description = COMPOUND_STRING(
            "Un ballon doux et\n"
            "rebondissant qui ressemble\n"
            "comme deux gouttes d'eau à\n"
            "un Marill. Faites attention à\n"
            "ne pas le confondre avec le\n"
            "vrai !"
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_CleverMochi,
    },

    [ITEM_SWIFT_MOCHI] =
    {
        .name = ITEM_NAME("MOCHI SPRINT"),
        .pluralName = ITEM_PLURAL_NAME("SWIFT MOCHI"),
        .price = 500,
        .description = COMPOUND_STRING(
            "Une petite balle en laine. Le\n"
            "fil est comprimé pour ne pas\n"
            "se défaire... Mais même si\n"
            "cela devait arriver, il est\n"
            "toujours possible d'utiliser\n"
            "la laine pour tricoter."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_SwiftMochi,
    },

    [ITEM_FRESH_START_MOCHI] =
    {
        .name = ITEM_NAME("MOCHI RENOUVEAU"),
        .pluralName = ITEM_PLURAL_NAME("FRESH-START MOCHI"),
        .price = 300,
        .description = COMPOUND_STRING(
            "Une assiette de pique-nique.\n"
            "Il en existe de nombreuses\n"
            "couleurs pour les accorder\n"
            "à l'ambiance ou au menu. La\n"
            "bleue se vend comme des\n"
            "petits pains."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ResetEVs,
        .effect = gItemEffect_ResetMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_FreshStartMochi,
    },

    [ITEM_GLIMMERING_CHARM] =
    {
        .name = ITEM_NAME("CHARME ÉCLATANT"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Une assiette de pique-nique.\n"
            "Il en existe de nombreuses\n"
            "couleurs pour les accorder\n"
            "à l'ambiance ou au menu.\n"
            "L'orange est un des modèles\n"
            "les plus appréciés."
        ),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GlimmeringCharm,
        .iconPalette = gItemIconPalette_GlimmeringCharm,
    },

    [ITEM_METAL_ALLOY] =
    {
        .name = ITEM_NAME("MÉTAL COMPOSITE"),
        .price = 6000,
        .description = COMPOUND_STRING(
            "Une assiette de pique-nique.\n"
            "Il en existe de nombreuses\n"
            "couleurs pour les accorder\n"
            "à l'ambiance ou au menu. La\n"
            "rouge se vend très bien\n"
            "d'une année sur l'autre."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_MetalAlloy,
        .iconPalette = gItemIconPalette_MetalAlloy,
    },

    [ITEM_STELLAR_TERA_SHARD] =
    {
        .name = ITEM_NAME("TÉRA-ÉCLAT STELL."),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un échantillon\n"
            "laissé par un\n"
            "Pokémon. Il peut\n"
            "être utilisé pour\n"
            "fabriquer des CT."
        ),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StellarTeraShard,
        .iconPalette = gItemIconPalette_StellarTeraShard,
    },

    [ITEM_JUBILIFE_MUFFIN] =
    {
        .name = ITEM_NAME("RUSTI-MUFFIN"),
        .price = 250,
        .description = COMPOUND_STRING(
            "Méthode pour Rusti-Muffin.\n"
            "Ressources requises : 2 épis\n"
            "de Riz Zélé, 2 Baies Bouhlon,\n"
            "1 Baie Framby et 1 boule\n"
            "d'Appâte."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_JubilifeMuffin,
        .iconPalette = gItemIconPalette_JubilifeMuffin,
    },

    [ITEM_REMEDY] =
    {
        .name = ITEM_NAME("REMÈDE"),
        .pluralName = ITEM_PLURAL_NAME("REMEDIES"),
        .price = 150,
        .description = COMPOUND_STRING(
            "Méthode pour\n"
            "Remède. Ressources\n"
            "requises : 2\n"
            "Plantes Répulsives."
        ),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Remedy,
        .flingPower = 30,
        .iconPic = gItemIcon_Remedy,
        .iconPalette = gItemIconPalette_Remedy,
    },

    [ITEM_FINE_REMEDY] =
    {
        .name = ITEM_NAME("SUPER REMÈDE"),
        .pluralName = ITEM_PLURAL_NAME("FINE REMEDIES"),
        .price = 150,
        .description = COMPOUND_STRING(
            "Une poudre amère\n"
            "qui restaure\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 60 points."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FineRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_FineRemedy,
        .iconPalette = gItemIconPalette_FineRemedy,
    },

    [ITEM_SUPERB_REMEDY] =
    {
        .name = ITEM_NAME("HYPER REMÈDE"),
        .pluralName = ITEM_PLURAL_NAME("SUPERB REMEDIES"),
        .price = 750,
        .description = COMPOUND_STRING(
            "Une poudre amère\n"
            "qui restaure\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 120 points."),
        #else
            "by 200 points."),
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperbRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_SuperbRemedy,
        .iconPalette = gItemIconPalette_SuperbRemedy,
    },

    [ITEM_AUX_EVASION] =
    {
        .name = ITEM_NAME("ESQUIVE EXTRA"),
        .price = 800,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup\n"
            "l'Esquive durant\n"
            "un combat."),
        #else
            "Monte l'Esquive\n"
            "durant un combat."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxEvasion,
    },

    [ITEM_AUX_GUARD] =
    {
        .name = ITEM_NAME("DÉFENSE EXTRA"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup les\n"
            "défenses durant\n"
            "un combat."),
        #else
            "Monte les défenses\n"
            "durant un combat."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxGuard,
    },

    [ITEM_AUX_POWER] =
    {
        .name = ITEM_NAME("OFFENSIVE EXTRA"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup les\n"
            "attaques durant\n"
            "un combat."),
        #else
            "Monte les attaques\n"
            "durant un combat."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxPower,
    },

    [ITEM_AUX_POWERGUARD] =
    {
        .name = ITEM_NAME("DOUBLE EXTRA"),
        .price = 1200,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Monte beaucoup les\n"
            "attaques et défenses\n"
            "durant un combat."),
        #else
            "Monte les attaques\n"
            "et défenses durant\n"
            "un combat."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxPowerguard,
        .iconPalette = gItemIconPalette_AuxPowerguard,
    },

    [ITEM_CHOICE_DUMPLING] =
    {
        .name = ITEM_NAME("PAPILLOTE CHOIX"),
        .price = 1200,
        .description = COMPOUND_STRING(
            "Méthode pour Papillote\n"
            "Choix. Ressources requises :\n"
            "3 Feuilles Rondes, 1\n"
            "Fortichampi, 1 Champiscoto\n"
            "et 2 épis de Riz Zélé."
        ),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_ChoiceDumpling,
        .iconPalette = gItemIconPalette_ChoiceDumpling,
    },

    [ITEM_SWAP_SNACK] =
    {
        .name = ITEM_NAME("EN-CAS CONTRAIRE"),
        .price = 1200,
        .description = COMPOUND_STRING(
            "Ce curieux en-cas permet\n"
            "d'inverser temporairement la\n"
            "puissance offensive et la\n"
            "puissance défensive d'un\n"
            "Pokémon."
        ),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_SwapSnack,
        .iconPalette = gItemIconPalette_SwapSnack,
    },

    [ITEM_TWICE_SPICED_RADISH] =
    {
        .name = ITEM_NAME("BOUCHÉE DOUBLE"),
        .pluralName = ITEM_PLURAL_NAME("TWICE-SPICED RADISHES"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "Ce mets permet à un\n"
            "Pokémon de frapper une fois\n"
            "et demie plus fort\n"
            "temporairement. Les effets\n"
            "sont similaires à ceux de la\n"
            "capacité Coup Double."
        ),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_TwiceSpicedRadish,
        .iconPalette = gItemIconPalette_TwiceSpicedRadish,
    },

    [ITEM_POKESHI_DOLL] =
    {
        .name = ITEM_NAME("POUPÉE POKÉSHI"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Méthode pour\n"
            "Poupée Pokéshi.\n"
            "Ressources\n"
            "requises : 3\n"
            "morceaux de Bois."
        ),
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_PokeshiDoll,
        .iconPalette = gItemIconPalette_PokeshiDoll,
    },

// HnS Items

    [ITEM_GS_BALL] =
    {
        .name = ITEM_NAME("GS BALL"),
        .price = 1000,
        .description = COMPOUND_STRING("Une étrange POKé BALL\naux motifs d'or et\nd'argent."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_GS,
        .iconPic = gItemIcon_GSBall,
        .iconPalette = gItemIconPalette_GSBall,
    },

    [ITEM_FERTILIZER] =
    {
        .name = ITEM_NAME("FERTIPOUSSE"),
        .price = 2500,
        .description = COMPOUND_STRING("Un engrais qui\naccélère la pousse\ndes Baies."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_EXP_SHARE_SMALL] =
    {
        .name = ITEM_NAME("MULTI EXP. P"),
        .price = 6000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        .description = COMPOUND_STRING("Objet à tenir donnant\ndes Points Exp. après\nles combats."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ExpShare,
        .iconPalette = gItemIconPalette_ExpShare,
    },

    [ITEM_HEALING_HEART] =
    {
        .name = ITEM_NAME("CŒUR GUÉRISSEUR"),
        .price = 0,
        .description = COMPOUND_STRING("Un cœur qui soigne\nl'équipe quand il est\nutilisé sur le terrain."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HealingHeart,
        .iconPalette = gItemIconPalette_HealingHeart,
    },

    [ITEM_INFINITE_REPEL] =
    {
        .name = ITEM_NAME("REPOUSSE INFINI"),
        .price = 0,
        .description = COMPOUND_STRING("Repousse indéfiniment\nles POKéMON sauvages\nles plus faibles."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_INFINITE_RARE_CANDIES] =
    {
        .name = ITEM_NAME("BOÎTE SUPER BONB."),
        .price = 0,
        .description = COMPOUND_STRING("Une boîte inépuisable\nde SUPER BONBONS."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_InfiniteRareCandies,
        .iconPic = gItemIcon_RareCandy,
        .iconPalette = gItemIconPalette_RareCandy,
    },

    [ITEM_CLEAR_BELL] =
    {
        .name = ITEM_NAME("GLAS TRANSPARENT"),
        .price = 0,
        .description = COMPOUND_STRING("Un glas au son pur et\nlimpide qui apaise\nles POKéMON."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ClearBell,
        .iconPalette = gItemIconPalette_ClearBell,
    },

    [ITEM_LOST_ITEM] =
    {
        .name = ITEM_NAME("OBJET PERDU"),
        .price = 0,
        .description = COMPOUND_STRING("Un objet perdu par\nune fille à\nSAFRANIA."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LostItem,
        .iconPalette = gItemIconPalette_LostItem,
    },

    [ITEM_MACHINE_PART] =
    {
        .name = ITEM_NAME("PARTIE MACHINE"),
        .price = 0,
        .description = COMPOUND_STRING("Une pièce requise pour\nréparer le générateur\nde la CENTRALE."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MachinePart,
        .iconPalette = gItemIconPalette_MachinePart,
    },

    [ITEM_MYSTERY_EGG] =
    {
        .name = ITEM_NAME("ŒUF MYSTÈRE"),
        .price = 0,
        .description = COMPOUND_STRING("Un OEUF reçu de\nM. POKéMON. À donner\nau PROF. ORME."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MysteryEgg,
        .iconPalette = gItemIconPalette_MysteryEgg,
    },

    [ITEM_PASS] =
    {
        .name = ITEM_NAME("PASSE TRAIN"),
        .price = 0,
        .description = COMPOUND_STRING("Un passe pour le TRAIN\nMAGNÉT. entre\nDOUBLONVILLE et SAFRANIA."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HnsPass,
        .iconPalette = gItemIconPalette_HnsPass,
    },

    [ITEM_RAINBOW_WING] =
    {
        .name = ITEM_NAME("ARC-EN-CI’AILE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une plume mystique\n"
            "aux couleurs de l'arc-\n"
            "en-ciel. Elle est sacrée."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RainbowWing,
        .iconPalette = gItemIconPalette_RainbowWing,
    },

    [ITEM_RED_SCALE] =
    {
        .name = ITEM_NAME("ÉCAILLE ROUGE"),
        .price = 0,
        .description = COMPOUND_STRING("Une écaille du\nLÉVIATOR ROUGE du\nLAC COLÈRE."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RedScale,
        .iconPalette = gItemIconPalette_RedScale,
    },

    [ITEM_SECRET_POTION] =
    {
        .name = ITEM_NAME("POTION SECRÈTE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Un remède secret\n"
            "préparé à la pharmacie\n"
            "d'IRISIA."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SecretPotion,
        .iconPalette = gItemIconPalette_SecretPotion,
    },

    [ITEM_SILVER_WING] =
    {
        .name = ITEM_NAME("ARGENT’AILE"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Une plume argentée\n"
            "mystique censée\n"
            "appeler Lugia."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SilverWing,
        .iconPalette = gItemIconPalette_SilverWing,
    },

    [ITEM_TIDAL_BELL] =
    {
        .name = ITEM_NAME("GLAS TEMPÊTE"),
        .price = 0,
        .description = COMPOUND_STRING("Un glas dont l'écho\nappelle Lugia."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TidalBell,
        .iconPalette = gItemIconPalette_TidalBell,
    },

    [ITEM_RADIO] =
    {
        .name = ITEM_NAME("RADIO"),
        .price = 0,
        .description = COMPOUND_STRING("Une radio portable\nqui capte différentes\nstations."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Radio,
        .iconPalette = gItemIconPalette_Radio,
    },

    [ITEM_SQUIRT_BOTTLE] =
    {
        .name = ITEM_NAME("CARAPUCE À O"),
        .price = 0,
        .description = COMPOUND_STRING("Un arrosoir pour les\nplantes et\nSIMULARBRE."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SquirtBottle,
        .iconPalette = gItemIconPalette_SquirtBottle,
    },

    [ITEM_ROOM_1_KEY] =
    {
        .name = ITEM_NAME("CLÉ SALLE 1"),
        .price = 0,
        .description = COMPOUND_STRING("Une clé de chambre\nde l'ENTREPÔT\nSOUTERRAIN."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room1Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_ROOM_2_KEY] =
    {
        .name = ITEM_NAME("CLÉ SALLE 2"),
        .price = 0,
        .description = COMPOUND_STRING("Une clé de chambre\nde l'ENTREPÔT\nSOUTERRAIN."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room2Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_ROOM_4_KEY] =
    {
        .name = ITEM_NAME("CLÉ SALLE 4"),
        .price = 0,
        .description = COMPOUND_STRING("Une clé de chambre\nde l'ENTREPÔT\nSOUTERRAIN."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room4Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_ROOM_6_KEY] =
    {
        .name = ITEM_NAME("CLÉ SALLE 6"),
        .price = 0,
        .description = COMPOUND_STRING("Une clé de chambre\nde l'ENTREPÔT\nSOUTERRAIN."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room6Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_UNUSED_BERRY_1] =
    {
        .name = ITEM_NAME("BAIE SITRUS"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING("Objet à tenir qui\nrestaure 30 PV\nau porteur."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_UNUSED_BERRY_2] =
    {
        .name = ITEM_NAME("????????"),
        .price = 0,
        .description = COMPOUND_STRING("Emplacement réservé\nà un objet inutilisé."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_UNUSED_BERRY_3] =
    {
        .name = ITEM_NAME("????????"),
        .price = 0,
        .description = COMPOUND_STRING("Emplacement réservé\nà un objet inutilisé."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_AZURE_FLUTE] =
    {
        .name = ITEM_NAME("FLÛTE AZUR"),
        .price = 0,
        .description = COMPOUND_STRING("Une flûte au son\nmystérieux."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_AzureFlute,
        .iconPalette = gItemIconPalette_AzureFlute,
    },
};

#undef ITEM_NAME
#undef ITEM_PLURAL_NAME
