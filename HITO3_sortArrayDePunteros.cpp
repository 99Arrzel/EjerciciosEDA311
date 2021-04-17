//Hacerlo con punteros
#include <iostream>
#include <conio.h>
/*
3	5	7	9		v1

45	67	12	89		v2
///////////////////////Debe quedar como abajo
89	12	67	45		

9	7	5	3	
*/
int main()
{
    //punteros para vectores
    int v1[4] = {3, 5, 7, 9};
    int v2[4] = {45, 67, 12, 89};
    int v3[4] = {0}; // para swap
    int *pointer;
    pointer = v1 + 3;
    for (int i = 0; i < 4; i++) //movemos al reves el v1 al v3
    {
        v3[i] = *pointer;
        pointer--;
    }
    pointer = v2 + 3;           //iniciamos en el 2
    for (int i = 0; i < 4; i++) //movemos al reves el v2 al v1
    {
        v1[i] = *pointer;
        pointer--;
    }
    pointer = v3;               //iniciamos en el 1
    for (int i = 0; i < 4; i++) //movemos al reves el v3 al v2
    {
        v2[i] = *pointer;
        pointer++;
    }
    //Display de resultado:
    for (int i = 0; i < 4; i++)
    {
        std::cout << v1[i] << "\t";
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << v2[i] << "\t";
    }
    getch();
    return 0;
}
