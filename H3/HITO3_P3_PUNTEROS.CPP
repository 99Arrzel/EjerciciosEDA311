#include "HITO3_P3_PUNTEROS.h"
int opt = 0, size = 0;


void menu()
{
    std::cout << "1)Hallar el promedio total de n números\n";
    std::cout << "2)Imprimir el ante penúltimo elemento de una lista de n elementos\n";
    std::cout << "3)Obtener un vector de otro vector, solo que con sus números impares divisibles entre 3\n";
    std::cout << "4)Intercambiar último con primer elemento\n";
    std::cout << "5)Multiplicar elementos pares x2\n";
    std::cout << "6)Contar capicuas(Números palindromos)\n";
    std::cout << "7)Promediar los 2 elementos centrales (Solo funciona con arrays de tamaño par)\n";
    std::cout << "8)Invertir el vector\n";
    std::cout << "9)Llenar 2 vectores e intercambiar elementos extremos\n";
    std::cout << "10)Ordenar un vector de mayor a menor\n";
    std::cout << "11)Mezclar dos vectores y sacar un tercero ordenado\n";
    std::cout << "12)Sumar 2 vectores empezando desde los extremos en un tercer vector\n";
    std::cout << "13)Simular la cola de un banco(Encolar, Desencolar)\n";
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
    Tarea1 tarea2;
    std::cout << "------------------------\n";
    tarea2.mostrarNumeros();
    std::cout << "\n------------------------\n";
    std::cout << "El ante penultimo es: " << tarea2.penultimo() << "\n";
}
void tarea3Ejecucion()
{
    Tarea1 tarea3;
    system("cls");
    tarea3.buildImpares();
    std::cout << "\n------N-----------------\n";
    tarea3.mostrarNumeros();
    std::cout << "\n--------I---------------\n";
    tarea3.imprimirValoresImpares();
}
void tarea4Ejecucion()
{
    Tarea1 tarea4;
    system("cls");
    tarea4.listarFinal();
}
void tarea5Ejecucion()
{
    Tarea1 tarea5;
    system("cls");
    std::cout << "--------------------\n";
    tarea5.mostrarNumeros();
    std::cout << "\n--------------------\n";
    tarea5.multiplicarPares();
    tarea5.mostrarNumeros();
}
void tarea6Ejecucion()
{
    Tarea1 tarea6;
    system("cls");
    tarea6.contarCapicuas();
}
void tarea7Ejecucion()
{
    Tarea1 tarea7;
    system("cls");
    tarea7.promediarMedios();
    tarea7.mostrarNumeros();
}
void tarea8Ejecucion()
{
    Tarea1 tarea8;
    system("cls");
    tarea8.mostrarNumeros();
    std::cout << "\n--------------\n";
    tarea8.invertirVector();
    tarea8.mostrarNumeros();
}
void tarea9Ejecucion()
{
    Tarea1 tarea9;
    system("cls");
    tarea9.invertirUltimoDigitoDeDosVectores();
}
void tarea10Ejecucion()
{
    Tarea1 tarea10;
    system("cls");
    tarea10.mostrarNumeros();
    tarea10.ordenarMayorMenor();
    std::cout << "\n---------------\n";
    tarea10.mostrarNumeros();
}
void tarea11Ejecucion()
{
    Tarea1 tarea11;
    system("cls");
    tarea11.dosVectoresOrdenadosEnOtro();

}
void tarea12Ejecucion()
{
    Tarea1 tarea12;
    system("cls");
    tarea12.sumaVectoresReversa();

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
        case 6:
        {
            system("cls");
            tarea6Ejecucion();
            limpiar();
            break;
        }
        case 7:
        {
            system("cls");
            tarea7Ejecucion();
            limpiar();
            break;
        }
        case 8:
        {
            system("cls");
            tarea8Ejecucion();
            limpiar();
            break;
        }
         case 9:
        {
            system("cls");
            tarea9Ejecucion();
            limpiar();
            break;
        }
        case 10:
        {
            system("cls");
            tarea10Ejecucion();
            limpiar();
            break;
        }
        case 11:
        {
            system("cls");
            tarea11Ejecucion();
            limpiar();
            break;
        }
        case 12:
        {
            system("cls");
            tarea12Ejecucion();
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