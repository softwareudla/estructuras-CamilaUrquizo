
#include <stdio.h>
#include <string.h>
#include "funciones.h"


void leerCadena(char *cadena, int maxLength) {
    fgets(cadena, maxLength, stdin);
    cadena[strcspn(cadena, "\n")] = 0; 
}

void registrarLibro(struct Libro libros[], int *i) {
    if (*i < 20) {
        printf("Ingrese el titulo del libro: ");
        leerCadena(libros[*i].titulo, 100);
        printf("Ingrese el autor del libro: ");
        leerCadena(libros[*i].autor, 50);
        do{
            printf("Ingrese el anio de publicacion: ");
            scanf("%d", &libros[*i].anio);
            if (libros[*i].anio < 0)
            {
                printf("No puede ingresar un numero negativo, debe ser positivo");
                scanf("%d",&libros[*i].anio);
            }
            
        } while (libros[*i].anio < 0);

        
        libros[*i].id = *i + 1;
        printf("Seleccione el estado del libro (1 = Disponible, 2 = Prestado): ");
        scanf("%d", &libros[*i].estado);

        printf("Libro registrado con ID: %d\n", libros[*i].id);
        (*i)++;
    } else {
        printf("No se pueden registrar mas de 20 libros.\n");
    }
}

void mostrarLibros(struct Libro libros[], int i) {
    if (i == 0) {
        printf("No hay libros registrados.\n");
    } else {
        printf("\n%-5s | %-30s | %-20s | %-6s | %-10s |\n", "ID", "Titulo", "Autor", "Anio", "Estado");
        printf("--------------------------------------------------------------------------\n");
        for (int j = 0; j < i; j++) {
            printf("%-5d | %-30s | %-20s | %-6d | %-10s |\n", libros[j].id, libros[j].titulo, libros[j].autor, libros[j].anio,
                   libros[j].estado == 1 ? "Disponible" : "Prestado");
        }
    }
}


void mostrarLibrosAntesAccion(struct Libro libros[], int i) {
    printf("\nMostrando todos los libros antes de la operacion:\n");
    mostrarLibros(libros, i);
}


void buscarLibroId(struct Libro libros[], int i) {
    int id;
    mostrarLibrosAntesAccion(libros, i);
    printf("Ingrese el ID del libro a buscar: ");
    scanf("%d", &id);

    for (int j = 0; j < i; j++) {
        if (libros[j].id == id) {
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[j].id, libros[j].titulo, libros[j].autor, libros[j].anio,
                   libros[j].estado == 1 ? "Disponible" : "Prestado");
            return;
        }
    }

    printf("Libro con ID %d no encontrado.\n", id);
}


void buscarLibroTitulo(struct Libro libros[], int i) {
    char titulo[100];
    mostrarLibrosAntesAccion(libros, i);
    printf("Ingrese el titulo del libro a buscar: ");
    leerCadena(titulo, 100);

    for (int j = 0; j < i; j++) {
        if (strcmp(libros[j].titulo, titulo) == 0) {
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[j].id, libros[j].titulo, libros[j].autor, libros[j].anio,
                   libros[j].estado == 1 ? "Disponible" : "Prestado");
            return;
        }
    }

    printf("Libro con titulo '%s' no encontrado.\n", titulo);
}


void actualizarEstado(struct Libro libros[], int i) {
    int id, nuevoEstado;
    mostrarLibrosAntesAccion(libros, i);
    printf("Ingrese el ID del libro a actualizar: ");
    scanf("%d", &id);

    for (int j = 0; j < i; j++) {
        if (libros[j].id == id) {
            printf("Seleccione el nuevo estado (1 = Disponible, 2 = Prestado): ");
            scanf("%d", &nuevoEstado);
            if (nuevoEstado == 1 || nuevoEstado == 2) {
                libros[j].estado = nuevoEstado;
                printf("Estado del libro con ID %d actualizado a '%s'.\n", id,
                       libros[j].estado == 1 ? "Disponible" : "Prestado");
            } else {
                printf("Estado no valido. Operacion cancelada.\n");
            }
            return;
        }
    }

    printf("Libro con ID %d no encontrado.\n", id);
}


void eliminarLibro(struct Libro libros[], int *i) {
    int id;
    mostrarLibrosAntesAccion(libros, *i);
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int j = 0; j < *i; j++) {
        if (libros[j].id == id) {
            for (int k = j; k < *i - 1; k++) {
                libros[k] = libros[k + 1];
            }
            (*i)--;
            printf("Libro con ID %d eliminado.\n", id);
            return;
        }
    }

    printf("Libro con ID %d no encontrado.\n", id);
}
