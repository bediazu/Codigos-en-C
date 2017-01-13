#include "gui.h"
#include "ventanas.h"
#include "../Eventos/eventos.h"

void generar_interfaz(int argc,char* argv[]){

    GtkBuilder* builder;

    gtk_init(&argc,&argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "GUI.glade", NULL);

    AcercaDe.ventana_acercade = GTK_WIDGET(gtk_builder_get_object(builder, "aboutdialog"));

    Principal.ventana_main = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    Principal.boton_ok = GTK_WIDGET(gtk_builder_get_object(builder, "button_ok"));
    Principal.boton_acercade = GTK_WIDGET(gtk_builder_get_object(builder, "button_about"));
    Principal.texto=GTK_WIDGET(gtk_builder_get_object(builder, "textview"));
    Principal.barra_carga=GTK_WIDGET(gtk_builder_get_object(builder, "levelbar"));

    Dialogo.ventana_dialogo = GTK_WIDGET(gtk_builder_get_object(builder, "dialog"));
    Dialogo.boton_ok = GTK_WIDGET(gtk_builder_get_object(builder, "button_ok_dialog"));
    Dialogo.boton_salir = GTK_WIDGET(gtk_builder_get_object(builder, "button_exit"));

    /**< EVENTOS */
    activar_eventos();

    gtk_widget_show(Principal.ventana_main);

}
