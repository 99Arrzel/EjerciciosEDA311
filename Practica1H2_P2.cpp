#include <iostream>
#include <windows.h>
#include <algorithm> // std::sort
#include <time.h>    //std:: time
#define tam 100
using namespace std;
int edades[tam];
int t;

void crear()
{
    memset(edades, 0, sizeof(edades));
}

void menu_principal()
{
    //endl comsndo salti de linea
    //cout<< comando salida de datos por pantalla
    cout << "\t\t\tMENU ARRAY UNIDIMENSIONAL" << endl;
    cout << "\t1.Insertar" << endl;
    cout << "\t2.Listar" << endl;
    cout << "\t3.Modificar" << endl;
    cout << "\t4.Eliminar" << endl;
    cout << "\t5.Ordenar" << endl;
    cout << "\t6.Promedio/Mayor/Menor" << endl;
    cout << "\t7.Salir" << endl;
    cout << "Elija opcion---->";
}
void menu_insert()
{
    cout << "\t\t\tSUB-MENU INSERTAR" << endl;
    cout << "\t1.Por posicion" << endl;
    cout << "\t2.Aleatoria" << endl;
    cout << "\t3.Retornar" << endl;
    cout << "Elija opcion---->";
}

void posicion()
{
    if (edades[0] > 0)
        cout << "El vector ya contiene dato" << endl;
    else
    {
        cout << "Introduzca cantidad datos a insertar----->";
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            cout << "edades[" << i << "]=";
            cin >> edades[i];
        }
    }
    system("pause");
    system("cls");
}
void aleatoria()
{
    int limInf, limSup;
    srand(time(NULL));
    cout << "Introduzca cantidad datos a insertar----->";
    cin >> t;
    cout << "Limite inferir-->";
    cin >> limInf;
    cout << "Limite Superior--->";
    cin >> limSup;
    for (int i = 0; i < t; i++)
    {
        edades[i] = limInf + rand() % ((limSup + 1) - limInf);
    }
    system("pause");
    system("cls");
}
void listar()
{
    std::cout << "La lista es: " << std::endl;
    for (int i = 0; i < t; i++)
    {
        cout << edades[i] << '\t';
    }
    std::cout << std::endl;
    system("pause");
}

void modifLista()
{
    std::cout << "\tElija una opción" << std::endl
              << "\t 1) Modificar por dato" << std::endl
              << "\t 2)Modificar por posición" << std::endl;
}
void ordenarLista()
{
    std::cout << "\tElija una opción" << std::endl
              << "\t 1) Ascendente" << std::endl
              << "\t 2) Descendente " << std::endl;
}

void elim_lista()
{
    std::cout << "\tElija una opción" << std::endl
              << "\t 1) eliminar por dato" << std::endl
              << "\t 2) eiiminar por posición" << std::endl;
}

void modif_dato()
{
    int dato;
    cout << endl;
    listar();
    cout << endl;
    listar();
    cout << "Dato a modificar--->";
    cin >> dato;
    for (int i = 0; i < t; i++)
    {
        if (edades[i] == dato)
        {
            cout << "Nuevo dato-->";
            cin >> edades[i];
        }
    }
    cout << endl;
    listar();
    cout << endl;
}
void modif_posi()
{
    int dato;
    cout << endl;
    listar();
    cout << endl;
    cout << "Posición a modificar--->";
    cin >> dato;
    for (int i = 0; i < t; i++)
    {
        if (dato == i)
        {
            cout << "Nuevo dato-->";
            cin >> edades[i];
        }
    }
    cout << endl;
    listar();
    cout << endl;
}

void elim_pos()
{
    int pos;
    cout << endl;
    listar();
    cout << endl;
    cout << "Posicion a eliminar";
    cin >> pos;
    edades[pos - 1] = 0;
    cout << endl;
    listar();
    cout << endl;
}

void elim_dato()
{
    int pos;
    cout << endl;
    listar();
    cout << endl;
    cout << "dato a eliminar";
    cin >> pos;
    for (int i = 0; i < t; i++)
    {
        if (edades[i] == pos)
        {
            edades[i] = 0;
        }
    }
    cout << endl;
    listar();
    cout << endl;
}

void ord_desc()
{
    cout << endl;
    listar();
    cout << endl;
    sort(edades, edades + t, greater<int>());
    cout << endl;
    listar();
    cout << endl;
}
void ord_asce()
{
    cout << endl;
    listar();
    cout << endl;
    sort(std::begin(edades), std::begin(edades)+t);
    cout << endl;
    listar();
    cout << endl;
}


void prom_may_men()
{
    int suma = 0, may = edades[0], men = edades[0];
    float promedio;
    for (int i = 0; i < t; i++)
    {
        suma = suma + edades[i];
        if (edades[i] > may)
            may = edades[i];
        if (edades[i] < men)
            men = edades[i];
    }
    promedio = suma / t;
    cout << "El promedio es-->" << promedio << endl;
    cout << "La menor edad es --->" << men << endl;
    cout << "La mayor edad es--->" << may << endl;
}

//funcion principsl
int main()
{
    int op = 0, op1 = 0;
    crear();
    do
    {
        menu_principal();
        cin >> op;
        // system("cls") comando para limpiar pantalla
        system("cls");
        switch (op)
        {
        case 1:
        {
            do
            {
                menu_insert();
                cin >> op1;
                system("cls");
                switch (op1)
                {
                case 1:
                {
                    posicion();
                    break;
                }
                case 2:
                {
                    aleatoria();
                    break;
                }
                case 3:
                    break;
                default:
                {
                    cout << "Codigo no valido" << endl;
                }
                }

            } while (op1 != 3);
            break;
        }
        case 2:
        {
            listar();
            break;
        }
        case 3:
        {
            modifLista();
            std::cin >> op1;
            switch (op1)
            {
            case 1:
            {

                modif_dato();
                break;
            }
            case 2:
            {
                modif_posi();
                break;
            }
            default:
                break;
            }

            break;
        }
        case 4:
        {
            elim_lista();
            std::cin >> op1;
            switch (op1)
            {
            case 1:
            {

                elim_dato();
                break;
            }
            case 2:
            {
                elim_pos();

                break;
            }
            default:
                break;
            }
            break;
        }
        case 5:
        {
            ordenarLista();
            std::cin >> op1;
            switch(op1)
            {
                case 1:
                {
                    ord_asce();
                    break;
                }
                case 2:
                {
                    ord_desc();
                    break;
                }
                default:
                break;
            }
            break;
        }
        case 6:
        {
            prom_may_men();
            break;
        }
        case 7:
            break;
        default:
            cout << "Opcion no vslida" << endl;
        }
    } while (op != 7);
    return 0;
}