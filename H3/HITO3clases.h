#include <iostream>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <vector>

static const char alphnum[]="0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; //"!@#$%^&*"
int strLen = sizeof(alphnum) - 1;

class Rectangle
{
  int width, height;

public:
  void set_values(int, int);
  int area() { return width * height; }
};

void Rectangle::set_values(int x, int y)
{
  width = x;
  height = y;
}

class Articulo
{
  float costoBase;

public:
  void set_values(float);
  float detal() { return costoBase + costoBase * 0.3; }
  float mayor() { return costoBase + costoBase * 0.15; }
};
void Articulo::set_values(float x)
{
  costoBase = x;
}
class Alumno
{
  std::string cedula;
  std::string nombre;
  float nota1, nota2, nota3;

public:
  void set_values(std::string, std::string, float, float, float);
  float notafinal() { return (nota1 + nota2 + nota3) / 3; }
  std::string datos() { return "Cedula: " + cedula + " Nombre: " + nombre; }
  bool aprobado()
  {
    if ((nota1 + nota2 + nota3) / 3 >= 48)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};
void Alumno::set_values(std::string d, std::string e, float a, float b, float c)
{
  cedula = d;
  nombre = e;
  nota1 = a;
  nota2 = b;
  nota3 = c;
}
class Rectangulo
{
  float base, altura;

public:
  void set_values(float, float);
  float area() { return base * altura; }
  float perimetro() { return 2 * base + 2 * altura; }
};
void Rectangulo::set_values(float b, float c)
{
  base = b;
  altura = c;
}
//No dijo que hacer con la cuenta //4
class Cuenta
{
  std::string titular;
  double cantidad;

public:
  void set_titular(std::string);
  void set_todo(std::string, double);
  double ingresar(double a)
  {
    if (a > 0)
    {
      return cantidad + a;
    }
  }
  double retirar(double a)
  {
    if (a > cantidad)
    {
      cantidad = 0;
      return 0;
    }
    else
    {
      return cantidad - a;
    }
  }
};
void Cuenta::set_titular(std::string a)
{
  a = titular;
}
void Cuenta::set_todo(std::string a, double b)
{
  a = titular;
  b = cantidad;
}
//5
class Persona
{
  std::string nombre = "";
  char sexo = 'H';
  int edad = 0;
  int dni;
  double peso, altura = 0;

public:
  Persona();                                       //Por defecto
  Persona(std::string, char, int);                 //nombre, sexo, edad
  Persona(std::string, char, int, double, double); //Todos como parametro
  int calcularIMC()
  {
    int a = peso / (pow(altura, 2));
    if (a < 20)
    {
      return -1;
    }
    if (a > 20 || a < 25)
    {
      return 0;
    }
    if (a > 25)
    {
      return 1;
    }
    else
    {
      return a;
    }
  }
  bool esMayorDeEdad()
  {
    if (edad >= 18)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  void comprobarSexo()
  {
    if (sexo != 'H' || sexo != 'M')
    {
      sexo = 'H';
    }
  }
  void toString() { std::cout << "\nNombre: " << nombre << "\nSexo: " << sexo << "\nEdad: " << edad << "\nDNI: " << dni << "\nPeso: " << peso << "\nAltura: " << altura; }
  void generaDNI()
  {
    srand(time(NULL));
    dni = rand() % 99999999 + 10000000;
  }
  void set_Nombre(std::string a) { nombre = a; }
  void set_Sexo(char a) { sexo = a; }
  void set_Edad(int a) { edad = a; }
  void set_Peso(double a) { peso = a; }
  void set_Altura(double a) { altura = a; }
};

Persona::Persona() //Por defecto
{
  nombre = "Andres";
  sexo = 'H';
  edad = 21;
  dni = 95841381;
  peso = 74;
  altura = 1.7;
}
Persona::Persona(std::string a, char b, int c)
{
  nombre = a;
  sexo = b;
  edad = c;
}
Persona::Persona(std::string a, char b, int c, double e, double f)
{
  nombre = a;
  sexo = b;
  edad = c;
  peso = e;
  altura = f;
}

class Password
{
  std::string password;
  int longitud;

public:
  Password();    //defecto
  Password(int); //con longitud
  bool esFuerte()
  {
    int i = 0;
    int mayus = 0, minus = 0, nums = 0;
    char c;
    for (int i= 0; i < password.length(); i++)
    {
      c = password[i];
      if (isupper(c))
      {
        mayus++;
      }
      if (islower(c))
      {
        minus++;
      }
      if (isdigit(c))
      {
        nums++;
      }
    }
    if (mayus > 2 && minus > 1 && nums > 5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  char GenRand()
  {
    return alphnum[rand() % strLen];
  }
  void generarPassword()
  {
    std::string passGenerada;
    char c;
    for (int in = 0; in < longitud; in++)
    {
      c = GenRand();
      passGenerada+=c;
    }
    password = passGenerada;
    passGenerada = "";
  }
  void set_Longitud(int a) { longitud = a; } //set
  std::string obtenerPass() { return password; }
  int obtenerLongitud() { return longitud; }

  //
};
Password::Password()
{
  longitud = 8;
}