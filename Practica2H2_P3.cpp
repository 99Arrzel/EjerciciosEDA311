#include <iostream>
#include <iomanip>
#include <conio.h>

void generarCuadro(int n)
{
    int magicSquare[100][100] = {0}; 

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else {
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
            magicSquare[i][j] = num++; // set number
 
        j++;
        i--; // 1st condition
    }
 
    std::cout << "The Magic Square for n=" << n
         << ":\nSum of "
            "each row or column "
         << n * (n * n + 1) / 2 << ":\n\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
 
            // setw(7) is used so that the matrix gets
            // printed in a proper square fashion.
            std::cout << std::setw(4) << magicSquare[i][j] << " ";
        std::cout << std::endl;
    }
}
int main()
{
    int n = 0;
    std::cout << "Introduzca un número" << std::endl;
    std::cin >> n;
    generarCuadro(n);
    getch();

    return 0;
}