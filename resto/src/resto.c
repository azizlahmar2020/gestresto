
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"resto.h"
#include<gtk/gtk.h>

enum
{ 
	EREFERENCE,
	ENOM,
	EDATE,
	ETYPE,
	EQUANTITE,
	EUNITE,
	ETRANSACTION,
	COLUMNS,
};



///////////////////////////////////////////////
void ajouter(Matiere m)
{
FILE *f;
f = fopen("resto.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s\n",m.ref,m.nom,m.date,m.type,m.quantite,m.unite,m.transaction);

fclose(f);
}
}
///////////////////////////////////////////////
void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char nom[30];
	char reference[30];
	char date[30];
	char type[30];
	char quantite[30];
	char unite[30];
	char transaction[30];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Ref ", renderer, "text",EREFERENCE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",EDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	  renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Quantite", renderer, "text",EQUANTITE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Unité ", renderer, "text",EUNITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Transaction", renderer, "text",ETRANSACTION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);





	}
	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING );
	f=fopen("resto.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("resto.txt","a+");
		while(fscanf(f," %s %s %s %s %s %s %s ",reference,nom,date,type,quantite,unite,transaction)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter,EREFERENCE, reference, ENOM, nom, EDATE,date,ETYPE,type,EQUANTITE,quantite,EUNITE,unite,ETRANSACTION,transaction,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}





}
///////////////////////////////////////////////
void supprimer(Matiere m)
///////////////////////////////////////////////
{
Matiere m1;
FILE *f,*g;
	f=fopen("resto.txt","r");
	g=fopen("aux.txt","w");
	if( f==NULL  || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s %s\n",m1.ref,m1.nom,m1.date,m1.type,m1.quantite,m1.unite,m1.transaction)!=EOF)
		{
			if (strcmp(m.ref,m1.ref)!=0 || strcmp(m.nom,m1.nom)!=0 || strcmp(m.date,m1.date)!=0 || strcmp(m.type,m1.type)!=0 || strcmp(m.quantite,m1.quantite)!=0|| strcmp(m.transaction,m1.transaction)!=0|| strcmp(m.unite,m1.unite)!=0)
			fprintf(g,"%s %s %s %s %s %s %s\n",m1.ref,m1.nom,m1.date,m1.type,m1.quantite,m1.transaction,m1.unite);
		}
		fclose(f);
		fclose(g);
	
remove("resto.txt");
rename("aux.txt","resto.txt");
	}



}


void changer (char achanger[50],char critere[50],char refe[50]){      
Matiere m1;
FILE *f, *temp;
temp=fopen ("Temp.txt","a");
f=fopen ("resto.txt","r+");
while (fscanf(f,"%s %s %s %s %s %s %s\n",m1.ref,m1.nom,m1.date,m1.type,m1.quantite,m1.transaction,m1.unite)!=EOF)
{
if (strcmp(m1.ref,refe)==0){
if(strcmp(critere,"Reference")==0)   
{       
strcpy(m1.ref,achanger);}

if(strcmp(critere,"Nom")==0)    
{      
strcpy(m1.nom,achanger);     }

if(strcmp(critere,"Date")==0)    
{       
strcpy(m1.date,achanger);     }
if(strcmp(critere,"Type")==0)    
{      
   strcpy(m1.type,achanger);} 
if(strcmp(critere,"Unite")==0)    
{    strcpy(m1.unite,achanger);     }    
if(strcmp(critere,"Quantite")==0)    
{    strcpy(m1.quantite,achanger);     }
if(strcmp(critere,"Transaction")==0)    
{      strcpy(m1.transaction,achanger);    } 
}
 

fprintf(temp,"%s %s %s %s %s %s %s\n",m1.ref,m1.nom,m1.date,m1.type,m1.quantite,m1.unite,m1.transaction);
}
fclose(temp);
fclose(f);
remove ("resto.txt");
rename ("Temp.txt","resto.txt");
}


void recherche(GtkWidget *liste,char refe[50])
{
        GtkCellRenderer *renderer;
        GtkTreeViewColumn *column;
        GtkTreeIter iter;
        GtkListStore *store;
        char ref[30];
        char nom[30];
        char date[30];
        char type[30];
        char quantite[30];
	char unite[30];
	char transaction[30];
        store=NULL;
        FILE *f;
        store=gtk_tree_view_get_model(liste);

        if (store==NULL)
        {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("reference", renderer, "text",EREFERENCE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",EDATE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

       renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",EQUANTITE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("unite", renderer, "text",EUNITE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("transaction", renderer, "text",ETRANSACTION,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	}
        store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        f=fopen("resto.txt","r");
        if(f==NULL)
        {
                return;
        }
        else
        {
                f= fopen("resto.txt","a+");
                while(fscanf(f,"%s %s %s %s %s %s %s\n",ref,nom,date,type,quantite,unite,transaction)!=EOF)
                {if(strcmp(refe,ref)==0){
                        gtk_list_store_append(store, &iter);
                        gtk_list_store_set(store,&iter, EREFERENCE, ref, ENOM, nom,EDATE,date,ETYPE,type,EQUANTITE,quantite,EUNITE,unite,ETRANSACTION,transaction,-1);

                }}
                fclose(f);
                gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
                g_object_unref (store);
        }


}

