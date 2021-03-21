#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <cwchar>
#include <sstream> // istring
#include <vector>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int opt;
std::string nombre, resultado, alreves, a, b, apellido;
;
std::string frase;
void limpiar()
{

    int n;
    for (n = 0; n < 10; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}
void ingresaNombre()
{
    std::cout << "Ingresa un nombre \n";
    std::cin >> nombre;
}
void ingresaApellido()
{
    std::cout << "Ingresa un apellido \n";
    std::cin >> apellido;
}
void ingresaFrase()
{
    std::cout << "Ingresa una frase \n";
    std::cin.ignore(); //limpia el buffer del input, al parecer no funciona sin esto
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); Lo mismo pero con funciones extra??
    std::getline(std::cin, frase);
}
void saludarMaria()
{
    ingresaNombre();
    resultado = "Hola " + nombre;
    std::cout << "\n"
              << resultado;
}

void nombreTriangularInvertido()
{
    ingresaNombre();
    for (int i = nombre.length(); i > -1; i--)
    {
        for (int j = 0; j < nombre.length() + 1; j++)
        {
            if (j < i)
            {
                std::cout << nombre[j];
            }
        }
        std::cout << "\n";
    }
}
void visualizarAlReves()
{
    ingresaNombre();
    for (int i = nombre.length(); i > -1; i--)
    {
        std::cout << nombre[i] << "\n";
    }
}
void visualizarDiagonal()
{
    ingresaNombre();
    for (int i = 0; i < nombre.length() + 1; i++)
    {
        for (int j = 0; j < nombre.length() + 1; j++)
        {
            if (i == j)
            {
                std::cout << nombre[i];
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}
void enOtraCadena()
{
    ingresaNombre();
    std::string otraCadena = nombre;
    std::cout << "Nueva cadena = " << otraCadena << "\n";
}
void enOtraCadenaLetraInvertida()
{
    ingresaNombre();
    std::string otracadena(nombre.length(), 'x');
    otracadena.reserve(otracadena.length());
    int j = 0;
    for (int i = nombre.length() - 1; i != -1; i--)
    {
        otracadena[j] = nombre[i];
        j++;
    }
    std::cout << "La nueva cadena es :" << otracadena << "\n";
}
void eliminarEspacios()
{
    ingresaFrase();
    frase.erase(std::remove_if(frase.begin(), frase.end(), ::isspace), frase.end());
    std::cout << frase; // el w es para width characters, no me funciono, no imprime la ñ o las tildes
}
void aMayusculas()
{
    ingresaFrase();
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < frase.length(); i++)
    {
        for (int j = 0; j < sizeof(vocales); j++)
        {
            if (vocales[j] == frase[i])
            {
                frase[i] = toupper(frase[i]);
            }
        }
    }
    std::cout << "La frase es : " << frase;
    std::cout << "\n";
}
void esPalindromo()
{
    bool seraPalindromo = false;
    ingresaFrase();
    std::string borrarCaracteres = ",.?¿!¿¡"; // caracteres a borrar para que lea bien
    for (int i = 0; i < frase.length(); i++)
    {
        for (int j = 0; j < borrarCaracteres.length(); j++)
        {
            if (frase[i] == borrarCaracteres[j])
            {
                frase.erase(i, 1); // borrar , o .
            }
        }
    }
    std::istringstream iss(frase);
    while (iss >> a)
    {
        b = a;
        reverse(b.begin(), b.end());
        for (int j = 0; j < a.length(); j++)
        {
            if (a[j] != b[j])
            {
                std::cout << b << " ";
                std::cout << " ---------No es palindromo \n";
                seraPalindromo = false;
                break;
            }
            if (a[j] == b[j])
            {
                seraPalindromo = true;
            }
        }
        if (seraPalindromo == true)
        {
            std::cout << b << "  --------- Es palindromo\n";
        }
    }
}
void visualizarPalabraporPalabra()
{
    ingresaFrase();
    std::istringstream iss(frase);
    while (iss >> a)
    {
        std::cout << a << "\n";
    }
}
void contarLetrasNombre()
{
    ingresaNombre();
    std::cout << "Tu nombre tiene " << nombre.length() << " letras\n";
    ingresaApellido();
    int countApellidoLetras = apellido.length();
    std::cout << "Tu apellido tiene " << apellido.length() << " letras\n";
    ingresaApellido();
    std::cout << "Tu segundo apellido tiene " << apellido.length() << " letras\n";
    countApellidoLetras += apellido.length();
    int sumatotal = countApellidoLetras + nombre.length();
    std::cout << "Tus apellidos tienen una longitud de: " << countApellidoLetras << " y con tu nombre suman " << sumatotal << "\n";
}
void contarVocalesEnFrase()
{

    ingresaFrase();
    std::string vocales = "aeiou";
    int contarVocales = 0;
    for (int i = 0; i < frase.length(); i++)
    {
        for (int j = 0; j < vocales.length(); j++)
        {
            if (tolower(frase[i]) == vocales[j])
            {
                contarVocales++;
            }
        }
    }
    std::cout << "Esta frase tiene " << contarVocales << " vocales.\n";
}
void intentosPalabraClave()
{
    int numeroDeIntentos = 0;
    bool acceso = false;
    std::cout << "Ingresa una palabra clave\n";
    std::cin >> a;
    std::for_each(a.begin(), a.end(), [](char &c) { c = ::toupper(c); }); // a mayusculas como pide
    std::cout << "Palabra clave: " << a << "\n";
    while (acceso == false)
    {
        std::cout << "Ingrese una palabra\n";
        std::cin >> b;
        std::for_each(b.begin(), b.end(), [](char &c) { c = ::toupper(c); }); // a mayusculas como pide
        if (a == b)
        {
            acceso = true;
            std::cout << "clave dee acceso autenticada \n";
        }
        numeroDeIntentos++;
        std::cout << "Número de intentos = " << numeroDeIntentos << "\n";
    }
}

void ordenarNombres()
{
    /* un poco arcaico y solo funciona con la primera letra
    std::string nombres[3];
    char chec, chectwo;
    for (int i = 0; i < 3; i++)
    {
        ingresaNombre();
        nombres[i] = nombre;
    }
    std::string abece = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < abece.length(); i++)
    {
        for (int j = 0; j < 3; j++) // ciclo para current name
        {
            chec = nombres[j].at(0); // Primera letra
            chectwo = nombres[j].at(1); // segunda letra
            toupper(chec);
            if (chec == abece[i])    // si primera letra empieza con:
            {
                std::cout << nombres[j] << "\n"; // primera letra
            }
        }
    }
    */
    std::string nombres, comparador;
    std::vector<std::string> stringVector;
    for (int i = 0; i < 3; i++)
    {
        ingresaNombre();
        nombres = nombres.append(nombre) + " ";
    }
    std::istringstream t(nombres);
    while (t >> comparador) //pasando los strings a un vector
    {
        stringVector.push_back(comparador); // push para meterlos
    }
    sort(stringVector.begin(), stringVector.end());                   // sort el vector
    for (auto i = stringVector.begin(); i != stringVector.end(); i++) // mostrar
    {
        std::cout << *i << "\n";
    }
}
void gotoXY(int x, int y);

void moverPalabraPantalla()
{
    ingresaFrase();
    system("cls");
    int x = 1;
    int y = 5;

    gotoXY(24, 2);
    std::cout << "La palabra se mueve";

    for (x = 1; x < 27; x++)
    {
        gotoXY(x, y);
        std::cout << frase;

        Sleep(100);
        gotoXY(x, y);
        std::cout << " ";
    }
    x--;
    for (x = 27; x > 1; x--)
    {
        gotoXY(x, y);
        std::cout << frase << " ";

        Sleep(100);
        gotoXY(x, y);
        std::cout << " ";
    }

    for (y = 5; y < 23; y++)
    {
        Sleep(100);
        gotoXY(x, y);
        std::cout << "                                   ";
        Sleep(200);
        gotoXY(x, y + 1);
        std::cout << frase;
    }
    Sleep(800);
    for (y = 23; y > 8; y--)
    {
        Sleep(100);
        gotoXY(x, y);
        std::cout << "                                   ";
        Sleep(200);
        gotoXY(x, y - 1);
        std::cout << frase;
    }

    Sleep(500);
    gotoXY(23, 24);
    std::cout << "F I N";
    getch();
}
void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void endCase()
{
    getch();
    limpiar();
}

void listaPractica()
{
    std::cout << "\n ----INGRESA UNA OPCIÓN ---ñ- \n"
              << std::endl
              << "0) SALIR" << std::endl
              << "1)Ingresa un nombre por teclado y visualizalo con un un saludo" << std::endl
              << "2)Ingresa un nombre y visualizalo en forma triangular invertido" << std::endl
              << "3)Ingresa un nombre y visualízalo al revés" << std::endl
              << "4)Ingresa un nombre y visualízalo letra por letra en diagonal" << std::endl
              << "5)Ingresa un nombre y almacénalo en otra cadena" << std::endl
              << "6)Ingresa un nombre y almacénalo, letra por letra en otra cadena" << std::endl
              << "7)Ingresa un nombre y almacénalo, letra por letra invertido" << std::endl
              << "8)Ingresa una frase y suprime todos los espacios en blanco" << std::endl
              << "9)Ingresar una frase en minusculas y reemplazar todas las vocales a mayúsculas" << std::endl
              << "10)Chequear si una frase o palabra es palindromo" << std::endl
              << "11)Ingresa una palabra y visualiza sus palabras en filas diferentes " << std::endl
              << "12)Ingresa una frase por teclado y cuenta el número de vocales que contiene" << std::endl
              << "13)Muestra los intentos para lograr que una palabra ingresada por teclado sea igual a una palabra clave (clave de acceso). La comparación debe hacerse con mayúsculas" << std::endl
              << "14)Ingresar tres nombres por teclado en mayúsculas. ordenarlos en forma ascendente." << std::endl
              << "15)Ingresa una palabra. Haz que esta palabra se mueva de izquierda a derecha en la pantalla y viceversa. Luego que baje y suba." << std::endl;
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    do
    {
        listaPractica();
        std::cin >> opt;
        switch (opt)
        {
        case 1: // 1
        {
            saludarMaria();
            endCase();
            break;
        }
        case 2: //3
        {
            nombreTriangularInvertido();
            endCase();
            break;
        }
        case 3: //5
        {
            visualizarAlReves();
            endCase();
            break;
        }
        case 4: // 7
        {
            visualizarDiagonal();
            endCase();
            break;
        }
        case 5: //9
        {
            enOtraCadena();
            endCase();
            break;
        }
        case 6: //11
        {
            enOtraCadenaLetraInvertida();
            endCase();
            break;
        }
        case 7: //13
        {
            eliminarEspacios();
            endCase();
            break;
        }
        case 8: //15
        {
            aMayusculas();
            endCase();
            break;
        }
        case 9: //17
        {
            esPalindromo();
            endCase();
            break;
        }
        case 10: //19
        {
            visualizarPalabraporPalabra();
            endCase();
            break;
        }
        case 11: //21
        {
            contarLetrasNombre();
            endCase();
            break;
        }
        case 12: //23
        {
            contarVocalesEnFrase();
            endCase();
            break;
        }
        case 13: //25
        {
            intentosPalabraClave();
            endCase();
            break;
        }
        case 14: //27
        {
            ordenarNombres();
            endCase();
            break;
        }
        case 15: //27
        {
            limpiar();
            moverPalabraPantalla();
            endCase();
            break;
        }
        default:
            break;
        }
    } while (opt != 0);

    return 0;
}