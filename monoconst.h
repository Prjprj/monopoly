/************************************
*                                   *
*                                   *
*                                   *
*            monoconst.h            *
*        Créé pour le projet        *
*            Monopoly               *
*                                   *
*                                   *
*    Pierre Ramos                   *
*    Laurent Nguyen                 *
*    Azouaou Sardou                 *
*                                   *
*                                   *
*                                   *
*                                   *
*                                   *
*                                   *
************************************/
#define PI 3.14159265
/*Constantes spécifiques au jeu*/
#define NBCASESPLATEAU 40
#define NBPROPRIETE 22
#define NBGARES 4
#define NBCOMPAGNIE 2
#define FONDSDEPART 150000
#define LONGNOMMAX 50
#define NBJOUEURMAX 8
#define NBJOUEURSMIN 2
#define NBDES 2
#define FACESDES 6
#define NBHOTELS 12
#define NBMAISONS 32
#define LONGCODE 8
#define SORTIEPRISON 5000
#define PASSAGEDEPART 20000
#define NBCARTECHANCE 12
#define NBCARTECAISSE 12
#define NBTOURPRISON  3
#define NBCOULEUR 8
/* Constantes de couleurs */
/* Arrière-plan */
#define BNOIR       0
#define BROUGE     BACKGROUND_RED              // 64
#define BVERT      BACKGROUND_GREEN            // 32
#define BBLEU      BACKGROUND_BLUE             // 16
#define BGRIS      BROUGE | BVERT | BBLEU      // 112
#define BINTENS    BACKGROUND_INTENSITY          
#define BVIOLET    BROUGE | BBLEU              // 80
#define BMARRON    BROUGE | BVERT              // 96
#define BBLEUC     BBLEU | BVERT               // 48
#define BROSE1     BROUGE |  BINTENS           // 192 
#define BVERTC     BVERT |  BINTENS            // 160
#define BVBLEUC    BBLEU |  BINTENS            // 144 
#define BBLANC     BGRIS | BINTENS             // 240 
#define BROSE2     BVIOLET | BINTENS           // 208 
#define BJAUNE     BMARRON | BINTENS           // 224
#define BTURQ      BBLEUC | BINTENS            // 176
/* Caractères */
#define FNOIR	   16
#define FROUGE     FOREGROUND_RED              // 4
#define FVERT      FOREGROUND_GREEN            // 2
#define FBLEU      FOREGROUND_BLUE             // 1
#define FGRIS      FROUGE | FVERT | FBLEU      // 7 
#define FINTENS    FOREGROUND_INTENSITY
#define FVIOLET    FROUGE | FBLEU              // 5
#define FMARRON    FROUGE | FVERT              // 6 
#define FBLEUC     FBLEU | FVERT               // 3
#define FROSE1     FROUGE |  FINTENS           // 12
#define FVERTC     FVERT |  FINTENS            // 10 
#define FVBLEUC    FBLEU |  FINTENS            // 9
#define FBLANC     FGRIS | FINTENS             // 15
#define FROSE2     FVIOLET | FINTENS           // 13 
#define FJAUNE     FMARRON | FINTENS           // 14
#define FTURQ      FBLEUC | FINTENS            // 11
