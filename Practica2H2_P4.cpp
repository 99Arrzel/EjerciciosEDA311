#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#define tam 100
using namespace std;
int v[tam];
int t;

void menu()
{
    cout << "MENU BUSQUEDA" << endl;
    cout << "1.Carga" << endl;
    cout << "2.Listado" << endl;
    cout << "3.Busqueda Secuencial" << endl;
    cout << "4.Busqueda Binaria" << endl;
    cout << "5.Salir" << endl;
    cout << "Elije opcion--->";
}

void carga_dato()
{
    int limInf, limSup;
    srand(time(NULL));
    cout << "Dimension del vector--";
    cin >> t;
    cout << "Limite Inferior-->";
    cin >> limInf;
    cout << "Limite Superior-->";
    cin >> limSup;
    for (int i = 0; i < t; i++)
    {
        v[i] = limInf + rand() % ((limSup + 1) - limInf);
    }
}
void listar()
{
    for (int i = 0; i < t; i++)
    {
        cout << v[i] << '\t';
    }
    cout << endl;
}

void busq_bina()
{
    int primero = 0, ultimo = t, medio, dato;
    sort(v, v + t);
    cout << endl;
    listar();
    cout << endl;
    cout << "Dato a buscar--->";
    cin >> dato;
    medio = (primero + ultimo) / 2;
    for (int i = 0; i < t; i++)
    {
        medio = (primero + ultimo) / 2;
        if (v[medio] == dato)
        {
            cout << "encontrado en  l posicion--->" << medio + 1;
            cout << endl;
            break;
        }
        if (v[medio] > dato)
        {
            primero = 0;
            ultimo = medio - 1;
        }
        if (v[medio] < dato)
        {
            primero = medio + 1;
        }
    }
}
void busq_sec()
{
    int dato;
    cout << endl;
    listar();
    cout << endl;
    cout << "Dato a buscar--->";
    cin >> dato;
    for (int i = 0; i < t; i++)
    {
        if (v[i] == dato)
        {
            cout << v[i] << " se encuntra en la pisicion " << i + 1 << endl;
            break;
        }
    }
}

int main()
{
    int op = 0;

    do
    {
        menu();
        cin >> op;
        system("cls");
        switch (op)
        {
        case 1:
        {
            carga_dato();
            break;
        }
        case 2:
        {
            listar();
            break;
        }
        case 4:
        {
            busq_bina();
        }
        case 5:
        {
            busq_sec();
            break;
        }
        default:
        {
            cout << "Opcion no válida" << endl;
            break;
        }
        }
    } while (op != 5);

    return 0;
}