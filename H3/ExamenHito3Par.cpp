#include <string>
#include <iostream>
#include <vector>

using namespace std;
struct nodot1 //ejercicio 1
{
    double entero1;
    struct nodot1 *sig;
};
struct nodot1 *cab, *fin, *p;

struct seleccion //ejercicio 2
{
    string pais;
    string nombreEntrenador;
    string jugador;
    string resultados;
};
void selecionfacil()
{
    seleccion miSeleccion;
    std::cout << "\nIngrese el país\n";
    std::cin >> miSeleccion.pais;
    std::cout << "\nIngrese el nombre del entrenador\n";
    std::cin >> miSeleccion.nombreEntrenador;
    std::cout << "\nIngrese el nombre del jugador\n";
    cin.ignore();
    std::getline(std::cin, miSeleccion.jugador);
    std::cout << "\nIngrese el resultado\n";
    std::cin >> miSeleccion.resultados;

    std::cout << "El  país es: " << miSeleccion.pais << "\n";
    std::cout << "El  nombre del entrenador es: " << miSeleccion.nombreEntrenador << "\n";
    std::cout << "El  nombre de los jugadores es: " << miSeleccion.jugador << "\n";
    std::cout << "El  resultado es: " << miSeleccion.resultados << "\n";
}

class EmpresaXEmpleados //Ejercicio 3
{
    string nombre;
    string apellido;
    int nHijos;
    double salario;
    string estadoCivil;
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
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Número de hijos: " << nHijos << endl;
        cout << "Salario: " << salario << endl;
        cout << "Estado civil: " << estadoCivil << endl;
        cout << "Años de servicio: " << tiempoServicio << endl;
    }
};
EmpresaXEmpleados::EmpresaXEmpleados()
{
    cout << "Ingrese el nombre del empleado" << endl;
    cin >> nombre;
    cout << "Ingrese el apellido del empleado" << endl;
    cin >> apellido;
    cout << "Ingrese el número de hijos del empleado" << endl;
    cin >> nHijos;
    cout << "Ingrese el salario del empleado" << endl;
    cin >> salario;
    cout << "Ingrese el estado civil del empleado" << endl;
    cin >> estadoCivil;
    cout << "Ingrese los años de servicio del empleado" << endl;
    cin >> tiempoServicio;
}
void menuEMpleados()
{
    EmpresaXEmpleados ajsdaa;
    std::cout <<"El porcentaje de pago del empleado es: " << ajsdaa.porcentajeDePago() << "\n";
    ajsdaa.listado();
}

///////////////////////
class TrianGod
{
public:
    struct nodoTriangulo //ejercicio 1
    {
        int ladoA;
        int ladoB;
        int ladoC;
        struct nodoTriangulo *sig;
        struct nodoTriangulo *ant;
    };
    struct nodoTriangulo *cab, *fin, *p;
    TrianGod();
    void insertarDatos(int a, int b, int c)
    {
        /*
        int a = 0, b = 0, c = 0;
        cout << "Insetar lado A" << endl;
        cin >> a;
        cout << "Insetar lado B" << endl;
        cin >> b;
        cout << "Insetar lado C" << endl;
        cin >> c;*/
        struct nodoTriangulo *nuevo;
        nuevo = new struct nodoTriangulo; //Crear un nuevo nodo
        nuevo->sig = NULL;                //Siguiente es null
        if (nuevo == NULL)
        {
            std::cout << "No hay espacio en Memoria\n";
        }
        else
        {
            nuevo->ladoA = a; //Entero para nuevo
            nuevo->ladoB = b;
            nuevo->ladoC = c;
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
    void listarTriangulos()
    {
        p = cab;
        cout << "Lista original" << endl;
        while (p != NULL) //Primera lista con todos los valores
        {
            cout << " Lado A: " << p->ladoA << " Lado B: " << p->ladoB << " Lado C: " << p->ladoC << endl;
            p = p->sig;
        }
        p = cab;
        cout << "Lista de equilateros" << endl;
        while (p != NULL) //Segunda para triangulos equilateros
        {
            int a = p->ladoA;
            int b = p->ladoB;
            int c = p->ladoC;
            if (a == b && b == c && c == a)
            {
                cout << " Lado A: " << p->ladoA << " Lado B: " << p->ladoB << " Lado C: " << p->ladoC << endl;
            }
            p = p->sig;
        }
        p = cab;
        cout << "Lista de Isosceles" << endl;
        while (p != NULL) //Segunda para triangulos equilateros
        {
            int a = p->ladoA;
            int b = p->ladoB;
            int c = p->ladoC;
            if (a == b && b == c && c == a)
            {
                //nada
            }
            else
            {
                if (a == b || a == c || b == c)
                {
                    cout << " Lado A: " << p->ladoA << " Lado B: " << p->ladoB << " Lado C: " << p->ladoC << endl;
                }
            }
            p = p->sig;
        }
        p = cab;
        cout << "Lista de escalenos" << endl;
        while (p != NULL)
        {
            int a = p->ladoA;
            int b = p->ladoB;
            int c = p->ladoC;
            if (a != b && b != c && c != a)
            {
                cout << " Lado A: " << p->ladoA << " Lado B: " << p->ladoB << " Lado C: " << p->ladoC << endl;
            }
            p = p->sig;
        }
    }
};
TrianGod::TrianGod()
{
    cab = NULL;
    fin = NULL;
}

void ejercicio4()
{
    int cuantos = 0, A = 0, B = 0, C = 0;
    TrianGod lista;
    cout << "¿Cuantos triangulos quieres comparar?" << endl;
    cin >> cuantos;
    for (int i = 0; i < cuantos; i++)
    {
        cout << "Para el triangulo " << i << endl;
        cout << "Ingresa el lado A" << endl;
        cin >> A;
        cout << "Ingresa el lado B" << endl;
        cin >> B;
        cout << "Ingresa el lado C" << endl;
        cin >> C;
        lista.insertarDatos(A, B, C);
    }
    lista.listarTriangulos();
}

void listar()
{
    p = cab;
    while (p != NULL)
    {
        int a = p->entero1;
        std::cout << p->entero1 << "  ";
        std::cout << "\n";
        std::cout << "Decimal: " << p->entero1 - a;
        std::cout << "\n";
        std::cout << "Entero: " << a;
        std::cout << "\n";
        p = p->sig;
    }
}

void menu()
{
    cout << "Ejercicio 1) Insertar enteros hasta poner 0" << endl;
    cout << "Ejercicio 2) Era solo crear un struct." << endl;
    cout << "Ejercicio 3) Era crear una clase." << endl;
    cout << "Ejercicio 4) Lista de triangulos y catalogo de estos" << endl;
    cout << "Ejercicio 5) Invertir una lista con punteros y dividirla a la mitad" << endl;
}
void ej1(double a)
{
    struct nodot1 *nuevo;
    nuevo = new struct nodot1; //Crear un nuevo nodo
    nuevo->sig = NULL;         //Siguiente es null
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
void limpiar()
{
    cout << endl
         << "Presiones una tecla para continuar" << endl;
}

void vectores()
{
    int *nArray;
    int size = 0;
    int dato = 0;
    std::cout << "Introduce el tamaño del array\n";
    std::cin >> size;
    nArray = NULL;          //A null
    nArray = new int[size]; //Declarando el array de pointers de el dato introducido
    int contador = 0;
    for (int i = 0; i < size; i++)
    {
        std::cout << "\nIntroduzca un dato para el array\n";
        std::cin >> dato;
        if (dato % 2 == 0)
        {
            break;
        }
        nArray[i] = dato;
        contador++;
    }
    for (int i = 0; i < contador; i++)
    {
        if (nArray[i] != 0)
        {
            cout << nArray[i] << "  ";
        }
        else
        {
            break;
        }
    }
    cout << endl;
    //Invertido con punteros
    int *invertedArray = new int[contador];
    nArray = nArray + (contador - 1); //recorremos
    auto savePosition = nArray;

    for (int i = 0; i < contador; i++)
    {
        invertedArray[i] = *nArray;
        nArray--;
    }
    nArray = invertedArray;
    for (int i = 0; i < contador; i++)
    {
        if (nArray[i] != 0)
        {
            cout << nArray[i] << "  ";
        }
        else
        {
            break;
        }
    }

    cout << endl;
    for (int i = 0; i < contador; i++)
    {
        if (i == contador / 2)
        {
            cout << endl;
        }
        if (nArray[i] != 0)
        {
            cout << nArray[i] << "  ";
        }
        else
        {
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
        switch (op)
        {
        case 1:
        {
            double a = 0;
            do
            {
                cout << "Ingrese un número" << endl;
                cin >> a;
                if (a != 0)
                {
                    ej1(a);
                }
            } while (a != 0);
            cout << endl;
            listar();
            limpiar();
            break;
        }
        case 2:
        {
            selecionfacil();
            break;
        }
        case 3:
        {
            menuEMpleados();
            break;
        }
        case 4:
        {
            ejercicio4();
            limpiar();
            break;
        }
        case 5:
        {
            vectores();
            limpiar();
            break;
        }
        default:
            break;
        }
    } while (op != 0);

    return 0;
}
