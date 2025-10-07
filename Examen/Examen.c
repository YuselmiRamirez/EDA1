#include <stdio.h> //Libreria escencial para la entrada y salida de datos
#include <stdlib.h> //Libreria para el uso de malloc, realloc y free

int main() {
    int estudiantes, i, std, suma = 0; // Variables de tipo entero
    float *calificaciones = NULL; // Variable puntero de tipo flotante inicializada en NULL para indicar que no apunta a ningun lado
    float promedio; // Variable de tipo flotante. El tipo flotante almacena decimales

    printf("¿Cuántos estudiantes deseas agregar? ");
    scanf("%d", &estudiantes); //Entrada de datos a almacenar en la variable estudiantes

    if (estudiantes <= 0) {
        printf("Cantidad no válida.\n");
        return 0; // Cuando estudiantes es menor o igual a cero, imprime que la cantidad de estudiantes no es valida y reinicia el programa
    }

    calificaciones = (float*)malloc(estudiantes * sizeof(float));
    if (calificaciones == NULL) {
        printf("Error al asignar memoria.\n");
        return 0; // Asignacion para saber si malloc devuelve NULL, al hacerlo devuelve error
    }

    for (i = 0; i < estudiantes; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i]; // For para la lectura de calificaciones de los estudiantes
    }

    promedio = (float)suma / estudiantes;
    printf("El promedio inicial es de %.2f\n", promedio); // Ecuacion e impresion del promedio de las calificaciones dadas hasta el momento

    printf("¿Deseas agregar más estudiantes? (Cantidad, 0 para no): ");
    scanf("%d", &std); // Entrada de datos para saber si existen mas estudiantes a considerar

    if (std == 0) {
        free(calificaciones);
        printf("Hasta luego.\n");
        return 0; // Cuando n es igual a cero, se libera memoria con free, se imprime mensaje de despedida y cierra el programa
    }

    float *nuevas_calificaciones = (float*)realloc(calificaciones, (estudiantes + std) * sizeof(float));
    if (nuevas_calificaciones == NULL) {
        printf("Error al reasignar memoria.\n");
        free(calificaciones);
        return 0; // Reasignacion de memoria para mas estudiantes, en caso de ser requerido. Caso similar al de malloc donde sen revisa si realloc imprime NULL, y de ser asi indica el error
    }

    calificaciones = nuevas_calificaciones; // Reasignacion de valor a calificaciones

    for (i = estudiantes; i < estudiantes + std; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma = suma + calificaciones[i]; // Entrada de calificaciones de los nuevos estudiantes y operacion de suma 
    }

    estudiantes = estudiantes + std; // Reasignacion del valor inicial de estudiantes, agregando a los nuevos 
    promedio = (float)suma / estudiantes; // Ecuacion para sacar el promedio

    printf("\nCalificaciones registradas:\n");
    for (i = 0; i < estudiantes; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]); 
    }

    printf("Promedio general: %.2f\n", promedio); // Impresion de promedio final

    free(calificaciones); // Liberacion de memoria 
    printf("Memoria liberada correctamente.\n");

    return 0;
}