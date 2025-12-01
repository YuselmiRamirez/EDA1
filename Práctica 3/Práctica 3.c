#include <stdio.h>
#include <string.h>

#define TAM 10
#define NUM_DIR 2

struct pelicula {
    char nombre[20];
    char genero[20];
    int  y;
    int  numDirectores;
    char directores[NUM_DIR][20];
};

int cad(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

int main(void) {
    struct pelicula videoteca[TAM];
    int numPeliculas;

    printf("¿Cuantas peliculas deseas agregar a tu videoteca? (mÃ­nimo 1): ");
    scanf("%d", &numPeliculas);
    
    if (numPeliculas < 1 || numPeliculas > TAM) {
        printf("Hasta luego.\n");
        return 0;
    }

    for (int i = 0; i < numPeliculas; i++) {
        printf("\n** Pelicula %d **\n", i + 1);
        
        printf("Nombre: ");
        scanf(" %19[^\n]", videoteca[i].nombre);
        
        printf("Genero: ");
        scanf(" %19[^\n]", videoteca[i].genero);  
        
        printf("AÃ±o: ");
        scanf("%d", &videoteca[i].y);
        
        printf("Numero de directores (Minimo 1. Maximo 2): ");
        scanf("%d", &videoteca[i].numDirectores);
        if(videoteca[i].numDirectores > 1 || videoteca[i].numDirectores <= NUM_DIR) {
            for (int j = 0; j < videoteca[i].numDirectores; j++) {
                printf("Nombre del director %d: ", j + 1);
                scanf(" %19[^\n]", videoteca[i].directores[j]);
            }
        } else {
            printf("Numero de directores no valido.\n");
            return 0;
        }
    }

    printf("\n Contenido de la videoteca. \n");
    for (int i = numPeliculas - 1; i >= 0; i--) {
        printf("Pelicula: %s\n", videoteca[i].nombre);
        printf("Genero: %s\n", videoteca[i].genero);
        printf("Anio: %d\n", videoteca[i].y);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
    }

    int a, b;
    char op[20];

    printf("\n¿Deseas hacer una busqueda mas precisa de tu videoteca? (Si = 1, No = 2): ");
    scanf("%d", &a);

    if (a == 1) {
        printf("Menu de opciones:\n 1. Nombre\n 2. Anio\n 3. Genero\n 4. Director\n");
        scanf("%d", &b);

        if (b == 1) {
            printf("Nombre de la pelicula: ");
            scanf(" %19[^\n]", op);
            for (int i = 0; i < numPeliculas; i++) {
                if (cad(videoteca[i].nombre, op)) {
                    printf("\nTu pelicula es:\n");
                    printf("Nombre: %s\n", videoteca[i].nombre);
                    printf("Genero: %s\n", videoteca[i].genero);
                    printf("Anio: %d\n", videoteca[i].y);
                    for (int j = 0; j < videoteca[i].numDirectores; j++) {
                        printf("  - %s\n", videoteca[i].directores[j]);
                    }
                }
            }
        } else if (b == 2) {
            int aB;
            printf("Anio de la pelicula: ");
            scanf("%d", &aB);
            for (int i = 0; i < numPeliculas; i++) {
                if (videoteca[i].y == aB) {
                   printf("\nTu pelicula es:\n");
                    printf("Nombre: %s\n", videoteca[i].nombre);
                    printf("Genero: %s\n", videoteca[i].genero);
                    printf("Anio: %d\n", videoteca[i].y);
                    for (int j = 0; j < videoteca[i].numDirectores; j++) {
                        printf("  - %s\n", videoteca[i].directores[j]);
                    }
                }
            }
        } else if (b == 3) {
            printf("Genero de la pelicula: ");
            scanf(" %19[^\n]", op);
            for (int i = 0; i < numPeliculas; i++) {
                if (cad(videoteca[i].genero, op)) {
                     printf("\nTu pelicula es:\n");
                    printf("Nombre: %s\n", videoteca[i].nombre);
                    printf("Genero: %s\n", videoteca[i].genero);
                    printf("Anio: %d\n", videoteca[i].y);
                    for (int j = 0; j < videoteca[i].numDirectores; j++) {
                        printf("  - %s\n", videoteca[i].directores[j]);
                    }
                }
            }
        } else if (b == 4) {
            printf("Director de la pelicula: ");
            scanf(" %19[^\n]", op);
            for (int i = 0; i < numPeliculas; i++) {
                for (int j = 0; j < videoteca[i].numDirectores; j++) {
                    if (cad(videoteca[i].directores[j], op)) {
                          printf("\nTu pelicula es:\n");
                    printf("Nombre: %s\n", videoteca[i].nombre);
                    printf("Genero: %s\n", videoteca[i].genero);
                    printf("Anio: %d\n", videoteca[i].y);
                    for (int j = 0; j < videoteca[i].numDirectores; j++) {
                        printf("  - %s\n", videoteca[i].directores[j]);
                        }
                    }
                }
            }
        } 
        else {
            printf("Opcion no valida.\n");
        }
    }
    else {
        printf("Hasta luego.\n");
    }

    return 0;
