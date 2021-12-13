#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "resto.h"
char choix[30]="";
int choix2=1;


///////////////////////////////////ajout////////////////////////////////////////////////

void
on_Ajout_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2, *input3, *input5,*input6,*input7,*input8;
GtkWidget *fenetre_ajout;
int jour=1;
int mois=1;
int annee=2021;
char sjour[10],smois[10],sannee[10],retour[50];;
fenetre_ajout=lookup_widget(objet_graphique,"ajout");

input1=lookup_widget(objet_graphique,"entry_produit");
input2=lookup_widget(objet_graphique,"entry_refrenece");
input3=lookup_widget(objet_graphique,"entry_quantit");


input6=lookup_widget(objet_graphique,"spinbutton_j");
input7=lookup_widget(objet_graphique,"spinbutton_m");
input8=lookup_widget(objet_graphique,"spinbutton_a");

Matiere m;
jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
strcpy(retour,"");
if (choix2==1) strcpy(retour,"Légume");
if (choix2==2) strcpy(retour,"Alimente");
if (choix2==3) strcpy(retour,"Fruite");

sprintf(sjour,"%d",jour);
sprintf(smois,"%d",mois);
sprintf(sannee,"%d",annee);

GtkWidget *combo;
combo=lookup_widget(objet_graphique,"combobox");
strcpy(m.unite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));

strcat(sjour,"/");
strcat(sjour,smois);
strcat(sjour,"/");
strcat(sjour,sannee);


strcpy(m.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(m.type,retour);
strcpy(m.ref,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(m.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(m.date,sjour);
//strcpy(m.unite,unite);
strcpy(m.transaction,choix);
ajouter(m);

GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"ajout");
gtk_widget_destroy(fenetre);

}
///////////////////////////////radiobutton//////////////////////////////////////////////

void
on_radiobutton_l_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2=1;
}


void
on_radiobutton_a_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2=2;
}


void
on_radiobutton_f_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix2=3;
}


void
on_checkbutton_a_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{//strcat(choix,"-Achat-");
strcpy(choix,"achat");
}


void
on_checkbutton_v_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{//strcat(choix,"-Vente");
strcpy(choix,"vente");
}


///////////////////////////////////////////////////////////////////////////////////////
void on_Recherche_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *input1;
char ref[50];
input1=lookup_widget(objet_graphique,"entry_ref");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher ();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");

recherche(treeview1,ref);
GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"Rech");
gtk_widget_destroy(fenetre);
}

///////////////////////////////////////////////////////////////////////////////
void
on_modifier2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_fenetre_modifier ();
  gtk_widget_show (window1);



}

/////////////////////////////////////////////////////////
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

     GtkTreeIter iter;
        gchar* nom;
        gchar* reference;
        gchar* date;
        gchar* type;
        gchar* quantite;
	gchar* unite;
        gchar* transaction;

       Matiere m;

        GtkTreeModel *model = gtk_tree_view_get_model(treeview);
        if (gtk_tree_model_get_iter(model, &iter ,path))
        {

                gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &reference, 1,  &nom, 2, &date , 3, &type,4,&quantite,5,&unite,6,&transaction,-1);

                
                
                strcpy(m.ref,reference);
   		strcpy(m.nom,nom);
                strcpy(m.date,date);
                strcpy(m.type,type);
                strcpy(m.quantite,quantite);
		strcpy(m.unite,unite);
		strcpy(m.transaction,transaction);
               supprimer(m);
                afficher(treeview);
        }
}

////////////////////////////////////////////////////////////////////////
void
on_OK_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *input1;
char ref[30];
input1=lookup_widget(objet_graphique,"entry_ref");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));
// supprimer(ref);
}
///////////////////////////////////////////////////////////////////////

void
on_ajout_a_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_ajout ();
  gtk_widget_show (window1);
}



/////////////////////////////////////////////////////////////////////////////////
void
on_affichage_a_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");
 afficher(treeview1);


}
//////////////////////////////////////////////////////////////////////////////

void
on_recherche_a_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_Rech ();
  gtk_widget_show (window1);
}

///////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

void
on_Retour_ajout_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"ajout");
gtk_widget_destroy(fenetre);
}
////////////////////////////////////////////////////////////////////////

void
on_Retour_rech_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"Rech");
gtk_widget_destroy(fenetre);
}

//////////////////////////////////
void
on_Retour_affichage_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"fenetre_afficher");
gtk_widget_destroy(fenetre);
}


////////////////////////////////

void
on_Retour_supprimer_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"supp");
gtk_widget_destroy(fenetre);

}
////////////////////////////

void
on_Retour_modifier_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"fenetre_modifier");
gtk_widget_destroy(fenetre);
}




void
on_Modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
  window1 = create_fenetre_modifier ();
  gtk_widget_show (window1);
}


void
on_ok1_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{char ref[50];
char amodifier[50];
char critere[50];

GtkWidget *input1,*input2,*combo;
GtkWidget *sortie;
input1=lookup_widget(objet_graphique,"entry1");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"entry2");
strcpy(amodifier,gtk_entry_get_text(GTK_ENTRY(input2)));
combo=lookup_widget(objet_graphique,"combobox1");
strcpy(critere,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));

changer ( amodifier,critere,ref);
sortie=lookup_widget(objet_graphique,"labels");
gtk_label_set_text(GTK_LABEL(sortie),amodifier);
GtkWidget *fenetre;
fenetre=lookup_widget(objet_graphique,"fenetre_modifier");
gtk_widget_destroy(fenetre);
}

