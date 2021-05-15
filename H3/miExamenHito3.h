#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

/// variables globales

///
bool esPalindromo(std::string palabra)
{
    std::string a, b;
    bool seraPalindromo = false;
    std::string frase = palabra;
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
                seraPalindromo = false;
                break;
            }
            if (a[j] == b[j])
            {
                seraPalindromo = true;
            }
        }
    }
    return seraPalindromo;
}

class Palindromos
{
public:
    struct misPalindromos
    {
        std::string palabra;
        struct misPalindromos *sig, *ant;
    };
    struct misPalindromos *cab, *fin, *p;
    Palindromos();
    void insetarPalindromo(std::string a)
    {
        struct misPalindromos *nuevo;
        nuevo = new struct misPalindromos;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        if (nuevo == NULL)
            std::cout << "No hay espacio en Memoria" << std::endl;
        else
        {
            nuevo->palabra = a;
            if (cab == NULL && fin == NULL)
            {
                nuevo->sig = NULL;
                nuevo->ant = NULL;
                cab = nuevo;
                fin = nuevo;
            }
            else
            {
                nuevo->sig = cab;
                cab->ant = nuevo;
                cab = nuevo;
            }
        }
    }
    void listarNodo()
    {
        if (cab != NULL)
        {
            p = cab;
        }
        else
        {
            std::cout << "No hay datos en el nodo\n";
            return;
        }
        while (p != NULL)
        {
            std::cout << p->palabra << std::endl;
            p = p->sig;
        }
    }
};
Palindromos::Palindromos()
{
    cab == NULL;
    fin == NULL;
}

///////////////222222222222222222222222222222222222222222

class MisNodos //Una clase para no andar iniciando cada vez.
{
public:            //Todo publico jaja
    struct nodillo //Nombre del nodo
    {
        double double1;
        int entero1;
        struct nodillo *sig;
    };
    struct nodillo *cab, *fin, *p, *p2; //Declaración de cabecera, final y pointer

    void insertarDato(double a)
    {
        struct nodillo *nuevo;
        nuevo = new struct nodillo;
        nuevo->sig = NULL;
        if (nuevo == NULL)
        {
            std::cout << "No hay espacio en Memoria" << std::endl;
        }

        else
        {
            nuevo->double1 = a;
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
    void listarDobles()
    {
        p = cab;
        while (p != NULL)
        {
            std::cout << p->double1 << " ";
            p = p->sig;
        }
    }
    void listarEnteros()
    {
        p = cab;
        while (p != NULL)
        {
            //std::cout << p->entero1 << " ";
            p = p->sig;
        }
    }
    void listarDecimales()
    {
        p = cab;
        double decimales;
        while (p != NULL)
        {
            //decimales = p->double1 - p->entero1;
            std::cout << decimales << " ";
            p = p->sig;
        }
    }
};
struct seleccion //ejercicio 3
{
    std::string pais;
    std::string nombreEntrenador;
    std::string jugador;
    std::string resultados;
};

class EmpresaXEmpleados //Ejercicio 4
{
    std::string nombre;
    std::string apellido;
    int nHijos;
    double salario;
    std::string estadoCivil;
    int tiempoServicio;

public:
    EmpresaXEmpleados(); //Default constructor
    int porcentajeDePago()
    {
        return (salario * 12) * 0.03;
    }
    int sueldoAnual()
    {
        return (salario * 12);
    }
    void listado()
    {
        std::cout << "Nombre: " << nombre << "\n";
        std::cout << "Apellido: " << apellido << "\n";
        std::cout << "Número de hijos: " << nHijos << "\n";
        std::cout << "Salario: " << salario << "\n";
        std::cout << "Estado civil: " << estadoCivil << "\n";
        std::cout << "Años de servicio: " << tiempoServicio << "\n";
    }
};
EmpresaXEmpleados::EmpresaXEmpleados()
{
    std::cout << "Ingrese el nombre del empleado"
              << "\n";
    std::cin >> nombre;
    std::cout << "Ingrese el apellido del empleado"
              << "\n";
    std::cin >> apellido;
    std::cout << "Ingrese el número de hijos del empleado"
              << "\n";
    std::cin >> nHijos;
    std::cout << "Ingrese el salario del empleado"
              << "\n";
    std::cin >> salario;
    std::cout << "Ingrese el estado civil del empleado"
              << "\n";
    std::cin >> estadoCivil;
    std::cout << "Ingrese los años de servicio del empleado"
              << "\n";
    std::cin >> tiempoServicio;
}

