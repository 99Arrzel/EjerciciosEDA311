#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>
#include <cstring>
void menu()
{
    std::cout << "0)SALIR" << std::endl
              << "1)Generar un cuadradro magico" << std::endl
              << "2)Generar las siguientes matrices" << std::endl
              << "3)Calcular la producción de lechde de N vacas" << std::endl;
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
void matrices()
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
            matrices();
            getch();
            break;
        }
        case 3:
        {
            
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