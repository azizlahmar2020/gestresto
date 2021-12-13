#include <gtk/gtk.h>


void
on_Ajout_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton_l_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_a_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_f_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_a_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_v_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Recherche_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifier2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_OK_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajout_a_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_affichage_a_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_recherche_a_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_a_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Retour_ajout_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Retour_rech_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Retour_affichage_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_Retour_supprimer_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Retour_modifier_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_ok1_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
