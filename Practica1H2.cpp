#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
#define tam 100
int v1[tam], v2[tam], v3[tam], cantidad, como;
void limpiar()
{

    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}

void menu()
{
    limpiar();
    std::cout << "\t\t\tIngrese una opción" << std::endl
              << "0)\tSalir." << std::endl
              << "1)\tSumar elementos de 2 vectores" << std::endl
              << "2)\tElevar al cuadrado elementos de un vector" << std::endl
              << "3)\tInvertir un vector y almacenarlo en otro vector" << std::endl
              << "4)\tVer si el vector está ordenado de manera ascendente" << std::endl
              << "5)\tMultiplicar el primer elemento por el último sucesivamente y almacenar en otro vector" << std::endl
              << "6)\tConcatenar 2 vectores y ordenarlos ascendentemente" << std::endl;
}
//Para preguntar si es manual o aleatorio

void listar(int array[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}
void comoLlenar()
{
    std::cout << "Ingrese una opción" << std::endl
              << "1)Manual" << std::endl
              << "2)Aleatorio" << std::endl;
}
//Función para llenar el array
void llenarArray(int *array, int cantidad, int como)
{
    if (cantidad > 100)
    {
        std::cout << "Valor demasiado grande" << std::endl;
        return;
    }
    else
    {
        int valor;
        if (como == 1)
        {

            for (int i = 0; i < cantidad; i++)
            {
                std::cout << "Ingrese valor para la posición " << i << " : ";
                std::cin >> valor;
                std::cout << std::endl;
                array[i] = valor;
            }
        }
        if (como == 2)
        {
            int valor, rini, rend;
            std::cout << "Ingrese el rango aleatorio inicial" << std::endl;
            std::cin >> rini;
            std::cout << "Ingrese el rango aleatorio final" << std::endl;
            std::cin >> rend;
            rend++;
            srand(time(0));
            for (int i = 0; i < cantidad; i++)
            {
                array[i] = rand() % rend + rini;
            }
        }
    }
}

int main()
{
    int a, b, c, ex = 0, i, como;
    do
    {
        menu();
        std::cin >> ex;
        switch (ex)
        {
        case 1:
        {
            std::cout << "Ingrese el tamaño de los vectores" << std::endl;
            std::cin >> cantidad;
            comoLlenar();
            std::cin >> como;
            std::cout << "Para vector A" << std::endl;
            llenarArray(v1, cantidad, como);
            std::cout << "Para vector B" << std::endl;
            llenarArray(v2, cantidad, como);
            for (i = 0; i < cantidad; i++)
            {
                v3[i] = v1[i] + v2[i];
            }
            std::cout << "El vector resultante es:" << std::endl;
            listar(v3, cantidad);
            getch();
            break;
        }
        case 2:
        {
            std::cout << "Ingrese el tamaño del vector";
            std::cin >> cantidad;
            comoLlenar();
            std::cin >> como;
            llenarArray(v1, cantidad, como);
            std::cout << "Original:" << std::endl;
            listar(v1, cantidad);
            for (int i = 0; i < cantidad; i++)
            {
                v2[i] = v1[i] * v1[i];
            }
            std::cout << std::endl;
            std::cout << "Al cuadrado: " << std::endl;
            listar(v2, cantidad);
            getch();
            break;
        }
        case 3:
        {
            std::cout << "Ingrese el tamaño del vector" << std::endl;
            std::cin >> cantidad;
            comoLlenar();
            std::cin >> como;
            llenarArray(v1, cantidad, como);
            std::cout << "Original" << std::endl;
            listar(v1, cantidad);
            for (int i = 0; i < cantidad; i++)
            {
                v2[i] = v1[cantidad - i - 1];
            }
            std::cout << std::endl;
            std::cout << "Inverso" << std::endl;
            listar(v2, cantidad);
            getch();
            break;
        }
        case 4:
        {
            std::cout << "Ingrese el tamaño del vector" << std::endl;
            std::cin >> cantidad;
            comoLlenar();
            std::cin >> como;
            llenarArray(v1, cantidad, como);
            std::cout << "Original" << std::endl;
            listar(v1, cantidad);
            int f;
            for (int i = 0; i < cantidad; i++)
            {
                if (v1[0] > v1[i])
                {
                    f = 1;
                    break;
                }
                else
                {
                    f = 0;
                }
            }
            if (f == 1)
            {
                std::cout << "El vector NO está ordenado de manera ascendente" << std::endl;
            }
            else
            {
                std::cout << "El vector está ordenado de manera ascendente" << std::endl;
            }
            getch();
            break;
        }
        case 5:
        {
            std::cout << "Ingrese el tamaño de los vectores" << std::endl;
            std::cin >> cantidad;
            comoLlenar();
            std::cin >> como;
            std::cout << "Para vector A" << std::endl;
            llenarArray(v1, cantidad, como);
            std::cout << "Para vector B" << std::endl;
            llenarArray(v2, cantidad, como);
            for (int i = 0; i < cantidad; i++)
            {
                v3[i] = v1[i] * v2[cantidad - i - 1];
            }
            std::cout << "Vectora A" << std::endl;
            listar(v1, cantidad);
            std::cout << "Vector B" << std::endl;
            listar(v2, cantidad);
            std::cout << "Vector C" << std::endl;
            listar(v3, cantidad);
            getch();
            break;
        }
        case 6:
        {
            int cantidad2;
            std::cout << "Ingrese el tamaño del vector A :";
            std::cin >> cantidad;
            std::cout << "Ingrese el tamaño del vector B :";
            std::cin >> cantidad2;
            if (cantidad + cantidad2 >= 100)
            {
                std::cout << "Demasiados valores" << std::endl;
                break;
            }
            comoLlenar();
            std::cin >> como;
            std::cout << "Para vector A" << std::endl;
            llenarArray(v1, cantidad, como);
            std::cout << "Para vector B" << std::endl;
            llenarArray(v2, cantidad2, como);
            std::cout << "Vector A SIN ORDENAR : " << std::endl;
            listar(v1, cantidad);
            std::cout << "Vector B SIN ORDENAR : " << std::endl;
            listar(v2, cantidad2);
            std::sort(std::begin(v1), std::begin(v1) + cantidad);
            std::cout << "Vector A ordenado ascendentemente : " << std::endl;
            listar(v1, cantidad);
            std::cout << "Vector B ordenado ascendentemente : " << std::endl;
            std::sort(std::begin(v2), std::begin(v2) + cantidad2);
            listar(v2, cantidad2);
            for (int i = 0; i < cantidad; i++)
            {
                v3[i] = v1[i];
            }
            for (int i = cantidad; i < cantidad + cantidad2; i++)
            {
                v3[i] = v2[i - cantidad];
            }
            std::sort(std::begin(v3), std::begin(v3) + (cantidad + cantidad2));
            std::cout << "Vector C ordenado ascendentemente : " << std::endl;
            listar(v3, cantidad + cantidad2);
            getch();
            break;
        }
        case 7:
        {
            
        }
        default:
            std::cout << "Ingrese una opción correcta";
            break;
        }
    } while (ex != 0);
    return 0;
}
