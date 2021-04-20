#include <iostream>
#include <conio.h>
#include <tuple>
#include <algorithm>
std::tuple<int *, int> gArrayxSize()
{
    int *nArray;
    int size = 0;
    std::cout << "Introduce el tamañ o del array\n";
    std::cin >> size;
    system("cls");
    nArray = NULL;          //A null
    nArray = new int[size]; //Declarando el array de pointers de el dato introducido
    for (int i = 0; i < size; i++)
    {
        nArray[i] = 0; //Inicio todos en 0, por si acaso
        std::cout << "\nIntroduzca un dato para el array\n";
        std::cin >> nArray[i]; // Doy un valor
        system("cls");
    }
    return std::make_tuple(nArray, size);
}

class Tarea1
{
    int *nArray;
    int size;

public:
    Tarea1();
    int get_size() { return size; }
    void mostrarNumeros()
    {
        auto savePosition = nArray;
        for (int i = 0; i < size; i++)
        {
            std::cout << *nArray << " ";
            nArray++;
        }
        nArray = savePosition;
    }
    int *get_nArray() { return nArray; }
    int promedio() //datos
    {
        auto savePosition = nArray; //Como no funciona restarle 5 denuevo, tengo que salvar la posición original del array, lo hago con auto por que ni idea JAJA
        int resultado = 0;          //Return para la función
        for (int i = 0; i < size; i++)
        {
            resultado += *nArray; //valor de pointer
            nArray++;             //Pasando el pointer
        }
        nArray = savePosition;
        resultado /= size; //División entre el size del array y la suma de los valores en el array
        return resultado;
    }
};
Tarea1::Tarea1() //Llenar el array dinamico por defecto
{
    std::tie(nArray, size) = gArrayxSize(); //Podria usar STD::TIE igual pero si lo declaro con auto se jode
}
//2
class Tarea2
{
    int *nArray;
    int size;

public:
    Tarea2();
    int get_size() { return size; }
    void mostrarNumeros()
    {
        auto savePosition = nArray;
        for (int i = 0; i < size; i++)
        {
            std::cout << *nArray << " ";
            nArray++;
        }
        nArray = savePosition;
    }
    int *get_nArray() { return nArray; }
    int penultimo() //datos
    {
        auto savePosition = nArray; //Como no funciona restarle 5 denuevo, tengo que salvar la posición original del array, lo hago con auto por que ni idea JAJA
        int resultado = 0;          //Return para la función
        for (int i = 0; i < size - 2; i++)
        {
            resultado = *nArray; //valor de pointer
            nArray++;            //Pasando el pointer
        }
        nArray = savePosition;
        return resultado;
    }
};
Tarea2::Tarea2() //Llenar el array dinamico por defecto
{
    std::tie(nArray, size) = gArrayxSize();
}
//
class Tarea3
{
    int *nArray, *Impares;
    int size, sizeImpares;

public:
    Tarea3(); //Constructor con solo el Array y el size
    void imprimirValoresNormales()
    {
        auto savePosition = nArray;

        for (int i = 0; i < size; i++)
        {
            std::cout << *nArray << " ";
            nArray++;
        }
        nArray = savePosition;
    }
    void imprimirValoresImpares()
    {
        auto savePosition = Impares;
        for (int i = 0; i < sizeImpares; i++)
        {
            std::cout << *Impares << " ";
            Impares++;
        }
        Impares = savePosition;
    }
    void buildImpares()
    {
        auto savePosition = nArray;
        sizeImpares = 0;
        for (int i = 0; i < size; i++)
        {

            if (*nArray % 2 != 0 && *nArray % 3 == 0) //Determina el tamaño de Impares
            {
                sizeImpares++; //Obtenemos el tamaño de nuestro proximo array dinamico
            }
            nArray++;
        }
        nArray = savePosition;          //Volver al inicio
        Impares = new int[sizeImpares]; //Determinar tamaño de Impares
        int contador = 0;               //Contador para impares
        for (int i = 0; i < size; i++)
        {
            if (*nArray % 2 != 0 && *nArray % 3 == 0)
            {
                Impares[contador] = *nArray; //Le damos al puntero el valor
                contador++;
            }
            nArray++;
        }
        nArray = savePosition; //Volver al inicio
    }
};

Tarea3::Tarea3()
{
    std::tie(nArray, size) = gArrayxSize();
}
class Tarea4
{
    int *nArray;
    int size;
    int posInicial, posFinal;

public:
    Tarea4();
    void listarFinal()
    {
        std::cout << "-------------\n";
        posInicial = *nArray;
        auto savePosition = nArray;
        for (int i = 0; i < size; i++)
        {
            std::cout << *nArray << " ";
            if (i == size - 2)
            {
                posFinal = *nArray;
            }
            nArray++;
        }
        std::cout << "\n-------------\n";

        nArray = savePosition;
        nArray[0] = posFinal;
        nArray[size - 1] = posInicial;
        for (int i = 0; i < size; i++)
        {
            std::cout << *nArray << " ";
            nArray++;
        }
    }
};
Tarea4::Tarea4()
{
    std::tie(nArray, size) = gArrayxSize();
}
class Tarea5
{
    int *nArray;
    int size;

public:
    Tarea5();
    void listar()
    {
        auto savePosition = nArray;
        for (int i = 0; i < size; i++)
        {
            std::cout << *nArray << " ";
            nArray++;
        }
        nArray = savePosition;
    }
    void multiplicarPares()
    {
        auto savePosition = nArray;
        for (int i = 0; i < size; i++)
        {
            if (*nArray % 2 == 0)
            {
                *nArray *= 2;
            }
            nArray++;
        }
        nArray = savePosition;
    }
};
Tarea5::Tarea5()
{
    std::tie(nArray, size) = gArrayxSize();
}
//Banco abajo
std::tuple<std::string *, int> colaInicial()
{
    std::string *nCola;
    int size = 0;
    std::cout << "Ingresa el número de personas que acaban de ingresar al banco!\n";
    std::cin >> size;
    system("cls");
    nCola = NULL;                  //A null
    nCola = new std::string[size]; //Declarando el array de pointers con el tamaño inicial introducido
    for (int i = 0; i < size; i++)
    {
        nCola[i] = "0"; //Inicio todos en 0, por si acaso
        std::cout << "\nIntroduzca un nuevo nombre para la cola\n";
        std::cin >> nCola[i]; // Doy un valor
        system("cls");
    }
    return std::make_tuple(nCola, size);
}
class ColaBanco
{
    std::string *nCola; //Array dinamico de strings
    int actualSize;     //Tamaño actual de la cola
public:
    ColaBanco();
    int get_size() { return actualSize; }
    void mostrarColaActual()
    {
        auto savePosition = nCola; //Salva posición del pointer
        for (int i = 0; i < actualSize; i++)
        {
            std::cout << "Posición: " << i << " | " << *nCola << "\n";
            nCola++;
        }
        nCola = savePosition; //Devuelve el pointer a su posición original
    }
    void Encolar()
    {
        std::string *ArrayNuevo = new std::string[actualSize + 1]; //Nuevo array con tamaño + 1;
        std::copy(nCola, nCola + std::min(actualSize, actualSize + 1), ArrayNuevo);
        actualSize++; //Establecemos que aumentó el tamaño
        for (int i = 0; i < actualSize; i++)
        {
            if (i == actualSize - 1)
            {
                if (actualSize == 1)
                {
                    std::cout << "Parece que no hay nadie! Ingresa el nombre de la persona que llegó al banco\n";
                    std::cin >> ArrayNuevo[i];
                    break;
                }
                else
                {
                    std::cout << "Introduce el nombre de la persona que ingresó a la cola" << actualSize << "\n";
                    std::cin >> ArrayNuevo[i];
                }
            }
        }
        nCola = ArrayNuevo; //Copiamos el array dinamico
    }
    void Desencolar()
    {
        std::cout << *nCola << " se fue del banco.\n";
        if (actualSize <= 1)
        {
            nCola[0] = "VACIO";
            if (actualSize == 1)
            {
                actualSize--;
            }
            return;
        }
        nCola++; //Movemos el puntero 1 valor
        std::string *ArrayNuevo = new std::string[actualSize - 1];
        std::copy(nCola, nCola + std::min(actualSize, actualSize - 1), ArrayNuevo);
        actualSize--;
        *nCola = *ArrayNuevo;
    }
};
ColaBanco::ColaBanco()
{
    std::tie(nCola, actualSize) = colaInicial();
}
