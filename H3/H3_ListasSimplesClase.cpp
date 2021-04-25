#include <iostream>
#include <conio.h>

using namespace std;

struct curso_3 //Nombre del nodo
{
    int ci;
    string nombre;
    float estatura;
    struct curso_3 *sig;
};
struct curso_3 *cab, *fin, *p; //Cab es principio(cabecera) y fin es fin jaja

void inic_punt()
{
    cab = NULL;
    fin = NULL;
}
void menu_principal()
{
    cout << "\t\t\tMENU LISTAS SIMPLES" << endl;
    cout << "\t1.Insertar" << endl;
    cout << "\t2.Listar" << endl;
    cout << "\t3.Eliminar" << endl; //Falta esto
    cout << "\t4.Salir" << endl;
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

void insert_inicio()
{
    int auxci;
    string auxnom;
    float auxest;
    struct curso_3 *nuevo;
    nuevo = new struct curso_3; //Crear un nuevo nodo
    nuevo->sig = NULL;          //Siguiente es null
    cout << "Carnet-->";
    cin >> auxci;
    cout << "Nombre-->";
    cin >> auxnom;
    cout << "Estatura-->";
    cin >> auxest;
    if (nuevo == NULL) //Check espacio en memoria
        cout << "No hay espacio en Memoria" << endl;
    else
    {
        if (cab == NULL && fin == NULL) //Si la cabecera está vacia y el final está vacio
        {
            nuevo->ci = auxci; //Asignando datos
            nuevo->nombre = auxnom;
            nuevo->estatura = auxest;
            nuevo->sig = NULL; //Siguiente es null
            cab = nuevo;       //Cabecero apunta a nuevo, que es el que acabas de crear
            fin = nuevo;       //Fin apunta a nuevo
            cout << "Nodo registrado" << endl;
        }
        else
        {
            nuevo->ci = auxci;
            nuevo->nombre = auxnom;
            nuevo->estatura = auxest;
            nuevo->sig = cab; //Siguiente es cabecera, o sea, lo inserta de primero
            cab = nuevo;      //Cabecera nuevo, ya no fin también
            cout << "Nodo registrado al inicio" << endl;
        }
    }
}
void list_datos()
{
    p = cab;
    while (p != NULL)
    {
        cout << p->ci << '\t' << p->nombre << '\t' << p->estatura << endl;
        p = p->sig;
    }
}

void insert_final()
{
    int auxci;
    string auxnom;
    float auxest;
    struct curso_3 *nuevo;
    nuevo = new struct curso_3;
    nuevo->sig = NULL;
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
            fin = nuevo;
            cout << "Nodo registrado" << endl;
        }
    }
}

void elim_inicio() //Eliminar al inicio
{
    p = cab;
    cab = p->sig;
    p->sig = NULL;
    delete p;
}
void elim_final()//Funca
{
    if (cab == NULL || fin == NULL)
    {
        std::cout << "Debes insertar para borrar\n";
        std::cout << "Error cabecera == NULL, OR fin == NULL\n";
        return;
    }
    curso_3 *aux_borrar;
    curso_3 *anterior = NULL;
    aux_borrar = cab; //A la cabecera
    while (aux_borrar != fin) //Llevamos al final
    {
        anterior = aux_borrar;
        aux_borrar = aux_borrar->sig;
    }
    fin = anterior;
    anterior->sig = NULL;
}
void elim_entrePosicion()
{
    if (cab == NULL || fin == NULL)
    {
        std::cout << "Debes insertar para borrar\n";
        std::cout << "Error cabecera == NULL, OR fin == NULL\n";
        return;
    }
    int posAEliminar = 0;
    std::cout << "Ingrese la posición a eliminar\n";
    std::cin >>posAEliminar;
    curso_3 *aux_borrar;
    curso_3 *anterior = NULL;
    aux_borrar = cab; //A la cabecera
    int i = 0;
    while (i < posAEliminar && aux_borrar->sig != NULL)
    {
        anterior = aux_borrar;
        aux_borrar=aux_borrar->sig;
        i++;
    }
    if(aux_borrar->sig != NULL)
    {
        anterior->sig = aux_borrar->sig;
    }
    else
    {
        anterior->sig = NULL;
    }
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
                nuevo->sig = NULL;
                nuevo->sig = p->sig;
                p->sig = nuevo;
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
            list_datos();
        }
    }
}

int main()
{
    int op = 0, op1 = 0, opt = 0;
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
            list_datos();
            break;
        }
        case 3:
            do
            {
                std::cout << "0)salir\n";
                std::cout << "1)Eliminar Inicio\n";
                std::cout << "2)Eliminar Final\n";
                std::cout << "3)Eliminar entre posiciones\n";
                std::cin >> opt;
                switch (opt)
                {
                case 1:
                {
                    elim_inicio();
                    std::cout << "Eliminado Principio\n";
                    list_datos();
                    getch();
                    break;
                }
                case 2:
                {
                    std::cout << "Eliminado Final\n";
                    list_datos();
                    getch();
                    elim_final();
                    list_datos();
                    getch();
                    break;
                }
                case 3:
                {
                    std::cout << "Eliminado posicion\n";
                    list_datos();
                    getch();
                    elim_entrePosicion();
                    list_datos();
                    getch();
                    break;
                }
                default:
                    break;
                }
            } while (opt != 0);
        default:
            cout << "Opcion no vslida" << endl;
        }
    } while (op != 4);

    // elim_inicio();

    return 0;
}