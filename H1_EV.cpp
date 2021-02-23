#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
//para mezclar
int main()
{
    std::string enu = " es el mayor de todos";
    int a, b, c, ex, i;
    std::cout << "Ingrese una opción" << std::endl
              << "1)Hallar el mayor de 3 números" << std::endl
              << "2)Generar n términos de la siguiente serie: 1, 3... etc" << std::endl
              << "3)Leer n números y hallar el promedio total" << std::endl
              << "4)Leer un número y hallar el primer dígito" << std::endl
              << "5)Lanzar 2 dados 50 veces. Visualizar el número de veces que salieron iguales y su porcentaje respecto del total de lanzamientos " << std::endl
              << "6)Establecer en forma randómica los 250 votos otorgados a los 3 candidatos a gobernador y mostrar el número de votos obtenidos por cada uno de ellos, al ganador y el porcentaje correspondiente a cada uno de ellos." << std::endl
              << "7)Almacenar en un vector de 50 posiciones, valores entre 1 y 90 que no se repitan y ordenar en forma ascendente.Mostrar el vector ordenado y aquellos elementos que son mayor al promedio del vector " << std::endl;
    std::cin >> ex;
    switch (ex)
    {
    case 1:
    {
        std::cout << "Ingrese el primer número : ";
        std::cin >> a;
        std::cout << "Ingrese el segundo número : ";
        std::cin >> b;
        std::cout << "Ingrese el tercer número : ";
        std::cin >> c;
        if (a > b && a > c)
        {
            std::cout << a << enu;
        }
        if (b > c && b > a)
        {
            std::cout << b << enu;
        }
        if (c > b && c > a)
        {
            std::cout << c << enu;
        }
    }
    case 2:
    {
        std::cout << "Ingrese la cantidad de terminos " << std::endl;
        std::cin >> a;
        b = 1;
        for (i = 0; i < a; i++)
        {
            std::cout << b;
            b = b + 2;
            if (i < a - 1)
            {
                std::cout << " , ";
            }
        }
        break;
    }
    case 3:
    {
        std::cout << "Ingrese la cantidad de terminos para hallar promedio (N)" << std::endl;
        std::cin >> a;
        b = 0;
        c = 0;
        for (i = 0; i < a; i++)
        {
            std::cout << "Ingrese el termino " << i + 1 << std::endl;
            std::cin >> b;
            c = c + b;
        }
        c = c / a;
        std ::cout << "El promedio es : " << c << std::endl;
    }
    case 4:
    {
        std::cout << "Ingrese un número" << std::endl;
        std::cin >> a;
        if (a == 0)
        {
            std::cout << "0";
            break;
        }
        int pri = a;
        //solo funciona para un int de 10 digitos, por suerte un int32 es 9 digitos
        for (pri = a; pri >= 10; pri = pri / 10)
            ;
        std::cout << "el primer número es : " << pri;
    }
    case 5:
    {
        double contador = 0;
        for (i = 0; i < 40; i++)
        {
            int d1 = rand() % 6 + 1;
            int d2 = rand() % 6 + 1;
            std::cout << "lanzamiento " << i + 1 << " de 40" << std::endl;
            if (d1 == d2)
            {
                std::cout << d1 << " coincide con " << d2 << std::endl;
                contador++;
            }
        }
        double resultado = (contador / 40) * 100;
        std::cout << "El porcentaje de paridad es : " << resultado << "%, " << contador << " de 40 lanzamientos." << std::endl;
    }
    case 6:
    {
        double contador1, contador2, contador3;
        for (i = 0; i < 250; i++)
        {
            a = 0;
            a = rand() % 3 + 1;
            if (a == 1)
                contador1++;
            if (a == 2)
                contador2++;
            if (a == 3)
                contador3++;
        }
        double resultado1 = (contador1 / 250) * 100;
        double resultado2 = (contador2 / 250) * 100;
        double resultado3 = (contador3 / 250) * 100;
        std::cout << "El primer candidato sacó " << contador1 << " votos, que es el " << resultado1 << "% de 250 votos" << std::endl;
        std::cout << "El segundo candidato sacó " << contador2 << " votos, que es el " << resultado2 << "% de 250 votos" << std::endl;
        std::cout << "El tercer candidato sacó " << contador3 << " votos, que es el " << resultado3 << "% de 250 votos" << std::endl;
        std::string enun = "Gano el candidato número :";
        if (contador1 > contador2 && contador1 > contador3)
            std::cout << enun << 1 << std::endl;
        if (contador2 > contador1 && contador2 > contador3)
            std::cout << enun << 2 << std::endl;

        if (contador3 > contador1 && contador3 > contador1)
            std::cout
                << enun << 3 << std::endl;
    }
    case 7:
    {
        int cop[90];
        int pos[50];
        int prom, suma;
        for (i = 0; i < 90; i++)
        {
            cop[i] = i;
        }
        std::cout << "Vector desordenado :" << std::endl;
        unsigned semilla = std::chrono::system_clock::now().time_since_epoch().count();
        // obtener una "semilla", sino, el promedio no varia casi nada std::shuffle(std::begin(cop), std::end(cop), std::default_random_engine(semilla));
        for (i = 0; i < 50; i++)
        {
            pos[i] = cop[i];
            std::cout << i + 1 << ": " << pos[i] << " " << std::endl;
            suma = pos[i];
            prom = prom + suma;
        }
        prom = prom / 50;
        std::cout << "Vector ordenado de manera ascendente :";
        std::sort(std::begin(pos), std::end(pos));
        for (i = 49; i != -1; i--) //mostrar el vector de manera ascendente
        {
            std::cout << i + 1 << " :" << pos[i] << " " << std::endl;
        }
        std::cout << std::endl
                  << "Los elementos mayores que el promedio de : " << prom << " son: " << std::endl;
        for (i = 0; i < 50; i++) //elementos mayores que el promedio
        {
            if (pos[i] > prom)
                std::cout << pos[i] << " ";
        }
        int cheq = rand() % 2 + 1;
        if (cheq == 1)
        {
            
        }
    }
    default:
        std::cout << "Elegiste mal.";
        break;
    }
}