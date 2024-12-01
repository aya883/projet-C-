
#include <stdio.h>
#include <stdlib.h>
#include "mesFcts.h"

GARAGE* allocationgarage(int nbgarage)
{   GARAGE *tgrg;
    tgrg=(GARAGE*)malloc(nbgarage*sizeof(GARAGE));
    if(!tgrg) exit (-1);
    return tgrg;
}
void remplirgarage(GARAGE* tgrg, int nbgarage) {

    for (int i = 0; i < nbgarage; i++) {
        printf("saisir les informations du garage %d\n", i + 1);
        printf("saisir la localisation:");
        scanf("%s", (tgrg + i)->localisation);
        printf("saisir le garde:");
        scanf("%s", (tgrg + i)->garde);
        printf("saisir le nbr d'ambulances:");
        scanf("%d", &(tgrg+i)->nbambulance);
        (tgrg + i)->ambulances = allocationambulance((tgrg+i)->nbambulance);
        remplirambulance((tgrg + i)->ambulances, (tgrg+i)->nbambulance);
    }
}
AMBULANCE* allocationambulance(int nbambulance)
{   AMBULANCE* ambulances;
    ambulances=(AMBULANCE*)malloc(nbambulance*sizeof(AMBULANCE));
    if (!ambulances) exit(-2);
    return ambulances;
}
void remplirambulance(AMBULANCE* ambulances, int nbambulance) {
    int i, nbchauffeur;
    for (int i = 0; i < nbambulance; i++) {
        printf("saisir les informations de l'ambulance %d\n", i + 1);
        printf("saisir la matricule:");
        scanf("%d", &(ambulances + i)->matricule);
        printf("saisir le type:");
        scanf("%s", (ambulances + i)->type);
        printf("entrer le nbr de chauffeurs:");
        scanf("%d", &(ambulances+i)->nbchauffeur);
        (ambulances + i)->chauffeurs = allocationchauffeur((ambulances+i)->nbchauffeur);
        remplirchauffeur((ambulances + i)->chauffeurs,(ambulances+i)->nbchauffeur);
    }
}
CHAUFFEUR* allocationchauffeur(int nbchauffeur) {
    CHAUFFEUR* chauffeurs;
    chauffeurs = (CHAUFFEUR*)malloc(nbchauffeur * sizeof(CHAUFFEUR));
    if (!chauffeurs) exit(-3);
    return chauffeurs;
}
void remplirchauffeur(CHAUFFEUR* chauffeurs, int nbchauffeur) {
    for (int k = 0; k < nbchauffeur; k++) {
        printf("saisir les informations du chauffeur %d\n", k + 1);
        printf("saisir le nom du chauffeur:");
        scanf("%s", (chauffeurs + k)->nom);
        printf("saisir l'age du chauffeur:");
        scanf("%d", &(chauffeurs + k)->age);
        printf("saisir l'emploi du chauffeur:");
        scanf("%d", &(chauffeurs + k)->emploi);
    }
}
CHEF* allocationchef(int nbchef)
{   CHEF * tchef;
    tchef=(CHEF*)malloc(nbchef*sizeof(CHEF));
    if(!tchef) exit (-1);
    return tchef;
}
void remplirchef(CHEF* tchef, int nbchef) {
    for (int a = 0; a < nbchef; a++) {
        printf("saisir les informations du chef %d\n", a + 1);
        printf("saisir le nom:");
        scanf("%s", (tchef + a)->nom);
        printf("saisir le nbr d'infirmiere:");
        scanf("%d", &(tchef + a)->nbinfirmiere);
        (tchef + a)->infirmieres= allocationinfirmiere((tchef + a)->nbinfirmiere);
        remplirinfirmiere((tchef + a)->infirmieres, (tchef + a)->nbinfirmiere);
    }
}
INFIRMIERE* allocationinfirmiere(int nbinfirmiere)
{   INFIRMIERE* infirmieres;
    infirmieres=(INFIRMIERE*)malloc(nbinfirmiere*sizeof(INFIRMIERE));
    if (!infirmieres) exit(-2);
    return infirmieres;
}
void remplirinfirmiere(INFIRMIERE* infirmieres, int nbinfirmiere) {
    for (int a = 0; a < nbinfirmiere; a++) {
        printf("saisir les informations de l'infirmiere %d\n", a + 1);
        printf("saisir le nom:");
        scanf("%s", (infirmieres + a)->nom);
        printf("saisir le salaire:");
        scanf("%d", &(infirmieres + a)->salaire);
        printf("saisir le nbr de medicaments:");
        scanf("%d", &(infirmieres + a)->nbmedicament);
        (infirmieres + a)->medicaments = allocationmedicament((infirmieres + a)->nbmedicament);
        remplirmedicament((infirmieres + a)->medicaments, (infirmieres + a)->nbmedicament);

    }
}
MEDICAMENT* allocationmedicament(int nbmedicament)
{   MEDICAMENT* medicaments;
    medicaments=(MEDICAMENT*)malloc(nbmedicament*sizeof(MEDICAMENT));
    if (!medicaments) exit(-3);
    return medicaments;
}
void remplirmedicament(MEDICAMENT* medicaments, int nbmedicament) {
    for (int c = 0; c < nbmedicament; c++) {
        printf("saisir les informations du medicament %d\n", c + 1);
        printf("saisir le nom du medicament:");
        scanf("%s", (medicaments + c)->nom_medicament);
        printf("saisir le delai:");
        scanf("%d", &(medicaments + c)->delai);
    }
}
void affichergarage(GARAGE* tgrg, int nbgarage) {
    for (int i = 0; i < nbgarage; i++) {
        printf("Garage %d:\n", i + 1);
        printf("Localisation: %s\n", (tgrg + i)->localisation);
        printf("Garde: %s\n", (tgrg + i)->garde);
        printf("Nombre d'ambulances: %d\n", (tgrg + i)->nbambulance);
        afficherambulance((tgrg + i)->ambulances,(tgrg + i)->nbambulance);
    }
}

void afficherambulance(AMBULANCE* ambulances, int nbambulance) {
    for (int i = 0; i < nbambulance; i++) {
        printf("Ambulance %d:\n", i + 1);
        printf("Matricule: %d\n", (ambulances + i)->matricule);
        printf("Type: %s\n", (ambulances + i)->type);
        printf("Nombre de chauffeurs: %d\n", (ambulances + i)->nbchauffeur);
        afficherchauffeur((ambulances + i)->chauffeurs,(ambulances + i)->nbchauffeur);

    }
}

void afficherchauffeur(CHAUFFEUR* chauffeurs, int nbchauffeur) {
    for (int k = 0; k < nbchauffeur; k++) {
        printf("Chauffeur %d:\n", k + 1);
        printf("Nom: %s\n", (chauffeurs + k)->nom);
        printf("Age: %d\n", (chauffeurs + k)->age);
        printf("Emploi: %d\n", (chauffeurs + k)->emploi);
    }
}

void afficherchef(CHEF* tchef, int nbchef) {
    for (int a = 0; a < nbchef; a++) {
        printf("Chef %d:\n", a + 1);
        printf("Nom: %s\n", (tchef + a)->nom);
        printf("Nombre d'infirmières: %d\n", (tchef + a)->nbinfirmiere);
        afficherinfirmiere((tchef + a)->infirmieres,(tchef + a)->nbinfirmiere);

    }
}

void afficherinfirmiere(INFIRMIERE* infirmieres, int nbinfirmiere) {
    for (int a = 0; a < nbinfirmiere; a++) {
        printf("Infirmière %d:\n", a + 1);
        printf("Nom: %s\n", (infirmieres + a)->nom);
        printf("Salaire: %d\n", (infirmieres + a)->salaire);
        printf("Nombre de médicaments: %d\n", (infirmieres + a)->nbmedicament);
        affichermedicament((infirmieres + a)->medicaments,(infirmieres + a)->nbmedicament);

    }
}

void affichermedicament(MEDICAMENT* medicaments, int nbmedicament) {
    for (int c = 0; c < nbmedicament; c++) {
        printf("Médicament %d:\n", c + 1);
        printf("Nom: %s\n", (medicaments + c)->nom_medicament);
        printf("Délai: %d\n", (medicaments + c)->delai);
    }
}
PATIENT* allocationpatient(int nbpatient)
{   PATIENT* tpat;
    tpat=(PATIENT*)malloc(nbpatient*sizeof(PATIENT));
    if(!tpat) exit (-1);
    return tpat;
}
void remplirpatient(PATIENT* tpat, int nbpatient) {
    for (int d = 0; d < nbpatient; d++) {
        printf("saisir les informations du patient %d\n", d + 1);
        printf("saisir le nom du patient:");
        scanf("%s", (tpat + d)->nom);
        printf("saisir l'identifiant du patient:");
        scanf("%d", &(tpat + d)->identifiant);
        printf("saisir le cas du patient:");
        scanf("%s", (tpat + d)->cas);
    }
}
void afficherpatient(PATIENT* tpat, int nbpatient) {
    for (int d = 0; d < nbpatient; d++) {
        printf("Patient %d:\n", d + 1);
        printf("Nom: %s\n", (tpat + d)->nom);
        printf("Identifiant: %d\n", (tpat + d)->identifiant);
        printf("Cas: %s\n", (tpat + d)->cas);
    }
}
ASSISTANT* allocationassistant(int nbassistant)
{   ASSISTANT* tass;
    tass=(ASSISTANT*)malloc(nbassistant*sizeof(ASSISTANT));
    if(!tass) exit (-1);
    return tass;
}
void remplirassistant(ASSISTANT* tass, int nbassistant) {
    for (int e = 0; e < nbassistant; e++) {
        printf("donner les informations de l'assistant %d\n", e + 1);
        printf("saisir le nom de l'assistant:");
        scanf("%s", (tass + e)->nom);
        printf("saisir le salaire:");
        scanf("%d", &(tass + e)->salaire);
        printf("saisir le numero de l'assistant:");
        scanf("%s", (tass + e)->num);
    }
}
void afficherassistant(ASSISTANT* tass, int nbassistant) {
    for (int e = 0; e < nbassistant; e++) {
        printf("Assistant %d:\n", e + 1);
        printf("Nom: %s\n", (tass + e)->nom);
        printf("Salaire: %d\n", (tass + e)->salaire);
        printf("Numéro: %s\n", (tass + e)->num);
    }
}
// Réallocation de mémoire pour les ambulances
AMBULANCE* ajoutambulance(AMBULANCE* ambulances, int* nbambulance) {

    AMBULANCE* temp = realloc(ambulances, (*nbambulance + 1) * sizeof(AMBULANCE));
    if (!temp) exit(-2);
    ambulances=temp;
    (*nbambulance)++;
    return ambulances;
}
// Réallocation de mémoire pour les chauffeurs
CHAUFFEUR* ajoutchauffeur(CHAUFFEUR* chauffeurs, int* nbchauffeur) {
    CHAUFFEUR*temp = realloc(chauffeurs, (*nbchauffeur + 1) * sizeof(CHAUFFEUR));
    if (!temp) exit(-3);
    chauffeurs=temp;
    (*nbchauffeur)++;
    return chauffeurs;
}

CHAUFFEUR* travailplus(CHAUFFEUR* chauffeurs, int nbchauffeur)
{
    if (nbchauffeur == 0) return NULL;  // Aucun chauffeur

    int max_heures = (chauffeurs)->emploi;
    CHAUFFEUR* chauffeur_max = chauffeurs;

    for (int i = 1; i < nbchauffeur; i++) {
        if ((chauffeurs + i)->emploi > max_heures) {
            max_heures = (chauffeurs + i)->emploi;
            chauffeur_max = (chauffeurs + i);
        }
    }

    return chauffeur_max;
}
void afficherchauffeurleplusage(CHAUFFEUR* chauffeurs, int nbchauffeur) {
    if (nbchauffeur == 0) {
        printf("Aucun chauffeur disponible.\n");
        return;
    }

    // Initialiser avec le premier chauffeur
    int maxAge = (chauffeurs + 0)->age;
    int indexMaxAge = 0;

    // Trouver le chauffeur le plus âgé
    for (int i = 1; i < nbchauffeur; i++) {
        if ((chauffeurs + i)->age > maxAge) {
            maxAge = (chauffeurs + i)->age;
            indexMaxAge = i;
        }
    }

    // Afficher les informations du chauffeur le plus âgé
    printf("Le chauffeur le plus âgé est:\n");
    printf("Nom: %s\n", (chauffeurs + indexMaxAge)->nom);
    printf("Age: %d\n", (chauffeurs + indexMaxAge)->age);
    printf("Emploi: %d\n", (chauffeurs + indexMaxAge)->emploi);
}

void afficherambulanceancienne(AMBULANCE* ambulances, int nbambulance) {
    if (nbambulance == 0) {
        printf("Aucune ambulance disponible.\n");
        return;
    }

    // Initialiser avec la première ambulance
    int minMatricule = (ambulances + 0)->matricule;
    int indexMinMatricule = 0;

    // Trouver l'ambulance avec la matricule la plus ancienne
    for (int i = 1; i < nbambulance; i++) {
        if ((ambulances + i)->matricule < minMatricule) {
            minMatricule = (ambulances + i)->matricule;
            indexMinMatricule = i;
        }
    }

    // Afficher les informations de l'ambulance avec la matricule la plus ancienne
    printf("L'ambulance avec la matricule la plus ancienne est:\n");
    printf("Matricule: %d\n", (ambulances + indexMinMatricule)->matricule);
    printf("Type: %s\n", (ambulances + indexMinMatricule)->type);}




void affichermedicamentsexpires(MEDICAMENT* medicaments, int nbmedicament, int jourActuel) {
    int count = 0;

    for (int i = 0; i < nbmedicament; i++) {
        if ((medicaments + i)->delai < jourActuel) {
            // Afficher les médicaments expirés
            printf("Médicament expiré %d:\n", i + 1);
            printf("Nom: %s\n", (medicaments + i)->nom_medicament);
            printf("Delai: %d jours\n", (medicaments + i)->delai);
            count++;
        }
    }

    if (count == 0) {
        printf("Aucun médicament expiré.\n");
    }
}


void afficherinfirmierelapluspayee(INFIRMIERE* infirmieres, int nbinfirmiere) {
    if (nbinfirmiere == 0) {
        printf("Aucune infirmière disponible.\n");
        return;
    }

    // Initialiser avec la première infirmière
    int maxSalaire = (infirmieres + 0)->salaire;
    int indexMaxSalaire = 0;

    // Trouver l'infirmière avec le salaire le plus élevé
    for (int i = 1; i < nbinfirmiere; i++) {
        if ((infirmieres + i)->salaire > maxSalaire) {
            maxSalaire = (infirmieres + i)->salaire;
            indexMaxSalaire = i;
        }
    }

    // Afficher les informations de l'infirmière la plus payée
    printf("L'infirmière la plus payée est:\n");
    printf("Nom: %s\n", (infirmieres + indexMaxSalaire)->nom);
    printf("Salaire: %d\n", (infirmieres + indexMaxSalaire)->salaire);
}



void afficherchefplusdinfirmieres(CHEF* tchef, int nbchef) {
    if (nbchef == 0) {
        printf("Aucun chef disponible.\n");
        return;
    }

    // Initialiser avec le premier chef
    int maxInfirmieres = (tchef + 0)->nbinfirmiere;
    int indexMaxInfirmieres = 0;

    // Trouver le chef avec le plus grand nombre d'infirmières
    for (int i = 1; i < nbchef; i++) {
        if ((tchef + i)->nbinfirmiere > maxInfirmieres) {
            maxInfirmieres = (tchef + i)->nbinfirmiere;
            indexMaxInfirmieres = i;
        }
    }

    // Afficher les informations du chef responsable du plus grand nombre d'infirmières
    printf("Le chef responsable du plus grand nombre d'infirmières est:\n");
    printf("Nom: %s\n", (tchef + indexMaxInfirmieres)->nom);
    printf("Nombre d'infirmières: %d\n", maxInfirmieres);
}



void afficherassistantpluspaye(ASSISTANT* tass, int nbassistant) {
    if (nbassistant == 0) {
        printf("Aucun assistant disponible.\n");
        return;
    }

    // Initialiser avec le premier assistant
    int maxSalaire = (tass + 0)->salaire;
    int indexMaxSalaire = 0;

    // Trouver l'assistant avec le salaire le plus élevé
    for (int i = 1; i < nbassistant; i++) {
        if ((tass + i)->salaire > maxSalaire) {
            maxSalaire = (tass + i)->salaire;
            indexMaxSalaire = i;
        }
    }

    // Afficher le numéro de l'assistant avec le salaire le plus élevé
    printf("L'assistant avec le salaire le plus élevé est:\n");
    printf("Numéro: %d\n", (tass + indexMaxSalaire)->num);
    printf("Salaire: %d\n", maxSalaire);
}

