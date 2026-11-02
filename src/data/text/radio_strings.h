// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("CHRONIQUE DU PROF.CHEN");
static const u8 sRadioStationName_PokedexShow[]     = _("ÉMISSION POKéDEX");
static const u8 sRadioStationName_PokemonMusic[]    = _("MUSIQUE POKéMON");
static const u8 sRadioStationName_LuckyChannel[]    = _("ANTENNE CHANCE");
static const u8 sRadioStationName_BuenasPassword[]  = _("MOT DE PASSE DE BUENA");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("SOCIO FM");
static const u8 sRadioStationName_LetsAllSing[]     = _("CHANTONS ENSEMBLE!");
static const u8 sRadioStationName_PokeFlute[]       = _("POKé FLÛTE");

static const u8 sRadioStationName_HoennSound[]  = _("SON DE HOENN");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("Une mélodie POKéMON venue");
static const u8 sRadioText_Hoenn2[] = _("d'une région nommée HOENN!");
static const u8 sRadioText_Hoenn3[] = _("Des POKéMON sauvages de là-bas");
static const u8 sRadioText_Hoenn4[] = _("peuvent apparaître ici!");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("ÉMISSION POKéDEX DE CHEN!");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("CHEN: Le POKéMON du jour: ");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("LULA: CHRONIQUE DU PROF.CHEN!");
static const u8 sRadioText_OPT_WithMeMary[] = _("Avec moi, LULA!");
static const u8 sRadioText_OPT_OakPrefix[] = _("CHEN: ");
static const u8 sRadioText_OPT_SeenAround[] = _("est près de:");
static const u8 sRadioText_OPT_MaryPrefix[] = _("LULA: ");
static const u8 sRadioText_OPT_MaryIs[] = _(" est ");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("CHRONIQUE POKéMON");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("adorable et");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("mou et");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("bien nommé et");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("vraiment");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("très");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("super");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("toxique et");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("sensuel et");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("vicieux et");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("célèbre et");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("très");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("dans l'eau est");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("évolué est");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provoquant et");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("fou et");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("tellement");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("mignon.");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("bizarre.");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("agréable.");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("courageux.");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("effrayant.");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("rapide!");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("puissant.");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("vigoureux.");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("cool!");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("exaltant.");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("amical.");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("chaud!");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("stimulant.");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("protégé.");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("gracieux.");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("rapide.");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("BEN: ANTENNE MUSIQUE PKMN!");
static const u8 sRadioText_BenIntro2[] = _("C'est moi, DJ BEN!");
static const u8 sRadioText_FernIntro[] = _("SEB: MUSIQUE POKéMON!");
static const u8 sRadioText_FernIntro2[] = _("Avec DJ SEB!");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("Aujourd'hui, ");
static const u8 sRadioText_BenFern_JamTo[] = _("on s'écoute");
static const u8 sRadioText_BenFern_ChillTo[] = _("on s'la donne avec");
static const u8 sRadioText_BenFern_March[] = _("la fanfare POKéMON!");
static const u8 sRadioText_BenFern_Lullaby[] = _("la berceuse POKéMON!");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("SAM: Yeah! Comment");
static const u8 sRadioText_LC2[] = _("ça gaze les gars?");
static const u8 sRadioText_LC3[] = _("Ne ratez jamais le");
static const u8 sRadioText_LC4[] = _("BON NUMÉRO!");
static const u8 sRadioText_LC5[] = _("Cette semaine, le No. est");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("Je répète...");
static const u8 sRadioText_LC_Match[] = _("Gagne et va vite");
static const u8 sRadioText_LC_Tower[] = _("à la TOUR RADIO!");
static const u8 sRadioText_LC_Drag1[] = _("J'aime pas trop");
static const u8 sRadioText_LC_Drag2[] = _("répéter...");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("SOCIO FM! Présenté");
static const u8 sRadioText_PnP_Intro2[] = _("par moi, DJ PETRA!");
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("est adorable.");
static const u8 sRadioText_PnP_Lazy[]       = _("est cool.");
static const u8 sRadioText_PnP_Happy[]      = _("est en joie.");
static const u8 sRadioText_PnP_Noisy[]      = _("fait du bruit.");
static const u8 sRadioText_PnP_Precocious[] = _("est calme.");
static const u8 sRadioText_PnP_Bold[]       = _("est difficile.");
static const u8 sRadioText_PnP_Picky[]      = _("est difficile!");
static const u8 sRadioText_PnP_SortOfOK[]   = _("est pas mal.");
static const u8 sRadioText_PnP_SoSo[]       = _("est OK.");
static const u8 sRadioText_PnP_Great[]       = _("est super!");
static const u8 sRadioText_PnP_MyType[]      = _("est trop cool.");
static const u8 sRadioText_PnP_Cool[]        = _("est cool, non?");
static const u8 sRadioText_PnP_Inspiring[]   = _("est terrible!");
static const u8 sRadioText_PnP_Weird[]       = _("est étrange.");
static const u8 sRadioText_PnP_RightForMe[]  = _("est formidable.");
static const u8 sRadioText_PnP_Odd[]         = _("est bizarre!");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
static const u8 sRadioText_Rocket1[]  = _("...Heu...on est");
static const u8 sRadioText_Rocket2[]  = _("la TEAM ROCKET!");
static const u8 sRadioText_Rocket3[]  = _("Après trois ans");
static const u8 sRadioText_Rocket4[]  = _("d'attente, on");
static const u8 sRadioText_Rocket5[]  = _("est de retour");
static const u8 sRadioText_Rocket6[]  = _("pour de bon!");
static const u8 sRadioText_Rocket7[]  = _("GIOVANNI! Chef!");
static const u8 sRadioText_Rocket8[]  = _("Il nous écoute?");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("BUENA: Ici BUENA!");
static const u8 sRadioText_Buena2[] = _("Le mot de passe!");
static const u8 sRadioText_Buena3[] = _("C'est...");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}!");
static const u8 sRadioText_Buena5[] = _("Souvenez-vous en! Je suis");
static const u8 sRadioText_Buena6[] = _("à la RADIO de DOUBLONVILLE!");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("BOURG GEON");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("VILLE GRIOTTE");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("ÉCORCIA");
static const u8 sRadioBuenaPassword_Flying[]          = _("VOL");
static const u8 sRadioBuenaPassword_Bug[]             = _("INSECTE");
static const u8 sRadioBuenaPassword_Grass[]           = _("PLANTE");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("CHRONIQUE POKéMON CHEN");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("MUSIQUE POKéMON");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("ANTENNE CHANCE");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("LULA: Ce soir, un rare instant");
static const u8 sOPT_Report_Clefairy_1[]  = _("au clair de lune!");
static const u8 sOPT_Report_Clefairy_2[]  = _("CHEN: Pleins feux sur le");
static const u8 sOPT_Report_Clefairy_3[]  = _("mystérieux MÉLOFÉE!");
static const u8 sOPT_Report_Clefairy_4[]  = _("Ils se réunissent au MONT");
static const u8 sOPT_Report_Clefairy_5[]  = _("SÉLÉNITE, les nuits de pleine lune.");
static const u8 sOPT_Report_Clefairy_6[]  = _("LULA: Ils DANSENT en cercle!");
static const u8 sOPT_Report_Clefairy_7[]  = _("C'est adorablement étrange!");
static const u8 sOPT_Report_Clefairy_8[]  = _("CHEN: Un mystère éternel");
static const u8 sOPT_Report_Clefairy_9[]  = _("et un spectacle à voir!");

static const u8 sOPT_Report_Lapras_0[]  = _("LULA: Un doux géant est");
static const u8 sOPT_Report_Lapras_1[]  = _("la vedette du jour!");
static const u8 sOPT_Report_Lapras_2[]  = _("CHEN: C'est le passeur des mers,");
static const u8 sOPT_Report_Lapras_3[]  = _("notre cher LOKHLASS!");
static const u8 sOPT_Report_Lapras_4[]  = _("On le voit aux CAVES JUMELLES,");
static const u8 sOPT_Report_Lapras_5[]  = _("et nulle part ailleurs. Curieux!");
static const u8 sOPT_Report_Lapras_6[]  = _("LULA: Si rare et paisible!");
static const u8 sOPT_Report_Lapras_7[]  = _("Et en plus, il chante!");
static const u8 sOPT_Report_Lapras_8[]  = _("CHEN: On dit que son chant apaise");
static const u8 sOPT_Report_Lapras_9[]  = _("l'âme de la mer.");

static const u8 sOPT_Report_Ampharos_0[]  = _("LULA: Bonjour à tous!");
static const u8 sOPT_Report_Ampharos_1[]  = _("Place à la CHRONIQUE POKéMON!");
static const u8 sOPT_Report_Ampharos_2[]  = _("CHEN: Éclairons notre ami");
static const u8 sOPT_Report_Ampharos_3[]  = _("PHARAMP!");
static const u8 sOPT_Report_Ampharos_4[]  = _("Sa queue lumineuse traverse");
static const u8 sOPT_Report_Ampharos_5[]  = _("le brouillard et guide les perdus.");
static const u8 sOPT_Report_Ampharos_6[]  = _("LULA: Puissant, élégant");
static const u8 sOPT_Report_Ampharos_7[]  = _("et vraiment amical!");
static const u8 sOPT_Report_Ampharos_8[]  = _("CHEN: Au cœur de nombreuses");
static const u8 sOPT_Report_Ampharos_9[]  = _("histoires de phares!");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("LULA: À suivre, un drôle d'oiseau");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("sur la ROUTE 36...");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("CHEN: SIMULARBRE! On dirait un");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("arbre, mais ce n'en est pas un!");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("Il bloque la route et ne");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("bouge pas sans eau.");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("LULA: Seul un certain");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("CARAPUCE À O peut le faire réagir!");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("CHEN: Ce n'est pas un buisson,");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("mais un type ROC déguisé!");

static const u8 sOPT_Report_RedGyarados_0[]  = _("LULA: L'histoire du jour vient");
static const u8 sOPT_Report_RedGyarados_1[]  = _("de secouer JOHTO!");
static const u8 sOPT_Report_RedGyarados_2[]  = _("CHEN: Des Dresseurs ont vu un");
static const u8 sOPT_Report_RedGyarados_3[]  = _("LÉVIATOR ROUGE au LAC COLÈRE!");
static const u8 sOPT_Report_RedGyarados_4[]  = _("Contrairement aux bleus habituels,");
static const u8 sOPT_Report_RedGyarados_5[]  = _("celui-ci est rouge écarlate!");
static const u8 sOPT_Report_RedGyarados_6[]  = _("LULA: On le dit lié à");
static const u8 sOPT_Report_RedGyarados_7[]  = _("d'étranges ondes radio!");
static const u8 sOPT_Report_RedGyarados_8[]  = _("CHEN: Une évolution mystérieuse...");
static const u8 sOPT_Report_RedGyarados_9[]  = _("Peut-être artificielle.");

static const u8 sOPT_Report_Unown_0[]  = _("LULA: Déjà visité les RUINES");
static const u8 sOPT_Report_Unown_1[]  = _("D'ALPHA? Ça fait peur!");
static const u8 sOPT_Report_Unown_2[]  = _("CHEN: D'étranges symboles couvrent");
static const u8 sOPT_Report_Unown_3[]  = _("les murs, comme d'antiques runes.");
static const u8 sOPT_Report_Unown_4[]  = _("À l'intérieur vivent des ZARBI...");
static const u8 sOPT_Report_Unown_5[]  = _("chacun en forme de lettre!");
static const u8 sOPT_Report_Unown_6[]  = _("LULA: Ils écrivent des mots,");
static const u8 sOPT_Report_Unown_7[]  = _("peut-être? Ou nous effraient!");
static const u8 sOPT_Report_Unown_8[]  = _("CHEN: Une véritable énigme");
static const u8 sOPT_Report_Unown_9[]  = _("de la nature, encore irrésolue.");

static const u8 sOPT_Report_Snubbull_0[]  = _("LULA: Les gens de DOUBLONVILLE");
static const u8 sOPT_Report_Snubbull_1[]  = _("cherchent partout!");
static const u8 sOPT_Report_Snubbull_2[]  = _("CHEN: Un SNUBBULL s'est enfui");
static const u8 sOPT_Report_Snubbull_3[]  = _("et court toujours!");
static const u8 sOPT_Report_Snubbull_4[]  = _("D'ordinaire timide et difficile,");
static const u8 sOPT_Report_Snubbull_5[]  = _("il a été vu près de la gare.");
static const u8 sOPT_Report_Snubbull_6[]  = _("LULA: Il cherche peut-être");
static const u8 sOPT_Report_Snubbull_7[]  = _("l'amour... ou l'aventure!");
static const u8 sOPT_Report_Snubbull_8[]  = _("CHEN: Ouvrez l'œil");
static const u8 sOPT_Report_Snubbull_9[]  = _("et gardez une laisse prête.");

static const u8 sOPT_Report_Slowpoke_0[]  = _("LULA: Grande nouvelle d'ÉCORCIA");
static const u8 sOPT_Report_Slowpoke_1[]  = _("cette semaine!");
static const u8 sOPT_Report_Slowpoke_2[]  = _("CHEN: Les RAMOLOSS sont revenus");
static const u8 sOPT_Report_Slowpoke_3[]  = _("dans leur puits après une crise!");
static const u8 sOPT_Report_Slowpoke_4[]  = _("La TEAM ROCKET leur coupait");
static const u8 sOPT_Report_Slowpoke_5[]  = _("la queue! C'est horrible!");
static const u8 sOPT_Report_Slowpoke_6[]  = _("LULA: Mais un jeune Dresseur");
static const u8 sOPT_Report_Slowpoke_7[]  = _("courageux les a arrêtés!");
static const u8 sOPT_Report_Slowpoke_8[]  = _("CHEN: Les RAMOLOSS sont saufs");
static const u8 sOPT_Report_Slowpoke_9[]  = _("et somnolent de nouveau.");

static const u8 sOPT_Report_LavenderTower_0[]  = _("LULA: La tour de LAVANVILLE");
static const u8 sOPT_Report_LavenderTower_1[]  = _("a changé de musique!");
static const u8 sOPT_Report_LavenderTower_2[]  = _("CHEN: L'ancienne tour hantée est");
static const u8 sOPT_Report_LavenderTower_3[]  = _("maintenant une STATION RADIO!");
static const u8 sOPT_Report_LavenderTower_4[]  = _("Certains habitants la trouvent");
static const u8 sOPT_Report_LavenderTower_5[]  = _("toujours... inquiétante.");
static const u8 sOPT_Report_LavenderTower_6[]  = _("LULA: J'ai vu un FANTOMINUS");
static const u8 sOPT_Report_LavenderTower_7[]  = _("près du studio, je le jure!");
static const u8 sOPT_Report_LavenderTower_8[]  = _("CHEN: Des parasites, peut-être...");
static const u8 sOPT_Report_LavenderTower_9[]  = _("ou des spectres!");

static const u8 sOPT_Report_Tentacruel_0[]  = _("LULA: Étrange nouvelle des");
static const u8 sOPT_Report_Tentacruel_1[]  = _("TOURB'ÎLES aujourd'hui!");
static const u8 sOPT_Report_Tentacruel_2[]  = _("CHEN: Des TENTACRUEL encerclent");
static const u8 sOPT_Report_Tentacruel_3[]  = _("les entrées des grottes!");
static const u8 sOPT_Report_Tentacruel_4[]  = _("Ils sont énormes et semblent");
static const u8 sOPT_Report_Tentacruel_5[]  = _("défendre leur territoire.");
static const u8 sOPT_Report_Tentacruel_6[]  = _("LULA: Ils barrent la route");
static const u8 sOPT_Report_Tentacruel_7[]  = _("sans attaquer...");
static const u8 sOPT_Report_Tentacruel_8[]  = _("CHEN: Comme s'ils protégeaient");
static const u8 sOPT_Report_Tentacruel_9[]  = _("quelque chose sous les flots.");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
