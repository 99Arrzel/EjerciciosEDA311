#include <iostream>
#include <math.h>
#include <conio.h>
int main()
{
    double x = 1, z = 1, y = 1;
    double sumarVelocidad = 0;
    double n;
    do
    {
        n++;
        x = z;
        sumarVelocidad += 100;
        z = (0.5) * pow(sumarVelocidad,2.0);
        y = z/x;
        std::cout << "El primer resultado es: "<< y <<"\n";
        std::cout << "x = " << x << "\n";
        std::cout << "z = " << z << "\n";
        std::cout << "sucesión: " << n << "\n";
        
        
    } while (y != 1);
    getch();
    return 0;
}