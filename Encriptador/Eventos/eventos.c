#include "eventos.h"

void activar_eventos(){
    g_signal_connect((GObject *) Principal.ventana_main,"delete-event",(GCallback ) gtk_main_quit,NULL);
    g_signal_connect ((GObject *) Principal.boton_ok, "clicked", (GCallback) on_button_ok_clicked,(gpointer)Principal.texto);
    g_signal_connect ((GObject *) Principal.boton_acercade, "clicked", (GCallback) on_button_acercade_clicked,(gpointer)AcercaDe.ventana_acercade);
}

void on_button_ok_clicked(GtkWidget* widget, gpointer data)
{
    FILE* salida=fopen("temporal.txt","w");
    if(salida==NULL){
        g_printf("Error en la generacion del archivo temporal.");
    }
    GtkTextBuffer* buffer;
    buffer = gtk_text_view_get_buffer((GtkTextView*)data);

    GtkTextIter start, end;
    gchar* msg;
    gtk_text_buffer_get_bounds (buffer, &start, &end);
    msg = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);
    fprintf(salida,"%s",msg);
    msg=NULL;
    buffer=NULL;
    fclose(salida);
    encriptar();
    gtk_level_bar_set_value((GtkLevelBar*)Principal.barra_carga,1.0);

    gtk_widget_show(Dialogo.ventana_dialogo);
    g_signal_connect ((GObject *) Dialogo.boton_salir, "clicked", (GCallback) gtk_main_quit,NULL);
    g_signal_connect ((GObject *) Dialogo.boton_ok, "clicked",(GCallback)ocultar_Dialogo,Dialogo.ventana_dialogo);

}

void on_button_acercade_clicked(GtkWidget* widget, gpointer data)
{
    gtk_widget_show(data);
}

void ocultar_Dialogo(GtkWidget* widget, gpointer data){
    gtk_level_bar_set_value((GtkLevelBar*)Principal.barra_carga,0.0);
    gtk_widget_hide((GtkWidget*)data);
}

void encriptar(){
    char aux;
    FILE* salida=fopen("temporal.txt","r");
    if(salida==NULL){
        g_printf("Error en la generacion del archivo temporal.");
    }

    FILE* salida_encriptada=fopen("encriptado.vrx","w");
    if(salida_encriptada==NULL){
        g_print("Error en la creacion del archivo encriptado.");
    }
    while((aux=getc(salida))!=EOF){
        if(isalpha(aux)){
            aux+=3;
        }
        fprintf(salida_encriptada,"%c",aux);
    }
    fclose(salida);
    remove("temporal.txt");
    fclose(salida_encriptada);
}
