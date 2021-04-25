#include <iostream> //COUT
#include <conio.h> //GETCH
#include <tuple> //TUPLA
#include <algorithm> //SORT

std::tuple<int *, int> gArrayxSize()
{
    int *nArray;
    int size = 0;
    std::cout << "Introduce el tamaño del array\n";
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
bool comparadorMayorMenor(const int a, const int b)
{

    return a > b;
}

//Cumple con los requisitos
class Tarea1
{
    int *nArray, *Impares, *nArray2, *nArray3;
    int size, size2, size3, sizeImpares, posInicial, posFinal;

public:
    Tarea1();
    int get_size() { return size; }
    int *get_nArray() { return nArray; }
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
    void listarFinal()
    {
        std::cout << "-------------\n";
        posInicial = *nArray;
        auto savePosition = nArray;
        for (int i = 0; i < size; i++)
        {
            std::cout << *nArray << " ";
            if (i == size - 1)
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
    void contarCapicuas()
    {
        int n = 0;
        int rev = 0;
        int dig = 0;
        auto savePosition = nArray;
        int contar = 0;
        for (int i = 0; i < size; i++)
        {
            n = *nArray;
            while (*nArray > 0)
            {
                dig = *nArray % 10;
                rev = rev * 10 + dig;
                *nArray = *nArray / 10;
            }
            nArray++;
            if (n == rev && n > 9) //tiene que ser mayor de 9 por que pide que sea capicuas de 2 cifras.
            {
                std::cout << "El número en la posición " << i << " es capicua. | " << n << "\n";
                contar++;
            }
            n = 0;
            rev = 0;
            dig = 0;
        }
        std::cout << "Hay " << contar << " capicuas\n";
        nArray = savePosition;
    }
    void promediarMedios()
    {
        int promedio = 0;
        if (size % 2 == 0)
        {
            auto savePosition = nArray;
            for (int i = 0; i < size; i++)
            {
                if (i == size / 2 || i == (size / 2) - 1)
                {
                    promedio += *nArray;
                }
                nArray++;
            }

            promedio /= 2;
            std::cout << "El promedio es: " << promedio << "\n";
            promedio = 0;
            nArray = savePosition;
        }
        else
        {
            std::cout << "No hay 2 centrales\n";
        }
    }
    void invertirVector()
    {
        int *invertedArray = new int[size];
        nArray = nArray + (size - 1); //recorremos
        auto savePosition = nArray;
        //Esto debería funcionar, pero no lo hace, por algo std::reverse(nArray, nArray + size-1);
        for (int i = 0; i < size; i++)
        {
            invertedArray[i] = *nArray;
            nArray--;
        }
        nArray = invertedArray;
    }
    void invertirUltimoDigitoDeDosVectores()
    {
        std::cout << "Ahora para el segundo vector\n";
        std::tie(nArray2, size2) = gArrayxSize(); // No es parte del default (los otros 8 usan el default)
        auto savePosition2 = nArray2;             //Salvando Posición original
        auto savePosition1 = nArray;              //Salvando Posición original
        int inicial1 = *nArray;
        int inicial2 = *nArray2;
        nArray += (size - 1);   //paso al final
        nArray2 += (size2 - 1); //paso al final
        int final1 = *nArray;
        int final2 = *nArray2; //Establezco el final
        nArray = savePosition1;
        nArray2 = savePosition2;
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
                nArray[i] = final2;
            if (i == size - 1)
                nArray[i] = inicial2;
        }
        for (int i = 0; i < size2; i++)
        {
            if (i == 0)
                nArray2[i] = final1;
            if (i == size2 - 1)
                nArray2[i] = inicial1;
        }
        mostrarNumeros();
        std::cout << "\n";
        for (int i = 0; i < size2; i++)
        {
            std::cout << *nArray2 << " ";
            nArray2++;
        }
        nArray2 = savePosition2;
    }
    void ordenarMayorMenor()
    {
        std::sort(nArray, nArray + size, comparadorMayorMenor);
    }
    void dosVectoresOrdenadosEnOtro()
    {
        std::cout << "Ahora para el segundo vector\n";
        std::tie(nArray2, size2) = gArrayxSize();
        size3 = size2 + size;
        nArray3 = new int[size3];
        std::copy(nArray, nArray + (size), nArray3);
        std::copy(nArray2, nArray2 + (size2), nArray3 + size);
        std::sort(nArray3, nArray3 + size3);
        mostrarNumeros();
        auto savePosition = nArray2;
        std::cout << "\n";
        for (int i = 0; i < size2; i++)
        {
            std::cout << *nArray2 << " ";
            nArray2++;
        }
        nArray2 = savePosition;
        std::cout << "\n";
        savePosition = nArray3;
        std::cout << "\n";
        for (int i = 0; i < size3; i++)
        {
            std::cout << *nArray3 << " ";
            nArray3++;
        }
        nArray3 = savePosition;
    }
    void sumaVectoresReversa()
    {
        std::cout << "Ahora para el segundo vector\n";
        std::tie(nArray2, size2) = gArrayxSize();
        if (size == size2)
        {
            size3 = size;
            nArray3 = new int[size3];
            auto savePosition = nArray; //Salvo nArray2
            auto savePosition2 = nArray2;
            nArray2 += (size2 - 1); //recorro
            int valores;
            for (int i = 0; i < size; i++)
            {
                valores = *nArray + *nArray2;
                nArray3[i] = valores;
                nArray2--;
                nArray++;
            }
            nArray = savePosition;
            nArray2 = savePosition2;
            mostrarNumeros();
            savePosition = nArray2;
            std::cout << "\n";
            for (int i = 0; i < size2; i++)
            {
                std::cout << *nArray2 << " ";
                nArray2++;
            }
            nArray2 = savePosition;
            std::cout << "\n";
            savePosition = nArray3;
            std::cout << "\n";
            for (int i = 0; i < size3; i++)
            {
                std::cout << *nArray3 << " ";
                nArray3++;
            }
            nArray3 = savePosition;
        }
        else
        {
            std::cout << "No se puede realizar la operación con 2 vectores de diferente tamaño.\n";
        }
    }
};
Tarea1::Tarea1() //Llenar el array dinamico por defecto
{
    std::tie(nArray, size) = gArrayxSize(); //Podria usar STD::TIE igual pero si lo declaro con auto se jode
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
