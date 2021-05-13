#include <iostream>

using namespace std;

struct curso_3
{
    struct curso_3 *ant;
    int ci;
    string nombre;
    float estatura;
    struct curso_3 *sig;
};
struct curso_3 *cab, *fin, *p, *aux1;

void inic_punt()
{
    cab = NULL;
    fin = NULL;
}
void menu_principal()
{
    cout << "\t\t\tMENU LISTAS DOBLE" << endl;
    cout << "\t1.Insertar" << endl;
    cout << "\t2.Listar RECORRIDO ADELANTE" << endl;
    cout << "\t3.Listar RECORRIDO ATRAS" << endl;
    cout << "\t4.Eliminar" << endl;
    cout << "\t5.Salir" << endl;
    cout << "Elija opcion---->";
}
void menu_insertar()
{
    cout << "\t\t\tMENU INSERTAR" << endl;
    cout << "\t1.Insertar_Inicio" << endl;
    cout << "\t2.Insertar_final" << endl;
    cout << "\t3.Insertar_Posicion" << endl;
    cout << "\t4.Retornar" << endl;
    cout << "Elija opcion---->";
}
void menu_elimiar()
{
    cout << "\t\t\tMENU ELIMIAR" << endl;
    cout << "\t1.Eliminar_Inicio" << endl;
    cout << "\t2.Eliminar_final" << endl;
    cout << "\t3.Eliminar_Posicion" << endl;
    cout << "\t4.Retornar" << endl;
    cout << "Elija opcion---->";
}
void list_datos_adelante()
{
    p = cab;
    while (p != NULL)
    {
        cout << p->ci << '\t' << p->nombre << endl;
        p = p->sig;
    }
}

void list_datos_atras()
{
    p = fin;
    while (p != NULL)
    {
        cout << p->ci << '\t' << p->nombre << endl;
        p = p->ant;
    }
}

void insert_inicio()
{
    int auxci;
    string auxnom;
    float auxest;
    struct curso_3 *nuevo;
    nuevo = new struct curso_3;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    cout << "Carnet-->";
    cin >> auxci;
    cout << "Nombre-->";
    cin >> auxnom;
    cout << "Estatura-->";
    cin >> auxest;
    if (nuevo == NULL)
        cout << "No hay espacio en Memoria" << endl;
    else
    {
        if (cab == NULL && fin == NULL)
        {
            nuevo->ci = auxci;
            nuevo->nombre = auxnom;
            nuevo->estatura = auxest;
            nuevo->sig = NULL;
            nuevo->ant = NULL;
            cab = nuevo;
            fin = nuevo;
            cout << "Nodo registrado" << endl;
        }
        else
        {
            nuevo->ci = auxci;
            nuevo->nombre = auxnom;
            nuevo->estatura = auxest;
            nuevo->sig = cab;
            cab->ant = nuevo;
            cab = nuevo;
            cout << "Nodo registrado" << endl;
        }
    }
    cout << endl;
    list_datos_atras();
}

void insert_final()
{
    int auxci;
    string auxnom;
    float auxest;
    struct curso_3 *nuevo;
    nuevo = new struct curso_3;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    cout << "Carnet-->";
    cin >> auxci;
    cout << "Nombre-->";
    cin >> auxnom;
    cout << "Estatura-->";
    cin >> auxest;
    if (nuevo == NULL)
        cout << "No hay espacio en Memoria" << endl;
    else
    {
        if (cab == NULL && fin == NULL)
        {
            nuevo->ci = auxci;
            nuevo->nombre = auxnom;
            nuevo->estatura = auxest;
            nuevo->sig = NULL;
            nuevo->ant = NULL;
            cab = nuevo;
            fin = nuevo;
            cout << "Nodo registrado" << endl;
        }
        else
        {
            nuevo->ci = auxci;
            nuevo->nombre = auxnom;
            nuevo->estatura = auxest;
            fin->sig = nuevo;
            nuevo->ant = fin;
            fin = nuevo;
            cout << "Nodo registrado" << endl;
        }
    }

    cout << endl;
    list_datos_atras();
}

//insertar entre posiciones
void insert_pos()
{

    bool control = false;
    int auxci, dato;
    string auxnom;
    float auxest;
    struct curso_3 *nuevo;
    nuevo = new struct curso_3;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    cout << "Carnet-->";
    cin >> auxci;
    cout << "Nombre-->";
    cin >> auxnom;
    cout << "Estatura-->";
    cin >> auxest;
    cout << "Ingrese el numero de ci donde insertara-->";
    cin >> dato;
    if (nuevo == NULL)
        cout << "No hay espacio en Memoria" << endl;
    else
    {
        p = cab;
        while (p != NULL)
        {
            if (p->ci == dato)
            {
                nuevo->ci = auxci;
                nuevo->nombre = auxnom;
                nuevo->estatura = auxest;
                aux1 = p->sig;
                nuevo->sig = aux1;
                aux1->ant = nuevo;
                p->sig = nuevo;
                nuevo->ant = p;
                cout << "Nodo registrado en una posicion" << endl;
                control = true;
            }
            p = p->sig;
        }
        if (!control)
            cout << "Dato no se encontro en la lista" << endl;
        else
        {
            cout << endl;
            list_datos_atras();
        }
    }
}

void eliminar_inicio()
{
    p = cab;
    cab = p->sig;
    cab->ant = NULL;
    delete (p);
}

void eliminar_final()
{
    p = fin;
    p = p->ant;
    p->sig = NULL;
    delete (fin);
    fin = p;
}

void eliminar_pos()
{
    int pos = 0;
    std::cout << "Ingrese posición a eliminar\n";
    std::cin >> pos;
    p = cab;
    for (int i = 0; i < pos; i++) //Solo para mover el puntero
    {
        if (p == NULL || p->sig == NULL)
        {
            std::cout << "La lista es más pequeña que la posición que indicaste.\n";
            break;
        }
        p = p->sig;
        if (i == pos - 1)
        {
            auto holdBack = p->ant;
            auto holdForward = p->sig;
            p = p->ant;
            p->sig = holdForward;
            holdForward->ant = p;
        }
    }
}
void menuBorrar()
{

    int opt = 0;
    do
    {
        std::cout << "0)SALIR\n";
        std::cout << "1)Borrar Inicio\n";
        std::cout << "2)Borrar Final\n";
        std::cout << "3)Borrar posición\n";
        std::cin >> opt;

        switch (opt)
        {
        case 1:
        {
            eliminar_inicio();
            std::cout << "Listo\n";
            break;
        }
        case 2:
        {
            eliminar_final();
            std::cout << "Final fue\n";
            break;
        }
        case 3:
        {
            eliminar_pos();
            break;
        }
        default:
            break;
        }
    } while (opt != 0);
}

int main()
{
    int op = 0, op1 = 0, op2 = 0;
    inic_punt();
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
                menu_insertar();
                cin >> op1;
                system("cls");
                switch (op1)
                {
                case 1:
                {
                    insert_inicio();
                    break;
                }
                case 2:
                {
                    insert_final();
                    break;
                }
                case 3:
                {
                    insert_pos();
                    break;
                }
                case 4:
                {
                    break;
                }

                default:
                {
                    cout << "Opcion no valida" << endl;
                }
                }
            } while (op1 != 4);

            break;
        }
        case 2:
        {
            list_datos_adelante();
            break;
        }
        case 3:
        {
            list_datos_atras();
            break;
        }
        case 4:
        {
            menuBorrar();
            break;
        }
        case 5:
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (op != 5);

    // elim_inicio();

    return 0;
}
