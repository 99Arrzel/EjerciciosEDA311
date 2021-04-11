#include <iostream>
#include <bits/stdc++.h>
#define tam 50
using namespace std;

struct fecha
{
    int dia;
    int mes;
    int anio;
};
struct persona
{
    int ci;
    string nombre;
    float estatura;
    struct fecha fecNac;
};

struct persona curso3[tam];
int t, anAc;
struct persona auxcur;
void carga_dato()
{
    cout << "cantidad de alumnos";
    cin >> t;
    cout << "Anio Actual";
    cin >> anAc;
    for (int i = 0; i < t; i++)
    {
        cout << "carnet";
        cin >> curso3[i].ci;
        cout << "nombre";
        cin >> curso3[i].nombre;
        cout << "estatura";
        cin >> curso3[i].estatura;
        cout << "fecha nacimiento";
        cin >> curso3[i].fecNac.dia >> curso3[i].fecNac.mes >> curso3[i].fecNac.anio;
    }
}

void listar_datos()
{
    cout << "\tLISTADO CURSO TERCERO" << endl;
    cout << "_______________________________________________________" << endl;
    cout << "CARNET\tNOMBRE\tESTATURA FECHA_NAC   EDAD" << endl;
    cout << "_______________________________________________________" << endl;
    for (int i = 0; i < t; i++)
    {
        cout << curso3[i].ci << '\t' << curso3[i].nombre << '\t' << curso3[i].estatura << '\t' << curso3[i].fecNac.dia << "/" << curso3[i].fecNac.mes << "/" << curso3[i].fecNac.anio << '\t' << anAc - curso3[i].fecNac.anio << endl;
    }
}

void listado_ord_nombre()
{

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t - 1; j++)
        {
            if (curso3[j].nombre > curso3[j + 1].nombre)
            {
                auxcur = curso3[j];
                curso3[j] = curso3[j + 1];
                curso3[j + 1] = auxcur;
            }
        }
    }
    cout << endl;
    listar_datos();
}

void busqueda_datos()
{
    int auxci = 0;
    bool control = false;
    cout << "CI a buscar" << endl;
    cin >> auxci;
    for (int i = 0; i < t; i++)
    {
        if (curso3[i].ci == auxci)
        {
            cout << "Dato Encontrado" << endl;
            cout << curso3[i].ci << '\t' << curso3[i].nombre << '\t' << curso3[i].estatura << '\t' << curso3[i].fecNac.dia << "/" << curso3[i].fecNac.mes << "/" << curso3[i].fecNac.anio << '\t' << anAc - curso3[i].fecNac.anio << endl;
            control = true;
        }
    }
    if (!control)
    {
        cout << "El numero de CI no se encuentra en la base de datos" << endl;
    }
}

void modificar_dato()
{
    int dato;
    cout << endl;
    listar_datos();
    cout << endl;
    cout << "dato de CI a modificar";
    cin >> dato;
    for (int i = 0; i < t; i++)
    {
        if (curso3[i].ci == dato)
        {
            cout << "Inserte nuevo dato";
            cin >> curso3[i].ci;
        }
        else
        {
            cout << "no se encontro el dato en la estructura" << endl;
        }
    }

    cout << endl;
    listar_datos();
    cout << endl;
}
void eliminar_dato()
{
    int elim;
    cout << endl;
    listar_datos();
    cout << endl;
    cout << "dato de CI a eliminar";
    cin >> elim;
    for (int i = 0; i < t; i++)
    {
        if (curso3[i].ci == elim)
        {
            curso3[i].ci = 0;
            cout << "Dato eliminado correctamente";
        }
        else
        {
            cout << "no se encontro el dato en la estructura" << endl;
        }
    }

    cout << endl;
    listar_datos();
    cout << endl;
}
void listado_edad()
{
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t - 1; j++)
        {
            if ((anAc - curso3[j].fecNac.anio) > (anAc - curso3[j + 1].fecNac.anio))
            {
                auxcur = curso3[j];
                curso3[j] = curso3[j + 1];
                curso3[j + 1] = auxcur;
            }
        }
    }
    cout << endl;
    listar_datos();
    cout << "El estudiante con menor edad es: " << curso3[0].nombre << " con " << anAc - curso3[0].fecNac.anio << " anios " << endl;
    cout << "El estudiante con mayor
        edad es : " <<curso3[t-1].nombre<<" con "<<anAc-curso3[t-1].fecNac.anio<<" anios "<<endl;
}

void menu_principal()
{
    cout << "\t\t\tMENU STRUCT" << endl;
    cout << "\t1.Cargar" << endl;
    cout << "\t2.Listar" << endl;
    cout << "\t3.Listado ordenado por nombre" << endl;
    cout << "\t4.Buscar" << endl;
    cout << "\t5.Modificar" << endl;
    cout << "\t6.Eliminar" << endl;
    cout << "\t7.Listado ordenado por edad" << endl;
    cout << "\t8.Salir" << endl;
    cout << "Elija opcion---->";
}

int main()
{
    int op = 0;

    do
    {
        menu_principal();
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
            listar_datos();
            break;
        }
        case 3:
        {
            listado_ord_nombre();
            break;
        }
        case 4:
        {
            busqueda_datos();
            break;
        }
        case 5:
        {
            modificar_dato();
            break;
        }
        case 6:
        {
            eliminar_dato();
            break;
        }
        case 7:
        {
            listado_edad();
            break;
        }
        case 8:
        {
            break;
        }
        default:
        {
            cout << "invalido" << endl;
            break;
        }
        }
    } while (op != 8);
    return 0;
}
