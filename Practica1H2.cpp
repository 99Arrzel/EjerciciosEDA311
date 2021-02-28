#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
#define tam 100
int v1[tam], v2[tam], v3[tam], v4[tam], cantidad, como, valor;
double b1[tam];
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
              << "6)\tConcatenar 2 vectores y ordenarlos ascendentemente" << std::endl
              << "7)\tRealizar el producto de dos vectores considerando que son de distinta longitud." << std::endl
              << "8)\tEscribe un programa que defina un vector de números y calcule si existe algún número en el vector cuyo valor equivale a la suma del resto de números del vector." << std::endl
              << "9)\t Realizar el producto de un vector de notas por un escalar (introducido por teclado). " << std::endl
              << "10)\tAlmacenar la siguiente serie en un vector de 10 posiciones: 1,1,2,3,5,8,.... (Serie de Fibbonacci)" <<std::endl
              << "11)\tImprimir la mayor de 10 estaturas entre 1.50 y 1.68 almacenadas en un vector. Indicar en qué posición se encuentra la misma. " << std::endl
              << "12)\tGenerar un vector de 10 posiciones con valores comprendidos entre 1 y 365. Visualizar aquellos elementos que sean pares." << std::endl
              << "13)\tGenerar un vector de 50 posiciones con valores comprendidos entre 1 y 10. Visualizar cuantos 1 hay, cuantos 2, cuantos 3, etc. hasta el 10." << std::endl
              << "14)\tBuscar en un vector de nombres un nombre específico. Indicar si se encuentra o no" << std::endl;
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
        case 3: //5 del documento
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
        case 4: //7 del documento
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
        case 5: // 9 del documento
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
        case 6: //11 del documento
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
        case 7://13 del documento
        {
            int cantidad2;
            std::cout << "Ingrese el tamaño del vector A :";
            std::cin >> cantidad;
            std::cout << "Ingrese el tamaño del vector B :";
            std::cin >> cantidad2;
            comoLlenar();
            std::cin >> como;
            std::cout << "Para vector A" << std::endl;
            llenarArray(v1, cantidad, como);
            std::cout << "Para vector B" << std::endl;
            llenarArray(v2, cantidad2, como);
            std::cout << "Vector A" << std::endl;
            listar(v1, cantidad);
            std::cout << "Vector B" << std::endl;
            listar(v2, cantidad2);
            std::cout << "Vector C" << std::endl;
            if (cantidad >= cantidad2)
            {
                for (int i = 0; i < cantidad2; i++)
                {
                    v3[i] = v1[i] * v2[i];
                }
                for (int i = cantidad2; i < cantidad; i++)
                {
                    v3[i] = v1[i];
                }
                listar(v3, cantidad);
            }
            else if (cantidad2 > cantidad)
            {
                for (int i = 0; i < cantidad; i++)
                {
                    v3[i] = v1[i] * v2[i];
                }
                for (int i = cantidad; i < cantidad2; i++)
                {
                    v3[i] = v2[i];
                }
                listar(v3, cantidad2);
            }
            getch();
            break;
        }
        case 8://15 del documento
        {
            int suma;
            int encontrado = 0;
            std::cout << "Ingrese el tamaño del vector" << std::endl;
            std::cin >> cantidad;
            llenarArray(v1, cantidad, 2);
            listar(v1, cantidad);
            for (int i = 0; i < cantidad; i++)
            {
                suma = 0;
                for (int j = 0; j < cantidad; j++)
                {
                    if (i != j)
                    {
                        suma = suma + v1[j];
                    }
                }
                if (v1[i] == suma)
                {
                    std::cout << "El valor : " << v1[i] << " en la posición " << i << " Equivale a la suma del resto del vector" << std::endl;
                    encontrado = 1;
                }
            }
            if (encontrado == 0)
            {
                std::cout << "No se halló ningún número que equivalga a la suma de los arrays" << std::endl;
            }
            getch();
            break;
        }
        case 9: //17 del documento
        {
            int escalar;
            std::cout << "Introduzca el vector : Posición X" << std::endl;
            std::cin >> v1[0];
            std::cout << "Introduzca el vector : Posición Y" << std::endl;
            std::cin >> v2[0];
            std::cout << std::endl;
            std::cout << "Vector en la posición (" << v1[0] << "," << v2[0] << ")" << std::endl;
            std::cout << "Introduzca el escalar" << std::endl;
            std::cin >> escalar;
            v1[1] = v1[0] * escalar;
            v2[1] = v2[0] * escalar;
            std::cout << "Vector en la posición (" << v1[1] << "," << v2[1] << ")" << std::endl;
            getch();
            break;
        }
        case 10: //19 del documentio
        {
            int n1 = 0, n2 = 1, ok = 0;
            for (int i = 0; i <= 10; ++i)
            {
                if (i == 1 || i == 2)
                {
                    v1[i] = i;
                    continue;
                }
                ok = n1 + n2;
                n1 = n2;
                n2 = ok;
                v1[i] = ok;
            }
            std::cout << "Los primeros 10 terminos de la serie de Fibbonacci son: " << std::endl;
            listar(v1, 10);
            getch();
            break;
        }
        case 11: //21 del documento
        {
            double valordouble;
            comoLlenar();
            std::cin >> como;
            if (como == 1)
            {
                for (int i = 0; i < 10; i++)
                {
                    std::cout << "Ingrese " << i + 1 << " de 10 valores" << std::endl;
                    std::cin >> valordouble;
                    if (valordouble > 1.50 && valordouble < 1.68)
                    {
                        b1[i] = std::round(valordouble * 1000.0) / 1000.0;
                    }
                    else
                    {
                        getch();
                        break;
                    }
                }
            }
            else if (como == 2)
            {
                srand(time(NULL));
                for (int i = 0; i < 10; i++)
                {
                    valordouble = 1.50 + rand() / (double)(RAND_MAX) * (1.68 - 1.50);
                    b1[i] = std::round(valordouble * 1000.0) / 1000.0;
                }
            }
            valordouble = 0.0;
            int posi;
            for (int i = 0; i < 10; i++)
            {
                std::cout.precision(3);
                std::cout << "Valor en la posición " << i << " :";
                std::cout << b1[i] << std::endl;
                if (b1[i] > valordouble)
                {
                    valordouble = b1[i];
                    posi = i;
                }
            }
            std::cout.precision(3);
            std::cout << "El valor más grande es " << valordouble << " y se encuentra en la posición : " << posi << std::endl;
            getch();
            break;
        }
        case 12: //23 del documento
        {
            for (i = 0; i < 10; i++)
            {
                v1[i] = rand() % 365 + 1;
            }
            std::cout << "El vector generado tiene los números: " << std::endl;
            listar(v1, 10);
            std::cout << "Los pares son: " << std::endl;
            for (int i = 0; i < 10; i++)
            {
                if (v1[i] % 2 == 0)
                {
                    std::cout << v1[i] << " En la posición :" << i << std::endl;
                }
            }
            getch();
            break;
        }
        case 13: // 25 del documento
        {
            srand(time(NULL));
            int contador = 0;
            for (i = 0; i < 50; i++)
            {
                v1[i] = rand() % 10 + 1;
            }
            for (i = 1; i < 10; i++)
            {
                for(int j = 0; j < 50; j++)
                {
                    if (v1[j] == i)
                    {
                        contador++;
                    }
                }
                std::cout << "Se han encontrado " << contador << " de " << i <<"s" <<std::endl;
                contador = 0;
            }
            getch();
            break;
        }
        case 14:// 27 del documento
        {
            int chequer = 0;
            std::string nombres[tam];
            std::string nombre;
            std::cout << "Ingresar la cantidad de nombres que ingresará" << std::endl;
            std::cin >> cantidad;
            for (int i = 0; i < cantidad; i++)
            {
                std::cout << "Ingrese el nombre para la posición " << i << std::endl;
                std::cin >> nombre;
                nombres[i] = nombre;
            }
            std::cout << "Ingrese el nombre para verificar en el array" << std::endl;
            std::cin >> nombre;
            for (int i = 0; i < cantidad; i++)
            {
                if(nombre == nombres[i])
                {
                    std::cout << "Nombre encontrado en la posición " << i << " :" << nombres[i] << std::endl;
                    chequer++;
                }
            }
            if(chequer == 0)
            {
                std::cout << "No se encontró el nombre" << std::endl;
            }
            getch();
            break;
            
        }
        default:
            std::cout << "Ingrese una opción correcta";
            break;
        }
    } while (ex != 0);
    return 0;
}
