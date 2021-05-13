#include "miExamenHito3.h"

void tarea1()
{
    std::string insertar;
    Palindromos lista1;
    Palindromos palin;
    Palindromos nopalin;
    do
    {
        std::cout << "Ingrese una palabra, presion 0 para salir\n";
        std::cin >> insertar;
        if (insertar == "0")
        {
            break;
        }
        if (esPalindromo(insertar))
        {
            palin.insetarPalindromo(insertar);
        }
        lista1.insetarPalindromo(insertar);

    } while (insertar != "0");

    std::cout << "Lista de palabras: \n";
    lista1.listarNodo();
    std::cout << "Lista de palindromos: \n";
    palin.listarNodo();
}
void tarea2()
{
    double insertarNumero;
    MisNodos nodo1;
    do
    {
        std::cout << "Ingrese un numero, presiona 0 para salir\n";
        std::cin >> insertarNumero;
        if (insertarNumero == 0)
        {
            break;
        }
        nodo1.insertarDato(insertarNumero);
    } while (insertarNumero != 0);
    std::cout << "La lista original\n";
    nodo1.listarDobles();
    std::cout << "La lista de enteros\n";
    nodo1.listarEnteros();
    std::cout << "La lista de los decimales\n";
    nodo1.listarDecimales();
}
void limpiar()
{
    std::cout << "\n Presiona una tecla para continuar\n";
    getch();
    system("cls");
}

void vectores()
{
    int *nArray;
    int size = 0;
    int dato = 0;
    std::cout << "Introduce el tamaño del array\n";
    std::cin >> size;
    system("cls");
    nArray = NULL;          //A null
    nArray = new int[size]; //Declarando el array de pointers de el dato introducido
    int contador = 0;
    for (int i = 0; i < size; i++)
    {
        std::cout << "\nIntroduzca un dato para el array\n";
        std::cin >> dato;
        if (dato % 2 == 0)
        {
            break;
        }
        nArray[i] = dato;
        system("cls");
        contador++;
    }
    for (int i = 0; i < contador; i++)
    {
        if (nArray[i] != 0)
        {
            std::cout << nArray[i] << "  ";
        }
        else
        {
            break;
        }
    }
    std::cout << "\n";
    //Invertido con punteros
    int *invertedArray = new int[contador];
    nArray = nArray + (contador - 1); //recorremos
    auto savePosition = nArray;

    for (int i = 0; i < contador; i++)
    {
        invertedArray[i] = *nArray;
        nArray--;
    }
    nArray = invertedArray;
    for (int i = 0; i < contador; i++)
    {
        if (nArray[i] != 0)
        {
            std::cout << nArray[i] << "  ";
        }
        else
        {
            break;
        }
    }

    std::cout << "\n";
    for (int i = 0; i < contador; i++)
    {
        if (i == contador / 2)
        {
            std::cout << "\n";
        }
        if (nArray[i] != 0)
        {
            std::cout << nArray[i] << "  ";
        }
        else
        {
            break;
        }
    }
}

void menu()
{
    std::cout << "1)Lista de palindromos\n";
    std::cout << "2)Algoritmo para ver decimales y enteros de una lista\n";
    std::cout << "3)es solo un struct, está en el.h\n";
    std::cout << "4)Es solo una clase, está en el .h\n";
    std::cout << "5)Recorrer un array con un puntero, darle la vuelta y dividirlo a la mitad\n";
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
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            vectores();
            limpiar();
            break;
        }
        default:
            break;
        }
    } while (opt != 0);
}