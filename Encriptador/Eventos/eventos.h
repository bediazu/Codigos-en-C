#ifndef EVENTOS_H_INCLUDED
#define EVENTOS_H_INCLUDED

#include "../Gui/ventanas.h"
#include <ctype.h>

void activar_eventos();
void on_button_ok_clicked(GtkWidget*, gpointer);
void on_button_acercade_clicked(GtkWidget*, gpointer);
void ocultar_Dialogo(GtkWidget*, gpointer);
void encriptar();

#endif // EVENTOS_H_INCLUDED
