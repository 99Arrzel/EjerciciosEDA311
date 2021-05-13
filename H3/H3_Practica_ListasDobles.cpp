#include "H3_Practica_ListasDobles.h"

void menu()
{
    std::cout << "1)Ordenar una lista de enteros\n";
    std::cout << "2)Listar un nodo al revés\n";
    std::cout << "3)Eliminar elementos repetidos de la lista\n";
    std::cout << "4)Convertir lista simple a doble\n";
}
void limpiar()
{
    std::cout << "Presiona enter para continuar\n";
    std::cin.get();
    system("clear");
}

void tarea1()
{
    Nodo ordenar;
    int entrada = 0;
    do
    {
        std::cout << "Ingrese un número, presiona 0 para salir\n";
        std::cin >> entrada;
        if (entrada == 0)
        {
            break;
        }
        ordenar.insertarEntero(entrada);

    } while (entrada != 0);
    std::cout << "Antes de ordenar: \n";
    ordenar.listarEnteros();
    ordenar.ordenarListaEntero();
    std::cout << "\nDespues de ordenar: \n";
    ordenar.listarEnteros();
    std::cin.get();
}
void tarea2()
{
    Nodo invertir;
    int entrada = 0;
    do
    {
        std::cout << "Ingrese un número, presiona 0 para salir\n";
        std::cin >> entrada;
        if (entrada == 0)
        {
            break;
        }
        invertir.insertarEntero(entrada);

    } while (entrada != 0);
    std::cout << "Antes de invertir: \n";
    invertir.listarEnteros();
    std::cout << "\nDespues de invertir: \n";
    invertir.listarInvertido();
    std::cout << "\n";
    std::cin.get();
}

void tarea3()
{
    Nodo eliminar;
    int entrada = 0;
    do
    {
        std::cout << "Ingrese un número, presiona 0 para salir\n";
        std::cin >> entrada;
        if (entrada == 0)
        {
            break;
        }
        eliminar.insertarEntero(entrada);

    } while (entrada != 0);
    std::cout << "Antes de eliminar repetidos: \n";
    eliminar.listarEnteros();
    std::cout << "\n";
    eliminar.eliminarRepetidos();
    std::cout << "Despues de eliminar repetidos: \n";
    eliminar.listarEnteros();
    std::cin.get();
}
void tarea4()
{
    Nodo doble;
    int entrada = 0;
    do
    {
        std::cout << "Ingrese un número, presiona 0 para salir\n";
        std::cin >> entrada;
        if (entrada == 0)
        {
            break;
        }
        insertarEnteroSimple(entrada);

    } while (entrada != 0);
    doble.simpleAdoble(cab);
    std::cout << "Lista doble\n";
    doble.listarEnteros();
    std::cin.get();
}
int main()
{
    int opt = 0;
    do
    {
        menu();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            tarea1();
            limpiar();
            break;
        }
        case 2:
        {
            tarea2();
            limpiar();
            break;
        }
        case 3:
        {
            tarea3();
            limpiar();
            break;
        }
        case 4:
        {
            tarea4();
            limpiar();
            break;
        }
        default:
            break;
        }
    } while (opt != 0);

    return 0;
}