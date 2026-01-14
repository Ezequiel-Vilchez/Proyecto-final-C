#include <stdio.h>
#include <stdlib.h>  //libreria q me permite usar system("cls");
#include <windows.h> //libreria q me permite usar SetConsoleOutputCP(65001); para forzar la consola a usar UTF-8 en Windows
#include <string.h>  //libreria q me permite usar la funcion strcmp para comparar cadenas de texto

typedef struct // typedef lo q hace es crear un tipo de dato en el no vamos a tener q estar escribiendo struct todo el tiempo en parte q hacemos referencia a la estructura
{
    char titulo[100];
    char descripcion[100];
    char estado[10];
    int dificultad;
    char Vencimiento[11];
} tarea;

int main()
{
    SetConsoleOutputCP(65001); // Forzar la consola a usar UTF-8 (Windows)

    int opcion;
    int menutareas;
    tarea tareas[10]; // limite de tareas
    int tarea_count = 0;
    int seleccion_tarea;
    char opcion_edicion;

    do
    {
        system("cls");
        printf("¡Hola!\n");
        printf("¿Que desea hacer?\n");
        printf("[1] Ver mis tareas.\n");
        printf("[2] Buscar una tarea.\n");
        printf("[3] Agregar una tarea.\n");
        printf("[4] Salir.\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            do
            {
                system("cls");
                printf("Que tareas deseas ver?\n");
                printf("[1] Todas\n");
                printf("[2] Pendientes\n");
                printf("[3] En curso\n");
                printf("[4] Terminadas\n");
                printf("[0] Volver\n");
                scanf("%d", &menutareas);
                system("cls");

                switch (menutareas)
                {
                case 1:
                    if (tarea_count == 0)
                    {
                        system("cls");
                        printf("No tienes tareas. \n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("Todas las tareas:\n");
                        for (int i = 0; i < tarea_count; i++)
                        {
                            printf("[%d] %s\n", i + 1, tareas[i].titulo);
                        }
                        printf("Seleccione una tarea para ver detalles (0 para volver): ");
                        scanf("%d", &seleccion_tarea);
                        if (seleccion_tarea > 0 && seleccion_tarea <= tarea_count)
                        {
                            int i = seleccion_tarea - 1;
                            system("cls");
                            printf("Detalles de la tarea seleccionada:\n");
                            printf("Tarea: %d \n", seleccion_tarea);
                            printf("Título: %s \n", tareas[i].titulo);
                            printf("Descripción: %s \n", tareas[i].descripcion);
                            printf("Estado: %s \n", tareas[i].estado);
                            printf("Dificultad: %d \n", tareas[i].dificultad);
                            printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                            printf("\n");

                            printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                            scanf(" %c", &opcion_edicion);

                            if (opcion_edicion == 'E' || opcion_edicion == 'e')
                            { // uso comillas simples ('E') porque mi variable es de tipo char (un solo carácter). En C, las comillas dobles ("E") se usan para cadenas de texto (strings) y no se pueden comparar directamente con un char.

                                printf("Esta es la tarea que elegiste,editando tarea %d...\n", seleccion_tarea);

                                printf("Nuevo titulo: ");
                                scanf(" %[^\n]", tareas[i].titulo);

                                printf("Nueva descripcion: ");
                                scanf(" %[^\n]", tareas[i].descripcion);

                                printf("Nuevo estado (pendiente, en curso, terminada): ");
                                scanf(" %[^\n]", tareas[i].estado);

                                do
                                {
                                    printf("Nueva dificultad (1-3): ");
                                    scanf("%d", &tareas[i].dificultad);

                                    if (tareas[i].dificultad < 1 || tareas[i].dificultad > 3)
                                    {
                                        printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                    }
                                } while (tareas[i].dificultad < 1 || tareas[i].dificultad > 3);

                                printf("Nueva fecha de vencimiento (DD/MM/AAAA): ");
                                scanf(" %[^\n]", tareas[i].Vencimiento);

                                printf("Tarea editada con exito. \n");
                                system("pause");
                            }
                            else
                            {
                                printf("Numero invalido, \n");
                            }
                        }
                    }
                    break;

                case 2:
                    printf("Tareas pendientes:\n");
                    for (int i = 0; i < tarea_count; i++)
                    {
                        if (strcmp(tareas[i].estado, "pendiente") == 0)
                        { // compara si el estado de la tarea es igual a "pendiente",si es 0 es porque son iguales
                            printf("[%d] %s \n", i + 1, tareas[i].titulo);
                        }
                    }
                    printf("Seleccione una tarea para ver detalles (0 para volver): ");
                    scanf("%d", &seleccion_tarea);
                    if (seleccion_tarea > 0 && seleccion_tarea <= tarea_count)
                    {
                        int i = seleccion_tarea - 1;
                        system("cls");
                        printf("Detalles de la tarea seleccionada:\n");
                        printf("Tarea: %d \n", seleccion_tarea);
                        printf("Título: %s \n", tareas[i].titulo);
                        printf("Descripción: %s \n", tareas[i].descripcion);
                        printf("Estado: %s \n", tareas[i].estado);
                        printf("Dificultad: %d \n", tareas[i].dificultad);
                        printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);

                        printf("\n");

                        printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                        scanf(" %c", &opcion_edicion);

                        if (opcion_edicion == 'E' || opcion_edicion == 'e')
                        { // uso comillas simples ('E') porque mi variable es de tipo char (un solo carácter). En C, las comillas dobles ("E") se usan para cadenas de texto (strings) y no se pueden comparar directamente con un char.

                            printf("Esta es la tarea que elegiste,editando tarea %d...\n", seleccion_tarea);

                            printf("Nuevo titulo: ");
                            scanf(" %[^\n]", tareas[i].titulo);

                            printf("Nueva descripcion: ");
                            scanf(" %[^\n]", tareas[i].descripcion);

                            printf("Nuevo estado (pendiente, en curso, terminada): ");
                            scanf(" %[^\n]", tareas[i].estado);

                            printf("Nueva fecha de vencimiento (DD/MM/AAAA): ");
                            scanf(" %[^\n]", tareas[i].Vencimiento);

                            do
                            {
                                printf("Nueva dificultad (1-3): ");
                                scanf("%d", &tareas[i].dificultad);

                                if (tareas[i].dificultad < 1 || tareas[i].dificultad > 3)
                                {
                                    printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                }
                            } while (tareas[i].dificultad < 1 || tareas[i].dificultad > 3);

                            printf("Tarea editada con exito. \n");
                            system("pause");
                        }
                        else
                        {
                            printf("Numero invalido, \n");
                        }
                    }
                    break;
                case 3:
                    printf("Tareas en curso:\n");
                    for (int i = 0; i < tarea_count; i++)
                    {
                        if (strcmp(tareas[i].estado, "en curso") == 0)
                        {
                            printf("[%d] %s \n", i + 1, tareas[i].titulo);
                        }
                    }
                    printf("Seleccione una tarea para ver detalles (0 para volver): ");
                    scanf("%d", &seleccion_tarea);
                    if (seleccion_tarea > 0 && seleccion_tarea <= tarea_count)
                    {
                        int i = seleccion_tarea - 1;
                        system("cls");
                        printf("Detalles de la tarea seleccionada:\n");
                        printf("Tarea: %d \n", seleccion_tarea);
                        printf("Título: %s \n", tareas[i].titulo);
                        printf("Descripción: %s \n", tareas[i].descripcion);
                        printf("Estado: %s \n", tareas[i].estado);
                        printf("Dificultad: %d \n", tareas[i].dificultad);
                        printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                        printf("\n");

                        printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                        scanf(" %c", &opcion_edicion);

                        if (opcion_edicion == 'E' || opcion_edicion == 'e')
                        { // uso comillas simples ('E') porque mi variable es de tipo char (un solo carácter). En C, las comillas dobles ("E") se usan para cadenas de texto (strings) y no se pueden comparar directamente con un char.

                            printf("Esta es la tarea que elegiste,editando tarea %d...\n", seleccion_tarea);

                            printf("Nuevo titulo: ");
                            scanf(" %[^\n]", tareas[i].titulo);

                            printf("Nueva descripcion: ");
                            scanf(" %[^\n]", tareas[i].descripcion);

                            printf("Nuevo estado (pendiente, en curso, terminada): ");
                            scanf(" %[^\n]", tareas[i].estado);

                            printf("Nueva fecha de vencimiento (DD/MM/AAAA): ");
                            scanf(" %[^\n]", tareas[i].Vencimiento);

                            do
                            {
                                printf("Nueva dificultad (1-3): ");
                                scanf("%d", &tareas[i].dificultad);

                                if (tareas[i].dificultad < 1 || tareas[i].dificultad > 3)
                                {
                                    printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                }
                            } while (tareas[i].dificultad < 1 || tareas[i].dificultad > 3);

                            printf("Tarea editada con exito. \n");
                            system("pause");
                        }
                        else
                        {
                            printf("Numero invalido, \n");
                        }
                    }
                    break;
                case 4:
                    for (int i = 0; i < tarea_count; i++)
                    {
                        if (strcmp(tareas[i].estado, "terminada") == 0)
                        {
                            printf("[%d] %s \n", i + 1, tareas[i].titulo);
                        }
                    }
                    printf("Seleccione una tarea para ver detalles (0 para volver): ");
                    scanf("%d", &seleccion_tarea);
                    if (seleccion_tarea > 0 && seleccion_tarea <= tarea_count)
                    {
                        int i = seleccion_tarea - 1;
                        system("cls");
                        printf("Detalles de la tarea seleccionada:\n");
                        printf("Tarea: %d \n", seleccion_tarea);
                        printf("Título: %s \n", tareas[i].titulo);
                        printf("Descripción: %s \n", tareas[i].descripcion);
                        printf("Estado: %s \n", tareas[i].estado);
                        printf("Dificultad: %d \n", tareas[i].dificultad);
                        printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                        printf("\n");

                        printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                        scanf(" %c", &opcion_edicion);

                        if (opcion_edicion == 'E' || opcion_edicion == 'e')
                        { // uso comillas simples ('E') porque mi variable es de tipo char (un solo carácter). En C, las comillas dobles ("E") se usan para cadenas de texto (strings) y no se pueden comparar directamente con un char.

                            printf("Esta es la tarea que elegiste,editando tarea %d...\n", seleccion_tarea);

                            printf("Nuevo titulo: ");
                            scanf(" %[^\n]", tareas[i].titulo);

                            printf("Nueva descripcion: ");
                            scanf(" %[^\n]", tareas[i].descripcion);

                            printf("Nuevo estado (pendiente, en curso, terminada): ");
                            scanf(" %[^\n]", tareas[i].estado);

                            printf("Nueva fecha de vencimiento (DD/MM/AAAA): ");
                            scanf(" %[^\n]", tareas[i].Vencimiento);

                            do
                            {
                                printf("Nueva dificultad (1-3): ");
                                scanf("%d", &tareas[i].dificultad);

                                if (tareas[i].dificultad < 1 || tareas[i].dificultad > 3)
                                {
                                    printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                }
                            } while (tareas[i].dificultad < 1 || tareas[i].dificultad > 3);

                            printf("Tarea editada con exito. \n");
                            system("pause");
                        }
                        else
                        {
                            printf("Numero invalido, \n");
                        }
                    }
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion no valida.\n");
                    break;
                }
            } while (menutareas != 0);
            break;

        case 2:
        {
            char buscar_titulo[100];
            int encontrado = 0;

            printf("Ingrese el titulo de la tarea a buscar: ");
            scanf(" %[^\n]", buscar_titulo); // esa funcion le dice al scanf " %[^\n]" que ignore cualquier "basura" de espacio en blanco (espacios, tabs o enters viejos) que haya quedado en el buffer de entrada antes de empezar a leer la nueva frase.
            for (int i = 0; i < tarea_count; i++)
            {
                if (strcmp(tareas[i].titulo, buscar_titulo) == 0)
                {
                    printf("\nEstas son las tareas relacionadas:\n");
                    printf("[%d] %s \n", i + 1, tareas[i].titulo);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                printf("\nNo se encontro ninguna tarea con el titulo: %s \n", buscar_titulo);
                system("pause");
            }
            else
            {
                printf("Seleccione una tarea para ver detalles (0 para volver): ");
                scanf("%d", &seleccion_tarea);
                if (seleccion_tarea > 0 && seleccion_tarea <= tarea_count)
                {
                    int i = seleccion_tarea - 1;
                    system("cls");
                    printf("Detalles de la tarea seleccionada:\n");
                    printf("Tarea: %d \n", seleccion_tarea);
                    printf("Título: %s \n", tareas[i].titulo);
                    printf("Descripción: %s \n", tareas[i].descripcion);
                    printf("Estado: %s \n", tareas[i].estado);
                    printf("Dificultad: %d \n", tareas[i].dificultad);
                    printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                    printf("\n");

                    printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                    scanf(" %c", &opcion_edicion);

                    if (opcion_edicion == 'E' || opcion_edicion == 'e')
                    { // uso comillas simples ('E') porque mi variable es de tipo char (un solo carácter). En C, las comillas dobles ("E") se usan para cadenas de texto (strings) y no se pueden comparar directamente con un char.

                        printf("Esta es la tarea que elegiste,editando tarea %d...\n", seleccion_tarea);

                        printf("Nuevo titulo: ");
                        scanf(" %[^\n]", tareas[i].titulo);

                        printf("Nueva descripcion: ");
                        scanf(" %[^\n]", tareas[i].descripcion);

                        printf("Nuevo estado (pendiente, en curso, terminada): ");
                        scanf(" %[^\n]", tareas[i].estado);

                        do
                        {
                            printf("Nueva dificultad (1-3): ");
                            scanf("%d", &tareas[i].dificultad);

                            if (tareas[i].dificultad < 1 || tareas[i].dificultad > 3)
                            {
                                printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                            }
                        } while (tareas[i].dificultad < 1 || tareas[i].dificultad > 3);

                        printf("Nueva fecha de vencimiento (DD/MM/AAAA): ");
                        scanf(" %[^\n]", tareas[i].Vencimiento);

                        printf("Tarea editada con exito. \n");
                        system("pause");
                    }
                    else
                    {
                        printf("Numero invalido, \n");
                    }
                }
            }
        }

        case 3:
            printf("Ingrese el titulo de la tarea: ");
            scanf(" %[^\n]", tareas[tarea_count].titulo);
            printf("Ingrese la descripcion de la tarea: ");
            scanf(" %[^\n]", tareas[tarea_count].descripcion);
            printf("Ingrese el estado de la tarea(pendiente, en curso, terminada): ");
            scanf(" %[^\n]", tareas[tarea_count].estado);
            printf("Ingrese la dificultad de la tarea (1-3): ");
            scanf("%d", &tareas[tarea_count].dificultad);
            printf("Ingrse la fecha de vencimiento de la tarea (DD/MM/AAAA): ");
            scanf(" %[^\n]", tareas[tarea_count].Vencimiento);
            tarea_count++;
            break;
            system("cls");

        case 4:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida.\n");
            break;
        }
    } while (opcion != 4);
    return 0;
}