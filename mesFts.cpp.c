#include<stdlib.h>
struct chauffeur
{
    char nom[50];
    int age;
    int emploi;
};
typedef struct chauffeur CHAUFFEUR;

struct ambulance
{

    int matricule;
    char type[50];
    int nbchauffeur;
    CHAUFFEUR*chauffeurs;
};
typedef struct ambulance AMBULANCE;

struct garage
{
    char localisation[50];
    char garde[50];
    int nbambulance;
    AMBULANCE*ambulances;
};
typedef struct garage GARAGE;

struct medicament
{
    char nom_medicament[50];
    int delai;

};
typedef struct medicament MEDICAMENT;

struct infirmiere
{
    char nom[50];
    int salaire;
    int nbmedicament;
    MEDICAMENT*medicaments;
};
typedef struct infirmiere INFIRMIERE;

struct chef
{
    char nom[50];
    int nbinfirmiere;
    INFIRMIERE*infirmieres;
};
typedef struct chef CHEF;

struct patient
{
    char nom[50];
    int identifiant;
    char cas[50];
   // int nbpatient;
};
typedef struct patient PATIENT;


struct assistant
{
    char nom[50];
    int salaire;
    int num;
   // int nbassistant;
};
typedef struct assistant ASSISTANT;

struct resultat
{
    char localisation[50];
    char garde[50];
};
typedef struct resultat RESULTAT;


GARAGE* allocationgarage(int);
void remplirgarage(GARAGE*, int);
AMBULANCE* allocationambulance(int);
void remplirambulance(AMBULANCE*, int);
CHAUFFEUR* allocationchauffeur(int);
void remplirchauffeur(CHAUFFEUR*, int);
CHEF* allocationchef(int);
void remplirchef(CHEF*, int);
INFIRMIERE* allocationinfirmiere(int);
void remplirinfirmiere(INFIRMIERE*, int);
MEDICAMENT* allocationmedicament(int);
void remplirmedicament(MEDICAMENT*, int);
void affichergarage(GARAGE*, int);
void afficherambulance(AMBULANCE*, int);
void afficherchauffeur(CHAUFFEUR*, int);
void afficherchef(CHEF*, int);
void afficherinfirmiere(INFIRMIERE*, int);
void affichermedicament(MEDICAMENT*, int);
PATIENT* allocationpatient(int);
void remplirpatient(PATIENT*, int);
void afficherpatient(PATIENT*, int);
ASSISTANT* allocationassistant(int);
void remplirassistant(ASSISTANT*, int);
void afficherassistant(ASSISTANT*, int);
AMBULANCE* ajoutambulance(AMBULANCE*, int*);
CHAUFFEUR* ajoutchauffeur(CHAUFFEUR*, int*);
CHAUFFEUR* travailplus(CHAUFFEUR*, int);
void afficherchauffeurleplusage(CHAUFFEUR*, int);
void afficherambulanceancienne(AMBULANCE*, int);
void affichermedicamentsexpires(MEDICAMENT*, int, int);
void afficherinfirmierelapluspayee(INFIRMIERE*, int);
void afficherchefplusdinfirmieres(CHEF*, int);
void afficherassistantpluspaye(ASSISTANT*, int);

