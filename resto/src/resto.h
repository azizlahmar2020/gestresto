#include<gtk/gtk.h>


typedef struct matiere
{
char nom[30];
char ref[30];
char date[30];
char type[30];
char quantite[30];
char unite [30];
char transaction[30]
}Matiere;

void  ajouter(Matiere m);
void  afficher(GtkWidget *liste);

void supprimer(Matiere m);
void changer (char achanger[50],char critere[50],char ref[50]);
void recherche(GtkWidget *liste,char refe[50]);

