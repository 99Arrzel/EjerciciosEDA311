#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>
#include <cstring>
int matrices[100][100] = {0};
int matrices2[100][100] = {0};
int matrices3[100][100] = {0};
void menu()
{
    std::cout << "0)SALIR" << std::endl
              << "1)Generar un cuadradro magico" << std::endl
              << "2)Generar las siguientes matrices" << std::endl
              << "3)Calcular la producción de leche semanal de N vacas" << std::endl
              << "4)Generar otras matrices..." << std::endl
              << "5)Suma de matrices de diferentes tamaños" << std::endl;
}

void generarCuadro(int n)
{
    //codigo de geeksforgeeks.org, corregido, no funcionaba con n=2
    int i = n / 2;
    int j = n - 1;
    int magicSquare[100][100] = {0};
    if (n != 2)
    {
        for (int num = 1; num <= n * n;)
        {
            if (i == -1 && j == n)
            {
                j = n - 2;
                i = 0;
            }
            else
            {
                if (j == n)
                    j = 0;
                if (i < 0)
                    i = n - 1;
            }
            if (magicSquare[i][j])
            {
                j -= 2;
                i++;
                continue;
            }
            else
                magicSquare[i][j] = num++;

            j++;
            i--;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                magicSquare[i][j] = 1;
            }
        }
    }

    std::cout << "El cuadrado mágico de tamaño " << n
              << ":" << std::endl;
    std::cout << "Suma de cada fila y columna: ";
    if (n == 2)
    {
        std::cout << " 2" << std::endl;
    }
    else
    {
        std::cout << n * (n * n + 1) / 2 << "\n\n";
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            std::cout << std::setw(7) << magicSquare[i][j] << " ";
        std::cout << std::endl
                  << std::endl;
    }
}
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
void listarmatriz2(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cout << matrices2[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
void listarmatriz3(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cout << matrices3[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
void lasmatrices()
{
    int matrices[5][5] = {0};
    int c = 0;
    for (int i = 0; i < 5; i++) //1
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i + j) >= 4)
            {
                c++;
                matrices[i][j] = c;
            }
            std::cout << std::setw(7) << matrices[i][j] << " ";
        }
        c = 0;
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    for (int i = 0; i < 5; i++) //2
    {
        c++;
        for (int j = 0; j < 5; j++)
        {
            matrices[i][j] = c;
            std::cout << std::setw(7) << matrices[i][j] << " ";
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    c = 1;
    for (int i = 0; i < 5; i++) //3
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 5; j++)
            {
                matrices[j][i] = c;
                c++;
            }
        }
        else
        {
            for (int j = 4; j > -1; j--)
            {
                matrices[j][i] = c;
                c++;
            }
        }

        c++;
        c--;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << std::setw(7) << matrices[i][j] << " ";
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    c = 0;
    for (int i = 0; i < 5; i++) //4
    {
        for (int j = 0; j < 5; j++)
        {
            c++;
            matrices[j][i] = c;
        }
        c++;
        c--;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << std::setw(7) << matrices[i][j] << " ";
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "---------------------------------------------4up-" << std::endl;
    for (int i = 0; i < 5; i++) //5
    {
        for (int j = 0; j < 5; j++)
        {
            if (i <= j)
            {
                matrices[i][j] = pow(2, i);
            }
            if (i < j)
            {
                matrices[j][i] = pow(2, i);
            }
            std::cout << std::setw(7) << matrices[i][j] << " ";
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    c = 0;
    for (int i = 0; i < 5; i++) //6
    {
        c++;
        if (i % 2 == 0)
        {
            for (int j = 0; j < 5; j++)
            {
                matrices[i][j] = c;
                c++;
            }
        }
        else
        {
            for (int j = 4; j > -1; j--)
            {
                matrices[i][j] = c;
                c++;
            }
        }
        c--;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << std::setw(7) << matrices[i][j] << " ";
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "--------------------------------------------6up-" << std::endl;
    for (int i = 0; i < 5; i++) //7
    {
        {
            for (int j = 0; j < 5; j++)
            {
                matrices[i][j] = i + 1;
                if (i >= j)
                    std::cout << std::setw(7) << matrices[i][j] << " ";
            }
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    for (int i = 0; i < 5; i++) //8
    {
        for (int j = 0; j < 5; j++)
        {
            matrices[i][j] = (i + 1) * 5;
        }
    }
    for (int i = 0; i < 5; i++) //8
    {
        for (int j = 0; j < 5; j++)
        {
            if (i <= j)
            {
                std::cout << std::setw(7) << matrices[i][j] << " ";
            }
            else
            {
                std::cout << std::setw(8) << " ";
            }
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
}
void vacas(int n, int ingresarRandom)
{
    memset(matrices, 0, sizeof(matrices));
    int inicial, rfinal, prtotal = 0, indiceVaca = 0, mayorVaca = 0;

    if (ingresarRandom == 1)
    {
        srand(time(NULL));
        std::cout << "Ingrese el rango aleatorio INICIAL de producción de leche" << std::endl;
        std::cin >> inicial;
        std::cout << "Ingrese el rango aleatorio INICIAL de producción de leche" << std::endl;
        std::cin >> rfinal;
        for (int i = 0; i < n; i++)
        {
            std::cout << "Vaca número " << i + 1 << ":\t";
            for (int j = 0; j < 7; j++)
            {
                matrices[i][j] = rand() % rfinal + inicial;
                std::cout << matrices[i][j] << "\t";
                prtotal += matrices[i][j];
            }
            std::cout << "Producción de la vaca total es :" << prtotal;
            if (prtotal > mayorVaca)
            {
                indiceVaca = i + 1;
                mayorVaca = prtotal;
            }
            prtotal = 0;
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    if (ingresarRandom == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                std::cout << "Ingrese la producción para la vaca " << i + 1 << " en el día " << j + 1 << std::endl;
                std::cin >> matrices[i][j];
                prtotal += matrices[i][j];
                std::cout << std::endl;
            }
            if (prtotal > mayorVaca)
            {
                indiceVaca = i + 1;
                mayorVaca = prtotal;
            }
            prtotal = 0;
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << "Vaca número " << i + 1 << ":\t";
            for (int j = 0; j < 7; j++)
            {
                std::cout << matrices[i][j] << "\t";
                prtotal += matrices[i][j];
            }
            prtotal = 0;
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "La vaca que más ha producido es la vaca número " << indiceVaca << std::endl;
    indiceVaca = 0;
}
//matrices2
void lasmatrices2()
{
    memset(matrices, 0, sizeof(matrices));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || j == (5 / 2))
            {
                matrices[i][j] = 1;
            }
            std::cout << matrices[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                matrices[i][j] = i + 1;
            }
            std::cout << matrices[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i <= 2 && j <= 2)
            {
                matrices[i][j] = 1;
            }
            if (i >= 3 && j <= 2)
            {
                matrices[i][j] = 3;
            }
            if (i <= 2 && j >= 3)
            {
                matrices[i][j] = 2;
            }
            if (i >= 3 && j >= 3)
            {
                matrices[i][j] = 4;
            }
            std::cout << matrices[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((i + j) >= 4 - 1)
            {
                matrices[i][j] = (i + 1) * 2;
            }
            std::cout << matrices[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j >= i)
            {
                matrices[i][j] = 4 - j;
            }
            std::cout << matrices[i][j] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    int tt = 16;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            matrices[j][i] = tt;
            tt--;
        }
    }
    listarmatriz(4, 4);
    std::cout << "------------------------------------------------------asd-------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    tt = 16;
    int tama = 4;
    int contado = 16;
    for (int z = 0; z < 4; z++)
    {
        for (int i = 0; i < tama; i++) //i y j recorren todo el array, z aumenta su valor
        {
            for (int j = 0; j < tama; j++)
            {
                if (j == z && i < tama - z)
                {
                    matrices[i][j] = tt;
                    tt--;
                }
                if (i == (tama - 1) - z && j > z)
                {
                    matrices[i][j] = tt;
                    tt--;
                }
            }
        }
    }

    listarmatriz(4, 4);
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    tama = 11;
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
    listarmatriz(11, 11);
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    int multi = 1, expo = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrices[i][j] = multi;
            multi *= 2;
        }
        multi = expo * 2;
        expo = expo * 2;
    }
    listarmatriz(5, 5);
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            matrices[i][j] = 3;
            if (i == j)
            {
                matrices[i][j] = 1;
            }
            if ((i + j) == 7 - 1)
            {
                matrices[i][j] = 2;
            }
        }
    }
    listarmatriz(7, 7);
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
    int unodos = 1, unodos2 = 1;
    for (int z = 0; z < 5; z++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == z && i >= z)
                {
                    matrices[i][j] = unodos;
                    unodos++;
                }
                if (i == z && j >= z)
                {
                    matrices[i][j] = unodos2;
                    unodos2++;
                }
            }
        }
        unodos = 1;
        unodos2 = 1;
    }
    listarmatriz(5, 5);
    std::cout << "-------------------------------------------------------------" << std::endl;
    memset(matrices, 0, sizeof(matrices));
}
void sumarmatrices()
{
    int ax, bx, cx, dx;
    std::cout << "Ingresa el largo de la primera matriz" << std::endl;
    std::cin >> ax;
    std::cout << "Ingresa el ancho de la primera matriz" << std::endl;
    std::cin >> bx;
    srand(time(NULL));
    for (int i = 0; i < ax; i++)
    {
        for (int j = 0; j < bx; j++)
        {
            matrices[i][j] = rand() % 10 + 1;
        }
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    listarmatriz(ax, bx);
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Ingresa el largo de la segunda matriz" << std::endl;
    std::cin >> cx;
    std::cout << "Ingresa el ancho de la segunda matriz" << std::endl;
    std::cin >> dx;
    srand(time(NULL));
    for (int i = 0; i < cx; i++)
    {
        for (int j = 0; j < dx; j++)
        {
            matrices2[i][j] = rand() % 10 + 1;
        }
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    listarmatriz2(cx, dx);
    std::cout << "-------------------------------------------------------------" << std::endl;
    int nx, mx;
    if (ax > cx)
    {
        nx = ax;
    }
    else
    {
        nx = cx;
    }
    if (bx > dx)
    {
        mx = bx;
    }
    else
    {
        mx = dx;
    }
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            matrices3[i][j] = matrices[i][j] + matrices2[i][j];
        }
    }
    std::cout << "-----------------------RESULTADO-------------" << std::endl;
    listarmatriz3(nx, mx);
     std::cout << std::endl;
}

int main()
{
    int opt = 0;
    int n = 0;
    do
    {
        menu();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            std::cout << "Introduzca el tamaño del cuadro mágico" << std::endl;
            std::cin >> n;
            generarCuadro(n);
            getch();
            break;
        }
        case 2:
        {
            lasmatrices();
            getch();
            break;
        }
        case 3:
        {
            int nVacas;
            int numero;
            std::cout << "Ingrese el número de vacas" << std::endl;
            std::cin >> nVacas;
            std::cout << "Ingresa una opción de llenado" << std::endl
                      << "Aleatorio = 1" << std::endl
                      << "A mano = 2" << std::endl;
            std::cin >> numero;
            vacas(nVacas, numero);
            getch();
            break;
        }
        case 4:
        {
            lasmatrices2();
            getch();
            break;
        }
        case 5:
        {
            sumarmatrices();
            getch();
            break;
        }
        default:
            std::cout << "opción incorrecta" << std::endl;
            break;
        }
    } while (opt != 0);
    return 0;
}