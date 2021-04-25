#include "HITO3clases.h"

float a, b, c, d = 0;
int opt, i, j, k;
std::string x, y;
double o, p, t;
char n;
void AArticulo()
{
    Articulo articulo;
    std::cout << "Ingrese el precio del articulo\n";
    std::cin >> a;
    articulo.set_values(a);
    std::cout << "El precio detal es " << articulo.detal() << " y el precio por mayor es " << articulo.mayor() << "\n";
}
void AAlumno()
{
    Alumno alumno;
    std::cout << "Ingrese el nombre del alumno\n";
    std::cin >> x;
    std::cout << "Ingrese la cédula del alumno\n";
    std::cin >> y;
    std::cout << "Ingrese la nota 1 del alumno\n";
    std::cin >> a;
    std::cout << "Ingrese la nota 2 del alumno\n";
    std::cin >> b;
    std::cout << "Ingrese la nota 3 del alumno\n";
    std::cin >> c;
    alumno.set_values(y, x, a, b, c);
    std::cout << alumno.datos() << "\n"
              << "Nota final: " << alumno.notafinal() << "\n";
    if (alumno.aprobado() == true)
    {
        std::cout << "Alumno aprobado\n";
    }
    else
    {
        std::cout << "Alumno Reprobado\n";
    }
}
void RRectangulo()
{
    Rectangulo rectangulo;
    std::cout << "Ingrese la altura del rectangulo\n";
    std::cin >> a;
    std::cout << "Ingrese la base del rectangulo\n";
    std::cin >> b;
    rectangulo.set_values(b, a);
    std::cout << "El área del rectangulo es " << rectangulo.area() << "\n";
    std::cout << "El perimetro del rectangulo es " << rectangulo.perimetro() << "\n";
}
void pesoIdeal(int a)
{
    if (a == -1)
    {
        std::cout << "Por debajo del peso ideal\n";
    }
    if (a == 0)
    {
        std::cout << "En el peso ideal\n";
    }
    if (a == 1)
    {
        std::cout << "Con sobrepeso\n";
    }
}
void esMayorDeEdad(bool a)
{
    if (a == true)
    {
        std::cout << "Es mayor de edad\n";
    }
    else
    {
        std::cout << "Es menor de edad\n";
    }
}
void PPersona()
{
    std::cout << "Ingresa el nombre\n";
    std::cin >> x;
    std::cout << "Ingresa la edad\n";
    std::cin >> i;
    std::cout << "Ingresa el sexo\n";
    std::cin >> n;
    std::cout << "Ingresa el peso\n";
    std::cin >> o;
    std::cout << "Ingresa la altura\n";
    std::cin >> p;
    std::cout << "----------------------\n";
    Persona p1, p2, p3;
    p1.set_Nombre(x);
    p1.set_Edad(i);
    p1.set_Peso(o);
    p1.set_Altura(p);
    p1.set_Sexo(n);
    //
    p2.set_Nombre(x);
    p2.set_Edad(i);
    p2.set_Sexo(n);
    //
    p3; //Defecto
    std::cout << "--------DATOS DE LOS 3------\n";
    p1.toString();
    std::cout << "Peso para p1\n";
    pesoIdeal(p1.calcularIMC()); //Peso ideal?
    esMayorDeEdad(p1.esMayorDeEdad());
    std::cout << "\n";
    p2.toString();
    std::cout << "Peso para p2\n";
    pesoIdeal(p2.calcularIMC()); //Peso ideal?
    esMayorDeEdad(p2.esMayorDeEdad());
    std::cout << "\n";
    p3.toString();
    std::cout << "Peso para p3\n";
    pesoIdeal(p3.calcularIMC()); //Peso ideal?
    esMayorDeEdad(p3.esMayorDeEdad());
    std::cout << "\n";
}

void PPassword()
{
    int e = 0;
    std::cout << "Ingresa el tamaño del array de passwords\n";
    std::cin >> k;
    std::cout << "Ingresa el tamaño de las passwords\n";
    std::cin >> e;
    Password parray[100]; //estatico
    bool esFuerte[100];
    for (int i = 0; i < k; i++)
    {
        parray[i].set_Longitud(e);
        parray[i].generarPassword();
        if (parray[i].esFuerte())
        {
            esFuerte[i] = true;
        }
        else
        {
            esFuerte[i] = false;
        }
    }
    for (int i = 0; i < k; i++)
    {
        std::cout << std::boolalpha;
        std::cout << parray[i].obtenerPass() << " " << esFuerte[i] << "\n";
    }
}
void menu()
{
    std::cout << "0) salir\n";
    std::cout << "1) Establecer el precio de un articulo, detal y mayor\n";
    std::cout << "2) Saber si el alumno aprobó\n";
    std::cout << "3) Hallar área y perimetro de un rectangulo\n";
    std::cout << "4) Declarar una clase (Fijarse clases)\n";
    std::cout << "5) Clase persona\n";
    std::cout << "6) Clase passwords\n";
}

void limpiar()
{
    std::cout << "\nPresione una tecla para volver al menú\n";
    getch();
    system("CLS");
}
int main()
{
    do
    {
        menu();
        std::cin >> opt;
        switch (opt)
        {
        case 1:
        {
            AArticulo();
            limpiar();
            break;
        }
        case 2:
        {
            AAlumno();
            limpiar();
            break;
        }
        case 3:
        {
            RRectangulo();
            limpiar();
            break;
        }
        case 4:
        {
            std::cout << "Solo pidió una clase hecha\n";
            limpiar();
            break;
        }
        case 5:
        {
            PPersona();
            limpiar();
            break;
        }
        case 6:
        {
            PPassword();
            limpiar();
            break;
        }
        default:
            break;
        }
    } while (opt != 0);
    getch();
    return 0;
}