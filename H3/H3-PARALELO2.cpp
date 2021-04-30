#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;

struct nodo
{
    string nombre;
    int edad;
    struct nodo *sig;
};

struct nodo *cab, *fin, *p, *l, *aux;

void inic_lista()
{
    cab = NULL;
    fin = NULL;
}

void menu_principal()
{
    //endl comsndo salti de linea
    //cout<< comando salida de datos por pantalla
    cout << "\t\t\tMENU LISTAS SIMPLES" << endl;
    cout << "\t1.Insertar" << endl;
    cout << "\t2.Listar" << endl;
    cout << "\t3.Eliminar" << endl;
    cout << "\t4.Buscar" << endl;
    cout << "\t5.Modificar por nombre" << endl;
    cout << "\t6.Ordenar por edad" << endl;
    cout << "\t7.Salir" << endl;
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

void menu_eliminar()
{
    cout << "\t\t\tMENU INSERTAR" << endl;
    cout << "\t1.Elimiar_Inicio" << endl;
    cout << "\t2.Eliminar_final" << endl;
    cout << "\t3.Eliminar_Posicion" << endl;
    cout << "\t4.Retornar" << endl;
    cout << "Elija opcion---->";
}

void menu_buscar()
{
    cout << "\t\t\tMENU BUSCAR DATO" << endl;
    cout << "\t1.Buscar nombre" << endl;
    cout << "\t2.Buscar edad" << endl;
    cout << "\t3.Salir\n";

    cout << "Elija opcion---->";
}

//Insertando al inicio
void insert_inicio()
{
    string auxNom;
    int auxEdad;
    struct nodo *nuevo;
    nuevo = new struct nodo;
    nuevo->sig = NULL;
    cout << "Nombre-->";
    cin >> auxNom;
    cout << "Edad-->";
    cin >> auxEdad;
    if (nuevo == NULL)
    {
        cout << "No hay espacio en al MEMORIA" << endl;
    }
    else
    {
        if (cab == NULL && fin == NULL)
        {
            nuevo->nombre = auxNom;
            nuevo->edad = auxEdad;
            nuevo->sig = NULL;
            cab = nuevo;
            fin = nuevo;
            cout << "Primer Nodo insertado en lista" << endl;
        }
        else
        {
            nuevo->nombre = auxNom;
            nuevo->edad = auxEdad;
            nuevo->sig = NULL;
            nuevo->sig = cab;
            cab = nuevo;
            cout << "Nodo insertado al inicio lista" << endl;
        }
    }
}

void list_datos()
{
    p = cab;
    while (p != NULL)
    {
        cout << p->nombre << '\t' << p->edad << endl;
        p = p->sig;
    }
}

//insertando al final
void insert_fin()
{
    string auxNom;
    int auxEdad;
    struct nodo *nuevo;
    nuevo = new struct nodo;
    nuevo->sig = NULL;
    cout << "Nombre-->";
    cin >> auxNom;
    cout << "Edad--Z";
    cin >> auxEdad;
    if (nuevo == NULL)
    {
        cout << "No hay espacio en al MEMORIA" << endl;
    }
    else
    {
        if (cab == NULL && fin == NULL)
        {
            nuevo->nombre = auxNom;
            nuevo->edad = auxEdad;
            nuevo->sig = NULL;
            cab = nuevo;
            fin = nuevo;
            cout << "Primer Nodo insertado en lista" << endl;
        }
        else
        {
            nuevo->nombre = auxNom;
            nuevo->edad = auxEdad;
            nuevo->sig = NULL;
            fin->sig = nuevo;
            fin = nuevo;
            cout << "Nodo insertado al final lista" << endl;
        }
    }
}
void insert_pos()
{
    bool control = false;
    string auxNom, dato;
    int auxEdad;
    struct nodo *nuevo;
    nuevo = new struct nodo;
    nuevo->sig = NULL;
    cout << "Nombre-->";
    cin >> auxNom;
    cout << "Edad--Z";
    cin >> auxEdad;
    cout << "Ingrese nombre donde se insertara--";
    cin >> dato;
    if (nuevo == NULL)
    {
        cout << "No hay espacio en al MEMORIA" << endl;
    }
    else
    {
        p = cab;
        while (p != NULL)
        {
            if (p->nombre == dato)
            {
                nuevo->nombre = auxNom;
                nuevo->edad = auxEdad;
                nuevo->sig = NULL;
                nuevo->sig = p->sig;
                p->sig = nuevo;
                cout << "Nodo insertado entre posiciones de la lista" << endl;
                control = true;
            }
            p = p->sig;
        }
        if (!control)
            cout << dato << "No existe en la lista" << endl;
        else
            list_datos();
    }
}

//eliminar al inicio
void elimiar_inicio()
{
    p = cab;
    cout << cab->sig;
    system("cls");
    if (cab == NULL && fin == NULL)
    {
        p = cab;
        cab = p->sig;
        p->sig = NULL;
        delete p;
        cout << endl;
        list_datos();
    }
    else
    {
        cout << "LIsta Vacia" << endl;
    }
}

void eliminar_final()
{
    p = cab;
    aux = p;
    system("cls");
    while (p != NULL)
    {
        aux = p;
        p = p->sig;
        if (p->sig == NULL)
        {
            fin = aux;
            fin->sig = NULL;
            delete p;
            break;
        }
    }
}

void eliminar_pos()
{
    bool control = false;
    string nom1;
    cout << "Nombre del nodo a eliminar-->";
    cin >> nom1;
    p = cab;
    aux = p;
    system("cls");
    while (p != NULL)
    {
        if (p->nombre == nom1)
        {
            cout << "Dato encontrado" << endl;
            aux->sig = p->sig;
            p->sig = NULL;
            control = true;
            delete p;
            break;
        }
        aux = p;
        p = p->sig;
    }
    if (!control)
    {
        cout << "Dato no se encuentra en lista" << endl;
    }
    else
    {
        cout << endl;
        list_datos();
    }
}

void modificar_menu() //Probar
{

    nodo *cab = new nodo();
    cab = l;
    bool encontrado = false;
    string nodoBuscado;
    cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
    cin >> nodoBuscado;
    system("cls");
    if (l != NULL)
    {

        while (cab != NULL && encontrado != true)
        {

            if (cab->nombre == nodoBuscado)
            {
                cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado";
                cout << "\n Ingrese el Nuevo dato para este Nodo: ";
                cin >> cab->nombre;
                encontrado = true;
            }

            cab = cab->sig;
        }
        if (!encontrado)
        {
            cout << "\n Nodo No Encontrado\n\n";
        }
    }
    else
    {
        cout << "\n La Lista se Encuentra Vacia\n\n";
    }
}

void insertar_MenuSwitch()
{
    int op1;
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
            insert_fin();
            break;
        }
        case 3:
        {
            insert_pos();
            break;
        }
        case 4:
        {
            op1 = 4;
            break;
        }

        default:
        {
            cout << "Opcion no valida" << endl;
        }
        }
    } while (op1 != 4);
}
void eliminar_MenuSwitch()
{
    int op2;
    do
    {
        menu_eliminar();
        cin >> op2;
        system("cls");
        switch (op2)
        {
        case 1:
        {
            elimiar_inicio();
            break;
        }
        case 2:
        {
            eliminar_final();
            break;
        }
        case 3:
        {
            eliminar_pos();
            break;
        }
        case 4:
            break;

        default:
        {
            cout << "Opcion no valida" << endl;
        }
        }
    } while (op2 != 5);
}

//struct nodo *cab, *fin, *p, *l, *aux;
void buscar_Nombre()
{
    bool loEncontraste = false;
    string nombreABuscar;
    if (cab == NULL && fin == NULL)
    {
        cout << "Llene el nodo primero\n";
        getch();
        return;
    }
    list_datos();
    p = cab;
    cout << "¿Qué nombre desea buscar?\n";
    cin >> nombreABuscar;
    while (p != NULL)
    {
        if (p->nombre == nombreABuscar)
        {
            std::cout << "Edad: " << p->edad << " Nombre: " << p->nombre << "\n";
            loEncontraste = true;
            break;
        }
        p = p->sig;
    }

    if (loEncontraste)
    {
        std::cout << "Se encontró el nombre y se imprimió los datos\n";
    }
    else
    {
        std::cout << "No se halló ningún dato con ese nombre\n";
    }
    getch();
    system("cls");
}
void buscarEdad()
{
    bool loEncontraste = false;
    int edadABuscar;
    if (cab == NULL && fin == NULL)
    {
        cout << "Llene el nodo primero\n";
        getch();
        return;
    }
    list_datos();
    p = cab;
    cout << "¿Qué edad desea buscar?\n";
    cin >> edadABuscar;
    while (p != NULL)
    {
        if (p->edad == edadABuscar)
        {
            std::cout << "Edad: " << p->edad << " Nombre: " << p->nombre << "\n";
            loEncontraste = true;
        }
        p = p->sig;
    }

    if (loEncontraste)
    {
        std::cout << "Se encontró los sujetos con X edad y se imprimió los datos\n";
    }
    else
    {
        std::cout << "No se halló ninguna persona con esa edad.\n";
    }
    getch();
    system("cls");
}
void modificarDato()
{
    bool loEncontraste = false;
    string nombreABuscar;
    if (cab == NULL && fin == NULL)
    {
        cout << "Llene el nodo primero\n";
        getch();
        return;
    }
    list_datos();
    p = cab;
    cout << "¿Qué nombre desea buscar?\n";
    cin >> nombreABuscar;
    while (p != NULL)
    {
        if (p->nombre == nombreABuscar)
        {
            std::cout << "Edad: " << p->edad << " Nombre: " << p->nombre << "\n";
            loEncontraste = true;
            std::cout << "Introduzca el nombre para modificar.\n";
            std::cin >> nombreABuscar;
            p->nombre = nombreABuscar;
            break;
        }
        p = p->sig;
    }

    if (loEncontraste)
    {
        std::cout << "Se modifico los datos\n";
    }
    else
    {
        std::cout << "No se halló ninguna persona con ese nombre.\n";
    }
    list_datos();
    getch();
    system("cls");
}

void buscar_MenuSwitch()
{
    int opt = 0;
    do
    {
        menu_buscar();
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            buscar_Nombre();
            break;
        }
        case 2:
        {
            buscarEdad();
            break;
        }
        case 3:
        {
            opt = 3;
            break;
        }
        default:
            break;
        }
    } while (opt != 3);
}

bool comparadorEdad(int a, int b)
{
    if(a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void ordenarPorNombre()
{
    nodo *siguiente; //Siguiente nodo
    int nEdad = 0; //Edad actual
    string nNombre;
    p = cab;  //Puntero
    while(p != NULL)
    {
        siguiente = p->sig; //Adelantamos 1
        while(siguiente != NULL)
        {
            if(p->edad > siguiente->edad) //Comparamos edad
            {
                nEdad = siguiente->edad;//Guardamos siguiente edad
                nNombre = siguiente->nombre;
                siguiente->edad = p->edad; //Asignamos al siguiente la edad del actual
                siguiente->nombre = p->nombre;
                p->edad = nEdad; //Asignamos la edad guardada del siguiente a la edad actual
                p->nombre = nNombre;
            }
            siguiente = siguiente->sig; //Recorremos siguiente
        }
        p = p->sig; //recorremos p
    }
    cout << "Lo intenté XD\n";
}

int main()
{
    int op = 0, op1 = 0, op2 = 0;
    inic_lista();

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
            insertar_MenuSwitch();
            break;
        }
        case 2:
        {
            list_datos();
            break;
        }
        case 3:
        {
            eliminar_MenuSwitch();
            break;
        }
        case 4:
        {
            buscar_MenuSwitch();
            break;
        }
        case 5:
        {
            
            modificarDato();
        }
        case 6:
        {
            ordenarPorNombre();
        }
            
    
        default:
            cout << "Opcion no vslida" << endl;
        }
    } while (op != 7);
    return 0;
}