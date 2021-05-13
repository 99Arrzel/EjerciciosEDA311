#include "H3_PracticaListasSimples20.h"

void limpiar()
{
    std::cout << "\nPresione una tecla para continuar\n";
    std::cin.get();
    system("cls");
}

void tarea1()
{
    MisNodos tarea1;
    int a;
    do
    {
        std::cout << "Ingrese un número\n";
        std::cin >> a;
        if (a != 0)
        {
            tarea1.insertarEntero(a);
        }
        tarea1.listarNodoEnteros();
        std::cout << "\n";
    } while (a != 0);
    tarea1.contarNodos(); //Cuenta como 2 igual XD
}
void tarea2()
{
    MisNodos tarea2;
    float a;
    do
    {
        std::cout << "Ingrese un número\n";
        std::cin >> a;
        if (a != 0)
        {
            tarea2.insertarFloat(a);
        }
        tarea2.listarNodoFloats();
        std::cout << "\n--SUMATORIA DE CUADRADOS ABAJO--\n";
        tarea2.calcularCuadrados();

    } while (a != 0);
}
void tarea4()
{
    MisNodos tarea4;
    int a = 0, b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea4.insertarEntero(b);
        }
    } while (b != 0);
    tarea4.listarNodoEnteros();
    std::cout << "\nIntroduzca el valor a buscar\n";
    std::cin >> a;
    MisNodos tarea4a;                                  //Creando otro nodo para que no tenga relación y para invocar al buscador
    tarea4a.buscarNumeroEntero(a, tarea4.returnCab()); //Le damos un número a buscar y le damos un pointer en el primer nodo
    //devuelve un pointer en la posición del número si se encuentra
}
void tarea5()
{
    MisNodos tarea5a; //Primera lista
    int a = 0, b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {

            tarea5a.insertarEntero(b);
        }

    } while (b != 0);
    std::cout << "\nAhora la segunda lista\n";
    MisNodos tarea5b; //Segunda lista
    a = 0;
    b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea5b.insertarEntero(b);
        }

    } while (b != 0);
    tarea5a.listarNodoEnteros();
    std::cout << "\n--------A-----------\n";
    tarea5b.listarNodoEnteros();
    std::cout << "\n--------B-----------\n";
    MisNodos tarea5c(tarea5a.returnCab(), tarea5b.returnCab()); //Buid un nodo
    std::cout << "\n----Resultado----\n";
    tarea5c.listarNodoEnteros();
}
void tarea6()
{
    MisNodos tarea6a;
    int b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {

            tarea6a.insertarEntero(b);
        }

    } while (b != 0);
    MisNodos tarea6b;
    tarea6b.invertirLista(tarea6a.returnCab());
    std::cout << "\n-------------\n";
    tarea6b.listarReversaEntero();
}
void tarea7()
{
    MisNodos tarea7a;
    int b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {

            tarea7a.insertarEntero(b);
        }

    } while (b != 0);
    MisNodos tarea7b;
    MisNodos tarea7c;
    auto cabB = tarea7b.returnCab();
    auto cabC = tarea7b.returnCab();
    auto a = tarea7a.returnCab();
    std::tie(cabB, cabC) = tarea7a.retornarParesEImpares(a);
    tarea7b.setCab(cabB);
    tarea7c.setCab(cabC);
    std::cout << "\n------NODOS PARES-----\n";
    tarea7b.listarNodoEnteros();
    std::cout << "\n------NODOS IMPARES-----\n";
    tarea7c.listarNodoEnteros();
}
void tarea8()
{
    MisNodos tarea8a; //Primera lista
    int a = 0, b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {

            tarea8a.insertarEntero(b);
        }

    } while (b != 0);
    std::cout << "\nAhora la segunda lista\n";
    MisNodos tarea8b; //Segunda lista
    a = 0;
    b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea8b.insertarEntero(b);
        }

    } while (b != 0);
    tarea8a.listarNodoEnteros();
    std::cout << "\n--------A-----------\n";
    tarea8b.listarNodoEnteros();
    std::cout << "\n--------B-----------\n";
    MisNodos tarea8c(tarea8a.returnCab(), tarea8b.returnCab()); //Buid un nodo
    std::cout << "\n----Resultado CONCATENADO----\n";
    tarea8c.listarNodoEnteros();
    //Ordenar acá
    std::cout << "\n----Resultado Ordenado----\n";
    tarea8c.ordenarNodo();
    //
    tarea8c.listarNodoEnteros();
}
void tarea10()
{
    MisNodos tarea10; //Primera lista
    int a = 0, b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {

            tarea10.insertarEntero(b);
        }

    } while (b != 0);
    std::cout << "--Listado--\n";
    tarea10.listarNodoEnteros();
    std::cout << "\n-----------\n";

    if (tarea10.checkDecendente())
    {
        std::cout << "Está ordenado de manera descendente\n";
    }
    else
    {
        std::cout << "NO está ordenado de manera descendente\n";
    }
}
void tarea11()
{
    MisNodos tarea11;
    int a = 0, b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {

            tarea11.insertarEntero(b);
        }

    } while (b != 0);
    std::cout << "--Listado--\n";
    tarea11.listarNodoEnteros();
    std::cout << "\n-----------\n---SUMA---:";
    std::cout << tarea11.sumaDeEnteros();
}
void tarea12()
{
    MisNodos tarea12a;
    int b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea12a.insertarEntero(b);
        }
    } while (b != 0);
    std::cout << "\n--Ahora para la segunda lista--\n";
    MisNodos tarea12b;
    b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea12b.insertarEntero(b);
        }
    } while (b != 0);
    std::cout << "1 : ";
    tarea12a.listarNodoEnteros();
    std::cout << "\n2 : ";
    tarea12b.listarNodoEnteros();
    std::cout << "\nResultado: " << tarea12a.compararEntero(tarea12a.returnCab(), tarea12b.returnCab()) << "\n";
}
void tarea13()
{
    MisNodos tarea13;
    int b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea13.insertarEntero(b);
        }
    } while (b != 0);
    std::cout << "\n---------------\n";
    tarea13.listarNodoEnteros();
    std::cout << "\n---------------";
    std::cout << "\nIngrese una posición\n";
    int bpos;
    std::cin >> bpos;
    tarea13.listarPosicionEnNodoEnteros(bpos);
}
void tarea14()
{
    std::cout << "Inserta 0 para salir\n";
    MisNodos tarea14;
    std::string insertar;
    while (insertar != "0")
    {
        std::cout << "Inserta un valor\n";
        std::cin >> insertar;
        if (insertar == "0")
        {
            break;
        }
        tarea14.insertarString(insertar);
    }
    std::cout << "\nIngresa un valor para buscar\n";
    std::cin >> insertar;
    auto puntero = tarea14.buscarStrings(insertar);
    if (puntero != NULL)
    {
        std::cout << "Elemento en la lista con valor :" << puntero->string1 << "\n";
    }
    else
    {
        std::cout << "Palabra no encontrada.\n";
    }
}
void tarea15()
{
    MisNodos tarea15;
    int b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea15.insertarEntero(b);
        }
    } while (b != 0);
    std::cout << "Ingrese el número a buscar en la lista\n";
    int buscar = 0;
    std::cin >> buscar;
    std::cout << "Elemento encontrado :" << tarea15.contarNumeroEnLista(buscar) << " veces\n";
}
void tarea16()
{
    MisNodos tarea16a;
    MisNodos tarea16b;
    int b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea16a.insertarEntero(b);
        }
    } while (b != 0);
    std::cout << "\nAhora para la segunda lista\n";
    b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea16b.insertarEntero(b);
        }
    } while (b != 0);
    auto cabA = tarea16a.returnCab();
    auto cabB = tarea16b.returnCab();
    tarea16a.encontrarInterseccion(cabA, cabB);
}
void tarea18()
{
    MisNodos tarea18;
    int b = 0;
    do
    {
        std::cout << "Introduzca un entero\n";
        std::cin >> b;
        if (b != 0)
        {
            tarea18.insertarEntero(b);
        }
    } while (b != 0);
    auto soloMayores = tarea18.listaPromedioMayor(tarea18.returnCab());
    tarea18.setCab(soloMayores);
    std::cout << "\nResultado\n";
    tarea18.listarNodoEnteros();
    std::cout << "\n---------------\n";
}
void tarea19()
{
    std::string nombre, apellido;
    MisNodos tarea19;
    std::cout << "Ingresa un nombre\n";
    std::cin >> nombre;
    std::cout << "Ingresa un apellido\n";
    std::cin >> apellido;
    tarea19.almacenarStrings(nombre,apellido);
    std::cout << "\n Resultado \n";
    tarea19.coutCharSeparadoGuion();
    std::cout << "\n";

}
void tarea20()
{
       
}
void tarea21()
{

}


int main()
{
    do
    {
        std::cout << "Introduzca una opción:\n";
        menuPrincipal();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            tarea1();
            break;
        }
        case 2:
        {
            tarea1();
            break;
        }
        case 3:
        {
            tarea2();
            break;
        }
        case 4:
        {
            tarea4();
            break;
        }
        case 5:
        {
            tarea5();
            break;
        }
        case 6:
        {
            tarea6();
            break;
        }
        case 7:
        {
            tarea7();
            break;
        }
        case 8:
        {
            tarea8();
            break;
        }
        case 9:
        {
            tarea1();
            break;
        }
        case 10:
        {
            tarea10();
            break;
        }
        case 11:
        {
            tarea11();
            break;
        }
        case 12:
        {
            tarea12();
            break;
        }
        case 13:
        {
            tarea13();
            break;
        }
        case 14:
        {
            tarea14();
            break;
        }
        case 15:
        {
            tarea15();
            break;
        }
        case 16:
        {
            tarea16();
            break;
        }
        case 17:
        {
            tarea5();
            break;
        }
        case 18:
        {
            tarea18();
            break;
        }
        case 19:
        {
            tarea19();
            break;
        }
        case 20:
        {
            tarea20();
            break;
        }
        case 21:
        {
            tarea21();
            break;
        }

        default:
        {
            break;
        }
        }
        limpiar();
    } while (opt != 0);
}