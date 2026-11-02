// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_DEMO_WINDOW] =
    {
        .header = COMPOUND_STRING("Information : fenêtres d'aide"),
        .desc = COMPOUND_STRING("Ceci est une fenêtre d'aide. Elle peut\nafficher beaucoup de texte à l'écran,\nque personne ne lira !\n\nFormidable, non ?"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 4, 5},
    },
    [HELP_GAMESTART_WINDOW] =
    {
        .header = COMPOUND_STRING("Information : autres options"),
        .desc = COMPOUND_STRING("L'horloge peut être réglée gratuitement\ndans n'importe quel CENTRE POKéMON.\nConsultez les OBJETS RARES du SAC et le\nmenu OPTIONS pour découvrir encore plus\nde réglages personnalisables.\nAmusez-vous bien !"),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_TRADE_WINDOW] =
    {
        .header = COMPOUND_STRING("ATTENTION : COMPATIBILITÉ"),
        .desc = COMPOUND_STRING("Une mauvaise connexion peut abîmer\n"
                                "votre sauvegarde définitivement.\n"
                                "Connectez-vous uniquement si :\n"
                                "Vous jouez tous deux à Heart & Soul.\n"
                                "Vous utilisez la même version.\n"
                                "Vos réglages de défi sont identiques.\n"
                                "Aucun mode aléatoire n’est activé."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 4, 5},
    },
    [HELP_TELEPORTER_WINDOW] =
    {
        .header = COMPOUND_STRING("CONTENU BONUS : TÉLÉPORTEUR"),
        .desc = COMPOUND_STRING("Le TÉLÉPORTEUR peut transformer\nDÉFINITIVEMENT des POKéMON en leur\nforme de Galar. Ces formes ne sont\nnécessaires ni pour progresser dans\nl'histoire, ni pour terminer le\nPOKéDEX NATIONAL."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_SINJOH_WINDOW] =
    {
        .header = COMPOUND_STRING("CONTENU BONUS : SINJOH"),
        .desc = COMPOUND_STRING("Ce personnage donne accès au contenu\nfacultatif de SINJOH. Il n'est requis\nni pour l'histoire, ni pour terminer\nle POKéDEX NATIONAL.\n\nCe n'est qu'un bonus, si vous le voulez."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_ALOLA_WINDOW] =
    {
        .header = COMPOUND_STRING("CONTENU BONUS : ÎLES"),
        .desc = COMPOUND_STRING("Ce personnage donne accès au contenu\nfacultatif des ÎLES. Il n'est requis\nni pour l'histoire, ni pour terminer\nle POKéDEX NATIONAL.\n\nCe n'est qu'un bonus, si vous le voulez."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE1_WINDOW] =
    {
        .header = COMPOUND_STRING("TALENTS DES BÉBÉS POKéMON"),
        .desc = COMPOUND_STRING("Le talent de PICHU est STATIK.\nCelui de MÉLO est JOLI SOURIRE.\nCelui de TOUDOUDOU est JOLI SOURIRE.\nCelui de DEBUGANT est CRAN.\nCelui de LIPPOUTI est BENÊT.\nCelui d'ÉLEKID est STATIK.\nCelui de MAGBY est CORPS ARDENT."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE2_WINDOW] =
    {
        .header = COMPOUND_STRING("TYPES DES BÉBÉS POKéMON"),
        .desc = COMPOUND_STRING("PICHU est de type ÉLECTRIK.\nMÉLO est de type NORMAL.\nTOUDOUDOU est de type NORMAL.\nDEBUGANT est de type COMBAT.\nLIPPOUTI est de type GLACE.\nÉLEKID est de type ÉLECTRIK.\nMAGBY est de type FEU."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE3_WINDOW] =
    {
        .header = COMPOUND_STRING("CRIS DES BÉBÉS POKéMON"),
        .desc = COMPOUND_STRING("PICHU crie OUIIIIN.\nMÉLO crie HII.\nTOUDOUDOU chante LALALA.\nDEBUGANT crie HIYAH.\nLIPPOUTI rit HÉHÉHÉ.\nÉLEKID crie OHÉ, OHÉ, OHÉ.\nMAGBY crie TCH."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_DAYCARE4_WINDOW] =
    {
        .header = COMPOUND_STRING("ACTIONS DES BÉBÉS POKéMON"),
        .desc = COMPOUND_STRING("PICHU aime JOUER toute la journée.\nMÉLO REGARDE la lune.\nTOUDOUDOU les ENDORT.\nDEBUGANT S'ENTRAÎNE sans arrêt.\nLIPPOUTI aime se MONTRER.\nÉLEKID emmagasine de l'énergie.\nMAGBY se met souvent EN COLÈRE."),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("MANGEOIRES : POKéBLOCS"),
        .desc = COMPOUND_STRING("Couleurs et IV parfaits attirés :\n"
                                "RGE: PV,ATQ,VIT   BLE: PV,ATS,VIT\n"
                                "ROS: ATQ,ATS,VIT  VRT: PV,DÉF,DFS\n"
                                "JNE: PV,ATQ,DÉF   VIO: ATQ,DÉF,DFS\n"
                                "IND: PV,ATS,DFS   BRN: DÉF,VIT,DFS\n"
                                "AZU: ATS,VIT,DFS  OLI: ATQ,DÉF,VIT\n"
                                "GRI: PV,ATQ,ATS\n"
                                "Chaque POKéBLOC attire un TALENT CACHÉ."

                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    [HELP_GOLD_POKEBLOCK_WINDOW] =
    {
        .header = COMPOUND_STRING("MANGEOIRES : POKéBLOCS OR"),
        .desc = COMPOUND_STRING("Les POKéBLOCS OR attirent des POKéMON\n"
                                "avec 5 IV parfaits. La saveur détermine\n"
                                "quel IV ne sera pas parfait.\n"
                                "ÉPICÉ: sans ATQ SPÉ  SEC: sans ATTAQUE\n"
                                "SUCRÉ: sans DÉF SPÉ  AMER: sans VITESSE\n"
                                "ACIDE: sans PV\n"
                                "Chaque POKéBLOC attire un TALENT CACHÉ."
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_SMALL,
        .headerColor = {0, 8, 3},
    },
    // Add more entries
};
