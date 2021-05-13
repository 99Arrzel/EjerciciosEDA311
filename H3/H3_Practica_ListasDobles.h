#include <iostream>

struct nodilloSimple
{
    int dato;
    nodilloSimple *siguiente;
} * cab, *fin;

void insertarEnteroSimple(int a)
{
    struct nodilloSimple *nuevo = (struct nodilloSimple *)malloc(sizeof(struct nodilloSimple)); //ALloc memory
    if (nuevo == NULL)
    {
        std::cout << "No hay espacio en Memoria" << std::endl;
    }
    else
    {
        nuevo->dato = a;
        nuevo->siguiente = NULL;
        if (cab == NULL)
        {
            cab = nuevo;
            return;
        }
        fin = cab;                     //Pones el fin en la cabecera
        while (fin->siguiente != NULL) //Recorres el fin hasta que el siguiente sea nulo
        {
            fin = fin->siguiente;
        }
        fin->siguiente = nuevo;
    }
}

class Nodo
{
    struct nodillo
    {
        int entero1;
        nodillo *siguiente, *anterior;
    } * cab, *fin, *p, *p2;

public:
    void setCab(nodillo *entrada) { entrada = cab; }
    void insertarEntero(int a)
    {
        struct nodillo *nuevo = (struct nodillo *)malloc(sizeof(struct nodillo)); //ALloc memory
        if (nuevo == NULL)
        {
            std::cout << "No hay espacio en Memoria" << std::endl;
        }
        else
        {
            nuevo->entero1 = a;
            nuevo->siguiente = NULL;
            if (cab == NULL)
            {
                nuevo->anterior = NULL;
                cab = nuevo;
                return;
            }
            fin = cab;                     //Pones el fin en la cabecera
            while (fin->siguiente != NULL) //Recorres el fin hasta que el siguiente sea nulo
            {
                fin = fin->siguiente;
            }
            fin->siguiente = nuevo;
            nuevo->anterior = fin;

            /*Esto es para poner al final
            nuevo->entero1 = a;
            //Cabecera = siguiente
            nuevo->siguiente = cab;
            //El anterior es null, pues no hay antes de este (es un push)
            nuevo->anterior = NULL;

            if (cab != NULL)
            {
                cab->anterior = nuevo;
            }
            cab = nuevo;*/
        }
    }
    void ordenarListaEntero()
    {
        int guardar1 = 0;
        nodillo *siguiente;
        p = cab;
        while (p != NULL)
        {
            siguiente = p->siguiente; //Adelantamos 1
            while (siguiente != NULL)
            {
                if (p->entero1 > siguiente->entero1) //Comparamos edad
                {
                    guardar1 = siguiente->entero1;   //Guardamos siguiente edad
                    siguiente->entero1 = p->entero1; //Asignamos al siguiente la edad del actual
                    p->entero1 = guardar1;           //Asignamos la edad guardada del siguiente a la edad actual
                }
                siguiente = siguiente->siguiente; //Recorremos siguiente
            }
            p = p->siguiente; //recorremos p
        }
    }
    void listarEnteros()
    {
        p = cab;
        while (p != NULL)
        {
            std::cout << p->entero1 << "  ";
            p = p->siguiente;
        }
    }
    void listarInvertido() //Por qué invertirlo? si es lo mismo al reves una lista doble, que fuese una simple...
    {
        p = fin->siguiente;
        while (p != NULL)
        {
            std::cout << p->entero1 << "    ";
            p = p->anterior;
        }
    }
    void eliminarRepetidos()
    {
        int guardar1 = 0;
        nodillo *siguiente;
        p = cab;
        while (p != NULL)
        {
            siguiente = p->siguiente; //Adelantamos 1
            while (siguiente != NULL)
            {
                if (p->entero1 == siguiente->entero1) //Comparamos edad
                {
                    p->siguiente = siguiente->siguiente;
                }
                siguiente = siguiente->siguiente; //Recorremos siguiente
            }
            p = p->siguiente; //recorremos p
        }
    }
    void simpleAdoble(nodilloSimple *cab)
    {
        nodilloSimple *rep;
        rep = cab;
        while (rep != NULL)
        {
            insertarEntero(rep->dato);
            rep = rep->siguiente;
        }
    }
};
