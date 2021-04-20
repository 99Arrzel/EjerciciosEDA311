#include "HITO3_P3_PUNTEROS.h"
int opt = 0, size = 0;

void menu()
{
    std::cout << "1)Hallar el promedio total de n números\n";
    std::cout << "2)Imprimir el ante penúltimo elemento de una lista de n elementos\n";
    std::cout << "3)Obtener un vector de otro vector, solo que con sus números impares divisibles entre 3\n";
    std::cout << "4)Intercambiar último con primer elemento\n";
    std::cout << "5)Multiplicar elementos pares x2\n";
}
void limpiar()
{
    std::cout << "\nPresione una tecla para volver al menú\n";
    getch();
    system("CLS");
}

void tarea1Ejecucion()
{
    Tarea1 tarea1;
    std::cout << "DE LOS NÚMEROS: \n";
    std::cout << "------------------------\n";
    tarea1.mostrarNumeros();
    std::cout << "\n------------------------\n";
    std::cout << "El promedio es: " << tarea1.promedio() << "\n";
}
void tarea2Ejecucion()
{
    Tarea2 tarea2;
    std::cout << "------------------------\n";
    tarea2.mostrarNumeros();
    std::cout << "\n------------------------\n";
    std::cout << "El ante penultimo es: " << tarea2.penultimo() << "\n";
}
void tarea3Ejecucion()
{
    Tarea3 tarea3;
    system("cls");
    tarea3.buildImpares();
    std::cout << "\n------N-----------------\n";
    tarea3.imprimirValoresNormales();
    std::cout << "\n--------I---------------\n";
    tarea3.imprimirValoresImpares();
}
void tarea4Ejecucion()
{
    Tarea4 tarea4;
    system("cls");
    tarea4.listarFinal();
}
void tarea5Ejecucion()
{
    Tarea5 tarea5;
    system("cls");
    std::cout << "--------------------\n";
    tarea5.listar();
    std::cout << "\n--------------------\n";
    tarea5.multiplicarPares();
    tarea5.listar();
}
void bancoEjecucion()
{
    int salir = 0;
    ColaBanco bnb; //Default constructor nos hace el favor acá
    do
    {
        system("cls");
        std::cout << "\n La cola actual es: \n";
        bnb.mostrarColaActual();
        std::cout << "\n ------------------ \n";
        std::cout << "0)Salir\n";
        std::cout << "1)Encolar\n";
        std::cout << "2)Desencolar\n";
        std::cout << "--Introduce una opción--\n";
        std::cin >> salir;
        switch (salir)
        {
        case 1:
        {
            bnb.Encolar();
            std::cout << "\n\npresione una tecla para continuar...\n";
            break;
        }
        case 2:
        {
            bnb.Desencolar();
            std::cout << "\n\npresione una tecla para continuar...\n";
            getch();
            break;
        }

        default:
            salir = 0;
            break;
        }

    } while (salir != 0);
}
int main()
{
    do
    {
        menu();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            system("cls");
            tarea1Ejecucion();
            limpiar();
            break;
        }
        case 2:
        {
            system("cls");
            tarea2Ejecucion();
            limpiar();
            break;
        }
        case 3:
        {
            system("cls");
            tarea3Ejecucion();
            limpiar();
            break;
        }
        case 4:
        {
            system("cls");
            tarea4Ejecucion();
            limpiar();
            break;
        }
        case 5:
        {
            system("cls");
            tarea5Ejecucion();
            limpiar();
            break;
        }
        case 13:
        {
            system("cls");
            bancoEjecucion();
            limpiar();
            break;
        }
        default:
            opt = 0;
            break;
        }
    } while (opt != 0);
    return 0;
}