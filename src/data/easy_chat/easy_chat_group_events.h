const u8 gEasyChatWord_Appeal[] = _("CHARME");
const u8 gEasyChatWord_Events[] = _("EVENEMENTS");
const u8 gEasyChatWord_StayAtHome[] = _("ARENE");
const u8 gEasyChatWord_Berry[] = _("BAIE");
const u8 gEasyChatWord_Contest[] = _("CONCOURS");
const u8 gEasyChatWord_Mc[] = _("ANIMATRICE");
const u8 gEasyChatWord_Judge[] = _("JUGE");
const u8 gEasyChatWord_Super[] = _("SUPER");
const u8 gEasyChatWord_Stage[] = _("VILLE");
const u8 gEasyChatWord_HallOfFame[] = _("PANTHEON");
const u8 gEasyChatWord_Evolution[] = _("EVOLUTION");
const u8 gEasyChatWord_Hyper[] = _("HYPER");
const u8 gEasyChatWord_BattleTower[] = _("TOUR COMBAT");
const u8 gEasyChatWord_Leaders[] = _("CHEFS");
const u8 gEasyChatWord_BattleRoom[] = _("SALLE COMBAT");
const u8 gEasyChatWord_Hidden[] = _("CACHE");
const u8 gEasyChatWord_SecretBase[] = _("BASE SECRETE");
const u8 gEasyChatWord_Blend[] = _("MIXER");
const u8 gEasyChatWord_POKEBLOCK[] = _("{POKEBLOCK}");
const u8 gEasyChatWord_Master[] = _("MAITRE");
const u8 gEasyChatWord_Rank[] = _("CATEGORIE");
const u8 gEasyChatWord_Ribbon[] = _("RUBAN");
const u8 gEasyChatWord_Crush[] = _("BROYEUR");
const u8 gEasyChatWord_Direct[] = _("DIRECT");
const u8 gEasyChatWord_Tower[] = _("TOUR");
const u8 gEasyChatWord_Union[] = _("UNION");
const u8 gEasyChatWord_Room[] = _("SALLE");
const u8 gEasyChatWord_Wireless[] = _("SANS FIL");
const u8 gEasyChatWord_Frontier[] = _("ZONE");

const struct EasyChatWordInfo gEasyChatGroup_Events[] = {
    [EC_INDEX(EC_WORD_APPEAL)] =
    {
        .text = COMPOUND_STRING("CHARME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENTS)] =
    {
        .text = COMPOUND_STRING("EVENEMENTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAY_AT_HOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAY_AT_HOME)] =
    {
        .text = COMPOUND_STRING("ARENE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BERRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BERRY)] =
    {
        .text = COMPOUND_STRING("BAIE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET_BASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONTEST)] =
    {
        .text = COMPOUND_STRING("CONCOURS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRUSH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MC)] =
    {
        .text = COMPOUND_STRING("ANIMATRICE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIDDEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUDGE)] =
    {
        .text = COMPOUND_STRING("JUGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RANK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUPER)] =
    {
        .text = COMPOUND_STRING("SUPER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAGE)] =
    {
        .text = COMPOUND_STRING("VILLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HALL_OF_FAME)] =
    {
        .text = COMPOUND_STRING("PANTHEON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONTEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLUTION)] =
    {
        .text = COMPOUND_STRING("EVOLUTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIRECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HYPER)] =
    {
        .text = COMPOUND_STRING("HYPER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_TOWER)] =
    {
        .text = COMPOUND_STRING("TOUR COMBAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLUTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADERS)] =
    {
        .text = COMPOUND_STRING("CHEFS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HYPER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_ROOM)] =
    {
        .text = COMPOUND_STRING("SALLE COMBAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUDGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIDDEN)] =
    {
        .text = COMPOUND_STRING("CACHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MASTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET_BASE)] =
    {
        .text = COMPOUND_STRING("BASE SECRETE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BLEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BLEND)] =
    {
        .text = COMPOUND_STRING("MIXER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HALL_OF_FAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEBLOCK)] =
    {
        .text = COMPOUND_STRING("{POKEBLOCK}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEBLOCK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MASTER)] =
    {
        .text = COMPOUND_STRING("MAITRE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIBBON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RANK)] =
    {
        .text = COMPOUND_STRING("CATEGORIE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIBBON)] =
    {
        .text = COMPOUND_STRING("RUBAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ROOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRUSH)] =
    {
        .text = COMPOUND_STRING("BROYEUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIRELESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIRECT)] =
    {
        .text = COMPOUND_STRING("DIRECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUPER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOWER)] =
    {
        .text = COMPOUND_STRING("TOUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOWER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNION)] =
    {
        .text = COMPOUND_STRING("UNION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_TOWER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROOM)] =
    {
        .text = COMPOUND_STRING("SALLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIRELESS)] =
    {
        .text = COMPOUND_STRING("SANS FIL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONTIER)] =
    {
        .text = COMPOUND_STRING("ZONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONTIER),
        .enabled = TRUE,
    },
};
