
#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    struct Libro libros[20]; 
    int i = 0; 
    int opcion; 

    do {
        printf("\nMENU\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro por ID\n");
        printf("4. Buscar libro por titulo\n");
        printf("5. Actualizar estado de libro\n");
        printf("6. Eliminar libro\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        while (getchar() != '\n'); 
        switch(opcion) {
            case 1:
                registrarLibro(libros, &i);
                break;
            case 2:
                mostrarLibrosAntesAccion(libros, i);
                break;
            case 3:
                buscarLibroId(libros, i);
                break;
            case 4:
                buscarLibroTitulo(libros, i);
                break;
            case 5:
                actualizarEstado(libros, i);
                break;
            case 6:
                eliminarLibro(libros, &i);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while(opcion != 7);

    return 0;
}
