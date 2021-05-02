#include <iostream>
#include <conio.h>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <cstring> //size
///////////////////GLOBALES
int opt = 0;

class MisNodos //Una clase para no andar iniciando cada vez.
{
public:            //Todo publico jaja
    struct nodillo //Nombre del nodo
    {
        int entero1;
        std::string string1;
        float float1;
        struct nodillo *sig, *ant;
        char char1;
    };
    struct nodillo *cab, *fin, *p, *p2; //Declaración de cabecera, final y pointer
    nodillo *returnCab() { return cab; }
    void setCab(nodillo *a) { cab = a; }
    MisNodos();
    MisNodos(nodillo *a, nodillo *b); //Builder si le das 2 nodillos
    void insertarEntero(int a)        //1/23
    {
        struct nodillo *nuevo;
        nuevo = new struct nodillo; //Crear un nuevo nodo
        nuevo->sig = NULL;          //Siguiente es null
        if (nuevo == NULL)
        {
            std::cout << "No hay espacio en Memoria\n";
        }
        else
        {
            nuevo->entero1 = a;             //Entero para nuevo
            if (cab == NULL && fin == NULL) //Si la cabecera está vacia y el final está vacio
            {
                cab = nuevo; //Cabecero apunta a nuevo, que es el que acabas de crear
                fin = nuevo; //Fin apunta a nuevo
                std::cout << "Nodo registrado\n";
            }
            else
            {
                fin->sig = nuevo;
                fin = nuevo;
                std::cout << "Nodo registrado\n";
            }
        }
    }
    void insertarString(std::string a)
    {
        struct nodillo *nuevo;
        nuevo = new struct nodillo;
        nuevo->sig = NULL;
        if (nuevo == NULL)
        {
            std::cout << "Sin espacio en memoria\n";
        }
        else
        {
            std::string mensaje = "String registrado\n";
            nuevo->string1 = a;
            if (cab == NULL && fin == NULL)
            {
                cab = nuevo;
                fin = nuevo;
                std::cout << mensaje;
            }
            else
            {
                fin->sig = nuevo;
                fin = nuevo;
                std::cout << mensaje;
            }
        }
    }
    void listarNodoEnteros()
    {
        p = cab;
        while (p != NULL)
        {
            std::cout << p->entero1 << "  ";
            p = p->sig;
        }
    }
    void listarNodoFloats()
    {
        p = cab;
        while (p != NULL)
        {
            std::cout << p->float1 << "  ";
            p = p->sig;
        }
    }
    void contarNodos() //2/23
    {
        p = cab;
        int contador = 0;
        while (p != NULL)
        {
            contador++;
            p = p->sig;
        }

        std::cout << "Hay " << contador << " nodos en la lista\n";
    }
    void insertarFloat(float a) //parte del 3
    {
        struct nodillo *nuevo;
        nuevo = new struct nodillo; //Crear un nuevo nodo
        nuevo->sig = NULL;          //Siguiente es null
        if (nuevo == NULL)
        {
            std::cout << "No hay espacio en Memoria\n";
        }
        else
        {
            nuevo->float1 = a;              //Entero para nuevo
            if (cab == NULL && fin == NULL) //Si la cabecera está vacia y el final está vacio
            {
                cab = nuevo; //Cabecero apunta a nuevo, que es el que acabas de crear
                fin = nuevo; //Fin apunta a nuevo
                std::cout << "Nodo registrado\n";
            }
            else
            {
                fin->sig = nuevo;
                fin = nuevo;
                std::cout << "Nodo registrado\n";
            }
        }
    }
    void calcularCuadrados() //3/23
    {
        float sumatoria = 0;
        float sumatoriaAux = 0;
        p = cab; //Apuntando al primer nodo de la lista papá
        while (p != NULL)
        {
            sumatoriaAux = p->float1;
            sumatoria += pow(sumatoriaAux, 2);
            p = p->sig;
        }
        std::cout << sumatoria << '\n';
    }
    nodillo *buscarNumeroEntero(int a, nodillo *b) //Tiene que devolver un pointer
    {
        int contador = 1;
        bool loEncontraste = false;
        nodillo *returnPos;
        while (b != NULL)
        {
            if (b->entero1 == a)
            {
                std::cout << "Entero encontrado en la posición :" << contador << "\n";
                returnPos = b; //Igualamos el puntero a donde se encontró
                loEncontraste = true;
                break;
            }
            b = b->sig;
            contador++;
        }

        if (loEncontraste == false)
        {
            std::cout << "Número no encontrado\n";
            return returnPos; //Retornar el puntero
        }
        else
        {
            return NULL; //Retorna null si no lo encuentra
        }
    }
    void invertirLista(nodillo *a) //Primera condición, recibir un pointer AKA de nodo simple a doble
    {
        cab = a;            //Es imposible volcar un nodo con pasarlo una vez, lo que haré es una lista de doble enlace y ya.
        nodillo *siguiente; //Así será en una sola pasada el listado al revés
        nodillo *actual;
        nodillo *anterior = NULL;
        actual = cab;
        while (actual != NULL)
        {
            siguiente = actual->sig;
            actual->ant = anterior;
            anterior = actual;

            actual = siguiente;
            if (siguiente == NULL)
            {
                break;
            }
        }
        fin = anterior;
    }
    void listarReversaEntero()
    {
        p = fin;
        while (p != NULL)
        {

            std::cout << p->entero1 << "  ";
            p = p->ant;
        }
    }
    nodillo *eliminarNodosPares(nodillo *a)
    {
        int contador = 0;
        nodillo *aux_borrar;
        nodillo *anterior = NULL;
        cab = a;
        aux_borrar = a;
        int i = 0;
        while (aux_borrar->sig != NULL)
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->sig;
            if (i % 2 == 0)
            {
                anterior->sig = aux_borrar->sig;
            }
            i++;
        }
        return cab;
    }
    std::tuple<nodillo *, nodillo *> retornarParesEImpares(nodillo *a) //Retornar 2 nodos, uno de pares y otro de pares en relación a la entrada de otro nodo
    {
        nodillo *paresCab;
        nodillo *imparesCab;
        nodillo *auxPares = NULL;
        nodillo *auxImpares = NULL;
        nodillo *pasador = NULL;
        paresCab = new struct nodillo;   //Inicio
        imparesCab = new struct nodillo; //inicio
        pasador = new struct nodillo;
        auxPares = paresCab;     //Puntero
        auxImpares = imparesCab; //Puntero al inicio igual
        //
        p = a;
        while (p != NULL) //Listamos a
        {
            std::cout << p->entero1 << "  ";
            p = p->sig;
        }
        std::cout << "Resultados abajo: \n";
        //
        int i = 1;
        pasador = a;
        do
        {
            if (i % 2 == 0)
            {
                auxPares->sig = pasador;
                std::cout << auxPares->entero1 << "p\n";
                auxPares = auxPares->sig;
            }
            else
            {
                auxImpares->sig = pasador;
                std::cout << auxImpares->entero1 << "im\n";
                auxImpares = auxImpares->sig;
            }

            pasador = pasador->sig;
            if (pasador == NULL)
            {
                auxImpares->sig = NULL;
                auxPares->sig = NULL;
                break;
            }
            i++;
        } while (pasador != NULL);

        //Adelanto uno
        paresCab = paresCab->sig;
        imparesCab = imparesCab->sig;
        return std::make_tuple(paresCab, imparesCab);
    }
    void ordenarNodo()
    {
        int guardar1 = 0;
        nodillo *siguiente; //Siguiente nodo
        p = cab;            //Puntero
        while (p != NULL)
        {
            siguiente = p->sig; //Adelantamos 1
            while (siguiente != NULL)
            {
                if (p->entero1 > siguiente->entero1) //Comparamos edad
                {
                    guardar1 = siguiente->entero1;   //Guardamos siguiente edad
                    siguiente->entero1 = p->entero1; //Asignamos al siguiente la edad del actual
                    p->entero1 = guardar1;           //Asignamos la edad guardada del siguiente a la edad actual
                }
                siguiente = siguiente->sig; //Recorremos siguiente
            }
            p = p->sig; //recorremos p
        }
        std::cout << "FACILITO\n";
    }
    bool checkDecendente() //10
    {
        bool estaOrdenado = false;
        int guardar1 = 0;
        nodillo *siguiente; //Siguiente nodo
        p = cab;            //Puntero
        while (p != NULL)
        {
            siguiente = p->sig; //Adelantamos 1
            while (siguiente != NULL)
            {
                if (p->entero1 > siguiente->entero1) //Comparamos edad
                {
                    estaOrdenado = true;
                    guardar1 = siguiente->entero1; //Guardamos siguiente edad
                }
                else
                {
                    estaOrdenado = false;
                    break;
                }
                siguiente = siguiente->sig; //Recorremos siguiente
            }
            p = p->sig; //recorremos p
        }
        return estaOrdenado;
    }
    int sumaDeEnteros()
    {
        p = cab;
        int suma = 0;
        while (p != NULL)
        {
            suma += p->entero1;
            p = p->sig;
        }
        return suma;
    }
    int compararEntero(nodillo *a, nodillo *b) //12
    {

        bool esIgual = false;
        while (a != NULL)
        {
            if (a->entero1 == b->entero1)
            {
                esIgual = true;
            }
            else
            {
                esIgual = false;
                break;
            }
            if (b->sig == NULL & a->sig != NULL) //No son del mismo largo
            {
                esIgual = false;
                break;
            }
            a = a->sig;

            b = b->sig;
        }
        if (esIgual == true)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void listarPosicionEnNodoEnteros(int pos)
    {

        int contador = 0;
        p = cab;
        while (p != NULL)
        {
            if (contador == pos - 1)
            {
                std::cout << p->entero1 << "  ";
            }
            p = p->sig;
            contador++;
        }
        if (contador < pos)
        {
            std::cout << "Esa posición no existe, la lista es más pequeña\n";
        }
    }
    nodillo *buscarStrings(std::string a)
    {
        bool encontrado = false;
        p = cab;
        while (p != NULL)
        {
            if (p->string1 == a)
            {
                encontrado = true;
                break;
            }
            p = p->sig;
        }
        if (encontrado)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
    int contarNumeroEnLista(int a)
    {
        int contador = 0;
        p = cab;
        while (p != NULL)
        {
            if (p->entero1 == a)
            {
                contador++;
            }
            p = p->sig;
        }
        return contador;
    }
    void encontrarInterseccion(nodillo *a, nodillo *b)
    {
        std::cout << "\nElementos de intersección\n";
        bool encontrado = false;
        auto bb = b;
        while (a != NULL)
        {
            bb = b;
            while (bb != NULL)
            {
                if (a->entero1 == bb->entero1)
                {
                    std::cout << a->entero1 << " ";
                    encontrado = true;
                }
                bb = bb->sig;
            }
            a = a->sig;
        }
        if (encontrado)
        {
            std::cout << "\nLa lista tiene elementos de interseccion.\n";
        }
        else
        {
            std::cout << "\nLa lista no tiene elementos de intersección.\n";
        }
    }
    nodillo *listaPromedioMayor(nodillo *a)
    {
        //Recorremos una vez para ver el promedio
        int sumador = 0, contador = 0;
        p = a;
        while (p != NULL)
        {
            sumador += p->entero1;
            contador++;
            p = p->sig;
        }
        int promedio = sumador / contador;
        nodillo *nuevo;
        nodillo *auxNuevo = NULL;
        nuevo = new struct nodillo; //Crear un nuevo nodo
        auxNuevo = nuevo;
        p = a; //Retornamos p a 'a';
        while (p != NULL)
        {
            if (p->entero1 > promedio)
            {
                auxNuevo->sig = p;

                auxNuevo = auxNuevo->sig;
            }

            p = p->sig;
            if (p == NULL)
            {
                auxNuevo->sig = NULL;
                break;
            }
        }
        nuevo = nuevo->sig;
        if (contador == 0)
        {
            std::cout << "0 valores, no se puede promediar\n";
            return NULL;
        }
        else
        {
            return nuevo;
        }
    }
    void almacenarStrings(std::string a, std::string b)
    {
        std::string c = a + b;
        ///AE
        for (int i = 0; i < c.size(); i++)
        {
            struct nodillo *nuevo;
            nuevo = new struct nodillo; //Crear un nuevo nodo
            nuevo->sig = NULL;          //Siguiente es null
            if (nuevo == NULL)
            {
                std::cout << "No hay espacio en Memoria\n";
            }
            else
            {
                nuevo->char1 = c[i];             //string para nuevo
                if (cab == NULL && fin == NULL) //Si la cabecera está vacia y el final está vacio
                {
                    cab = nuevo; //Cabecero apunta a nuevo, que es el que acabas de crear
                    fin = nuevo; //Fin apunta a nuevo
                }
                else
                {
                    fin->sig = nuevo;
                    fin = nuevo;
                }
            }
        }
    }
    void coutCharSeparadoGuion()
    {
        p = cab;
        while (p != NULL)
        {
            std::cout << p->char1;
            p = p->sig;
            if (p!=NULL)
            {
                std::cout << "-";
            }
        }
    }
    

};

MisNodos::MisNodos()
{
    cab = NULL;
    fin = NULL; //Primero que nada iniciamos en null la cabecera y el final, constructor default
}
MisNodos::MisNodos(nodillo *a, nodillo *b) //Ambas cabeceras debo tener.
{
    cab = a;
    p = a;            //Iniciamos en cabecera de a
    while (p != NULL) //Debería llegar hasta el final
    {
        p = p->sig;
        if (p->sig == NULL) //Si el siguiente es null, no asignar
        {
            break;
        }
    }
    p->sig = b; //Asignamos p->sig al inicio de b
    while (p != NULL)
    {
        p = p->sig;
    }
    fin = p;
}
void menuPrincipal()
{
    std::cout << "1 Y 2)Insertar nodos en una lista hasta que se presione 0 y contar los nodos en esta lista.\n"; //Cuenta como 1 y como 2
    std::cout << "3)Sumar los cuadrados de una lista de floats.\n";
    std::cout << "4)Buscar un entero en un nodo y retornar un pointer con la posición del número\n";
    std::cout << "5)Algoritmo que recibe 2 pointer y concatena 2 listas, ejemplo con enteros.\n";
    std::cout << "6)Algoritmo que recibe un pointer e invierte una lista recorriendola UNA VEZ\n";
    std::cout << "7)Algoritmo que recibe un pointer y devuelve 2, uno con nodos pares y otro con nodos impares.\n";
    std::cout << "8)Algoritmo que recibe 2 listas de números enteros y las concatena de forma ordenada\n";
    std::cout << "9) Es lo mismo que la 2 y la 2 está en la 1.\n";
    std::cout << "10)Verificar si la lista está ordenada de manera descendente.\n";
    std::cout << "11)Sumar los nodos de una lista de enteros.\n";
    std::cout << "12)Comparar 2 listas y retornar 1 si son iguales y 0 si no lo son\n";
    std::cout << "13)Seleccionar el n valor de una lista\n";
    std::cout << "14)Buscar x elemento en una lista(Usaré strings)\n";
    std::cout << "15)Contar el número de veces que hay un entero en una lista\n";
    std::cout << "16)Mostrar intersecciones de 2 listas de enteros.\n";
    std::cout << "17)Es lo mismo que la 5 ZzZzZz\n";
    std::cout << "18)Dada una lista devolver otra con valores mayores al promedio(No dice que tipo de datos, así que enteros)\n";
    std::cout << "19)Juntar 2 strings letra por letra en una lista de chars y mostrarla separada con -\n";
    std::cout << "20)Insertar un dato en una lista enlazada de manera que esté ordenado\n";
    std::cout << "21)Insertar un dato al final si no es un dato repetido de la lista.\n";
}
