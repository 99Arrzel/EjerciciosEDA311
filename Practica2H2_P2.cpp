//ESTRUCTURAS ARRAYS BIDIMENSIONALES
//Completar el menú y la opciones de diagonal secundaria,triangular superior e inferior
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define tam 50
using namespace std;
int m[tam][tam] = {0};
int fila, col, rangoinicial = 0, rangofinal = 0;

void listarMatriz()
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << m[i][j] << '\t';
        }
        cout << endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
void insertRandom()
{

    cout << "Filas-->";
    cin >> fila;
    cout << "Columnas-->";
    cin >> col;
    srand(time(NULL));
    std::cout << "Rango randomico INICIAL" << std::endl;
    std::cin >> rangoinicial;
    std::cout << "Rango randomico FINAL" << std::endl;
    std::cin >> rangofinal;
    int valorandom;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            /*+cout<<"m["<<i<<"]["<<j<<"]=";
        cin>>m[i][j] ;*/
            valorandom = rand() % rangofinal + rangoinicial;
            m[i][j] = valorandom;
        }
    }
    listarMatriz();
}
void insertManual()
{
    cout << "Filas-->";
    cin >> fila;
    cout << "Columnas-->";
    cin >> col;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "m[" << i << "][" << j << "]=";
            cin >> m[i][j];
        }
    }
}

void DiagonalPrinc(int insertarthis)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
                m[i][j] = insertarthis;
        }
    }
    listarMatriz();
}
void DiagonalSecundaria(int insertarthis)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((i + j) == fila - 1)
                m[i][j] = insertarthis;
        }
    }
    listarMatriz();
}
void triangulosuperior(int insertarthis)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i < j)
                m[i][j] = insertarthis;
        }
    }
    listarMatriz();
}
void trianguloinferior(int insertarthis)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i > j)
                m[i][j] = insertarthis;
        }
    }
    listarMatriz();
}
void vermenu()
{
    std::cout << "1) Mostrar matriz" << std::endl
              << "2) Insertar números aleatorios" << std::endl
              << "3) Insertar números manualmente" << std::endl
              << "4) Insertar en diagonal principal" << std::endl
              << "5) Insertar en diagonal secundaria" << std::endl
              << "6) Insertar en triangulo superior" << std::endl
              << "7) Insertar en triangulo inferior" << std::endl;
}

int main()
{
    int opt = 0;
    do
    {
        vermenu();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            listarMatriz();
            getch();
            break;
        }
        case 2:
        {
            insertRandom();
            getch();
            break;
        }
        case 3:
        {
            insertManual();
            getch();
            break;
        }
        case 4:
        {
            int insertarthis;
            std::cout << "¿Con que desea llenar la diagonal?" << std::endl;
            std::cin >> insertarthis;
            DiagonalPrinc(insertarthis);
            getch();
            break;
        }
        case 5:
        {
            int insertarthis;
            std::cout << "¿Con que desea llenar la diagonal?" << std::endl;
            std::cin >> insertarthis;
            DiagonalSecundaria(insertarthis);
            getch();
            break;
        }
        case 6:
        {
            int insertarthis;
            std::cout << "¿Con que desea llenar el triangulo??" << std::endl;
            std::cin >> insertarthis;
            triangulosuperior(insertarthis);
            getch();
            break;
        }
        case 7:
        {
            int insertarthis;
            std::cout << "¿Con que desea llenar el triangulo??" << std::endl;
            std::cin >> insertarthis;
            trianguloinferior(insertarthis);
            getch();
            break;
        }
        default:
            break;
        }

    } while (opt != 0);

    return 0;
}
