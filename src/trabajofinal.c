#include <stdio.h>
#include <stdlib.h>  
#include <windows.h> 
#include <string.h>  

typedef struct 
{
    char titulo[100];
    char descripcion[100];
    char estado[10];
    char dificultad;
    char Vencimiento[11];
    
} tarea;


void guardarTareas(tarea tareas[], int contador)
{

    FILE *archivo = fopen("mis_tareas.dat", "wb");


    if (archivo == NULL)
        return;


    fwrite(&contador, sizeof(int), 1, archivo);

    fwrite(tareas, sizeof(tarea), contador, archivo);

    fclose(archivo);
}


int cargarTareas(tarea tareas[])
{

    FILE *archivo = fopen("mis_tareas.dat", "rb");
    

    int contador = 0;

    if (archivo == NULL)
        return 0; 

    fread(&contador, sizeof(int), 1, archivo);

    fread(tareas, sizeof(tarea), contador, archivo);

    fclose(archivo);

    return contador;
}

int main()
{
    SetConsoleOutputCP(65001); 

    int opcion;
    int menutareas;
    tarea tareas[200]; 
    int seleccion_tarea;
    char opcion_edicion;
    int tarea_count = cargarTareas(tareas);

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

            if (tarea_count == 0)
            {
                system("cls");
                printf("No tienes tareas. \n");
                system("pause");
                break;
            }

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

                switch (menutareas)
                {
                case 1:
                    system("cls");
                    printf("Todas las tareas:\n");
                    for (int i = 0; i < tarea_count; i++)
                    {
                        printf("[%d] %s\n", i + 1, tareas[i].titulo);
                    }

                    printf("Seleccione una tarea para ver detalles (0 para volver): ");
                    scanf("%d", &seleccion_tarea);

                    system("cls");

                    if (seleccion_tarea > 0 && seleccion_tarea <= tarea_count)
                    {
                        int i = seleccion_tarea - 1;
                        printf("Detalles de la tarea seleccionada:\n");
                        printf("Tarea: %d \n", seleccion_tarea);
                        printf("Título: %s \n", tareas[i].titulo);
                        printf("Descripción: %s \n", tareas[i].descripcion);
                        printf("Estado: %s \n", tareas[i].estado);
                        printf("Dificultad: %c \n", tareas[i].dificultad);
                        printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                        printf("\n");

                        printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                        scanf(" %c", &opcion_edicion);

                        system("cls");

                        if (opcion_edicion == 'E' || opcion_edicion == 'e')
                        { 

                            printf("Esta es la tarea que elegiste, editando la tarea %d...\n\n", seleccion_tarea);

                            system("cls");
                            printf("Nuevo titulo: ");
                            scanf(" %[^\n]", tareas[i].titulo);

                            system("cls");
                            printf("Nueva descripcion: ");
                            scanf(" %[^\n]", tareas[i].descripcion);

                            system("cls");
                            printf("Nuevo estado (pendiente, en curso, terminada): ");
                            scanf(" %[^\n]", tareas[i].estado);

                            do
                            {
                                system("cls");

                                printf("Nueva dificultad (1-3): ");
                                scanf("%s", &tareas[i].dificultad);

                                if (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' ||tareas[i].dificultad == '3'))
                                {
                                    printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                    system("pause");
                                }

                            } while (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' ||tareas[i].dificultad == '3'));

                            system("cls");
                            printf("Nueva fecha de vencimiento: ");
                            scanf(" %[^\n]", tareas[i].Vencimiento);

                            system("cls");
                            printf("Tarea editada con exito. \n");

                            guardarTareas(tareas, tarea_count);

                            system("pause");
                        }
                        else
                        {
                            printf("Opcion invalida, \n");
                        }
                    }

                    break;

                case 2:
                    printf("Tareas pendientes:\n");
                    for (int i = 0; i < tarea_count; i++)
                    {
                        if (strcmp(tareas[i].estado, "pendiente") == 0)
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
                        printf("Dificultad: %c \n", tareas[i].dificultad);
                        printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);

                        printf("\n");

                        printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                        scanf(" %c", &opcion_edicion);

                        if (opcion_edicion == 'E' || opcion_edicion == 'e')
                        { 

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
                                scanf("%s", &tareas[i].dificultad);

                                if (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' || tareas[i].dificultad == '3'))
                                {
                                    printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                    system("pause");
                                    tareas[i].dificultad = 0; 
                                }
                            } while (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' ||tareas[i].dificultad == '3'));

                            printf("Tarea editada con exito. \n");

                            guardarTareas(tareas, tarea_count);

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
                        printf("Dificultad: %c \n", tareas[i].dificultad);
                        printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                        printf("\n");

                        printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                        scanf(" %c", &opcion_edicion);

                        if (opcion_edicion == 'E' || opcion_edicion == 'e')
                        { 

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
                                scanf("%s", &tareas[i].dificultad);

                                if (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' || tareas[i].dificultad == '3'))
                                {
                                    printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                }
                            } while (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' || tareas[i].dificultad == '3'));

                            printf("Tarea editada con exito. \n");

                            guardarTareas(tareas, tarea_count);

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
                        printf("Dificultad: %c \n", tareas[i].dificultad);
                        printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                        printf("\n");

                        printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                        scanf(" %c", &opcion_edicion);

                        if (opcion_edicion == 'E' || opcion_edicion == 'e')
                        { 

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
                                scanf("%s", &tareas[i].dificultad);

                                if (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' || tareas[i].dificultad == '3'))
                                {
                                    printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                }
                            } while (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' || tareas[i].dificultad == '3'));

                            printf("Tarea editada con exito. \n");

                            guardarTareas(tareas, tarea_count);

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
            if (tarea_count == 0)
            {
                system("cls");
                printf("No tienes tareas. \n");
                system("pause");
                break;
            }

            char buscar_titulo[100];
            int encontrado = 0;

            printf("Ingrese el titulo de la tarea a buscar: ");
            scanf(" %[^\n]", buscar_titulo); 
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
                    printf("Dificultad: %c \n", tareas[i].dificultad);
                    printf("Fecha de vencimiento: %s \n", tareas[i].Vencimiento);
                    printf("\n");

                    printf("¿Desea editar esta tarea? (E para editar / 0 para volver): ");
                    scanf(" %c", &opcion_edicion);

                    if (opcion_edicion == 'E' || opcion_edicion == 'e')
                    { 

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
                            scanf("%s", &tareas[i].dificultad);

                            if (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' || tareas[i].dificultad == '3'))
                            {
                                printf("Dificultad invalida. Debe ser entre 1 y 3. \n");
                                system("pause");
                            }
                        } while (!(tareas[i].dificultad == '1' || tareas[i].dificultad == '2' || tareas[i].dificultad == '3'));

                        printf("Nueva fecha de vencimiento (DD/MM/AAAA): ");
                        scanf(" %[^\n]", tareas[i].Vencimiento);

                        printf("Tarea editada con exito. \n");

                        guardarTareas(tareas, tarea_count);

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
            system("cls");
            printf("Ingrese el titulo de la tarea: ");
            scanf(" %[^\n]", tareas[tarea_count].titulo);
            printf("Ingrese la descripcion de la tarea: ");
            scanf(" %[^\n]", tareas[tarea_count].descripcion);
            printf("Ingrese el estado de la tarea(pendiente, en curso, terminada): ");
            scanf(" %[^\n]", tareas[tarea_count].estado);
            printf("Ingrese la dificultad de la tarea (1-3): ");
            scanf("%s", &tareas[tarea_count].dificultad);
            printf("Ingrse la fecha de vencimiento de la tarea (DD/MM/AAAA): ");
            scanf(" %[^\n]", tareas[tarea_count].Vencimiento);
            tarea_count++;
            guardarTareas(tareas, tarea_count);
            break;

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