#include <iostream>
#include <conio.h>

int main()
{
    int value = 5;

    int *ptr = &value;
    std::cout << *ptr;
    getch();
    return 0;
}
