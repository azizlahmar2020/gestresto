
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"repture.h"
#include<gtk/gtk.h>


void ProduitsRupture(char * fichierProduit, char * fichierRupture)
{ Matiere m1;
  FILE *f1,*f2;
   fichierProduit=fopen ("resto.txt","r+");
fichierRupture=fopen ("repture.txt","a+");
while (fscanf(fichierProduit,"%s %s %s %s %s %s %s\n",m1.ref,m1.nom,m1.date,m1.type,m1.quantite,m1.transaction,m1.unite)!=EOF)
{
if (strcmp(m1.quantite,"0")==0)
 fprintf(fichierRupture,"%s %s %s %s %s %s %s\n",m1.ref,m1.nom,m1.date,m1.type,m1.quantite,m1.transaction,m1.unite);
fclose(fichierProduit);
fclose(fichierRupture);}
}

