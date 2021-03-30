// practica malaza
#include <iostream>  //cout
#include <string>    //getline
#include <conio.h>   // getch
#include <vector>    //vector
#include <Windows.h> //sleep
#include <algorithm> //reverse

using std::cout;
std::string pass, mensaje, pass2, reversa;
std::vector<std::string> mensajeEncriptado;
int passN, passN2, mensajeCheck, checksum = 0, passNcheck = 0;
char ch = '0';
int optme = 0;
int opt = 0;
int estaEncriptado = 0;
void obtenerPass()
{
    passN = 0;
    checksum = 0;
    cout << "Ingrese la clave para encriptar\n";
    std::cin.ignore();
    std::getline(std::cin, pass);
    reverse(pass.begin(), pass.end());
    for (int i = 0; i < pass.length(); i++) // suma de todos los
    {
        passN += (int(pass[i]) * i) * 3; // le sumo i para que varie con la longitud, 3 para variar más
    }
    passNcheck = 1;
}
void encriptado()
{
    obtenerPass();
    if (mensajeCheck == 0)
    {
        cout << "Debes introducir un mensaje primero";
        return;
    }
    if (passNcheck == 0)
    {
        cout << "\nIngresa una PASS primero\n";
        return;
    }

    for (int i = 0; i < mensaje.length(); i++)
    {

        mensajeEncriptado.push_back(std::to_string(int(mensaje[i]) * passN));
        cout << "Para la letra " << mensaje[i] << " valor " << mensajeEncriptado[i] << "\n";
        if (i % 2 == 0)
        {
            checksum += int(mensaje[i]) * passN;
        }
        Sleep(150); // para hacerlo más dramático
    }
    estaEncriptado = 1;
    cout << "\nEl checksum es..."
         << checksum << "\n";
}
void obtenerMensaje()
{
    if (mensaje.empty() == false)
    {
        cout << "Hay un mensaje almacenado, ¿desea sobreescribirlo?\n1)SI\n2)NO\n";
        std::cin >> optme;
        if (optme == 2 || 0)
        {
            return;
        }
        else if (optme == 1)
        {
            estaEncriptado = 0;
        }
    }
    mensajeEncriptado.clear();
    mensaje.clear();
    cout << "Ingrese el mensaje a encriptar\n";
    std::cin.ignore(); //limpia el buffer del input, al parecer no funciona sin esto
    std::getline(std::cin, mensaje);
    mensajeCheck = 1;
}

void desEncriptado()
{
    cout << "Introduzca la PASS\n";
    std::cin.ignore();
    std::getline(std::cin, pass2);
    reverse(pass2.begin(), pass2.end());
    for (int i = 0; i < pass2.length(); i++) // suma de todos los
    {
        passN2 += (int(pass2[i]) * i) * 3; // le sumo i para que varie con la longitud, 3 para variar más
    }

    cout << "--------------El mensaje es ----------------"
         << "\n";
    if (estaEncriptado == 1)
    {
        int lmensaje = mensaje.length();
        for (int i = 0; i < lmensaje; i++)
        {
            int nchar = std::stoi(mensajeEncriptado[i]) / passN2;
            if (nchar >= 0 && nchar <= 127) //valores ASCII
            {
                ch = (char)nchar;
            }
            cout << ch;
        }
    }
    else
    {
        cout << "Encripta el mensaje primero\n";
    }
    passN2 = 0;
}

void mensajeActual()
{
    cout << "El mensaje actual es: \n";
    cout << mensaje;
    cout << "\nEl mensaje encriptado es :\n";
    int mensajeSize = mensajeEncriptado.size();
    for (int i = 0; i < mensajeSize; i++)
    {
        cout << mensajeEncriptado[i] << " ";
    }
    cout << "El checksum es: " << checksum << "\n";
}
void presioneTecla()
{
    cout << "\n\nPresione una tecla para continuar\n";
    getch();
    system("cls");
}
void menu()
{
    cout << "0)SALIR\n";
    cout << "1)Ingresar Mensaje\n";
    cout << "2)Encriptar\n";
    cout << "3)Desencriptar\n";
    cout << "4)Mensaje actual\n";
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
            system("cls");
            obtenerMensaje();
            presioneTecla();
            break;
        }
        case 2:
        {
            system("cls");
            encriptado();
            presioneTecla();
            break;
        }
        case 3:
        {
            system("cls");
            desEncriptado();
            presioneTecla();
            break;
        }
        case 4:
        {
            system("cls");
            mensajeActual();
            presioneTecla();
            break;
        }
        default:
            break;
        }

    } while (opt != 0);
    cout << "\nProceso terminado\n";
    getch();
    return 0;
}