#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <algorithm>

int main()
{
    int a, b, c, ex, i;
    std::cout << "Ingrese una opción" << std::endl
              << "1) suma de 2 vectores aleatorios en un tercer vector" << std::endl
              << "2)Llenar un vector de N elementos, imprimir la posición y el valor del elemento mayor almacenado en el vector. Suponga que todos los elementos del vector son diferentes." << std::endl
              << "3)Almacenar N números en un vector, elevar al cuadrado cada valor almacenado en el vector, almacenar el resultado en otro vector. Imprimir el vector original y el vector resultante." << std::endl
              << "4)Almacenar N números en un vector, imprimir cuantos son ceros, cuantos son negativos, cuantos positivos. Imprimir además la suma de los negativos y la suma de los positivos." << std::endl
              << "5)Almacenar N números en un vector, almacenarlos en otro vector en orden inverso al vector original e imprimir el vector resultante." << std::endl
              << "6)Se tienen almacenados en la memoria dos vectores A y B de N elementos cada uno. Hacer un algoritmo que escriba la palabra “Iguales” si ambos vectores son iguales y “Diferentes” si no lo son. Serán iguales cuando en la misma posición de ambos vectores se tenga el mismo valor para todos los elementos." << std::endl
              << "7)Se tiene el vector A con N elementos almacenados. Diseñe un algoritmo que escriba “SI” si el vector está ordenado ascendentemente o “NO” si el vector no está ordenado." << std::endl
              << "8)Diseñe un algoritmo que lea un número cualquiera y lo busque en el vector V, el cual tiene almacenados N elementos. Escribir la posición donde se encuentra almacenado el número en el vector o el mensaje “NO” si no lo encuentra. Búsqueda secuencial." << std::endl
              << "9)Diseñe un algoritmo que lea dos vectores A y B de N elementos cada uno y multiplique el primer elemento de A con el último elemento de B y luego el segundo elemento de A por el N-1 elemento de B y así sucesivamente hasta llegar al N elemento de A por el primer elemento de B. El resultado de la multiplicación almacenarlo en un vector C." << std::endl
              << "10)Dado un vector A de N elementos, hallar:" << std::endl << "a.  La suma de los números pares" << std::endl << "b.	La suma de los números impares" << std::endl << "c.	La suma de los números primos" << std::endl << "d.	La cantidad de números pares, impares y primos." << std::endl;

    std::cin >> ex;
    switch (ex)
    {
    case 1:
    {
        std::cout << "Ingrese el tamaño de los vectores A y B: ";
        std::cin >> a;
        int *v1 = new int[a];
        int *v2 = new int[a];
        int *v3 = new int[a];
        for (i = 0; i < a; i++)
        {
            v1[i] = rand() % 99 + 1;
            std::cout << "V1 = " << v1[i];
            v2[i] = rand() % 30 + 10;
            std::cout << ", V2 = " << v2[i];
            v3[i] = v1[i] + v2[i];
            std::cout << " : V3 = " << v3[i] << std::endl;
        }
        break;
    }
    case 2:
    {
        std::cout << "Ingrese el tamaño del vector : ";
        std::cin >> a;
        int *v1 = new int[a];
        for (i = 0; i < a; i++)
        {
            v1[i] = rand() % 200 + 10;
            std::cout << i << " : " << v1[i] << std::endl;
        }
        b = 0;
        int contador = 0;
        for (i = 0; i < a; i++)
        {
            c = v1[i];
            if (c > b)
            {
                b = c;
                contador = i;
            }
        }
        std::cout << std::endl;
        std::cout << "número más alto en la posición : " << contador << " con valor de : " << b;
        break;
    }
    break;
    case 3:
    {
        std::cout << "Ingrese el tamaño del vector : ";
        std::cin >> a;
        double *v1 = new double[a];
        double *v2 = new double[a];
        std::cout << "Num : Sqrt" << std::endl;
        for (i = 0; i < a; i++)
        {
            v1[i] = rand() % 100 + 10;
            std::cout << v1[i];
            v2[i] = sqrt(v1[i]);
            std::cout << " : " << v2[i] << std::endl;
        }
        break;
    }
    case 4:
    {
        srand(time(0));
        std::cout << "Ingrese el tamaño del vector : ";
        std::cin >> a;
        int *v1 = new int[a];
        int nega = 0, posi = 0, cero = 0;
        int sumanega = 0, sumaposi = 0;

        for (i = 0; i < a; i++)
        {
            v1[i] = (rand() % +201) - 100;
            std::cout << v1[i] << " : ";
            if (v1[i] == 0)
                cero++;
            if (v1[i] > 0)
            {
                posi++;
                sumaposi = sumaposi + v1[i];
            }
            if (v1[i] < 0)
            {
                nega++;
                sumanega = sumanega + v1[i];
            }
        }
        std::cout << std::endl
                  << "Hay " << cero << " cero(s), " << posi << " positivos y " << nega << " negativos" << std::endl;
        std::cout << "La suma de positivos es: " << sumaposi << " y la suma de negativos es : " << sumanega << std::endl;
        break;
    }
    case 5:
    {
        std::cout << "Ingrese el tamaño del vector" << std::endl;
        std::cin >> a;
        int *v1 = new int[a];
        int *v2 = new int[a];
        srand(time(0));
        std::cout << "Este es el vector aleatorio de " << a << " números" <<std::endl;
        for (i = 0; i < a; i++)
        {
            v1[i] = rand()% 100 + 1;
            std::cout << v1[i] << " ";
        }
        std::cout << std::endl << "Este es el vector inverso " << std::endl;
        int cont = 0;
        for (i = a-1; i > -1; i--)
        {
            v2[cont] = v1[i];
            cont++; 
        }
        for(i=0; i < a; i++)
        {
            std::cout << v2[i] << " ";
        }
        std::cout << std::endl;
        break;
    }
    case 6:
    {
        std::cout << "Ingrese el tamaño del vector " <<std::endl;
        std::cin >> a;
        int *v1 = new int[a];
        int *v2 = new int[a];
        srand(time(0));
        for (i=0; i < a; i++)
        {
            v1[i] = rand()%10 + 1;
            v2[i] = rand()%10 + 1;
            if (v1[i] == v2[i])
            {
                std::cout << "Posición Nº : " << i << " : " << v1[i] << "-" << v2[i] << " : SON IGUALES" << std::endl;
            }
            else
            {
                std::cout << "Posición Nº : " << i << " : " << v1[i] << "-" << v2[i] << " : SON DIFERENTES" << std::endl;
            }
        }
        break;
    }
    case 7:
    {
        std::cout << "Ingrese el tamaño del vector :";
        std::cin >> a;
        std::vector<int> v1;
        srand(time(0));
        std::cout << "Generando vector aleatorio con valores: 1-100" << std::endl;
        for (i = 0; i < a; i++)
        {
            v1.push_back(rand()% 100 + 1);
            std::cout << v1[i] << " ";
        }
        int cheq = rand() % 2 + 1;
        if (cheq==1)
        {
            std::sort(std::begin(v1), std::end(v1));
        }
        std::cout << "Randomizando si ordenar o no..." << std::endl;//
        //aquí comienza el algoritmo para chequear si está ordenado de forma ascendente
        c = v1[0];
        int z = 0;
        for (i = 0; i < a; i++)
        {
            std::cout << v1[i] << " ";
            b = v1[i];            
            if (b >= c)
            {
                z = 1;
            }
            else
            {
                z = 0;
                break;
            }
        }
        if (z == 1)
        {
            std::cout << "Está ordenado de manera ascendente." << std::endl;
        }
        else
        {
            std::cout << "NO está ordenado de manera ascendente." << std::endl;
        }
        break;    
    }
    default:
        std::cout << "Ingrese una opción correcta";
        break;
        
    }
}