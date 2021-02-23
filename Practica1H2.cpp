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
              << "2)Llenar un vector de N elementos, imprimir la posición y el valor del elemento mayor almacenado en el vector. Suponga que todos los elementos del vector son diferentes." << std::endl;
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
        std::vector<int> v1; //usando vector
        srand(time(0));
        for (i = 0; i < a; i++)
        {
            v1[i] = rand()% 100 + 1 ;
        }
        int cheq = rand()%2+1;
        if (cheq==1)
        {
            std::sort(std::begin(v1), std::end(v1));
        }
        //aquí comienza el algoritmo para chequear si está ordenado de forma ascendente
        c = v1[0];
        int z = 0;
        for (i = 0; i < a; i++)
        {
            b = v1[i+1];            
            if (b > c)
            {
                z = 1;
            }
            else
            {
                z = 0;
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