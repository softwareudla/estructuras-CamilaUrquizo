struct Libro {
    int id;             
    char titulo[100];   
    char autor[50];     
    int anio;           
    int estado;         
};


void registrarLibro(struct Libro libros[], int *i);
void mostrarLibros(struct Libro libros[], int i);
void mostrarLibrosAntesAccion(struct Libro libros[], int i);
void buscarLibroId(struct Libro libros[], int i);
void buscarLibroTitulo(struct Libro libros[], int i);
void actualizarEstado(struct Libro libros[], int i);
void eliminarLibro(struct Libro libros[], int *i);
void leerCadena(char *cadena, int maxLength);
