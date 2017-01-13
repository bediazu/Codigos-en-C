#include <gtk/gtk.h>

#include "Gui/gui.h"
#include <stdio.h>

int main(int argc,char* argv[]){
    generar_interfaz(argc,argv);
    gtk_main();
    return 0;
}

