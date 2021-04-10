#include <iostream>
#include <conio.h>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
int opt = 0;
std::string paulaString;
std::string abc = "abcdefghijklmnñopqrstuvwxyz", ABC = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

void menu()
{
    cout << "1)Generar un vector de 10 posiciones con valores entre 15 y 595 sin repetir." << endl;
    cout << "2)El ejercicio de Paula" << endl;
    cout << "3)N caracters de int a ascii aleatorios SIN REPETIR" << endl;
    cout << "4)Matriz 11x11" << endl;
    cout << "5)Nombre a minuscula con CHAR ARRAY" << endl;
}
void vector10()
{
    srand(time(NULL));
    std::vector<int> pool;
    int v10[10] = {0};
    int suma10;

    for (int i = 15; i < 595; i++)
    {
        pool.push_back(i);
    }
    std::default_random_engine e(time(NULL));
    std::shuffle(std::begin(pool), std::end(pool), e);

    for (int i = 0; i < 10; i++)
    {
        v10[i] = pool[i];
        cout << v10[i] << " ";
        suma10 += v10[i];
    }
    suma10 = suma10 / 10;
    cout << "El promedio es: " << suma10 << endl;
    for (int i = 0; i < 10; i++)
    {
        if (v10[i] > suma10)
        {
            cout << "El valor :" << v10[i] << " en la posición " << i << " es mayor que el promedio" << endl;
        }
    }
}
void paula()
{
    int resultado = 0;
    int hecho = 0;
    int a = 0;
    int b = 0;
    cout << "Este es el juego de Paula! Ingresa un ejemplo." << endl;
    std::cin.ignore();
    getline(std::cin, paulaString);
    a = paulaString[0] - '0';
    b = paulaString[2] - '0';
    if (paulaString.length() > 3)
    {
        cout << "El juego consiste con 3 caracteres, intente denuevo" << endl;
        return;
    }
    for (int i = 0; i < abc.length(); i++)
    {
        if (paulaString[1] == abc[i]) // si es minuscula
        {
            resultado = a + b;
            cout << "Es minuscula" << endl;
            hecho = 1;
            break; // rompe el ciclo
        }
    }
    if (hecho == 0)
    {
        for (int i = 0; i < ABC.length(); i++)
        {
            if (paulaString[1] == ABC[i])
            {
                resultado = a - b;
                cout << "Es mayuscula " << endl;
                break; // rompe el ciclo
            }
        }
    }
    if (paulaString[0] == paulaString[2])
    {
        resultado = a * b;
        cout << "Es igual " << endl;
    }
    cout << "El resultado es: " << resultado << endl;
    resultado = 0;
}
void vector3()
{
    int numb;
    std::vector<int> elvector3;
    for (int i = 97; i < 123; i++)
    {
        elvector3.push_back(i);
    }
    std::default_random_engine e(time(NULL));
    std::shuffle(std::begin(elvector3), std::end(elvector3), e);
    cout << "Ingrese un número menor a 25" << endl;
    std::cin >> numb;
    for (int i = 0; i < numb; i++)
    {
        std::string s1;
        s1 = (char)elvector3[i];
        cout << "El valor random de " << elvector3[i] << " Equivale a : " << s1 << endl;
    }
}

////////
int matrices[100][100] = {0};
void listarmatriz(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cout << matrices[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
void matrizGrafica()
{
    int tama = 11;
    int cS = 3;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {

            if (i == j)
            {
                matrices[i][j] = 2;
            }
            else if ((i + j) == tama - 1)
            {
                matrices[i][j] = 3;
            }
            if (i > (tama / 2) - cS && i < (tama / 2) + cS)
            {
                if (j > (tama / 2) - cS && j < (tama / 2) + cS)
                {
                    matrices[i][j] = 1;
                }
            }
            if (i == (tama / 2) && j == (tama / 2))
            {
                matrices[i][j] = 4;
            }
        }
    }
    listarmatriz(11,11);
}
void pedirNombre()
{
    cout << "Ingrese un nombre" << endl;
    char nombre[1024];
    std::cin.ignore();
    std::cin.getline(nombre,1024,'\n');
    if(nombre[0] == 'A' || nombre[0] == 'a')
    {
        cout << strlwr(nombre) << endl;
    }
    else
    {
        cout << nombre << endl;
    }
}
void limpiar()
{
    cout << "Presiona una tecla para continuar" << endl;
    getch();

    system("cls");
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
            vector10();
            limpiar();
            break;
        }
        case 2:
        {
            paula();
            limpiar();
            break;
        }
        case 3:
        {
            vector3();
            limpiar();
            break;
        }
        case 4:
        {
            matrizGrafica();
            limpiar();
            break;
        }
        case 5:
        {
            pedirNombre();
            limpiar();
            break;
        }

        default:
            break;
        }
    } while (opt != 0);
}