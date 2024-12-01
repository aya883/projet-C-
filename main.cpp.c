#include <stdio.h>
#include <stdlib.h>
#include "mesFcts.h"


int main() {
     int choix;
     GARAGE *tgrg;
     GARAGE grg;
     int nbgarage;
     printf("entrer le nbr garages:");
     scanf("%d",&nbgarage);
     tgrg=allocationgarage(nbgarage);
     remplirgarage(tgrg,nbgarage);
     printf("\n----------------\n");
     affichergarage(tgrg,nbgarage);





     CHEF *tchef;
     CHEF chef;
     int nbchef;
     printf("entrer le nbr des chefs:");
     scanf("%d",&nbchef);
     tchef=allocationchef(nbchef);
     remplirchef(tchef,nbchef);
     printf("\n******************\n");
     afficherchef(tchef,nbchef);




     PATIENT *tpat;

     int nbpatient,d;
     printf("entrer le nbr des patients:");
     scanf("%d",&nbpatient);
     tpat=allocationpatient(nbpatient);
     remplirpatient(tpat,nbpatient);
     printf("\n++++++++++++++++++\n");
     afficherpatient(tpat,nbpatient);


     ASSISTANT *tass;
     int nbassistant,e;
     printf("entrer le nbr des assistants:");
     scanf("%d",&nbassistant);
     tass=allocationassistant(nbassistant);
     remplirassistant(tass,nbassistant);
     printf("\n================\n");
     afficherassistant(tass,nbassistant);



     RESULTAT **result;
     int n,h;
     printf("saisir la taille du tableau:");
     scanf("%d",&n);
     result=(RESULTAT**)malloc(n*sizeof(RESULTAT*));
     if (!result) exit (-1);
     for (h=0;h<n;h++){
         *(result+h)=(RESULTAT*)malloc(n*sizeof(RESULTAT));
         if (! *(result+h)) exit(-2);
         printf("donner le resultat %d\n",h+1);
         printf("saisir la localisation:");
         scanf("%s",(*(result+h))->localisation);
         printf("saisir le garde:");
         scanf("%s",(*(result+h))->garde);}


     for (h=0;h<n;h++){
         printf("\n###################\n");
         printf("la localisation est: %s\n",(*(result+h))->localisation);
         printf("le garde est: %s\n",(*(result+h))->garde);
     }
    //do afficher_menu and traiterChoix

    AMBULANCE *ambulances;
    CHAUFFEUR *chauffeurs;
    INFIRMIERE *infirmieres;
    MEDICAMENT*medicaments;

    int   nbambulance = 0, nbchauffeur = 0, nbinfirmiere = 0, nbmedicament = 0, jourActuel ;

    traiterChoix(choix, tgrg, nbgarage, ambulances, nbambulance, chauffeurs, nbchauffeur, tchef, nbchef, infirmieres, nbinfirmiere, medicaments, nbmedicament, tass, nbassistant, tpat, nbpatient);
 }





void afficher_menu() {
    printf("\n====================== MENU ======================\n");
    printf("1. Ajouter une ambulance\n");
    printf("2. Ajouter un chauffeur\n");
    printf("3. Afficher le chauffeur qui travaille le plus\n");
    printf("4. Afficher le chauffeur le plus payé\n");
    printf("5. Afficher l'ambulance la plus ancienne\n");
    printf("6. Afficher les médicaments expirés\n");
    printf("7. Afficher l'infirmière la plus payée\n");
    printf("8. Afficher le chef avec le plus grand nombre d'infirmières\n");
    printf("9. Afficher l'assistant le mieux payé\n");
    printf("10. Quitter\n");
    printf("===================================================\n");
    printf("Choisir une option: ");
}
void traiterChoix(int choix, GARAGE* tgrg, int nbgarage, AMBULANCE* ambulances, int nbambulance,
                  CHAUFFEUR* chauffeurs, int nbchauffeur, CHEF* tchef, int nbchef,
                  INFIRMIERE* infirmieres, int nbinfirmiere, MEDICAMENT* medicaments, int nbmedicament,
                  ASSISTANT* tass, int nbassistant, PATIENT* tpat, int nbpatient, int jourActuel) {


    do {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
               ambulances=ajoutambulance(ambulances, &nbambulance);
                break;

            case 2:
                chauffeurs=ajoutchauffeur(chauffeurs, &nbchauffeur);
                break;

            case 3:
                chauffeurs=travailplus(chauffeurs, nbchauffeur);
                break;

            case 4:
                afficherchauffeurleplusage( chauffeurs, nbchauffeur);
                break;

            case 5:
                afficherambulanceancienne( ambulances, nbambulance);
                break;

            case 6:
                printf("entrer le jour actuel :");
                scanf("%d",&jourActuel);
                affichermedicamentsexpires( medicaments, nbmedicament, jourActuel);
                break;

            case 7:
                afficherinfirmierelapluspayee(infirmieres, nbinfirmiere);
                break;

            case 8:
                afficherchefplusdinfirmieres( tchef, nbchef);
                break;

            case 9:
                afficherassistantpluspaye( tass, nbassistant);
                break;


            case 10:
                printf("Sortie du programme.\n");
                break;


            default:
                printf("Choix invalide, réessayez.\n");
                break;
        }

    } while (choix != 0);

    // Libération de la mémoire
    for (int i = 0; i < nbgarage; i++) {
        for (int j = 0; j < (tgrg + i)->nbambulance; j++) {
            free(((tgrg + i)->ambulances + j)->chauffeurs);
        }
        free((tgrg + i)->ambulances);
    }
    free(tgrg);
    free(ambulances);
    free(chauffeurs);

                  }
