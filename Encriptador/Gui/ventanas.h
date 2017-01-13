#ifndef VENTANAS_H_INCLUDED
#define VENTANAS_H_INCLUDED

#include <gtk/gtk.h>

typedef struct about{
    GtkWidget* ventana_acercade;
}About;

 typedef struct dialog{
    GtkWidget* ventana_dialogo;
    GtkWidget* boton_ok;
    GtkWidget* boton_salir;
 }Dialog;

 typedef struct main_window{
    GtkWidget* ventana_main;
    GtkWidget* boton_ok;
    GtkWidget* boton_acercade;
    GtkWidget* texto;
    GtkWidget* barra_carga;
 }Main_Window;

 /**< CREACION DE VENTANAS */

 Dialog Dialogo;
 Main_Window Principal;
 About AcercaDe;

#endif // VENTANAS_H_INCLUDED
